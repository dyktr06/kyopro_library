#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_undirected"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/eulerian_trail.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        int n, m; cin >> n >> m;
        EulerianTrail et(n, false);
        for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            et.add_edge(u, v);
        }
        bool res = et.build();
        vector<int> ansv = et.getVertex(), anse = et.getEdge();
        if(!res){
            cout << "No" << '\n';
        }else{
            cout << "Yes" << '\n';
            for(int i = 0; i < m + 1; i++){
                if(i) cout << ' ';
                cout << ansv[i];
            }
            cout << '\n';
            for(int i = 0; i < m; i++){
                if(i) cout << ' ';
                cout << anse[i];
            }
            cout << '\n';
        }
    }
}
