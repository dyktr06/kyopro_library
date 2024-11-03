#pragma once

/**
 * @brief Multipoint Evaluation (多点評価)
 * @see https://37zigen.com/multipoint-evaluation/
 */

#include "../polynomial/formal_power_series.hpp"
#include <vector>

template <typename T>
std::vector<T> multipointEvalutation(const FormalPowerSeries<T> &f, const std::vector<T> &p){
    using FPS = FormalPowerSeries<T>;
    int m = 1;
    while(m < (int) p.size()) m *= 2;
    std::vector<FPS> product_tree(m * 2, FPS({T(1)}));
    for(int i = 0; i < (int) p.size(); i++){
        // f(a) = f(x) (mod (x - a))
        product_tree[m + i] = {-p[i], T(1)};
    }
    for(int i = m - 1; i >= 1; i--){
        product_tree[i] = product_tree[i * 2] * product_tree[i * 2 + 1];
    }
    std::vector<FPS> reminder_tree(m * 2, FPS({T(0)}));
    reminder_tree[1] = f % product_tree[1];
    for(int i = 2; i < m * 2; i++){
        // (f mod (g_0 g_1)) mod g_0 = f mod g_0
        reminder_tree[i] = reminder_tree[i / 2] % product_tree[i];
        reminder_tree[i].shrink();
    }
    std::vector<T> res(p.size());
    for(int i = 0; i < (int) p.size(); i++){
        res[i] = reminder_tree[m + i][0];
    }
    return res;
}
