---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/convolution_mod_2_64.test.cpp
    title: test/library_checker/convolution/convolution_mod_2_64.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/convolution/karatsuba_algorithm.hpp\"\n\ntemplate <typename\
    \ T>\nvector<T> karatsuba_algorithm(vector<T> &a, vector<T> &b){\n    const int\
    \ n = (int) a.size();\n    const int h = n >> 1;\n    if(n <= 64){\n        vector<T>\
    \ res(2 * n - 1);\n        for(int i = 0; i < n; ++i){\n            for(int j\
    \ = 0; j < n; ++j){\n                res[i + j] += a[i] * b[j];\n            }\n\
    \        }\n        return res;\n    }\n    vector<T> p(h), q(h), r(h), s(h),\
    \ t(h), u(h);\n    for(int i = 0; i < h; ++i){\n        p[i] = a[i + h];\n   \
    \     q[i] = a[i];\n        r[i] = b[i + h];\n        s[i] = b[i];\n        t[i]\
    \ = p[i] + q[i];\n        u[i] = r[i] + s[i];\n    }\n    p = karatsuba_algorithm(p,\
    \ r);\n    q = karatsuba_algorithm(q, s);\n    t = karatsuba_algorithm(t, u);\n\
    \    vector<T> res(2 * n - 1, 0);\n    for(int i = 0; i < n - 1; ++i){\n     \
    \   res[i] += q[i];\n        res[i + h] += t[i] - p[i] - q[i];\n        res[i\
    \ + n] += p[i];\n    }\n    return res;\n}\n"
  code: "#pragma once\n\ntemplate <typename T>\nvector<T> karatsuba_algorithm(vector<T>\
    \ &a, vector<T> &b){\n    const int n = (int) a.size();\n    const int h = n >>\
    \ 1;\n    if(n <= 64){\n        vector<T> res(2 * n - 1);\n        for(int i =\
    \ 0; i < n; ++i){\n            for(int j = 0; j < n; ++j){\n                res[i\
    \ + j] += a[i] * b[j];\n            }\n        }\n        return res;\n    }\n\
    \    vector<T> p(h), q(h), r(h), s(h), t(h), u(h);\n    for(int i = 0; i < h;\
    \ ++i){\n        p[i] = a[i + h];\n        q[i] = a[i];\n        r[i] = b[i +\
    \ h];\n        s[i] = b[i];\n        t[i] = p[i] + q[i];\n        u[i] = r[i]\
    \ + s[i];\n    }\n    p = karatsuba_algorithm(p, r);\n    q = karatsuba_algorithm(q,\
    \ s);\n    t = karatsuba_algorithm(t, u);\n    vector<T> res(2 * n - 1, 0);\n\
    \    for(int i = 0; i < n - 1; ++i){\n        res[i] += q[i];\n        res[i +\
    \ h] += t[i] - p[i] - q[i];\n        res[i + n] += p[i];\n    }\n    return res;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: lib/convolution/karatsuba_algorithm.hpp
  requiredBy: []
  timestamp: '2023-05-01 02:14:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/convolution/convolution_mod_2_64.test.cpp
documentation_of: lib/convolution/karatsuba_algorithm.hpp
layout: document
redirect_from:
- /library/lib/convolution/karatsuba_algorithm.hpp
- /library/lib/convolution/karatsuba_algorithm.hpp.html
title: lib/convolution/karatsuba_algorithm.hpp
---
