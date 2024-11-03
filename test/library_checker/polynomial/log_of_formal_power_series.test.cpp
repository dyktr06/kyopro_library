#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"
#include <iostream>

#include "../../../lib/math/modint.hpp"
#include "../../../lib/polynomial/formal_power_series.hpp"

using namespace std;

using mint = ModInt<998244353>;
using FPS = FormalPowerSeries<mint>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    FPS f(n);
    for(int i = 0; i < n; i++) cin >> f[i];
    FPS g = f.log();
    for(int i = 0; i < n; i++) cout << g[i] << (i == n - 1 ? '\n' : ' ');
}
