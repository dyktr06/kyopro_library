#pragma once

#include "../data_structure/union_find.hpp"

/**
 * @brief Manhattan MST
 * @docs docs/graph/manhattanMST.md
 */

template <typename T>
vector<pair<int, int>> manhattanMST(vector<T> x, vector<T> y){
    int n = x.size();
    vector<tuple<T, int, int>> edge;
    edge.reserve(4 * n);
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    for(int s = 0; s < 2; ++s){
        for(int t = 0; t < 2; ++t){
            sort(idx.begin(), idx.end(), [&](const int i, const int j) {
                return x[i] + y[i] < x[j] + y[j];
            });
            map<T, int, greater<>> map;
            for(const int i : idx){
                for(auto iter = map.lower_bound(y[i]); iter != map.end(); iter = map.erase(iter)){
                    const int j = iter->second;
                    const T dx = x[i] - x[j];
                    const T dy = y[i] - y[j];
                    if(dy > dx) break;
                    edge.emplace_back(dx + dy, i, j);
                }
                map[y[i]] = i;
            }
            swap(x, y);
        }
        for(int i = 0; i < n; ++i) {
            x[i] *= -1;
        }
    }
    sort(edge.begin(), edge.end());
    UnionFind dsu(n);
    vector<pair<int, int>> used;
    used.reserve(n - 1);
    for(const auto &[c, i, j] : edge){
        if(!dsu.same(i, j)){
            used.emplace_back(i, j);
            dsu.unite(i, j);
        }
    }
    return used;
}
