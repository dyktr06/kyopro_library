#pragma once

/**
 * @brief Bernoulli Number (ベルヌーイ数)
 */

#include "../polynomial/formal_power_series.hpp"
#include <vector>

template <typename T>
std::vector<T> bernoulliNumber(const int n){
    using FPS = FormalPowerSeries<T>;
    // ベルヌーイ数 B_i は、関数 x/(exp(x) - 1) = sum ((B_n / n!) x^n) として定義される
    // inv((exp(x) - 1)/x) の係数を求めればよい
    FPS f(n + 1);
    std::vector<T> inv(n + 2), invfact(n + 2);
    inv[1] = 1;
    invfact[0] = invfact[1] = 1;
    long long mod = T::mod();
    for(int i = 2; i <= n + 1; ++i){
        inv[i] = mod - inv[mod % i] * (mod / i);
        invfact[i] = invfact[i - 1] * inv[i];
    }
    for(int i = 0; i <= n; i++){
        // exp(x) - 1 = x + x^2/2! + x^3/3! + ...
        // (exp(x) - 1)/x = 1 + x/2! + x^2/3! + ...
        f[i] = invfact[i + 1];
    }
    f = f.inv(n + 1);
    T fact = 1;
    for(int i = 0; i <= n; i++){
        if(i >= 1) fact *= i;
        f[i] *= fact;
    }
    return std::vector<T>(std::begin(f), std::end(f));
}
