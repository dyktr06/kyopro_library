#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/topological_sort.hpp"

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }
    vector<int> tsort = topological_sort(G);
    for(auto x : tsort){
        cout << x << "\n";
    }
}