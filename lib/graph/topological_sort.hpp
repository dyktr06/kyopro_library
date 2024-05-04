#pragma once

/**
 * @brief Topological Sort
 * @docs docs/graph/topological_sort.md
 */

template <typename T>
vector<T> topological_sort(const vector<vector<T>> &G){
    int siz = (int) G.size();
    vector<int> indegree(siz);
    for(int i = 0; i < siz; i++){
        for(auto x : G[i]){
            indegree[x]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 0; i < siz; i++){
        if(indegree[i] == 0){
            heap.push(i);
        }
    }

    vector<T> res;
    while(!heap.empty()){
        int node = heap.top();
        heap.pop();
        res.push_back(node);
        for(auto x : G[node]){
            indegree[x]--;
            if(indegree[x] == 0){
                heap.push(x);
            }
        }
    }
    return res;
}
