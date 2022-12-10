---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/dynamic_binary_indexed_tree_2d.hpp
    title: lib/data_structure/dynamic_binary_indexed_tree_2d.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1_5_d.test.cpp
    title: test/aoj/alds1/alds1_5_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/point_add_rectangle_sum.test.cpp
    title: test/library_checker/data_structure/point_add_rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/dynamic_binary_indexed_tree.hpp\"\n\n\
    /* \n    DynamicBinaryIndexedTree<S, T>(n) : BIT\u3092\u30B5\u30A4\u30BAn\u3067\
    \u69CB\u7BC9\n    add(i, x) : i \u756A\u76EE\u306E\u8981\u7D20\u306B\u52A0\u7B97\
    \u3057\u307E\u3059\u3002 O(log(n)^2)\n    sum(l, r) : [l, r) \u306E\u533A\u9593\
    \u548C\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002O(log(n)^2)\n    \n    (\u4EE5\
    \u4E0B\u306E\u6A5F\u80FD\u3092\u4F7F\u3046\u306B\u306F\u30010 <= i < N \u306B\u304A\
    \u3044\u3066\u3001A_i >= 0 \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308A\u307E\
    \u3059\u3002)\n    lower_bound(x) : A_0 + A_1 + ... + A_y >= x \u3068\u306A\u308B\
    \u6700\u5C0F\u306E y \u3092\u6C42\u3081\u307E\u3059\u3002O(log(n))\n*/\n\ntemplate\
    \ <typename S, typename T>\nstruct DynamicBinaryIndexedTree{\n    S N;\n    unordered_map<S,\
    \ T> data;\n    DynamicBinaryIndexedTree(S _N): N(_N + 1){\n    }\n\n    void\
    \ add(S i, const T &x){\n        for(++i; i < N; i += i & -i) data[i] += x;\n\
    \    }\n\n    T sum(int i){\n        if(i < 0){\n            return 0;\n     \
    \   }\n        T ans = 0;\n        while(i > 0){\n            const auto iter\
    \ = data.find(i);\n            if(iter != data.end()){\n                ans +=\
    \ iter->second;\n            }\n            i -= i & -i;\n        }\n        return\
    \ ans;\n    }\n\n    T sum(int L, int R){\n        return sum(R) - sum(L);\n \
    \   }\n\n    T operator[](S i){\n        return sum(i + 1) - sum(i);\n    }\n\n\
    \    S lower_bound(T x){\n        if(x <= 0){\n            return 0;\n       \
    \ }\n        S v = 0, r = 1;\n        while(r < N) r = r << 1;\n        for(S\
    \ len = r; len > 0; len = len >> 1){\n            if(v + len < N && data[v + len]\
    \ < x){\n                x -= data[v + len];\n                v += len;\n    \
    \        }\n        }\n        return v;\n    }\n};\n"
  code: "#pragma once\n\n/* \n    DynamicBinaryIndexedTree<S, T>(n) : BIT\u3092\u30B5\
    \u30A4\u30BAn\u3067\u69CB\u7BC9\n    add(i, x) : i \u756A\u76EE\u306E\u8981\u7D20\
    \u306B\u52A0\u7B97\u3057\u307E\u3059\u3002 O(log(n)^2)\n    sum(l, r) : [l, r)\
    \ \u306E\u533A\u9593\u548C\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002O(log(n)^2)\n\
    \    \n    (\u4EE5\u4E0B\u306E\u6A5F\u80FD\u3092\u4F7F\u3046\u306B\u306F\u3001\
    0 <= i < N \u306B\u304A\u3044\u3066\u3001A_i >= 0 \u3067\u3042\u308B\u5FC5\u8981\
    \u304C\u3042\u308A\u307E\u3059\u3002)\n    lower_bound(x) : A_0 + A_1 + ... +\
    \ A_y >= x \u3068\u306A\u308B\u6700\u5C0F\u306E y \u3092\u6C42\u3081\u307E\u3059\
    \u3002O(log(n))\n*/\n\ntemplate <typename S, typename T>\nstruct DynamicBinaryIndexedTree{\n\
    \    S N;\n    unordered_map<S, T> data;\n    DynamicBinaryIndexedTree(S _N):\
    \ N(_N + 1){\n    }\n\n    void add(S i, const T &x){\n        for(++i; i < N;\
    \ i += i & -i) data[i] += x;\n    }\n\n    T sum(int i){\n        if(i < 0){\n\
    \            return 0;\n        }\n        T ans = 0;\n        while(i > 0){\n\
    \            const auto iter = data.find(i);\n            if(iter != data.end()){\n\
    \                ans += iter->second;\n            }\n            i -= i & -i;\n\
    \        }\n        return ans;\n    }\n\n    T sum(int L, int R){\n        return\
    \ sum(R) - sum(L);\n    }\n\n    T operator[](S i){\n        return sum(i + 1)\
    \ - sum(i);\n    }\n\n    S lower_bound(T x){\n        if(x <= 0){\n         \
    \   return 0;\n        }\n        S v = 0, r = 1;\n        while(r < N) r = r\
    \ << 1;\n        for(S len = r; len > 0; len = len >> 1){\n            if(v +\
    \ len < N && data[v + len] < x){\n                x -= data[v + len];\n      \
    \          v += len;\n            }\n        }\n        return v;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/dynamic_binary_indexed_tree.hpp
  requiredBy:
  - lib/data_structure/dynamic_binary_indexed_tree_2d.hpp
  timestamp: '2022-11-11 02:51:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/point_add_rectangle_sum.test.cpp
  - test/aoj/alds1/alds1_5_d.test.cpp
documentation_of: lib/data_structure/dynamic_binary_indexed_tree.hpp
layout: document
redirect_from:
- /library/lib/data_structure/dynamic_binary_indexed_tree.hpp
- /library/lib/data_structure/dynamic_binary_indexed_tree.hpp.html
title: lib/data_structure/dynamic_binary_indexed_tree.hpp
---
