---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/binary_indexed_tree.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/library_checker/data_structure/point_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/binary_indexed_tree.hpp\"\
    \n\n/**\n * @brief Binary Indexed Tree\n * @docs docs/data_structure/binary_indexed_tree.md\n\
    \ */\n\ntemplate <typename T>\nstruct BinaryIndexedTree{\n    int N;\n    vector<T>\
    \ BIT;\n    BinaryIndexedTree(const int &N): N(N), BIT(N + 1, 0){\n    }\n\n \
    \   T get(int i){\n        return sum(i + 1) - sum(i);\n    }\n\n    void add(int\
    \ i, T x){\n        i++;\n        while(i <= N){\n            BIT[i] += x;\n \
    \           i += i & -i;\n        }\n    }\n\n    T sum(int i) const {\n     \
    \   T ans = 0;\n        while(i > 0){\n            ans += BIT[i];\n          \
    \  i -= i & -i;\n        }\n        return ans;\n    }\n\n    T sum(int L, int\
    \ R) const {\n        return sum(R) - sum(L);\n    }\n\n    int lower_bound(T\
    \ x) const {\n        if(x <= 0){\n            return 0;\n        }else{\n   \
    \         int v = 0, r = 1;\n            while(r < N) r = r << 1;\n          \
    \  for(int len = r; len > 0; len = len >> 1){\n                if(v + len < N\
    \ && BIT[v + len] < x){\n                    x -= BIT[v + len];\n            \
    \        v += len;\n                }\n            }\n            return v;\n\
    \        }\n    }\n\n    int upper_bound(T x) const {\n        if(x < 0){\n  \
    \          return 0;\n        }else{\n            int v = 0, r = 1;\n        \
    \    while(r <= N) r = r << 1;\n            for(int len = r; len > 0; len = len\
    \ >> 1){\n                if(v + len <= N && BIT[v + len] <= x){\n           \
    \         x -= BIT[v + len];\n                    v += len;\n                }\n\
    \            }\n            return v;\n        }\n    }\n\n    T operator [](int\
    \ i) const {\n        return sum(i, i + 1);\n    }\n};\n#line 6 \"test/library_checker/data_structure/point_add_range_sum.test.cpp\"\
    \n\nint main(){\n    int n, q; cin >> n >> q;\n    BinaryIndexedTree<long long>\
    \ BIT(n);\n    for(int i = 0; i < n; i++){\n        int a; cin >> a;\n       \
    \ BIT.add(i, a);\n    }\n    while(q--){\n        int t; cin >> t;\n        if(t\
    \ == 0){\n            int p, x; cin >> p >> x;\n            BIT.add(p, x);\n \
    \       }else{\n            int l, r; cin >> l >> r;\n            cout << BIT.sum(l,\
    \ r) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/binary_indexed_tree.hpp\"\
    \n\nint main(){\n    int n, q; cin >> n >> q;\n    BinaryIndexedTree<long long>\
    \ BIT(n);\n    for(int i = 0; i < n; i++){\n        int a; cin >> a;\n       \
    \ BIT.add(i, a);\n    }\n    while(q--){\n        int t; cin >> t;\n        if(t\
    \ == 0){\n            int p, x; cin >> p >> x;\n            BIT.add(p, x);\n \
    \       }else{\n            int l, r; cin >> l >> r;\n            cout << BIT.sum(l,\
    \ r) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - lib/data_structure/binary_indexed_tree.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-05-14 15:04:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/point_add_range_sum.test.cpp
- /verify/test/library_checker/data_structure/point_add_range_sum.test.cpp.html
title: test/library_checker/data_structure/point_add_range_sum.test.cpp
---
