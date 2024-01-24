#pragma once

/**
 * @brief Bellman-Ford Algorithm (ベルマン-フォード法)
 * @docs docs/graph/bellman_ford.md
 */

template <typename T>
vector<long long> bellman_ford(const vector<T> &E, const int &n, const int &x){
    const long long INF = 0x1fffffffffffffff;
    vector<long long> cost(n, INF);
    cost[x] = 0;
    for(int i = 0; i < n - 1; i++){
        for(auto [from, to, t] : E){
            if(cost[from] == INF) continue;
            cost[to] = min(cost[to], cost[from] + t);
        }
    }
    for(int i = 0; i < n - 1; i++){
        for(auto [from, to, t] : E){
            if(cost[from] == INF) continue;
            if(cost[from] + t < cost[to]){
                cost[to] = -INF;
            }
        }
    }
    return cost;
}