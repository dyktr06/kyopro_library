---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/union_find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/library_checker/data_structure/unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"lib/data_structure/union_find.hpp\"\n\n#line\
    \ 5 \"lib/data_structure/union_find.hpp\"\n\n/**\n * @brief Union Find\n * @docs\
    \ docs/data_structure/union_find.md\n */\n\nstruct UnionFind{\n    int V;\n  \
    \  std::vector<int> par;\n    std::vector<int> edg;\n\n    UnionFind(int N) :\
    \ V(N), par(N), edg(N){\n        for(int i = 0; i < N; ++i){\n            par[i]\
    \ = -1;\n            edg[i] = 0;\n        }\n    }\n\n    int root(int x){\n \
    \       assert(0 <= x && x < V);\n        if(par[x] < 0) return x;\n        return\
    \ par[x] = root(par[x]);\n    }\n\n    int unite(int x, int y){\n        int rx\
    \ = root(x);\n        int ry = root(y);\n        if(rx == ry){\n            edg[rx]++;\n\
    \            return rx;\n        }\n        if(-par[rx] < -par[ry]) std::swap(rx,\
    \ ry);\n        par[rx] = par[rx] + par[ry];\n        par[ry] = rx;\n        edg[rx]\
    \ += edg[ry] + 1;\n        return rx;\n    }\n\n    bool same(int x, int y){\n\
    \        int rx = root(x);\n        int ry = root(y);\n        return rx == ry;\n\
    \    }\n\n    long long size(int x){\n        return -par[root(x)];\n    }\n\n\
    \    long long edge(int x){\n        return edg[root(x)];\n    }\n};\n#line 6\
    \ \"test/library_checker/data_structure/unionfind.test.cpp\"\n\nint main(){\n\
    \    int n, q; cin >> n >> q;\n    UnionFind tree(n);\n    while(q--){\n     \
    \   int t, u, v; cin >> t >> u >> v;\n        if(t == 0){\n            tree.unite(u,\
    \ v);\n        }else{\n            if(tree.same(u, v)){\n                cout\
    \ << 1 << \"\\n\";\n            }else{\n                cout << 0 << \"\\n\";\n\
    \            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../../lib/data_structure/union_find.hpp\"\
    \n\nint main(){\n    int n, q; cin >> n >> q;\n    UnionFind tree(n);\n    while(q--){\n\
    \        int t, u, v; cin >> t >> u >> v;\n        if(t == 0){\n            tree.unite(u,\
    \ v);\n        }else{\n            if(tree.same(u, v)){\n                cout\
    \ << 1 << \"\\n\";\n            }else{\n                cout << 0 << \"\\n\";\n\
    \            }\n        }\n    }\n}"
  dependsOn:
  - lib/data_structure/union_find.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-10-31 17:18:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/unionfind.test.cpp
- /verify/test/library_checker/data_structure/unionfind.test.cpp.html
title: test/library_checker/data_structure/unionfind.test.cpp
---
