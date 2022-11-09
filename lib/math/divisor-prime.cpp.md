---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/math/divisor-prime.cpp\"\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n// \u7D04\u6570\u3092\u6607\u9806\u306B\u3057\u3066\u914D\
    \u5217\u306B\u3057\u3066\u51FA\u529B\u3057\u307E\u3059 : O(\u221An)\ntemplate\
    \ <typename T>\nvector<T> getDivisor(T n){\n    T rt = sqrt(n);\n    vector<T>\
    \ res, resB;\n    for(T i = 1; i * i <= n; i++){\n        if(n % i == 0){\n  \
    \          res.push_back(i);\n            T j = n / i;\n            if(j != rt){\n\
    \                resB.push_back(j);\n            }\n        }\n    }\n    for(int\
    \ i = (int) resB.size() - 1; i >= 0; i--){\n        res.push_back(resB[i]);\n\
    \    }\n    return res;\n}\n\n// \u7D20\u6570\u304B\u3069\u3046\u304B\u3092\u5224\
    \u5B9A\u3057\u307E\u3059 : O(\u221An)\ntemplate <typename T>\nbool isPrime(T n){\n\
    \    switch(n) {\n        case 0: // fall-through\n        case 1: return false;\n\
    \        case 2: return true;\n    }\n\n    if(n % 2 == 0) return false;\n\n \
    \   for(T i = 3; i*i <= n; i += 2){\n        if(n % i == 0){\n            return\
    \ false;\n        }\n    }\n    return true;\n}\n\n// N \u306B\u3064\u3044\u3066\
    \u7D20\u56E0\u6570\u5206\u89E3\u3092\u3057\u307E\u3059 : O(\u221AN)\ntemplate\
    \ <typename T>\nvector<pair<T, T>> prime_factor(T n) {\n    vector<pair<T, T>>\
    \ ret;\n    for (T i = 2; i * i <= n; i++) {\n        if (n % i != 0) continue;\n\
    \        T tmp = 0;\n        while (n % i == 0) {\n            tmp++;\n      \
    \      n /= i;\n        }\n        ret.push_back(make_pair(i, tmp));\n    }\n\
    \    if (n != 1) ret.push_back(make_pair(n, 1));\n    return ret;\n}\n\n// N \u306B\
    \u3064\u3044\u3066\u7D20\u56E0\u6570\u5206\u89E3\u3092\u3057\u307E\u3059 : \u69CB\
    \u7BC9: O(NloglogN) \u53D6\u5F97: O(logN)\ntemplate <typename T>\nstruct PrimeFact{\n\
    \    vector<T> spf;\n    PrimeFact(T N){ init(N); }\n    void init(T N){\n   \
    \     spf.assign(N + 1, 0);\n        for(T i = 0; i <= N; i++) spf[i] = i;\n \
    \       for(T i = 2; i * i <= N; i++) {\n            if(spf[i] == i) {\n     \
    \           for(T j = i * i; j <= N; j += i){\n                    if(spf[j] ==\
    \ j){\n                        spf[j] = i;\n                    }\n          \
    \      }\n            }\n        }\n    }\n\n    map<T, T> get(T n){\n       \
    \ map<T, T> m;\n        while(n != 1){\n            if(m.count(spf[n]) == 0){\n\
    \                m[spf[n]] = 1;\n            }else{\n                m[spf[n]]++;\n\
    \            }\n            n /= spf[n];\n        }\n        return m;\n    }\n\
    };\n\n// 2\u304B\u3089N\u307E\u3067\u306E\u7D20\u56E0\u6570\u306E\u500B\u6570\u3092\
    \u8FD4\u3057\u307E\u3059 (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u3075\
    \u308B\u3044) : O(NloglogN)\ntemplate <typename T>\nvector<T> getSieve(T n){\n\
    \    vector<T> c(n+1);\n    for(int i = 2; i <= n; i++){\n        if(c[i] != 0)\
    \ continue;\n        for(int j = i; j <= n; j += i){\n            c[j] += 1;\n\
    \        }\n    }\n    return c;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// \u7D04\u6570\u3092\
    \u6607\u9806\u306B\u3057\u3066\u914D\u5217\u306B\u3057\u3066\u51FA\u529B\u3057\
    \u307E\u3059 : O(\u221An)\ntemplate <typename T>\nvector<T> getDivisor(T n){\n\
    \    T rt = sqrt(n);\n    vector<T> res, resB;\n    for(T i = 1; i * i <= n; i++){\n\
    \        if(n % i == 0){\n            res.push_back(i);\n            T j = n /\
    \ i;\n            if(j != rt){\n                resB.push_back(j);\n         \
    \   }\n        }\n    }\n    for(int i = (int) resB.size() - 1; i >= 0; i--){\n\
    \        res.push_back(resB[i]);\n    }\n    return res;\n}\n\n// \u7D20\u6570\
    \u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3057\u307E\u3059 : O(\u221An)\ntemplate\
    \ <typename T>\nbool isPrime(T n){\n    switch(n) {\n        case 0: // fall-through\n\
    \        case 1: return false;\n        case 2: return true;\n    }\n\n    if(n\
    \ % 2 == 0) return false;\n\n    for(T i = 3; i*i <= n; i += 2){\n        if(n\
    \ % i == 0){\n            return false;\n        }\n    }\n    return true;\n\
    }\n\n// N \u306B\u3064\u3044\u3066\u7D20\u56E0\u6570\u5206\u89E3\u3092\u3057\u307E\
    \u3059 : O(\u221AN)\ntemplate <typename T>\nvector<pair<T, T>> prime_factor(T\
    \ n) {\n    vector<pair<T, T>> ret;\n    for (T i = 2; i * i <= n; i++) {\n  \
    \      if (n % i != 0) continue;\n        T tmp = 0;\n        while (n % i ==\
    \ 0) {\n            tmp++;\n            n /= i;\n        }\n        ret.push_back(make_pair(i,\
    \ tmp));\n    }\n    if (n != 1) ret.push_back(make_pair(n, 1));\n    return ret;\n\
    }\n\n// N \u306B\u3064\u3044\u3066\u7D20\u56E0\u6570\u5206\u89E3\u3092\u3057\u307E\
    \u3059 : \u69CB\u7BC9: O(NloglogN) \u53D6\u5F97: O(logN)\ntemplate <typename T>\n\
    struct PrimeFact{\n    vector<T> spf;\n    PrimeFact(T N){ init(N); }\n    void\
    \ init(T N){\n        spf.assign(N + 1, 0);\n        for(T i = 0; i <= N; i++)\
    \ spf[i] = i;\n        for(T i = 2; i * i <= N; i++) {\n            if(spf[i]\
    \ == i) {\n                for(T j = i * i; j <= N; j += i){\n               \
    \     if(spf[j] == j){\n                        spf[j] = i;\n                \
    \    }\n                }\n            }\n        }\n    }\n\n    map<T, T> get(T\
    \ n){\n        map<T, T> m;\n        while(n != 1){\n            if(m.count(spf[n])\
    \ == 0){\n                m[spf[n]] = 1;\n            }else{\n               \
    \ m[spf[n]]++;\n            }\n            n /= spf[n];\n        }\n        return\
    \ m;\n    }\n};\n\n// 2\u304B\u3089N\u307E\u3067\u306E\u7D20\u56E0\u6570\u306E\
    \u500B\u6570\u3092\u8FD4\u3057\u307E\u3059 (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\
    \u30B9\u306E\u3075\u308B\u3044) : O(NloglogN)\ntemplate <typename T>\nvector<T>\
    \ getSieve(T n){\n    vector<T> c(n+1);\n    for(int i = 2; i <= n; i++){\n  \
    \      if(c[i] != 0) continue;\n        for(int j = i; j <= n; j += i){\n    \
    \        c[j] += 1;\n        }\n    }\n    return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/divisor-prime.cpp
  requiredBy: []
  timestamp: '2022-10-17 23:35:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/divisor-prime.cpp
layout: document
redirect_from:
- /library/lib/math/divisor-prime.cpp
- /library/lib/math/divisor-prime.cpp.html
title: lib/math/divisor-prime.cpp
---
