#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/arbitrary_modint.hpp"
#include "../../../lib/math/combination.hpp"

using mint = ModInt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, m; cin >> t >> m;
    mint::setMod(m);
    Combination comb(10000000, m);
    while(t--){
        int n, k; cin >> n >> k;
        mint ans = comb.ncr(n, k);
        cout << ans << "\n";
    }
}