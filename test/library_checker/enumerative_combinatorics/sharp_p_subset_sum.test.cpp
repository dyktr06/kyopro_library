#define PROBLEM "https://judge.yosupo.jp/problem/many_factorials"
#include <iostream>

#include "../../../lib/math/modint.hpp"
#include "../../../lib/math/subset_sum.hpp"

using namespace std;

using mint = ModInt<998244353>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, t; cin >> n >> t;
    vector<long long> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    auto ans = subsetSum<mint>(s, t);
    for(int i = 1; i <= t; i++){
        cout << ans[i] << (i == t ? '\n' : ' ');
    }
}
