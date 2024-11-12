#pragma once

/**
 * @brief Bell Number (ベル数)
 */

#include "../polynomial/formal_power_series.hpp"
#include <vector>

template <typename T>
std::vector<T> bellNumber(const int n){
    using FPS = FormalPowerSeries<T>;
    // ベル数 B_i は、関数 e^{e^x - 1} = sum ((B_n / n!) x^n) として定義される
    FPS f = {0, 1};
    f = f.exp(n + 1);
    f[0] -= 1;
    f = f.exp(n + 1);

    T fact = 1;
    for(int i = 0; i <= n; i++){
        if(i) fact *= i;
        f[i] *= fact;
    }
    return std::vector<T>(std::begin(f), std::end(f));
}
