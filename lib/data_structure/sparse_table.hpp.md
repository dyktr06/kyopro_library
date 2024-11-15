---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/data_structure/static_rmq_1.test.cpp
    title: test/library_checker/data_structure/static_rmq_1.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Sparse Table
    links: []
  bundledCode: "#line 2 \"lib/data_structure/sparse_table.hpp\"\n\n/**\n * @brief\
    \ Sparse Table\n */\n\n#include <vector>\n#include <cassert>\n\ntemplate <class\
    \ T, T (*op)(T, T)>\nstruct SparseTable{\n    std::vector<std::vector<T>> _table;\n\
    \    std::vector<int> _log2;\n\n    SparseTable(const std::vector<T> &v){\n  \
    \      const int n = v.size();\n        _log2.assign(n + 1, 0);\n        for(int\
    \ i = 2; i <= n; i++) _log2[i] = _log2[i >> 1] + 1;\n        _table.assign(_log2[n]\
    \ + 1, std::vector<T>(n));\n        for(int i = 0; i < n; i++) _table[0][i] =\
    \ v[i];\n        for(int k = 1; k <= _log2[n]; k++){\n            for(int i =\
    \ 0; i + (1 << k) <= n; i++)\n                _table[k][i] = op(_table[k - 1][i],\
    \ _table[k - 1][i + (1 << (k - 1))]);\n        }\n    }\n\n    inline T query(const\
    \ int &l, const int &r) const {\n        assert(l < r);\n        const int ex\
    \ = _log2[r - l];\n        return op(_table[ex][l], _table[ex][r - (1 << ex)]);\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Sparse Table\n */\n\n#include <vector>\n#include\
    \ <cassert>\n\ntemplate <class T, T (*op)(T, T)>\nstruct SparseTable{\n    std::vector<std::vector<T>>\
    \ _table;\n    std::vector<int> _log2;\n\n    SparseTable(const std::vector<T>\
    \ &v){\n        const int n = v.size();\n        _log2.assign(n + 1, 0);\n   \
    \     for(int i = 2; i <= n; i++) _log2[i] = _log2[i >> 1] + 1;\n        _table.assign(_log2[n]\
    \ + 1, std::vector<T>(n));\n        for(int i = 0; i < n; i++) _table[0][i] =\
    \ v[i];\n        for(int k = 1; k <= _log2[n]; k++){\n            for(int i =\
    \ 0; i + (1 << k) <= n; i++)\n                _table[k][i] = op(_table[k - 1][i],\
    \ _table[k - 1][i + (1 << (k - 1))]);\n        }\n    }\n\n    inline T query(const\
    \ int &l, const int &r) const {\n        assert(l < r);\n        const int ex\
    \ = _log2[r - l];\n        return op(_table[ex][l], _table[ex][r - (1 << ex)]);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2024-11-15 15:44:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/data_structure/static_rmq_1.test.cpp
documentation_of: lib/data_structure/sparse_table.hpp
layout: document
redirect_from:
- /library/lib/data_structure/sparse_table.hpp
- /library/lib/data_structure/sparse_table.hpp.html
title: Sparse Table
---
