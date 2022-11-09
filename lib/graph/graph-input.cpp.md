---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/graph/graph-input.cpp\"\n#include <bits/stdc++.h>\n\n\
    using namespace std;\n\nint n, m;\nvector<vector<int>> G;\n\n// \u30B0\u30E9\u30D5\
    (\u96A3\u63A5\u30EA\u30B9\u30C8)\u306E\u5165\u529B\nvoid inputGraph(){\n    cin\
    \ >> n >> m;\n    G = vector<vector<int>>(n);\n\n    for(int i = 0; i < m; i++){\n\
    \        int a, b;\n        cin >> a >> b;\n        a--, b--;\n        G[a].push_back(b);\n\
    \        G[b].push_back(a);\n    }\n    return;\n}\n\n// \u30B0\u30E9\u30D5\u306E\
    \u5165\u529B\u3092\u7C21\u7565\u5316\ntemplate<class T, class U>\nvoid inGraph(vector<vector<T>>&\
    \ G, U n, U m, bool directed = true) {\n    G.resize(n);\n    for(int i = 0; i\
    \ < m; i++){\n        int a, b;\n        cin >> a >> b;\n        a--, b--;\n \
    \       G[a].push_back(b);\n        if(!directed) G[b].push_back(a);\n    }\n\
    }\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\nint n, m;\nvector<vector<int>>\
    \ G;\n\n// \u30B0\u30E9\u30D5(\u96A3\u63A5\u30EA\u30B9\u30C8)\u306E\u5165\u529B\
    \nvoid inputGraph(){\n    cin >> n >> m;\n    G = vector<vector<int>>(n);\n\n\
    \    for(int i = 0; i < m; i++){\n        int a, b;\n        cin >> a >> b;\n\
    \        a--, b--;\n        G[a].push_back(b);\n        G[b].push_back(a);\n \
    \   }\n    return;\n}\n\n// \u30B0\u30E9\u30D5\u306E\u5165\u529B\u3092\u7C21\u7565\
    \u5316\ntemplate<class T, class U>\nvoid inGraph(vector<vector<T>>& G, U n, U\
    \ m, bool directed = true) {\n    G.resize(n);\n    for(int i = 0; i < m; i++){\n\
    \        int a, b;\n        cin >> a >> b;\n        a--, b--;\n        G[a].push_back(b);\n\
    \        if(!directed) G[b].push_back(a);\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/graph-input.cpp
  requiredBy: []
  timestamp: '2022-08-06 06:50:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/graph-input.cpp
layout: document
redirect_from:
- /library/lib/graph/graph-input.cpp
- /library/lib/graph/graph-input.cpp.html
title: lib/graph/graph-input.cpp
---
