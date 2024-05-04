#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/convolution/fps.hpp"
#include "../../../lib/math/modint.hpp"

using mint = ModInt<998244353>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(NULL));

    int n, m; cin >> n >> m;
    vector<mint> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    auto c = FPS::convolution(a, b);
    for(int i = 0; i < n + m - 1; i++) cout << c[i] << (i + 1 == n + m - 1 ? '\n' : ' ');
}
