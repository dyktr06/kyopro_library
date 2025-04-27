---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp
    title: test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/associative_array.test.cpp
    title: test/library_checker/data_structure/associative_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/point_add_rectangle_sum.test.cpp
    title: test/library_checker/data_structure/point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp
    title: test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/range_kth_smallest.test.cpp
    title: test/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/static_range_count_distinct.test.cpp
    title: test/library_checker/data_structure/static_range_count_distinct.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/static_range_frequency.test.cpp
    title: test/library_checker/data_structure/static_range_frequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/static_range_inversions_query.test.cpp
    title: test/library_checker/data_structure/static_range_inversions_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/static_range_mode_query.test.cpp
    title: test/library_checker/data_structure/static_range_mode_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/others/compression.md
    document_title: "Compression (\u5EA7\u6A19\u5727\u7E2E)"
    links: []
  bundledCode: "#line 2 \"lib/others/compression.hpp\"\n\n/**\n * @brief Compression\
    \ (\u5EA7\u6A19\u5727\u7E2E)\n * @docs docs/others/compression.md\n */\n\n#include\
    \ <vector>\n#include <algorithm>\n\ntemplate <typename T>\nstruct compress{\n\
    \    std::vector<T> sorted;\n    std::vector<int> compressed;\n\n    compress(const\
    \ std::vector<T> &vec){\n        int n = vec.size();\n        compressed.resize(n);\n\
    \        for(T x : vec){\n            sorted.emplace_back(x);\n        }\n   \
    \     std::sort(sorted.begin(), sorted.end());\n        sorted.erase(std::unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n        for(int i = 0; i < n; ++i){\n       \
    \     compressed[i] = std::lower_bound(sorted.begin(), sorted.end(), vec[i]) -\
    \ sorted.begin();\n        }\n    }\n\n    int get(const T &x) const{\n      \
    \  return std::lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();\n\
    \    }\n\n    T inv(const int x) const{\n        return sorted[x];\n    }\n\n\
    \    size_t size() const{\n        return sorted.size();\n    }\n\n    std::vector<int>\
    \ getCompressed() const{\n        return compressed;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Compression (\u5EA7\u6A19\u5727\u7E2E)\n *\
    \ @docs docs/others/compression.md\n */\n\n#include <vector>\n#include <algorithm>\n\
    \ntemplate <typename T>\nstruct compress{\n    std::vector<T> sorted;\n    std::vector<int>\
    \ compressed;\n\n    compress(const std::vector<T> &vec){\n        int n = vec.size();\n\
    \        compressed.resize(n);\n        for(T x : vec){\n            sorted.emplace_back(x);\n\
    \        }\n        std::sort(sorted.begin(), sorted.end());\n        sorted.erase(std::unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n        for(int i = 0; i < n; ++i){\n       \
    \     compressed[i] = std::lower_bound(sorted.begin(), sorted.end(), vec[i]) -\
    \ sorted.begin();\n        }\n    }\n\n    int get(const T &x) const{\n      \
    \  return std::lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();\n\
    \    }\n\n    T inv(const int x) const{\n        return sorted[x];\n    }\n\n\
    \    size_t size() const{\n        return sorted.size();\n    }\n\n    std::vector<int>\
    \ getCompressed() const{\n        return compressed;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/compression.hpp
  requiredBy: []
  timestamp: '2025-01-09 22:07:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp
  - test/library_checker/data_structure/static_range_count_distinct.test.cpp
  - test/library_checker/data_structure/range_kth_smallest.test.cpp
  - test/library_checker/data_structure/static_range_inversions_query.test.cpp
  - test/library_checker/data_structure/static_range_mode_query.test.cpp
  - test/library_checker/data_structure/static_range_frequency.test.cpp
  - test/library_checker/data_structure/associative_array.test.cpp
  - test/library_checker/data_structure/point_add_rectangle_sum.test.cpp
  - test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp
documentation_of: lib/others/compression.hpp
layout: document
redirect_from:
- /library/lib/others/compression.hpp
- /library/lib/others/compression.hpp.html
title: "Compression (\u5EA7\u6A19\u5727\u7E2E)"
---
## Compression (座標圧縮)

#### 使い方

- `compress<T>(vec)`: vec を座標圧縮します。
- `get(x)`: x の座標圧縮後の値を取得します。
- `inv(x)`: x の座標圧縮前の値を取得します。
- `getCompressed()`: 座標圧縮後の配列を取得します。

#### 計算量

- `compress<T>(vec)`: $\mathrm{O}(N \log N)$
- `get(x)`: $\mathrm{O}(\log N)$
- `inv(x)`: $\mathrm{O}(1)$
- `getCompressed()`: $\mathrm{O}(N)$