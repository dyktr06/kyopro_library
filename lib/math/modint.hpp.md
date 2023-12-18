---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/library_checker/matrix/pow_of_matrix.cpp
    title: test/library_checker/matrix/pow_of_matrix.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/bitwise_and_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/queue_operate_all_composite.test.cpp
    title: test/library_checker/data_structure/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/vertex_set_path_composite.test.cpp
    title: test/library_checker/data_structure/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/inverse_matrix.test.cpp
    title: test/library_checker/matrix/inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_det.test.cpp
    title: test/library_checker/matrix/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_product.test.cpp
    title: test/library_checker/matrix/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/tree_path_composite_sum.test.cpp
    title: test/library_checker/tree/tree_path_composite_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/modint.md
    document_title: ModInt
    links: []
  bundledCode: "#line 2 \"lib/math/modint.hpp\"\n\n/**\n * @brief ModInt\n * @docs\
    \ docs/math/modint.md\n */\n\ntemplate <long long Modulus>\nstruct ModInt{\n \
    \   long long val;\n    constexpr ModInt(const long long _val = 0) noexcept :\
    \ val(_val) {\n        normalize();\n    }\n    void normalize(){\n        val\
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
    \ pow(long long n){\n        assert(0 <= n);\n        ModInt x = *this, r = 1;\n\
    \        while(n){\n            if(n & 1) r *= x;\n            x *= x;\n     \
    \       n >>= 1;\n        }\n        return r;\n    }\n    ModInt inv(const long\
    \ long n) const {\n        long long a = n, b = Modulus, u = 1, v = 0;\n     \
    \   while(b){\n            long long t = a / b;\n            a -= t * b; swap(a,\
    \ b);\n            u -= t * v; swap(u, v);\n        }\n        u %= Modulus;\n\
    \        if(u < 0) u += Modulus;\n        return u;\n    }\n    friend inline\
    \ ModInt operator+(const ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs)\
    \ += rhs; }\n    friend inline ModInt operator-(const ModInt& lhs, const ModInt&\
    \ rhs) noexcept { return ModInt(lhs) -= rhs; }\n    friend inline ModInt operator*(const\
    \ ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) *= rhs; }\n  \
    \  friend inline ModInt operator/(const ModInt& lhs, const ModInt& rhs) noexcept\
    \ { return ModInt(lhs) /= rhs; }\n    friend inline bool operator==(const ModInt&\
    \ lhs, const ModInt& rhs) noexcept { return lhs.val == rhs.val; }\n    friend\
    \ inline bool operator!=(const ModInt& lhs, const ModInt& rhs) noexcept { return\
    \ lhs.val != rhs.val; }\n    friend inline istream& operator>>(istream& is, ModInt&\
    \ x) noexcept {\n        is >> x.val;\n        x.normalize();\n        return\
    \ is;\n    }\n    friend inline ostream& operator<<(ostream& os, const ModInt&\
    \ x) noexcept { return os << x.val; }\n};\n"
  code: "#pragma once\n\n/**\n * @brief ModInt\n * @docs docs/math/modint.md\n */\n\
    \ntemplate <long long Modulus>\nstruct ModInt{\n    long long val;\n    constexpr\
    \ ModInt(const long long _val = 0) noexcept : val(_val) {\n        normalize();\n\
    \    }\n    void normalize(){\n        val = (val % Modulus + Modulus) % Modulus;\n\
    \    }\n    inline ModInt& operator+=(const ModInt& rhs) noexcept {\n        if(val\
    \ += rhs.val, val >= Modulus) val -= Modulus;\n        return *this;\n    }\n\
    \    inline ModInt& operator-=(const ModInt& rhs) noexcept {\n        if(val -=\
    \ rhs.val, val < 0) val += Modulus;\n        return *this;\n    }\n    inline\
    \ ModInt& operator*=(const ModInt& rhs) noexcept {\n        val = val * rhs.val\
    \ % Modulus;\n        return *this;\n    }\n    inline ModInt& operator/=(const\
    \ ModInt& rhs) noexcept {\n        val = val * inv(rhs.val).val % Modulus;\n \
    \       return *this;\n    }\n    inline ModInt& operator++() noexcept {\n   \
    \     if(++val >= Modulus) val -= Modulus;\n        return *this;\n    }\n   \
    \ inline ModInt operator++(int) noexcept {\n        ModInt t = val;\n        if(++val\
    \ >= Modulus) val -= Modulus;\n        return t;\n    }\n    inline ModInt& operator--()\
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
    \ ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) += rhs; }\n  \
    \  friend inline ModInt operator-(const ModInt& lhs, const ModInt& rhs) noexcept\
    \ { return ModInt(lhs) -= rhs; }\n    friend inline ModInt operator*(const ModInt&\
    \ lhs, const ModInt& rhs) noexcept { return ModInt(lhs) *= rhs; }\n    friend\
    \ inline ModInt operator/(const ModInt& lhs, const ModInt& rhs) noexcept { return\
    \ ModInt(lhs) /= rhs; }\n    friend inline bool operator==(const ModInt& lhs,\
    \ const ModInt& rhs) noexcept { return lhs.val == rhs.val; }\n    friend inline\
    \ bool operator!=(const ModInt& lhs, const ModInt& rhs) noexcept { return lhs.val\
    \ != rhs.val; }\n    friend inline istream& operator>>(istream& is, ModInt& x)\
    \ noexcept {\n        is >> x.val;\n        x.normalize();\n        return is;\n\
    \    }\n    friend inline ostream& operator<<(ostream& os, const ModInt& x) noexcept\
    \ { return os << x.val; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/modint.hpp
  requiredBy:
  - test/library_checker/matrix/pow_of_matrix.cpp
  timestamp: '2023-12-18 11:09:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/matrix/matrix_product.test.cpp
  - test/library_checker/matrix/inverse_matrix.test.cpp
  - test/library_checker/matrix/matrix_det.test.cpp
  - test/library_checker/convolution/bitwise_xor_convolution.test.cpp
  - test/library_checker/convolution/bitwise_and_convolution.test.cpp
  - test/library_checker/data_structure/queue_operate_all_composite.test.cpp
  - test/library_checker/data_structure/vertex_set_path_composite.test.cpp
  - test/library_checker/tree/tree_path_composite_sum.test.cpp
documentation_of: lib/math/modint.hpp
layout: document
redirect_from:
- /library/lib/math/modint.hpp
- /library/lib/math/modint.hpp.html
title: ModInt
---
## ModInt

#### 概要

Modulus で割ったあまりの値を管理する構造体です。

四則演算や入出力が実装されています。

除算は Modulus と互いに素である値でないと行うことができないことに注意してください。