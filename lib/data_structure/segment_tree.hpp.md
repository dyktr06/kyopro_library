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
    \  const X ex;\n    vector<X> dat;\n\n    SegTree(int n_, FX fx_, X ex_) : n(),\
    \ fx(fx_), ex(ex_), dat(n_ * 4, ex_){\n        int x = 1;\n        while(n_ >\
    \ x){\n            x *= 2;\n        }\n        n = x;\n    }\n\n    X get(int\
    \ i){\n        return dat[i + n - 1];\n    }\n    \n    void set(int i, X x){\
    \ dat[i + n - 1] = x; }\n\n    void build(){\n        for(int k = n - 2; k >=\
    \ 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);\n    }\n\n    void update(int\
    \ i, X x){\n        i += n - 1;\n        dat[i] = x;\n        while(i > 0){\n\
    \            i = (i - 1) / 2;  // parent\n            dat[i] = fx(dat[i * 2 +\
    \ 1], dat[i * 2 + 2]);\n        }\n    }\n\n    X query(int a, int b){ return\
    \ query_sub(a, b, 0, 0, n); }\n\n    X query_sub(int a, int b, int k, int l, int\
    \ r){\n        if(r <= a || b <= l){\n            return ex;\n        }else if(a\
    \ <= l && r <= b){\n            return dat[k];\n        }else{\n            X\
    \ vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);\n            X vr = query_sub(a,\
    \ b, k * 2 + 2, (l + r) / 2, r);\n            return fx(vl, vr);\n        }\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Segment Tree\n * @docs docs/data_structure/segment_tree.md\n\
    \ */\n\ntemplate <typename X>\nstruct SegTree{\n    using FX = function<X(X, X)>;\
    \ // X\u2022X -> X \u3068\u306A\u308B\u95A2\u6570\u306E\u578B\n    int n;\n  \
    \  FX fx;\n    const X ex;\n    vector<X> dat;\n\n    SegTree(int n_, FX fx_,\
    \ X ex_) : n(), fx(fx_), ex(ex_), dat(n_ * 4, ex_){\n        int x = 1;\n    \
    \    while(n_ > x){\n            x *= 2;\n        }\n        n = x;\n    }\n\n\
    \    X get(int i){\n        return dat[i + n - 1];\n    }\n    \n    void set(int\
    \ i, X x){ dat[i + n - 1] = x; }\n\n    void build(){\n        for(int k = n -\
    \ 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);\n    }\n\n    void\
    \ update(int i, X x){\n        i += n - 1;\n        dat[i] = x;\n        while(i\
    \ > 0){\n            i = (i - 1) / 2;  // parent\n            dat[i] = fx(dat[i\
    \ * 2 + 1], dat[i * 2 + 2]);\n        }\n    }\n\n    X query(int a, int b){ return\
    \ query_sub(a, b, 0, 0, n); }\n\n    X query_sub(int a, int b, int k, int l, int\
    \ r){\n        if(r <= a || b <= l){\n            return ex;\n        }else if(a\
    \ <= l && r <= b){\n            return dat[k];\n        }else{\n            X\
    \ vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);\n            X vr = query_sub(a,\
    \ b, k * 2 + 2, (l + r) / 2, r);\n            return fx(vl, vr);\n        }\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2023-01-06 16:06:42+09:00'
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