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
  bundledCode: "#line 2 \"lib/data_structure/square_division.hpp\"\n\ntemplate <typename\
    \ X>\nstruct SquareDiv{\n    using FX = function<X(X, X)>;\n    int n, bn;\n \
    \   const int block;\n    FX fx;\n    const X ex;\n    int nowt = 0;\n    vector<int>\
    \ t, block_t;\n    vector<X> dat, block_dat, lazy;\n\n    SquareDiv(int n_, int\
    \ block_, const FX &fx_, const X &ex_) : n(n_), block(block_), fx(fx_), ex(ex_){\n\
    \        init();\n        dat.assign(n, ex);\n    }\n\n    SquareDiv(vector<X>\
    \ v, int block_, const FX &fx_, const X &ex_) : block(block_), fx(fx_), ex(ex_),\
    \ dat(v){\n        n = v.size();\n        init();\n        while((int) dat.size()\
    \ < n){\n            dat.emplace_back(ex);\n        }\n        for(int i = 0;\
    \ i < bn; ++i){\n            apply(i);\n        }\n    }\n\n    void init(){\n\
    \        bn = (n + block - 1) / block;\n        n = bn * block;\n        t.assign(n,\
    \ 0);\n        block_t.assign(bn, 0);\n        block_dat.assign(bn, ex);\n   \
    \     lazy.assign(bn, ex);\n    }\n\n    X get(int i) const {\n        if(t[i]\
    \ < block_t[i / block]) return lazy[i / block];\n        else return dat[i];\n\
    \    }\n\n    void apply(int k){\n        X s = ex;\n        for(int i = k * block;\
    \ i < (k + 1) * block; ++i){\n            s = fx(s, get(i));\n        }\n    \
    \    block_dat[k] = s;\n    }\n\n    // [l, r)\n    void update(int l, int r,\
    \ X x){\n        nowt++;\n\n        int lb = (l + block - 1) / block, rb = r /\
    \ block;\n        if(rb - lb < 0){\n            for(int i = l; i < r; ++i){\n\
    \                dat[i] = x;\n                t[i] = nowt;\n            }\n  \
    \          apply(l / block);\n            return;\n        }\n\n        for(int\
    \ i = l; i < lb * block; ++i){\n            dat[i] = x;\n            t[i] = nowt;\n\
    \        }\n        if(lb * block - l) apply(l / block);\n\n        if(rb - lb){\n\
    \            X s = ex;\n            for(int i = 0; i < block; ++i){\n        \
    \        s = fx(s, x);\n            }\n            for(int i = lb; i < rb; ++i){\n\
    \                block_dat[i] = s;\n                lazy[i] = x;\n           \
    \     block_t[i] = nowt;\n            }\n        }\n\n        for(int i = rb *\
    \ block; i < r; ++i){\n            dat[i] = x;\n            t[i] = nowt;\n   \
    \     }\n        if(r - rb * block) apply(rb);\n    }\n\n    // [l, r)\n    X\
    \ query(int l, int r){\n        int lb = (l + block - 1) / block, rb = r / block;\n\
    \        X res = ex;\n        if(rb - lb < 0){\n            for(int i = l; i <\
    \ r; i++){\n                res = fx(res, get(i));\n            }\n          \
    \  return res;\n        }\n        \n        for(int i = l; i < lb * block; ++i){\n\
    \            res = fx(res, get(i));\n        }\n        for(int i = lb; i < rb;\
    \ ++i){\n            res = fx(res, block_dat[i]);\n        }\n        for(int\
    \ i = rb * block; i < r; ++i){\n            res = fx(res, get(i));\n        }\n\
    \        return res;\n    }\n    \n    X operator [](int i) const {\n        return\
    \ get(i);\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename X>\nstruct SquareDiv{\n    using FX =\
    \ function<X(X, X)>;\n    int n, bn;\n    const int block;\n    FX fx;\n    const\
    \ X ex;\n    int nowt = 0;\n    vector<int> t, block_t;\n    vector<X> dat, block_dat,\
    \ lazy;\n\n    SquareDiv(int n_, int block_, const FX &fx_, const X &ex_) : n(n_),\
    \ block(block_), fx(fx_), ex(ex_){\n        init();\n        dat.assign(n, ex);\n\
    \    }\n\n    SquareDiv(vector<X> v, int block_, const FX &fx_, const X &ex_)\
    \ : block(block_), fx(fx_), ex(ex_), dat(v){\n        n = v.size();\n        init();\n\
    \        while((int) dat.size() < n){\n            dat.emplace_back(ex);\n   \
    \     }\n        for(int i = 0; i < bn; ++i){\n            apply(i);\n       \
    \ }\n    }\n\n    void init(){\n        bn = (n + block - 1) / block;\n      \
    \  n = bn * block;\n        t.assign(n, 0);\n        block_t.assign(bn, 0);\n\
    \        block_dat.assign(bn, ex);\n        lazy.assign(bn, ex);\n    }\n\n  \
    \  X get(int i) const {\n        if(t[i] < block_t[i / block]) return lazy[i /\
    \ block];\n        else return dat[i];\n    }\n\n    void apply(int k){\n    \
    \    X s = ex;\n        for(int i = k * block; i < (k + 1) * block; ++i){\n  \
    \          s = fx(s, get(i));\n        }\n        block_dat[k] = s;\n    }\n\n\
    \    // [l, r)\n    void update(int l, int r, X x){\n        nowt++;\n\n     \
    \   int lb = (l + block - 1) / block, rb = r / block;\n        if(rb - lb < 0){\n\
    \            for(int i = l; i < r; ++i){\n                dat[i] = x;\n      \
    \          t[i] = nowt;\n            }\n            apply(l / block);\n      \
    \      return;\n        }\n\n        for(int i = l; i < lb * block; ++i){\n  \
    \          dat[i] = x;\n            t[i] = nowt;\n        }\n        if(lb * block\
    \ - l) apply(l / block);\n\n        if(rb - lb){\n            X s = ex;\n    \
    \        for(int i = 0; i < block; ++i){\n                s = fx(s, x);\n    \
    \        }\n            for(int i = lb; i < rb; ++i){\n                block_dat[i]\
    \ = s;\n                lazy[i] = x;\n                block_t[i] = nowt;\n   \
    \         }\n        }\n\n        for(int i = rb * block; i < r; ++i){\n     \
    \       dat[i] = x;\n            t[i] = nowt;\n        }\n        if(r - rb *\
    \ block) apply(rb);\n    }\n\n    // [l, r)\n    X query(int l, int r){\n    \
    \    int lb = (l + block - 1) / block, rb = r / block;\n        X res = ex;\n\
    \        if(rb - lb < 0){\n            for(int i = l; i < r; i++){\n         \
    \       res = fx(res, get(i));\n            }\n            return res;\n     \
    \   }\n        \n        for(int i = l; i < lb * block; ++i){\n            res\
    \ = fx(res, get(i));\n        }\n        for(int i = lb; i < rb; ++i){\n     \
    \       res = fx(res, block_dat[i]);\n        }\n        for(int i = rb * block;\
    \ i < r; ++i){\n            res = fx(res, get(i));\n        }\n        return\
    \ res;\n    }\n    \n    X operator [](int i) const {\n        return get(i);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/square_division.hpp
  requiredBy: []
  timestamp: '2023-07-28 03:02:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/square_division.hpp
layout: document
redirect_from:
- /library/lib/data_structure/square_division.hpp
- /library/lib/data_structure/square_division.hpp.html
title: lib/data_structure/square_division.hpp
---
