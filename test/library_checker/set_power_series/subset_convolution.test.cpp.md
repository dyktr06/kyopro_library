---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/convolution/subset_convolution.hpp
    title: lib/convolution/subset_convolution.hpp
  - icon: ':question:'
    path: lib/math/modint.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"test/library_checker/set_power_series/subset_convolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n#include\
    \ <iostream>\n\n#line 2 \"lib/math/modint.hpp\"\n\n#line 4 \"lib/math/modint.hpp\"\
    \n#include <cassert>\n\n/**\n * @brief ModInt\n * @docs docs/math/modint.md\n\
    \ */\n\ntemplate <long long Modulus>\nstruct ModInt{\n    long long val;\n   \
    \ static constexpr int mod() { return Modulus; }\n    constexpr ModInt(const long\
    \ long _val = 0) noexcept : val(_val) {\n        normalize();\n    }\n    void\
    \ normalize(){\n        val = (val % Modulus + Modulus) % Modulus;\n    }\n  \
    \  inline ModInt &operator+=(const ModInt &rhs) noexcept {\n        if(val +=\
    \ rhs.val, val >= Modulus) val -= Modulus;\n        return *this;\n    }\n   \
    \ inline ModInt &operator-=(const ModInt &rhs) noexcept {\n        if(val -= rhs.val,\
    \ val < 0) val += Modulus;\n        return *this;\n    }\n    inline ModInt &operator*=(const\
    \ ModInt &rhs) noexcept {\n        val = val * rhs.val % Modulus;\n        return\
    \ *this;\n    }\n    inline ModInt &operator/=(const ModInt &rhs) noexcept {\n\
    \        val = val * inv(rhs.val).val % Modulus;\n        return *this;\n    }\n\
    \    inline ModInt &operator++() noexcept {\n        if(++val >= Modulus) val\
    \ -= Modulus;\n        return *this;\n    }\n    inline ModInt operator++(int)\
    \ noexcept {\n        ModInt t = val;\n        if(++val >= Modulus) val -= Modulus;\n\
    \        return t;\n    }\n    inline ModInt &operator--() noexcept {\n      \
    \  if(--val < 0) val += Modulus;\n        return *this;\n    }\n    inline ModInt\
    \ operator--(int) noexcept {\n        ModInt t = val;\n        if(--val < 0) val\
    \ += Modulus;\n        return t;\n    }\n    inline ModInt operator-() const noexcept\
    \ { return (Modulus - val) % Modulus; }\n    inline ModInt inv(void) const { return\
    \ inv(val); }\n    ModInt pow(long long n) const {\n        assert(0 <= n);\n\
    \        ModInt x = *this, r = 1;\n        while(n){\n            if(n & 1) r\
    \ *= x;\n            x *= x;\n            n >>= 1;\n        }\n        return\
    \ r;\n    }\n    ModInt inv(const long long n) const {\n        long long a =\
    \ n, b = Modulus, u = 1, v = 0;\n        while(b){\n            long long t =\
    \ a / b;\n            a -= t * b; std::swap(a, b);\n            u -= t * v; std::swap(u,\
    \ v);\n        }\n        u %= Modulus;\n        if(u < 0) u += Modulus;\n   \
    \     return u;\n    }\n    friend inline ModInt operator+(const ModInt &lhs,\
    \ const ModInt &rhs) noexcept { return ModInt(lhs) += rhs; }\n    friend inline\
    \ ModInt operator-(const ModInt &lhs, const ModInt &rhs) noexcept { return ModInt(lhs)\
    \ -= rhs; }\n    friend inline ModInt operator*(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept { return ModInt(lhs) *= rhs; }\n    friend inline ModInt operator/(const\
    \ ModInt &lhs, const ModInt &rhs) noexcept { return ModInt(lhs) /= rhs; }\n  \
    \  friend inline bool operator==(const ModInt &lhs, const ModInt &rhs) noexcept\
    \ { return lhs.val == rhs.val; }\n    friend inline bool operator!=(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept { return lhs.val != rhs.val; }\n    friend\
    \ inline std::istream &operator>>(std::istream &is, ModInt &x) noexcept {\n  \
    \      is >> x.val;\n        x.normalize();\n        return is;\n    }\n    friend\
    \ inline std::ostream &operator<<(std::ostream &os, const ModInt &x) noexcept\
    \ { return os << x.val; }\n};\n#line 2 \"lib/convolution/subset_convolution.hpp\"\
    \n\n#include <vector>\n#include <array>\n#line 6 \"lib/convolution/subset_convolution.hpp\"\
    \n\ntemplate <typename T, int MAX_RANK>\nstd::vector<std::array<T, MAX_RANK>>\
    \ ranked_zeta_transform(const std::vector<T> &f){\n    int N = f.size();\n   \
    \ std::vector<std::array<T, MAX_RANK>> fr(N);\n    for(int i = 0; i < N; i++)\
    \ fr[i][__builtin_popcount(i)] = f[i];\n    for(int k = 1; k < N; k <<= 1){\n\
    \        for(int i = k; i < N; i = (i + 1) | k){\n            for(int p = 0; p\
    \ < MAX_RANK; p++){\n                fr[i][p] += fr[i ^ k][p];\n            }\n\
    \        }\n    }\n    return fr;\n}\n\ntemplate <typename T, int MAX_RANK>\n\
    std::vector<T> ranked_mobius_transform(std::vector<std::array<T, MAX_RANK>> fr)\
    \ {\n    int N = fr.size();\n    for(int k = 1; k < N; k <<= 1){\n        for(int\
    \ i = k; i < N; i = (i + 1) | k){\n            for(int p = 0; p < MAX_RANK; p++){\n\
    \                fr[i][p] -= fr[i ^ k][p];\n            }\n        }\n    }\n\
    \    std::vector<T> f(N);\n    for(int i = 0; i < N; i++) f[i] = fr[i][__builtin_popcount(i)];\n\
    \    return f;\n}\n\ntemplate <typename T, int MAX_RANK>\nstd::vector<T> subset_convolution(const\
    \ std::vector<T> &f, const std::vector<T> &g){\n    const int N = f.size(), n\
    \ = __builtin_ctz(f.size());\n    assert(f.size() == g.size());\n    assert((N\
    \ & (N - 1)) == 0);\n    assert(MAX_RANK >= n);\n    auto fr = ranked_zeta_transform<T,\
    \ MAX_RANK + 1>(f);\n    auto gr = ranked_zeta_transform<T, MAX_RANK + 1>(g);\n\
    \    for(int i = 0; i < N; i++){\n        for(int p = MAX_RANK; p >= 0; p--){\n\
    \            for(int q = MAX_RANK - p; q > 0; q--){\n                fr[i][p +\
    \ q] += fr[i][p] * gr[i][q];\n            }\n            fr[i][p] *= gr[i][0];\n\
    \        }\n    }\n    return ranked_mobius_transform<T, MAX_RANK + 1>(std::move(fr));\n\
    }\n#line 6 \"test/library_checker/set_power_series/subset_convolution.test.cpp\"\
    \n\nusing namespace std;\n\nconst long long MOD = 998244353;\nusing mint = ModInt<MOD>;\n\
    \nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n   \
    \ int n; cin >> n;\n    vector<mint> a(1 << n), b(1 << n);\n    for(int i = 0;\
    \ i < (1 << n); i++) cin >> a[i];\n    for(int i = 0; i < (1 << n); i++) cin >>\
    \ b[i];\n    auto c = subset_convolution<mint, 20>(a, b);\n    for(int i = 0;\
    \ i < (1 << n); i++) cout << c[i] << \" \\n\"[i == (1 << n) - 1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\
    #include <iostream>\n\n#include \"../../../lib/math/modint.hpp\"\n#include \"\
    ../../../lib/convolution/subset_convolution.hpp\"\n\nusing namespace std;\n\n\
    const long long MOD = 998244353;\nusing mint = ModInt<MOD>;\n\nint main(){\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int n; cin >> n;\n\
    \    vector<mint> a(1 << n), b(1 << n);\n    for(int i = 0; i < (1 << n); i++)\
    \ cin >> a[i];\n    for(int i = 0; i < (1 << n); i++) cin >> b[i];\n    auto c\
    \ = subset_convolution<mint, 20>(a, b);\n    for(int i = 0; i < (1 << n); i++)\
    \ cout << c[i] << \" \\n\"[i == (1 << n) - 1];\n}\n"
  dependsOn:
  - lib/math/modint.hpp
  - lib/convolution/subset_convolution.hpp
  isVerificationFile: true
  path: test/library_checker/set_power_series/subset_convolution.test.cpp
  requiredBy: []
  timestamp: '2025-02-28 02:51:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/set_power_series/subset_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/set_power_series/subset_convolution.test.cpp
- /verify/test/library_checker/set_power_series/subset_convolution.test.cpp.html
title: test/library_checker/set_power_series/subset_convolution.test.cpp
---
