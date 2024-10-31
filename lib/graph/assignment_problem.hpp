#pragma once

/**
 * @brief Assignment Problem (割当て問題)
 */

#include "../graph/primal_dual.hpp"

template <typename T>
vector<int> assignmentProblem(vector<vector<T>> &p){
    int n = p.size();
    T minA = (T) 0;
    PrimalDual<int, T> G(n * 2 + 2);
    int s = n * 2, t = n * 2 + 1;
    for(int i = 0; i < n; i++){
        G.add_edge(s, i, 1, 0);
        G.add_edge(i + n, t, 1, 0);
    }
    for(int i = 0; i < n; i++){
        assert((int) p[i].size() == n);
        for(int j = 0; j < n; j++){
            minA = min(minA, p[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            G.add_edge(i, j + n, 1, minA + p[i][j]);
        }
    }

    G.flow(s, t, n);
    auto edges = G.edges();
    vector<int> ans(n);
    for(auto &e : edges){
        if(e.from == s || e.to == t || e.flow == 0) continue;
        ans[e.from] = e.to - n;
    }
    return ans;
}
