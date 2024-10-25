#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/convolution/bitwise_or_convolution.hpp"
#include "../../../lib/math/modint.hpp"

using mint = ModInt<998244353>;

int main(){
    int n; cin >> n;
    int m = 1 << n;
    vector<mint> a(m), b(m);
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<mint> c = bitwise_or_convolution(a, b);
    reverse(c.begin(), c.end());
    for(int i = 0; i < m; i++){
        cout << c[i] << " \n"[i == m - 1];
    }
}
