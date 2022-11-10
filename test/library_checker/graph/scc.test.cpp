#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/scc.hpp"

int n, m;
vector<vector<int>> G;

int main(){
    cin >> n >> m;
    G.resize(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }
    SCC<int> scc(G);
    vector<vector<int>> v = scc.get();
    cout << (int) v.size() << "\n";
    for(auto s : v){
        cout << (int) s.size() << " ";
        for(auto x : s){
            cout << x << " ";
        }
        cout << "\n";
    }
}