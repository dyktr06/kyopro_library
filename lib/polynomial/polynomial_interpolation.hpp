#pragma once

/**
 * @brief Polynomial Interpolation (多項式補間)
 * @see https://37zigen.com/lagrange-interpolation/
 */

#include "../polynomial/formal_power_series.hpp"
#include "../polynomial/multipoint_evaluation.hpp"
#include <vector>

template <typename T>
FormalPowerSeries<T> polynomialInterpolation(const std::vector<T> &x, const std::vector<T> &y){
    using FPS = FormalPowerSeries<T>;
    assert(x.size() == y.size());
    int n = 1;
    while(n < (int) x.size()) n *= 2;
    std::vector<FPS> product_tree(n * 2, FPS({T(1)}));
    for(int i = 0; i < (int) x.size(); i++){
        product_tree[n + i] = {-x[i], T(1)};
    }
    for(int i = n - 1; i >= 1; i--){
        product_tree[i] = product_tree[i * 2] * product_tree[i * 2 + 1];
    }
    // g = procuct_tree[1]
    FPS g_d = product_tree[1].diff();
    std::vector<T> p = multipointEvalutation(g_d, x);

    std::vector<FPS> f(n * 2, FPS({T(0)}));
    for(int i = 0; i < (int) x.size(); i++){
        f[n + i] = FPS({y[i] / p[i]});
    }
    for(int i = n - 1; i >= 1; i--){
        // 通分
        f[i] = (f[i * 2] * product_tree[i * 2 + 1]) + (f[i * 2 + 1] * product_tree[i * 2]);
    }
    // g * f / g = f
    return f[1].pre(n);
}
