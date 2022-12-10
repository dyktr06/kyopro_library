---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/modcalc.hpp
    title: lib/math/modcalc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/117
    links:
    - https://yukicoder.me/problems/no/117
  bundledCode: "#line 1 \"test/yukicoder/yuki_117.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/117\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/modcalc.hpp\"\
    \n\n// mod. m \u3067\u306E x^n \u3092\u8A08\u7B97\u3057\u307E\u3059 : O(logn)\n\
    template <typename T>\nT modpow(T x, T n, const T &m){\n    T ret = 1 % m;\n \
    \   x %= m;\n    while(n > 0){\n        if(n & 1) (ret *= x) %= m;\n        (x\
    \ *= x) %= m;\n        n >>= 1;\n    }\n    return ret;\n}\n\n// mod. m \u3067\
    \u306E a \u306E\u9006\u5143 a^{-1} \u3092\u8A08\u7B97\u3057\u307E\u3059 : O(logm)\n\
    template <typename T>\nT modinv(T a, T m){\n    T b = m, u = 1, v = 0;\n    while(b){\n\
    \        T t = a / b;\n        a -= t * b; swap(a, b);\n        u -= t * v; swap(u,\
    \ v);\n    }\n    u %= m;\n    if (u < 0) u += m;\n    return u;\n}\n\n// mod.\
    \ m \u3067\u306E\u521D\u9805 a, \u516C\u5DEE d, \u9805\u6570 n \u306E\u7B49\u5DEE\
    \u6570\u5217\u306E\u548C\u3092\u8A08\u7B97\u3057\u307E\u3059 : O(logm)\ntemplate\
    \ <typename T>\nT modarithmeticsum(T a, T d, T n, T m){\n    a %= m, n %= m, d\
    \ %= m;\n    T b = (n - 1) * d % m;\n    return n * (a * 2 + b) % m * modinv((T)\
    \ 2, m) % m;\n}\n\n// mod. m \u3067\u306E\u521D\u9805 a, \u516C\u6BD4 r, \u9805\
    \u6570 n \u306E\u7B49\u6BD4\u6570\u5217\u306E\u548C\u3092\u8A08\u7B97\u3057\u307E\
    \u3059 : O(log(nm))\ntemplate <typename T>\nT modgeometricsum(T a, T r, T n, T\
    \ m){\n    a %= m;\n    if(r == 1){\n        n %= m;\n        return a * n % m;\n\
    \    }\n    return a * (modpow(r, n, m) + m - 1) % m * modinv(r - 1, m) % m;\n\
    }\n\n// mod. m \u3067\u306E\u4E8C\u9805\u4FC2\u6570\u306A\u3069\u3092\u9AD8\u901F\
    \u3067\u8A08\u7B97\u3057\u307E\u3059 : O(N)\nstruct Combination{\n    vector<long\
    \ long> memo, memoinv, inv;\n    const long long mod;\n    Combination(const int\
    \ &N, const long long &m) : memo(N + 1), memoinv(N + 1), inv(N + 1), mod(m){\n\
    \        memo[0] = memo[1] = 1;\n        memoinv[0] = memoinv[1] = 1;\n      \
    \  inv[1] = 1;\n        for(int i = 2; i <= N; ++i){\n            memo[i] = memo[i\
    \ - 1] * i % mod;\n            inv[i] = mod - inv[mod % i] * (m / i) % mod;\n\
    \            memoinv[i] = memoinv[i - 1] * inv[i] % mod;\n        }\n    }\n \
    \   inline long long fact(const long long &n) const {\n        return memo[n];\n\
    \    }\n    inline long long factinv(const long long &n) const {\n        return\
    \ memoinv[n];\n    }\n    inline long long ncr(const long long &n, const long\
    \ long &r) const {\n        if(n < r || r < 0) return 0;\n        return (memo[n]\
    \ * memoinv[r] % mod) * memoinv[n - r] % mod;\n    }\n    inline long long npr(const\
    \ long long &n, const long long &r) const {\n        if(n < r || r < 0) return\
    \ 0;\n        return (memo[n] % mod) * memoinv[n - r] % mod;\n    }\n    inline\
    \ long long nhr(const long long &n, const long long &r) const {\n        if(n\
    \ == 0 && r == 0) return 1;\n        return ncr(n + r - 1, r);\n    }\n};\n#line\
    \ 6 \"test/yukicoder/yuki_117.test.cpp\"\n\nconst long long MOD = 1000000007;\n\
    \nint main(){\n    int t; cin >> t;\n    Combination comb(2000000, MOD);\n\n \
    \   while(t--){\n        char s[10];\n        int n, k;\n        scanf(\"%1s(%d,%d)\"\
    , s, &n, &k);\n\t\tlong long ans = 0;\n\t\tif(s[0] == 'C') ans = comb.ncr(n, k);\n\
    \t\telse if(s[0] == 'P') ans = comb.npr(n, k);\n\t\telse if(s[0] == 'H') ans =\
    \ comb.nhr(n, k);\n\t\tcout << ans << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/117\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../lib/math/modcalc.hpp\"\n\nconst long\
    \ long MOD = 1000000007;\n\nint main(){\n    int t; cin >> t;\n    Combination\
    \ comb(2000000, MOD);\n\n    while(t--){\n        char s[10];\n        int n,\
    \ k;\n        scanf(\"%1s(%d,%d)\", s, &n, &k);\n\t\tlong long ans = 0;\n\t\t\
    if(s[0] == 'C') ans = comb.ncr(n, k);\n\t\telse if(s[0] == 'P') ans = comb.npr(n,\
    \ k);\n\t\telse if(s[0] == 'H') ans = comb.nhr(n, k);\n\t\tcout << ans << endl;\n\
    \    }\n}"
  dependsOn:
  - lib/math/modcalc.hpp
  isVerificationFile: true
  path: test/yukicoder/yuki_117.test.cpp
  requiredBy: []
  timestamp: '2022-12-10 16:41:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/yuki_117.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/yuki_117.test.cpp
- /verify/test/yukicoder/yuki_117.test.cpp.html
title: test/yukicoder/yuki_117.test.cpp
---
