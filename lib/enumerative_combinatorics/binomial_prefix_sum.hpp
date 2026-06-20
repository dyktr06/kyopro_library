#pragma once

/**
 * @brief Binomial Prefix Sum (二項係数の累積和)
 */

#include "../data_structure/mo.hpp"
#include "../enumerative_combinatorics/combination_modint.hpp"

// sum_{i=0}^{r-1} binom(n, i)
template <typename T, typename U>
std::vector<T> binomialPrefixSum(const std::vector<U> &query){
    Combination<T> comb;
    int q = query.size();
    std::vector<T> res(q);
    int max_n = 0;
    for(auto [q1, q2] : query) max_n = std::max(max_n, (int) q1);
    Mo mo(max_n + 1);
    for(auto [q1, q2] : query) mo.add(q1, q2);
    T s = 0, inv2 = T(2).inv();
    int n = 0, r = -1;
    auto addL = [&](int i){
        // n -> n + 1
        //   sum_{i=0}^{r} binom(n + 1, i)
        // = sum_{i=0}^{r} (binom(n, i) + binom(n, i - 1))
        // = -binom(n, r) + 2 * sum_{i=0}^{r} binom(n, i)
        s *= 2;
        s -= comb.ncr(n, r);
        n++;
    };
    auto eraseL = [&](int i){
        n--;
        s += comb.ncr(n, r);
        s *= inv2;
    };
    auto addR = [&](int i){
        // r -> r + 1
        r++;
        s += comb.ncr(n, r);
    };
    auto eraseR = [&](int i){
        // r -> r - 1
        s -= comb.ncr(n, r);
        r--;
    };
    auto output = [&](int q){
        res[q] = s;
    };
    mo.build(eraseL, addR, addL, eraseR, output);
    return res;
}

// sum_{i=0}^{r-1} binom(n, i) i
template <typename T, typename U>
std::vector<std::pair<T, T>> binomialPrefixSum2(const std::vector<U> &query){
    Combination<T> comb;
    int q = query.size();
    std::vector<std::pair<T, T>> res(q);
    int max_n = 0;
    for(auto [q1, q2] : query) max_n = std::max(max_n, (int) q1);
    Mo mo(max_n + 1);
    for(auto [q1, q2] : query) mo.add(q1, q2);
    T s1 = 0, s2 = 0, inv2 = T(2).inv() = 0;
    int n = 0, r = -1;
    auto addL = [&](int i){
        // n -> n + 1
        //   sum_{i=0}^{r} binom(n + 1, i) i
        // = sum_{i=0}^{r} (binom(n, i) i + binom(n, i - 1) (i - 1) + binom(n, i - 1) (1))
        // = -binom(n, r) * r + 2 * sum_{i=0}^{r} binom(n, i) i + sum_{i=0}^{r} binom(n, i) - binom(n, r)
        // = -binom(n, r) * (r + 1) + 2 * sum_{i=0}^{r} binom(n, i) i + sum_{i=0}^{r} binom(n, i)
        T binom = comb.ncr(n, r);
        s2 *= 2;
        s2 -= binom * (r + 1);
        s2 += s1;
        s1 *= 2;
        s1 -= binom;
        n++;
    };
    auto eraseL = [&](int i){
        n--;
        T binom = comb.ncr(n, r);
        s1 += binom;
        s1 *= inv2;
        s2 -= s1;
        s2 += binom * (r + 1);
        s2 *= inv2;
    };
    auto addR = [&](int i){
        // r -> r + 1
        r++;
        T binom = comb.ncr(n, r);
        s1 += binom;
        s2 += binom * (r);
    };
    auto eraseR = [&](int i){
        // r -> r - 1
        T binom = comb.ncr(n, r);
        s1 -= binom;
        s2 -= binom * (r);
        r--;
    };
    auto output = [&](int q){
        res[q] = std::make_pair(s1, s2);
    };
    mo.build(eraseL, addR, addL, eraseR, output);
    return res;
}
