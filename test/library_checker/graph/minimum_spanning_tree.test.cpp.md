---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/data_structure/union_find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/minimum_spanning_tree
    links:
    - https://judge.yosupo.jp/problem/minimum_spanning_tree
  bundledCode: "#line 1 \"test/library_checker/graph/minimum_spanning_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/minimum_spanning_tree\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/union_find.hpp\"\
    \n\n/**\n * @brief Union Find\n * @docs docs/data_structure/union_find.md\n */\n\
    \nstruct UnionFind{\n    vector<int> par;\n    vector<int> edg;\n\n    UnionFind(int\
    \ N) : par(N), edg(N){\n        for(int i = 0; i < N; ++i){\n            par[i]\
    \ = -1;\n            edg[i] = 0;\n        }\n    }\n\n    int root(int x){\n \
    \       if(par[x] < 0) return x;\n        return par[x] = root(par[x]);\n    }\n\
    \n    int unite(int x, int y){\n        int rx = root(x);\n        int ry = root(y);\n\
    \        if(rx == ry){\n            edg[rx]++;\n            return rx;\n     \
    \   }\n        if(-par[rx] < -par[ry]) swap(rx, ry);\n        par[rx] = par[rx]\
    \ + par[ry];\n        par[ry] = rx;\n        edg[rx] += edg[ry] + 1;\n       \
    \ return rx;\n    }\n\n    bool same(int x, int y){\n        int rx = root(x);\n\
    \        int ry = root(y);\n        return rx == ry;\n    }\n\n    long long size(int\
    \ x){\n        return -par[root(x)];\n    }\n\n    long long edge(int x){\n  \
    \      return edg[root(x)];\n    }\n};\n#line 6 \"test/library_checker/graph/minimum_spanning_tree.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int n, m; cin >> n >> m;\n\n    using Edge = pair<int, int>;\n    vector<Edge>\
    \ e(m);\n    vector<long long> c(m);\n    for(int i = 0; i < m; i++){\n      \
    \  cin >> e[i].first >> e[i].second >> c[i];\n    }\n\n    vector<pair<long long,\
    \ int>> sorted(m);\n    for(int i = 0; i < m; i++){\n        sorted[i] = {c[i],\
    \ i};\n    }\n    UnionFind uf(n);\n    sort(sorted.begin(), sorted.end());\n\
    \    long long sum = 0;\n    vector<int> ans;\n    for(int i = 0; i < m; i++){\n\
    \        auto [w, idx] = sorted[i];\n        auto [u, v] = e[idx];\n        if(!uf.same(u,\
    \ v)){\n            ans.push_back(idx);\n            sum += w;\n            uf.unite(u,\
    \ v);\n        }\n    }\n    cout << sum << \"\\n\";\n    for(int i = 0; i < n\
    \ - 1; i++){\n        if(i >= 1) cout << \" \";\n        cout << ans[i];\n   \
    \ }\n    cout << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/minimum_spanning_tree\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/union_find.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int n, m; cin >> n >> m;\n\n    using Edge = pair<int, int>;\n    vector<Edge>\
    \ e(m);\n    vector<long long> c(m);\n    for(int i = 0; i < m; i++){\n      \
    \  cin >> e[i].first >> e[i].second >> c[i];\n    }\n\n    vector<pair<long long,\
    \ int>> sorted(m);\n    for(int i = 0; i < m; i++){\n        sorted[i] = {c[i],\
    \ i};\n    }\n    UnionFind uf(n);\n    sort(sorted.begin(), sorted.end());\n\
    \    long long sum = 0;\n    vector<int> ans;\n    for(int i = 0; i < m; i++){\n\
    \        auto [w, idx] = sorted[i];\n        auto [u, v] = e[idx];\n        if(!uf.same(u,\
    \ v)){\n            ans.push_back(idx);\n            sum += w;\n            uf.unite(u,\
    \ v);\n        }\n    }\n    cout << sum << \"\\n\";\n    for(int i = 0; i < n\
    \ - 1; i++){\n        if(i >= 1) cout << \" \";\n        cout << ans[i];\n   \
    \ }\n    cout << \"\\n\";\n}"
  dependsOn:
  - lib/data_structure/union_find.hpp
  isVerificationFile: true
  path: test/library_checker/graph/minimum_spanning_tree.test.cpp
  requiredBy: []
  timestamp: '2024-04-21 00:12:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/minimum_spanning_tree.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/minimum_spanning_tree.test.cpp
- /verify/test/library_checker/graph/minimum_spanning_tree.test.cpp.html
title: test/library_checker/graph/minimum_spanning_tree.test.cpp
---
