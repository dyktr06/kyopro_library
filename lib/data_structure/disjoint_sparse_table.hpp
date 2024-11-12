#pragma once

template <typename T, T (*op)(T, T)>
struct DisjointSparseTable{
    int n, log2;
    std::vector<std::vector<T>> table;
    std::vector<T> val;
    DisjointSparseTable(std::vector<T> &a) : val(a) {
        int len = a.size();
        n = 1, log2 = 0;
        while(n < len){
            n *= 2;
            log2++;
        }
        val.resize(n);
        table = std::vector<std::vector<T>>(log2, std::vector<T>(n));
        init();
    }

    void init(){
        for(int i = 0; i < log2; i++){
            for(int j = 0; j < n; j += (n >> i)){
                int h = n >> (i + 1);
                // h を中心に左右に累積した値を計算
                table[i][j + h] = val[j + h];
                for(int k = j + h + 1; k < j + h * 2; k++){
                    table[i][k] = op(table[i][k - 1], val[k]);
                }
                table[i][j + h - 1] = val[j + h - 1];
                for(int k = j + h - 2; k >= j; k--){
                    table[i][k] = op(table[i][k + 1], val[k]);
                }
            }
        }
    }

    // [l, r]
    T query(int l, int r){
        assert(l <= r);
        if(l == r){
            return val[l];
        }
        // またぐ場所の計算
        int d = __builtin_clz(l ^ r) - (32 - log2);
        return op(table[d][l], table[d][r]);
    }
};
