---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/weighted_union_find.hpp
    title: Weighted Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"test/aoj/dsl/dsl_1_b.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/weighted_union_find.hpp\"\
    \n\n/**\n * @brief Weighted Union Find\n * @docs docs/data_structure/weighted_union_find.md\n\
    \ */\n\ntemplate <typename T>\nstruct WeightedUnionFind{\n    vector<int> par;\n\
    \    vector<T> diff_weight;\n    T ex;\n\n    WeightedUnionFind(const int N, const\
    \ T &e = 0) : par(N), diff_weight(N), ex(e){\n        for(int i = 0; i < N; ++i){\n\
    \            par[i] = -1;\n            diff_weight[i] = e;\n        }\n    }\n\
    \n    int root(const int x){\n        if(par[x] < 0){\n            return x;\n\
    \        }\n        int px = par[x];\n        int rx = root(par[x]);\n       \
    \ diff_weight[x] = diff_weight[x] + diff_weight[px];\n        return par[x] =\
    \ rx;\n    }\n\n    T weight(const int x){\n        root(x);\n        return diff_weight[x];\n\
    \    }\n\n    T diff(const int x, const int y){\n        return weight(x) - weight(y);\n\
    \    }\n\n    void unite(const int x, const int y, const T &w){\n        int tx\
    \ = x, ty = y;\n        T tw = w;\n        int rx = root(x), ry = root(y);\n \
    \       if(rx == ry) return;\n\n        if(par[rx] < par[ry]){\n            swap(rx,\
    \ ry);\n            swap(tx, ty);\n            tw = ex - tw;\n        }\n\n  \
    \      par[ry] = par[rx] + par[ry];\n        par[rx] = ry;\n        diff_weight[rx]\
    \ = ex - diff_weight[tx] + tw + diff_weight[ty];\n    }\n\n    bool same(const\
    \ int x, const int y){\n        return root(x) == root(y);\n    }\n\n    int size(const\
    \ int x){\n        return -par[root(x)];\n    }\n};\n#line 6 \"test/aoj/dsl/dsl_1_b.test.cpp\"\
    \n\nint main(){\n    int n, q; cin >> n >> q;\n    WeightedUnionFind<int> tree(n);\n\
    \    while(q--){\n        int t; cin >> t;\n        if(t == 0){\n            int\
    \ x, y, z; cin >> x >> y >> z;\n            tree.unite(x, y, z);\n        }else{\n\
    \            int x, y; cin >> x >> y;\n            if(tree.same(x, y)){\n    \
    \            cout << tree.diff(x, y) << \"\\n\";\n            }else{\n       \
    \         cout << \"?\" << \"\\n\";\n            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/weighted_union_find.hpp\"\
    \n\nint main(){\n    int n, q; cin >> n >> q;\n    WeightedUnionFind<int> tree(n);\n\
    \    while(q--){\n        int t; cin >> t;\n        if(t == 0){\n            int\
    \ x, y, z; cin >> x >> y >> z;\n            tree.unite(x, y, z);\n        }else{\n\
    \            int x, y; cin >> x >> y;\n            if(tree.same(x, y)){\n    \
    \            cout << tree.diff(x, y) << \"\\n\";\n            }else{\n       \
    \         cout << \"?\" << \"\\n\";\n            }\n        }\n    }\n}"
  dependsOn:
  - lib/data_structure/weighted_union_find.hpp
  isVerificationFile: true
  path: test/aoj/dsl/dsl_1_b.test.cpp
  requiredBy: []
  timestamp: '2024-08-24 05:13:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl/dsl_1_b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl/dsl_1_b.test.cpp
- /verify/test/aoj/dsl/dsl_1_b.test.cpp.html
title: test/aoj/dsl/dsl_1_b.test.cpp
---
