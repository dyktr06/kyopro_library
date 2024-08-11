#pragma once

#include "../data_structure/union_find.hpp"

vector<pair<int, int>> T_join(vector<pair<int, int>> &edges, vector<bool> &b){
    const int n = b.size();
    UnionFind uf(n);
    vector<vector<int>> G(n);
    for(auto [x, y] : edges){
        if(!uf.same(x, y)){
            uf.unite(x, y);
            G[x].emplace_back(y);
            G[y].emplace_back(x);
        }
    }

    vector<bool> d = b;
    vector<pair<int, int>> ans;
    auto dfs = [&](auto &self, int curr, int prv) -> int {
        int cd = d[curr];
        for(auto nxt : G[curr]){
            if(nxt == prv) continue;
            int nd = self(self, nxt, curr);
            if(nd){
                cd ^= 1;
                ans.emplace_back(curr, nxt);
            }
        }
        return d[curr] = cd;
    };
    for(int i = 0; i < n; i++){
        if(uf.root(i) == i){
            dfs(dfs, i, -1);
        }
    }
    int sum = 0;
    for(auto x : d) sum += x;
    return (sum == 0 ? ans : vector<pair<int, int>>());
}
