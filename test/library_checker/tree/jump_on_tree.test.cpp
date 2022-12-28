#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/heavy_light_decomposition.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    HeavyLightDecomposition hl(n);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        hl.add_edge(u, v);
    }
    hl.build();
    while(q--){
        int s, t, i; cin >> s >> t >> i;
        cout << hl.jump(s, t, i) << "\n";
    }
}