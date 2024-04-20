---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/static_rmq.test.cpp
    title: test/library_checker/data_structure/static_rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/vertex_set_path_composite.test.cpp
    title: test/library_checker/data_structure/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/segment_tree.md
    document_title: Segment Tree
    links: []
  bundledCode: "#line 2 \"lib/data_structure/segment_tree.hpp\"\n\n/**\n * @brief\
    \ Segment Tree\n * @docs docs/data_structure/segment_tree.md\n */\n\ntemplate\
    \ <typename X>\nstruct SegTree{\n    using FX = function<X(X, X)>; // X\u2022\
    X -> X \u3068\u306A\u308B\u95A2\u6570\u306E\u578B\n    int n;\n    FX fx;\n  \
    \  const X ex;\n    vector<X> dat;\n\n    SegTree(int n_, const FX &fx_, const\
    \ X &ex_) : n(), fx(fx_), ex(ex_){\n        int x = 1;\n        while(n_ > x){\n\
    \            x *= 2;\n        }\n        n = x;\n        dat.assign(n * 2, ex);\n\
    \    }\n\n    X get(int i) const {\n        return dat[i + n];\n    }\n    \n\
    \    void set(int i, const X &x){ dat[i + n] = x; }\n\n    void build(){\n   \
    \     for(int k = n - 1; k >= 1; k--) dat[k] = fx(dat[k * 2], dat[k * 2 + 1]);\n\
    \    }\n\n    void update(int i, const X &x){\n        i += n;\n        dat[i]\
    \ = x;\n        while(i > 0){\n            i >>= 1;  // parent\n            dat[i]\
    \ = fx(dat[i * 2], dat[i * 2 + 1]);\n        }\n    }\n\n    X query(int a, int\
    \ b){\n        X vl = ex;\n        X vr = ex;\n        int l = a + n;\n      \
    \  int r = b + n;\n        while(l < r){\n            if(l & 1) vl = fx(vl, dat[l++]);\n\
    \            if(r & 1) vr = fx(dat[--r], vr);\n            l >>= 1;\n        \
    \    r >>= 1;\n        }\n        return fx(vl, vr);\n    }\n    \n    X operator\
    \ [](int i) const {\n        return dat[i + n];\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Segment Tree\n * @docs docs/data_structure/segment_tree.md\n\
    \ */\n\ntemplate <typename X>\nstruct SegTree{\n    using FX = function<X(X, X)>;\
    \ // X\u2022X -> X \u3068\u306A\u308B\u95A2\u6570\u306E\u578B\n    int n;\n  \
    \  FX fx;\n    const X ex;\n    vector<X> dat;\n\n    SegTree(int n_, const FX\
    \ &fx_, const X &ex_) : n(), fx(fx_), ex(ex_){\n        int x = 1;\n        while(n_\
    \ > x){\n            x *= 2;\n        }\n        n = x;\n        dat.assign(n\
    \ * 2, ex);\n    }\n\n    X get(int i) const {\n        return dat[i + n];\n \
    \   }\n    \n    void set(int i, const X &x){ dat[i + n] = x; }\n\n    void build(){\n\
    \        for(int k = n - 1; k >= 1; k--) dat[k] = fx(dat[k * 2], dat[k * 2 + 1]);\n\
    \    }\n\n    void update(int i, const X &x){\n        i += n;\n        dat[i]\
    \ = x;\n        while(i > 0){\n            i >>= 1;  // parent\n            dat[i]\
    \ = fx(dat[i * 2], dat[i * 2 + 1]);\n        }\n    }\n\n    X query(int a, int\
    \ b){\n        X vl = ex;\n        X vr = ex;\n        int l = a + n;\n      \
    \  int r = b + n;\n        while(l < r){\n            if(l & 1) vl = fx(vl, dat[l++]);\n\
    \            if(r & 1) vr = fx(dat[--r], vr);\n            l >>= 1;\n        \
    \    r >>= 1;\n        }\n        return fx(vl, vr);\n    }\n    \n    X operator\
    \ [](int i) const {\n        return dat[i + n];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2024-01-29 20:46:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/vertex_set_path_composite.test.cpp
  - test/library_checker/data_structure/static_rmq.test.cpp
documentation_of: lib/data_structure/segment_tree.hpp
layout: document
redirect_from:
- /library/lib/data_structure/segment_tree.hpp
- /library/lib/data_structure/segment_tree.hpp.html
title: Segment Tree
---
## Segment Tree

#### 使い方

- `SegTree<X>(N, fx, ex)`: モノイド(集合 X, 二項演算 fx, 単位元 ex) について Segment Tree をサイズ N で構築します。
- `get(i)`: i 番目の要素を取得します。
- `update(i, x)`: i 番目の要素を x に更新します。
- `query(a, b)`: 区間 `[a, b)` の全てに fx を作用させた値を取得します。

#### 計算量

- `get(i)`: $\mathrm{O}(1)$
- `update(i, x)`: $\mathrm{O}(\log N)$
- `query(a, b)`: $\mathrm{O}(\log N)$