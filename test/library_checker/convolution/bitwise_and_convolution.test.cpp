#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/convolution/bitwise_and_convolution.hpp"
#include "../../../lib/math/modint.hpp"

using mint = ModInt<998244353>;

int main(){
    int n; cin >> n;
    int m = 1LL << n;
    vector<mint> a(m), b(m);
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    vector<mint> c = bitwise_and_convolution(a, b);
    for(int i = 0; i < m; i++){
        cout << c[i] << " \n"[i == m - 1];
    }
}
