---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/convolution/bitwise_or_convolution.hpp
    title: Bitwise OR Convolution
  - icon: ':heavy_check_mark:'
    path: lib/convolution/set_zeta_mobius_transform.hpp
    title: Set Zeta/Mobius Transform
  - icon: ':heavy_check_mark:'
    path: lib/math/modint.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/library_checker/convolution/bitwise_and_convolution_1.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\
    #include <iostream>\n#include <vector>\n#include <algorithm>\n\n#line 2 \"lib/convolution/bitwise_or_convolution.hpp\"\
    \n\n/**\n * @brief Bitwise OR Convolution\n */\n\n#line 8 \"lib/convolution/bitwise_or_convolution.hpp\"\
    \n#include <cassert>\n\n#line 2 \"lib/convolution/set_zeta_mobius_transform.hpp\"\
    \n\n/**\n * @brief Set Zeta/Mobius Transform\n */\n\n#line 9 \"lib/convolution/set_zeta_mobius_transform.hpp\"\
    \n\ntemplate <typename T>\nvoid superset_zeta_transform(std::vector<T> &f){\n\
    \    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for(int i =\
    \ 1; i < n; i <<= 1){\n        for(int j = 0; j < n; ++j){\n            if((j\
    \ & i) == 0){\n                f[j] += f[j | i];\n            }\n        }\n \
    \   }\n}\n\ntemplate <typename T>\nvoid superset_mobius_transform(std::vector<T>\
    \ &f){\n    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for(int\
    \ i = 1; i < n; i <<= 1){\n        for(int j = 0; j < n; ++j){\n            if((j\
    \ & i) == 0){\n                f[j] -= f[j | i];\n            }\n        }\n \
    \   }\n}\n\ntemplate <typename T>\nvoid subset_zeta_transform(std::vector<T> &f){\n\
    \    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for(int i =\
    \ 1; i < n; i <<= 1){\n        for(int j = 0; j < n; ++j){\n            if((j\
    \ & i) == 0){\n                f[j | i] += f[j];\n            }\n        }\n \
    \   }\n}\n\ntemplate <typename T>\nvoid subset_mobius_transform(std::vector<T>\
    \ &f){\n    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for(int\
    \ i = 1; i < n; i <<= 1){\n        for(int j = 0; j < n; ++j){\n            if((j\
    \ & i) == 0){\n                f[j | i] -= f[j];\n            }\n        }\n \
    \   }\n}\n#line 11 \"lib/convolution/bitwise_or_convolution.hpp\"\n\ntemplate\
    \ <typename T>\nstd::vector<T> bitwise_or_convolution(std::vector<T> f, std::vector<T>\
    \ g){\n    const int n = (int) f.size();\n    assert(f.size() == g.size());\n\
    \    assert((n & (n - 1)) == 0);\n    subset_zeta_transform(f);\n    subset_zeta_transform(g);\n\
    \    for(int i = 0; i < n; ++i){\n        f[i] *= g[i];\n    }\n    subset_mobius_transform(f);\n\
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
    \ }\n};\n#line 8 \"test/library_checker/convolution/bitwise_and_convolution_1.test.cpp\"\
    \n\nusing namespace std;\n\nusing mint = ModInt<998244353>;\n\nint main(){\n \
    \   int n; cin >> n;\n    int m = 1 << n;\n    vector<mint> a(m), b(m);\n    for(int\
    \ i = 0; i < m; i++){\n        cin >> a[i];\n    }\n    for(int i = 0; i < m;\
    \ i++){\n        cin >> b[i];\n    }\n    reverse(a.begin(), a.end());\n    reverse(b.begin(),\
    \ b.end());\n    vector<mint> c = bitwise_or_convolution(a, b);\n    reverse(c.begin(),\
    \ c.end());\n    for(int i = 0; i < m; i++){\n        cout << c[i] << \" \\n\"\
    [i == m - 1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n#include <iostream>\n#include <vector>\n#include <algorithm>\n\n#include \"\
    ../../../lib/convolution/bitwise_or_convolution.hpp\"\n#include \"../../../lib/math/modint.hpp\"\
    \n\nusing namespace std;\n\nusing mint = ModInt<998244353>;\n\nint main(){\n \
    \   int n; cin >> n;\n    int m = 1 << n;\n    vector<mint> a(m), b(m);\n    for(int\
    \ i = 0; i < m; i++){\n        cin >> a[i];\n    }\n    for(int i = 0; i < m;\
    \ i++){\n        cin >> b[i];\n    }\n    reverse(a.begin(), a.end());\n    reverse(b.begin(),\
    \ b.end());\n    vector<mint> c = bitwise_or_convolution(a, b);\n    reverse(c.begin(),\
    \ c.end());\n    for(int i = 0; i < m; i++){\n        cout << c[i] << \" \\n\"\
    [i == m - 1];\n    }\n}\n"
  dependsOn:
  - lib/convolution/bitwise_or_convolution.hpp
  - lib/convolution/set_zeta_mobius_transform.hpp
  - lib/math/modint.hpp
  isVerificationFile: true
  path: test/library_checker/convolution/bitwise_and_convolution_1.test.cpp
  requiredBy: []
  timestamp: '2024-11-13 13:43:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/convolution/bitwise_and_convolution_1.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/convolution/bitwise_and_convolution_1.test.cpp
- /verify/test/library_checker/convolution/bitwise_and_convolution_1.test.cpp.html
title: test/library_checker/convolution/bitwise_and_convolution_1.test.cpp
---