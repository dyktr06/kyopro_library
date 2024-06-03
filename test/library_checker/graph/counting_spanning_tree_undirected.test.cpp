#define PROBLEM "https://judge.yosupo.jp/problem/counting_spanning_tree_undirected"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/modint.hpp"

using mint = ModInt<998244353>;

#include "../../../lib/graph/counting_spanning_tree.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r; cin >> n >> m;
    vector<vector<int>> G(n);
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cout << countingSpanningTree<mint>(G, 0) << '\n';
}
