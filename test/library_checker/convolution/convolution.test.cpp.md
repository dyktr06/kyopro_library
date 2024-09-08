---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/convolution/fps.hpp
    title: lib/convolution/fps.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/library_checker/convolution/convolution.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/convolution/fps.hpp\"\
    \n\nnamespace FPS{\n    const unsigned long long MOD = 998244353;\n\n    // @param\
    \ n `0 <= n`\n    // @return minimum non-negative `x` s.t. `n <= 2**x`\n    int\
    \ ceil_pow2(int n) {\n        int x = 0;\n        while((1U << x) < (unsigned\
    \ int) (n)) x++;\n        return x;\n    }\n\n    // @param n `1 <= n`\n    //\
    \ @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\n    int bsf(unsigned\
    \ int n) {\n        return __builtin_ctz(n);\n    }\n\n    int primitive_root(int\
    \ m) {\n        if(m == 2) return 1;\n        if(m == 167772161) return 3;\n \
    \       if(m == 469762049) return 3;\n        if(m == 754974721) return 11;\n\
    \        if(m == 998244353) return 3;\n        return 1;\n    }\n\n    template\
    \ <typename T>\n    void butterfly(vector<T> &a){\n        int g = primitive_root(MOD);\n\
    \        int n = int(a.size());\n        int h = ceil_pow2(n);\n\n        static\
    \ bool first = true;\n        static T sum_e[30];  // sum_e[i] = ies[0] * ...\
    \ * ies[i - 1] * es[i]\n        if(first){\n            first = false;\n     \
    \       T es[30], ies[30];  // es[i]^(2^(2+i)) == 1\n            int cnt2 = bsf(MOD\
    \ - 1);\n            T e = T(g).pow((MOD - 1) >> cnt2), ie = e.inv();\n      \
    \      for(int i = cnt2; i >= 2; i--){\n                // e^(2^i) == 1\n    \
    \            es[i - 2] = e;\n                ies[i - 2] = ie;\n              \
    \  e *= e;\n                ie *= ie;\n            }\n            T now = 1;\n\
    \            for(int i = 0; i <= cnt2 - 2; i++){\n                sum_e[i] = es[i]\
    \ * now;\n                now *= ies[i];\n            }\n        }\n        for(int\
    \ ph = 1; ph <= h; ph++){\n            int w = 1 << (ph - 1), p = 1 << (h - ph);\n\
    \            T now = 1;\n            for(int s = 0; s < w; s++){\n           \
    \     int offset = s << (h - ph + 1);\n                for(int i = 0; i < p; i++){\n\
    \                    auto l = a[i + offset];\n                    auto r = a[i\
    \ + offset + p] * now;\n                    a[i + offset] = l + r;\n         \
    \           a[i + offset + p] = l - r;\n                }\n                now\
    \ *= sum_e[bsf(~(unsigned int) (s))];\n            }\n        }\n    }\n\n   \
    \ template <typename T>\n    void butterfly_inv(vector<T> &a) {\n        int g\
    \ = primitive_root(MOD);\n        int n = int(a.size());\n        int h = ceil_pow2(n);\n\
    \n        static bool first = true;\n        static T sum_ie[30];  // sum_ie[i]\
    \ = es[0] * ... * es[i - 1] * ies[i]\n        if(first){\n            first =\
    \ false;\n            T es[30], ies[30];  // es[i]^(2^(2+i)) == 1\n          \
    \  int cnt2 = bsf(MOD - 1);\n            T e = T(g).pow((MOD - 1) >> cnt2), ie\
    \ = e.inv();\n            for(int i = cnt2; i >= 2; i--){\n                //\
    \ e^(2^i) == 1\n                es[i - 2] = e;\n                ies[i - 2] = ie;\n\
    \                e *= e;\n                ie *= ie;\n            }\n         \
    \   T now = 1;\n            for(int i = 0; i <= cnt2 - 2; i++){\n            \
    \    sum_ie[i] = ies[i] * now;\n                now *= es[i];\n            }\n\
    \        }\n\n        for(int ph = h; ph >= 1; ph--){\n            int w = 1 <<\
    \ (ph - 1), p = 1 << (h - ph);\n            T inow = 1;\n            for(int s\
    \ = 0; s < w; s++){\n                int offset = s << (h - ph + 1);\n       \
    \         for(int i = 0; i < p; i++){\n                    auto l = a[i + offset];\n\
    \                    auto r = a[i + offset + p];\n                    a[i + offset]\
    \ = l + r;\n                    a[i + offset + p] = (unsigned long long) (MOD\
    \ + l.val - r.val) * inow.val;\n                }\n                inow *= sum_ie[bsf(~(unsigned\
    \ int) (s))];\n            }\n        }\n    }\n\n    template <typename T>\n\
    \    vector<T> convolution(vector<T> a, vector<T> b){\n        int n = int(a.size()),\
    \ m = int(b.size());\n        if(!n || !m) return {};\n        if(min(n, m) <=\
    \ 60) {\n            if(n < m) {\n                swap(n, m);\n              \
    \  swap(a, b);\n            }\n            vector<T> ans(n + m - 1);\n       \
    \     for(int i = 0; i < n; i++){\n                for(int j = 0; j < m; j++){\n\
    \                    ans[i + j] += a[i] * b[j];\n                }\n         \
    \   }\n            return ans;\n        }\n        int z = 1 << ceil_pow2(n +\
    \ m - 1);\n        a.resize(z);\n        butterfly(a);\n        b.resize(z);\n\
    \        butterfly(b);\n        for(int i = 0; i < z; i++){\n            a[i]\
    \ *= b[i];\n        }\n        butterfly_inv(a);\n        a.resize(n + m - 1);\n\
    \        T iz = T(z).inv();\n        for(int i = 0; i < n + m - 1; i++) a[i] *=\
    \ iz;\n        return a;\n    }\n};\n#line 2 \"lib/math/modint.hpp\"\n\n/**\n\
    \ * @brief ModInt\n * @docs docs/math/modint.md\n */\n\ntemplate <long long Modulus>\n\
    struct ModInt{\n    long long val;\n    constexpr ModInt(const long long _val\
    \ = 0) noexcept : val(_val) {\n        normalize();\n    }\n    void normalize(){\n\
    \        val = (val % Modulus + Modulus) % Modulus;\n    }\n    inline ModInt\
    \ &operator+=(const ModInt &rhs) noexcept {\n        if(val += rhs.val, val >=\
    \ Modulus) val -= Modulus;\n        return *this;\n    }\n    inline ModInt &operator-=(const\
    \ ModInt &rhs) noexcept {\n        if(val -= rhs.val, val < 0) val += Modulus;\n\
    \        return *this;\n    }\n    inline ModInt &operator*=(const ModInt &rhs)\
    \ noexcept {\n        val = val * rhs.val % Modulus;\n        return *this;\n\
    \    }\n    inline ModInt &operator/=(const ModInt &rhs) noexcept {\n        val\
    \ = val * inv(rhs.val).val % Modulus;\n        return *this;\n    }\n    inline\
    \ ModInt &operator++() noexcept {\n        if(++val >= Modulus) val -= Modulus;\n\
    \        return *this;\n    }\n    inline ModInt operator++(int) noexcept {\n\
    \        ModInt t = val;\n        if(++val >= Modulus) val -= Modulus;\n     \
    \   return t;\n    }\n    inline ModInt &operator--() noexcept {\n        if(--val\
    \ < 0) val += Modulus;\n        return *this;\n    }\n    inline ModInt operator--(int)\
    \ noexcept {\n        ModInt t = val;\n        if(--val < 0) val += Modulus;\n\
    \        return t;\n    }\n    inline ModInt operator-() const noexcept { return\
    \ (Modulus - val) % Modulus; }\n    inline ModInt inv(void) const { return inv(val);\
    \ }\n    ModInt pow(long long n){\n        assert(0 <= n);\n        ModInt x =\
    \ *this, r = 1;\n        while(n){\n            if(n & 1) r *= x;\n          \
    \  x *= x;\n            n >>= 1;\n        }\n        return r;\n    }\n    ModInt\
    \ inv(const long long n) const {\n        long long a = n, b = Modulus, u = 1,\
    \ v = 0;\n        while(b){\n            long long t = a / b;\n            a -=\
    \ t * b; swap(a, b);\n            u -= t * v; swap(u, v);\n        }\n       \
    \ u %= Modulus;\n        if(u < 0) u += Modulus;\n        return u;\n    }\n \
    \   friend inline ModInt operator+(const ModInt &lhs, const ModInt &rhs) noexcept\
    \ { return ModInt(lhs) += rhs; }\n    friend inline ModInt operator-(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept { return ModInt(lhs) -= rhs; }\n    friend\
    \ inline ModInt operator*(const ModInt &lhs, const ModInt &rhs) noexcept { return\
    \ ModInt(lhs) *= rhs; }\n    friend inline ModInt operator/(const ModInt &lhs,\
    \ const ModInt &rhs) noexcept { return ModInt(lhs) /= rhs; }\n    friend inline\
    \ bool operator==(const ModInt &lhs, const ModInt &rhs) noexcept { return lhs.val\
    \ == rhs.val; }\n    friend inline bool operator!=(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept { return lhs.val != rhs.val; }\n    friend inline istream &operator>>(istream\
    \ &is, ModInt &x) noexcept {\n        is >> x.val;\n        x.normalize();\n \
    \       return is;\n    }\n    friend inline ostream &operator<<(ostream &os,\
    \ const ModInt &x) noexcept { return os << x.val; }\n};\n#line 7 \"test/library_checker/convolution/convolution.test.cpp\"\
    \n\nusing mint = ModInt<998244353>;\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    srand(time(NULL));\n\n    int n, m; cin >> n >> m;\n\
    \    vector<mint> a(n), b(m);\n    for(int i = 0; i < n; i++) cin >> a[i];\n \
    \   for(int i = 0; i < m; i++) cin >> b[i];\n    auto c = FPS::convolution(a,\
    \ b);\n    for(int i = 0; i < n + m - 1; i++) cout << c[i] << (i + 1 == n + m\
    \ - 1 ? '\\n' : ' ');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/convolution/fps.hpp\"\
    \n#include \"../../../lib/math/modint.hpp\"\n\nusing mint = ModInt<998244353>;\n\
    \nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    srand(time(NULL));\n\
    \n    int n, m; cin >> n >> m;\n    vector<mint> a(n), b(m);\n    for(int i =\
    \ 0; i < n; i++) cin >> a[i];\n    for(int i = 0; i < m; i++) cin >> b[i];\n \
    \   auto c = FPS::convolution(a, b);\n    for(int i = 0; i < n + m - 1; i++) cout\
    \ << c[i] << (i + 1 == n + m - 1 ? '\\n' : ' ');\n}\n"
  dependsOn:
  - lib/convolution/fps.hpp
  - lib/math/modint.hpp
  isVerificationFile: true
  path: test/library_checker/convolution/convolution.test.cpp
  requiredBy: []
  timestamp: '2024-05-05 01:52:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/convolution/convolution.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/convolution/convolution.test.cpp
- /verify/test/library_checker/convolution/convolution.test.cpp.html
title: test/library_checker/convolution/convolution.test.cpp
---
