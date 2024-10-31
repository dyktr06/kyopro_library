---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/convolution/ntt.hpp
    title: lib/convolution/ntt.hpp
  - icon: ':question:'
    path: lib/math/crt.hpp
    title: "Chinese Remainder Theorem (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)"
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 1 \"test/library_checker/convolution/convolution_mod_1000000007.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/convolution/ntt.hpp\"\
    \n\n#line 2 \"lib/math/modint.hpp\"\n\n#line 4 \"lib/math/modint.hpp\"\n\n/**\n\
    \ * @brief ModInt\n * @docs docs/math/modint.md\n */\n\ntemplate <long long Modulus>\n\
    struct ModInt{\n    long long val;\n    static constexpr int mod() { return Modulus;\
    \ }\n    constexpr ModInt(const long long _val = 0) noexcept : val(_val) {\n \
    \       normalize();\n    }\n    void normalize(){\n        val = (val % Modulus\
    \ + Modulus) % Modulus;\n    }\n    inline ModInt &operator+=(const ModInt &rhs)\
    \ noexcept {\n        if(val += rhs.val, val >= Modulus) val -= Modulus;\n   \
    \     return *this;\n    }\n    inline ModInt &operator-=(const ModInt &rhs) noexcept\
    \ {\n        if(val -= rhs.val, val < 0) val += Modulus;\n        return *this;\n\
    \    }\n    inline ModInt &operator*=(const ModInt &rhs) noexcept {\n        val\
    \ = val * rhs.val % Modulus;\n        return *this;\n    }\n    inline ModInt\
    \ &operator/=(const ModInt &rhs) noexcept {\n        val = val * inv(rhs.val).val\
    \ % Modulus;\n        return *this;\n    }\n    inline ModInt &operator++() noexcept\
    \ {\n        if(++val >= Modulus) val -= Modulus;\n        return *this;\n   \
    \ }\n    inline ModInt operator++(int) noexcept {\n        ModInt t = val;\n \
    \       if(++val >= Modulus) val -= Modulus;\n        return t;\n    }\n    inline\
    \ ModInt &operator--() noexcept {\n        if(--val < 0) val += Modulus;\n   \
    \     return *this;\n    }\n    inline ModInt operator--(int) noexcept {\n   \
    \     ModInt t = val;\n        if(--val < 0) val += Modulus;\n        return t;\n\
    \    }\n    inline ModInt operator-() const noexcept { return (Modulus - val)\
    \ % Modulus; }\n    inline ModInt inv(void) const { return inv(val); }\n    ModInt\
    \ pow(long long n){\n        assert(0 <= n);\n        ModInt x = *this, r = 1;\n\
    \        while(n){\n            if(n & 1) r *= x;\n            x *= x;\n     \
    \       n >>= 1;\n        }\n        return r;\n    }\n    ModInt inv(const long\
    \ long n) const {\n        long long a = n, b = Modulus, u = 1, v = 0;\n     \
    \   while(b){\n            long long t = a / b;\n            a -= t * b; std::swap(a,\
    \ b);\n            u -= t * v; std::swap(u, v);\n        }\n        u %= Modulus;\n\
    \        if(u < 0) u += Modulus;\n        return u;\n    }\n    friend inline\
    \ ModInt operator+(const ModInt &lhs, const ModInt &rhs) noexcept { return ModInt(lhs)\
    \ += rhs; }\n    friend inline ModInt operator-(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept { return ModInt(lhs) -= rhs; }\n    friend inline ModInt operator*(const\
    \ ModInt &lhs, const ModInt &rhs) noexcept { return ModInt(lhs) *= rhs; }\n  \
    \  friend inline ModInt operator/(const ModInt &lhs, const ModInt &rhs) noexcept\
    \ { return ModInt(lhs) /= rhs; }\n    friend inline bool operator==(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept { return lhs.val == rhs.val; }\n    friend\
    \ inline bool operator!=(const ModInt &lhs, const ModInt &rhs) noexcept { return\
    \ lhs.val != rhs.val; }\n    friend inline std::istream &operator>>(std::istream\
    \ &is, ModInt &x) noexcept {\n        is >> x.val;\n        x.normalize();\n \
    \       return is;\n    }\n    friend inline std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &x) noexcept { return os << x.val; }\n};\n#line 2 \"lib/math/crt.hpp\"\
    \n\n/**\n * @brief Chinese Remainder Theorem (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\
    )\n * @docs docs/math/crt.md\n */\n\nnamespace CRT{\n    inline long long mod(long\
    \ long a, long long m){\n        return (a % m + m) % m;\n    }\n\n    long long\
    \ extGCD(long long a, long long b, long long &x, long long &y){\n        if(b\
    \ == 0){\n            x = 1;\n            y = 0;\n            return a;\n    \
    \    }\n        long long d = extGCD(b, a % b, y, x);\n        y -= a / b * x;\n\
    \        return d;\n    }\n\n    pair<long long, long long> chineseRem(const vector<long\
    \ long> &b, const vector<long long> &m) {\n        long long r = 0, M = 1;\n \
    \       for(int i = 0; i < (int) b.size(); i++){\n            long long p, q;\n\
    \            long long d = extGCD(M, m[i], p, q);\n            if((b[i] - r) %\
    \ d != 0) return {0, -1};\n            long long tmp = (b[i] - r) / d * p % (m[i]\
    \ / d);\n            r += M * tmp;\n            M *= m[i] / d;\n        }\n  \
    \      r %= M;\n        if(r < 0) r += M;\n        return {r, M};\n    }\n\n \
    \   // not coprime\n    long long preGarner(vector<long long> &b, vector<long\
    \ long> &m, const long long MOD){\n        long long res = 1;\n        int n =\
    \ b.size();\n        for(int i = 0; i < n; i++){\n            for(int j = 0; j\
    \ < i; j++){\n                long long g = gcd(m[i], m[j]);\n               \
    \ if((b[i] - b[j]) % g != 0) return -1;\n                m[i] /= g, m[j] /= g;\n\
    \                // gcd \u306E\u5206\u3060\u3051\u88AB\u3063\u3066\u308B\u306E\
    \u3067\u632F\u308A\u5206\u3051\u308B\n                long long gi = gcd(m[i],\
    \ g), gj = g / gi;\n                do{\n                    g = gcd(gi, gj);\n\
    \                    gi *= g, gj /= g;\n                }while(g != 1);\n    \
    \            m[i] *= gi, m[j] *= gj;\n                b[i] %= m[i], b[j] %= m[j];\n\
    \            }\n        }\n        for(auto x : m) (res *= x) %= MOD;\n      \
    \  return res;\n    }\n\n    long long garner(const vector<long long> &b, const\
    \ vector<long long> &m, const long long MOD){\n        vector<long long> tm =\
    \ m;\n        tm.push_back(MOD);\n        auto inv = [&](long long a, long long\
    \ m) -> long long {\n            long long x, y;\n            extGCD(a, m, x,\
    \ y);\n            return mod(x, m);\n        };\n        int n = b.size();\n\
    \        vector<long long> coeffs(n + 1, 1), constants(n + 1, 0);\n        for(int\
    \ i = 0; i < n; i++){\n            // solve \"coeffs[i] * t[i] + constants[i]\
    \ = b[i] (mod. m[i])\n            long long t = mod((b[i] - constants[i]) * inv(coeffs[i],\
    \ tm[i]), tm[i]);\n            for(int j = i + 1; j < n + 1; j++){\n         \
    \       (constants[j] += t * coeffs[j]) %= tm[j];\n                (coeffs[j]\
    \ *= tm[i]) %= tm[j];\n            }\n        }\n        return constants[n];\n\
    \    }\n}\n#line 5 \"lib/convolution/ntt.hpp\"\n\nnamespace NTT{\n    // @param\
    \ n `0 <= n`\n    // @return minimum non-negative `x` s.t. `n <= 2**x`\n    int\
    \ ceil_pow2(int n) {\n        int x = 0;\n        while((1U << x) < (unsigned\
    \ int) (n)) x++;\n        return x;\n    }\n\n    // @param n `1 <= n`\n    //\
    \ @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\n    int bsf(unsigned\
    \ int n) {\n        return __builtin_ctz(n);\n    }\n\n    int primitive_root(int\
    \ m) {\n        if(m == 2) return 1;\n        if(m == 167772161) return 3;\n \
    \       if(m == 469762049) return 3;\n        if(m == 754974721) return 11;\n\
    \        if(m == 998244353) return 3;\n        return 1;\n    }\n\n    template\
    \ <typename T>\n    void butterfly(vector<T> &a){\n        int g = primitive_root(T::mod());\n\
    \        int n = int(a.size());\n        int h = ceil_pow2(n);\n\n        static\
    \ bool first = true;\n        static T sum_e[30];  // sum_e[i] = ies[0] * ...\
    \ * ies[i - 1] * es[i]\n        if(first){\n            first = false;\n     \
    \       T es[30], ies[30];  // es[i]^(2^(2+i)) == 1\n            int cnt2 = bsf(T::mod()\
    \ - 1);\n            T e = T(g).pow((T::mod() - 1) >> cnt2), ie = e.inv();\n \
    \           for(int i = cnt2; i >= 2; i--){\n                // e^(2^i) == 1\n\
    \                es[i - 2] = e;\n                ies[i - 2] = ie;\n          \
    \      e *= e;\n                ie *= ie;\n            }\n            T now =\
    \ 1;\n            for(int i = 0; i <= cnt2 - 2; i++){\n                sum_e[i]\
    \ = es[i] * now;\n                now *= ies[i];\n            }\n        }\n \
    \       for(int ph = 1; ph <= h; ph++){\n            int w = 1 << (ph - 1), p\
    \ = 1 << (h - ph);\n            T now = 1;\n            for(int s = 0; s < w;\
    \ s++){\n                int offset = s << (h - ph + 1);\n                for(int\
    \ i = 0; i < p; i++){\n                    auto l = a[i + offset];\n         \
    \           auto r = a[i + offset + p] * now;\n                    a[i + offset]\
    \ = l + r;\n                    a[i + offset + p] = l - r;\n                }\n\
    \                now *= sum_e[bsf(~(unsigned int) (s))];\n            }\n    \
    \    }\n    }\n\n    template <typename T>\n    void butterfly_inv(vector<T> &a)\
    \ {\n        int g = primitive_root(T::mod());\n        int n = int(a.size());\n\
    \        int h = ceil_pow2(n);\n\n        static bool first = true;\n        static\
    \ T sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]\n        if(first){\n\
    \            first = false;\n            T es[30], ies[30];  // es[i]^(2^(2+i))\
    \ == 1\n            int cnt2 = bsf(T::mod() - 1);\n            T e = T(g).pow((T::mod()\
    \ - 1) >> cnt2), ie = e.inv();\n            for(int i = cnt2; i >= 2; i--){\n\
    \                // e^(2^i) == 1\n                es[i - 2] = e;\n           \
    \     ies[i - 2] = ie;\n                e *= e;\n                ie *= ie;\n \
    \           }\n            T now = 1;\n            for(int i = 0; i <= cnt2 -\
    \ 2; i++){\n                sum_ie[i] = ies[i] * now;\n                now *=\
    \ es[i];\n            }\n        }\n\n        for(int ph = h; ph >= 1; ph--){\n\
    \            int w = 1 << (ph - 1), p = 1 << (h - ph);\n            T inow = 1;\n\
    \            for(int s = 0; s < w; s++){\n                int offset = s << (h\
    \ - ph + 1);\n                for(int i = 0; i < p; i++){\n                  \
    \  auto l = a[i + offset];\n                    auto r = a[i + offset + p];\n\
    \                    a[i + offset] = l + r;\n                    a[i + offset\
    \ + p] = (unsigned long long) (T::mod() + l.val - r.val) * inow.val;\n       \
    \         }\n                inow *= sum_ie[bsf(~(unsigned int) (s))];\n     \
    \       }\n        }\n    }\n\n    template <typename T>\n    vector<T> convolution(vector<T>\
    \ a, vector<T> b){\n        int n = int(a.size()), m = int(b.size());\n      \
    \  if(!n || !m) return {};\n        if(min(n, m) <= 60) {\n            if(n <\
    \ m) {\n                swap(n, m);\n                swap(a, b);\n           \
    \ }\n            vector<T> ans(n + m - 1);\n            for(int i = 0; i < n;\
    \ i++){\n                for(int j = 0; j < m; j++){\n                    ans[i\
    \ + j] += a[i] * b[j];\n                }\n            }\n            return ans;\n\
    \        }\n        int z = 1 << ceil_pow2(n + m - 1);\n        a.resize(z);\n\
    \        butterfly(a);\n        b.resize(z);\n        butterfly(b);\n        for(int\
    \ i = 0; i < z; i++){\n            a[i] *= b[i];\n        }\n        butterfly_inv(a);\n\
    \        a.resize(n + m - 1);\n        T iz = T(z).inv();\n        for(int i =\
    \ 0; i < n + m - 1; i++) a[i] *= iz;\n        return a;\n    }\n\n    template\
    \ <typename T>\n    vector<T> convolution_mod(const vector<T> &a, const vector<T>\
    \ &b, const long long MOD){\n        constexpr long long m0 = 167772161;\n   \
    \     constexpr long long m1 = 469762049;\n        constexpr long long m2 = 754974721;\n\
    \        using mint0 = ModInt<m0>;\n        using mint1 = ModInt<m1>;\n      \
    \  using mint2 = ModInt<m2>;\n        int n = a.size(), m = b.size();\n      \
    \  vector<mint0> a0(n), b0(m);\n        vector<mint1> a1(n), b1(m);\n        vector<mint2>\
    \ a2(n), b2(m);\n        for(int i = 0; i < n; i++){\n            a0[i] = a[i].val;\n\
    \            a1[i] = a[i].val;\n            a2[i] = a[i].val;\n        }\n   \
    \     for(int i = 0; i < m; i++){\n            b0[i] = b[i].val;\n           \
    \ b1[i] = b[i].val;\n            b2[i] = b[i].val;\n        }\n        auto c0\
    \ = convolution(a0, b0);\n        auto c1 = convolution(a1, b1);\n        auto\
    \ c2 = convolution(a2, b2);\n        vector<T> ret(n + m - 1);\n        for(int\
    \ i = 0; i < n + m - 1; i++){\n            ret[i] = CRT::garner({c0[i].val, c1[i].val,\
    \ c2[i].val}, {m0, m1, m2}, MOD);\n        }\n        return ret;\n    }\n};\n\
    #line 7 \"test/library_checker/convolution/convolution_mod_1000000007.test.cpp\"\
    \n\nconst long long MOD = 1000000007;\nusing mint = ModInt<MOD>;\n\nint main(){\n\
    \    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int n, m; cin\
    \ >> n >> m;\n    vector<mint> a(n), b(m);\n    for(int i = 0; i < n; i++) cin\
    \ >> a[i];\n    for(int i = 0; i < m; i++) cin >> b[i];\n    auto c = NTT::convolution_mod(a,\
    \ b, MOD);\n    for(int i = 0; i < n + m - 1; i++) cout << c[i] << (i + 1 == n\
    \ + m - 1 ? '\\n' : ' ');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/convolution/ntt.hpp\"\
    \n#include \"../../../lib/math/modint.hpp\"\n\nconst long long MOD = 1000000007;\n\
    using mint = ModInt<MOD>;\n\nint main(){\n    ios::sync_with_stdio(false);\n \
    \   cin.tie(nullptr);\n\n    int n, m; cin >> n >> m;\n    vector<mint> a(n),\
    \ b(m);\n    for(int i = 0; i < n; i++) cin >> a[i];\n    for(int i = 0; i < m;\
    \ i++) cin >> b[i];\n    auto c = NTT::convolution_mod(a, b, MOD);\n    for(int\
    \ i = 0; i < n + m - 1; i++) cout << c[i] << (i + 1 == n + m - 1 ? '\\n' : ' ');\n\
    }\n"
  dependsOn:
  - lib/convolution/ntt.hpp
  - lib/math/modint.hpp
  - lib/math/crt.hpp
  isVerificationFile: true
  path: test/library_checker/convolution/convolution_mod_1000000007.test.cpp
  requiredBy: []
  timestamp: '2024-10-31 17:18:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/convolution/convolution_mod_1000000007.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/convolution/convolution_mod_1000000007.test.cpp
- /verify/test/library_checker/convolution/convolution_mod_1000000007.test.cpp.html
title: test/library_checker/convolution/convolution_mod_1000000007.test.cpp
---
