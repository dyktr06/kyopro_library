#pragma once

// ベルマンフォード法 : O(VE)
template <typename T>
vector<long long> bellman_ford(vector<T> E, int n, int x){
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