#include <bits/stdc++.h>

using namespace std;

// 行列 ... ここでは、vector<vector<long long>> の二次元配列で定義されます。

// 行列の累乗 (mod. m) を計算します。: O(N^3 log n)
vector<vector<long long>> matrixpow(vector<vector<long long>> a, long long n, long long m){

    int siz = a.size();
    vector<vector<long long>> b(siz, vector<long long>(siz, 0));
    for(int i = 0; i < siz; i++) b[i][i] = 1;

    auto mul = [](vector<vector<long long>> a, vector<vector<long long>> b, long long m) -> vector<vector<long long>> {
        vector<vector<long long>> res((int) a.size(), vector<long long>(b[0].size()));
        for(int i = 0; i < (int) a.size(); i++){
            for(int j = 0; j < (int) b[0].size(); j++){
                for(int k = 0; k < (int) b.size(); k++){
                    res[i][j] += a[i][k] * b[k][j];
                    res[i][j] %= m;
                }
            }
        }
        return res;
    };

    while(n > 0){
        if(n & 1) b = mul(b, a, m);
        a = mul(a, a, m);
        n >>= 1;
    }
    return b;
}

// 行列の積 (mod. m) を計算します。: O(N^3)
vector<vector<long long>> mul(vector<vector<long long>> a, vector<vector<long long>> b, long long m){
    vector<vector<long long>> res((int) a.size(), vector<long long>(b[0].size()));
    for(int i = 0; i < (int) a.size(); i++){
        for(int j = 0; j < (int) b[0].size(); j++){
            for(int k = 0; k < (int) b.size(); k++){
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= m;
            }
        }
    }
    return res;
}