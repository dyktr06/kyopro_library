---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/chromatic_number.test.cpp
    title: test/library_checker/graph/chromatic_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/chromatic_number.md
    document_title: "Chromatic Number (\u5F69\u8272\u6570)"
    links:
    - https://www.slideshare.net/wata_orz/ss-12131479
  bundledCode: "#line 2 \"lib/graph/chromatic_number.hpp\"\n\n/**\n * @brief Chromatic\
    \ Number (\u5F69\u8272\u6570)\n * @docs docs/graph/chromatic_number.md\n * @see\
    \ https://www.slideshare.net/wata_orz/ss-12131479\n */\n\nint chromaticNumber(vector<vector<int>>\
    \ &G) {\n    int n = G.size();\n    vector<int> adj(n);\n    for(int i = 0; i\
    \ < n; i++){\n        for(auto &j : G[i]){\n            adj[i] |= 1 << j;\n  \
    \      }\n    }\n\n    // dp[S] ... S \u306E\u90E8\u5206\u96C6\u5408\u3067\u72EC\
    \u7ACB\u306A\u3082\u306E\u306E\u500B\u6570\n    vector<int> dp(1 << n, 0);\n \
    \   dp[0] = 1;\n    for(int S = 1; S < (1 << n); S++){\n        int i = __builtin_ctz(S);\n\
    \        dp[S] = dp[S ^ (1 << i)] + dp[(S ^ (1 << i)) & (~adj[i])];\n    }\n\n\
    \    // \u5305\u9664\u539F\u7406\n    vector<int> cnt((1 << n) + 1, 0);\n    for(int\
    \ S = 0; S < (1 << n); S++){\n        cnt[dp[S]] += __builtin_parity(S) ? 1 :\
    \ -1;\n    }\n\n    vector<pair<long long, long long>> f;\n    for(int i = 0;\
    \ i <= (1 << n); i++){\n        if(cnt[i] != 0){\n            f.emplace_back(i,\
    \ cnt[i]);\n        }\n    }\n\n    int ans = n;\n    constexpr long long MODS[]\
    \ = {1000000007, 1000000009, 1000000021};\n    for(int i = 0; i < 3; i++){\n \
    \       auto nf = f;\n        for(int k = 1; k <= n; k++){\n            if(ans\
    \ <= k) break;\n            // k \u5F69\u8272\u3059\u308B\u901A\u308A\u6570\n\
    \            long long sum = 0;\n            for(auto &[x, y] : nf){\n       \
    \         sum += (y = y * x % MODS[i]);\n                sum %= MODS[i];\n   \
    \         }\n            if(sum != 0) ans = min(ans, k);\n        }\n    }\n \
    \   return ans;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Chromatic Number (\u5F69\u8272\u6570)\n *\
    \ @docs docs/graph/chromatic_number.md\n * @see https://www.slideshare.net/wata_orz/ss-12131479\n\
    \ */\n\nint chromaticNumber(vector<vector<int>> &G) {\n    int n = G.size();\n\
    \    vector<int> adj(n);\n    for(int i = 0; i < n; i++){\n        for(auto &j\
    \ : G[i]){\n            adj[i] |= 1 << j;\n        }\n    }\n\n    // dp[S] ...\
    \ S \u306E\u90E8\u5206\u96C6\u5408\u3067\u72EC\u7ACB\u306A\u3082\u306E\u306E\u500B\
    \u6570\n    vector<int> dp(1 << n, 0);\n    dp[0] = 1;\n    for(int S = 1; S <\
    \ (1 << n); S++){\n        int i = __builtin_ctz(S);\n        dp[S] = dp[S ^ (1\
    \ << i)] + dp[(S ^ (1 << i)) & (~adj[i])];\n    }\n\n    // \u5305\u9664\u539F\
    \u7406\n    vector<int> cnt((1 << n) + 1, 0);\n    for(int S = 0; S < (1 << n);\
    \ S++){\n        cnt[dp[S]] += __builtin_parity(S) ? 1 : -1;\n    }\n\n    vector<pair<long\
    \ long, long long>> f;\n    for(int i = 0; i <= (1 << n); i++){\n        if(cnt[i]\
    \ != 0){\n            f.emplace_back(i, cnt[i]);\n        }\n    }\n\n    int\
    \ ans = n;\n    constexpr long long MODS[] = {1000000007, 1000000009, 1000000021};\n\
    \    for(int i = 0; i < 3; i++){\n        auto nf = f;\n        for(int k = 1;\
    \ k <= n; k++){\n            if(ans <= k) break;\n            // k \u5F69\u8272\
    \u3059\u308B\u901A\u308A\u6570\n            long long sum = 0;\n            for(auto\
    \ &[x, y] : nf){\n                sum += (y = y * x % MODS[i]);\n            \
    \    sum %= MODS[i];\n            }\n            if(sum != 0) ans = min(ans, k);\n\
    \        }\n    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/chromatic_number.hpp
  requiredBy: []
  timestamp: '2024-10-31 23:51:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/chromatic_number.test.cpp
documentation_of: lib/graph/chromatic_number.hpp
layout: document
redirect_from:
- /library/lib/graph/chromatic_number.hpp
- /library/lib/graph/chromatic_number.hpp.html
title: "Chromatic Number (\u5F69\u8272\u6570)"
---
## Chromatic Number (彩色数)

#### 概要

グラフ $G$ について、彩色数を求めます。

#### 計算量

頂点数を $V$ とすると、$\mathrm{O}(2^V V)$
