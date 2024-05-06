#define PROBLEM "https://judge.yosupo.jp/problem/connected_components_of_complement_graph"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/connected_components_of_complement_graph.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<vector<int>> ans = connectedComponentsOfComplementGraph(G);
    cout << ans.size() << "\n";
    for(auto &v : ans){
        cout << v.size() << " ";
        for(auto x : v){
            cout << x << " ";
        }
        cout << "\n";
    }
}
