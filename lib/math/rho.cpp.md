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
  bundledCode: "#line 1 \"lib/math/rho.cpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n// Rho::rabin_miller(N) : N \u304C\u7D20\u6570\u304B\u3069\u3046\u304B\
    \u3092\u5224\u5B9A\u3057\u307E\u3059\u3002(N <= 2^64 \u306A\u3089\u5FC5\u305A\u6210\
    \u529F\u3057\u307E\u3059) O(log N)\n// Rho::factorial(N) : N \u306B\u3064\u3044\
    \u3066\u7D20\u56E0\u6570\u5206\u89E3\u3092\u3057\u307E\u3059\u3002O(N^(1/4))\n\
    // Rho::divisor(N) : N \u306E\u7D04\u6570\u3092\u5217\u6319\u3057\u307E\u3059\u3002\
    O(N^(1/4) log N)\n\nnamespace Rho{\n    unsigned long long mul(unsigned long long\
    \ a, unsigned long long b, const unsigned long long mod) {\n        long long\
    \ ret = a * b - mod * (unsigned long long)(1.0L / mod * a * b);\n        return\
    \ ret + mod * (ret < 0) - mod * (ret >= (long long) mod);\n    }\n\n    bool rabin_miller(unsigned\
    \ long long n){\n        switch(n){\n            case 0: // fall-through\n   \
    \         case 1: return false;\n            case 2: return true;\n        }\n\
    \n        if(n % 2 == 0) return false;\n        vector<long long> A = {2, 325,\
    \ 9375, 28178, 450775, 9780504, 1795265022};\n        unsigned long long s = 0,\
    \ d = n - 1;\n        while(d % 2 == 0){\n            s++;\n            d >>=\
    \ 1;\n        }\n\n        auto modpow = [](unsigned long long x, unsigned long\
    \ long e, const unsigned long long mod) -> unsigned long long {\n            unsigned\
    \ long long ret = 1 % mod;\n            x %= mod;\n            while(e > 0){\n\
    \                if(e & 1) ret = mul(ret, x, mod);\n                x = mul(x,\
    \ x, mod);\n                e >>= 1;\n            }\n            return ret;\n\
    \        };\n\n        for(auto a : A){\n            if(a % n == 0) return true;\n\
    \            unsigned long long t, x = modpow(a, d, n);\n            if(x != 1){\n\
    \                for(t = 0; t < s; ++t){\n                    if(x == n - 1) break;\n\
    \                    x = mul(x, x, n);\n                }\n                if(t\
    \ == s) return false;\n            }\n        }\n        return true;\n    }\n\
    \n    mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());\n\
    \    unsigned long long FindFactor(unsigned long long n) {\n        if(n == 1\
    \ || rabin_miller(n)) return n;\n        if(n % 2 == 0) return 2;\n        unsigned\
    \ long long c = 1, x = 0, y = 0, t = 0, prod = 2, x0 = 1, q;\n        auto f =\
    \ [&](unsigned long long X) { return mul(X, X, n) + c;};\n\n        while (t++\
    \ % 128 or __gcd(prod, n) == 1) {\n            if(x == y) c = rng() % (n-1) +\
    \ 1, x = x0, y = f(x);\n            if((q = mul(prod, max(x, y) - min(x, y), n)))\
    \ prod = q;\n            x = f(x), y = f(f(y));\n        }\n        return __gcd(prod,\
    \ n);\n    }\n\n    vector<unsigned long long> factorize(unsigned long long x)\
    \ {\n        if(x == 1) return {};\n        unsigned long long a = FindFactor(x),\
    \ b = x / a;\n        if(a == x) return {a};\n        vector<unsigned long long>\
    \ L = factorize(a), R = factorize(b);\n        L.insert(L.end(), R.begin(), R.end());\n\
    \        return L;\n    }\n\n    vector<unsigned long long> divisor(unsigned long\
    \ long x){\n        vector<unsigned long long> factor = Rho::factorize(x);\n \
    \       map<unsigned long long, int> countFactor;\n        for(auto x : factor){\n\
    \            if(countFactor.count(x) == 0) countFactor[x] = 0;\n            countFactor[x]++;\n\
    \        }\n        vector<unsigned long long> ret = {1};\n        for(auto [x,\
    \ cnt] : countFactor){\n            vector<unsigned long long> tmp;\n        \
    \    for(auto y : ret){\n                unsigned long long z = y;\n         \
    \       for(int i = 0; i < cnt + 1; i++){\n                    tmp.push_back(z);\n\
    \                    z *= x;\n                }\n            }\n            ret\
    \ = tmp;\n        }\n        return ret;\n    }\n}\n\n// example (Factorize (Library\
    \ Checker))\nint main(){\n    int q; cin >> q;\n    while(q--){\n        long\
    \ long a; cin >> a;\n        vector<unsigned long long> factor = Rho::factorize(a);\n\
    \        sort(factor.begin(), factor.end());\n        int n = factor.size();\n\
    \        cout << n;\n        for(int i = 0; i < n; i++){\n            cout <<\
    \ \" \" << factor[i];\n        }\n        cout << \"\\n\";\n    }\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// Rho::rabin_miller(N)\
    \ : N \u304C\u7D20\u6570\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3057\u307E\
    \u3059\u3002(N <= 2^64 \u306A\u3089\u5FC5\u305A\u6210\u529F\u3057\u307E\u3059\
    ) O(log N)\n// Rho::factorial(N) : N \u306B\u3064\u3044\u3066\u7D20\u56E0\u6570\
    \u5206\u89E3\u3092\u3057\u307E\u3059\u3002O(N^(1/4))\n// Rho::divisor(N) : N \u306E\
    \u7D04\u6570\u3092\u5217\u6319\u3057\u307E\u3059\u3002O(N^(1/4) log N)\n\nnamespace\
    \ Rho{\n    unsigned long long mul(unsigned long long a, unsigned long long b,\
    \ const unsigned long long mod) {\n        long long ret = a * b - mod * (unsigned\
    \ long long)(1.0L / mod * a * b);\n        return ret + mod * (ret < 0) - mod\
    \ * (ret >= (long long) mod);\n    }\n\n    bool rabin_miller(unsigned long long\
    \ n){\n        switch(n){\n            case 0: // fall-through\n            case\
    \ 1: return false;\n            case 2: return true;\n        }\n\n        if(n\
    \ % 2 == 0) return false;\n        vector<long long> A = {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022};\n        unsigned long long s = 0, d = n - 1;\n\
    \        while(d % 2 == 0){\n            s++;\n            d >>= 1;\n        }\n\
    \n        auto modpow = [](unsigned long long x, unsigned long long e, const unsigned\
    \ long long mod) -> unsigned long long {\n            unsigned long long ret =\
    \ 1 % mod;\n            x %= mod;\n            while(e > 0){\n               \
    \ if(e & 1) ret = mul(ret, x, mod);\n                x = mul(x, x, mod);\n   \
    \             e >>= 1;\n            }\n            return ret;\n        };\n\n\
    \        for(auto a : A){\n            if(a % n == 0) return true;\n         \
    \   unsigned long long t, x = modpow(a, d, n);\n            if(x != 1){\n    \
    \            for(t = 0; t < s; ++t){\n                    if(x == n - 1) break;\n\
    \                    x = mul(x, x, n);\n                }\n                if(t\
    \ == s) return false;\n            }\n        }\n        return true;\n    }\n\
    \n    mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());\n\
    \    unsigned long long FindFactor(unsigned long long n) {\n        if(n == 1\
    \ || rabin_miller(n)) return n;\n        if(n % 2 == 0) return 2;\n        unsigned\
    \ long long c = 1, x = 0, y = 0, t = 0, prod = 2, x0 = 1, q;\n        auto f =\
    \ [&](unsigned long long X) { return mul(X, X, n) + c;};\n\n        while (t++\
    \ % 128 or __gcd(prod, n) == 1) {\n            if(x == y) c = rng() % (n-1) +\
    \ 1, x = x0, y = f(x);\n            if((q = mul(prod, max(x, y) - min(x, y), n)))\
    \ prod = q;\n            x = f(x), y = f(f(y));\n        }\n        return __gcd(prod,\
    \ n);\n    }\n\n    vector<unsigned long long> factorize(unsigned long long x)\
    \ {\n        if(x == 1) return {};\n        unsigned long long a = FindFactor(x),\
    \ b = x / a;\n        if(a == x) return {a};\n        vector<unsigned long long>\
    \ L = factorize(a), R = factorize(b);\n        L.insert(L.end(), R.begin(), R.end());\n\
    \        return L;\n    }\n\n    vector<unsigned long long> divisor(unsigned long\
    \ long x){\n        vector<unsigned long long> factor = Rho::factorize(x);\n \
    \       map<unsigned long long, int> countFactor;\n        for(auto x : factor){\n\
    \            if(countFactor.count(x) == 0) countFactor[x] = 0;\n            countFactor[x]++;\n\
    \        }\n        vector<unsigned long long> ret = {1};\n        for(auto [x,\
    \ cnt] : countFactor){\n            vector<unsigned long long> tmp;\n        \
    \    for(auto y : ret){\n                unsigned long long z = y;\n         \
    \       for(int i = 0; i < cnt + 1; i++){\n                    tmp.push_back(z);\n\
    \                    z *= x;\n                }\n            }\n            ret\
    \ = tmp;\n        }\n        return ret;\n    }\n}\n\n// example (Factorize (Library\
    \ Checker))\nint main(){\n    int q; cin >> q;\n    while(q--){\n        long\
    \ long a; cin >> a;\n        vector<unsigned long long> factor = Rho::factorize(a);\n\
    \        sort(factor.begin(), factor.end());\n        int n = factor.size();\n\
    \        cout << n;\n        for(int i = 0; i < n; i++){\n            cout <<\
    \ \" \" << factor[i];\n        }\n        cout << \"\\n\";\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/rho.cpp
  requiredBy: []
  timestamp: '2022-10-19 03:16:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/rho.cpp
layout: document
redirect_from:
- /library/lib/math/rho.cpp
- /library/lib/math/rho.cpp.html
title: lib/math/rho.cpp
---
