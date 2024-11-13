---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/convolution/bitwise_xor_convolution.hpp
    title: Bitwise XOR Convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Fast Walsh-Hadamard Transform
    links: []
  bundledCode: "#line 2 \"lib/convolution/fast_walsh_hadamard_transform.hpp\"\n\n\
    /**\n * @brief Fast Walsh-Hadamard Transform\n */\n\n#include <vector>\n#include\
    \ <cassert>\n\ntemplate <typename T>\nvoid fast_walsh_hadamard_transform(std::vector<T>\
    \ &f, bool inv = false){\n    const int n = (int) f.size();\n    assert((n & (n\
    \ - 1)) == 0);\n    for(int i = 1; i < n; i <<= 1){\n        for(int j = 0; j\
    \ < n; j += i << 1){\n            for(int k = 0; k < i; ++k){\n              \
    \  T s = f[j + k], t = f[j + k + i];\n                f[j + k] = s + t;\n    \
    \            f[j + k + i] = s - t;\n            }\n        }\n    }\n    if(inv){\n\
    \        T inv_n = T(1) / n;\n        for(auto &x : f) x *= inv_n;\n    }\n}\n"
  code: "#pragma once\n\n/**\n * @brief Fast Walsh-Hadamard Transform\n */\n\n#include\
    \ <vector>\n#include <cassert>\n\ntemplate <typename T>\nvoid fast_walsh_hadamard_transform(std::vector<T>\
    \ &f, bool inv = false){\n    const int n = (int) f.size();\n    assert((n & (n\
    \ - 1)) == 0);\n    for(int i = 1; i < n; i <<= 1){\n        for(int j = 0; j\
    \ < n; j += i << 1){\n            for(int k = 0; k < i; ++k){\n              \
    \  T s = f[j + k], t = f[j + k + i];\n                f[j + k] = s + t;\n    \
    \            f[j + k + i] = s - t;\n            }\n        }\n    }\n    if(inv){\n\
    \        T inv_n = T(1) / n;\n        for(auto &x : f) x *= inv_n;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/convolution/fast_walsh_hadamard_transform.hpp
  requiredBy:
  - lib/convolution/bitwise_xor_convolution.hpp
  timestamp: '2024-11-13 13:43:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/convolution/bitwise_xor_convolution.test.cpp
documentation_of: lib/convolution/fast_walsh_hadamard_transform.hpp
layout: document
redirect_from:
- /library/lib/convolution/fast_walsh_hadamard_transform.hpp
- /library/lib/convolution/fast_walsh_hadamard_transform.hpp.html
title: Fast Walsh-Hadamard Transform
---
