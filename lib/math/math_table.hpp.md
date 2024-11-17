---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Math Table
    links: []
  bundledCode: "#line 2 \"lib/math/math_table.hpp\"\n\n/**\n * @brief Math Table\n\
    \ */\n\n#include <vector>\n\nnamespace MathTable{\n    // \u30C8\u30FC\u30B7\u30A7\
    \u30F3\u30C8\u95A2\u6570\n    template <typename T>\n    std::vector<T> totient_table(T\
    \ n){\n        std::vector<T> r(n + 1);\n        for(int i = 0; i <= n; i++){\n\
    \            r[i] = i;\n        }\n        for(int i = 2; i <= n; i++){\n    \
    \        if(r[i] != i) continue;\n            for(int j = i; j <= n; j += i){\n\
    \                r[j] -= r[j] / i;\n            }\n        }\n        return r;\n\
    \    }\n\n    // \u7D20\u56E0\u6570\u306E\u500B\u6570\n    template <typename\
    \ T>\n    std::vector<T> prime_factor_table(T n){\n        std::vector<T> c(n\
    \ + 1);\n        for(int i = 2; i <= n; i++){\n            if(c[i] != 0) continue;\n\
    \            for(int j = i; j <= n; j += i){\n                c[j] += 1;\n   \
    \         }\n        }\n        return c;\n    }\n\n    // \u7D04\u6570\n    template\
    \ <typename T>\n    std::vector<std::vector<T>> divisor_table(T n){\n        std::vector<std::vector<T>>\
    \ div(n + 1);\n        for(int i = 1; i <= n; i++){\n            for(int j = i;\
    \ j <= n; j += i){\n                div[j].push_back(i);\n            }\n    \
    \    }\n        return div;\n    }\n\n    // \u7D2F\u4E57\n    template <typename\
    \ T>\n    std::vector<T> power_table(int n, T p){\n        std::vector<T> power(n\
    \ + 1);\n        power[0] = (T) 1;\n        for(int i = 1; i <= n; i++){\n   \
    \         power[i] = power[i - 1] * p;\n        }\n        return power;\n   \
    \ }\n}\n"
  code: "#pragma once\n\n/**\n * @brief Math Table\n */\n\n#include <vector>\n\nnamespace\
    \ MathTable{\n    // \u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\n    template\
    \ <typename T>\n    std::vector<T> totient_table(T n){\n        std::vector<T>\
    \ r(n + 1);\n        for(int i = 0; i <= n; i++){\n            r[i] = i;\n   \
    \     }\n        for(int i = 2; i <= n; i++){\n            if(r[i] != i) continue;\n\
    \            for(int j = i; j <= n; j += i){\n                r[j] -= r[j] / i;\n\
    \            }\n        }\n        return r;\n    }\n\n    // \u7D20\u56E0\u6570\
    \u306E\u500B\u6570\n    template <typename T>\n    std::vector<T> prime_factor_table(T\
    \ n){\n        std::vector<T> c(n + 1);\n        for(int i = 2; i <= n; i++){\n\
    \            if(c[i] != 0) continue;\n            for(int j = i; j <= n; j +=\
    \ i){\n                c[j] += 1;\n            }\n        }\n        return c;\n\
    \    }\n\n    // \u7D04\u6570\n    template <typename T>\n    std::vector<std::vector<T>>\
    \ divisor_table(T n){\n        std::vector<std::vector<T>> div(n + 1);\n     \
    \   for(int i = 1; i <= n; i++){\n            for(int j = i; j <= n; j += i){\n\
    \                div[j].push_back(i);\n            }\n        }\n        return\
    \ div;\n    }\n\n    // \u7D2F\u4E57\n    template <typename T>\n    std::vector<T>\
    \ power_table(int n, T p){\n        std::vector<T> power(n + 1);\n        power[0]\
    \ = (T) 1;\n        for(int i = 1; i <= n; i++){\n            power[i] = power[i\
    \ - 1] * p;\n        }\n        return power;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/math_table.hpp
  requiredBy: []
  timestamp: '2024-11-18 03:25:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/math_table.hpp
layout: document
redirect_from:
- /library/lib/math/math_table.hpp
- /library/lib/math/math_table.hpp.html
title: Math Table
---
