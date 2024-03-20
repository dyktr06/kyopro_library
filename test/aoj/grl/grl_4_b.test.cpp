#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/topological_sort.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
    }
    for(auto x : topological_sort(G)) cout << x << "\n";
}
