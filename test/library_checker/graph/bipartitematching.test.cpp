#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/dinic.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, r, m; cin >> l >> r >> m;
    Dinic<long long> G(l + r + 2);
    int s = l + r;
    int t = s + 1;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        G.add_edge(a, b + l, 1);
    }
    for(int i = 0; i < l; i++){
        G.add_edge(s, i, 1);
    }
    for(int i = 0; i < r; i++){
        G.add_edge(i + l, t, 1);
    }
    long long res = G.flow(s, t);
    cout << res << "\n";

    for(int i = 0; i < l + r + 2; i++){
        for(auto &e : G.G[i]){
            if(res == 0) break;
            if(e.flow > 0){
                cout << i << " " << e.to - l << "\n";
                res--;
            }
        }
    }
}