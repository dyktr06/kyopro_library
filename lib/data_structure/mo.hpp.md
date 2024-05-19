---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    links: []
  bundledCode: "#line 2 \"lib/data_structure/mo.hpp\"\n\n// [0 , N) \u4E0A\u306E\u533A\
    \u9593\u306B\u5BFE\u3059\u308B Q \u500B\u306E\u30AF\u30A8\u30EA\u3092\u8A08\u7B97\
    \u3057\u307E\u3059\u3002 : O(N\u221AQ) (\u533A\u9593\u306E\u4F38\u7E2E\u304C O(1)\
    \ \u3067\u884C\u3048\u308B\u5834\u5408)\nstruct Mo{\n    int n;\n    vector<pair<int,\
    \ int>> lr;\n\n    Mo(const int n) : n(n) {}\n\n    /* [l, r) */\n    void add(const\
    \ int l, const int r){\n        lr.emplace_back(l, r);\n    }\n\n    template\
    \ <typename AL, typename AR, typename EL, typename ER, typename O>\n    void build(const\
    \ AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right,\
    \ const O &out){\n        int q = (int) lr.size();\n        int border = max<int>(1,\
    \ 1.0 * n / max<double>(1.0, sqrt(q * 2.0 / 3.0)));\n        vector<int> ord(q);\n\
    \        iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(), ord.end(),\
    \ [&](int a, int b){\n            int ablock = lr[a].first / border, bblock =\
    \ lr[b].first / border;\n            if(ablock != bblock){\n                return\
    \ ablock < bblock;\n            }\n            return (ablock & 1) ? lr[a].second\
    \ > lr[b].second : lr[a].second < lr[b].second;\n        });\n        int l =\
    \ 0, r = 0;\n        for(const auto &k : ord){\n            while(l > lr[k].first)\
    \ add_left(--l);\n            while(r < lr[k].second) add_right(r++);\n      \
    \      while(l < lr[k].first) erase_left(l++);\n            while(r > lr[k].second)\
    \ erase_right(--r);\n            out(k);\n        }\n    }\n\n    template <typename\
    \ A, typename E, typename O>\n    void build(const A &add, const E &erase, const\
    \ O &out){\n        build(add, add, erase, erase, out);\n    }\n};\n"
  code: "#pragma once\n\n// [0 , N) \u4E0A\u306E\u533A\u9593\u306B\u5BFE\u3059\u308B\
    \ Q \u500B\u306E\u30AF\u30A8\u30EA\u3092\u8A08\u7B97\u3057\u307E\u3059\u3002 :\
    \ O(N\u221AQ) (\u533A\u9593\u306E\u4F38\u7E2E\u304C O(1) \u3067\u884C\u3048\u308B\
    \u5834\u5408)\nstruct Mo{\n    int n;\n    vector<pair<int, int>> lr;\n\n    Mo(const\
    \ int n) : n(n) {}\n\n    /* [l, r) */\n    void add(const int l, const int r){\n\
    \        lr.emplace_back(l, r);\n    }\n\n    template <typename AL, typename\
    \ AR, typename EL, typename ER, typename O>\n    void build(const AL &add_left,\
    \ const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out){\n\
    \        int q = (int) lr.size();\n        int border = max<int>(1, 1.0 * n /\
    \ max<double>(1.0, sqrt(q * 2.0 / 3.0)));\n        vector<int> ord(q);\n     \
    \   iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(), ord.end(), [&](int\
    \ a, int b){\n            int ablock = lr[a].first / border, bblock = lr[b].first\
    \ / border;\n            if(ablock != bblock){\n                return ablock\
    \ < bblock;\n            }\n            return (ablock & 1) ? lr[a].second > lr[b].second\
    \ : lr[a].second < lr[b].second;\n        });\n        int l = 0, r = 0;\n   \
    \     for(const auto &k : ord){\n            while(l > lr[k].first) add_left(--l);\n\
    \            while(r < lr[k].second) add_right(r++);\n            while(l < lr[k].first)\
    \ erase_left(l++);\n            while(r > lr[k].second) erase_right(--r);\n  \
    \          out(k);\n        }\n    }\n\n    template <typename A, typename E,\
    \ typename O>\n    void build(const A &add, const E &erase, const O &out){\n \
    \       build(add, add, erase, erase, out);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/mo.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/static_range_mode_query.test.cpp
  - test/library_checker/data_structure/static_range_count_distinct.test.cpp
  - test/library_checker/data_structure/static_range_frequency.test.cpp
  - test/library_checker/data_structure/static_range_inversions_query.test.cpp
  - test/library_checker/data_structure/range_kth_smallest.test.cpp
documentation_of: lib/data_structure/mo.hpp
layout: document
redirect_from:
- /library/lib/data_structure/mo.hpp
- /library/lib/data_structure/mo.hpp.html
title: lib/data_structure/mo.hpp
---
