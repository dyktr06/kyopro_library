---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/union_find.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: lib/graph/manhattanMST.hpp
    title: Manhattan MST
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/manhattanmst
    links:
    - https://judge.yosupo.jp/problem/manhattanmst
  bundledCode: "#line 1 \"test/library_checker/geometry/manhattanmst.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"lib/graph/manhattanMST.hpp\"\n\n#line 2 \"lib/data_structure/union_find.hpp\"\
    \n\n#line 5 \"lib/data_structure/union_find.hpp\"\n\n/**\n * @brief Union Find\n\
    \ * @docs docs/data_structure/union_find.md\n */\n\nstruct UnionFind{\n    int\
    \ V;\n    std::vector<int> par;\n    std::vector<int> edg;\n\n    UnionFind(int\
    \ N) : V(N), par(N), edg(N){\n        for(int i = 0; i < N; ++i){\n          \
    \  par[i] = -1;\n            edg[i] = 0;\n        }\n    }\n\n    int root(int\
    \ x){\n        assert(0 <= x && x < V);\n        if(par[x] < 0) return x;\n  \
    \      return par[x] = root(par[x]);\n    }\n\n    int unite(int x, int y){\n\
    \        int rx = root(x);\n        int ry = root(y);\n        if(rx == ry){\n\
    \            edg[rx]++;\n            return rx;\n        }\n        if(-par[rx]\
    \ < -par[ry]) std::swap(rx, ry);\n        par[rx] = par[rx] + par[ry];\n     \
    \   par[ry] = rx;\n        edg[rx] += edg[ry] + 1;\n        return rx;\n    }\n\
    \n    bool same(int x, int y){\n        int rx = root(x);\n        int ry = root(y);\n\
    \        return rx == ry;\n    }\n\n    long long size(int x){\n        return\
    \ -par[root(x)];\n    }\n\n    long long edge(int x){\n        return edg[root(x)];\n\
    \    }\n};\n#line 4 \"lib/graph/manhattanMST.hpp\"\n\n/**\n * @brief Manhattan\
    \ MST\n * @docs docs/graph/manhattanMST.md\n */\n\ntemplate <typename T>\nvector<pair<int,\
    \ int>> manhattanMST(vector<T> x, vector<T> y){\n    int n = x.size();\n    vector<tuple<T,\
    \ int, int>> edge;\n    edge.reserve(4 * n);\n    vector<int> idx(n);\n    iota(idx.begin(),\
    \ idx.end(), 0);\n    for(int s = 0; s < 2; ++s){\n        for(int t = 0; t <\
    \ 2; ++t){\n            sort(idx.begin(), idx.end(), [&](const int i, const int\
    \ j) {\n                return x[i] + y[i] < x[j] + y[j];\n            });\n \
    \           map<T, int, greater<>> map;\n            for(const int i : idx){\n\
    \                for(auto iter = map.lower_bound(y[i]); iter != map.end(); iter\
    \ = map.erase(iter)){\n                    const int j = iter->second;\n     \
    \               const T dx = x[i] - x[j];\n                    const T dy = y[i]\
    \ - y[j];\n                    if(dy > dx) break;\n                    edge.emplace_back(dx\
    \ + dy, i, j);\n                }\n                map[y[i]] = i;\n          \
    \  }\n            swap(x, y);\n        }\n        for(int i = 0; i < n; ++i) {\n\
    \            x[i] *= -1;\n        }\n    }\n    sort(edge.begin(), edge.end());\n\
    \    UnionFind dsu(n);\n    vector<pair<int, int>> used;\n    used.reserve(n -\
    \ 1);\n    for(const auto &[c, i, j] : edge){\n        if(!dsu.same(i, j)){\n\
    \            used.emplace_back(i, j);\n            dsu.unite(i, j);\n        }\n\
    \    }\n    return used;\n}\n#line 6 \"test/library_checker/geometry/manhattanmst.test.cpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    vector<int> x(n), y(n);\n    for(int\
    \ i = 0; i < n; i++){\n        cin >> x[i] >> y[i];\n    }\n    vector<pair<int,\
    \ int>> ans = manhattanMST(x, y);\n    long long sum = 0;\n    for(auto [i, j]\
    \ : ans){\n        sum += abs(x[i] - x[j]) + abs(y[i] - y[j]);\n    }\n    cout\
    \ << sum << \"\\n\";\n    for(auto [i, j] : ans){\n        cout << i << \" \"\
    \ << j << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/manhattanMST.hpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    vector<int> x(n), y(n);\n    for(int\
    \ i = 0; i < n; i++){\n        cin >> x[i] >> y[i];\n    }\n    vector<pair<int,\
    \ int>> ans = manhattanMST(x, y);\n    long long sum = 0;\n    for(auto [i, j]\
    \ : ans){\n        sum += abs(x[i] - x[j]) + abs(y[i] - y[j]);\n    }\n    cout\
    \ << sum << \"\\n\";\n    for(auto [i, j] : ans){\n        cout << i << \" \"\
    \ << j << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/graph/manhattanMST.hpp
  - lib/data_structure/union_find.hpp
  isVerificationFile: true
  path: test/library_checker/geometry/manhattanmst.test.cpp
  requiredBy: []
  timestamp: '2024-11-04 03:12:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/geometry/manhattanmst.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/geometry/manhattanmst.test.cpp
- /verify/test/library_checker/geometry/manhattanmst.test.cpp.html
title: test/library_checker/geometry/manhattanmst.test.cpp
---
