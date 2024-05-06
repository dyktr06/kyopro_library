#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/tree_diameter.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    TreeDiameter<int> td(n);
    for(int i = 0; i < n - 1; i++){
        int u, v, w; cin >> u >> v >> w;
        td.add_edge(u, v, w);
    }
    td.build();
    cout << td.diameter() << "\n";
}
