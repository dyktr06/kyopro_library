#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"
#include <iostream>
#include <vector>

#include "../../../lib/convolution/lcm_convolution.hpp"
#include "../../../lib/math/modint.hpp"

using namespace std;

using mint = ModInt<998244353>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<mint> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    auto c = lcm_convolution(a, b);
    for(int i = 1; i <= n; ++i){
        cout << c[i] << " \n"[i == n];
    }
}
