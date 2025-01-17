#pragma once

/**
 * @brief Stirling Number of the Second Kind (第 2 種スターリング数)
 */


#include "../enumerative_combinatorics/combination_modint.hpp"
#include "../polynomial/formal_power_series.hpp"

#include <vector>

template <typename T>
std::vector<T> stirling_number_2nd(int n){
    // 第 2 種スターリング数は、
    // S(n, k) = 1/k! sum_{0}^{k} (-1)^{k - i} Choose(k, i) i^n
    // = 1/k! sum_{0}^{k} (-1)^{k - i} (k!/(i)!(k - i)!) i^n
    // = sum_{0}^{k} (-1)^{k - i} 1/(i)!(k - i)! i^n
    // = sum_{0}^{k} ( (-1)^{k - i} / (k - i)! ) ( i^n / i! )
    // -> 畳み込みで計算可能
    using FPS = FormalPowerSeries<T>;
    Combination<T> comb;
    FPS f(n + 1), g(n + 1);
    for(int i = 0; i <= n; i++){
        f[i] = (i & 1) ? (-1) : 1;
        f[i] *= comb.factinv(i);

        g[i] = T(i).pow(n);
        g[i] *= comb.factinv(i);
    }
    f *= g;
    return std::vector<T>(f.begin(), f.begin() + n + 1);
}

template <typename T>
std::vector<T> stirling_number_2nd_fixed_k(int n, int k){
    // 第 2 種スターリング数の指数型母関数は、
    // (exp(x) - 1)^k / k! = sum S(n, k) x^n / n!
    using FPS = FormalPowerSeries<T>;
    FPS f({T(0), T(1)});
    f = f.exp(n + 1);
    f[0] -= 1;
    f = f.pow(k);
    T k_fact = 1;
    for(int i = 1; i <= k; i++) k_fact *= i;
    k_fact = k_fact.inv();
    T fact = 1;
    for(int i = 0; i <= n; i++){
        if(i >= 1) fact *= i;
        f[i] *= fact;
        f[i] *= k_fact;
    }
    return std::vector<T>(f.begin(), f.begin() + n + 1);
}
