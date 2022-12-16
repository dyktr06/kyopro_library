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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/binary_indexed_tree.hpp\"\n\n/* \n  \
    \  binary_indexed_tree<T>(n) : BIT\u3092\u30B5\u30A4\u30BAn\u3067\u69CB\u7BC9\n\
    \    get(i)    : i \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3057\u307E\
    \u3059\u3002 O(log(n))\n    add(i, x) : i \u756A\u76EE\u306E\u8981\u7D20\u306B\
    \u52A0\u7B97\u3057\u307E\u3059\u3002 O(log(n))\n    sum(l, r) : [l, r) \u306E\u533A\
    \u9593\u548C\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002O(log(n))\n    \n    (\u4EE5\
    \u4E0B\u306E\u6A5F\u80FD\u3092\u4F7F\u3046\u306B\u306F\u30010 <= i < N \u306B\u304A\
    \u3044\u3066\u3001A_i >= 0 \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308A\u307E\
    \u3059\u3002)\n    lower_bound(x) : A_0 + A_1 + ... + A_y >= x \u3068\u306A\u308B\
    \u6700\u5C0F\u306E y \u3092\u6C42\u3081\u307E\u3059\u3002O(log(n))\n    upper_bound(x)\
    \ : A_0 + A_1 + ... + A_y > x \u3068\u306A\u308B\u6700\u5C0F\u306E y \u3092\u6C42\
    \u3081\u307E\u3059\u3002O(log(n))\n*/\n\ntemplate <typename T>\nstruct BinaryIndexedTree{\n\
    \    int N;\n    vector<T> BIT;\n    BinaryIndexedTree(const int &N): N(N), BIT(N\
    \ + 1, 0){\n    }\n\n    T get(int i){\n        return sum(i + 1) - sum(i);\n\
    \    }\n\n    void add(int i, T x){\n        i++;\n        while(i <= N){\n  \
    \          BIT[i] += x;\n            i += i & -i;\n        }\n    }\n\n    T sum(int\
    \ i) const {\n        T ans = 0;\n        while(i > 0){\n            ans += BIT[i];\n\
    \            i -= i & -i;\n        }\n        return ans;\n    }\n\n    T sum(int\
    \ L, int R) const {\n        return sum(R) - sum(L);\n    }\n\n    int lower_bound(T\
    \ x) const {\n        if(x <= 0){\n            return 0;\n        }else{\n   \
    \         int v = 0, r = 1;\n            while(r < N) r = r << 1;\n          \
    \  for(int len = r; len > 0; len = len >> 1){\n                if(v + len < N\
    \ && BIT[v + len] < x){\n                    x -= BIT[v + len];\n            \
    \        v += len;\n                }\n            }\n            return v;\n\
    \        }\n    }\n\n    int upper_bound(T x) const {\n        if(x < 0){\n  \
    \          return 0;\n        }else{\n            int v = 0, r = 1;\n        \
    \    while(r <= N) r = r << 1;\n            for(int len = r; len > 0; len = len\
    \ >> 1){\n                if(v + len <= N && BIT[v + len] <= x){\n           \
    \         x -= BIT[v + len];\n                    v += len;\n                }\n\
    \            }\n            return v;\n        }\n    }\n};\n"
  code: "#pragma once\n\n/* \n    binary_indexed_tree<T>(n) : BIT\u3092\u30B5\u30A4\
    \u30BAn\u3067\u69CB\u7BC9\n    get(i)    : i \u756A\u76EE\u306E\u8981\u7D20\u3092\
    \u53D6\u5F97\u3057\u307E\u3059\u3002 O(log(n))\n    add(i, x) : i \u756A\u76EE\
    \u306E\u8981\u7D20\u306B\u52A0\u7B97\u3057\u307E\u3059\u3002 O(log(n))\n    sum(l,\
    \ r) : [l, r) \u306E\u533A\u9593\u548C\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\
    O(log(n))\n    \n    (\u4EE5\u4E0B\u306E\u6A5F\u80FD\u3092\u4F7F\u3046\u306B\u306F\
    \u30010 <= i < N \u306B\u304A\u3044\u3066\u3001A_i >= 0 \u3067\u3042\u308B\u5FC5\
    \u8981\u304C\u3042\u308A\u307E\u3059\u3002)\n    lower_bound(x) : A_0 + A_1 +\
    \ ... + A_y >= x \u3068\u306A\u308B\u6700\u5C0F\u306E y \u3092\u6C42\u3081\u307E\
    \u3059\u3002O(log(n))\n    upper_bound(x) : A_0 + A_1 + ... + A_y > x \u3068\u306A\
    \u308B\u6700\u5C0F\u306E y \u3092\u6C42\u3081\u307E\u3059\u3002O(log(n))\n*/\n\
    \ntemplate <typename T>\nstruct BinaryIndexedTree{\n    int N;\n    vector<T>\
    \ BIT;\n    BinaryIndexedTree(const int &N): N(N), BIT(N + 1, 0){\n    }\n\n \
    \   T get(int i){\n        return sum(i + 1) - sum(i);\n    }\n\n    void add(int\
    \ i, T x){\n        i++;\n        while(i <= N){\n            BIT[i] += x;\n \
    \           i += i & -i;\n        }\n    }\n\n    T sum(int i) const {\n     \
    \   T ans = 0;\n        while(i > 0){\n            ans += BIT[i];\n          \
    \  i -= i & -i;\n        }\n        return ans;\n    }\n\n    T sum(int L, int\
    \ R) const {\n        return sum(R) - sum(L);\n    }\n\n    int lower_bound(T\
    \ x) const {\n        if(x <= 0){\n            return 0;\n        }else{\n   \
    \         int v = 0, r = 1;\n            while(r < N) r = r << 1;\n          \
    \  for(int len = r; len > 0; len = len >> 1){\n                if(v + len < N\
    \ && BIT[v + len] < x){\n                    x -= BIT[v + len];\n            \
    \        v += len;\n                }\n            }\n            return v;\n\
    \        }\n    }\n\n    int upper_bound(T x) const {\n        if(x < 0){\n  \
    \          return 0;\n        }else{\n            int v = 0, r = 1;\n        \
    \    while(r <= N) r = r << 1;\n            for(int len = r; len > 0; len = len\
    \ >> 1){\n                if(v + len <= N && BIT[v + len] <= x){\n           \
    \         x -= BIT[v + len];\n                    v += len;\n                }\n\
    \            }\n            return v;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/binary_indexed_tree.hpp
  requiredBy: []
  timestamp: '2022-11-10 01:58:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/point_add_range_sum.test.cpp
  - test/library_checker/data_structure/static_range_inversions_query.test.cpp
  - test/library_checker/data_structure/range_kth_smallest.test.cpp
documentation_of: lib/data_structure/binary_indexed_tree.hpp
layout: document
redirect_from:
- /library/lib/data_structure/binary_indexed_tree.hpp
- /library/lib/data_structure/binary_indexed_tree.hpp.html
title: lib/data_structure/binary_indexed_tree.hpp
---
