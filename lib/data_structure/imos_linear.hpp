#pragma once

/**
 * @brief Imos Linear (静的な一次関数の加算)
 * @docs docs/data_structure/imos_linear.md
 */

#include <vector>
#include <algorithm>

template <typename T>
struct imos_linear{
    int N;
    std::vector<T> imos1, imos0;
    imos_linear(int N) : N(N){ init(); }

    void init(){
        imos1.resize(N + 1);
        imos0.resize(N + 1);
    }

    // [l, r) に wX + v を加算
    // imos[l] += v, imos[l + 1] += v + w, ...
    void add(int l, int r, T v, T w){
        l = std::clamp(l, 0, N), r = std::clamp(r, 0, N);
        imos1[l] += w;
        imos1[r] -= w;
        imos0[l] += v - w;
        imos0[r] -= v + w * (r - l - 1);
    }

    void build(){
        for(int i = 0; i < N; i++){
            imos1[i + 1] += imos1[i];
            imos0[i] += imos1[i];
            imos0[i + 1] += imos0[i];
        }
    }

    T &operator [](int i){
        return imos0[i];
    }
};
