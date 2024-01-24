#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/bellman_ford.hpp"

int n, m, r;
vector<array<long long, 3>> E;

int main(){
    cin >> n >> m >> r;
    E = vector<array<long long, 3>>();

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        // a -> b : cost c
        E.push_back({a, b, c});
    }
    
    vector<long long> ans = bellman_ford(E, n, r);
    bool is_ncycle = false;
    for(int i = 0; i < n; i++){
        if(ans[i] <= -0x1fffffffffffffff){
            is_ncycle = true;
        }
    }
    if(is_ncycle){
        cout << "NEGATIVE CYCLE" << "\n";
    }else{
        for(int i = 0; i < n; i++){
            if(ans[i] >= 0x1fffffffffffffff){
                cout << "INF" << "\n";
            }else{
                cout << ans[i] << "\n";
            }
        }
    }
}