#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/convolution/ntt.hpp"
#include "../../../lib/math/modint.hpp"

const long long MOD = 1000000007;
using mint = ModInt<MOD>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<mint> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    auto c = NTT::convolution_mod(a, b, MOD);
    for(int i = 0; i < n + m - 1; i++) cout << c[i] << (i + 1 == n + m - 1 ? '\n' : ' ');
}
