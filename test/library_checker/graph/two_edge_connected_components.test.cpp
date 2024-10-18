#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/two_edge_connected_components.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    TwoEdgeConnectedComponents tecc(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        tecc.add_edge(a, b);
    }
    tecc.build();
    auto ans = tecc.get();
    cout << ans.size() << '\n';
    for(auto &x : ans){
        cout << x.size();
        for(auto &y : x){
            cout << ' ' << y;
        }
        cout << '\n';
    }
}
