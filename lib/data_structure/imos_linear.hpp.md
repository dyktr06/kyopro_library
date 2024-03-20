---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_1008.test.cpp
    title: test/yukicoder/yuki_1008.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/imos_linear.hpp\"\n\n/* \n    imos_linear<T>(n)\
    \ : \u30B5\u30A4\u30BAn\u3067\u69CB\u7BC9\n    add(l, r, v, w) : [l, r) \u306B\
    \ wX + v \u3092\u52A0\u7B97\u3057\u307E\u3059\u3002 O(1)\n    build() : \u52A0\
    \u7B97\u3055\u308C\u305F\u914D\u5217\u3092\u69CB\u7BC9\u3057\u307E\u3059\u3002\
    O(n)\n*/\n\ntemplate <typename T>\nstruct imos_linear{\n    int N;\n    vector<T>\
    \ imos1, imos0;\n    imos_linear(int N) : N(N){ init(); }\n\n    void init(){\n\
    \        imos1.resize(N + 1);\n        imos0.resize(N + 1);\n    }\n\n    // [l,\
    \ r) \u306B wX + v \u3092\u52A0\u7B97 \n    // imos[l] += v, imos[l + 1] += v\
    \ + w, ...\n    void add(int l, int r, T v, T w){\n        l = clamp(l, 0, N),\
    \ r = clamp(r, 0, N);\n        imos1[l] += w;\n        imos1[r] -= w;\n      \
    \  imos0[l] += v - w;\n        imos0[r] -= v + w * (r - l - 1);\n    }\n\n   \
    \ void build(){\n        for(int i = 0; i < N; i++){\n            imos1[i + 1]\
    \ += imos1[i];\n            imos0[i] += imos1[i];\n            imos0[i + 1] +=\
    \ imos0[i];\n        }\n    }\n    \n    T & operator [](int i){\n        return\
    \ imos0[i];\n    }\n};\n"
  code: "#pragma once\n\n/* \n    imos_linear<T>(n) : \u30B5\u30A4\u30BAn\u3067\u69CB\
    \u7BC9\n    add(l, r, v, w) : [l, r) \u306B wX + v \u3092\u52A0\u7B97\u3057\u307E\
    \u3059\u3002 O(1)\n    build() : \u52A0\u7B97\u3055\u308C\u305F\u914D\u5217\u3092\
    \u69CB\u7BC9\u3057\u307E\u3059\u3002O(n)\n*/\n\ntemplate <typename T>\nstruct\
    \ imos_linear{\n    int N;\n    vector<T> imos1, imos0;\n    imos_linear(int N)\
    \ : N(N){ init(); }\n\n    void init(){\n        imos1.resize(N + 1);\n      \
    \  imos0.resize(N + 1);\n    }\n\n    // [l, r) \u306B wX + v \u3092\u52A0\u7B97\
    \ \n    // imos[l] += v, imos[l + 1] += v + w, ...\n    void add(int l, int r,\
    \ T v, T w){\n        l = clamp(l, 0, N), r = clamp(r, 0, N);\n        imos1[l]\
    \ += w;\n        imos1[r] -= w;\n        imos0[l] += v - w;\n        imos0[r]\
    \ -= v + w * (r - l - 1);\n    }\n\n    void build(){\n        for(int i = 0;\
    \ i < N; i++){\n            imos1[i + 1] += imos1[i];\n            imos0[i] +=\
    \ imos1[i];\n            imos0[i + 1] += imos0[i];\n        }\n    }\n    \n \
    \   T & operator [](int i){\n        return imos0[i];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/imos_linear.hpp
  requiredBy: []
  timestamp: '2024-03-21 02:13:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_1008.test.cpp
documentation_of: lib/data_structure/imos_linear.hpp
layout: document
redirect_from:
- /library/lib/data_structure/imos_linear.hpp
- /library/lib/data_structure/imos_linear.hpp.html
title: lib/data_structure/imos_linear.hpp
---
