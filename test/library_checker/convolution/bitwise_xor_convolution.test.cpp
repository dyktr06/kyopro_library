#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/convolution/bitwise_xor_convolution.hpp"
#include "../../../lib/math/modint.hpp"
#include "../../../lib/math/utils.hpp"

using mint = ModInt<998244353>;

int main(){
    int n; cin >> n;
    int m = intpow(2, n);
    vector<mint> a(m), b(m);
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    vector<mint> c = bitwise_xor_convolution(a, b);
    for(int i = 0; i < m; i++){
        cout << c[i] << " \n"[i == m - 1];
    }
}