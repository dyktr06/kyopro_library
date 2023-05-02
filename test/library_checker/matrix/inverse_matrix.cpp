#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/modint.hpp"
#include "../../../lib/math/matrix.hpp"

using mint = ModInt<998244353>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    Matrix<mint> a(n, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    try{
        a = a.inv();
        cout << a;
    }
    catch(...){
        cout << -1 << endl;
    }
}