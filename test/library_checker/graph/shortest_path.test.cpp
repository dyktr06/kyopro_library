#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/dijkstra.hpp"

vector<vector<array<long long, 2>>> G;

int n, m, s, t;

int main(){
    cin >> n >> m >> s >> t;
    G.resize(n);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        G[a].push_back({b, c});
    }
    pair<long long, vector<pair<int, int>>> p = shortestPath(G, s, t);
    if(p.first == -1){
        cout << -1 << "\n";
    }else{
        cout << p.first << " " << (int) p.second.size() << "\n";
        for(auto [u, v] : p.second){
            cout << u << " " << v << "\n";
        } 
    }
}