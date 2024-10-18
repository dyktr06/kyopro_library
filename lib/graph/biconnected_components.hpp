#pragma once

#include "../graph/lowlink.hpp"

struct BiconnectedComponents : LowLink{
    using super = LowLink;

    vector<vector<Edge>> edge_result;
    vector<vector<int>> result;

    BiconnectedComponents(const int node_size) : super(node_size){}

    void build(){
        super::build();
        vector<bool> visited(V, false);
        vector<Edge> edges;
        // 辺ベースで分解
        auto dfs = [&](auto &self, int cur, int prv) -> void {
            visited[cur] = true;
            bool is_multiple = false;
            for(auto &edge : G[cur]){
                if(edge.to == prv && !is_multiple){
                    is_multiple = true;
                    continue;
                }
                if(!visited[edge.to] || ord[edge.to] < ord[cur]){
                    edges.emplace_back(edge);
                }
                if(!visited[edge.to]){
                    self(self, edge.to, cur);
                    if(ord[cur] <= low[edge.to]){
                        edge_result.push_back({});
                        while(true){
                            auto edgeb = edges.back();
                            edge_result.back().push_back(edgeb);
                            edges.pop_back();
                            if(edge.id == edgeb.id) break;
                        }
                    }
                }
            }
        };
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(dfs, i, -1);
            }
        }

        vector<bool> used(V);
        for(auto &x : edge_result){
            vector<int> v;
            for(auto &y : x){
                v.push_back(y.from);
                v.push_back(y.to);
                used[y.from] = true;
                used[y.to] = true;
            }
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
            result.push_back(v);
        }
        for(int i = 0; i < V; i++){
            if(!used[i]){
                result.push_back({i});
            }
        }
    }

    vector<vector<int>> get(){
        return result;
    }
};
