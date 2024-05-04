#pragma once

/**
 * @brief Floyd-Warshall Algorithm (ワーシャルフロイド法)
 * @docs docs/graph/warshall_floyd.md
 */

template <typename T>
void warshall_floyd(vector<vector<T>> &d, const T &INF) {
    int n = d.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(d[j][i] == INF || d[i][k] == INF) continue;
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
}
