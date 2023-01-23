---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/dp/longest_increasing_subsequence.test.cpp
    title: test/library_checker/dp/longest_increasing_subsequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/dp/LIS.md
    document_title: Longest Increasing Subsequence
    links: []
  bundledCode: "#line 2 \"lib/dp/LIS.hpp\"\n\n/**\n * @brief Longest Increasing Subsequence\n\
    \ * @docs docs/dp/LIS.md\n */\n\ntemplate <typename T>\nint LIS(vector<T> a, \
    \ bool is_strong = true){\n    const long long INF = 0x1fffffffffffffff;\n   \
    \ int n = (int) a.size();\n    vector<long long> dp(n, INF);\n    for(int i =\
    \ 0; i < n; ++i){\n        if (is_strong) *lower_bound(dp.begin(), dp.end(), a[i])\
    \ = a[i];\n        else *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];\n   \
    \ }\n    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();\n}\n\ntemplate\
    \ <typename T>\nvector<int> construct_LIS(vector<T> a,  bool is_strong = true){\n\
    \    const long long INF = 0x1fffffffffffffff;\n    int n = (int) a.size();\n\
    \    vector<long long> dp(n, INF);\n    vector<vector<int>> idx(n);\n    for(int\
    \ i = 0; i < n; ++i){\n        if(is_strong){\n             auto iter = lower_bound(dp.begin(),\
    \ dp.end(), a[i]);\n            *iter = a[i];\n            idx[(int) (iter - dp.begin())].emplace_back(i);\n\
    \        }else{\n            auto iter = upper_bound(dp.begin(), dp.end(), a[i]);\n\
    \            *iter = a[i];\n            idx[(int) (iter - dp.begin())].emplace_back(i);\n\
    \        }\n    }\n    int k = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();\n\
    \    vector<int> res;\n    int now = n;\n    for(int i = k - 1; i >= 0; --i){\n\
    \        auto iter = upper_bound(idx[i].begin(), idx[i].end(), now);\n       \
    \ iter--;\n        now = *iter;\n        res.push_back(now);\n    }\n    reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Longest Increasing Subsequence\n * @docs docs/dp/LIS.md\n\
    \ */\n\ntemplate <typename T>\nint LIS(vector<T> a,  bool is_strong = true){\n\
    \    const long long INF = 0x1fffffffffffffff;\n    int n = (int) a.size();\n\
    \    vector<long long> dp(n, INF);\n    for(int i = 0; i < n; ++i){\n        if\
    \ (is_strong) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];\n        else *upper_bound(dp.begin(),\
    \ dp.end(), a[i]) = a[i];\n    }\n    return lower_bound(dp.begin(), dp.end(),\
    \ INF) - dp.begin();\n}\n\ntemplate <typename T>\nvector<int> construct_LIS(vector<T>\
    \ a,  bool is_strong = true){\n    const long long INF = 0x1fffffffffffffff;\n\
    \    int n = (int) a.size();\n    vector<long long> dp(n, INF);\n    vector<vector<int>>\
    \ idx(n);\n    for(int i = 0; i < n; ++i){\n        if(is_strong){\n         \
    \    auto iter = lower_bound(dp.begin(), dp.end(), a[i]);\n            *iter =\
    \ a[i];\n            idx[(int) (iter - dp.begin())].emplace_back(i);\n       \
    \ }else{\n            auto iter = upper_bound(dp.begin(), dp.end(), a[i]);\n \
    \           *iter = a[i];\n            idx[(int) (iter - dp.begin())].emplace_back(i);\n\
    \        }\n    }\n    int k = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();\n\
    \    vector<int> res;\n    int now = n;\n    for(int i = k - 1; i >= 0; --i){\n\
    \        auto iter = upper_bound(idx[i].begin(), idx[i].end(), now);\n       \
    \ iter--;\n        now = *iter;\n        res.push_back(now);\n    }\n    reverse(res.begin(),\
    \ res.end());\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/dp/LIS.hpp
  requiredBy: []
  timestamp: '2023-01-23 12:51:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/dp/longest_increasing_subsequence.test.cpp
documentation_of: lib/dp/LIS.hpp
layout: document
redirect_from:
- /library/lib/dp/LIS.hpp
- /library/lib/dp/LIS.hpp.html
title: Longest Increasing Subsequence
---
## Longest Increasing Subsequence

#### 概要

配列の最長増加部分列の長さを求めます。

$dp[i]$: 長さが i の増加部分列として最後尾の要素のとりうる最小値
とすると計算できる。

#### 使い方

- `LIS(a, is_strong)`: 配列 a の最長増加部分列の長さを求めます。(is_strong = false のとき、広義最長増加部分列)
- `construct_LIS(a, is_strong)`: 配列 a の最長増加部分列を構築します。

#### 計算量

配列の要素数を $N$ とする。
- `LIS(a, is_strong)`: $\mathrm{O}(N \log N)$
- `construct_LIS(a, is_strong)`: $\mathrm{O}(N \log N)$