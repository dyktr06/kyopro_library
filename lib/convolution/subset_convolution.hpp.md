---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/set_power_series/subset_convolution.test.cpp
    title: test/library_checker/set_power_series/subset_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/convolution/subset_convolution.hpp\"\n\n#include <vector>\n\
    #include <array>\n#include <cassert>\n\ntemplate <typename T, int MAX_RANK>\n\
    std::vector<std::array<T, MAX_RANK>> ranked_zeta_transform(const std::vector<T>\
    \ &f){\n    int N = f.size();\n    std::vector<std::array<T, MAX_RANK>> fr(N);\n\
    \    for(int i = 0; i < N; i++) fr[i][__builtin_popcount(i)] = f[i];\n    for(int\
    \ k = 1; k < N; k <<= 1){\n        for(int i = k; i < N; i = (i + 1) | k){\n \
    \           for(int p = 0; p < MAX_RANK; p++){\n                fr[i][p] += fr[i\
    \ ^ k][p];\n            }\n        }\n    }\n    return fr;\n}\n\ntemplate <typename\
    \ T, int MAX_RANK>\nstd::vector<T> ranked_mobius_transform(std::vector<std::array<T,\
    \ MAX_RANK>> fr) {\n    int N = fr.size();\n    for(int k = 1; k < N; k <<= 1){\n\
    \        for(int i = k; i < N; i = (i + 1) | k){\n            for(int p = 0; p\
    \ < MAX_RANK; p++){\n                fr[i][p] -= fr[i ^ k][p];\n            }\n\
    \        }\n    }\n    std::vector<T> f(N);\n    for(int i = 0; i < N; i++) f[i]\
    \ = fr[i][__builtin_popcount(i)];\n    return f;\n}\n\ntemplate <typename T, int\
    \ MAX_RANK>\nstd::vector<T> subset_convolution(const std::vector<T> &f, const\
    \ std::vector<T> &g){\n    const int N = f.size(), n = __builtin_ctz(f.size());\n\
    \    assert(f.size() == g.size());\n    assert((N & (N - 1)) == 0);\n    assert(MAX_RANK\
    \ >= n);\n    auto fr = ranked_zeta_transform<T, MAX_RANK + 1>(f);\n    auto gr\
    \ = ranked_zeta_transform<T, MAX_RANK + 1>(g);\n    for(int i = 0; i < N; i++){\n\
    \        for(int p = MAX_RANK; p >= 0; p--){\n            for(int q = MAX_RANK\
    \ - p; q > 0; q--){\n                fr[i][p + q] += fr[i][p] * gr[i][q];\n  \
    \          }\n            fr[i][p] *= gr[i][0];\n        }\n    }\n    return\
    \ ranked_mobius_transform<T, MAX_RANK + 1>(std::move(fr));\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <array>\n#include <cassert>\n\
    \ntemplate <typename T, int MAX_RANK>\nstd::vector<std::array<T, MAX_RANK>> ranked_zeta_transform(const\
    \ std::vector<T> &f){\n    int N = f.size();\n    std::vector<std::array<T, MAX_RANK>>\
    \ fr(N);\n    for(int i = 0; i < N; i++) fr[i][__builtin_popcount(i)] = f[i];\n\
    \    for(int k = 1; k < N; k <<= 1){\n        for(int i = k; i < N; i = (i + 1)\
    \ | k){\n            for(int p = 0; p < MAX_RANK; p++){\n                fr[i][p]\
    \ += fr[i ^ k][p];\n            }\n        }\n    }\n    return fr;\n}\n\ntemplate\
    \ <typename T, int MAX_RANK>\nstd::vector<T> ranked_mobius_transform(std::vector<std::array<T,\
    \ MAX_RANK>> fr) {\n    int N = fr.size();\n    for(int k = 1; k < N; k <<= 1){\n\
    \        for(int i = k; i < N; i = (i + 1) | k){\n            for(int p = 0; p\
    \ < MAX_RANK; p++){\n                fr[i][p] -= fr[i ^ k][p];\n            }\n\
    \        }\n    }\n    std::vector<T> f(N);\n    for(int i = 0; i < N; i++) f[i]\
    \ = fr[i][__builtin_popcount(i)];\n    return f;\n}\n\ntemplate <typename T, int\
    \ MAX_RANK>\nstd::vector<T> subset_convolution(const std::vector<T> &f, const\
    \ std::vector<T> &g){\n    const int N = f.size(), n = __builtin_ctz(f.size());\n\
    \    assert(f.size() == g.size());\n    assert((N & (N - 1)) == 0);\n    assert(MAX_RANK\
    \ >= n);\n    auto fr = ranked_zeta_transform<T, MAX_RANK + 1>(f);\n    auto gr\
    \ = ranked_zeta_transform<T, MAX_RANK + 1>(g);\n    for(int i = 0; i < N; i++){\n\
    \        for(int p = MAX_RANK; p >= 0; p--){\n            for(int q = MAX_RANK\
    \ - p; q > 0; q--){\n                fr[i][p + q] += fr[i][p] * gr[i][q];\n  \
    \          }\n            fr[i][p] *= gr[i][0];\n        }\n    }\n    return\
    \ ranked_mobius_transform<T, MAX_RANK + 1>(std::move(fr));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/convolution/subset_convolution.hpp
  requiredBy: []
  timestamp: '2025-02-28 02:51:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/set_power_series/subset_convolution.test.cpp
documentation_of: lib/convolution/subset_convolution.hpp
layout: document
redirect_from:
- /library/lib/convolution/subset_convolution.hpp
- /library/lib/convolution/subset_convolution.hpp.html
title: lib/convolution/subset_convolution.hpp
---
