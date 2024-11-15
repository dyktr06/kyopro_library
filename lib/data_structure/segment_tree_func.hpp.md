---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: lib/data_structure/range_parallel_union_find.hpp
    title: lib/data_structure/range_parallel_union_find.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp
    title: test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp
  - icon: ':x:'
    path: test/library_checker/data_structure/range_parallel_unionfind.test.cpp
    title: test/library_checker/data_structure/range_parallel_unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/segment_tree_func.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n\ntemplate <typename T, T (*op)(T, T), T(*e)()>\nstruct SegTree{\n\
    \    int n;\n    std::vector<T> dat;\n\n    SegTree(int n_){\n        int x =\
    \ 1;\n        while(n_ > x){\n            x *= 2;\n        }\n        n = x;\n\
    \        dat.resize(n * 2);\n        for(int i = 0; i < n * 2; ++i){\n       \
    \     dat[i] = e();\n        }\n    }\n    SegTree(std::vector<T> &v){\n     \
    \   int x = 1;\n        while((int) v.size() > x){\n            x *= 2;\n    \
    \    }\n        n = x;\n        dat.resize(n * 2);\n        for(int i = 0; i <\
    \ n; ++i){\n            set(i, (i < (int) v.size() ? v[i] : e()));\n        }\n\
    \        build();\n    }\n\nprivate:\n    void set(int i, const T &x){ dat[i +\
    \ n] = x; }\n\n    void build(){\n        for(int k = n - 1; k >= 1; k--) dat[k]\
    \ = op(dat[k * 2], dat[k * 2 + 1]);\n    }\n\npublic:\n    T get(int i) const\
    \ {\n        assert(0 <= i && i < n);\n        return dat[i + n];\n    }\n\n \
    \   void update(int i, const T &x){\n        assert(0 <= i && i < n);\n      \
    \  i += n;\n        dat[i] = x;\n        while(i > 0){\n            i >>= 1; \
    \ // parent\n            dat[i] = op(dat[i * 2], dat[i * 2 + 1]);\n        }\n\
    \    }\n\n    T query(int a, int b){\n        assert(0 <= a && a <= b && b <=\
    \ n);\n        T vl = e();\n        T vr = e();\n        int l = a + n;\n    \
    \    int r = b + n;\n        while(l < r){\n            if(l & 1) vl = op(vl,\
    \ dat[l++]);\n            if(r & 1) vr = op(dat[--r], vr);\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n        return op(vl, vr);\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\ntemplate <typename\
    \ T, T (*op)(T, T), T(*e)()>\nstruct SegTree{\n    int n;\n    std::vector<T>\
    \ dat;\n\n    SegTree(int n_){\n        int x = 1;\n        while(n_ > x){\n \
    \           x *= 2;\n        }\n        n = x;\n        dat.resize(n * 2);\n \
    \       for(int i = 0; i < n * 2; ++i){\n            dat[i] = e();\n        }\n\
    \    }\n    SegTree(std::vector<T> &v){\n        int x = 1;\n        while((int)\
    \ v.size() > x){\n            x *= 2;\n        }\n        n = x;\n        dat.resize(n\
    \ * 2);\n        for(int i = 0; i < n; ++i){\n            set(i, (i < (int) v.size()\
    \ ? v[i] : e()));\n        }\n        build();\n    }\n\nprivate:\n    void set(int\
    \ i, const T &x){ dat[i + n] = x; }\n\n    void build(){\n        for(int k =\
    \ n - 1; k >= 1; k--) dat[k] = op(dat[k * 2], dat[k * 2 + 1]);\n    }\n\npublic:\n\
    \    T get(int i) const {\n        assert(0 <= i && i < n);\n        return dat[i\
    \ + n];\n    }\n\n    void update(int i, const T &x){\n        assert(0 <= i &&\
    \ i < n);\n        i += n;\n        dat[i] = x;\n        while(i > 0){\n     \
    \       i >>= 1;  // parent\n            dat[i] = op(dat[i * 2], dat[i * 2 + 1]);\n\
    \        }\n    }\n\n    T query(int a, int b){\n        assert(0 <= a && a <=\
    \ b && b <= n);\n        T vl = e();\n        T vr = e();\n        int l = a +\
    \ n;\n        int r = b + n;\n        while(l < r){\n            if(l & 1) vl\
    \ = op(vl, dat[l++]);\n            if(r & 1) vr = op(dat[--r], vr);\n        \
    \    l >>= 1;\n            r >>= 1;\n        }\n        return op(vl, vr);\n \
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/segment_tree_func.hpp
  requiredBy:
  - lib/data_structure/range_parallel_union_find.hpp
  timestamp: '2024-10-31 17:18:53+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/data_structure/range_parallel_unionfind.test.cpp
  - test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp
documentation_of: lib/data_structure/segment_tree_func.hpp
layout: document
redirect_from:
- /library/lib/data_structure/segment_tree_func.hpp
- /library/lib/data_structure/segment_tree_func.hpp.html
title: lib/data_structure/segment_tree_func.hpp
---
