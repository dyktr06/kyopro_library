#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/heavy_light_decomposition.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    HeavyLightDecomposition hl(n);
    for(int i = 1; i < n; i++){
        int p; cin >> p;
        hl.add_edge(p, i);
    }
    hl.build();
    while(q--){
        int u, v; cin >> u >> v;
        cout << hl.lca(u, v) << "\n";
    }
}