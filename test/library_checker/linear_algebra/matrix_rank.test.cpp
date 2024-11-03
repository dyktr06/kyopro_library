#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/modint.hpp"
#include "../../../lib/math/matrix.hpp"

using mint = ModInt<998244353>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    Matrix<mint> mat(n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    cout << mat.rank(false) << "\n"; 
}
