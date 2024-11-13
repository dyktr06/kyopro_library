---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/convolution/set_zeta_mobius_transform.hpp
    title: Set Zeta/Mobius Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/bitwise_and_convolution_1.test.cpp
    title: test/library_checker/convolution/bitwise_and_convolution_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Bitwise OR Convolution
    links: []
  bundledCode: "#line 2 \"lib/convolution/bitwise_or_convolution.hpp\"\n\n/**\n *\
    \ @brief Bitwise OR Convolution\n */\n\n#include <vector>\n#include <cassert>\n\
    \n#line 2 \"lib/convolution/set_zeta_mobius_transform.hpp\"\n\n/**\n * @brief\
    \ Set Zeta/Mobius Transform\n */\n\n#line 9 \"lib/convolution/set_zeta_mobius_transform.hpp\"\
    \n\ntemplate <typename T>\nvoid superset_zeta_transform(std::vector<T> &f){\n\
    \    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for(int i =\
    \ 1; i < n; i <<= 1){\n        for(int j = 0; j < n; ++j){\n            if((j\
    \ & i) == 0){\n                f[j] += f[j | i];\n            }\n        }\n \
    \   }\n}\n\ntemplate <typename T>\nvoid superset_mobius_transform(std::vector<T>\
    \ &f){\n    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for(int\
    \ i = 1; i < n; i <<= 1){\n        for(int j = 0; j < n; ++j){\n            if((j\
    \ & i) == 0){\n                f[j] -= f[j | i];\n            }\n        }\n \
    \   }\n}\n\ntemplate <typename T>\nvoid subset_zeta_transform(std::vector<T> &f){\n\
    \    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for(int i =\
    \ 1; i < n; i <<= 1){\n        for(int j = 0; j < n; ++j){\n            if((j\
    \ & i) == 0){\n                f[j | i] += f[j];\n            }\n        }\n \
    \   }\n}\n\ntemplate <typename T>\nvoid subset_mobius_transform(std::vector<T>\
    \ &f){\n    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for(int\
    \ i = 1; i < n; i <<= 1){\n        for(int j = 0; j < n; ++j){\n            if((j\
    \ & i) == 0){\n                f[j | i] -= f[j];\n            }\n        }\n \
    \   }\n}\n#line 11 \"lib/convolution/bitwise_or_convolution.hpp\"\n\ntemplate\
    \ <typename T>\nstd::vector<T> bitwise_or_convolution(std::vector<T> f, std::vector<T>\
    \ g){\n    const int n = (int) f.size();\n    assert(f.size() == g.size());\n\
    \    assert((n & (n - 1)) == 0);\n    subset_zeta_transform(f);\n    subset_zeta_transform(g);\n\
    \    for(int i = 0; i < n; ++i){\n        f[i] *= g[i];\n    }\n    subset_mobius_transform(f);\n\
    \    return f;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Bitwise OR Convolution\n */\n\n#include <vector>\n\
    #include <cassert>\n\n#include \"../convolution/set_zeta_mobius_transform.hpp\"\
    \n\ntemplate <typename T>\nstd::vector<T> bitwise_or_convolution(std::vector<T>\
    \ f, std::vector<T> g){\n    const int n = (int) f.size();\n    assert(f.size()\
    \ == g.size());\n    assert((n & (n - 1)) == 0);\n    subset_zeta_transform(f);\n\
    \    subset_zeta_transform(g);\n    for(int i = 0; i < n; ++i){\n        f[i]\
    \ *= g[i];\n    }\n    subset_mobius_transform(f);\n    return f;\n}\n"
  dependsOn:
  - lib/convolution/set_zeta_mobius_transform.hpp
  isVerificationFile: false
  path: lib/convolution/bitwise_or_convolution.hpp
  requiredBy: []
  timestamp: '2024-11-13 13:43:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/convolution/bitwise_and_convolution_1.test.cpp
documentation_of: lib/convolution/bitwise_or_convolution.hpp
layout: document
redirect_from:
- /library/lib/convolution/bitwise_or_convolution.hpp
- /library/lib/convolution/bitwise_or_convolution.hpp.html
title: Bitwise OR Convolution
---
