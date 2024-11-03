#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/combination.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, m; cin >> t >> m;
    Combination comb(10000000, m);
    while(t--){
        int n, k; cin >> n >> k;
        cout << comb.ncr(n, k) << "\n";
    }
}