#pragma once

// 参考: https://www.slideshare.net/slideshow/trianguler/38443802
vector<array<int, 3>> enumerateTriangles(vector<vector<int>> &G){
    int n = G.size();
    vector<vector<int>> DAG(n);
    for(int i = 0; i < n; i++){
        for(auto &j : G[i]){
            pair<int, int> p = {(int) G[i].size(), i}, q = {(int) G[j].size(), j};
            if(p < q){
                DAG[i].push_back(j);
            }
        }
    }

    vector<array<int, 3>> res;
    vector<int> edge(n);
    for(int i = 0; i < n; i++){
        for(auto j : DAG[i]){
            for(auto k : DAG[i]){
                edge[k]++;
            }
            for(auto k : DAG[j]){
                if(edge[k]){
                    res.push_back({i, j, k});
                }
            }
            for(auto k : DAG[i]){
                edge[k]--;
            }
        }
    }
    return res;
}
