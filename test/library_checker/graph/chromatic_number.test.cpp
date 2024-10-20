#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/chromatic_number.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << chromaticNumber(G) << '\n';
}

