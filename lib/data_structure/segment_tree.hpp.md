---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/static_rmq.test.cpp
    title: test/library_checker/data_structure/static_rmq.test.cpp
  - icon: ':x:'
    path: test/library_checker/tree/vertex_set_path_composite.test.cpp
    title: test/library_checker/tree/vertex_set_path_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/data_structure/segment_tree.md
    document_title: Segment Tree
    links: []
  bundledCode: "#line 2 \"lib/data_structure/segment_tree.hpp\"\n\n/**\n * @brief\
    \ Segment Tree\n * @docs docs/data_structure/segment_tree.md\n */\n\ntemplate\
    \ <typename T>\nstruct SegTree{\n    using FX = function<T(T, T)>; // T\u2022\
    T -> T \u3068\u306A\u308B\u95A2\u6570\u306E\u578B\n    int n;\n    const FX fx;\n\
    \    const T ex;\n    vector<T> dat;\n\n    SegTree(int n_, const FX &fx_, const\
    \ T &ex_) : n(), fx(fx_), ex(ex_){\n        int x = 1;\n        while(n_ > x){\n\
    \            x *= 2;\n        }\n        n = x;\n        dat.resize(n * 2);\n\
    \        for(int i = 0; i < n * 2; ++i){\n            dat[i] = ex;\n        }\n\
    \    }\n    SegTree(vector<T> &v, const FX &fx_, const T &ex_) : n(), fx(fx_),\
    \ ex(ex_){\n        int x = 1;\n        while((int) v.size() > x){\n         \
    \   x *= 2;\n        }\n        n = x;\n        dat.resize(n * 2);\n        for(int\
    \ i = 0; i < n; ++i){\n            set(i, (i < (int) v.size() ? v[i] : ex));\n\
    \        }\n        build();\n    }\n\n    void set(int i, const T &x){ dat[i\
    \ + n] = x; }\n\n    void build(){\n        for(int k = n - 1; k >= 1; k--) dat[k]\
    \ = fx(dat[k * 2], dat[k * 2 + 1]);\n    }\n\n    T get(int i) const {\n     \
    \   return dat[i + n];\n    }\n\n    void update(int i, const T &x){\n       \
    \ i += n;\n        dat[i] = x;\n        while(i > 0){\n            i >>= 1;  //\
    \ parent\n            dat[i] = fx(dat[i * 2], dat[i * 2 + 1]);\n        }\n  \
    \  }\n\n    T query(int a, int b){\n        T vl = ex;\n        T vr = ex;\n \
    \       int l = a + n;\n        int r = b + n;\n        while(l < r){\n      \
    \      if(l & 1) vl = fx(vl, dat[l++]);\n            if(r & 1) vr = fx(dat[--r],\
    \ vr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ fx(vl, vr);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Segment Tree\n * @docs docs/data_structure/segment_tree.md\n\
    \ */\n\ntemplate <typename T>\nstruct SegTree{\n    using FX = function<T(T, T)>;\
    \ // T\u2022T -> T \u3068\u306A\u308B\u95A2\u6570\u306E\u578B\n    int n;\n  \
    \  const FX fx;\n    const T ex;\n    vector<T> dat;\n\n    SegTree(int n_, const\
    \ FX &fx_, const T &ex_) : n(), fx(fx_), ex(ex_){\n        int x = 1;\n      \
    \  while(n_ > x){\n            x *= 2;\n        }\n        n = x;\n        dat.resize(n\
    \ * 2);\n        for(int i = 0; i < n * 2; ++i){\n            dat[i] = ex;\n \
    \       }\n    }\n    SegTree(vector<T> &v, const FX &fx_, const T &ex_) : n(),\
    \ fx(fx_), ex(ex_){\n        int x = 1;\n        while((int) v.size() > x){\n\
    \            x *= 2;\n        }\n        n = x;\n        dat.resize(n * 2);\n\
    \        for(int i = 0; i < n; ++i){\n            set(i, (i < (int) v.size() ?\
    \ v[i] : ex));\n        }\n        build();\n    }\n\n    void set(int i, const\
    \ T &x){ dat[i + n] = x; }\n\n    void build(){\n        for(int k = n - 1; k\
    \ >= 1; k--) dat[k] = fx(dat[k * 2], dat[k * 2 + 1]);\n    }\n\n    T get(int\
    \ i) const {\n        return dat[i + n];\n    }\n\n    void update(int i, const\
    \ T &x){\n        i += n;\n        dat[i] = x;\n        while(i > 0){\n      \
    \      i >>= 1;  // parent\n            dat[i] = fx(dat[i * 2], dat[i * 2 + 1]);\n\
    \        }\n    }\n\n    T query(int a, int b){\n        T vl = ex;\n        T\
    \ vr = ex;\n        int l = a + n;\n        int r = b + n;\n        while(l <\
    \ r){\n            if(l & 1) vl = fx(vl, dat[l++]);\n            if(r & 1) vr\
    \ = fx(dat[--r], vr);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return fx(vl, vr);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2024-05-31 18:23:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/data_structure/static_rmq.test.cpp
  - test/library_checker/tree/vertex_set_path_composite.test.cpp
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