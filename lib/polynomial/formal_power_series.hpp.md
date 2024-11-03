---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: lib/polynomial/product_of_polynomial_sequence.hpp
    title: lib/polynomial/product_of_polynomial_sequence.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/polynomial/division_of_polynomials.test.cpp
    title: test/library_checker/polynomial/division_of_polynomials.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/exp_of_formal_power_series.test.cpp
    title: test/library_checker/polynomial/exp_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/inv_of_formal_power_series.test.cpp
    title: test/library_checker/polynomial/inv_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/log_of_formal_power_series.test.cpp
    title: test/library_checker/polynomial/log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/pow_of_formal_power_series.test.cpp
    title: test/library_checker/polynomial/pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
    title: test/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/sqrt_of_formal_power_series.test.cpp
    title: test/library_checker/polynomial/sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/polynomial/formal_power_series.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\ntemplate <typename T>\nstruct FormalPowerSeries\
    \ : std::vector<T> {\n    using std::vector<T>::vector;\n    using FPS = FormalPowerSeries;\n\
    \n    // deg \u6B21\u3068\u3057\u3066\u521D\u671F\u5316\n    FPS pre(int deg)\
    \ const {\n        FPS res(std::begin(*this), std::begin(*this) + std::min((int)\
    \ this->size(), deg));\n        if((int) res.size() < deg) res.resize(deg, T(0));\n\
    \        return res;\n    }\n\n    // deg \u6B21\u3068\u3057\u3066\u53CD\u8EE2\
    \n    FPS rev(int deg = -1) const {\n        FPS res(*this);\n        if(deg !=\
    \ -1) res.resize(deg, T(0));\n        std::reverse(std::begin(res), std::end(res));\n\
    \        return res;\n    }\n\n    void shrink() {\n        while(this->size()\
    \ && this->back() == T(0)) this->pop_back();\n    }\n\n    FPS operator+(const\
    \ T &rhs) const { return FPS(*this) += rhs; }\n    FPS operator+(const FPS &rhs)\
    \ const { return FPS(*this) += rhs; }\n    FPS operator-(const T &rhs) const {\
    \ return FPS(*this) -= rhs; }\n    FPS operator-(const FPS &rhs) const { return\
    \ FPS(*this) -= rhs; }\n    FPS operator*(const T &rhs) const { return FPS(*this)\
    \ *= rhs; }\n    FPS operator*(const FPS &rhs) const { return FPS(*this) *= rhs;\
    \ }\n    FPS operator/(const T &rhs) const { return FPS(*this) /= rhs; }\n   \
    \ FPS operator/(const FPS &rhs) const { return FPS(*this) /= rhs; }\n    FPS operator%(const\
    \ FPS &rhs) const { return FPS(*this) %= rhs; }\n    FPS operator-() const {\n\
    \        FPS res(this->size());\n        for(int i = 0; i < (int) this->size();\
    \ i++) res[i] = -(*this)[i];\n        return res;\n    }\n\n    FPS &operator+=(const\
    \ T &rhs){\n        if(this->empty()) this->resize(1);\n        (*this)[0] +=\
    \ rhs;\n        return *this;\n    }\n\n    FPS &operator-=(const T &rhs){\n \
    \       if(this->empty()) this->resize(1);\n        (*this)[0] -= rhs;\n     \
    \   return *this;\n    }\n\n    FPS &operator*=(const T &rhs){\n        for(auto\
    \ &x : *this) x *= rhs;\n        return *this;\n    }\n\n    FPS &operator/=(const\
    \ T &rhs){\n        for(auto &x : *this) x /= rhs;\n        return *this;\n  \
    \  }\n\n    FPS &operator+=(const FPS &rhs) noexcept {\n        if(this->size()\
    \ < rhs.size()) this->resize(rhs.size());\n        for(int i = 0; i < (int) rhs.size();\
    \ i++) (*this)[i] += rhs[i];\n        return *this;\n    }\n\n    FPS &operator-=(const\
    \ FPS &rhs) noexcept {\n        if(this->size() < rhs.size()) this->resize(rhs.size());\n\
    \        for(int i = 0; i < (int) rhs.size(); i++) (*this)[i] -= rhs[i];\n   \
    \     return *this;\n    }\n\n    FPS &operator*=(const FPS &rhs) noexcept {\n\
    \        auto res = NTT::convolution_mod(*this, rhs, T::mod());\n        return\
    \ *this = {std::begin(res), std::end(res)};\n    }\n\n    // f/g = f * (g.inv())\n\
    \    FPS &operator/=(const FPS &rhs) noexcept {\n        if(this->size() < rhs.size())\
    \ return *this = FPS();\n        const int n = this->size() - rhs.size() + 1;\n\
    \        return *this = (rev().pre(n) * rhs.rev().inv(n)).pre(n).rev(n);\n   \
    \ }\n\n    FPS &operator%=(const FPS &rhs) noexcept {\n        return *this -=\
    \ (*this / rhs) * rhs;\n    }\n\n    FPS operator>>(int deg) const {\n       \
    \ if((int) this->size() <= deg) return {};\n        FPS res(*this);\n        res.erase(std::begin(res),\
    \ std::begin(res) + deg);\n        return res;\n    }\n\n    FPS operator<<(int\
    \ deg) const {\n        FPS res(*this);\n        res.insert(std::begin(res), deg,\
    \ T(0));\n        return res;\n    }\n\n    // \u5FAE\u5206\n    FPS diff() const\
    \ {\n        const int n = this->size();\n        FPS res(std::max(0, n - 1));\n\
    \        for(int i = 1; i < n; i++) res[i - 1] = (*this)[i] * T(i);\n        return\
    \ res;\n    }\n\n    // \u7A4D\u5206\n    FPS integral() const {\n        const\
    \ int n = this->size();\n        FPS res(n + 1);\n        res[0] = T(0);\n   \
    \     for(int i = 0; i < n; i++) res[i + 1] = (*this)[i] / T(i + 1);\n       \
    \ return res;\n    }\n\n    // {lhs / rhs, lhs % rhs}\n    std::pair<FPS, FPS>\
    \ division(const FPS &rhs) const {\n        FPS q = *this / rhs;\n        FPS\
    \ r = *this - q * rhs;\n        q.shrink(), r.shrink();\n        return {q, r};\n\
    \    }\n\n    // fg = 1 (mod x^n) \u3068\u306A\u308B g\n    FPS inv(int deg =\
    \ -1) const {\n        assert((*this)[0] != T(0));\n        if(deg == -1) deg\
    \ = this->size();\n        // g_p mod x^k \u304B\u3089 g mod x^2k \u3092\u6C42\
    \u3081\u308B\n        // (g - g_p)^2 = g^2 - 2 g g_p + (g_p)^2 = 0 (mod x^2k)\n\
    \        // fg^2 - 2fg g_p + f (g_p)^2\n        // = g - 2(g_p) + f (g_p)^2 =\
    \ 0 (mod x^2k)\n        // g = 2(g_p) - f (g_p)^2 (mod x^2k)\n        FPS res({T(1)\
    \ / (*this)[0]});\n        for(int i = 1; i < deg; i <<= 1) {\n            res\
    \ = (res + res - res * res * pre(i << 1)).pre(i << 1);\n        }\n        return\
    \ res.pre(deg);\n    }\n\n    // g = log f \u3068\u306A\u308B g\n    FPS log(int\
    \ deg = -1) const {\n        assert((*this)[0] == T(1));\n        if(deg == -1)\
    \ deg = this->size();\n        // log f = integral((f' / f) dx)\n        return\
    \ (this->diff() * this->inv(deg)).pre(deg - 1).integral().pre(deg);\n    }\n\n\
    \    // g = exp(f) \u3068\u306A\u308B g\n    FPS exp(int deg = -1) const {\n \
    \       assert((*this)[0] == T(0));\n        if(deg == -1) deg = this->size();\n\
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
    \ & 1) return {};\n                FPS res = (*this >> i).sqrt().pre(deg - i /\
    \ 2);\n                res = res << (i / 2);\n                return res;\n  \
    \          }\n            FPS res(deg, T(0));\n            return res;\n     \
    \   }\n        // g_p mod x^k \u304B\u3089 g mod x^2k \u3092\u30CB\u30E5\u30FC\
    \u30C8\u30F3\u6CD5\u3067\u6C42\u3081\u308B\n        // g^2 = f (mod x^n) \u3067\
    \u3042\u308B\u304B\u3089\u3001\n        // g = g_p - ((g_p)^2 - f)/((g_p^2)')\n\
    \        //   = g_p - ((g_p)^2 - f)/(2 g_p)\n        //   = 1/2 * (g_p + f/g_p\
    \ (mod x^2k)\n        long long sqrt0 = sqrtT((*this)[0]);\n        if(sqrt0 ==\
    \ -1) return {};\n        FPS res({T(sqrt0)});\n        T inv2 = T(1) / T(2);\n\
    \        for(int i = 1; i < deg; i <<= 1) {\n            res = (res + pre(i <<\
    \ 1) * res.inv(i << 1)) * inv2;\n        }\n        return res.pre(deg);\n   \
    \ }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \ntemplate <typename T>\nstruct FormalPowerSeries : std::vector<T> {\n    using\
    \ std::vector<T>::vector;\n    using FPS = FormalPowerSeries;\n\n    // deg \u6B21\
    \u3068\u3057\u3066\u521D\u671F\u5316\n    FPS pre(int deg) const {\n        FPS\
    \ res(std::begin(*this), std::begin(*this) + std::min((int) this->size(), deg));\n\
    \        if((int) res.size() < deg) res.resize(deg, T(0));\n        return res;\n\
    \    }\n\n    // deg \u6B21\u3068\u3057\u3066\u53CD\u8EE2\n    FPS rev(int deg\
    \ = -1) const {\n        FPS res(*this);\n        if(deg != -1) res.resize(deg,\
    \ T(0));\n        std::reverse(std::begin(res), std::end(res));\n        return\
    \ res;\n    }\n\n    void shrink() {\n        while(this->size() && this->back()\
    \ == T(0)) this->pop_back();\n    }\n\n    FPS operator+(const T &rhs) const {\
    \ return FPS(*this) += rhs; }\n    FPS operator+(const FPS &rhs) const { return\
    \ FPS(*this) += rhs; }\n    FPS operator-(const T &rhs) const { return FPS(*this)\
    \ -= rhs; }\n    FPS operator-(const FPS &rhs) const { return FPS(*this) -= rhs;\
    \ }\n    FPS operator*(const T &rhs) const { return FPS(*this) *= rhs; }\n   \
    \ FPS operator*(const FPS &rhs) const { return FPS(*this) *= rhs; }\n    FPS operator/(const\
    \ T &rhs) const { return FPS(*this) /= rhs; }\n    FPS operator/(const FPS &rhs)\
    \ const { return FPS(*this) /= rhs; }\n    FPS operator%(const FPS &rhs) const\
    \ { return FPS(*this) %= rhs; }\n    FPS operator-() const {\n        FPS res(this->size());\n\
    \        for(int i = 0; i < (int) this->size(); i++) res[i] = -(*this)[i];\n \
    \       return res;\n    }\n\n    FPS &operator+=(const T &rhs){\n        if(this->empty())\
    \ this->resize(1);\n        (*this)[0] += rhs;\n        return *this;\n    }\n\
    \n    FPS &operator-=(const T &rhs){\n        if(this->empty()) this->resize(1);\n\
    \        (*this)[0] -= rhs;\n        return *this;\n    }\n\n    FPS &operator*=(const\
    \ T &rhs){\n        for(auto &x : *this) x *= rhs;\n        return *this;\n  \
    \  }\n\n    FPS &operator/=(const T &rhs){\n        for(auto &x : *this) x /=\
    \ rhs;\n        return *this;\n    }\n\n    FPS &operator+=(const FPS &rhs) noexcept\
    \ {\n        if(this->size() < rhs.size()) this->resize(rhs.size());\n       \
    \ for(int i = 0; i < (int) rhs.size(); i++) (*this)[i] += rhs[i];\n        return\
    \ *this;\n    }\n\n    FPS &operator-=(const FPS &rhs) noexcept {\n        if(this->size()\
    \ < rhs.size()) this->resize(rhs.size());\n        for(int i = 0; i < (int) rhs.size();\
    \ i++) (*this)[i] -= rhs[i];\n        return *this;\n    }\n\n    FPS &operator*=(const\
    \ FPS &rhs) noexcept {\n        auto res = NTT::convolution_mod(*this, rhs, T::mod());\n\
    \        return *this = {std::begin(res), std::end(res)};\n    }\n\n    // f/g\
    \ = f * (g.inv())\n    FPS &operator/=(const FPS &rhs) noexcept {\n        if(this->size()\
    \ < rhs.size()) return *this = FPS();\n        const int n = this->size() - rhs.size()\
    \ + 1;\n        return *this = (rev().pre(n) * rhs.rev().inv(n)).pre(n).rev(n);\n\
    \    }\n\n    FPS &operator%=(const FPS &rhs) noexcept {\n        return *this\
    \ -= (*this / rhs) * rhs;\n    }\n\n    FPS operator>>(int deg) const {\n    \
    \    if((int) this->size() <= deg) return {};\n        FPS res(*this);\n     \
    \   res.erase(std::begin(res), std::begin(res) + deg);\n        return res;\n\
    \    }\n\n    FPS operator<<(int deg) const {\n        FPS res(*this);\n     \
    \   res.insert(std::begin(res), deg, T(0));\n        return res;\n    }\n\n  \
    \  // \u5FAE\u5206\n    FPS diff() const {\n        const int n = this->size();\n\
    \        FPS res(std::max(0, n - 1));\n        for(int i = 1; i < n; i++) res[i\
    \ - 1] = (*this)[i] * T(i);\n        return res;\n    }\n\n    // \u7A4D\u5206\
    \n    FPS integral() const {\n        const int n = this->size();\n        FPS\
    \ res(n + 1);\n        res[0] = T(0);\n        for(int i = 0; i < n; i++) res[i\
    \ + 1] = (*this)[i] / T(i + 1);\n        return res;\n    }\n\n    // {lhs / rhs,\
    \ lhs % rhs}\n    std::pair<FPS, FPS> division(const FPS &rhs) const {\n     \
    \   FPS q = *this / rhs;\n        FPS r = *this - q * rhs;\n        q.shrink(),\
    \ r.shrink();\n        return {q, r};\n    }\n\n    // fg = 1 (mod x^n) \u3068\
    \u306A\u308B g\n    FPS inv(int deg = -1) const {\n        assert((*this)[0] !=\
    \ T(0));\n        if(deg == -1) deg = this->size();\n        // g_p mod x^k \u304B\
    \u3089 g mod x^2k \u3092\u6C42\u3081\u308B\n        // (g - g_p)^2 = g^2 - 2 g\
    \ g_p + (g_p)^2 = 0 (mod x^2k)\n        // fg^2 - 2fg g_p + f (g_p)^2\n      \
    \  // = g - 2(g_p) + f (g_p)^2 = 0 (mod x^2k)\n        // g = 2(g_p) - f (g_p)^2\
    \ (mod x^2k)\n        FPS res({T(1) / (*this)[0]});\n        for(int i = 1; i\
    \ < deg; i <<= 1) {\n            res = (res + res - res * res * pre(i << 1)).pre(i\
    \ << 1);\n        }\n        return res.pre(deg);\n    }\n\n    // g = log f \u3068\
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
    \ & 1) return {};\n                FPS res = (*this >> i).sqrt().pre(deg - i /\
    \ 2);\n                res = res << (i / 2);\n                return res;\n  \
    \          }\n            FPS res(deg, T(0));\n            return res;\n     \
    \   }\n        // g_p mod x^k \u304B\u3089 g mod x^2k \u3092\u30CB\u30E5\u30FC\
    \u30C8\u30F3\u6CD5\u3067\u6C42\u3081\u308B\n        // g^2 = f (mod x^n) \u3067\
    \u3042\u308B\u304B\u3089\u3001\n        // g = g_p - ((g_p)^2 - f)/((g_p^2)')\n\
    \        //   = g_p - ((g_p)^2 - f)/(2 g_p)\n        //   = 1/2 * (g_p + f/g_p\
    \ (mod x^2k)\n        long long sqrt0 = sqrtT((*this)[0]);\n        if(sqrt0 ==\
    \ -1) return {};\n        FPS res({T(sqrt0)});\n        T inv2 = T(1) / T(2);\n\
    \        for(int i = 1; i < deg; i <<= 1) {\n            res = (res + pre(i <<\
    \ 1) * res.inv(i << 1)) * inv2;\n        }\n        return res.pre(deg);\n   \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/polynomial/formal_power_series.hpp
  requiredBy:
  - lib/polynomial/product_of_polynomial_sequence.hpp
  timestamp: '2024-11-03 22:42:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/polynomial/inv_of_formal_power_series.test.cpp
  - test/library_checker/polynomial/pow_of_formal_power_series.test.cpp
  - test/library_checker/polynomial/log_of_formal_power_series.test.cpp
  - test/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
  - test/library_checker/polynomial/exp_of_formal_power_series.test.cpp
  - test/library_checker/polynomial/division_of_polynomials.test.cpp
  - test/library_checker/polynomial/sqrt_of_formal_power_series.test.cpp
documentation_of: lib/polynomial/formal_power_series.hpp
layout: document
redirect_from:
- /library/lib/polynomial/formal_power_series.hpp
- /library/lib/polynomial/formal_power_series.hpp.html
title: lib/polynomial/formal_power_series.hpp
---
