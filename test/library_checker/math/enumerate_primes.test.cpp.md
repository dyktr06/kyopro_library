---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/prime-sieve.hpp
    title: "Prime Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/library_checker/math/enumerate_primes.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/prime-sieve.hpp\"\
    \n\n/**\n * @brief Prime Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
    \u7BE9)\n * @docs docs/math/prime-sieve.md\n */\n\ntemplate <typename T>\nstruct\
    \ PrimeSieve{\n    int n, half;\n    vector<bool> sieve;\n    vector<T> prime_list;\n\
    \    // sieve[i] ... 2 * i + 1\n\n    PrimeSieve(T _n) : n(_n){\n        init();\n\
    \    }\n\n    void init(){\n        if(n < 2){\n            return;\n        }\n\
    \        half = (n + 1) / 2;\n        sieve.assign(half, true);\n        sieve[0]\
    \ = false;\n        prime_list.emplace_back(2);\n        for(long long i = 1;\
    \ 2 * i + 1 <= n; ++i){\n            if(!sieve[i]) continue;\n            T p\
    \ = 2 * i + 1;\n            prime_list.emplace_back(p);\n            for(long\
    \ long j = 2 * i * (i + 1); j < half; j += p){\n                sieve[j] = false;\n\
    \            }\n        }\n    }\n\n    bool isPrime(T x){\n        if(x == 2)\
    \ return true;\n        if(x % 2 == 0) return false;\n        return sieve[x /\
    \ 2];\n    }\n\n    T getPrimeCount(){\n        return prime_list.size();\n  \
    \  }\n\n    T getKthPrime(int k){\n        return prime_list[k];\n    }\n};\n\
    #line 6 \"test/library_checker/math/enumerate_primes.test.cpp\"\n\nint main(){\n\
    \    int n, a, b; cin >> n >> a >> b;\n    PrimeSieve<int> s(n);\n    int cnt\
    \ = s.getPrimeCount();\n    vector<int> res;\n    for(int i = b; i < cnt; i +=\
    \ a){\n        res.push_back(s.getKthPrime(i));\n    }\n    int cnt2 = res.size();\n\
    \    cout << cnt << \" \" << cnt2 << \"\\n\";\n    for(int i = 0; i < cnt2; i++){\n\
    \        if(i >= 1) cout << \" \";\n        cout << res[i];\n    }\n    cout <<\
    \ \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/prime-sieve.hpp\"\
    \n\nint main(){\n    int n, a, b; cin >> n >> a >> b;\n    PrimeSieve<int> s(n);\n\
    \    int cnt = s.getPrimeCount();\n    vector<int> res;\n    for(int i = b; i\
    \ < cnt; i += a){\n        res.push_back(s.getKthPrime(i));\n    }\n    int cnt2\
    \ = res.size();\n    cout << cnt << \" \" << cnt2 << \"\\n\";\n    for(int i =\
    \ 0; i < cnt2; i++){\n        if(i >= 1) cout << \" \";\n        cout << res[i];\n\
    \    }\n    cout << \"\\n\";\n}"
  dependsOn:
  - lib/math/prime-sieve.hpp
  isVerificationFile: true
  path: test/library_checker/math/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2023-01-25 06:41:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/math/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/math/enumerate_primes.test.cpp
- /verify/test/library_checker/math/enumerate_primes.test.cpp.html
title: test/library_checker/math/enumerate_primes.test.cpp
---
