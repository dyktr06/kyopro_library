---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/arbitrary_modint.hpp
    title: Arbitrary Modint
  - icon: ':question:'
    path: lib/math/combination.hpp
    title: "Combination (\u4E8C\u9805\u4FC2\u6570)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"test/library_checker/math/binomial_coefficient_prime_mod_1.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/arbitrary_modint.hpp\"\
    \n\n/**\n * @brief Arbitrary Modint\n * @docs docs/math/arbitrary_modint.md\n\
    \ */\n\nstruct ModInt{\n    long long val;\n    ModInt(const long long &_val =\
    \ 0) noexcept : val(_val) {\n        normalize();\n    }\n    static long long\
    \ &Modulus(){\n        static long long mod = 0;\n        return mod;\n    }\n\
    \    static void setMod(const int &mod){\n        Modulus() = mod;\n    }\n  \
    \  void normalize(){\n        val = (val % Modulus() + Modulus()) % Modulus();\n\
    \    }\n    inline ModInt &operator+=(const ModInt &rhs) noexcept {\n        if(val\
    \ += rhs.val, val >= Modulus()) val -= Modulus();\n        return *this;\n   \
    \ }\n    inline ModInt &operator-=(const ModInt &rhs) noexcept {\n        if(val\
    \ -= rhs.val, val < 0) val += Modulus();\n        return *this;\n    }\n    inline\
    \ ModInt &operator*=(const ModInt &rhs) noexcept {\n        val = val * rhs.val\
    \ % Modulus();\n        return *this;\n    }\n    inline ModInt &operator/=(const\
    \ ModInt &rhs) noexcept {\n        val = val * inv(rhs.val).val % Modulus();\n\
    \        return *this;\n    }\n    inline ModInt &operator++() noexcept {\n  \
    \      if(++val >= Modulus()) val -= Modulus();\n        return *this;\n    }\n\
    \    inline ModInt operator++(int) noexcept {\n        ModInt t = val;\n     \
    \   if(++val >= Modulus()) val -= Modulus();\n        return t;\n    }\n    inline\
    \ ModInt &operator--() noexcept {\n        if(--val < 0) val += Modulus();\n \
    \       return *this;\n    }\n    inline ModInt operator--(int) noexcept {\n \
    \       ModInt t = val;\n        if(--val < 0) val += Modulus();\n        return\
    \ t;\n    }\n    inline ModInt operator-() const noexcept { return (Modulus()\
    \ - val) % Modulus(); }\n    inline ModInt inv(void) const { return inv(val);\
    \ }\n    ModInt inv(const long long &n) const {\n        long long a = n, b =\
    \ Modulus(), u = 1, v = 0;\n        while(b){\n            long long t = a / b;\n\
    \            a -= t * b; swap(a, b);\n            u -= t * v; swap(u, v);\n  \
    \      }\n        u %= Modulus();\n        if(u < 0) u += Modulus();\n       \
    \ return u;\n    }\n    friend inline ModInt operator+(const ModInt &lhs, const\
    \ ModInt &rhs) noexcept { return ModInt(lhs) += rhs; }\n    friend inline ModInt\
    \ operator-(const ModInt &lhs, const ModInt &rhs) noexcept { return ModInt(lhs)\
    \ -= rhs; }\n    friend inline ModInt operator*(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept { return ModInt(lhs) *= rhs; }\n    friend inline ModInt operator/(const\
    \ ModInt &lhs, const ModInt &rhs) noexcept { return ModInt(lhs) /= rhs; }\n  \
    \  friend inline bool operator==(const ModInt &lhs, const ModInt &rhs) noexcept\
    \ { return lhs.val == rhs.val; }\n    friend inline bool operator!=(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept { return lhs.val != rhs.val; }\n    friend\
    \ inline istream &operator>>(istream &is, ModInt &x) noexcept {\n        is >>\
    \ x.val;\n        x.normalize();\n        return is;\n    }\n    friend inline\
    \ ostream &operator<<(ostream &os, const ModInt &x) noexcept { return os << x.val;\
    \ }\n};\n#line 2 \"lib/math/combination.hpp\"\n\n/**\n * @brief Combination (\u4E8C\
    \u9805\u4FC2\u6570)\n * @docs docs/math/combination.md\n */\n\nstruct Combination{\n\
    \    vector<long long> memo, memoinv, inv;\n    const long long mod;\n    Combination(const\
    \ int &N, const long long &m) : memo(N + 1), memoinv(N + 1), inv(N + 1), mod(m){\n\
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
    \ == 0 && r == 0) return 1;\n        return ncr(n + r - 1, r);\n    }\n};\n\n\
    struct CombinationByPascal{\n    vector<vector<long long>> memo;\n    const long\
    \ long mod;\n    CombinationByPascal(const int &N, const long long &m) : mod(m){\n\
    \        memo.assign(N + 1, vector<long long>(N + 1));\n        memo[0][0] = 1;\n\
    \        for(int i = 1; i <= N; ++i){\n            memo[i][0] = 1;\n         \
    \   for(int j = 1; j <= N; ++j){\n                memo[i][j] = (memo[i - 1][j\
    \ - 1] + memo[i - 1][j]);\n                if(memo[i][j] >= mod) memo[i][j] -=\
    \ mod;\n            }\n        }\n    }\n    inline long long ncr(const int &n,\
    \ const int &r) const {\n        if(n < r || r < 0) return 0;\n        return\
    \ memo[n][r];\n    }\n};\n#line 7 \"test/library_checker/math/binomial_coefficient_prime_mod_1.test.cpp\"\
    \n\nusing mint = ModInt;\n\nint main(){\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n\n    int t, m; cin >> t >> m;\n    mint::setMod(m);\n \
    \   Combination comb(10000000, m);\n    while(t--){\n        int n, k; cin >>\
    \ n >> k;\n        mint ans = comb.ncr(n, k);\n        cout << ans << \"\\n\"\
    ;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/arbitrary_modint.hpp\"\
    \n#include \"../../../lib/math/combination.hpp\"\n\nusing mint = ModInt;\n\nint\
    \ main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int\
    \ t, m; cin >> t >> m;\n    mint::setMod(m);\n    Combination comb(10000000, m);\n\
    \    while(t--){\n        int n, k; cin >> n >> k;\n        mint ans = comb.ncr(n,\
    \ k);\n        cout << ans << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/math/arbitrary_modint.hpp
  - lib/math/combination.hpp
  isVerificationFile: true
  path: test/library_checker/math/binomial_coefficient_prime_mod_1.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/math/binomial_coefficient_prime_mod_1.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/math/binomial_coefficient_prime_mod_1.test.cpp
- /verify/test/library_checker/math/binomial_coefficient_prime_mod_1.test.cpp.html
title: test/library_checker/math/binomial_coefficient_prime_mod_1.test.cpp
---
