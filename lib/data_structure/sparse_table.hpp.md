---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/static_rmq_1.test.cpp
    title: test/library_checker/data_structure/static_rmq_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/sparse_table.hpp\"\n\ntemplate <class\
    \ T>\nstruct SparseTable{\n    using FX = function<T(T, T)>;\n    FX op;\n   \
    \ vector<vector<T>> _table;\n    vector<int> _log2;\n\n    SparseTable(const vector<T>\
    \ &v, FX fx_) : op(fx_){\n        const int n = v.size();\n        _log2.assign(n\
    \ + 1, 0);\n        for (int i = 2; i <= n; i++) _log2[i] = _log2[i >> 1] + 1;\n\
    \        _table.assign(_log2[n] + 1, vector<T>(n));\n        for (int i = 0; i\
    \ < n; i++) _table[0][i] = v[i];\n        for (int k = 1; k <= _log2[n]; k++)\
    \ {\n            for (int i = 0; i + (1 << k) <= n; i++)\n                _table[k][i]\
    \ = op(_table[k - 1][i], _table[k - 1][i + (1 << (k - 1))]);\n        }\n    }\n\
    \n    inline T query(const int& l, const int& r) const {\n        const int ex\
    \ = _log2[r - l];\n        return op(_table[ex][l], _table[ex][r - (1 << ex)]);\n\
    \    }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct SparseTable{\n    using FX = function<T(T,\
    \ T)>;\n    FX op;\n    vector<vector<T>> _table;\n    vector<int> _log2;\n\n\
    \    SparseTable(const vector<T> &v, FX fx_) : op(fx_){\n        const int n =\
    \ v.size();\n        _log2.assign(n + 1, 0);\n        for (int i = 2; i <= n;\
    \ i++) _log2[i] = _log2[i >> 1] + 1;\n        _table.assign(_log2[n] + 1, vector<T>(n));\n\
    \        for (int i = 0; i < n; i++) _table[0][i] = v[i];\n        for (int k\
    \ = 1; k <= _log2[n]; k++) {\n            for (int i = 0; i + (1 << k) <= n; i++)\n\
    \                _table[k][i] = op(_table[k - 1][i], _table[k - 1][i + (1 << (k\
    \ - 1))]);\n        }\n    }\n\n    inline T query(const int& l, const int& r)\
    \ const {\n        const int ex = _log2[r - l];\n        return op(_table[ex][l],\
    \ _table[ex][r - (1 << ex)]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2024-01-29 20:46:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/static_rmq_1.test.cpp
documentation_of: lib/data_structure/sparse_table.hpp
layout: document
redirect_from:
- /library/lib/data_structure/sparse_table.hpp
- /library/lib/data_structure/sparse_table.hpp.html
title: lib/data_structure/sparse_table.hpp
---
