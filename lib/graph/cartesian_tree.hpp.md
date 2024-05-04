---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/tree/cartesian_tree.test.cpp
    title: test/library_checker/tree/cartesian_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/cartesian_tree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename T>\npair<vector<vector<int>>, int>\
    \ CartesianTree(vector<T> &a){\n    int n = a.size();\n    vector<vector<int>>\
    \ G(n);\n    vector<int> par(n, -1), st;\n    for(int i = 0; i < n; ++i){\n  \
    \      int prev = -1;\n        while(!st.empty() && a[i] < a[st.back()]){\n  \
    \          prev = st.back();\n            st.pop_back();\n        }\n        if(prev\
    \ != -1){\n            par[prev] = i;\n        }\n        if(!st.empty()){\n \
    \           par[i] = st.back();\n        }\n        st.emplace_back(i);\n    }\n\
    \    int root = -1;\n    for(int i = 0; i < n; ++i){\n        if(par[i] != -1){\n\
    \            G[par[i]].emplace_back(i);\n        } else{\n            root = i;\n\
    \        }\n    }\n    return make_pair(G, root);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T>\npair<vector<vector<int>>, int> CartesianTree(vector<T> &a){\n\
    \    int n = a.size();\n    vector<vector<int>> G(n);\n    vector<int> par(n,\
    \ -1), st;\n    for(int i = 0; i < n; ++i){\n        int prev = -1;\n        while(!st.empty()\
    \ && a[i] < a[st.back()]){\n            prev = st.back();\n            st.pop_back();\n\
    \        }\n        if(prev != -1){\n            par[prev] = i;\n        }\n \
    \       if(!st.empty()){\n            par[i] = st.back();\n        }\n       \
    \ st.emplace_back(i);\n    }\n    int root = -1;\n    for(int i = 0; i < n; ++i){\n\
    \        if(par[i] != -1){\n            G[par[i]].emplace_back(i);\n        }\
    \ else{\n            root = i;\n        }\n    }\n    return make_pair(G, root);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/tree/cartesian_tree.test.cpp
documentation_of: lib/graph/cartesian_tree.hpp
layout: document
redirect_from:
- /library/lib/graph/cartesian_tree.hpp
- /library/lib/graph/cartesian_tree.hpp.html
title: lib/graph/cartesian_tree.hpp
---
