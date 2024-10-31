#pragma once

/**
 * @brief Maximum Independent Set (最大独立集合)
 */

vector<int> maximumIndependentSet(vector<vector<int>> &G, int loop = 100000){
    const int MAX_V = 64;
    int n = G.size();
    assert(n <= MAX_V);
    vector<bitset<MAX_V>> g(n);
    for(int i = 0; i < n; i++){
        for(auto &v : G[i]){
            g[i][v] = 1;
        }
    }

    auto random_shuffle = [](vector<int> &p){
        int n = p.size();
        for(int i = n; i > 1; i--){
            int a = i - 1;
            int b = rand() % i;
            swap(p[a], p[b]);
        }
    };

    vector<int> ans;
    bitset<MAX_V> used, emp;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    for(int k = 0; k < loop; k++){
        random_shuffle(p);
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(used[p[i]]) continue;
            res.push_back(p[i]);
            used |= g[p[i]];
        }
        if(ans.size() < res.size()){
            swap(ans, res);
        }
        used &= emp;
    }
    return ans;
}
