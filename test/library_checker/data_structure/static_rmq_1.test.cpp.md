---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/sparse_table.hpp
    title: lib/data_structure/sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/library_checker/data_structure/static_rmq_1.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"lib/data_structure/sparse_table.hpp\"\n\ntemplate\
    \ <class T>\nstruct SparseTable{\n    using FX = function<T(T, T)>;\n    FX op;\n\
    \    vector<vector<T>> _table;\n    vector<int> _log2;\n\n    SparseTable(const\
    \ vector<T> &v, const FX &fx_) : op(fx_){\n        const int n = v.size();\n \
    \       _log2.assign(n + 1, 0);\n        for(int i = 2; i <= n; i++) _log2[i]\
    \ = _log2[i >> 1] + 1;\n        _table.assign(_log2[n] + 1, vector<T>(n));\n \
    \       for(int i = 0; i < n; i++) _table[0][i] = v[i];\n        for(int k = 1;\
    \ k <= _log2[n]; k++){\n            for(int i = 0; i + (1 << k) <= n; i++)\n \
    \               _table[k][i] = op(_table[k - 1][i], _table[k - 1][i + (1 << (k\
    \ - 1))]);\n        }\n    }\n\n    inline T query(const int &l, const int &r)\
    \ const {\n        const int ex = _log2[r - l];\n        return op(_table[ex][l],\
    \ _table[ex][r - (1 << ex)]);\n    }\n};\n#line 6 \"test/library_checker/data_structure/static_rmq_1.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n   \
    \ \n    int n, q; cin >> n >> q;\n    auto fx = [](int x1, int x2) -> int { return\
    \ min(x1, x2); };\n    vector<int> a(n);\n    for(int i = 0; i < n; i++){\n  \
    \      cin >> a[i];\n    }\n    SparseTable<int> rmq(a, fx);\n    while(q--){\n\
    \        int l, r; cin >> l >> r;\n        cout << rmq.query(l, r) << \"\\n\"\
    ;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../../lib/data_structure/sparse_table.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n   \
    \ \n    int n, q; cin >> n >> q;\n    auto fx = [](int x1, int x2) -> int { return\
    \ min(x1, x2); };\n    vector<int> a(n);\n    for(int i = 0; i < n; i++){\n  \
    \      cin >> a[i];\n    }\n    SparseTable<int> rmq(a, fx);\n    while(q--){\n\
    \        int l, r; cin >> l >> r;\n        cout << rmq.query(l, r) << \"\\n\"\
    ;\n    }\n}"
  dependsOn:
  - lib/data_structure/sparse_table.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/static_rmq_1.test.cpp
  requiredBy: []
  timestamp: '2024-02-14 05:46:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/static_rmq_1.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/static_rmq_1.test.cpp
- /verify/test/library_checker/data_structure/static_rmq_1.test.cpp.html
title: test/library_checker/data_structure/static_rmq_1.test.cpp
---
