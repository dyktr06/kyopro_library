#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/graph-input.hpp"
#include "../../../lib/graph/scc.hpp"

int n, m;
vector<vector<int>> G;

int main(){
    cin >> n >> m;
    inGraph(G, n, m);
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