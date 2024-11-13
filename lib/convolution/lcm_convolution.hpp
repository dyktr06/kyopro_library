#pragma once

/**
 * @brief LCM Convolution
 */

#include <vector>
#include <cassert>

#include "../convolution/divisor_zeta_mobius_transform.hpp"

template <typename T>
std::vector<T> lcm_convolution(std::vector<T> f, std::vector<T> g){
    const int n = (int) f.size();
    assert(f.size() == g.size());
    assert(1 <= n);
    divisor_zeta_transform(f);
    divisor_zeta_transform(g);
    for(int i = 1; i < n; ++i){
        f[i] *= g[i];
    }
    divisor_mobius_transform(f);
    return f;
}
