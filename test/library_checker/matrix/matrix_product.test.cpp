#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/modint.hpp"
#include "../../../lib/math/matrix.hpp"

using mint = ModInt<998244353>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    Matrix<mint> a(n, m), b(m, k);
    int scan;
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
    a *= b;
    cout << a;
}