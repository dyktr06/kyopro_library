---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/prime-factor.md
    document_title: Smallest Prime Factor
    links: []
  bundledCode: "#line 2 \"lib/math/prime-factor.hpp\"\n\n/**\n * @brief Smallest Prime\
    \ Factor\n * @docs docs/math/prime-factor.md\n */\n\ntemplate <typename T>\nstruct\
    \ PrimeFactor{\n    vector<T> spf;\n    PrimeFactor(T N){ init(N); }\n    void\
    \ init(T N){\n        spf.assign(N + 1, 0);\n        for(T i = 0; i <= N; i++)\
    \ spf[i] = i;\n        for(T i = 2; i * i <= N; i++) {\n            if(spf[i]\
    \ == i) {\n                for(T j = i * i; j <= N; j += i){\n               \
    \     if(spf[j] == j){\n                        spf[j] = i;\n                \
    \    }\n                }\n            }\n        }\n    }\n\n    map<T, T> get(T\
    \ n){\n        map<T, T> m;\n        while(n != 1){\n            if(m.count(spf[n])\
    \ == 0){\n                m[spf[n]] = 1;\n            } else{\n              \
    \  m[spf[n]]++;\n            }\n            n /= spf[n];\n        }\n        return\
    \ m;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Smallest Prime Factor\n * @docs docs/math/prime-factor.md\n\
    \ */\n\ntemplate <typename T>\nstruct PrimeFactor{\n    vector<T> spf;\n    PrimeFactor(T\
    \ N){ init(N); }\n    void init(T N){\n        spf.assign(N + 1, 0);\n       \
    \ for(T i = 0; i <= N; i++) spf[i] = i;\n        for(T i = 2; i * i <= N; i++)\
    \ {\n            if(spf[i] == i) {\n                for(T j = i * i; j <= N; j\
    \ += i){\n                    if(spf[j] == j){\n                        spf[j]\
    \ = i;\n                    }\n                }\n            }\n        }\n \
    \   }\n\n    map<T, T> get(T n){\n        map<T, T> m;\n        while(n != 1){\n\
    \            if(m.count(spf[n]) == 0){\n                m[spf[n]] = 1;\n     \
    \       } else{\n                m[spf[n]]++;\n            }\n            n /=\
    \ spf[n];\n        }\n        return m;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/prime-factor.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/prime-factor.hpp
layout: document
redirect_from:
- /library/lib/math/prime-factor.hpp
- /library/lib/math/prime-factor.hpp.html
title: Smallest Prime Factor
---
## Smallest Prime Factor

#### 概要

各数に対する最小の素因数を前計算しておくことによって、素因数分解を高速に行います。

#### 使い方

- `PrimeFactor(N)`: $N$ までの前計算を行います。
- `get(n)`: $n$ について素因数分解を行います。

#### 計算量

- `PrimeFactor(N)`: $\mathrm{O}(N \log \log N)$
- `get(n)`: $\mathrm{O}(\log^2 N)$