#pragma once

/**
 * @brief Taylor Shift
 * @see https://drken1215.hatenablog.com/entry/2023/09/08/003100
 */

#include "../enumerative_combinatorics/combination_modint.hpp"
#include "../polynomial/formal_power_series.hpp"
#include <vector>

// g(x) = f(x + a) となる g
template <typename T>
FormalPowerSeries<T> taylorShift(const FormalPowerSeries<T> &f, const T c) {
    const int deg = f.size();
    Combination<T> comb(deg);
    // g_j = 1/j! sum(f_{i + j} (i + j!) * (c^i / i!)) -> f_{i + j} (i + j!) と (c^i / i!) は添え字の差の畳み込み
    FormalPowerSeries<T> res = f;
    for(int i = 0; i < deg; i++){
        res[i] *= comb.fact(i);
    }
    std::reverse(std::begin(res), std::end(res));
    FormalPowerSeries<T> res2(deg, T(1));
    for(int i = 1; i < deg; i++){
        res2[i] = (res2[i - 1] * c) * comb.inv[i];
    }
    res = (res * res2).pre(deg);
    std::reverse(std::begin(res), std::end(res));
    for(int i = 0; i < deg; i++){
        res[i] *= comb.factinv(i);
    }
    return res;
}
