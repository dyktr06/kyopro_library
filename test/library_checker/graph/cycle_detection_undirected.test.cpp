#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection_undirected"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/union_find.hpp"
#include "../../../lib/graph/dijkstra.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    vector<int> u(m), v(m);
    map<pair<int, int>, int> e;
    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i];
        e[{u[i], v[i]}] = i;
        e[{v[i], u[i]}] = i;
    }
    vector<vector<array<long long, 2>>> G(n);
    UnionFind uf(n);
    vector<int> ansv, anse;
    for(int i = 0; i < m; i++){
        if(uf.same(u[i], v[i])){
            auto [w, path] = shortest_path(G, u[i], v[i]);
            ansv.push_back(u[i]);
            for(auto [x, y] : path){
                ansv.push_back(y);
                anse.push_back(e[{x, y}]);
            }
            anse.push_back(i);
            break;
        }
        uf.unite(u[i], v[i]);
        G[u[i]].push_back({v[i], 1});
        G[v[i]].push_back({u[i], 1});
    }
    
    int siz = ansv.size();
    if(siz == 0){
        cout << -1 << "\n";
        return 0;
    }
    cout << siz << "\n";
    for(int i = 0; i < siz; i++){
        cout << ansv[i] << " \n"[i == siz - 1];
    }
    for(int i = 0; i < siz; i++){
        cout << anse[i] << " \n"[i == siz - 1];
    }
}