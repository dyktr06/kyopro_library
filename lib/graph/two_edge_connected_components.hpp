#pragma once

/**
 * @brief Two Edge Connected Components (二重辺連結成分分解)
 * @docs docs/graph/two_edge_connected_components.md
 * @see https://kntychance.hatenablog.jp/entry/2022/09/16/161858
 */

#include "../graph/lowlink.hpp"

struct TwoEdgeConnectedComponents : LowLink{
    using super = LowLink;

    vector<vector<int>> result;

    TwoEdgeConnectedComponents(const int node_size) : super(node_size){}

    void build(){
        super::build();
        vector<bool> visited(V, false);
        vector<int> v;
        auto dfs = [&](auto &self, int cur) -> void {
            visited[cur] = true;
            v.push_back(cur);
            for(auto &edge : G[cur]){
                if(visited[edge.to]) continue;
                if(!is_bridge[edge.id]){
                    self(self, edge.to);
                }
            }
        };
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                v.clear();
                dfs(dfs, i);
                result.push_back(v);
            }
        }
    }

    vector<vector<int>> get(){
        return result;
    }
};
