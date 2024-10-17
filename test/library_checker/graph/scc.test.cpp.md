---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/graph-input.hpp
    title: lib/graph/graph-input.hpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/scc.hpp
    title: "Strongly Connected Component (\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/library_checker/graph/scc.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/scc\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 2 \"lib/graph/graph-input.hpp\"\n\n/*\n    \u30B0\u30E9\u30D5\u306E\
    \u5165\u529B\u3092\u7C21\u7565\u5316\n*/\ntemplate<class T, class U>\nvoid inGraph(vector<vector<T>>\
    \ &G, U n, U m, bool directed = true, bool zero_index = true){\n    G.resize(n);\n\
    \    for(int i = 0; i < m; i++){\n        int a, b;\n        cin >> a >> b;\n\
    \        if(!zero_index) a--, b--;\n        G[a].push_back(b);\n        if(!directed)\
    \ G[b].push_back(a);\n    }\n}\n#line 2 \"lib/graph/scc.hpp\"\n\n/**\n * @brief\
    \ Strongly Connected Component (\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)\n\
    \ * @docs docs/graph/scc.md\n */\n\ntemplate <typename T>\nstruct SCC{\n    int\
    \ siz;\n    vector<vector<T>> G_reverse, G_compress;\n    vector<bool> check;\n\
    \    vector<int> memo, id;\n    vector<T> s;\n    vector<vector<T>> result;\n\n\
    \    SCC(const vector<vector<T>> &G) : G_reverse((int) G.size()), check((int)\
    \ G.size()), id((int) G.size()){\n        siz = (int) G.size();\n        for(int\
    \ i = 0; i < siz; ++i){\n            for(const auto &x : G[i]){\n            \
    \    G_reverse[x].emplace_back(i);\n            }\n        }\n\n        for(int\
    \ i = 0; i < siz; ++i){\n            if(!check[i]){\n                dfs(G, i);\n\
    \            }\n        }\n        reverse(memo.begin(), memo.end());\n\n    \
    \    for(int i = 0; i < siz; ++i) check[i] = false;\n        for(const auto &x\
    \ : memo){\n            if(!check[x]){\n                s = {};\n            \
    \    dfs2(G_reverse, x);\n                for(const auto &y : s){\n          \
    \          id[y] = (int) result.size();\n                }\n                result.emplace_back(s);\n\
    \            }\n        }\n\n        G_compress.resize(result.size());\n     \
    \   for(int i = 0; i < siz; ++i){\n            for(const auto &x : G[i]){\n  \
    \              if(id[i] != id[x]){\n                    G_compress[id[i]].emplace_back(id[x]);\n\
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
    \    }\n};\n#line 7 \"test/library_checker/graph/scc.test.cpp\"\n\nint n, m;\n\
    vector<vector<int>> G;\n\nint main(){\n    cin >> n >> m;\n    inGraph(G, n, m);\n\
    \    SCC<int> scc(G);\n    vector<vector<int>> v = scc.get();\n    cout << (int)\
    \ v.size() << \"\\n\";\n    for(auto s : v){\n        cout << (int) s.size() <<\
    \ \" \";\n        for(auto x : s){\n            cout << x << \" \";\n        }\n\
    \        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../../lib/graph/graph-input.hpp\"\n#include\
    \ \"../../../lib/graph/scc.hpp\"\n\nint n, m;\nvector<vector<int>> G;\n\nint main(){\n\
    \    cin >> n >> m;\n    inGraph(G, n, m);\n    SCC<int> scc(G);\n    vector<vector<int>>\
    \ v = scc.get();\n    cout << (int) v.size() << \"\\n\";\n    for(auto s : v){\n\
    \        cout << (int) s.size() << \" \";\n        for(auto x : s){\n        \
    \    cout << x << \" \";\n        }\n        cout << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/graph/graph-input.hpp
  - lib/graph/scc.hpp
  isVerificationFile: true
  path: test/library_checker/graph/scc.test.cpp
  requiredBy: []
  timestamp: '2024-10-17 17:10:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/scc.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/scc.test.cpp
- /verify/test/library_checker/graph/scc.test.cpp.html
title: test/library_checker/graph/scc.test.cpp
---
