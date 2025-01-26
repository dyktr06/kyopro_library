---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/point_add_range_sum.test.cpp
    title: test/library_checker/data_structure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/range_kth_smallest.test.cpp
    title: test/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/static_range_inversions_query.test.cpp
    title: test/library_checker/data_structure/static_range_inversions_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/vertex_add_path_sum.test.cpp
    title: test/library_checker/tree/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/vertex_add_subtree_sum.test.cpp
    title: test/library_checker/tree/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/binary_indexed_tree.md
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "#line 2 \"lib/data_structure/binary_indexed_tree.hpp\"\n\n/**\n *\
    \ @brief Binary Indexed Tree\n * @docs docs/data_structure/binary_indexed_tree.md\n\
    \ */\n\n#include <vector>\n\ntemplate <typename T>\nstruct BinaryIndexedTree{\n\
    \    int N;\n    std::vector<T> BIT;\n    BinaryIndexedTree(const int N) : N(N),\
    \ BIT(N + 1, 0){\n    }\n\n    T get(int i){\n        return sum(i + 1) - sum(i);\n\
    \    }\n\n    void add(int i, T x){\n        i++;\n        while(i <= N){\n  \
    \          BIT[i] += x;\n            i += i & -i;\n        }\n    }\n\n    T sum(int\
    \ i) const {\n        T ans = 0;\n        while(i > 0){\n            ans += BIT[i];\n\
    \            i -= i & -i;\n        }\n        return ans;\n    }\n\n    T sum(int\
    \ L, int R) const {\n        return sum(R) - sum(L);\n    }\n\n    int lower_bound(T\
    \ x) const {\n        if(x <= 0){\n            return 0;\n        } else{\n  \
    \          int v = 0, r = 1;\n            while(r < N) r = r << 1;\n         \
    \   for(int len = r; len > 0; len = len >> 1){\n                if(v + len < N\
    \ && BIT[v + len] < x){\n                    x -= BIT[v + len];\n            \
    \        v += len;\n                }\n            }\n            return v;\n\
    \        }\n    }\n\n    int upper_bound(T x) const {\n        if(x < 0){\n  \
    \          return 0;\n        } else{\n            int v = 0, r = 1;\n       \
    \     while(r <= N) r = r << 1;\n            for(int len = r; len > 0; len = len\
    \ >> 1){\n                if(v + len <= N && BIT[v + len] <= x){\n           \
    \         x -= BIT[v + len];\n                    v += len;\n                }\n\
    \            }\n            return v;\n        }\n    }\n\n    T operator [](int\
    \ i) const {\n        return sum(i, i + 1);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Binary Indexed Tree\n * @docs docs/data_structure/binary_indexed_tree.md\n\
    \ */\n\n#include <vector>\n\ntemplate <typename T>\nstruct BinaryIndexedTree{\n\
    \    int N;\n    std::vector<T> BIT;\n    BinaryIndexedTree(const int N) : N(N),\
    \ BIT(N + 1, 0){\n    }\n\n    T get(int i){\n        return sum(i + 1) - sum(i);\n\
    \    }\n\n    void add(int i, T x){\n        i++;\n        while(i <= N){\n  \
    \          BIT[i] += x;\n            i += i & -i;\n        }\n    }\n\n    T sum(int\
    \ i) const {\n        T ans = 0;\n        while(i > 0){\n            ans += BIT[i];\n\
    \            i -= i & -i;\n        }\n        return ans;\n    }\n\n    T sum(int\
    \ L, int R) const {\n        return sum(R) - sum(L);\n    }\n\n    int lower_bound(T\
    \ x) const {\n        if(x <= 0){\n            return 0;\n        } else{\n  \
    \          int v = 0, r = 1;\n            while(r < N) r = r << 1;\n         \
    \   for(int len = r; len > 0; len = len >> 1){\n                if(v + len < N\
    \ && BIT[v + len] < x){\n                    x -= BIT[v + len];\n            \
    \        v += len;\n                }\n            }\n            return v;\n\
    \        }\n    }\n\n    int upper_bound(T x) const {\n        if(x < 0){\n  \
    \          return 0;\n        } else{\n            int v = 0, r = 1;\n       \
    \     while(r <= N) r = r << 1;\n            for(int len = r; len > 0; len = len\
    \ >> 1){\n                if(v + len <= N && BIT[v + len] <= x){\n           \
    \         x -= BIT[v + len];\n                    v += len;\n                }\n\
    \            }\n            return v;\n        }\n    }\n\n    T operator [](int\
    \ i) const {\n        return sum(i, i + 1);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/binary_indexed_tree.hpp
  requiredBy: []
  timestamp: '2024-11-15 16:06:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/range_kth_smallest.test.cpp
  - test/library_checker/data_structure/static_range_inversions_query.test.cpp
  - test/library_checker/data_structure/point_add_range_sum.test.cpp
  - test/library_checker/tree/vertex_add_subtree_sum.test.cpp
  - test/library_checker/tree/vertex_add_path_sum.test.cpp
documentation_of: lib/data_structure/binary_indexed_tree.hpp
layout: document
redirect_from:
- /library/lib/data_structure/binary_indexed_tree.hpp
- /library/lib/data_structure/binary_indexed_tree.hpp.html
title: Binary Indexed Tree
---
## Binary Indexed Tree

#### 使い方

- `BinaryIndexedTree<T>(N)`: 要素数 $N$ のBITを構築します。
- `add(i, x)`: i 番目の要素に x を加算します。
- `get(i)`: i 番目の要素を取得します。
- `sum(i)`: 区間 `[0, i)`の和を取得します。
- `sum(l, r)`: 区間 `[l, r)` の和を取得します。
- `lower_bound(x)`: 要素が全て非負である時、`[0, k)`の区間和が x 以上となるような最小の k を求めます。
- `upper_bound(x)`: 要素が全て非負である時、`[0, k)`の区間和が x より大きくなるような最小の k を求めます。

#### 計算量

- `add(i, x)`: $\mathrm{O}(\log N)$
- `get(i)`: $\mathrm{O}(\log N)$
- `sum(i)`: $\mathrm{O}(\log N)$
- `sum(l, r)`: $\mathrm{O}(\log N)$
- `lower_bound(x)`: $\mathrm{O}(\log N)$
- `upper_bound(x)`: $\mathrm{O}(\log N)$