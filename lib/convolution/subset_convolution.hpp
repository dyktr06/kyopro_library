#pragma once

#include <vector>
#include <array>
#include <cassert>

template <typename T, int MAX_RANK>
std::vector<std::array<T, MAX_RANK>> ranked_zeta_transform(const std::vector<T> &f){
    int N = f.size();
    std::vector<std::array<T, MAX_RANK>> fr(N);
    for(int i = 0; i < N; i++) fr[i][__builtin_popcount(i)] = f[i];
    for(int k = 1; k < N; k <<= 1){
        for(int i = k; i < N; i = (i + 1) | k){
            for(int p = 0; p < MAX_RANK; p++){
                fr[i][p] += fr[i ^ k][p];
            }
        }
    }
    return fr;
}

template <typename T, int MAX_RANK>
std::vector<T> ranked_mobius_transform(std::vector<std::array<T, MAX_RANK>> fr) {
    int N = fr.size();
    for(int k = 1; k < N; k <<= 1){
        for(int i = k; i < N; i = (i + 1) | k){
            for(int p = 0; p < MAX_RANK; p++){
                fr[i][p] -= fr[i ^ k][p];
            }
        }
    }
    std::vector<T> f(N);
    for(int i = 0; i < N; i++) f[i] = fr[i][__builtin_popcount(i)];
    return f;
}

template <typename T, int MAX_RANK>
std::vector<T> subset_convolution(const std::vector<T> &f, const std::vector<T> &g){
    const int N = f.size(), n = __builtin_ctz(f.size());
    assert(f.size() == g.size());
    assert((N & (N - 1)) == 0);
    assert(MAX_RANK >= n);
    auto fr = ranked_zeta_transform<T, MAX_RANK + 1>(f);
    auto gr = ranked_zeta_transform<T, MAX_RANK + 1>(g);
    for(int i = 0; i < N; i++){
        for(int p = MAX_RANK; p >= 0; p--){
            for(int q = MAX_RANK - p; q > 0; q--){
                fr[i][p + q] += fr[i][p] * gr[i][q];
            }
            fr[i][p] *= gr[i][0];
        }
    }
    return ranked_mobius_transform<T, MAX_RANK + 1>(std::move(fr));
}
