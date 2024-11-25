#pragma once

/**
 * @brief Partition Function (分割数)
 * @see https://ladywingclover.hatenablog.com/entry/2023/04/05/153502
 */

#include "../polynomial/formal_power_series.hpp"
#include <vector>

template <typename T>
std::vector<T> partitionFunction(const int n){
    using FPS = FormalPowerSeries<T>;
    FPS f(n + 1);
    // (1 + x + x^2 + ...)(1 + x^2 + x^4 + ...)(1 + x^3 + x^6 + ...)(...)
    // N 次までで良いので、等比数列の和を考えると、
    // (1/(1 - x))(1/(1 - x^2))(1/(1 - x^3))(...)
    // = exp(log(1/(1 - x)) + log(1/(1 - x^2)) + log(1/(1 - x^3)) + ...)
    // = exp(-log(1 - x) - log(1 - x^2) - log(1 - x^3) - ...)

    std::vector<T> inv(n + 1);
    inv[1] = 1;
    long long mod = T::mod();
    for(int i = 2; i <= n; ++i){
        inv[i] = mod - inv[mod % i] * (mod / i);
    }

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            // log(1 - x) = -x - x^2/2 - x^3/3 - ...
            // -log(1 - x) = x + x^2/2 + x^3/3 + ...
            f[j] += inv[j / i];
        }
    }
    f = f.exp(n + 1);
    return std::vector<T>(std::begin(f), std::end(f));
}
