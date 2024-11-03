#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"
#include <iostream>

#include "../../../lib/math/modint.hpp"
#include "../../../lib/polynomial/formal_power_series.hpp"

using namespace std;

using mint = ModInt<998244353>;
using FPS = FormalPowerSeries<mint>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    FPS f(n), g(m);
    for(int i = 0; i < n; i++){
        cin >> f[i];
    }
    for(int i = 0; i < m; i++){
        cin >> g[i];
    }
    auto [ansq, ansr] = f.division(g);
    int u = ansq.size(), v = ansr.size();
    cout << u << ' ' << v << '\n';
    for(int i = 0; i < u; i++){
        if(i) cout << ' ';
        cout << ansq[i];
    }
    cout << '\n';
    for(int i = 0; i < v; i++){
        if(i) cout << ' ';
        cout << ansr[i];
    }
    cout << '\n';
}
