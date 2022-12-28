#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/binary_indexed_tree.hpp"
#include "../../../lib/graph/heavy_light_decomposition.hpp"

int main(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    HeavyLightDecomposition hl(n);
    for(int i = 1; i < n; i++){
        int p; cin >> p;
        hl.add_edge(p, i);
    }
    hl.build();
    BinaryIndexedTree<long long> BIT(n);
    for(int i = 0; i < n; i++){
        BIT.add(hl.get(i), a[i]);
    }
    long long ans = 0;
    auto query = [&](int l, int r){
        ans += BIT.sum(l, r);
    };
    while(q--){
        int t; cin >> t;
        if(t == 0){
            int p, x; cin >> p >> x;
            BIT.add(hl.get(p), x);
        }else{
            int u; cin >> u;
            ans = 0;
            hl.subtree_query(u, query);
            cout << ans << "\n";
        }
    }
}