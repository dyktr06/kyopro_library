---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/convolution/ntt.hpp
    title: lib/convolution/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: lib/math/crt.hpp
    title: "Chinese Remainder Theorem (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)"
  - icon: ':heavy_check_mark:'
    path: lib/math/modint.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: lib/polynomial/formal_power_series.hpp
    title: lib/polynomial/formal_power_series.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
    title: test/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/polynomial/product_of_polynomial_sequence.hpp\"\n\n\
    #line 2 \"lib/polynomial/formal_power_series.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n#line 2 \"lib/convolution/ntt.hpp\"\n\n#line 2\
    \ \"lib/math/modint.hpp\"\n\n#include <iostream>\n#line 5 \"lib/math/modint.hpp\"\
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
    \ }\n};\n#line 2 \"lib/math/crt.hpp\"\n\n/**\n * @brief Chinese Remainder Theorem\
    \ (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)\n * @docs docs/math/crt.md\n */\n\n#include\
    \ <numeric>\n#line 10 \"lib/math/crt.hpp\"\n\nnamespace CRT{\n    inline long\
    \ long mod(long long a, long long m){\n        return (a % m + m) % m;\n    }\n\
    \n    long long extGCD(long long a, long long b, long long &x, long long &y){\n\
    \        if(b == 0){\n            x = 1;\n            y = 0;\n            return\
    \ a;\n        }\n        long long d = extGCD(b, a % b, y, x);\n        y -= a\
    \ / b * x;\n        return d;\n    }\n\n    std::pair<long long, long long> chineseRem(const\
    \ std::vector<long long> &b, const std::vector<long long> &m) {\n        long\
    \ long r = 0, M = 1;\n        for(int i = 0; i < (int) b.size(); i++){\n     \
    \       long long p, q;\n            long long d = extGCD(M, m[i], p, q);\n  \
    \          if((b[i] - r) % d != 0) return {0, -1};\n            long long tmp\
    \ = (b[i] - r) / d * p % (m[i] / d);\n            r += M * tmp;\n            M\
    \ *= m[i] / d;\n        }\n        r %= M;\n        if(r < 0) r += M;\n      \
    \  return {r, M};\n    }\n\n    // not coprime\n    long long preGarner(std::vector<long\
    \ long> &b, std::vector<long long> &m, const long long MOD){\n        long long\
    \ res = 1;\n        int n = b.size();\n        for(int i = 0; i < n; i++){\n \
    \           for(int j = 0; j < i; j++){\n                long long g = std::gcd(m[i],\
    \ m[j]);\n                if((b[i] - b[j]) % g != 0) return -1;\n            \
    \    m[i] /= g, m[j] /= g;\n                // gcd \u306E\u5206\u3060\u3051\u88AB\
    \u3063\u3066\u308B\u306E\u3067\u632F\u308A\u5206\u3051\u308B\n               \
    \ long long gi = std::gcd(m[i], g), gj = g / gi;\n                do{\n      \
    \              g = std::gcd(gi, gj);\n                    gi *= g, gj /= g;\n\
    \                }while(g != 1);\n                m[i] *= gi, m[j] *= gj;\n  \
    \              b[i] %= m[i], b[j] %= m[j];\n            }\n        }\n       \
    \ for(auto x : m) (res *= x) %= MOD;\n        return res;\n    }\n\n    long long\
    \ garner(const std::vector<long long> &b, const std::vector<long long> &m, const\
    \ long long MOD){\n        std::vector<long long> tm = m;\n        tm.push_back(MOD);\n\
    \        auto inv = [&](long long a, long long m) -> long long {\n           \
    \ long long x, y;\n            extGCD(a, m, x, y);\n            return mod(x,\
    \ m);\n        };\n        int n = b.size();\n        std::vector<long long> coeffs(n\
    \ + 1, 1), constants(n + 1, 0);\n        for(int i = 0; i < n; i++){\n       \
    \     // solve \"coeffs[i] * t[i] + constants[i] = b[i] (mod. m[i])\n        \
    \    long long t = mod((b[i] - constants[i]) * inv(coeffs[i], tm[i]), tm[i]);\n\
    \            for(int j = i + 1; j < n + 1; j++){\n                (constants[j]\
    \ += t * coeffs[j]) %= tm[j];\n                (coeffs[j] *= tm[i]) %= tm[j];\n\
    \            }\n        }\n        return constants[n];\n    }\n}\n#line 5 \"\
    lib/convolution/ntt.hpp\"\n\n#line 7 \"lib/convolution/ntt.hpp\"\n\nnamespace\
    \ NTT{\n\n    // @param n `0 <= n`\n    // @return minimum non-negative `x` s.t.\
    \ `n <= 2**x`\n    int ceil_pow2(int n) {\n        int x = 0;\n        while((1U\
    \ << x) < (unsigned int) (n)) x++;\n        return x;\n    }\n\n    // @param\
    \ n `1 <= n`\n    // @return minimum non-negative `x` s.t. `(n & (1 << x)) !=\
    \ 0`\n    int bsf(unsigned int n) {\n        return __builtin_ctz(n);\n    }\n\
    \n    int primitive_root(int m) {\n        if(m == 2) return 1;\n        if(m\
    \ == 167772161) return 3;\n        if(m == 469762049) return 3;\n        if(m\
    \ == 754974721) return 11;\n        if(m == 998244353) return 3;\n        return\
    \ 1;\n    }\n\n    template <typename T>\n    void butterfly(std::vector<T> &a){\n\
    \        int g = primitive_root(T::mod());\n        int n = int(a.size());\n \
    \       int h = ceil_pow2(n);\n\n        static bool first = true;\n        static\
    \ T sum_e[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]\n        if(first){\n\
    \            first = false;\n            T es[30], ies[30];  // es[i]^(2^(2+i))\
    \ == 1\n            int cnt2 = bsf(T::mod() - 1);\n            T e = T(g).pow((T::mod()\
    \ - 1) >> cnt2), ie = e.inv();\n            for(int i = cnt2; i >= 2; i--){\n\
    \                // e^(2^i) == 1\n                es[i - 2] = e;\n           \
    \     ies[i - 2] = ie;\n                e *= e;\n                ie *= ie;\n \
    \           }\n            T now = 1;\n            for(int i = 0; i <= cnt2 -\
    \ 2; i++){\n                sum_e[i] = es[i] * now;\n                now *= ies[i];\n\
    \            }\n        }\n        for(int ph = 1; ph <= h; ph++){\n         \
    \   int w = 1 << (ph - 1), p = 1 << (h - ph);\n            T now = 1;\n      \
    \      for(int s = 0; s < w; s++){\n                int offset = s << (h - ph\
    \ + 1);\n                for(int i = 0; i < p; i++){\n                    auto\
    \ l = a[i + offset];\n                    auto r = a[i + offset + p] * now;\n\
    \                    a[i + offset] = l + r;\n                    a[i + offset\
    \ + p] = l - r;\n                }\n                now *= sum_e[bsf(~(unsigned\
    \ int) (s))];\n            }\n        }\n    }\n\n    template <typename T>\n\
    \    void butterfly_inv(std::vector<T> &a) {\n        int g = primitive_root(T::mod());\n\
    \        int n = int(a.size());\n        int h = ceil_pow2(n);\n\n        static\
    \ bool first = true;\n        static T sum_ie[30];  // sum_ie[i] = es[0] * ...\
    \ * es[i - 1] * ies[i]\n        if(first){\n            first = false;\n     \
    \       T es[30], ies[30];  // es[i]^(2^(2+i)) == 1\n            int cnt2 = bsf(T::mod()\
    \ - 1);\n            T e = T(g).pow((T::mod() - 1) >> cnt2), ie = e.inv();\n \
    \           for(int i = cnt2; i >= 2; i--){\n                // e^(2^i) == 1\n\
    \                es[i - 2] = e;\n                ies[i - 2] = ie;\n          \
    \      e *= e;\n                ie *= ie;\n            }\n            T now =\
    \ 1;\n            for(int i = 0; i <= cnt2 - 2; i++){\n                sum_ie[i]\
    \ = ies[i] * now;\n                now *= es[i];\n            }\n        }\n\n\
    \        for(int ph = h; ph >= 1; ph--){\n            int w = 1 << (ph - 1), p\
    \ = 1 << (h - ph);\n            T inow = 1;\n            for(int s = 0; s < w;\
    \ s++){\n                int offset = s << (h - ph + 1);\n                for(int\
    \ i = 0; i < p; i++){\n                    auto l = a[i + offset];\n         \
    \           auto r = a[i + offset + p];\n                    a[i + offset] = l\
    \ + r;\n                    a[i + offset + p] = (unsigned long long) (T::mod()\
    \ + l.val - r.val) * inow.val;\n                }\n                inow *= sum_ie[bsf(~(unsigned\
    \ int) (s))];\n            }\n        }\n    }\n\n    template <typename T>\n\
    \    std::vector<T> convolution(std::vector<T> a, std::vector<T> b){\n       \
    \ int n = int(a.size()), m = int(b.size());\n        if(!n || !m) return {};\n\
    \        if(std::min(n, m) <= 60) {\n            if(n < m) {\n               \
    \ std::swap(n, m);\n                std::swap(a, b);\n            }\n        \
    \    std::vector<T> ans(n + m - 1);\n            for(int i = 0; i < n; i++){\n\
    \                for(int j = 0; j < m; j++){\n                    ans[i + j] +=\
    \ a[i] * b[j];\n                }\n            }\n            return ans;\n  \
    \      }\n        int z = 1 << ceil_pow2(n + m - 1);\n        a.resize(z);\n \
    \       butterfly(a);\n        b.resize(z);\n        butterfly(b);\n        for(int\
    \ i = 0; i < z; i++){\n            a[i] *= b[i];\n        }\n        butterfly_inv(a);\n\
    \        a.resize(n + m - 1);\n        T iz = T(z).inv();\n        for(int i =\
    \ 0; i < n + m - 1; i++) a[i] *= iz;\n        return a;\n    }\n\n    template\
    \ <typename T>\n    std::vector<T> convolution_mod(const std::vector<T> &a, const\
    \ std::vector<T> &b, const long long MOD){\n        if(MOD == 998244353){\n  \
    \          return convolution(a, b);\n        }\n        constexpr long long m0\
    \ = 167772161;\n        constexpr long long m1 = 469762049;\n        constexpr\
    \ long long m2 = 754974721;\n        using mint0 = ModInt<m0>;\n        using\
    \ mint1 = ModInt<m1>;\n        using mint2 = ModInt<m2>;\n        int n = a.size(),\
    \ m = b.size();\n        std::vector<mint0> a0(n), b0(m);\n        std::vector<mint1>\
    \ a1(n), b1(m);\n        std::vector<mint2> a2(n), b2(m);\n        for(int i =\
    \ 0; i < n; i++){\n            a0[i] = a[i].val;\n            a1[i] = a[i].val;\n\
    \            a2[i] = a[i].val;\n        }\n        for(int i = 0; i < m; i++){\n\
    \            b0[i] = b[i].val;\n            b1[i] = b[i].val;\n            b2[i]\
    \ = b[i].val;\n        }\n        auto c0 = convolution(a0, b0);\n        auto\
    \ c1 = convolution(a1, b1);\n        auto c2 = convolution(a2, b2);\n        std::vector<T>\
    \ ret(n + m - 1);\n        for(int i = 0; i < n + m - 1; i++){\n            ret[i]\
    \ = CRT::garner({c0[i].val, c1[i].val, c2[i].val}, {m0, m1, m2}, MOD);\n     \
    \   }\n        return ret;\n    }\n};\n#line 7 \"lib/polynomial/formal_power_series.hpp\"\
    \n\ntemplate <typename T>\nstruct FormalPowerSeries : std::vector<T> {\n    using\
    \ std::vector<T>::vector;\n    using FPS = FormalPowerSeries;\n\n    // deg \u6B21\
    \u3068\u3057\u3066\u521D\u671F\u5316\n    FPS pre(int deg) const {\n        FPS\
    \ res(std::begin(*this), std::begin(*this) + std::min((int) this->size(), deg));\n\
    \        if((int) res.size() < deg) res.resize(deg, T(0));\n        return res;\n\
    \    }\n\n    // deg \u6B21\u3068\u3057\u3066\u53CD\u8EE2\n    FPS rev(int deg\
    \ = -1) const {\n        FPS res(*this);\n        if(deg != -1) res.resize(deg,\
    \ T(0));\n        std::reverse(std::begin(res), std::end(res));\n        return\
    \ res;\n    }\n\n    int notZeroCount() const {\n        int res = 0;\n      \
    \  for(auto x : *this){\n            if(x != T(0)) res++;\n        }\n       \
    \ return res;\n    }\n\n    int maxDeg() const {\n        for(int i = (int) this->size()\
    \ - 1; i >= 0; i--){\n            if((*this)[i] != T(0)) return i;\n        }\n\
    \        return -1;\n    }\n\n    void shrink() {\n        while(this->size()\
    \ && this->back() == T(0)) this->pop_back();\n    }\n\n    std::vector<std::pair<int,\
    \ T>> sparseFormat() const {\n        std::vector<std::pair<int, T>> res;\n  \
    \      for(int i = 0; i < (int) this->size(); i++){\n            if((*this)[i]\
    \ != T(0)) res.emplace_back(i, (*this)[i]);\n        }\n        return res;\n\
    \    }\n\n    FPS operator+(const T &rhs) const { return FPS(*this) += rhs; }\n\
    \    FPS operator+(const FPS &rhs) const { return FPS(*this) += rhs; }\n    FPS\
    \ operator-(const T &rhs) const { return FPS(*this) -= rhs; }\n    FPS operator-(const\
    \ FPS &rhs) const { return FPS(*this) -= rhs; }\n    FPS operator*(const T &rhs)\
    \ const { return FPS(*this) *= rhs; }\n    FPS operator*(const FPS &rhs) const\
    \ { return FPS(*this) *= rhs; }\n    FPS operator/(const T &rhs) const { return\
    \ FPS(*this) /= rhs; }\n    FPS operator/(const FPS &rhs) const { return FPS(*this)\
    \ /= rhs; }\n    FPS operator%(const FPS &rhs) const { return FPS(*this) %= rhs;\
    \ }\n    FPS operator-() const {\n        FPS res(this->size());\n        for(int\
    \ i = 0; i < (int) this->size(); i++) res[i] = -(*this)[i];\n        return res;\n\
    \    }\n\n    FPS &operator+=(const T &rhs){\n        if(this->empty()) this->resize(1);\n\
    \        (*this)[0] += rhs;\n        return *this;\n    }\n\n    FPS &operator-=(const\
    \ T &rhs){\n        if(this->empty()) this->resize(1);\n        (*this)[0] -=\
    \ rhs;\n        return *this;\n    }\n\n    FPS &operator*=(const T &rhs){\n \
    \       for(auto &x : *this) x *= rhs;\n        return *this;\n    }\n\n    FPS\
    \ &operator/=(const T &rhs){\n        for(auto &x : *this) x /= rhs;\n       \
    \ return *this;\n    }\n\n    FPS &operator+=(const FPS &rhs) noexcept {\n   \
    \     if(this->size() < rhs.size()) this->resize(rhs.size());\n        for(int\
    \ i = 0; i < (int) rhs.size(); i++) (*this)[i] += rhs[i];\n        return *this;\n\
    \    }\n\n    FPS &operator-=(const FPS &rhs) noexcept {\n        if(this->size()\
    \ < rhs.size()) this->resize(rhs.size());\n        for(int i = 0; i < (int) rhs.size();\
    \ i++) (*this)[i] -= rhs[i];\n        return *this;\n    }\n\n    FPS &operator*=(const\
    \ FPS &rhs) noexcept {\n        long long len1 = this->notZeroCount(), len2 =\
    \ rhs.notZeroCount();\n        // Sparse \u306A\u5834\u5408\n        if(len1 *\
    \ len2 <= 60LL * (long long) std::max(this->size(), rhs.size())){\n          \
    \  std::vector<std::pair<int, T>> rhs_sparse = rhs.sparseFormat();\n         \
    \   return *this = this->multiply_naive(rhs_sparse);\n        }\n        auto\
    \ res = NTT::convolution_mod(*this, rhs, T::mod());\n        return *this = {std::begin(res),\
    \ std::end(res)};\n    }\n\n    // f/g = f * (g.inv())\n    FPS &operator/=(const\
    \ FPS &rhs) noexcept {\n        if(this->size() < rhs.size()) return *this = FPS();\n\
    \        const int n = this->size() - rhs.size() + 1;\n        return *this =\
    \ (rev().pre(n) * rhs.rev().inv(n)).pre(n).rev(n);\n    }\n\n    FPS &operator%=(const\
    \ FPS &rhs) noexcept {\n        return *this -= (*this / rhs) * rhs;\n    }\n\n\
    \    FPS operator>>(int deg) const {\n        if((int) this->size() <= deg) return\
    \ {};\n        FPS res(*this);\n        res.erase(std::begin(res), std::begin(res)\
    \ + deg);\n        return res;\n    }\n\n    FPS operator<<(int deg) const {\n\
    \        FPS res(*this);\n        res.insert(std::begin(res), deg, T(0));\n  \
    \      return res;\n    }\n\n    // \u5FAE\u5206\n    FPS diff() const {\n   \
    \     const int n = this->size();\n        FPS res(std::max(0, n - 1));\n    \
    \    for(int i = 1; i < n; i++) res[i - 1] = (*this)[i] * T(i);\n        return\
    \ res;\n    }\n\n    // \u7A4D\u5206\n    FPS integral() const {\n        const\
    \ int n = this->size();\n        FPS res(n + 1);\n        res[0] = T(0);\n   \
    \     for(int i = 0; i < n; i++) res[i + 1] = (*this)[i] / T(i + 1);\n       \
    \ return res;\n    }\n\n    // {lhs / rhs, lhs % rhs}\n    std::pair<FPS, FPS>\
    \ division(const FPS &rhs) const {\n        FPS q = *this / rhs;\n        FPS\
    \ r = *this - q * rhs;\n        q.shrink(), r.shrink();\n        return {q, r};\n\
    \    }\n\n    FPS multiply_naive(const std::vector<std::pair<int, T>> &rhs, int\
    \ deg = -1){\n        if(deg == -1) deg = this->size() + (rhs.back().first + 1)\
    \ - 1;\n        FPS res(deg, T(0));\n        for(auto &[i, x] : this->sparseFormat()){\n\
    \            for(auto &[j, y] : rhs){\n                if(i + j >= deg) break;\n\
    \                res[i + j] += x * y;\n            }\n        }\n        return\
    \ *this = {std::begin(res), std::end(res)};\n    }\n\n    FPS divide_naive(const\
    \ std::vector<std::pair<int, T>> &rhs){\n        assert(!rhs.empty());\n     \
    \   if((int) this->size() < (rhs.back().first + 1)) return FPS();\n        auto\
    \ [i0, x0] = rhs[0];\n        assert(i0 == 0 && x0 != T(0));\n        T x0_inv\
    \ = T(1) / x0;\n        for(int i = 0; i < (int) this->size(); i++){\n       \
    \     for(int i2 = 1; i2 < (int) rhs.size(); i2++){\n                auto &[j,\
    \ y] = rhs[i2];\n                if(i < j) break;\n                (*this)[i]\
    \ -= (*this)[i - j] * y;\n            }\n            (*this)[i] *= x0_inv;\n \
    \       }\n        return *this;\n    }\n\n    // fg = 1 (mod x^n) \u3068\u306A\
    \u308B g\n    FPS inv(int deg = -1) const {\n        assert((*this)[0] != T(0));\n\
    \        if(deg == -1) deg = this->size();\n        // g_p mod x^k \u304B\u3089\
    \ g mod x^2k \u3092\u6C42\u3081\u308B\n        // (g - g_p)^2 = g^2 - 2 g g_p\
    \ + (g_p)^2 = 0 (mod x^2k)\n        // fg^2 - 2fg g_p + f (g_p)^2\n        //\
    \ = g - 2(g_p) + f (g_p)^2 = 0 (mod x^2k)\n        // g = 2(g_p) - f (g_p)^2 (mod\
    \ x^2k)\n        FPS res({T(1) / (*this)[0]});\n        for(int i = 1; i < deg;\
    \ i <<= 1) {\n            res = (res + res - res * res * pre(i << 1)).pre(i <<\
    \ 1);\n        }\n        return res.pre(deg);\n    }\n\n    // g = log f \u3068\
    \u306A\u308B g\n    FPS log(int deg = -1) const {\n        assert((*this)[0] ==\
    \ T(1));\n        if(deg == -1) deg = this->size();\n        // log f = integral((f'\
    \ / f) dx)\n        return (this->diff() * this->inv(deg)).pre(deg - 1).integral().pre(deg);\n\
    \    }\n\n    // g = exp(f) \u3068\u306A\u308B g\n    FPS exp(int deg = -1) const\
    \ {\n        assert((*this)[0] == T(0));\n        if(deg == -1) deg = this->size();\n\
    \        // g_p mod x^k \u304B\u3089 g mod x^2k \u3092\u30CB\u30E5\u30FC\u30C8\
    \u30F3\u6CD5\u3067\u6C42\u3081\u308B\n        // log g = f (mod x^n) \u3067\u3042\
    \u308B\u304B\u3089\u3001\n        // g = g_p - (log g_p - f)/(log' g_p)\n    \
    \    //   = g_p(1 - log g_p + f) (mod x^2k)\n        FPS res({T(1)});\n      \
    \  for(int i = 1; i < deg; i <<= 1) {\n            res = (res * (-res.log(i <<\
    \ 1) + pre(i << 1) + T(1))).pre(i << 1);\n        }\n        return res.pre(deg);\n\
    \    }\n\n    // g = f^k \u3068\u306A\u308B g\n    FPS pow(long long k, int deg\
    \ = -1) const {\n        if(deg == -1) deg = this->size();\n        if(k == 0){\n\
    \            FPS res(deg, T(0));\n            res[0] = T(1);\n            return\
    \ res;\n        }\n        // f^k = exp(log f)^k = exp(k log f)\n        // log\
    \ \u3092\u8A08\u7B97\u3059\u308B\u306E\u306B\u5B9A\u6570\u9805\u304C 1 \u3067\u3042\
    \u308B\u5FC5\u8981\u304C\u3042\u308B\u306E\u3067\u8ABF\u6574\u3059\u308B\n   \
    \     // \u6700\u3082\u4F4E\u6B21\u306E\u9805\u3092 a x^i \u3068\u3057\u3066\u3001\
    (f / (a x^i))^k \u3092\u8A08\u7B97\u3057\u3066\u304B\u3089 (a x^i)^k \u3092\u639B\
    \u3051\u308B\n        for(int i = 0; i < (int) this->size(); i++){\n         \
    \   if(k * i > deg) return FPS(deg, T(0));\n            if((*this)[i] != T(0)){\n\
    \                T inv_i = T(1) / (*this)[i];\n                FPS res = ((((*this)\
    \ * inv_i) >> i).log() * k).exp() * ((*this)[i].pow(k));\n                res\
    \ = (res << (k * i)).pre(deg);\n                return res;\n            }\n \
    \       }\n        return *this;\n    }\n\n    long long sqrtT(const T a) const\
    \ {\n        const long long p = T::mod();\n        if(a == T(0) || a == T(1))\
    \ return a.val;\n        if(a.pow((p - 1) / 2) != T(1)) return -1LL;\n       \
    \ T b = 1;\n        while(b.pow((p - 1) / 2) == 1) b++;\n        // p - 1 = m\
    \ 2^e\n        long long m = p - 1;\n        int e = 0;\n        while(m % 2 ==\
    \ 0) m >>= 1, e++;\n        // x = a^((m + 1) / 2) (mod p)\n        T x = a.pow((m\
    \ - 1) / 2);\n        // y = a^{-1} x^2 (mod p)\n        T y = (a * x) * x;\n\
    \        x *= a;\n        T z = b.pow(m);\n        while(y != 1){\n          \
    \  int j = 0;\n            T t = y;\n            while(t != 1){\n            \
    \    t *= t;\n                j++;\n            }\n            z = z.pow(1LL <<\
    \ (e - j - 1));\n            x *= z;\n            z *= z;\n            y *= z;\n\
    \            e = j;\n        }\n        return x.val;\n    }\n\n    // g^2 = f\
    \ \u3068\u306A\u308B g\n    FPS sqrt(int deg = -1) const {\n        if(this->empty())\
    \ return {};\n        if(deg == -1) deg = this->size();\n        // inv \u3092\
    \u8A08\u7B97\u3059\u308B\u306E\u306B\u5B9A\u6570\u9805\u304C\u975E\u96F6\u3067\
    \u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\u306E\u3067\u8ABF\u6574\u3059\u308B\
    \n        if((*this)[0] == T(0)){\n            for(int i = 1; i < (int) this->size();\
    \ i++){\n                if((*this)[i] == T(0)) continue;\n                if(i\
    \ & 1) return {};\n                FPS res = (*this >> i).sqrt();\n          \
    \      if(res.empty()) return {};\n                res = res.pre(deg - i / 2)\
    \ << (i / 2);\n                return res;\n            }\n            FPS res(deg,\
    \ T(0));\n            return res;\n        }\n        // g_p mod x^k \u304B\u3089\
    \ g mod x^2k \u3092\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\u3067\u6C42\u3081\u308B\
    \n        // g^2 = f (mod x^n) \u3067\u3042\u308B\u304B\u3089\u3001\n        //\
    \ g = g_p - ((g_p)^2 - f)/((g_p^2)')\n        //   = g_p - ((g_p)^2 - f)/(2 g_p)\n\
    \        //   = 1/2 * (g_p + f/g_p (mod x^2k)\n        long long sqrt0 = sqrtT((*this)[0]);\n\
    \        if(sqrt0 == -1) return {};\n        FPS res({T(sqrt0)});\n        T inv2\
    \ = T(1) / T(2);\n        for(int i = 1; i < deg; i <<= 1) {\n            res\
    \ = (res + pre(i << 1) * res.inv(i << 1)) * inv2;\n        }\n        return res.pre(deg);\n\
    \    }\n};\n#line 5 \"lib/polynomial/product_of_polynomial_sequence.hpp\"\n\n\
    template <typename T>\nFormalPowerSeries<T> product(const std::vector<FormalPowerSeries<T>>\
    \ &f){\n    auto dfs = [&](auto &self, int l, int r) -> FormalPowerSeries<T> {\n\
    \        if(r - l == 1) return f[l];\n        if(r - l == 0) return {T(1)};\n\
    \        int mid = (l + r) / 2;\n        return self(self, l, mid) * self(self,\
    \ mid, r);\n    };\n    return dfs(dfs, 0, (int) f.size());\n}\n"
  code: "#pragma once\n\n#include \"../polynomial/formal_power_series.hpp\"\n#include\
    \ <vector>\n\ntemplate <typename T>\nFormalPowerSeries<T> product(const std::vector<FormalPowerSeries<T>>\
    \ &f){\n    auto dfs = [&](auto &self, int l, int r) -> FormalPowerSeries<T> {\n\
    \        if(r - l == 1) return f[l];\n        if(r - l == 0) return {T(1)};\n\
    \        int mid = (l + r) / 2;\n        return self(self, l, mid) * self(self,\
    \ mid, r);\n    };\n    return dfs(dfs, 0, (int) f.size());\n}\n"
  dependsOn:
  - lib/polynomial/formal_power_series.hpp
  - lib/convolution/ntt.hpp
  - lib/math/modint.hpp
  - lib/math/crt.hpp
  isVerificationFile: false
  path: lib/polynomial/product_of_polynomial_sequence.hpp
  requiredBy: []
  timestamp: '2024-11-05 00:02:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
documentation_of: lib/polynomial/product_of_polynomial_sequence.hpp
layout: document
redirect_from:
- /library/lib/polynomial/product_of_polynomial_sequence.hpp
- /library/lib/polynomial/product_of_polynomial_sequence.hpp.html
title: lib/polynomial/product_of_polynomial_sequence.hpp
---
