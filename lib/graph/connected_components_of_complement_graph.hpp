#pragma once

/**
 * @brief Connected Components of Complement Graph (補グラフの連結成分分解)
 * @docs docs/graph/connected_components_of_complement_graph.md
 */

template <typename T>
vector<vector<int>> connectedComponentsOfComplementGraph(vector<vector<T>> &G){
    int n = (int) G.size();
    vector<vector<int>> ans;
    vector<bool> used(n, false), reach(n, true);
    vector<int> s(n);
    iota(s.begin(), s.end(), 0);
    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        vector<int> v;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int x = q.front(); q.pop();
            if(used[x]) continue;
            used[x] = true;
            v.push_back(x);
            for(auto y : G[x]){
                reach[y] = false;
            }
            vector<int> ts;
            while(!s.empty()){
                if(reach[s.back()]){
                    q.push(s.back());
                } else{
                    ts.push_back(s.back());
                }
                s.pop_back();
            }
            swap(s, ts);
            for(auto y : G[x]){
                reach[y] = true;
            }
        }
        ans.push_back(v);
    }
    return ans;
}
