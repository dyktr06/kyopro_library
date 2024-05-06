#pragma once

/**
 * @brief Tree Diameter (木の直径)
 * @docs docs/graph/tree_diameter.md
 */

template <typename T>
struct TreeDiameter{
    using Graph = vector<vector<pair<int, T>>>;
    Graph G;
    vector<int> dist, dist2;
    int V, root, diam = -1;
    pair<int, int> ep;

    TreeDiameter(int n) : V(n){
        G.resize(n);
    }

    void add_edge(int u, int v, T w = 1){
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    void build(int _root = 0){
        root = _root;
        dist.assign(V, -1); dist2.assign(V, -1);
        dfs(G, root, -1, 0);
        int mx = 0;
        for(int i = 0; i < V; i++){
            if(mx < dist[i]){
                mx = dist[i];
                ep.first = i;
            }
        }

        dfs2(G, ep.first, -1, 0);
        for(int i = 0; i < V; i++){
            if(diam < dist2[i]){
                diam = dist2[i];
                ep.second = i;
            }
        }
    }

    void dfs(const Graph &G, int v, int p, int d){
        dist[v] = d;
        for(auto [e, w] : G[v]){
            if(e != p) dfs(G, e, v, d + w);
        }
    }

    void dfs2(const Graph &G, int v, int p, int d){
        dist2[v] = d;
        for(auto [e, w] : G[v]){
            if(e != p) dfs2(G, e, v, d + w);
        }
    }

    int diameter(){
        return diam;
    }

    pair<int, int> endpoint(){
        return ep;
    }
};
