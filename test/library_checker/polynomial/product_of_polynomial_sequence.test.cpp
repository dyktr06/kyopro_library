#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"
#include <iostream>

#include "../../../lib/math/modint.hpp"
#include "../../../lib/polynomial/formal_power_series.hpp"
#include "../../../lib/polynomial/product_of_polynomial_sequence.hpp"

using namespace std;

using mint = ModInt<998244353>;
using FPS = FormalPowerSeries<mint>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<FPS> f(n);
    for(int i = 0; i < n; i++){
        int d; cin >> d;
        f[i].resize(d + 1);
        for(int j = 0; j < d + 1; j++) cin >> f[i][j];
    }
    FPS ans = product(f);
    int len = ans.size();
    for(int i = 0; i < len; i++){
        cout << ans[i] << (i == len - 1 ? '\n' : ' ');
    }
}
