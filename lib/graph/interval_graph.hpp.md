---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Interval Graph (\u533A\u9593\u30B0\u30E9\u30D5)"
    links:
    - https://www.slideshare.net/secret/r8gjH9xYxFR0Fu
  bundledCode: "#line 2 \"lib/graph/interval_graph.hpp\"\n\n/**\n * @brief Interval\
    \ Graph (\u533A\u9593\u30B0\u30E9\u30D5)\n * @see https://www.slideshare.net/secret/r8gjH9xYxFR0Fu\n\
    \ */\n\nstruct IntervalGraph{\n    int n;\n    vector<vector<int>> G;\n\n    IntervalGraph(int\
    \ n_) : n(){\n        int x = 1;\n        while(n_ > x){\n            x *= 2;\n\
    \        }\n        n = x;\n        G.resize(n * 2);\n\n        for(int i = n\
    \ - 1; i > 0; i--){\n            G[i].push_back(i * 2);\n            G[i].push_back(i\
    \ * 2 + 1);\n        }\n    }\n\n    int get(int x){\n        return x + n;\n\
    \    }\n\n    int inv(int x){\n        return x - n;\n    }\n\n    // [a, b)\n\
    \    void add_edge(int x, int a, int b){\n        int l = a + n;\n        int\
    \ r = b + n;\n        while(l < r){\n            if(l & 1) G[x + n].push_back(l++);\n\
    \            if(r & 1) G[x + n].push_back(--r);\n            l >>= 1;\n      \
    \      r >>= 1;\n        }\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Interval Graph (\u533A\u9593\u30B0\u30E9\u30D5\
    )\n * @see https://www.slideshare.net/secret/r8gjH9xYxFR0Fu\n */\n\nstruct IntervalGraph{\n\
    \    int n;\n    vector<vector<int>> G;\n\n    IntervalGraph(int n_) : n(){\n\
    \        int x = 1;\n        while(n_ > x){\n            x *= 2;\n        }\n\
    \        n = x;\n        G.resize(n * 2);\n\n        for(int i = n - 1; i > 0;\
    \ i--){\n            G[i].push_back(i * 2);\n            G[i].push_back(i * 2\
    \ + 1);\n        }\n    }\n\n    int get(int x){\n        return x + n;\n    }\n\
    \n    int inv(int x){\n        return x - n;\n    }\n\n    // [a, b)\n    void\
    \ add_edge(int x, int a, int b){\n        int l = a + n;\n        int r = b +\
    \ n;\n        while(l < r){\n            if(l & 1) G[x + n].push_back(l++);\n\
    \            if(r & 1) G[x + n].push_back(--r);\n            l >>= 1;\n      \
    \      r >>= 1;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/interval_graph.hpp
  requiredBy: []
  timestamp: '2024-11-01 00:31:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/interval_graph.hpp
layout: document
redirect_from:
- /library/lib/graph/interval_graph.hpp
- /library/lib/graph/interval_graph.hpp.html
title: "Interval Graph (\u533A\u9593\u30B0\u30E9\u30D5)"
---
