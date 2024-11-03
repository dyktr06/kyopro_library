#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"
#include <iostream>

#include "../../../lib/math/modint.hpp"
#include "../../../lib/polynomial/taylor_shift.hpp"

using namespace std;

using mint = ModInt<998244353>;
using FPS = FormalPowerSeries<mint>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    mint c; cin >> c;
    FPS f(n);
    for(int i = 0; i < n; i++){
        cin >> f[i];
    }
    FPS g = taylorShift(f, c);
    for(int i = 0; i < n; i++){
        cout << g[i] << (i == n - 1 ? '\n' : ' ');
    }
}
