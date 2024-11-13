---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/convolution/divisor_zeta_mobius_transform.hpp
    title: Divisor Zeta/Mobius Transform
  - icon: ':heavy_check_mark:'
    path: lib/convolution/gcd_convolution.hpp
    title: GCD Convolution
  - icon: ':question:'
    path: lib/math/modint.hpp
    title: ModInt
  - icon: ':question:'
    path: lib/math/prime_sieve.hpp
    title: "Prime Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "#line 1 \"test/library_checker/convolution/gcd_convolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n#include\
    \ <iostream>\n#include <vector>\n\n#line 2 \"lib/convolution/gcd_convolution.hpp\"\
    \n\n/**\n * @brief GCD Convolution\n * @see https://noshi91.hatenablog.com/entry/2018/12/27/121649\n\
    \ */\n\n#line 9 \"lib/convolution/gcd_convolution.hpp\"\n#include <cassert>\n\n\
    #line 2 \"lib/convolution/divisor_zeta_mobius_transform.hpp\"\n\n/**\n * @brief\
    \ Divisor Zeta/Mobius Transform\n */\n\n#line 8 \"lib/convolution/divisor_zeta_mobius_transform.hpp\"\
    \n\n#line 2 \"lib/math/prime_sieve.hpp\"\n\n/**\n * @brief Prime Sieve (\u30A8\
    \u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)\n * @docs docs/math/prime-sieve.md\n\
    \ */\n\n#line 9 \"lib/math/prime_sieve.hpp\"\n\ntemplate <typename T>\nstruct\
    \ PrimeSieve{\n    int n, half;\n    std::vector<bool> sieve;\n    std::vector<T>\
    \ prime_list;\n    // sieve[i] ... 2 * i + 1\n\n    PrimeSieve(T _n) : n(_n){\n\
    \        init();\n    }\n\n    void init(){\n        if(n < 2){\n            return;\n\
    \        }\n        half = (n + 1) / 2;\n        sieve.assign(half, true);\n \
    \       sieve[0] = false;\n        prime_list.emplace_back(2);\n        for(long\
    \ long i = 1; 2 * i + 1 <= n; ++i){\n            if(!sieve[i]) continue;\n   \
    \         T p = 2 * i + 1;\n            prime_list.emplace_back(p);\n        \
    \    for(long long j = 2 * i * (i + 1); j < half; j += p){\n                sieve[j]\
    \ = false;\n            }\n        }\n    }\n\n    bool isPrime(T x){\n      \
    \  if(x == 2) return true;\n        if(x % 2 == 0) return false;\n        return\
    \ sieve[x / 2];\n    }\n\n    T getPrimeCount(){\n        return prime_list.size();\n\
    \    }\n\n    T getKthPrime(int k){\n        return prime_list[k];\n    }\n};\n\
    #line 10 \"lib/convolution/divisor_zeta_mobius_transform.hpp\"\n\ntemplate <typename\
    \ T>\nvoid divisor_zeta_transform(std::vector<T> &a){\n    int n = a.size() -\
    \ 1;\n    PrimeSieve<int> sieve(n);\n    for(int d = 2; d <= n; d++){\n      \
    \  if(sieve.isPrime(d)){\n            for(int i = 1; i * d <= n; i++){\n     \
    \           a[i * d] += a[i];\n            }\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid divisor_reversed_zeta_transform(std::vector<T> &a){\n   \
    \ int n = a.size() - 1;\n    PrimeSieve<int> sieve(n);\n    for(int d = 2; d <=\
    \ n; d++){\n        if(sieve.isPrime(d)){\n            for(int i = n / d; i >=\
    \ 1; i--){\n                a[i] += a[i * d];\n            }\n        }\n    }\n\
    }\n\ntemplate <typename T>\nvoid divisor_mobius_transform(std::vector<T> &a){\n\
    \    int n = a.size() - 1;\n    PrimeSieve<int> sieve(n);\n    for(int d = 2;\
    \ d <= n; d++){\n        if(sieve.isPrime(d)){\n            for(int i = n / d;\
    \ i >= 1; i--){\n                a[i * d] -= a[i];\n            }\n        }\n\
    \    }\n}\n\ntemplate <typename T>\nvoid divisor_reversed_mobius_transform(std::vector<T>\
    \ &a){\n    int n = a.size() - 1;\n    PrimeSieve<int> sieve(n);\n    for(int\
    \ d = 2; d <= n; d++){\n        if(sieve.isPrime(d)){\n            for(int i =\
    \ 1; i * d <= n; i++){\n                a[i] -= a[i * d];\n            }\n   \
    \     }\n    }\n}\n#line 12 \"lib/convolution/gcd_convolution.hpp\"\n\ntemplate\
    \ <typename T>\nstd::vector<T> gcd_convolution(std::vector<T> f, std::vector<T>\
    \ g){\n    const int n = (int) f.size();\n    assert(f.size() == g.size());\n\
    \    assert(1 <= n);\n    divisor_reversed_zeta_transform(f);\n    divisor_reversed_zeta_transform(g);\n\
    \    for(int i = 1; i < n; ++i){\n        f[i] *= g[i];\n    }\n    divisor_reversed_mobius_transform(f);\n\
    \    return f;\n}\n#line 2 \"lib/math/modint.hpp\"\n\n#line 5 \"lib/math/modint.hpp\"\
    \n\n/**\n * @brief ModInt\n * @docs docs/math/modint.md\n */\n\ntemplate <long\
    \ long Modulus>\nstruct ModInt{\n    long long val;\n    static constexpr int\
    \ mod() { return Modulus; }\n    constexpr ModInt(const long long _val = 0) noexcept\
    \ : val(_val) {\n        normalize();\n    }\n    void normalize(){\n        val\
    \ = (val % Modulus + Modulus) % Modulus;\n    }\n    inline ModInt &operator+=(const\
    \ ModInt &rhs) noexcept {\n        if(val += rhs.val, val >= Modulus) val -= Modulus;\n\
    \        return *this;\n    }\n    inline ModInt &operator-=(const ModInt &rhs)\
    \ noexcept {\n        if(val -= rhs.val, val < 0) val += Modulus;\n        return\
    \ *this;\n    }\n    inline ModInt &operator*=(const ModInt &rhs) noexcept {\n\
    \        val = val * rhs.val % Modulus;\n        return *this;\n    }\n    inline\
    \ ModInt &operator/=(const ModInt &rhs) noexcept {\n        val = val * inv(rhs.val).val\
    \ % Modulus;\n        return *this;\n    }\n    inline ModInt &operator++() noexcept\
    \ {\n        if(++val >= Modulus) val -= Modulus;\n        return *this;\n   \
    \ }\n    inline ModInt operator++(int) noexcept {\n        ModInt t = val;\n \
    \       if(++val >= Modulus) val -= Modulus;\n        return t;\n    }\n    inline\
    \ ModInt &operator--() noexcept {\n        if(--val < 0) val += Modulus;\n   \
    \     return *this;\n    }\n    inline ModInt operator--(int) noexcept {\n   \
    \     ModInt t = val;\n        if(--val < 0) val += Modulus;\n        return t;\n\
    \    }\n    inline ModInt operator-() const noexcept { return (Modulus - val)\
    \ % Modulus; }\n    inline ModInt inv(void) const { return inv(val); }\n    ModInt\
    \ pow(long long n) const {\n        assert(0 <= n);\n        ModInt x = *this,\
    \ r = 1;\n        while(n){\n            if(n & 1) r *= x;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return r;\n    }\n    ModInt inv(const\
    \ long long n) const {\n        long long a = n, b = Modulus, u = 1, v = 0;\n\
    \        while(b){\n            long long t = a / b;\n            a -= t * b;\
    \ std::swap(a, b);\n            u -= t * v; std::swap(u, v);\n        }\n    \
    \    u %= Modulus;\n        if(u < 0) u += Modulus;\n        return u;\n    }\n\
    \    friend inline ModInt operator+(const ModInt &lhs, const ModInt &rhs) noexcept\
    \ { return ModInt(lhs) += rhs; }\n    friend inline ModInt operator-(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept { return ModInt(lhs) -= rhs; }\n    friend\
    \ inline ModInt operator*(const ModInt &lhs, const ModInt &rhs) noexcept { return\
    \ ModInt(lhs) *= rhs; }\n    friend inline ModInt operator/(const ModInt &lhs,\
    \ const ModInt &rhs) noexcept { return ModInt(lhs) /= rhs; }\n    friend inline\
    \ bool operator==(const ModInt &lhs, const ModInt &rhs) noexcept { return lhs.val\
    \ == rhs.val; }\n    friend inline bool operator!=(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept { return lhs.val != rhs.val; }\n    friend inline std::istream\
    \ &operator>>(std::istream &is, ModInt &x) noexcept {\n        is >> x.val;\n\
    \        x.normalize();\n        return is;\n    }\n    friend inline std::ostream\
    \ &operator<<(std::ostream &os, const ModInt &x) noexcept { return os << x.val;\
    \ }\n};\n#line 7 \"test/library_checker/convolution/gcd_convolution.test.cpp\"\
    \n\nusing namespace std;\n\nusing mint = ModInt<998244353>;\n\nint main() {\n\
    \    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int n; cin >>\
    \ n;\n    vector<mint> a(n + 1), b(n + 1);\n    for(int i = 1; i <= n; ++i){\n\
    \        cin >> a[i];\n    }\n    for(int i = 1; i <= n; ++i){\n        cin >>\
    \ b[i];\n    }\n    auto c = gcd_convolution(a, b);\n    for(int i = 1; i <= n;\
    \ ++i){\n        cout << c[i] << \" \\n\"[i == n];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../../../lib/convolution/gcd_convolution.hpp\"\
    \n#include \"../../../lib/math/modint.hpp\"\n\nusing namespace std;\n\nusing mint\
    \ = ModInt<998244353>;\n\nint main() {\n    ios::sync_with_stdio(false);\n   \
    \ cin.tie(nullptr);\n\n    int n; cin >> n;\n    vector<mint> a(n + 1), b(n +\
    \ 1);\n    for(int i = 1; i <= n; ++i){\n        cin >> a[i];\n    }\n    for(int\
    \ i = 1; i <= n; ++i){\n        cin >> b[i];\n    }\n    auto c = gcd_convolution(a,\
    \ b);\n    for(int i = 1; i <= n; ++i){\n        cout << c[i] << \" \\n\"[i ==\
    \ n];\n    }\n}\n"
  dependsOn:
  - lib/convolution/gcd_convolution.hpp
  - lib/convolution/divisor_zeta_mobius_transform.hpp
  - lib/math/prime_sieve.hpp
  - lib/math/modint.hpp
  isVerificationFile: true
  path: test/library_checker/convolution/gcd_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-11-13 13:43:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/convolution/gcd_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/convolution/gcd_convolution.test.cpp
- /verify/test/library_checker/convolution/gcd_convolution.test.cpp.html
title: test/library_checker/convolution/gcd_convolution.test.cpp
---
