#pragma once

/**
 * @brief Bitwise OR Convolution
 */

#include <vector>
#include <cassert>

#include "../convolution/set_zeta_mobius_transform.hpp"

template <typename T>
std::vector<T> bitwise_or_convolution(std::vector<T> f, std::vector<T> g){
    const int n = (int) f.size();
    assert(f.size() == g.size());
    assert((n & (n - 1)) == 0);
    subset_zeta_transform(f);
    subset_zeta_transform(g);
    for(int i = 0; i < n; ++i){
        f[i] *= g[i];
    }
    subset_mobius_transform(f);
    return f;
}
