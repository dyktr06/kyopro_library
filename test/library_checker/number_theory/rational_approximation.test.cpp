#define PROBLEM "https://judge.yosupo.jp/problem/rational_approximation"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/rational_approximation.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        long long n, x, y; cin >> n >> x >> y;
        fraction<long long> f(x, y);
        auto [l, r] = rationalApproximation(n, f);
        if(f == l) r = l;
        cout << l.p << " " << l.q << " " << r.p << " " << r.q << "\n";
    }
}