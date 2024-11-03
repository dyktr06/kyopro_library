#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"
#include <iostream>

#include "../../../lib/math/modint.hpp"
#include "../../../lib/polynomial/polynomial_interpolation.hpp"

using namespace std;

using mint = ModInt<998244353>;
using FPS = FormalPowerSeries<mint>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<mint> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int i = 0; i < n; i++){
        cin >> y[i];
    }
    auto res = polynomialInterpolation(x, y);
    for(int i = 0; i < n; i++){
        cout << res[i] << (i == n - 1 ? '\n' : ' ');
    }
}
