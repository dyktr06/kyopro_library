---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/math/rho.hpp
    title: Pollard's Rho
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/library_checker/math/factorize.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"lib/math/rho.hpp\"\n\n/**\n * @brief Pollard's\
    \ Rho\n * @docs docs/math/rho.md\n */\n\nnamespace Rho{\n    unsigned long long\
    \ mul(unsigned long long a, unsigned long long b, const unsigned long long mod)\
    \ {\n        long long ret = a * b - mod * (unsigned long long)(1.0L / mod * a\
    \ * b);\n        return ret + mod * (ret < 0) - mod * (ret >= (long long) mod);\n\
    \    }\n\n    bool rabin_miller(unsigned long long n){\n        switch(n){\n \
    \       case 0: // fall-through\n        case 1: return false;\n        case 2:\
    \ return true;\n        }\n\n        if(n % 2 == 0) return false;\n        vector<long\
    \ long> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n        unsigned\
    \ long long s = 0, d = n - 1;\n        while(d % 2 == 0){\n            s++;\n\
    \            d >>= 1;\n        }\n\n        auto modpow = [](unsigned long long\
    \ x, unsigned long long e, const unsigned long long mod) -> unsigned long long\
    \ {\n            unsigned long long ret = 1 % mod;\n            x %= mod;\n  \
    \          while(e > 0){\n                if(e & 1) ret = mul(ret, x, mod);\n\
    \                x = mul(x, x, mod);\n                e >>= 1;\n            }\n\
    \            return ret;\n        };\n\n        for(auto a : A){\n           \
    \ if(a % n == 0) return true;\n            unsigned long long t, x = modpow(a,\
    \ d, n);\n            if(x != 1){\n                for(t = 0; t < s; ++t){\n \
    \                   if(x == n - 1) break;\n                    x = mul(x, x, n);\n\
    \                }\n                if(t == s) return false;\n            }\n\
    \        }\n        return true;\n    }\n\n    mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());\n\
    \    unsigned long long FindFactor(unsigned long long n) {\n        if(n == 1\
    \ || rabin_miller(n)) return n;\n        if(n % 2 == 0) return 2;\n        unsigned\
    \ long long c = 1, x = 0, y = 0, t = 0, prod = 2, x0 = 1, q;\n        auto f =\
    \ [&](unsigned long long X) { return mul(X, X, n) + c;};\n\n        while(t++\
    \ % 128 or __gcd(prod, n) == 1) {\n            if(x == y) c = rng() % (n - 1)\
    \ + 1, x = x0, y = f(x);\n            if((q = mul(prod, max(x, y) - min(x, y),\
    \ n))) prod = q;\n            x = f(x), y = f(f(y));\n        }\n        return\
    \ __gcd(prod, n);\n    }\n\n    vector<unsigned long long> factorize(unsigned\
    \ long long x) {\n        if(x == 1) return {};\n        unsigned long long a\
    \ = FindFactor(x), b = x / a;\n        if(a == x) return {a};\n        vector<unsigned\
    \ long long> L = factorize(a), R = factorize(b);\n        L.insert(L.end(), R.begin(),\
    \ R.end());\n        return L;\n    }\n\n    vector<unsigned long long> divisor(unsigned\
    \ long long x){\n        vector<unsigned long long> factor = Rho::factorize(x);\n\
    \        map<unsigned long long, int> countFactor;\n        for(auto x : factor){\n\
    \            if(countFactor.count(x) == 0) countFactor[x] = 0;\n            countFactor[x]++;\n\
    \        }\n        vector<unsigned long long> ret = {1};\n        for(auto [x,\
    \ cnt] : countFactor){\n            int n = ret.size();\n            for(int i\
    \ = 0; i < n; ++i){\n                unsigned long long z = ret[i];\n        \
    \        for(int j = 0; j < cnt; ++j){\n                    z *= x;\n        \
    \            ret.push_back(z);\n                }\n            }\n        }\n\
    \        return ret;\n    }\n}\n#line 6 \"test/library_checker/math/factorize.test.cpp\"\
    \n\nint main(){\n    int q; cin >> q;\n    while(q--){\n        long long a; cin\
    \ >> a;\n        vector<unsigned long long> factor = Rho::factorize(a);\n    \
    \    sort(factor.begin(), factor.end());\n        int n = factor.size();\n   \
    \     cout << n;\n        for(int i = 0; i < n; i++){\n            cout << \"\
    \ \" << factor[i];\n        }\n        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../../lib/math/rho.hpp\"\n\nint main(){\n\
    \    int q; cin >> q;\n    while(q--){\n        long long a; cin >> a;\n     \
    \   vector<unsigned long long> factor = Rho::factorize(a);\n        sort(factor.begin(),\
    \ factor.end());\n        int n = factor.size();\n        cout << n;\n       \
    \ for(int i = 0; i < n; i++){\n            cout << \" \" << factor[i];\n     \
    \   }\n        cout << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/math/rho.hpp
  isVerificationFile: true
  path: test/library_checker/math/factorize.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/math/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/math/factorize.test.cpp
- /verify/test/library_checker/math/factorize.test.cpp.html
title: test/library_checker/math/factorize.test.cpp
---
