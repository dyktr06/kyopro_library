#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/dijkstra.hpp"

vector<vector<array<long long, 2>>> G;

int n, m;

int main(){
    cin >> n;
    G.resize(n);
    for(int i = 0; i < n - 1; i++){
        int a, b, c; cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    vector<long long> cost = dijkstra(G, 0);
    int s, t;
    long long mx1 = -1, mx2 = -1;
    for(int i = 0; i < n; i++){
        if(cost[i] >= mx1){
            mx1 = cost[i];
            s = i;
        }
    }
    vector<long long> cost2 = dijkstra(G, s);
    for(int i = 0; i < n; i++){
        if(cost2[i] >= mx2){
            mx2 = cost2[i];
            t = i;
        }
    }
    pair<long long, vector<pair<int, int>>> p = shortestPath(G, s, t);
    vector<int> e;
    for(auto [u, v] : p.second){
        if(!e.size() || e.back() != u){
            e.push_back(u);
        }
        e.push_back(v);
    }
    cout << p.first << " " << (int) e.size() << "\n";
    for(auto x : e){
        cout << x << " ";
    }
    cout << "\n";
}