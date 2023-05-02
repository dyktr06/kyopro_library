---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/convolution/bitwise_xor_convolution.hpp
    title: lib/convolution/bitwise_xor_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: lib/convolution/fast_walsh_hadamard_transform.hpp
    title: lib/convolution/fast_walsh_hadamard_transform.hpp
  - icon: ':question:'
    path: lib/math/modint.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: lib/math/utils.hpp
    title: lib/math/utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"test/library_checker/convolution/bitwise_xor_convolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/convolution/bitwise_xor_convolution.hpp\"\
    \n\n#line 2 \"lib/convolution/fast_walsh_hadamard_transform.hpp\"\n\ntemplate\
    \ <typename T>\nvoid fast_walsh_hadamard_transform(vector<T> &f, bool inv = false){\n\
    \    const int n = (int) f.size();\n    assert((n & (n - 1)) == 0);\n    for(int\
    \ i = 1; i < n; i <<= 1){\n        for(int j = 0; j < n; j += i << 1){\n     \
    \       for(int k = 0; k < i; ++k){\n                T s = f[j + k], t = f[j +\
    \ k + i];\n                f[j + k] = s + t;\n                f[j + k + i] = s\
    \ - t;\n            }\n        }\n    }\n    if(inv){\n        T inv_n = T(1)\
    \ / n;\n        for(auto &x : f) x *= inv_n;\n    }\n}\n#line 4 \"lib/convolution/bitwise_xor_convolution.hpp\"\
    \n\ntemplate <typename T>\nvector<T> bitwise_xor_convolution(vector<T> f, vector<T>\
    \ g){\n    const int n = (int) f.size();\n    assert(f.size() == g.size());\n\
    \    assert((n & (n - 1)) == 0);\n    fast_walsh_hadamard_transform(f, false);\n\
    \    fast_walsh_hadamard_transform(g, false);\n    for(int i = 0; i < n; ++i){\n\
    \        f[i] *= g[i];\n    }\n    fast_walsh_hadamard_transform(f, true);\n \
    \   return f;\n}\n#line 2 \"lib/math/modint.hpp\"\n\n/**\n * @brief ModInt\n *\
    \ @docs docs/math/modint.md\n */\n\ntemplate <long long Modulus>\nstruct ModInt{\n\
    \    long long val;\n    constexpr ModInt(const long long &_val = 0) noexcept\
    \ : val(_val) {\n        normalize();\n    }\n    void normalize(){\n        val\
    \ = (val % Modulus + Modulus) % Modulus;\n    }\n    inline ModInt& operator+=(const\
    \ ModInt& rhs) noexcept {\n        if(val += rhs.val, val >= Modulus) val -= Modulus;\n\
    \        return *this;\n    }\n    inline ModInt& operator-=(const ModInt& rhs)\
    \ noexcept {\n        if(val -= rhs.val, val < 0) val += Modulus;\n        return\
    \ *this;\n    }\n    inline ModInt& operator*=(const ModInt& rhs) noexcept {\n\
    \        val = val * rhs.val % Modulus;\n        return *this;\n    }\n    inline\
    \ ModInt& operator/=(const ModInt& rhs) noexcept {\n        val = val * inv(rhs.val).val\
    \ % Modulus;\n        return *this;\n    }\n    inline ModInt& operator++() noexcept\
    \ {\n        if(++val >= Modulus) val -= Modulus;\n        return *this;\n   \
    \ }\n    inline ModInt operator++(int) noexcept {\n        ModInt t = val;\n \
    \       if(++val >= Modulus) val -= Modulus;\n        return t;\n    }\n    inline\
    \ ModInt& operator--() noexcept {\n        if(--val < 0) val += Modulus;\n   \
    \     return *this;\n    }\n    inline ModInt operator--(int) noexcept {\n   \
    \     ModInt t = val;\n        if(--val < 0) val += Modulus;\n        return t;\n\
    \    }\n    inline ModInt operator-() const noexcept { return (Modulus - val)\
    \ % Modulus; }\n    inline ModInt inv(void) const { return inv(val); }\n    ModInt\
    \ inv(const long long& n) const {\n        long long a = n, b = Modulus, u = 1,\
    \ v = 0;\n        while(b){\n            long long t = a / b;\n            a -=\
    \ t * b; swap(a, b);\n            u -= t * v; swap(u, v);\n        }\n       \
    \ u %= Modulus;\n        if(u < 0) u += Modulus;\n        return u;\n    }\n \
    \   friend inline ModInt operator+(const ModInt& lhs, const ModInt& rhs) noexcept\
    \ { return ModInt(lhs) += rhs; }\n    friend inline ModInt operator-(const ModInt&\
    \ lhs, const ModInt& rhs) noexcept { return ModInt(lhs) -= rhs; }\n    friend\
    \ inline ModInt operator*(const ModInt& lhs, const ModInt& rhs) noexcept { return\
    \ ModInt(lhs) *= rhs; }\n    friend inline ModInt operator/(const ModInt& lhs,\
    \ const ModInt& rhs) noexcept { return ModInt(lhs) /= rhs; }\n    friend inline\
    \ bool operator==(const ModInt& lhs, const ModInt& rhs) noexcept { return lhs.val\
    \ == rhs.val; }\n    friend inline bool operator!=(const ModInt& lhs, const ModInt&\
    \ rhs) noexcept { return lhs.val != rhs.val; }\n    friend inline istream& operator>>(istream&\
    \ is, ModInt& x) noexcept {\n        is >> x.val;\n        x.normalize();\n  \
    \      return is;\n    }\n    friend inline ostream& operator<<(ostream& os, const\
    \ ModInt& x) noexcept { return os << x.val; }\n};\n#line 2 \"lib/math/utils.hpp\"\
    \n\n// a\u304B\u3089b\u307E\u3067\u306E\u548C\u3092\u3082\u3068\u3081\u307E\u3059\
    \ : O(1)\ntemplate <typename T>\nlong long sum(T a, T b){\n    long long res =\
    \ ((b - a + 1) * (a + b)) / 2;\n    return res;\n}\n\n// x^n\u3092\u3082\u3068\
    \u3081\u307E\u3059 : O(logN)\ntemplate <typename T>\nT intpow(T x, T n){\n   \
    \ T ret = 1;\n    while(n > 0) {\n        if(n & 1) (ret *= x);\n        (x *=\
    \ x);\n        n >>= 1;\n    }\n    return ret;\n}\n\n// \u521D\u9805 a, \u516C\
    \u5DEE d, \u9805\u6570 n \u306E\u7B49\u5DEE\u6570\u5217\u306E\u548C\u3092\u8A08\
    \u7B97\u3057\u307E\u3059 : O(1)\ntemplate <typename T>\nT arithmeticsum(T a, T\
    \ d, T n){\n    return n * (a * 2 + (n - 1) * d) / 2;\n}\n\n// \u521D\u9805 a,\
    \ \u516C\u6BD4 r, \u9805\u6570 n \u306E\u7B49\u6BD4\u6570\u5217\u306E\u548C\u3092\
    \u8A08\u7B97\u3057\u307E\u3059 : O(1)\ntemplate <typename T>\nT geometricsum(T\
    \ a, T r, T n){\n    if(r == 1){\n        return a * n;\n    }\n    return a *\
    \ (intpow(r, n) - 1) / (r - 1);\n}\n\n// a \u3092 b \u3067\u5272\u3063\u305F\u6B63\
    \u306E\u3042\u307E\u308A\u3092\u6C42\u3081\u307E\u3059 : O(1)\ntemplate <typename\
    \ T>\nT getReminder(T a, T b){\n    if(b == 0) return -1;\n    if(a >= 0 && b\
    \ > 0){\n        return a % b;\n    }else if(a < 0 && b > 0){\n        return\
    \ ((a % b) + b) % b;\n    }else if(a >= 0 && b < 0){\n        return a % b;\n\
    \    }else{\n        return (abs(b) - abs(a % b)) % b;\n    }\n}\n\n// x \u306E\
    \u90E8\u5206\u96C6\u5408\u3092\u5217\u6319\u3057\u307E\u3059\u3002\ntemplate <typename\
    \ T>\nvector<T> getSubmask(T x){\n    vector<T> submask;\n    for(T i = x; ; i\
    \ = (i - 1) & x){ \n        submask.push_back(i);\n        if(i == 0) break;\n\
    \    }\n    sort(submask.begin(), submask.end());\n    return submask;\n}\n#line\
    \ 8 \"test/library_checker/convolution/bitwise_xor_convolution.test.cpp\"\n\n\
    using mint = ModInt<998244353>;\n\nint main(){\n    int n; cin >> n;\n    int\
    \ m = intpow(2, n);\n    vector<mint> a(m), b(m);\n    for(int i = 0; i < m; i++){\n\
    \        cin >> a[i];\n    }\n    for(int i = 0; i < m; i++){\n        cin >>\
    \ b[i];\n    }\n    vector<mint> c = bitwise_xor_convolution(a, b);\n    for(int\
    \ i = 0; i < m; i++){\n        cout << c[i] << \" \\n\"[i == m - 1];\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/convolution/bitwise_xor_convolution.hpp\"\
    \n#include \"../../../lib/math/modint.hpp\"\n#include \"../../../lib/math/utils.hpp\"\
    \n\nusing mint = ModInt<998244353>;\n\nint main(){\n    int n; cin >> n;\n   \
    \ int m = intpow(2, n);\n    vector<mint> a(m), b(m);\n    for(int i = 0; i <\
    \ m; i++){\n        cin >> a[i];\n    }\n    for(int i = 0; i < m; i++){\n   \
    \     cin >> b[i];\n    }\n    vector<mint> c = bitwise_xor_convolution(a, b);\n\
    \    for(int i = 0; i < m; i++){\n        cout << c[i] << \" \\n\"[i == m - 1];\n\
    \    }\n}"
  dependsOn:
  - lib/convolution/bitwise_xor_convolution.hpp
  - lib/convolution/fast_walsh_hadamard_transform.hpp
  - lib/math/modint.hpp
  - lib/math/utils.hpp
  isVerificationFile: true
  path: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2023-05-01 02:14:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/convolution/bitwise_xor_convolution.test.cpp
- /verify/test/library_checker/convolution/bitwise_xor_convolution.test.cpp.html
title: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
---
