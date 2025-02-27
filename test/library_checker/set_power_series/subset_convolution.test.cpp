#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"
#include <iostream>

#include "../../../lib/math/modint.hpp"
#include "../../../lib/convolution/subset_convolution.hpp"

using namespace std;

const long long MOD = 998244353;
using mint = ModInt<MOD>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<mint> a(1 << n), b(1 << n);
    for(int i = 0; i < (1 << n); i++) cin >> a[i];
    for(int i = 0; i < (1 << n); i++) cin >> b[i];
    auto c = subset_convolution<mint, 20>(a, b);
    for(int i = 0; i < (1 << n); i++) cout << c[i] << " \n"[i == (1 << n) - 1];
}
