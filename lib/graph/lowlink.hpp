#pragma once

struct LowLink{
    struct Edge{
        int from, to, id;
    };
    vector<vector<Edge>> G;
    int V = 0, E = 0;
    vector<bool> used;
    vector<int> ord, low;
    vector<int> reachable;
    vector<pair<int, int>> bridges; // 橋
    vector<int> articulations; // 関節点
    vector<bool> is_bridge, is_articulation;

    LowLink(const int node_size) : V(node_size){
        G.resize(V);
    }

    void add_edge(int from, int to){
        G[from].push_back({from, to, E});
        G[to].push_back({to, from, E});
        E++;
    }

    void build(){
        used.assign(G.size(), 0);
        ord.assign(G.size(), 0);
        low.assign(G.size(), 0);
        reachable.assign(G.size(), -1);
        is_bridge.assign(E, false);
        is_articulation.assign(V, false);

        int k = 0;
        for(int i = 0; i < (int) G.size(); i++){
            if(!used[i]) dfs(i, -1, k);
        }
    }

    void dfs(int cur, int prv, int &k){
        used[cur] = true;
        ord[cur] = k++;
        low[cur] = ord[cur];
        bool flag_articulation = false;
        int child_count = 0; // DFS 木の子の数

        bool is_multiple = false;
        for(auto &edge : G[cur]){
            if(edge.to == prv && !is_multiple){
                is_multiple = true;
                continue;
            }
            if(!used[edge.to]){
                child_count++;
                dfs(edge.to, cur, k);
                low[cur] = min(low[cur], low[edge.to]);
                if(prv != -1 && ord[cur] <= low[edge.to]){
                    flag_articulation = true;
                }
                if(ord[cur] < low[edge.to]){
                    bridges.emplace_back(min(cur, edge.to), max(cur, edge.to));
                    is_bridge[edge.id] = true;
                }
            }else{ // 後退辺
                low[cur] = min(low[cur], ord[edge.to]);
            }
        }
        if(prv == -1 && child_count >= 2) flag_articulation = true;
        if(flag_articulation){
            articulations.push_back(cur);
            is_articulation[cur] = true;
        }
    }
};
