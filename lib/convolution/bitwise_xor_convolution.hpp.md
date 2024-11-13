---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/convolution/fast_walsh_hadamard_transform.hpp
    title: Fast Walsh-Hadamard Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Bitwise XOR Convolution
    links: []
  bundledCode: "#line 2 \"lib/convolution/bitwise_xor_convolution.hpp\"\n\n/**\n *\
    \ @brief Bitwise XOR Convolution\n */\n\n#include <vector>\n#include <cassert>\n\
    \n#line 2 \"lib/convolution/fast_walsh_hadamard_transform.hpp\"\n\n/**\n * @brief\
    \ Fast Walsh-Hadamard Transform\n */\n\n#line 9 \"lib/convolution/fast_walsh_hadamard_transform.hpp\"\
    \n\ntemplate <typename T>\nvoid fast_walsh_hadamard_transform(std::vector<T> &f,\
    \ bool inv = false){\n    const int n = (int) f.size();\n    assert((n & (n -\
    \ 1)) == 0);\n    for(int i = 1; i < n; i <<= 1){\n        for(int j = 0; j <\
    \ n; j += i << 1){\n            for(int k = 0; k < i; ++k){\n                T\
    \ s = f[j + k], t = f[j + k + i];\n                f[j + k] = s + t;\n       \
    \         f[j + k + i] = s - t;\n            }\n        }\n    }\n    if(inv){\n\
    \        T inv_n = T(1) / n;\n        for(auto &x : f) x *= inv_n;\n    }\n}\n\
    #line 11 \"lib/convolution/bitwise_xor_convolution.hpp\"\n\ntemplate <typename\
    \ T>\nstd::vector<T> bitwise_xor_convolution(std::vector<T> f, std::vector<T>\
    \ g){\n    const int n = (int) f.size();\n    assert(f.size() == g.size());\n\
    \    assert((n & (n - 1)) == 0);\n    fast_walsh_hadamard_transform(f, false);\n\
    \    fast_walsh_hadamard_transform(g, false);\n    for(int i = 0; i < n; ++i){\n\
    \        f[i] *= g[i];\n    }\n    fast_walsh_hadamard_transform(f, true);\n \
    \   return f;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Bitwise XOR Convolution\n */\n\n#include <vector>\n\
    #include <cassert>\n\n#include \"../convolution/fast_walsh_hadamard_transform.hpp\"\
    \n\ntemplate <typename T>\nstd::vector<T> bitwise_xor_convolution(std::vector<T>\
    \ f, std::vector<T> g){\n    const int n = (int) f.size();\n    assert(f.size()\
    \ == g.size());\n    assert((n & (n - 1)) == 0);\n    fast_walsh_hadamard_transform(f,\
    \ false);\n    fast_walsh_hadamard_transform(g, false);\n    for(int i = 0; i\
    \ < n; ++i){\n        f[i] *= g[i];\n    }\n    fast_walsh_hadamard_transform(f,\
    \ true);\n    return f;\n}\n"
  dependsOn:
  - lib/convolution/fast_walsh_hadamard_transform.hpp
  isVerificationFile: false
  path: lib/convolution/bitwise_xor_convolution.hpp
  requiredBy: []
  timestamp: '2024-11-13 13:43:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/convolution/bitwise_xor_convolution.test.cpp
documentation_of: lib/convolution/bitwise_xor_convolution.hpp
layout: document
redirect_from:
- /library/lib/convolution/bitwise_xor_convolution.hpp
- /library/lib/convolution/bitwise_xor_convolution.hpp.html
title: Bitwise XOR Convolution
---
