#define PROBLEM "https://judge.yosupo.jp/problem/range_parallel_unionfind"
#include <iostream>

#include "../../../lib/data_structure/range_parallel_union_find.hpp"
#include "../../../lib/math/modint.hpp"

using namespace std;

using mint = ModInt<998244353>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<mint> x(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i];
    }

    RangeParallelUnionFind uf(n);
    mint ans = 0;
    while(q--){
        int k, a, b; cin >> k >> a >> b;
        uf.unite(k, a, b, [&](int ra, int rb){
            ans += x[ra] * x[rb];
            x[ra] += x[rb];
        });
        cout << ans << '\n';
    }
}
