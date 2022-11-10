#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/tree.hpp"

int n, q;
vector<vector<int>> G;

int main(){
    cin >> n >> q;
    G.resize(n);
    for(int i = 1; i <= n - 1; i++){
        int p; cin >> p;
        G[i].push_back(p);
        G[p].push_back(i);
    }
    TreeLibrary TL(G);
    while(q--){
        int u, v; cin >> u >> v;
        cout << TL.lca(u, v) << "\n";
    }
}