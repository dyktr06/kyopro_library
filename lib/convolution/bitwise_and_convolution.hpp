#pragma once

#include "../convolution/superset_zeta_moebius_transform.hpp"

template <typename T>
vector<T> bitwise_and_convolution(vector<T> f, vector<T> g){
    const int n = (int) f.size();
    assert(f.size() == g.size());
    assert((n & (n - 1)) == 0);
    superset_zeta_transform(f);
    superset_zeta_transform(g);
    for(int i = 0; i < n; ++i){
        f[i] *= g[i];
    }
    superset_mobius_transform(f);
    return f;
}
