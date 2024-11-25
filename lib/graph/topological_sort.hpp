#pragma once

/**
 * @brief Topological Sort
 * @docs docs/graph/topological_sort.md
 */

#include <vector>
#include <queue>

template <typename T>
std::vector<T> topological_sort(const std::vector<std::vector<T>> &G){
    int siz = (int) G.size();
    std::vector<int> indegree(siz);
    for(int i = 0; i < siz; i++){
        for(auto x : G[i]){
            indegree[x]++;
        }
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
    for(int i = 0; i < siz; i++){
        if(indegree[i] == 0){
            heap.push(i);
        }
    }

    std::vector<T> res;
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
