---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/maximum_independent_set.test.cpp
    title: test/library_checker/graph/maximum_independent_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Maximum Independent Set (\u6700\u5927\u72EC\u7ACB\u96C6\u5408\
      )"
    links: []
  bundledCode: "#line 2 \"lib/graph/maximum_independent_set.hpp\"\n\n/**\n * @brief\
    \ Maximum Independent Set (\u6700\u5927\u72EC\u7ACB\u96C6\u5408)\n */\n\nvector<int>\
    \ maximumIndependentSet(vector<vector<int>> &G, int loop = 100000){\n    const\
    \ int MAX_V = 64;\n    int n = G.size();\n    assert(n <= MAX_V);\n    vector<bitset<MAX_V>>\
    \ g(n);\n    for(int i = 0; i < n; i++){\n        for(auto &v : G[i]){\n     \
    \       g[i][v] = 1;\n        }\n    }\n\n    auto random_shuffle = [](vector<int>\
    \ &p){\n        int n = p.size();\n        for(int i = n; i > 1; i--){\n     \
    \       int a = i - 1;\n            int b = rand() % i;\n            swap(p[a],\
    \ p[b]);\n        }\n    };\n\n    vector<int> ans;\n    bitset<MAX_V> used, emp;\n\
    \    vector<int> p(n);\n    iota(p.begin(), p.end(), 0);\n    for(int k = 0; k\
    \ < loop; k++){\n        random_shuffle(p);\n        vector<int> res;\n      \
    \  for(int i = 0; i < n; i++){\n            if(used[p[i]]) continue;\n       \
    \     res.push_back(p[i]);\n            used |= g[p[i]];\n        }\n        if(ans.size()\
    \ < res.size()){\n            swap(ans, res);\n        }\n        used &= emp;\n\
    \    }\n    return ans;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Maximum Independent Set (\u6700\u5927\u72EC\
    \u7ACB\u96C6\u5408)\n */\n\nvector<int> maximumIndependentSet(vector<vector<int>>\
    \ &G, int loop = 100000){\n    const int MAX_V = 64;\n    int n = G.size();\n\
    \    assert(n <= MAX_V);\n    vector<bitset<MAX_V>> g(n);\n    for(int i = 0;\
    \ i < n; i++){\n        for(auto &v : G[i]){\n            g[i][v] = 1;\n     \
    \   }\n    }\n\n    auto random_shuffle = [](vector<int> &p){\n        int n =\
    \ p.size();\n        for(int i = n; i > 1; i--){\n            int a = i - 1;\n\
    \            int b = rand() % i;\n            swap(p[a], p[b]);\n        }\n \
    \   };\n\n    vector<int> ans;\n    bitset<MAX_V> used, emp;\n    vector<int>\
    \ p(n);\n    iota(p.begin(), p.end(), 0);\n    for(int k = 0; k < loop; k++){\n\
    \        random_shuffle(p);\n        vector<int> res;\n        for(int i = 0;\
    \ i < n; i++){\n            if(used[p[i]]) continue;\n            res.push_back(p[i]);\n\
    \            used |= g[p[i]];\n        }\n        if(ans.size() < res.size()){\n\
    \            swap(ans, res);\n        }\n        used &= emp;\n    }\n    return\
    \ ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/maximum_independent_set.hpp
  requiredBy: []
  timestamp: '2024-10-31 23:51:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/maximum_independent_set.test.cpp
documentation_of: lib/graph/maximum_independent_set.hpp
layout: document
redirect_from:
- /library/lib/graph/maximum_independent_set.hpp
- /library/lib/graph/maximum_independent_set.hpp.html
title: "Maximum Independent Set (\u6700\u5927\u72EC\u7ACB\u96C6\u5408)"
---
