#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"
#include <iostream>

#include "../../../lib/data_structure/weighted_union_find.hpp"
#include "../../../lib/math/modint.hpp"

using namespace std;

using mint = ModInt<998244353>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    WeightedUnionFind<mint> uf(n, 0);
    while(q--){
        int t; cin >> t;
        if(t == 0){
            int u, v; cin >> u >> v;
            mint x; cin >> x;
            if(uf.same(u, v)){
                if(uf.diff(u, v) == x){
                    cout << 1 << "\n";
                } else{
                    cout << 0 << "\n";
                }
            } else{
                uf.unite(u, v, x);
                cout << 1 << "\n";
            }
        } else{
            int u, v; cin >> u >> v;
            if(uf.same(u, v)){
                cout << uf.diff(u, v) << "\n";
            } else{
                cout << -1 << "\n";
            }
        }
    }
}
