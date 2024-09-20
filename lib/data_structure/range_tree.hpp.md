---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/point_add_rectangle_sum_rt.test.cpp
    title: test/library_checker/data_structure/point_add_rectangle_sum_rt.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/point_set_range_frequency.test.cpp
    title: test/library_checker/data_structure/point_set_range_frequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/rectangle_add_point_get.test.cpp
    title: test/library_checker/data_structure/rectangle_add_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/rectangle_sum.test.cpp
    title: test/library_checker/data_structure/rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/range_tree.hpp\"\n\ntemplate <typename\
    \ S, typename T>\nstruct RangeTree{\n    struct BinaryIndexedTree{\n        int\
    \ N;\n        vector<T> BIT;\n        BinaryIndexedTree() {}\n\n        void init(int\
    \ size){\n            N = size;\n            BIT.assign(N + 1, 0);\n        }\n\
    \n        T get(int i){\n            return sum(i + 1) - sum(i);\n        }\n\n\
    \        void add(int i, T x){\n            ++i;\n            while(i <= N){\n\
    \                BIT[i] += x;\n                i += i & -i;\n            }\n \
    \       }\n\n        T sum(int i) const {\n            T ans = 0;\n          \
    \  while(i > 0){\n                ans += BIT[i];\n                i -= i & -i;\n\
    \            }\n            return ans;\n        }\n\n        T sum(int L, int\
    \ R) const {\n            return sum(R) - sum(L);\n        }\n    };\n\n    using\
    \ P = pair<S, S>;\n    S N, M;\n    vector<BinaryIndexedTree> bit;\n    vector<vector<S>>\
    \ ys;\n    vector<P> ps;\n\n    RangeTree() {}\n\n    void add_point(S x, S y){\n\
    \        ps.push_back(make_pair(x, y));\n    }\n\n    void build(){\n        sort(ps.begin(),\
    \ ps.end());\n        ps.erase(unique(ps.begin(), ps.end()), ps.end());\n\n  \
    \      N = ps.size();\n        bit.resize(N + 1);\n        ys.resize(N + 1);\n\
    \        for(int i = 0; i <= N; ++i){\n            int j = i + 1;\n          \
    \  while(j <= N){\n                ys[j].push_back(ps[i].second);\n          \
    \      j += j & -j;\n            }\n\n            sort(ys[i].begin(), ys[i].end());\n\
    \            ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());\n \
    \           bit[i].init(ys[i].size());\n        }\n    }\n\n    int id(S x) const\
    \ {\n        auto f = [](const P &a, const P &b){\n            return a.first\
    \ < b.first;\n        };\n        return lower_bound(ps.begin(), ps.end(), make_pair(x,\
    \ S()), f) - ps.begin();\n    }\n\n    int id(int i, S y) const {\n        return\
    \ lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();\n    }\n\n    void\
    \ add(S x, S y, T a){\n        int i = lower_bound(ps.begin(), ps.end(), make_pair(x,\
    \ y)) - ps.begin();\n        assert(ps[i] == make_pair(x, y));\n        ++i;\n\
    \        while(i <= N){\n            bit[i].add(id(i, y), a);\n            i +=\
    \ i & -i;\n        }\n    }\n\n    T sum(S x, S y) const {\n        T ret = T();\n\
    \        int a = id(x);\n        while(a > 0){\n            ret += bit[a].sum(id(a,\
    \ y));\n            a -= a & -a;\n        }\n        return ret;\n    }\n\n  \
    \  // [(xl, yl), (xr, yr))\n    T sum(S xl, S yl, S xr, S yr) const {\n      \
    \  T ret = T();\n        int a = id(xl), b = id(xr);\n        while(a != b) {\n\
    \            if(a < b){\n                ret += bit[b].sum(id(b, yl), id(b, yr));\n\
    \                b -= b & -b;\n            } else{\n                ret -= bit[a].sum(id(a,\
    \ yl), id(a, yr));\n                a -= a & -a;\n            }\n        }\n \
    \       return ret;\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename S, typename T>\nstruct RangeTree{\n  \
    \  struct BinaryIndexedTree{\n        int N;\n        vector<T> BIT;\n       \
    \ BinaryIndexedTree() {}\n\n        void init(int size){\n            N = size;\n\
    \            BIT.assign(N + 1, 0);\n        }\n\n        T get(int i){\n     \
    \       return sum(i + 1) - sum(i);\n        }\n\n        void add(int i, T x){\n\
    \            ++i;\n            while(i <= N){\n                BIT[i] += x;\n\
    \                i += i & -i;\n            }\n        }\n\n        T sum(int i)\
    \ const {\n            T ans = 0;\n            while(i > 0){\n               \
    \ ans += BIT[i];\n                i -= i & -i;\n            }\n            return\
    \ ans;\n        }\n\n        T sum(int L, int R) const {\n            return sum(R)\
    \ - sum(L);\n        }\n    };\n\n    using P = pair<S, S>;\n    S N, M;\n   \
    \ vector<BinaryIndexedTree> bit;\n    vector<vector<S>> ys;\n    vector<P> ps;\n\
    \n    RangeTree() {}\n\n    void add_point(S x, S y){\n        ps.push_back(make_pair(x,\
    \ y));\n    }\n\n    void build(){\n        sort(ps.begin(), ps.end());\n    \
    \    ps.erase(unique(ps.begin(), ps.end()), ps.end());\n\n        N = ps.size();\n\
    \        bit.resize(N + 1);\n        ys.resize(N + 1);\n        for(int i = 0;\
    \ i <= N; ++i){\n            int j = i + 1;\n            while(j <= N){\n    \
    \            ys[j].push_back(ps[i].second);\n                j += j & -j;\n  \
    \          }\n\n            sort(ys[i].begin(), ys[i].end());\n            ys[i].erase(unique(ys[i].begin(),\
    \ ys[i].end()), ys[i].end());\n            bit[i].init(ys[i].size());\n      \
    \  }\n    }\n\n    int id(S x) const {\n        auto f = [](const P &a, const\
    \ P &b){\n            return a.first < b.first;\n        };\n        return lower_bound(ps.begin(),\
    \ ps.end(), make_pair(x, S()), f) - ps.begin();\n    }\n\n    int id(int i, S\
    \ y) const {\n        return lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();\n\
    \    }\n\n    void add(S x, S y, T a){\n        int i = lower_bound(ps.begin(),\
    \ ps.end(), make_pair(x, y)) - ps.begin();\n        assert(ps[i] == make_pair(x,\
    \ y));\n        ++i;\n        while(i <= N){\n            bit[i].add(id(i, y),\
    \ a);\n            i += i & -i;\n        }\n    }\n\n    T sum(S x, S y) const\
    \ {\n        T ret = T();\n        int a = id(x);\n        while(a > 0){\n   \
    \         ret += bit[a].sum(id(a, y));\n            a -= a & -a;\n        }\n\
    \        return ret;\n    }\n\n    // [(xl, yl), (xr, yr))\n    T sum(S xl, S\
    \ yl, S xr, S yr) const {\n        T ret = T();\n        int a = id(xl), b = id(xr);\n\
    \        while(a != b) {\n            if(a < b){\n                ret += bit[b].sum(id(b,\
    \ yl), id(b, yr));\n                b -= b & -b;\n            } else{\n      \
    \          ret -= bit[a].sum(id(a, yl), id(a, yr));\n                a -= a &\
    \ -a;\n            }\n        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/range_tree.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/rectangle_add_point_get.test.cpp
  - test/library_checker/data_structure/rectangle_sum.test.cpp
  - test/library_checker/data_structure/point_set_range_frequency.test.cpp
  - test/library_checker/data_structure/point_add_rectangle_sum_rt.test.cpp
documentation_of: lib/data_structure/range_tree.hpp
layout: document
redirect_from:
- /library/lib/data_structure/range_tree.hpp
- /library/lib/data_structure/range_tree.hpp.html
title: lib/data_structure/range_tree.hpp
---
