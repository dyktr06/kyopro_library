---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/static_range_sum.test.cpp
    title: test/library_checker/data_structure/static_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/static_rmq_2.test.cpp
    title: test/library_checker/data_structure/static_rmq_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/disjoint_sparse_table.hpp\"\n\ntemplate\
    \ <typename T, T (*op)(T, T)>\nstruct DisjointSparseTable{\n    int n, log2;\n\
    \    std::vector<std::vector<T>> table;\n    std::vector<T> val;\n    DisjointSparseTable(std::vector<T>\
    \ &a) : val(a) {\n        int len = a.size();\n        n = 1, log2 = 0;\n    \
    \    while(n < len){\n            n *= 2;\n            log2++;\n        }\n  \
    \      val.resize(n);\n        table = std::vector<std::vector<T>>(log2, std::vector<T>(n));\n\
    \        init();\n    }\n\n    void init(){\n        for(int i = 0; i < log2;\
    \ i++){\n            for(int j = 0; j < n; j += (n >> i)){\n                int\
    \ h = n >> (i + 1);\n                // h \u3092\u4E2D\u5FC3\u306B\u5DE6\u53F3\
    \u306B\u7D2F\u7A4D\u3057\u305F\u5024\u3092\u8A08\u7B97\n                table[i][j\
    \ + h] = val[j + h];\n                for(int k = j + h + 1; k < j + h * 2; k++){\n\
    \                    table[i][k] = op(table[i][k - 1], val[k]);\n            \
    \    }\n                table[i][j + h - 1] = val[j + h - 1];\n              \
    \  for(int k = j + h - 2; k >= j; k--){\n                    table[i][k] = op(table[i][k\
    \ + 1], val[k]);\n                }\n            }\n        }\n    }\n\n    //\
    \ [l, r]\n    T query(int l, int r){\n        assert(l <= r);\n        if(l ==\
    \ r){\n            return val[l];\n        }\n        // \u307E\u305F\u3050\u5834\
    \u6240\u306E\u8A08\u7B97\n        int d = __builtin_clz(l ^ r) - (32 - log2);\n\
    \        return op(table[d][l], table[d][r]);\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T, T (*op)(T, T)>\nstruct DisjointSparseTable{\n\
    \    int n, log2;\n    std::vector<std::vector<T>> table;\n    std::vector<T>\
    \ val;\n    DisjointSparseTable(std::vector<T> &a) : val(a) {\n        int len\
    \ = a.size();\n        n = 1, log2 = 0;\n        while(n < len){\n           \
    \ n *= 2;\n            log2++;\n        }\n        val.resize(n);\n        table\
    \ = std::vector<std::vector<T>>(log2, std::vector<T>(n));\n        init();\n \
    \   }\n\n    void init(){\n        for(int i = 0; i < log2; i++){\n          \
    \  for(int j = 0; j < n; j += (n >> i)){\n                int h = n >> (i + 1);\n\
    \                // h \u3092\u4E2D\u5FC3\u306B\u5DE6\u53F3\u306B\u7D2F\u7A4D\u3057\
    \u305F\u5024\u3092\u8A08\u7B97\n                table[i][j + h] = val[j + h];\n\
    \                for(int k = j + h + 1; k < j + h * 2; k++){\n               \
    \     table[i][k] = op(table[i][k - 1], val[k]);\n                }\n        \
    \        table[i][j + h - 1] = val[j + h - 1];\n                for(int k = j\
    \ + h - 2; k >= j; k--){\n                    table[i][k] = op(table[i][k + 1],\
    \ val[k]);\n                }\n            }\n        }\n    }\n\n    // [l, r]\n\
    \    T query(int l, int r){\n        assert(l <= r);\n        if(l == r){\n  \
    \          return val[l];\n        }\n        // \u307E\u305F\u3050\u5834\u6240\
    \u306E\u8A08\u7B97\n        int d = __builtin_clz(l ^ r) - (32 - log2);\n    \
    \    return op(table[d][l], table[d][r]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2024-11-12 11:47:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/static_rmq_2.test.cpp
  - test/library_checker/data_structure/static_range_sum.test.cpp
documentation_of: lib/data_structure/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/lib/data_structure/disjoint_sparse_table.hpp
- /library/lib/data_structure/disjoint_sparse_table.hpp.html
title: lib/data_structure/disjoint_sparse_table.hpp
---
