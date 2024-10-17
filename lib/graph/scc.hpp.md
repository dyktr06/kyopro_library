---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/cycle_detection.test.cpp
    title: test/library_checker/graph/cycle_detection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/scc.test.cpp
    title: test/library_checker/graph/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/scc.md
    document_title: "Strongly Connected Component (\u5F37\u9023\u7D50\u6210\u5206\u5206\
      \u89E3)"
    links: []
  bundledCode: "#line 2 \"lib/graph/scc.hpp\"\n\n/**\n * @brief Strongly Connected\
    \ Component (\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)\n * @docs docs/graph/scc.md\n\
    \ */\n\ntemplate <typename T>\nstruct SCC{\n    int siz;\n    vector<vector<T>>\
    \ G_reverse, G_compress;\n    vector<bool> check;\n    vector<int> memo, id;\n\
    \    vector<T> s;\n    vector<vector<T>> result;\n\n    SCC(const vector<vector<T>>\
    \ &G) : G_reverse((int) G.size()), check((int) G.size()), id((int) G.size()){\n\
    \        siz = (int) G.size();\n        for(int i = 0; i < siz; ++i){\n      \
    \      for(const auto &x : G[i]){\n                G_reverse[x].emplace_back(i);\n\
    \            }\n        }\n\n        for(int i = 0; i < siz; ++i){\n         \
    \   if(!check[i]){\n                dfs(G, i);\n            }\n        }\n   \
    \     reverse(memo.begin(), memo.end());\n\n        for(int i = 0; i < siz; ++i)\
    \ check[i] = false;\n        for(const auto &x : memo){\n            if(!check[x]){\n\
    \                s = {};\n                dfs2(G_reverse, x);\n              \
    \  for(const auto &y : s){\n                    id[y] = (int) result.size();\n\
    \                }\n                result.emplace_back(s);\n            }\n \
    \       }\n\n        G_compress.resize(result.size());\n        for(int i = 0;\
    \ i < siz; ++i){\n            for(const auto &x : G[i]){\n                if(id[i]\
    \ != id[x]){\n                    G_compress[id[i]].emplace_back(id[x]);\n   \
    \             }\n            }\n        }\n    }\n\n    void dfs(const vector<vector<T>>\
    \ &G, int curr){\n        check[curr] = true;\n        for(const auto &x : G[curr]){\n\
    \            if(check[x]){\n                continue;\n            }\n       \
    \     dfs(G, x);\n        }\n        memo.emplace_back(curr);\n    }\n\n    void\
    \ dfs2(const vector<vector<T>> &G, int curr){\n        s.emplace_back(curr);\n\
    \        check[curr] = true;\n        for(const auto &x : G[curr]){\n        \
    \    if(check[x]){\n                continue;\n            }\n            dfs2(G,\
    \ x);\n        }\n    }\n\n    vector<vector<T>> get() const {\n        return\
    \ result;\n    }\n\n    vector<vector<T>> getCompressed() const {\n        return\
    \ G_compress;\n    }\n\n    int getId(int x) const {\n        return id[x];\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Strongly Connected Component (\u5F37\u9023\
    \u7D50\u6210\u5206\u5206\u89E3)\n * @docs docs/graph/scc.md\n */\n\ntemplate <typename\
    \ T>\nstruct SCC{\n    int siz;\n    vector<vector<T>> G_reverse, G_compress;\n\
    \    vector<bool> check;\n    vector<int> memo, id;\n    vector<T> s;\n    vector<vector<T>>\
    \ result;\n\n    SCC(const vector<vector<T>> &G) : G_reverse((int) G.size()),\
    \ check((int) G.size()), id((int) G.size()){\n        siz = (int) G.size();\n\
    \        for(int i = 0; i < siz; ++i){\n            for(const auto &x : G[i]){\n\
    \                G_reverse[x].emplace_back(i);\n            }\n        }\n\n \
    \       for(int i = 0; i < siz; ++i){\n            if(!check[i]){\n          \
    \      dfs(G, i);\n            }\n        }\n        reverse(memo.begin(), memo.end());\n\
    \n        for(int i = 0; i < siz; ++i) check[i] = false;\n        for(const auto\
    \ &x : memo){\n            if(!check[x]){\n                s = {};\n         \
    \       dfs2(G_reverse, x);\n                for(const auto &y : s){\n       \
    \             id[y] = (int) result.size();\n                }\n              \
    \  result.emplace_back(s);\n            }\n        }\n\n        G_compress.resize(result.size());\n\
    \        for(int i = 0; i < siz; ++i){\n            for(const auto &x : G[i]){\n\
    \                if(id[i] != id[x]){\n                    G_compress[id[i]].emplace_back(id[x]);\n\
    \                }\n            }\n        }\n    }\n\n    void dfs(const vector<vector<T>>\
    \ &G, int curr){\n        check[curr] = true;\n        for(const auto &x : G[curr]){\n\
    \            if(check[x]){\n                continue;\n            }\n       \
    \     dfs(G, x);\n        }\n        memo.emplace_back(curr);\n    }\n\n    void\
    \ dfs2(const vector<vector<T>> &G, int curr){\n        s.emplace_back(curr);\n\
    \        check[curr] = true;\n        for(const auto &x : G[curr]){\n        \
    \    if(check[x]){\n                continue;\n            }\n            dfs2(G,\
    \ x);\n        }\n    }\n\n    vector<vector<T>> get() const {\n        return\
    \ result;\n    }\n\n    vector<vector<T>> getCompressed() const {\n        return\
    \ G_compress;\n    }\n\n    int getId(int x) const {\n        return id[x];\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/scc.hpp
  requiredBy: []
  timestamp: '2024-10-17 17:10:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/cycle_detection.test.cpp
  - test/library_checker/graph/scc.test.cpp
documentation_of: lib/graph/scc.hpp
layout: document
redirect_from:
- /library/lib/graph/scc.hpp
- /library/lib/graph/scc.hpp.html
title: "Strongly Connected Component (\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)"
---
## Strongly Connected Component (強連結成分分解)

#### 概要

グラフ $G$ に対して強連結成分分解を行います。

#### 計算量

頂点数を $V$、辺の数を $E$ とすると、$\mathrm{O}(E + V)$