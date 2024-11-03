#pragma once

/**
 * @brief Subset Sum
 * @see https://suu-0313.hatenablog.com/entry/2022/04/12/225153
 */

#include "../polynomial/formal_power_series.hpp"
#include <vector>

template <typename T>
std::vector<T> subsetSum(std::vector<long long> s, const int t_max){
    using FPS = FormalPowerSeries<T>;
    // prod (1 + x^{s_i}) -> exp(sum log(1 + x^{s_i}))
    std::vector<T> cnt(t_max + 1, T(0));
    for(auto x : s){
        if(x > t_max) continue;
        cnt[x]++;
    }

    std::vector<T> inv(t_max + 1);
    inv[1] = 1;
    long long mod = T::mod();
    for(int i = 2; i <= t_max; ++i){
        inv[i] = mod - inv[mod % i] * (mod / i);
    }

    FPS ans(t_max + 1);
    for(int i = 1; i <= t_max; i++){
        if(cnt[i] == T(0)) continue;
        // log(1 + x^i) = x^i - x^(2i)/2 + x^(3i)/3 - ...
        T sign = T(1);
        for(int j = i; j <= t_max; j += i){
            ans[j] += T(cnt[i]) * sign * inv[j / i];
            sign *= T(-1);
        }
    }
    ans = ans.exp();
    std::vector<T> res(t_max + 1, T(0));
    for(int i = 0; i <= t_max; i++){
        res[i] = ans[i];
    }
    return res;
}
