---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/union_find.hpp
    title: lib/data_structure/union_find.hpp
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
    using namespace std;\n\n#line 2 \"lib/data_structure/union_find.hpp\"\n\n/* \n\
    \    UnionFind(n) : Union-Find \u6728\u3092\u30B5\u30A4\u30BAn\u3067\u69CB\u7BC9\
    \n    \u8A08\u7B97\u91CF : O(a(n)) -> \u30A2\u30C3\u30AB\u30FC\u30DE\u30F3\u306E\
    \u9006\u95A2\u6570\n    root(x) : \u96C6\u5408 x \u306E\u6839\u3092\u53D6\u5F97\
    \u3057\u307E\u3059\u3002\n    unite(x, y) : \u96C6\u5408 x \u3068 y \u3092\u4F75\
    \u5408\u3057\u307E\u3059\u3002\n    same(x, y) : \u96C6\u5408 x \u3068 \u96C6\u5408\
    \ y \u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3057\u307E\
    \u3059\u3002\n    size(x) : x \u3092\u542B\u3080\u96C6\u5408\u306E\u5927\u304D\
    \u3055\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\n    edge(x) : x \u3092\u542B\
    \u3080\u96C6\u5408\u306B\u8CBC\u3089\u308C\u3066\u3044\u308B\u8FBA\u306E\u672C\
    \u6570\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\n*/\n\n// Union-Find \u6728\u306E\
    \u5B9F\u88C5\nstruct UnionFind {\n    vector<int> par;\n    vector<int> siz;\n\
    \    vector<int> edg;\n\n    UnionFind(int N) : par(N), siz(N), edg(N) {\n   \
    \     for(int i = 0; i < N; ++i){\n            par[i] = i;\n            siz[i]\
    \ = 1;\n            edg[i] = 0;\n        }\n    }\n\n    int root(int x) {\n \
    \       if (par[x] == x) return x;\n        return par[x] = root(par[x]);\n  \
    \  }\n\n    void unite(int x, int y) {\n        int rx = root(x);\n        int\
    \ ry = root(y);\n        if (rx == ry){\n            edg[rx]++;\n            return;\n\
    \        }\n        par[rx] = ry;\n        siz[ry] += siz[rx];\n        edg[ry]\
    \ += edg[rx] + 1;\n    }\n\n    bool same(int x, int y){\n        int rx = root(x);\n\
    \        int ry = root(y);\n        return rx == ry;\n    }\n\n    long long size(int\
    \ x){\n        return siz[root(x)];\n    }\n\n    long long edge(int x){\n   \
    \     return edg[root(x)];\n    }\n};\n#line 6 \"test/library_checker/data_structure/unionfind.test.cpp\"\
    \n\nint main(){\n    int n, q; cin >> n >> q;\n    UnionFind tree(n);\n    while(q--){\n\
    \        int t, u, v; cin >> t >> u >> v;\n        if(t == 0){\n            tree.unite(u,\
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
  timestamp: '2022-11-18 02:29:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/unionfind.test.cpp
- /verify/test/library_checker/data_structure/unionfind.test.cpp.html
title: test/library_checker/data_structure/unionfind.test.cpp
---
