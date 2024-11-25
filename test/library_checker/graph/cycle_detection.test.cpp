#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/dijkstra.hpp"
#include "../../../lib/graph/scc.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> u(m), v(m);
    map<pair<int, int>, int> e;
    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i];
        e[{u[i], v[i]}] = i;
    }
    vector<vector<int>> G(n);
    SCC scc(n);
    vector<vector<array<long long, 2>>> G2(n);
    for(int i = 0; i < m; i++){
        scc.add_edge(u[i], v[i]);
        G2[u[i]].push_back({v[i], 1});
    }
    scc.build();
    vector<int> ans;
    for(auto &s : scc.get()){
        int sizs = s.size();
        if(sizs == 1) continue;
        auto [w1, e1] = shortest_path(G2, s[0], s[1]);
        auto [w2, e2] = shortest_path(G2, s[1], s[0]);
        for(auto [a, b] : e1){
            ans.push_back(e[{a, b}]);
        }
        for(auto [a, b] : e2){
            ans.push_back(e[{a, b}]);
        }
        break;
    }

    int siz = ans.size();
    if(siz == 0){
        cout << -1 << "\n";
        return 0;
    }
    cout << siz << "\n";
    for(int i = 0; i < siz; i++){
        cout << ans[i] << "\n";
    }
}
