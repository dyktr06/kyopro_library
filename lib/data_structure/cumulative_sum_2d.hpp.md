---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/dsl_5_b_cs2d.test.cpp
    title: test/aoj/dsl/dsl_5_b_cs2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/cumulative_sum_2d.md
    document_title: Cumulative Sum 2D
    links: []
  bundledCode: "#line 2 \"lib/data_structure/cumulative_sum_2d.hpp\"\n\n/**\n * @brief\
    \ Cumulative Sum 2D\n * @docs docs/data_structure/cumulative_sum_2d.md\n */\n\n\
    #include <vector>\n#include <cassert>\n\ntemplate <typename T>\nstruct CumulativeSum2D{\n\
    \    int H, W;\n    std::vector<std::vector<T>> data;\n\n    CumulativeSum2D(const\
    \ int _H, const int _W) : H(_H), W(_W), data(_H + 3, std::vector<T>(_W + 3, 0))\
    \ {}\n\n    void add(int i, int j, const T &z){\n        ++i, ++j;\n        if(i\
    \ >= (int) data.size() || j >= (int) data[0].size()) return;\n        data[i][j]\
    \ += z;\n    }\n\n    void imos(const int i1, const int j1, const int i2, const\
    \ int j2, const T &z = 1) {\n        assert(0 <= i1 && i1 <= i2 && i2 <= H);\n\
    \        assert(0 <= j1 && j1 <= j2 && j2 <= W);\n        add(i1, j1, z);\n  \
    \      add(i1, j2, -z);\n        add(i2, j1, -z);\n        add(i2, j2, z);\n \
    \   }\n\n    void build(){\n        for(int i = 1; i < (int) data.size(); ++i){\n\
    \            for(int j = 1; j < (int) data[i].size(); ++j){\n                data[i][j]\
    \ += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];\n            }\n  \
    \      }\n    }\n\n    inline T imos_get(const int i, const int j) const{\n  \
    \      return data[i + 1][j + 1];\n    }\n\n    inline T sum(const int i1, const\
    \ int j1, const int i2, const int j2) const {\n        assert(0 <= i1 && i1 <=\
    \ i2 && i2 <= H);\n        assert(0 <= j1 && j1 <= j2 && j2 <= W);\n        return\
    \ (data[i2][j2] - data[i1][j2] - data[i2][j1] + data[i1][j1]);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Cumulative Sum 2D\n * @docs docs/data_structure/cumulative_sum_2d.md\n\
    \ */\n\n#include <vector>\n#include <cassert>\n\ntemplate <typename T>\nstruct\
    \ CumulativeSum2D{\n    int H, W;\n    std::vector<std::vector<T>> data;\n\n \
    \   CumulativeSum2D(const int _H, const int _W) : H(_H), W(_W), data(_H + 3, std::vector<T>(_W\
    \ + 3, 0)) {}\n\n    void add(int i, int j, const T &z){\n        ++i, ++j;\n\
    \        if(i >= (int) data.size() || j >= (int) data[0].size()) return;\n   \
    \     data[i][j] += z;\n    }\n\n    void imos(const int i1, const int j1, const\
    \ int i2, const int j2, const T &z = 1) {\n        assert(0 <= i1 && i1 <= i2\
    \ && i2 <= H);\n        assert(0 <= j1 && j1 <= j2 && j2 <= W);\n        add(i1,\
    \ j1, z);\n        add(i1, j2, -z);\n        add(i2, j1, -z);\n        add(i2,\
    \ j2, z);\n    }\n\n    void build(){\n        for(int i = 1; i < (int) data.size();\
    \ ++i){\n            for(int j = 1; j < (int) data[i].size(); ++j){\n        \
    \        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];\n\
    \            }\n        }\n    }\n\n    inline T imos_get(const int i, const int\
    \ j) const{\n        return data[i + 1][j + 1];\n    }\n\n    inline T sum(const\
    \ int i1, const int j1, const int i2, const int j2) const {\n        assert(0\
    \ <= i1 && i1 <= i2 && i2 <= H);\n        assert(0 <= j1 && j1 <= j2 && j2 <=\
    \ W);\n        return (data[i2][j2] - data[i1][j2] - data[i2][j1] + data[i1][j1]);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/cumulative_sum_2d.hpp
  requiredBy: []
  timestamp: '2024-11-15 16:06:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl/dsl_5_b_cs2d.test.cpp
documentation_of: lib/data_structure/cumulative_sum_2d.hpp
layout: document
redirect_from:
- /library/lib/data_structure/cumulative_sum_2d.hpp
- /library/lib/data_structure/cumulative_sum_2d.hpp.html
title: Cumulative Sum 2D
---
## Cumulative Sum 2D (二次元累積和)

#### 使い方

- `CumulativeSum2D<T>(H, W)`: コンストラクタ
- `add(x, y, z)`: (x, y) に z を加算します。
- `imos(x1, y1, x2, y2, z)`: いもす法において、[(x1, y1), (x2, y2)) に v を加算します。
- `build()`: 加算された配列を構築します。
- `sum(x1, y1, x2, y2)`: [(x1, y1), (x2, y2)) の和を取得します。

#### 計算量

- `CumulativeSum2D<T>(H, W)`: $\mathrm{O}(HW)$
- `add(x, y, z)`: $\mathrm{O}(1)$
- `imos(x1, y1, x2, y2, z)`: $\mathrm{O}(1)$
- `build()`: $\mathrm{O}(HW)$
- `sum(x1, y1, x2, y2)`: $\mathrm{O}(1)$
