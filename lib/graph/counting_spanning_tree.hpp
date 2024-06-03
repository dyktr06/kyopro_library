#pragma once

#include "../math/matrix.hpp"

template <typename T>
T countingSpanningTree(const vector<vector<int>> &G, int root = 0){
    const int n = G.size();
    Matrix<mint> mat(n, n), dmat(n - 1, n - 1);
    // ラプラシアン行列を作る
    for(int i = 0; i < n; i++){
        for(auto &j : G[i]){
            if(i == j) continue;
            mat[i][j] -= 1;
            mat[j][j] += 1;
        }
    }

    // 余因子を求める
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != root && j != root){
                dmat[i - (i > root ? 1 : 0)][j - (j > root ? 1 : 0)] = mat[i][j];
            }
        }
    }
    return dmat.det();
}
