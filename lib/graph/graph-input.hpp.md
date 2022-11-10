---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/graph/scc.test.cpp
    title: test/library_checker/graph/scc.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/graph-input.hpp\"\n\n/*\n    \u30B0\u30E9\u30D5\
    \u306E\u5165\u529B\u3092\u7C21\u7565\u5316\n*/\ntemplate<class T, class U>\nvoid\
    \ inGraph(vector<vector<T>>& G, U n, U m, bool directed = true) {\n    G.resize(n);\n\
    \    for(int i = 0; i < m; i++){\n        int a, b;\n        cin >> a >> b;\n\
    \        a--, b--;\n        G[a].push_back(b);\n        if(!directed) G[b].push_back(a);\n\
    \    }\n}\n"
  code: "#pragma once\n\n/*\n    \u30B0\u30E9\u30D5\u306E\u5165\u529B\u3092\u7C21\u7565\
    \u5316\n*/\ntemplate<class T, class U>\nvoid inGraph(vector<vector<T>>& G, U n,\
    \ U m, bool directed = true) {\n    G.resize(n);\n    for(int i = 0; i < m; i++){\n\
    \        int a, b;\n        cin >> a >> b;\n        a--, b--;\n        G[a].push_back(b);\n\
    \        if(!directed) G[b].push_back(a);\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/graph-input.hpp
  requiredBy: []
  timestamp: '2022-11-11 07:01:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/scc.test.cpp
documentation_of: lib/graph/graph-input.hpp
layout: document
redirect_from:
- /library/lib/graph/graph-input.hpp
- /library/lib/graph/graph-input.hpp.html
title: lib/graph/graph-input.hpp
---
