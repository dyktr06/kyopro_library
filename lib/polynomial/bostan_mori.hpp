#pragma once

/**
 * @brief Bostan-Mori
 * @see https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a
 */

#include <cassert>
#include <vector>
#include "../polynomial/formal_power_series.hpp"

// [x^n] f(x)/g(x) : O(d log d log n)
template <typename T>
T bostan_mori(long long n, FormalPowerSeries<T> f, FormalPowerSeries<T> g){
    using FPS = FormalPowerSeries<T>;
    assert(n >= 0);
    g.shrink();
    assert(!g.empty());
    {
        int h = 0;
        while(g[h] == T(0)) h++;
        g.erase(g.begin(), g.begin() + h);
        n += h;
    }

    if((int) g.size() == 1){
        return ((int) f.size() > n) ? f[n] / g[0] : T(0);
    }

    while(n > 0){
        FPS tmp_g = g;
        for(int i = 1; i < (int) g.size(); i += 2){
            tmp_g[i] *= -1;
        }
        FPS u = f * tmp_g;
        for(int i = 0; i < (int) f.size(); i++){
            f[i] = u[i * 2 + n % 2];
        }
        f.resize(((int) u.size() + 1 - (n % 2)) / 2);
        tmp_g *= g;
        for(int i = 0; i < (int) g.size(); i++){
            g[i] = tmp_g[i * 2];
        }
        n >>= 1;
    }
    return f[0] / g[0];
}

// a_i = sum_{j = 1}^{d} a_{i - j} * c[j] を満たす数列の k 番目の項を求める
template <typename T>
T findKthTerm(const std::vector<T> &init, const std::vector<T> &c, long long k){
    using FPS = FormalPowerSeries<T>;
    assert((int) init.size() + 1 == (int) c.size());
    FPS f(init.size()), g(c.size());
    for(int i = 0; i < (int) init.size(); i++){
        f[i] = init[i];
    }
    g[0] = 1;
    for(int i = 1; i < (int) c.size(); i++){
        g[i] = c[i] * T(-1);
    }
    f *= g;
    f.resize(init.size());
    return bostan_mori(k, f, g);
}
