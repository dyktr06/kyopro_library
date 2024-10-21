---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/convolution/lcm_convolution.test.cpp
    title: test/library_checker/convolution/lcm_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/convolution/lcm_convolution.hpp\"\n\ntemplate <typename\
    \ T>\nvector<T> lcm_convolution(vector<T> f, vector<T> g){\n    const int n =\
    \ (int) f.size();\n    assert(f.size() == g.size());\n    assert(1 <= n);\n  \
    \  divisor_zeta_transform(f);\n    divisor_zeta_transform(g);\n    for(int i =\
    \ 1; i < n; ++i){\n        f[i] *= g[i];\n    }\n    divisor_mobius_transform(f);\n\
    \    return f;\n}\n"
  code: "#pragma once\n\ntemplate <typename T>\nvector<T> lcm_convolution(vector<T>\
    \ f, vector<T> g){\n    const int n = (int) f.size();\n    assert(f.size() ==\
    \ g.size());\n    assert(1 <= n);\n    divisor_zeta_transform(f);\n    divisor_zeta_transform(g);\n\
    \    for(int i = 1; i < n; ++i){\n        f[i] *= g[i];\n    }\n    divisor_mobius_transform(f);\n\
    \    return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/convolution/lcm_convolution.hpp
  requiredBy: []
  timestamp: '2024-10-21 21:43:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/convolution/lcm_convolution.test.cpp
documentation_of: lib/convolution/lcm_convolution.hpp
layout: document
redirect_from:
- /library/lib/convolution/lcm_convolution.hpp
- /library/lib/convolution/lcm_convolution.hpp.html
title: lib/convolution/lcm_convolution.hpp
---
