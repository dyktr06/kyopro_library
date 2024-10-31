#pragma once

vector<vector<int>> enumerateCliques(vector<vector<int>> &G){
    int n = G.size();
    vector<pair<int, int>> deg(n);
    for(int i = 0; i < n; i++){
        deg[i] = {(int) G[i].size(), i};
    }

    vector<vector<bool>> adj(n, vector<bool>(n));
    for(int i = 0; i < n; i++){
        for(auto &j : G[i]){
            adj[i][j] = adj[j][i] = true;
        }
    }

    // 次数が √2m 未満かどうかで場合分け -> 次数が低い頂点から処理をしても十分高速 (O(2^(√2m) * n^2))
    sort(deg.begin(), deg.end());
    vector<vector<int>> res;
    for(int i = 0; i < n; i++){
        int cur = deg[i].second;
        vector<int> nxt;
        for(int j = 0; j < n; j++){
            if(adj[cur][j]){
                nxt.push_back(j);
            }
        }
        int d = nxt.size();
        for(int bit = 0; bit < (1 << d); bit++){
            vector<int> s = {cur};
            for(int j = 0; j < d; j++){
                if(bit & (1 << j)){
                    s.push_back(nxt[j]);
                }
            }
            bool is_ok = true;
            for(auto x : s){
                for(auto y : s){
                    if(x == y) continue;
                    if(adj[x][y] == 0){
                        is_ok = false;
                    }
                }
            }
            if(is_ok){
                res.push_back(s);
            }
        }
        for(int j = 0; j < d; j++){
            adj[cur][nxt[j]] = adj[nxt[j]][cur] = false;
        }
    }
    return res;
}
