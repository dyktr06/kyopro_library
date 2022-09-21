#include <bits/stdc++.h>

using namespace std;

int n, m, r;
vector<array<long long, 3>> E;

// ベルマンフォード法 : O(VE)
template <typename T>
vector<long long> bellman_ford(T x){
    const long long INF = 0x1fffffffffffffff;
    vector<long long> cost(n, INF);
    cost[x] = 0;
    for(int i = 0; i < n - 1; i++){
        for(auto [from, to, t] : E){
            if(cost[from] == INF) continue;
            cost[to] = min(cost[to], cost[from] + t);
        }
    }
    for(auto [from, to, t] : E){
        if(cost[from] == INF) continue;
        if(cost[from] + t < cost[to]) return vector<long long>();
    }
    return cost;
}

// example (AOJ GRL_1_B)
int main(){
    cin >> n >> m >> r;
    E = vector<array<long long, 3>>();

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        // a -> b : cost c
        E.push_back({a, b, c});
    }
    
    vector<long long> ans = bellman_ford(r);
    if(ans.empty()){
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