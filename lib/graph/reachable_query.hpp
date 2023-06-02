#pragma once

#include "../graph/topological_sort.hpp";

template <typename T>
vector<bool> reachable_query(const vector<vector<T>> &G, const vector<pair<T, T>> &query){
    int n = G.size(), q = query.size();
    vector<T> ord = topological_sort(G);
    vector<bool> res(q);
    for(int l = 0; l < q; l += 64){
        int r = min(q, l + 64);
        vector<long long> dp(n);
        for(int k = l; k < r; k++){
            auto [a, b] = query[k];
            dp[a] |= 1LL << (k - l);
        }
        for(auto &idx : ord){
            for(auto &to : G[idx]){
                dp[to] |= dp[idx];
            }
        }
        for(int k = l; k < r; k++){
            auto [a, b] = query[k];
            res[k] = (dp[b] >> (k - l)) & 1;
        }
    }
    return res;
}
