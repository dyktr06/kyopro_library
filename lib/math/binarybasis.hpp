#pragma once

/*
    配列 vec の xor 基底を求めます。

    add(x): x を基底の集合に追加します。
    exist(x): 基底の集合の中から XOR を繰り返して x を作れるかどうかを判定します。
    normalize(): 基底の集合を整理します。
    kth_element(k): 基底から生成できる数の集合の k 番目を取得します。(0-indexed)
    size(x): 基底の集合の大きさを取得します。
*/

template <typename T>
struct BinaryBasis{

    vector<T> basis, original;
    BinaryBasis(const vector<T>& vec){
        for(auto x : vec){
            T y = x;
            for(auto z : basis){
                y = min(y, y ^ z);
            }
            if(y > 0){
                basis.push_back(y);
                original.push_back(x);
            }
        }
        normalize();
    }

    void add(const T &x){
        T y = x;
        for(auto z : basis){
            y = min(y, y ^ z);
        }
        if(y > 0){
            basis.push_back(y);
            original.push_back(x);
        }
    }

    void normalize(){
        sort(basis.begin(), basis.end());
        for(int i = 0; i < (int) basis.size(); ++i){
            for(int j = 0; j < i; ++j){
                basis[i] = min(basis[i], basis[i] ^ basis[j]);
            }
        }
    }

    bool exist(const T &x){
        T y = x;
        for(auto z : basis){
            y = min(y, y ^ z);
        }
        return y > 0;
    }

    T kth_element(const long long &k){
        T res = 0;
        for(int i = 0; i < (int) basis.size(); ++i){
            if(k & (1LL << i)){
                res ^= basis[i];
            }
        }
        return res;
    }

    size_t size(){
        return basis.size();
    }
};