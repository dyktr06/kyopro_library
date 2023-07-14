#pragma once

template <typename T>
struct BipartiteMatching{
    vector<vector<T>> G;
    vector<T> alive, match, used;
    int timestamp;

    BipartiteMatching(int n){
        G.resize(n);
        alive.assign(n, 1);
        match.assign(n, -1);
        used.assign(n, 0);
        timestamp = 0;
    }

    void add_edge(int u, int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool dfs(int v){
        used[v] = timestamp;
        for(auto &x : G[v]){
            int y = match[x];
            if(alive[x] == 0) continue;
            if(y == -1 || (used[y] != timestamp && dfs(y))){
                match[v] = x;
                match[x] = v;
                return true;
            }
        }
        return false;
    }

    int bipartite_matching(){
        int res = 0;
        for(int i = 0; i < (int) G.size(); i++){
            if(alive[i] == 0) continue;
            if(match[i] == -1){
                ++timestamp;
                res += dfs(i);
            }
        }
        return res;
    }
};