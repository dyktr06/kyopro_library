#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/segment_tree.hpp"
#include "../../../lib/graph/heavy_light_decomposition.hpp"
#include "../../../lib/math/modint.hpp"

using mint = ModInt<998244353>;

int main(){
    int n, q; cin >> n >> q;
    using T = pair<mint, mint>;
    vector<T> f(n);
    for(int i = 0; i < n; i++){
        cin >> f[i].first >> f[i].second;
    }
    HeavyLightDecomposition hl(n);
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        hl.add_edge(u, v);
    }
    hl.build();
    
    auto op = [](T x1, T x2) -> T { 
        return {x1.first * x2.first, (x2.first * x1.second + x2.second)};
    };
    T ex = {1, 0};
    SegTree<T> seg(n, op, ex), seg2(n, op, ex);
    for(int i = 0; i < n; i++){
        seg.update(hl.get(i), {f[i].first, f[i].second});
        seg2.update(n - hl.get(i) - 1, {f[i].first, f[i].second});
    }
    mint ans = 0;
    T g = ex;
    auto query = [&](int l, int r){
        g = op(g, seg.query(l, r));
    };
    auto query2 = [&](int l, int r){
        g = op(g, seg2.query(l, r));
    };
    while(q--){
        int t; cin >> t;
        if(t == 0){
            int p, c, d; cin >> p >> c >> d;
            seg.update(hl.get(p), {c, d});
            seg2.update(n - hl.get(p) - 1, {c, d});
        }else{
            int u, v, x; cin >> u >> v >> x;
            g = ex;
            hl.path_noncommutative_query(u, v, query, query2);
            ans = g.first * x + g.second;
            cout << ans << "\n";
        }
    }
}