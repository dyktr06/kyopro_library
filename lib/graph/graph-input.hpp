#pragma once

/*
    グラフの入力を簡略化
*/
template<class T, class U>
void inGraph(vector<vector<T>> &G, U n, U m, bool directed = true, bool zero_index = true){
    G.resize(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(!zero_index) a--, b--;
        G[a].push_back(b);
        if(!directed) G[b].push_back(a);
    }
}
