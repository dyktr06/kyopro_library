---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/data_structure/sparse_table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/library_checker/data_structure/static_rmq_1.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <iostream>\n\
    \n#line 2 \"lib/data_structure/sparse_table.hpp\"\n\n/**\n * @brief Sparse Table\n\
    \ */\n\n#include <vector>\n#include <cassert>\n\ntemplate <class T, T (*op)(T,\
    \ T)>\nstruct SparseTable{\n    std::vector<std::vector<T>> _table;\n    std::vector<int>\
    \ _log2;\n\n    SparseTable(const std::vector<T> &v){\n        const int n = v.size();\n\
    \        _log2.assign(n + 1, 0);\n        for(int i = 2; i <= n; i++) _log2[i]\
    \ = _log2[i >> 1] + 1;\n        _table.assign(_log2[n] + 1, std::vector<T>(n));\n\
    \        for(int i = 0; i < n; i++) _table[0][i] = v[i];\n        for(int k =\
    \ 1; k <= _log2[n]; k++){\n            for(int i = 0; i + (1 << k) <= n; i++)\n\
    \                _table[k][i] = op(_table[k - 1][i], _table[k - 1][i + (1 << (k\
    \ - 1))]);\n        }\n    }\n\n    inline T query(const int &l, const int &r)\
    \ const {\n        assert(l < r);\n        const int ex = _log2[r - l];\n    \
    \    return op(_table[ex][l], _table[ex][r - (1 << ex)]);\n    }\n};\n#line 5\
    \ \"test/library_checker/data_structure/static_rmq_1.test.cpp\"\n\nusing namespace\
    \ std;\n\nint op(int a, int b){\n    return min(a, b);\n}\n\nint main(){\n   \
    \ ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int n, q; cin >>\
    \ n >> q;\n    vector<int> a(n);\n    for(int i = 0; i < n; i++){\n        cin\
    \ >> a[i];\n    }\n    SparseTable<int, op> rmq(a);\n    while(q--){\n       \
    \ int l, r; cin >> l >> r;\n        cout << rmq.query(l, r) << \"\\n\";\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <iostream>\n\
    \n#include \"../../../lib/data_structure/sparse_table.hpp\"\n\nusing namespace\
    \ std;\n\nint op(int a, int b){\n    return min(a, b);\n}\n\nint main(){\n   \
    \ ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int n, q; cin >>\
    \ n >> q;\n    vector<int> a(n);\n    for(int i = 0; i < n; i++){\n        cin\
    \ >> a[i];\n    }\n    SparseTable<int, op> rmq(a);\n    while(q--){\n       \
    \ int l, r; cin >> l >> r;\n        cout << rmq.query(l, r) << \"\\n\";\n    }\n\
    }\n"
  dependsOn:
  - lib/data_structure/sparse_table.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/static_rmq_1.test.cpp
  requiredBy: []
  timestamp: '2024-11-15 15:44:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/data_structure/static_rmq_1.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/static_rmq_1.test.cpp
- /verify/test/library_checker/data_structure/static_rmq_1.test.cpp.html
title: test/library_checker/data_structure/static_rmq_1.test.cpp
---
