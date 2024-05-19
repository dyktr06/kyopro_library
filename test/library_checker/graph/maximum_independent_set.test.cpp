#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/maximum_independent_set.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> ans = maximumIndependentSet(G);
    cout << ans.size() << '\n';
    for(auto &v : ans){
        cout << v << " ";
    }
}
