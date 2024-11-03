#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"
#include <iostream>

#include "../../../lib/math/modint.hpp"
#include "../../../lib/polynomial/multipoint_evaluation.hpp"

using namespace std;

using mint = ModInt<998244353>;
using FPS = FormalPowerSeries<mint>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    FPS f(n);
    for(int i = 0; i < n; i++){
        cin >> f[i];
    }
    vector<mint> p(m);
    for(int i = 0; i < m; i++){
        cin >> p[i];
    }
    auto res = multipointEvalutation(f, p);
    for(int i = 0; i < m; i++){
        cout << res[i] << (i == m - 1 ? '\n' : ' ');
    }
}
