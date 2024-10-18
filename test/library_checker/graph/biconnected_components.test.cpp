#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/biconnected_components.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    BiconnectedComponents bc(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        bc.add_edge(a, b);
    }
    bc.build();
    auto ans = bc.get();
    cout << ans.size() << '\n';
    for(auto &x : ans){
        cout << x.size();
        for(auto &y : x){
            cout << ' ' << y;
        }
        cout << '\n';
    }
}
