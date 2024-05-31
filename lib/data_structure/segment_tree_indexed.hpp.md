---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/segment_tree_indexed.hpp\"\n\ntemplate\
    \ <typename T>\nstruct SegTree{\n    using FX = function<T(T, T)>; // T\u2022\
    T -> T \u3068\u306A\u308B\u95A2\u6570\u306E\u578B\n    int n;\n    const FX fx;\n\
    \    const T ex;\n    shared_ptr<T[]> dat;\n\n    SegTree(int n_, const FX &fx_,\
    \ const T &ex_) : n(), fx(fx_), ex(ex_){\n        int x = 1;\n        while(n_\
    \ > x){\n            x *= 2;\n        }\n        n = x;\n        dat = make_shared<T[]>(n\
    \ * 2);\n        for(int i = 0; i < n * 2; ++i){\n            dat[i] = ex;\n \
    \       }\n    }\n    SegTree(vector<T> &v, const FX &fx_, const T &ex_) : n(),\
    \ fx(fx_), ex(ex_){\n        int x = 1;\n        while((int) v.size() > x){\n\
    \            x *= 2;\n        }\n        n = x;\n        dat = make_shared<T[]>(n\
    \ * 2);\n        for(int i = 0; i < n; ++i){\n            set(i, (i < (int) v.size()\
    \ ? v[i] : ex));\n        }\n        build();\n    }\n\n    void set(int i, const\
    \ T &x){ dat[i + n] = x; }\n\n    void build(){\n        for(int k = n - 1; k\
    \ >= 1; k--) dat[k] = fx(dat[k * 2], dat[k * 2 + 1]);\n    }\n\n    T get(int\
    \ i) const {\n        return dat[i + n];\n    }\n\n    void update(int i, const\
    \ T &x){\n        i += n;\n        dat[i] = x;\n        while(i > 0){\n      \
    \      i >>= 1;  // parent\n            dat[i] = fx(dat[i * 2], dat[i * 2 + 1]);\n\
    \        }\n    }\n\n    T query(int a, int b){\n        T vl = ex;\n        T\
    \ vr = ex;\n        int l = a + n;\n        int r = b + n;\n        while(l <\
    \ r){\n            if(l & 1) vl = fx(vl, dat[l++]);\n            if(r & 1) vr\
    \ = fx(dat[--r], vr);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return fx(vl, vr);\n    }\n\n    class Index{\n        const shared_ptr<T[]>\
    \ data;\n        const int pos;\n        const FX fx;\n\n    public:\n       \
    \ Index(const shared_ptr<T[]> &data_, const int index, const int size, const FX\
    \ &fx_) : data(data_), pos(index + size), fx(fx_) {}\n        void operator=(const\
    \ T value){\n            data[pos] = value;\n            for(int i = (pos >> 1);\
    \ i > 0; i >>= 1) {\n                data[i] = fx(data[2 * i], data[2 * i + 1]);\n\
    \            }\n        }\n        operator T() const {\n            return data[pos];\n\
    \        }\n    };\n\n    Index operator[](const int index) const {\n        assert((uint)\
    \ index < (uint) n);\n        return Index(dat, index, n, fx);\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct SegTree{\n    using FX = function<T(T,\
    \ T)>; // T\u2022T -> T \u3068\u306A\u308B\u95A2\u6570\u306E\u578B\n    int n;\n\
    \    const FX fx;\n    const T ex;\n    shared_ptr<T[]> dat;\n\n    SegTree(int\
    \ n_, const FX &fx_, const T &ex_) : n(), fx(fx_), ex(ex_){\n        int x = 1;\n\
    \        while(n_ > x){\n            x *= 2;\n        }\n        n = x;\n    \
    \    dat = make_shared<T[]>(n * 2);\n        for(int i = 0; i < n * 2; ++i){\n\
    \            dat[i] = ex;\n        }\n    }\n    SegTree(vector<T> &v, const FX\
    \ &fx_, const T &ex_) : n(), fx(fx_), ex(ex_){\n        int x = 1;\n        while((int)\
    \ v.size() > x){\n            x *= 2;\n        }\n        n = x;\n        dat\
    \ = make_shared<T[]>(n * 2);\n        for(int i = 0; i < n; ++i){\n          \
    \  set(i, (i < (int) v.size() ? v[i] : ex));\n        }\n        build();\n  \
    \  }\n\n    void set(int i, const T &x){ dat[i + n] = x; }\n\n    void build(){\n\
    \        for(int k = n - 1; k >= 1; k--) dat[k] = fx(dat[k * 2], dat[k * 2 + 1]);\n\
    \    }\n\n    T get(int i) const {\n        return dat[i + n];\n    }\n\n    void\
    \ update(int i, const T &x){\n        i += n;\n        dat[i] = x;\n        while(i\
    \ > 0){\n            i >>= 1;  // parent\n            dat[i] = fx(dat[i * 2],\
    \ dat[i * 2 + 1]);\n        }\n    }\n\n    T query(int a, int b){\n        T\
    \ vl = ex;\n        T vr = ex;\n        int l = a + n;\n        int r = b + n;\n\
    \        while(l < r){\n            if(l & 1) vl = fx(vl, dat[l++]);\n       \
    \     if(r & 1) vr = fx(dat[--r], vr);\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n        return fx(vl, vr);\n    }\n\n    class Index{\n     \
    \   const shared_ptr<T[]> data;\n        const int pos;\n        const FX fx;\n\
    \n    public:\n        Index(const shared_ptr<T[]> &data_, const int index, const\
    \ int size, const FX &fx_) : data(data_), pos(index + size), fx(fx_) {}\n    \
    \    void operator=(const T value){\n            data[pos] = value;\n        \
    \    for(int i = (pos >> 1); i > 0; i >>= 1) {\n                data[i] = fx(data[2\
    \ * i], data[2 * i + 1]);\n            }\n        }\n        operator T() const\
    \ {\n            return data[pos];\n        }\n    };\n\n    Index operator[](const\
    \ int index) const {\n        assert((uint) index < (uint) n);\n        return\
    \ Index(dat, index, n, fx);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/segment_tree_indexed.hpp
  requiredBy: []
  timestamp: '2024-05-31 18:23:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/segment_tree_indexed.hpp
layout: document
redirect_from:
- /library/lib/data_structure/segment_tree_indexed.hpp
- /library/lib/data_structure/segment_tree_indexed.hpp.html
title: lib/data_structure/segment_tree_indexed.hpp
---
