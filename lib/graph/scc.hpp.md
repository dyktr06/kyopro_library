---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/graph/two_sat.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/cycle_detection.test.cpp
    title: test/library_checker/graph/cycle_detection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/scc.test.cpp
    title: test/library_checker/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/other/two_sat.test.cpp
    title: test/library_checker/other/two_sat.test.cpp
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
    \ */\n\n#include <vector>\n#include <cassert>\n#include <algorithm>\n\nstruct\
    \ SCC{\n    int siz;\n    std::vector<std::vector<int>> G, G_reverse, G_compress;\n\
    \    std::vector<bool> check;\n    std::vector<int> memo, id;\n    std::vector<int>\
    \ s;\n    std::vector<std::vector<int>> result;\n\n    SCC(const int N) : siz(N),\
    \ G(N), G_reverse(N), check(N), id(N){ }\n\n    void add_edge(int u, int v){\n\
    \        assert(0 <= u && u < siz);\n        assert(0 <= v && v < siz);\n    \
    \    G[u].emplace_back(v);\n    }\n\n    void build(){\n        for(int i = 0;\
    \ i < siz; ++i){\n            for(const auto &x : G[i]){\n                G_reverse[x].emplace_back(i);\n\
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
    \             }\n            }\n        }\n    }\n\n    void dfs(const std::vector<std::vector<int>>\
    \ &G, int curr){\n        check[curr] = true;\n        for(const auto &x : G[curr]){\n\
    \            if(check[x]){\n                continue;\n            }\n       \
    \     dfs(G, x);\n        }\n        memo.emplace_back(curr);\n    }\n\n    void\
    \ dfs2(const std::vector<std::vector<int>> &G, int curr){\n        s.emplace_back(curr);\n\
    \        check[curr] = true;\n        for(const auto &x : G[curr]){\n        \
    \    if(check[x]){\n                continue;\n            }\n            dfs2(G,\
    \ x);\n        }\n    }\n\n    std::vector<std::vector<int>> get() const {\n \
    \       return result;\n    }\n\n    std::vector<std::vector<int>> getCompressed()\
    \ const {\n        return G_compress;\n    }\n\n    int getId(int x) const {\n\
    \        return id[x];\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Strongly Connected Component (\u5F37\u9023\
    \u7D50\u6210\u5206\u5206\u89E3)\n * @docs docs/graph/scc.md\n */\n\n#include <vector>\n\
    #include <cassert>\n#include <algorithm>\n\nstruct SCC{\n    int siz;\n    std::vector<std::vector<int>>\
    \ G, G_reverse, G_compress;\n    std::vector<bool> check;\n    std::vector<int>\
    \ memo, id;\n    std::vector<int> s;\n    std::vector<std::vector<int>> result;\n\
    \n    SCC(const int N) : siz(N), G(N), G_reverse(N), check(N), id(N){ }\n\n  \
    \  void add_edge(int u, int v){\n        assert(0 <= u && u < siz);\n        assert(0\
    \ <= v && v < siz);\n        G[u].emplace_back(v);\n    }\n\n    void build(){\n\
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
    \                }\n            }\n        }\n    }\n\n    void dfs(const std::vector<std::vector<int>>\
    \ &G, int curr){\n        check[curr] = true;\n        for(const auto &x : G[curr]){\n\
    \            if(check[x]){\n                continue;\n            }\n       \
    \     dfs(G, x);\n        }\n        memo.emplace_back(curr);\n    }\n\n    void\
    \ dfs2(const std::vector<std::vector<int>> &G, int curr){\n        s.emplace_back(curr);\n\
    \        check[curr] = true;\n        for(const auto &x : G[curr]){\n        \
    \    if(check[x]){\n                continue;\n            }\n            dfs2(G,\
    \ x);\n        }\n    }\n\n    std::vector<std::vector<int>> get() const {\n \
    \       return result;\n    }\n\n    std::vector<std::vector<int>> getCompressed()\
    \ const {\n        return G_compress;\n    }\n\n    int getId(int x) const {\n\
    \        return id[x];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/scc.hpp
  requiredBy:
  - lib/graph/two_sat.hpp
  timestamp: '2024-11-25 23:10:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/cycle_detection.test.cpp
  - test/library_checker/graph/scc.test.cpp
  - test/library_checker/other/two_sat.test.cpp
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