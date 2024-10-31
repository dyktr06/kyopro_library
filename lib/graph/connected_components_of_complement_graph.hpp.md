---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/connected_components_of_complement_graph.test.cpp
    title: test/library_checker/graph/connected_components_of_complement_graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/connected_components_of_complement_graph.md
    document_title: "Connected Components of Complement Graph (\u88DC\u30B0\u30E9\u30D5\
      \u306E\u9023\u7D50\u6210\u5206\u5206\u89E3)"
    links: []
  bundledCode: "#line 2 \"lib/graph/connected_components_of_complement_graph.hpp\"\
    \n\n/**\n * @brief Connected Components of Complement Graph (\u88DC\u30B0\u30E9\
    \u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3)\n * @docs docs/graph/connected_components_of_complement_graph.md\n\
    \ */\n\ntemplate <typename T>\nvector<vector<int>> connectedComponentsOfComplementGraph(vector<vector<T>>\
    \ &G){\n    int n = (int) G.size();\n    vector<vector<int>> ans;\n    vector<bool>\
    \ used(n, false), reach(n, true);\n    vector<int> s(n);\n    iota(s.begin(),\
    \ s.end(), 0);\n    for(int i = 0; i < n; i++){\n        if(used[i]) continue;\n\
    \        vector<int> v;\n        queue<int> q;\n        q.push(i);\n        while(!q.empty()){\n\
    \            int x = q.front(); q.pop();\n            if(used[x]) continue;\n\
    \            used[x] = true;\n            v.push_back(x);\n            for(auto\
    \ y : G[x]){\n                reach[y] = false;\n            }\n            vector<int>\
    \ ts;\n            while(!s.empty()){\n                if(reach[s.back()]){\n\
    \                    q.push(s.back());\n                } else{\n            \
    \        ts.push_back(s.back());\n                }\n                s.pop_back();\n\
    \            }\n            swap(s, ts);\n            for(auto y : G[x]){\n  \
    \              reach[y] = true;\n            }\n        }\n        ans.push_back(v);\n\
    \    }\n    return ans;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Connected Components of Complement Graph (\u88DC\
    \u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3)\n * @docs docs/graph/connected_components_of_complement_graph.md\n\
    \ */\n\ntemplate <typename T>\nvector<vector<int>> connectedComponentsOfComplementGraph(vector<vector<T>>\
    \ &G){\n    int n = (int) G.size();\n    vector<vector<int>> ans;\n    vector<bool>\
    \ used(n, false), reach(n, true);\n    vector<int> s(n);\n    iota(s.begin(),\
    \ s.end(), 0);\n    for(int i = 0; i < n; i++){\n        if(used[i]) continue;\n\
    \        vector<int> v;\n        queue<int> q;\n        q.push(i);\n        while(!q.empty()){\n\
    \            int x = q.front(); q.pop();\n            if(used[x]) continue;\n\
    \            used[x] = true;\n            v.push_back(x);\n            for(auto\
    \ y : G[x]){\n                reach[y] = false;\n            }\n            vector<int>\
    \ ts;\n            while(!s.empty()){\n                if(reach[s.back()]){\n\
    \                    q.push(s.back());\n                } else{\n            \
    \        ts.push_back(s.back());\n                }\n                s.pop_back();\n\
    \            }\n            swap(s, ts);\n            for(auto y : G[x]){\n  \
    \              reach[y] = true;\n            }\n        }\n        ans.push_back(v);\n\
    \    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/connected_components_of_complement_graph.hpp
  requiredBy: []
  timestamp: '2024-11-01 00:31:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/connected_components_of_complement_graph.test.cpp
documentation_of: lib/graph/connected_components_of_complement_graph.hpp
layout: document
redirect_from:
- /library/lib/graph/connected_components_of_complement_graph.hpp
- /library/lib/graph/connected_components_of_complement_graph.hpp.html
title: "Connected Components of Complement Graph (\u88DC\u30B0\u30E9\u30D5\u306E\u9023\
  \u7D50\u6210\u5206\u5206\u89E3)"
---
## Connected Components of Complement Graph (補グラフの連結成分分解)

#### 概要

グラフ $G$ の補グラフについてのそれぞれの連結成分を求めます。

#### 計算量

頂点数を $V$、辺の数を $E$ とすると、$\mathrm{O}(E + V)$
