#pragma once

struct EulerianTrail{
    struct Edge{
        int from, to, id;
    };
    int V;
    int E = 0;
    bool directed;
    vector<vector<Edge>> G;
    vector<int> deg;
    EulerianTrail(int n, bool directed = true) : V(n), directed(directed) {
        G.resize(V);
        deg.resize(V);
    }

    void add_edge(int u, int v){
        if(directed){
            G[u].push_back({u, v, E});
            deg[u]++;
            deg[v]--;
        }else{
            G[u].push_back({u, v, E});
            G[v].push_back({v, u, E});
            deg[u]++;
            deg[v]++;
        }
        E++;
    }

    vector<int> trail_v, trail_e;

    bool build(){
        int s = -1, t = -1;
        if(directed){
            for(int i = 0; i < V; i++){
                if(abs(deg[i]) > 1){
                    return false;
                }else if(deg[i] == 1){
                    if(s != -1) return false;
                    s = i;
                }else if(deg[i] == -1){
                    t = i;
                }
            }
        }else{
            for(int i = 0; i < V; i++){
                if(deg[i] % 2){
                    if(s == -1){
                        s = i;
                    }else if(t == -1){
                        t = i;
                    }else{
                        return false;
                    }
                }
            }
        }
        if(s == -1){
            s = 0;
            for(int i = 0; i < V; i++){
                if(!G[i].empty()){
                    s = i;
                    break;
                }
            }
        }
        if(t == -1) t = s;

        trail_e.clear();
        trail_v.clear();

        vector<bool> used(E);
        auto dfs = [&](auto &self, int cur) -> void {
            while(G[cur].size()){
                auto e = G[cur].back();
                 G[cur].pop_back();
                if(used[e.id]){
                    continue;
                }
                used[e.id] = true;
                self(self, e.to);
                trail_e.push_back(e.id);
            }
            trail_v.push_back(cur);
        };
        dfs(dfs, s);
        reverse(trail_v.begin(), trail_v.end());
        reverse(trail_e.begin(), trail_e.end());
        if((int) trail_e.size() != E){
            trail_v.clear();
            trail_e.clear();
            return false;
        }
        return true;
    }

    vector<int> getVertex(){
        return trail_v;
    }

    vector<int> getEdge(){
        return trail_e;
    }
};
