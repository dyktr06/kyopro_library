#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/modint.hpp"
#include "../../../lib/math/matrix.hpp"

using mint = ModInt<998244353>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

    long long n, k; cin >> n >> k;
    Matrix<mint> mat(n, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    cout << mat.pow(k) << endl;
}