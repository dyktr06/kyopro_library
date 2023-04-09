---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1_5_a.test.cpp
    title: test/aoj/alds1/alds1_5_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/others/exhaustive_search.md
    document_title: "Exhaustive Search (bit \u5168\u63A2\u7D22)"
    links: []
  bundledCode: "#line 2 \"lib/others/exhaustive_search.hpp\"\n\n/**\n * @brief Exhaustive\
    \ Search (bit \u5168\u63A2\u7D22)\n * @docs docs/others/exhaustive_search.md\n\
    \ */\n\ntemplate<typename T>\nvector<long long> sum_subsets(T a){\n    vector<long\
    \ long> res;\n    int n = a.size();\n    for(int bit = 0; bit < (1 << n); bit++){\n\
    \        long long sum = 0;\n        for(int i = 0; i < n; i++){\n           \
    \ int mask = 1 << i;\n            if(bit & mask){\n                sum += a[i];\n\
    \            }\n        }\n        res.emplace_back(sum);\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n\n/**\n * @brief Exhaustive Search (bit \u5168\u63A2\u7D22\
    )\n * @docs docs/others/exhaustive_search.md\n */\n\ntemplate<typename T>\nvector<long\
    \ long> sum_subsets(T a){\n    vector<long long> res;\n    int n = a.size();\n\
    \    for(int bit = 0; bit < (1 << n); bit++){\n        long long sum = 0;\n  \
    \      for(int i = 0; i < n; i++){\n            int mask = 1 << i;\n         \
    \   if(bit & mask){\n                sum += a[i];\n            }\n        }\n\
    \        res.emplace_back(sum);\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/exhaustive_search.hpp
  requiredBy: []
  timestamp: '2023-01-23 00:47:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/alds1/alds1_5_a.test.cpp
documentation_of: lib/others/exhaustive_search.hpp
layout: document
redirect_from:
- /library/lib/others/exhaustive_search.hpp
- /library/lib/others/exhaustive_search.hpp.html
title: "Exhaustive Search (bit \u5168\u63A2\u7D22)"
---
## Exhaustive Search (bit 全探索)

#### 概要

a の部分集合の和の組み合わせをすべて列挙します。

bit 全探索のサンプルコードです。

#### 計算量

a の要素数を $N$ とすると、$\mathrm{O}(N 2^N)$