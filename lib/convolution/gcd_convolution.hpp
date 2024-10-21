#pragma once

#include "../convolution/divisor_zeta_mobius_transform.hpp"

// 参考: https://noshi91.hatenablog.com/entry/2018/12/27/121649
template <typename T>
vector<T> gcd_convolution(vector<T> f, vector<T> g){
    const int n = (int) f.size();
    assert(f.size() == g.size());
    assert(1 <= n);
    divisor_reversed_zeta_transform(f);
    divisor_reversed_zeta_transform(g);
    for(int i = 1; i < n; ++i){
        f[i] *= g[i];
    }
    divisor_reversed_mobius_transform(f);
    return f;
}
