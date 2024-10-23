#define PROBLEM "https://judge.yosupo.jp/problem/minimum_diameter_spanning_tree"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/minimum_diameter_spanning_tree.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    MinimumDiameterSpanningTree mst(n);
    for(int i = 0; i < m; i++){
        int u, v; long long c;
        cin >> u >> v >> c;
        mst.add_edge(u, v, c);
    }
    mst.build();
    vector<int> tree_edge = mst.get();
    cout << mst.getTreeDiameter() << '\n';
    for(int i = 0; i < n - 1; i++){
        if(i) cout << ' ';
        cout << tree_edge[i];
    }
    cout << '\n';
}
