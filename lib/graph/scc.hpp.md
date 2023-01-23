---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \ G1, G2;\n    vector<int> check;\n    vector<int> memo;\n    vector<T> s;\n \
    \   vector<vector<T>> result;\n \n    SCC(const vector<vector<T>> &G) : G2((int)\
    \ G.size()), check((int) G.size()){\n        siz = (int) G.size();\n        G1\
    \ = G;\n        for(int i = 0; i < siz; i++){\n            for(auto x : G1[i]){\n\
    \                G2[x].emplace_back(i);\n            }\n        }\n \n       \
    \ for(int i = 0; i < siz; i++){\n            if(!check[i]){\n                dfs(i);\n\
    \            }\n        }\n        reverse(memo.begin(), memo.end());\n \n   \
    \     for(int i = 0; i < siz; i++) check[i] = 0;\n        for(auto x : memo){\n\
    \            if(!check[x]){\n                s = {};\n                dfs2(x);\n\
    \                sort(s.rbegin(), s.rend());\n                result.emplace_back(s);\n\
    \            }\n        }\n    }\n \n    void dfs(int curr){\n        check[curr]\
    \ = 1;\n        for(auto x : G1[curr]){\n            if(check[x]){\n         \
    \       continue;\n            }\n            dfs(x);\n        }\n        memo.emplace_back(curr);\n\
    \    }\n \n    void dfs2(int curr){\n        s.push_back(curr);\n        check[curr]\
    \ = 1;\n        for(auto x : G2[curr]){\n            if(check[x]){\n         \
    \       continue;\n            }\n            dfs2(x);\n        }\n    }\n \n\
    \    vector<vector<T>> get(){\n        return result;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Strongly Connected Component (\u5F37\u9023\
    \u7D50\u6210\u5206\u5206\u89E3)\n * @docs docs/graph/scc.md\n */\n\ntemplate <typename\
    \ T>\nstruct SCC{\n    int siz;\n    vector<vector<T>> G1, G2;\n    vector<int>\
    \ check;\n    vector<int> memo;\n    vector<T> s;\n    vector<vector<T>> result;\n\
    \ \n    SCC(const vector<vector<T>> &G) : G2((int) G.size()), check((int) G.size()){\n\
    \        siz = (int) G.size();\n        G1 = G;\n        for(int i = 0; i < siz;\
    \ i++){\n            for(auto x : G1[i]){\n                G2[x].emplace_back(i);\n\
    \            }\n        }\n \n        for(int i = 0; i < siz; i++){\n        \
    \    if(!check[i]){\n                dfs(i);\n            }\n        }\n     \
    \   reverse(memo.begin(), memo.end());\n \n        for(int i = 0; i < siz; i++)\
    \ check[i] = 0;\n        for(auto x : memo){\n            if(!check[x]){\n   \
    \             s = {};\n                dfs2(x);\n                sort(s.rbegin(),\
    \ s.rend());\n                result.emplace_back(s);\n            }\n       \
    \ }\n    }\n \n    void dfs(int curr){\n        check[curr] = 1;\n        for(auto\
    \ x : G1[curr]){\n            if(check[x]){\n                continue;\n     \
    \       }\n            dfs(x);\n        }\n        memo.emplace_back(curr);\n\
    \    }\n \n    void dfs2(int curr){\n        s.push_back(curr);\n        check[curr]\
    \ = 1;\n        for(auto x : G2[curr]){\n            if(check[x]){\n         \
    \       continue;\n            }\n            dfs2(x);\n        }\n    }\n \n\
    \    vector<vector<T>> get(){\n        return result;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/scc.hpp
  requiredBy: []
  timestamp: '2023-01-23 11:19:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
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