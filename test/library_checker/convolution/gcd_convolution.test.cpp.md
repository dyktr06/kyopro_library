---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/convolution/gcd_convolution.hpp
    title: lib/convolution/gcd_convolution.hpp
  - icon: ':question:'
    path: lib/math/modint.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "#line 1 \"test/library_checker/convolution/gcd_convolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/convolution/gcd_convolution.hpp\"\
    \n\n// \u53C2\u8003: https://noshi91.hatenablog.com/entry/2018/12/27/121649\n\
    template <typename T>\nvector<T> gcd_convolution(vector<T> f, vector<T> g){\n\
    \    const int n = (int) f.size();\n    assert(f.size() == g.size());\n    assert(1\
    \ <= n);\n    divisor_reversed_zeta_transform(f);\n    divisor_reversed_zeta_transform(g);\n\
    \    for(int i = 1; i < n; ++i){\n        f[i] *= g[i];\n    }\n    divisor_reversed_mobius_transform(f);\n\
    \    return f;\n}\n#line 2 \"lib/math/modint.hpp\"\n\n/**\n * @brief ModInt\n\
    \ * @docs docs/math/modint.md\n */\n\ntemplate <long long Modulus>\nstruct ModInt{\n\
    \    long long val;\n    static constexpr int mod() { return Modulus; }\n    constexpr\
    \ ModInt(const long long _val = 0) noexcept : val(_val) {\n        normalize();\n\
    \    }\n    void normalize(){\n        val = (val % Modulus + Modulus) % Modulus;\n\
    \    }\n    inline ModInt &operator+=(const ModInt &rhs) noexcept {\n        if(val\
    \ += rhs.val, val >= Modulus) val -= Modulus;\n        return *this;\n    }\n\
    \    inline ModInt &operator-=(const ModInt &rhs) noexcept {\n        if(val -=\
    \ rhs.val, val < 0) val += Modulus;\n        return *this;\n    }\n    inline\
    \ ModInt &operator*=(const ModInt &rhs) noexcept {\n        val = val * rhs.val\
    \ % Modulus;\n        return *this;\n    }\n    inline ModInt &operator/=(const\
    \ ModInt &rhs) noexcept {\n        val = val * inv(rhs.val).val % Modulus;\n \
    \       return *this;\n    }\n    inline ModInt &operator++() noexcept {\n   \
    \     if(++val >= Modulus) val -= Modulus;\n        return *this;\n    }\n   \
    \ inline ModInt operator++(int) noexcept {\n        ModInt t = val;\n        if(++val\
    \ >= Modulus) val -= Modulus;\n        return t;\n    }\n    inline ModInt &operator--()\
    \ noexcept {\n        if(--val < 0) val += Modulus;\n        return *this;\n \
    \   }\n    inline ModInt operator--(int) noexcept {\n        ModInt t = val;\n\
    \        if(--val < 0) val += Modulus;\n        return t;\n    }\n    inline ModInt\
    \ operator-() const noexcept { return (Modulus - val) % Modulus; }\n    inline\
    \ ModInt inv(void) const { return inv(val); }\n    ModInt pow(long long n){\n\
    \        assert(0 <= n);\n        ModInt x = *this, r = 1;\n        while(n){\n\
    \            if(n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n  \
    \      }\n        return r;\n    }\n    ModInt inv(const long long n) const {\n\
    \        long long a = n, b = Modulus, u = 1, v = 0;\n        while(b){\n    \
    \        long long t = a / b;\n            a -= t * b; swap(a, b);\n         \
    \   u -= t * v; swap(u, v);\n        }\n        u %= Modulus;\n        if(u <\
    \ 0) u += Modulus;\n        return u;\n    }\n    friend inline ModInt operator+(const\
    \ ModInt &lhs, const ModInt &rhs) noexcept { return ModInt(lhs) += rhs; }\n  \
    \  friend inline ModInt operator-(const ModInt &lhs, const ModInt &rhs) noexcept\
    \ { return ModInt(lhs) -= rhs; }\n    friend inline ModInt operator*(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept { return ModInt(lhs) *= rhs; }\n    friend\
    \ inline ModInt operator/(const ModInt &lhs, const ModInt &rhs) noexcept { return\
    \ ModInt(lhs) /= rhs; }\n    friend inline bool operator==(const ModInt &lhs,\
    \ const ModInt &rhs) noexcept { return lhs.val == rhs.val; }\n    friend inline\
    \ bool operator!=(const ModInt &lhs, const ModInt &rhs) noexcept { return lhs.val\
    \ != rhs.val; }\n    friend inline istream &operator>>(istream &is, ModInt &x)\
    \ noexcept {\n        is >> x.val;\n        x.normalize();\n        return is;\n\
    \    }\n    friend inline ostream &operator<<(ostream &os, const ModInt &x) noexcept\
    \ { return os << x.val; }\n};\n#line 7 \"test/library_checker/convolution/gcd_convolution.test.cpp\"\
    \n\nusing mint = ModInt<998244353>;\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int n; cin >> n;\n    vector<mint> a(n + 1), b(n\
    \ + 1);\n    for(int i = 1; i <= n; ++i){\n        cin >> a[i];\n    }\n    for(int\
    \ i = 1; i <= n; ++i){\n        cin >> b[i];\n    }\n    auto c = gcd_convolution(a,\
    \ b);\n    for(int i = 1; i <= n; ++i){\n        cout << c[i] << \" \\n\"[i ==\
    \ n];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/convolution/gcd_convolution.hpp\"\
    \n#include \"../../../lib/math/modint.hpp\"\n\nusing mint = ModInt<998244353>;\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n  \
    \  int n; cin >> n;\n    vector<mint> a(n + 1), b(n + 1);\n    for(int i = 1;\
    \ i <= n; ++i){\n        cin >> a[i];\n    }\n    for(int i = 1; i <= n; ++i){\n\
    \        cin >> b[i];\n    }\n    auto c = gcd_convolution(a, b);\n    for(int\
    \ i = 1; i <= n; ++i){\n        cout << c[i] << \" \\n\"[i == n];\n    }\n}\n"
  dependsOn:
  - lib/convolution/gcd_convolution.hpp
  - lib/math/modint.hpp
  isVerificationFile: true
  path: test/library_checker/convolution/gcd_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-10-21 21:43:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/convolution/gcd_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/convolution/gcd_convolution.test.cpp
- /verify/test/library_checker/convolution/gcd_convolution.test.cpp.html
title: test/library_checker/convolution/gcd_convolution.test.cpp
---
