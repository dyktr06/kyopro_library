---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/convolution/bitwise_and_convolution.hpp
    title: lib/convolution/bitwise_and_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/bitwise_and_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_and_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/convolution/superset_zeta_moebius_transform.hpp\"\n\n\
    template <typename T>\nvoid superset_zeta_transform(vector<T> &f){\n    const\
    \ int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for(int i = 1; i < n;\
    \ i <<= 1){\n        for(int j = 0; j < n; ++j){\n            if((j & i) == 0){\n\
    \                f[j] += f[j | i];\n            }\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid superset_mobius_transform(vector<T> &f){\n    const int n\
    \ = f.size();\n    assert((n & (n - 1)) == 0);\n    for(int i = 1; i < n; i <<=\
    \ 1){\n        for(int j = 0; j < n; ++j){\n            if((j & i) == 0){\n  \
    \              f[j] -= f[j | i];\n            }\n        }\n    }\n}\n"
  code: "#pragma once\n\ntemplate <typename T>\nvoid superset_zeta_transform(vector<T>\
    \ &f){\n    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for(int\
    \ i = 1; i < n; i <<= 1){\n        for(int j = 0; j < n; ++j){\n            if((j\
    \ & i) == 0){\n                f[j] += f[j | i];\n            }\n        }\n \
    \   }\n}\n\ntemplate <typename T>\nvoid superset_mobius_transform(vector<T> &f){\n\
    \    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for(int i =\
    \ 1; i < n; i <<= 1){\n        for(int j = 0; j < n; ++j){\n            if((j\
    \ & i) == 0){\n                f[j] -= f[j | i];\n            }\n        }\n \
    \   }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/convolution/superset_zeta_moebius_transform.hpp
  requiredBy:
  - lib/convolution/bitwise_and_convolution.hpp
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/convolution/bitwise_and_convolution.test.cpp
documentation_of: lib/convolution/superset_zeta_moebius_transform.hpp
layout: document
redirect_from:
- /library/lib/convolution/superset_zeta_moebius_transform.hpp
- /library/lib/convolution/superset_zeta_moebius_transform.hpp.html
title: lib/convolution/superset_zeta_moebius_transform.hpp
---
