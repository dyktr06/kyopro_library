#pragma once

/**
 * @brief Dijkstra's Algorithm (ダイクストラ法)
 * @docs docs/graph/dijkstra.md
 */

template <typename T>
vector<long long> dijkstra(const vector<vector<array<long long, 2>>> &G, T x){
    const long long INF = 0x1fffffffffffffff;
    vector<long long> cost((int) G.size(), INF);
    using P = pair<long long, long long>;
    priority_queue<P, vector<P>, greater<>> q;
    cost[x] = 0;
    q.emplace(0, x);

    while(q.size()){
        auto [c, at] = q.top();
        q.pop();
        if(c > cost[at]) continue;
        for(auto &[to, t] : G[at]){
            if(cost[to] > c + t){
                cost[to] = c + t;
                q.emplace(cost[to], to);
            }
        }
    }
    return cost;
}

pair<long long, vector<pair<int, int>>> shortest_path(const vector<vector<array<long long, 2>>> &G, int s, int t){
    const long long INF = 0x1fffffffffffffff;
    vector<long long> cost((int) G.size(), INF);
    vector<int> par((int) G.size(), -1);
    using P = pair<long long, long long>;
    priority_queue<P, vector<P>, greater<>> q;
    cost[s] = 0;
    par[s] = -1;
    q.emplace(0, s);

    while(q.size()){
        auto [c, at] = q.top();
        q.pop();
        if(c > cost[at]) continue;
        for(auto &[to, t] : G[at]){
            if(cost[to] > c + t){
                par[to] = at;
                cost[to] = c + t;
                q.emplace(cost[to], to);
            }
        }
    }

    if(cost[t] == INF){
        return {-1, {}};
    }
    vector<pair<int, int>> path;
    for(int now = t; par[now] != -1; now = par[now]){
        path.emplace_back(par[now], now);
    }
    reverse(path.begin(), path.end());

    return {cost[t], path};
}
