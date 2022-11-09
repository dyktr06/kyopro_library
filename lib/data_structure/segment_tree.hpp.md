---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/static_rmq.test.cpp
    title: test/library_checker/data_structure/static_rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/segment_tree.hpp\"\n\n/* \n    SegTree<X>(n,fx,ex)\
    \ : \u30E2\u30CE\u30A4\u30C9(\u96C6\u5408 X, \u4E8C\u9805\u6F14\u7B97 fx, \u5358\
    \u4F4D\u5143 ex)\u306B\u3064\u3044\u3066\u30B5\u30A4\u30BAn\u3067\u69CB\u7BC9\u3057\
    \u307E\u3059\u3002\n    set(int i, X x), build() : i \u756A\u76EE\u306E\u8981\u7D20\
    \u3092 x \u306B\u30BB\u30C3\u30C8\u3002\u307E\u3068\u3081\u3066\u30BB\u30B0\u6728\
    \u3092\u69CB\u7BC9\u3057\u307E\u3059\u3002O(n)\n    get(i,x) : i \u756A\u76EE\u306E\
    \u8981\u7D20\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002O(1)\n    update(i,x) :\
    \ i \u756A\u76EE\u306E\u8981\u7D20\u3092 x \u306B\u66F4\u65B0\u3057\u307E\u3059\
    \u3002O(log(n))\n    query(a,b) : [a, b) \u306E\u5168\u3066\u306Bfx\u3092\u4F5C\
    \u7528\u3055\u305B\u305F\u5024\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002O(log(n))\n\
    */\ntemplate <typename X>\nstruct SegTree{\n    using FX = function<X(X, X)>;\
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
    \    }\n};\n"
  code: "#pragma once\n\n/* \n    SegTree<X>(n,fx,ex) : \u30E2\u30CE\u30A4\u30C9(\u96C6\
    \u5408 X, \u4E8C\u9805\u6F14\u7B97 fx, \u5358\u4F4D\u5143 ex)\u306B\u3064\u3044\
    \u3066\u30B5\u30A4\u30BAn\u3067\u69CB\u7BC9\u3057\u307E\u3059\u3002\n    set(int\
    \ i, X x), build() : i \u756A\u76EE\u306E\u8981\u7D20\u3092 x \u306B\u30BB\u30C3\
    \u30C8\u3002\u307E\u3068\u3081\u3066\u30BB\u30B0\u6728\u3092\u69CB\u7BC9\u3057\
    \u307E\u3059\u3002O(n)\n    get(i,x) : i \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\
    \u5F97\u3057\u307E\u3059\u3002O(1)\n    update(i,x) : i \u756A\u76EE\u306E\u8981\
    \u7D20\u3092 x \u306B\u66F4\u65B0\u3057\u307E\u3059\u3002O(log(n))\n    query(a,b)\
    \ : [a, b) \u306E\u5168\u3066\u306Bfx\u3092\u4F5C\u7528\u3055\u305B\u305F\u5024\
    \u3092\u53D6\u5F97\u3057\u307E\u3059\u3002O(log(n))\n*/\ntemplate <typename X>\n\
    struct SegTree{\n    using FX = function<X(X, X)>; // X\u2022X -> X \u3068\u306A\
    \u308B\u95A2\u6570\u306E\u578B\n    int n;\n    FX fx;\n    const X ex;\n    vector<X>\
    \ dat;\n\n    SegTree(int n_, FX fx_, X ex_) : n(), fx(fx_), ex(ex_), dat(n_ *\
    \ 4, ex_){\n        int x = 1;\n        while(n_ > x){\n            x *= 2;\n\
    \        }\n        n = x;\n    }\n\n    X get(int i){\n        return dat[i +\
    \ n - 1];\n    }\n    \n    void set(int i, X x){ dat[i + n - 1] = x; }\n\n  \
    \  void build(){\n        for(int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 *\
    \ k + 1], dat[2 * k + 2]);\n    }\n\n    void update(int i, X x){\n        i +=\
    \ n - 1;\n        dat[i] = x;\n        while(i > 0){\n            i = (i - 1)\
    \ / 2;  // parent\n            dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);\n\
    \        }\n    }\n\n    X query(int a, int b){ return query_sub(a, b, 0, 0, n);\
    \ }\n\n    X query_sub(int a, int b, int k, int l, int r){\n        if(r <= a\
    \ || b <= l){\n            return ex;\n        }else if(a <= l && r <= b){\n \
    \           return dat[k];\n        }else{\n            X vl = query_sub(a, b,\
    \ k * 2 + 1, l, (l + r) / 2);\n            X vr = query_sub(a, b, k * 2 + 2, (l\
    \ + r) / 2, r);\n            return fx(vl, vr);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2022-11-10 01:58:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/static_rmq.test.cpp
documentation_of: lib/data_structure/segment_tree.hpp
layout: document
redirect_from:
- /library/lib/data_structure/segment_tree.hpp
- /library/lib/data_structure/segment_tree.hpp.html
title: lib/data_structure/segment_tree.hpp
---
