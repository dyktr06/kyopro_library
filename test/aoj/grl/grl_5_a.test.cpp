#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/bipartite_matching.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, e; cin >> x >> y >> e;
    BipartiteMatching<int> bm(x + y);
    for(int i = 0; i < e; i++){
        int u, v; cin >> u >> v;
        bm.add_edge(u, v + x);
    }
    cout << bm.bipartite_matching() << "\n";
}
