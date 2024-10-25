---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/convolution/set_zeta_mobius_transform.hpp
    title: lib/convolution/set_zeta_mobius_transform.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/bitwise_and_convolution_1.test.cpp
    title: test/library_checker/convolution/bitwise_and_convolution_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/convolution/bitwise_or_convolution.hpp\"\n\n#line 2\
    \ \"lib/convolution/set_zeta_mobius_transform.hpp\"\n\ntemplate <typename T>\n\
    void superset_zeta_transform(vector<T> &f){\n    const int n = f.size();\n   \
    \ assert((n & (n - 1)) == 0);\n    for(int i = 1; i < n; i <<= 1){\n        for(int\
    \ j = 0; j < n; ++j){\n            if((j & i) == 0){\n                f[j] +=\
    \ f[j | i];\n            }\n        }\n    }\n}\n\ntemplate <typename T>\nvoid\
    \ superset_mobius_transform(vector<T> &f){\n    const int n = f.size();\n    assert((n\
    \ & (n - 1)) == 0);\n    for(int i = 1; i < n; i <<= 1){\n        for(int j =\
    \ 0; j < n; ++j){\n            if((j & i) == 0){\n                f[j] -= f[j\
    \ | i];\n            }\n        }\n    }\n}\n\ntemplate <typename T>\nvoid subset_zeta_transform(vector<T>\
    \ &f){\n    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for(int\
    \ i = 1; i < n; i <<= 1){\n        for(int j = 0; j < n; ++j){\n            if((j\
    \ & i) == 0){\n                f[j | i] += f[j];\n            }\n        }\n \
    \   }\n}\n\ntemplate <typename T>\nvoid subset_mobius_transform(vector<T> &f){\n\
    \    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for(int i =\
    \ 1; i < n; i <<= 1){\n        for(int j = 0; j < n; ++j){\n            if((j\
    \ & i) == 0){\n                f[j | i] -= f[j];\n            }\n        }\n \
    \   }\n}\n#line 4 \"lib/convolution/bitwise_or_convolution.hpp\"\n\ntemplate <typename\
    \ T>\nvector<T> bitwise_or_convolution(vector<T> f, vector<T> g){\n    const int\
    \ n = (int) f.size();\n    assert(f.size() == g.size());\n    assert((n & (n -\
    \ 1)) == 0);\n    subset_zeta_transform(f);\n    subset_zeta_transform(g);\n \
    \   for(int i = 0; i < n; ++i){\n        f[i] *= g[i];\n    }\n    subset_mobius_transform(f);\n\
    \    return f;\n}\n"
  code: "#pragma once\n\n#include \"../convolution/set_zeta_mobius_transform.hpp\"\
    \n\ntemplate <typename T>\nvector<T> bitwise_or_convolution(vector<T> f, vector<T>\
    \ g){\n    const int n = (int) f.size();\n    assert(f.size() == g.size());\n\
    \    assert((n & (n - 1)) == 0);\n    subset_zeta_transform(f);\n    subset_zeta_transform(g);\n\
    \    for(int i = 0; i < n; ++i){\n        f[i] *= g[i];\n    }\n    subset_mobius_transform(f);\n\
    \    return f;\n}\n"
  dependsOn:
  - lib/convolution/set_zeta_mobius_transform.hpp
  isVerificationFile: false
  path: lib/convolution/bitwise_or_convolution.hpp
  requiredBy: []
  timestamp: '2024-10-25 14:09:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/convolution/bitwise_and_convolution_1.test.cpp
documentation_of: lib/convolution/bitwise_or_convolution.hpp
layout: document
redirect_from:
- /library/lib/convolution/bitwise_or_convolution.hpp
- /library/lib/convolution/bitwise_or_convolution.hpp.html
title: lib/convolution/bitwise_or_convolution.hpp
---
