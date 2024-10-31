---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/graph/enumerate_cliques.test.cpp
    title: test/library_checker/graph/enumerate_cliques.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/enumerate_cliques.hpp\"\n\nvector<vector<int>>\
    \ enumerateCliques(vector<vector<int>> &G){\n    int n = G.size();\n    int m\
    \ = 0;\n    vector<pair<int, int>> deg(n);\n    for(int i = 0; i < n; i++){\n\
    \        m += (int) G[i].size();\n        deg[i] = {(int) G[i].size(), i};\n \
    \   }\n    m /= 2;\n\n    vector<vector<bool>> adj(n, vector<bool>(n));\n    for(int\
    \ i = 0; i < n; i++){\n        for(auto &j : G[i]){\n            adj[i][j] = adj[j][i]\
    \ = true;\n        }\n    }\n\n    // \u6B21\u6570\u304C \u221A2m \u672A\u6E80\
    \u304B\u3069\u3046\u304B\u3067\u5834\u5408\u5206\u3051 -> \u6B21\u6570\u304C\u4F4E\
    \u3044\u9802\u70B9\u304B\u3089\u51E6\u7406\u3092\u3057\u3066\u3082\u5341\u5206\
    \u9AD8\u901F (O(2^(\u221A2m) * n^2))\n    sort(deg.begin(), deg.end());\n    vector<vector<int>>\
    \ res;\n    for(int i = 0; i < n; i++){\n        int cur = deg[i].second;\n  \
    \      vector<int> nxt;\n        for(int j = 0; j < n; j++){\n            if(adj[cur][j]){\n\
    \                nxt.push_back(j);\n            }\n        }\n        int d =\
    \ nxt.size();\n        for(int bit = 0; bit < (1 << d); bit++){\n            vector<int>\
    \ s = {cur};\n            for(int j = 0; j < d; j++){\n                if(bit\
    \ & (1 << j)){\n                    s.push_back(nxt[j]);\n                }\n\
    \            }\n            bool is_ok = true;\n            for(auto x : s){\n\
    \                for(auto y : s){\n                    if(x == y) continue;\n\
    \                    if(adj[x][y] == 0){\n                        is_ok = false;\n\
    \                    }\n                }\n            }\n            if(is_ok){\n\
    \                res.push_back(s);\n            }\n        }\n        for(int\
    \ j = 0; j < d; j++){\n            adj[cur][nxt[j]] = adj[nxt[j]][cur] = false;\n\
    \        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n\nvector<vector<int>> enumerateCliques(vector<vector<int>>\
    \ &G){\n    int n = G.size();\n    int m = 0;\n    vector<pair<int, int>> deg(n);\n\
    \    for(int i = 0; i < n; i++){\n        m += (int) G[i].size();\n        deg[i]\
    \ = {(int) G[i].size(), i};\n    }\n    m /= 2;\n\n    vector<vector<bool>> adj(n,\
    \ vector<bool>(n));\n    for(int i = 0; i < n; i++){\n        for(auto &j : G[i]){\n\
    \            adj[i][j] = adj[j][i] = true;\n        }\n    }\n\n    // \u6B21\u6570\
    \u304C \u221A2m \u672A\u6E80\u304B\u3069\u3046\u304B\u3067\u5834\u5408\u5206\u3051\
    \ -> \u6B21\u6570\u304C\u4F4E\u3044\u9802\u70B9\u304B\u3089\u51E6\u7406\u3092\u3057\
    \u3066\u3082\u5341\u5206\u9AD8\u901F (O(2^(\u221A2m) * n^2))\n    sort(deg.begin(),\
    \ deg.end());\n    vector<vector<int>> res;\n    for(int i = 0; i < n; i++){\n\
    \        int cur = deg[i].second;\n        vector<int> nxt;\n        for(int j\
    \ = 0; j < n; j++){\n            if(adj[cur][j]){\n                nxt.push_back(j);\n\
    \            }\n        }\n        int d = nxt.size();\n        for(int bit =\
    \ 0; bit < (1 << d); bit++){\n            vector<int> s = {cur};\n           \
    \ for(int j = 0; j < d; j++){\n                if(bit & (1 << j)){\n         \
    \           s.push_back(nxt[j]);\n                }\n            }\n         \
    \   bool is_ok = true;\n            for(auto x : s){\n                for(auto\
    \ y : s){\n                    if(x == y) continue;\n                    if(adj[x][y]\
    \ == 0){\n                        is_ok = false;\n                    }\n    \
    \            }\n            }\n            if(is_ok){\n                res.push_back(s);\n\
    \            }\n        }\n        for(int j = 0; j < d; j++){\n            adj[cur][nxt[j]]\
    \ = adj[nxt[j]][cur] = false;\n        }\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/enumerate_cliques.hpp
  requiredBy: []
  timestamp: '2024-10-21 04:45:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/enumerate_cliques.test.cpp
documentation_of: lib/graph/enumerate_cliques.hpp
layout: document
redirect_from:
- /library/lib/graph/enumerate_cliques.hpp
- /library/lib/graph/enumerate_cliques.hpp.html
title: lib/graph/enumerate_cliques.hpp
---
