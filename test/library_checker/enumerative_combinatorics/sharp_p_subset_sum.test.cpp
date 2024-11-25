#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"
#include <iostream>

#include "../../../lib/enumerative_combinatorics/subset_sum.hpp"
#include "../../../lib/math/modint.hpp"

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
