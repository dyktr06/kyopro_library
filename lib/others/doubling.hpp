#pragma once

/**
 * @brief Doubling (ダブリング)
 */

#include <vector>

template <typename T>
struct Doubling{
    int log, n;
    std::vector<std::vector<int>> nxt;
    std::vector<std::vector<T>> cost;

    Doubling(const std::vector<int> &_nxt, const std::vector<T> &_cost, int _log = 30) : log(_log), n((int) _nxt.size()){
        nxt = std::vector<std::vector<int>>(log + 1, std::vector<int>(n));
        cost = std::vector<std::vector<T>>(log + 1, std::vector<T>(n));
        nxt[0] = _nxt;
        cost[0] = _cost;

        for(int i = 1; i <= log; i++){
            for(int j = 0; j < n; j++){
                nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
                cost[i][j] = cost[i - 1][j] + cost[i - 1][nxt[i - 1][j]];
            }
        }
    }

    // v から k 回移動した後の位置とコスト
    std::pair<int, T> get(int v, T k){
        T c = T(0);
        int cur = v;
        for(int i = 0; i <= log; i++){
            if((k >> i) & 1){
                c += cost[i][cur];
                cur = nxt[i][cur];
            }
        }
        return {cur, c};
    }

    // v からコストが c 以下で到達できる最大の位置とその回数
    std::pair<int, T> girigiri(int v, T c){
        T k = 0;
        int cur = v;
        for(int i = log; i >= 0; i--){
            if(cost[i][cur] <= c){
                c -= cost[i][cur];
                cur = nxt[i][cur];
                k += ((T) 1 << i);
            }
        }
        return {cur, k};
    }
};
