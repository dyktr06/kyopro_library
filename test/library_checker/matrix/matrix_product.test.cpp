#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/matrix.hpp"

const long long MOD = 998244353;

int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<long long>> a(n, vector<long long>(m));
    vector<vector<long long>> b(m, vector<long long>(k));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < k; j++){
            cin >> b[i][j];
        }
    }
    vector<vector<long long>> c = mul(a, b, MOD);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            if(j >= 1) cout << " ";
            cout << c[i][j];
        }
        cout << "\n";
    }
}