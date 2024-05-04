---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/convolution/superset_zeta_moebius_transform.hpp
    title: lib/convolution/superset_zeta_moebius_transform.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/convolution/bitwise_and_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_and_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/convolution/bitwise_and_convolution.hpp\"\n\n#line 2\
    \ \"lib/convolution/superset_zeta_moebius_transform.hpp\"\n\ntemplate <typename\
    \ T>\nvoid superset_zeta_transform(vector<T> &f){\n    const int n = f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    for(int i = 1; i < n; i <<= 1){\n      \
    \  for(int j = 0; j < n; ++j){\n            if((j & i) == 0){\n              \
    \  f[j] += f[j | i];\n            }\n        }\n    }\n}\n\ntemplate <typename\
    \ T>\nvoid superset_mobius_transform(vector<T> &f){\n    const int n = f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    for(int i = 1; i < n; i <<= 1){\n      \
    \  for(int j = 0; j < n; ++j){\n            if((j & i) == 0){\n              \
    \  f[j] -= f[j | i];\n            }\n        }\n    }\n}\n#line 4 \"lib/convolution/bitwise_and_convolution.hpp\"\
    \n\ntemplate <typename T>\nvector<T> bitwise_and_convolution(vector<T> f, vector<T>\
    \ g){\n    const int n = (int) f.size();\n    assert(f.size() == g.size());\n\
    \    assert((n & (n - 1)) == 0);\n    superset_zeta_transform(f);\n    superset_zeta_transform(g);\n\
    \    for(int i = 0; i < n; ++i){\n        f[i] *= g[i];\n    }\n    superset_mobius_transform(f);\n\
    \    return f;\n}\n"
  code: "#pragma once\n\n#include \"../convolution/superset_zeta_moebius_transform.hpp\"\
    \n\ntemplate <typename T>\nvector<T> bitwise_and_convolution(vector<T> f, vector<T>\
    \ g){\n    const int n = (int) f.size();\n    assert(f.size() == g.size());\n\
    \    assert((n & (n - 1)) == 0);\n    superset_zeta_transform(f);\n    superset_zeta_transform(g);\n\
    \    for(int i = 0; i < n; ++i){\n        f[i] *= g[i];\n    }\n    superset_mobius_transform(f);\n\
    \    return f;\n}\n"
  dependsOn:
  - lib/convolution/superset_zeta_moebius_transform.hpp
  isVerificationFile: false
  path: lib/convolution/bitwise_and_convolution.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/convolution/bitwise_and_convolution.test.cpp
documentation_of: lib/convolution/bitwise_and_convolution.hpp
layout: document
redirect_from:
- /library/lib/convolution/bitwise_and_convolution.hpp
- /library/lib/convolution/bitwise_and_convolution.hpp.html
title: lib/convolution/bitwise_and_convolution.hpp
---
