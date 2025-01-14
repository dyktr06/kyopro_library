---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Doubling (\u30C0\u30D6\u30EA\u30F3\u30B0)"
    links: []
  bundledCode: "#line 2 \"lib/others/doubling.hpp\"\n\n/**\n * @brief Doubling (\u30C0\
    \u30D6\u30EA\u30F3\u30B0)\n */\n\n#include <vector>\n\ntemplate <typename T>\n\
    struct Doubling{\n    int log, n;\n    std::vector<std::vector<int>> nxt;\n  \
    \  std::vector<std::vector<T>> cost;\n\n    Doubling(const std::vector<int> &_nxt,\
    \ const std::vector<T> &_cost, int _log = 30) : log(_log), n((int) _nxt.size()){\n\
    \        nxt = std::vector<std::vector<int>>(log + 1, std::vector<int>(n));\n\
    \        cost = std::vector<std::vector<T>>(log + 1, std::vector<T>(n));\n   \
    \     nxt[0] = _nxt;\n        cost[0] = _cost;\n\n        for(int i = 1; i <=\
    \ log; i++){\n            for(int j = 0; j < n; j++){\n                nxt[i][j]\
    \ = nxt[i - 1][nxt[i - 1][j]];\n                cost[i][j] = cost[i - 1][j] +\
    \ cost[i - 1][nxt[i - 1][j]];\n            }\n        }\n    }\n\n    // v \u304B\
    \u3089 k \u56DE\u79FB\u52D5\u3057\u305F\u5F8C\u306E\u4F4D\u7F6E\u3068\u30B3\u30B9\
    \u30C8\n    std::pair<int, T> get(int v, T k){\n        T c = T(0);\n        int\
    \ cur = v;\n        for(int i = 0; i <= log; i++){\n            if((k >> i) &\
    \ 1){\n                c += cost[i][cur];\n                cur = nxt[i][cur];\n\
    \            }\n        }\n        return {cur, c};\n    }\n\n    // v \u304B\u3089\
    \u30B3\u30B9\u30C8\u304C c \u4EE5\u4E0B\u3067\u5230\u9054\u3067\u304D\u308B\u6700\
    \u5927\u306E\u4F4D\u7F6E\u3068\u305D\u306E\u56DE\u6570\n    std::pair<int, T>\
    \ girigiri(int v, T c){\n        T k = 0;\n        int cur = v;\n        for(int\
    \ i = log; i >= 0; i--){\n            if(cost[i][cur] <= c){\n               \
    \ c -= cost[i][cur];\n                cur = nxt[i][cur];\n                k +=\
    \ ((T) 1 << i);\n            }\n        }\n        return {cur, k};\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Doubling (\u30C0\u30D6\u30EA\u30F3\u30B0)\n\
    \ */\n\n#include <vector>\n\ntemplate <typename T>\nstruct Doubling{\n    int\
    \ log, n;\n    std::vector<std::vector<int>> nxt;\n    std::vector<std::vector<T>>\
    \ cost;\n\n    Doubling(const std::vector<int> &_nxt, const std::vector<T> &_cost,\
    \ int _log = 30) : log(_log), n((int) _nxt.size()){\n        nxt = std::vector<std::vector<int>>(log\
    \ + 1, std::vector<int>(n));\n        cost = std::vector<std::vector<T>>(log +\
    \ 1, std::vector<T>(n));\n        nxt[0] = _nxt;\n        cost[0] = _cost;\n\n\
    \        for(int i = 1; i <= log; i++){\n            for(int j = 0; j < n; j++){\n\
    \                nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];\n                cost[i][j]\
    \ = cost[i - 1][j] + cost[i - 1][nxt[i - 1][j]];\n            }\n        }\n \
    \   }\n\n    // v \u304B\u3089 k \u56DE\u79FB\u52D5\u3057\u305F\u5F8C\u306E\u4F4D\
    \u7F6E\u3068\u30B3\u30B9\u30C8\n    std::pair<int, T> get(int v, T k){\n     \
    \   T c = T(0);\n        int cur = v;\n        for(int i = 0; i <= log; i++){\n\
    \            if((k >> i) & 1){\n                c += cost[i][cur];\n         \
    \       cur = nxt[i][cur];\n            }\n        }\n        return {cur, c};\n\
    \    }\n\n    // v \u304B\u3089\u30B3\u30B9\u30C8\u304C c \u4EE5\u4E0B\u3067\u5230\
    \u9054\u3067\u304D\u308B\u6700\u5927\u306E\u4F4D\u7F6E\u3068\u305D\u306E\u56DE\
    \u6570\n    std::pair<int, T> girigiri(int v, T c){\n        T k = 0;\n      \
    \  int cur = v;\n        for(int i = log; i >= 0; i--){\n            if(cost[i][cur]\
    \ <= c){\n                c -= cost[i][cur];\n                cur = nxt[i][cur];\n\
    \                k += ((T) 1 << i);\n            }\n        }\n        return\
    \ {cur, k};\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/doubling.hpp
  requiredBy: []
  timestamp: '2025-01-14 11:20:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/doubling.hpp
layout: document
redirect_from:
- /library/lib/others/doubling.hpp
- /library/lib/others/doubling.hpp.html
title: "Doubling (\u30C0\u30D6\u30EA\u30F3\u30B0)"
---
