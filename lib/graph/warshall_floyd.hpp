#pragma once

// ワ―シャルフロイド法で全頂点間の最短距離を求めます : (O(n^3))
template <typename T>
void warshall_floyd(vector<vector<T>> &d, int n) { // nは頂点数
    for(int i = 0; i < n; i++)          // 経由する頂点
        for(int j = 0; j < n; j++)      // 開始頂点
            for(int k = 0; k < n; k++)  // 終端
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}