---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/queue_operate_all_composite.test.cpp
    title: test/library_checker/data_structure/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/vertex_set_path_composite.test.cpp
    title: test/library_checker/data_structure/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/modint.hpp\"\n\ntemplate <long long Modulus>\n\
    struct ModInt{\n    long long val;\n    constexpr ModInt(const long long &_val\
    \ = 0) noexcept : val(_val) {\n        normalize();\n    }\n    void normalize(){\n\
    \        val = (val % Modulus + Modulus) % Modulus;\n    }\n    inline ModInt&\
    \ operator+=(const ModInt& rhs) noexcept {\n        if(val += rhs.val, val >=\
    \ Modulus) val -= Modulus;\n        return *this;\n    }\n    inline ModInt& operator-=(const\
    \ ModInt& rhs) noexcept {\n        if(val -= rhs.val, val < 0) val += Modulus;\n\
    \        return *this;\n    }\n    inline ModInt& operator*=(const ModInt& rhs)\
    \ noexcept {\n        val = val * rhs.val % Modulus;\n        return *this;\n\
    \    }\n    inline ModInt& operator/=(const ModInt& rhs) noexcept {\n        val\
    \ = val * inv(rhs.val).val % Modulus;\n        return *this;\n    }\n    inline\
    \ ModInt& operator++() noexcept {\n        if(++val >= Modulus) val -= Modulus;\n\
    \        return *this;\n    }\n    inline ModInt operator++(int) noexcept {\n\
    \        ModInt t = val;\n        if(++val >= Modulus) val -= Modulus;\n     \
    \   return t;\n    }\n    inline ModInt& operator--() noexcept {\n        if(--val\
    \ < 0) val += Modulus;\n        return *this;\n    }\n    inline ModInt operator--(int)\
    \ noexcept {\n        ModInt t = val;\n        if(--val < 0) val += Modulus;\n\
    \        return t;\n    }\n    inline ModInt operator-() const noexcept { return\
    \ (Modulus - val) % Modulus; }\n    inline ModInt inv(void) const { return inv(val);\
    \ }\n    ModInt inv(const long long& n) const {\n        long long a = n, b =\
    \ Modulus, u = 1, v = 0;\n        while(b){\n            long long t = a / b;\n\
    \            a -= t * b; swap(a, b);\n            u -= t * v; swap(u, v);\n  \
    \      }\n        u %= Modulus;\n        if(u < 0) u += Modulus;\n        return\
    \ u;\n    }\n    friend inline ModInt operator+(const ModInt& lhs, const ModInt&\
    \ rhs) noexcept { return ModInt(lhs) += rhs; }\n    friend inline ModInt operator-(const\
    \ ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) -= rhs; }\n  \
    \  friend inline ModInt operator*(const ModInt& lhs, const ModInt& rhs) noexcept\
    \ { return ModInt(lhs) *= rhs; }\n    friend inline ModInt operator/(const ModInt&\
    \ lhs, const ModInt& rhs) noexcept { return ModInt(lhs) /= rhs; }\n    friend\
    \ inline bool operator==(const ModInt& lhs, const ModInt& rhs) noexcept { return\
    \ lhs.val == rhs.val; }\n    friend inline bool operator!=(const ModInt& lhs,\
    \ const ModInt& rhs) noexcept { return lhs.val != rhs.val; }\n    friend inline\
    \ istream& operator>>(istream& is, ModInt& x) noexcept {\n        is >> x.val;\n\
    \        x.normalize();\n        return is;\n    }\n    friend inline ostream&\
    \ operator<<(ostream& os, const ModInt& x) noexcept { return os << x.val; }\n\
    };\n"
  code: "#pragma once\n\ntemplate <long long Modulus>\nstruct ModInt{\n    long long\
    \ val;\n    constexpr ModInt(const long long &_val = 0) noexcept : val(_val) {\n\
    \        normalize();\n    }\n    void normalize(){\n        val = (val % Modulus\
    \ + Modulus) % Modulus;\n    }\n    inline ModInt& operator+=(const ModInt& rhs)\
    \ noexcept {\n        if(val += rhs.val, val >= Modulus) val -= Modulus;\n   \
    \     return *this;\n    }\n    inline ModInt& operator-=(const ModInt& rhs) noexcept\
    \ {\n        if(val -= rhs.val, val < 0) val += Modulus;\n        return *this;\n\
    \    }\n    inline ModInt& operator*=(const ModInt& rhs) noexcept {\n        val\
    \ = val * rhs.val % Modulus;\n        return *this;\n    }\n    inline ModInt&\
    \ operator/=(const ModInt& rhs) noexcept {\n        val = val * inv(rhs.val).val\
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
    \ ModInt& x) noexcept { return os << x.val; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/modint.hpp
  requiredBy: []
  timestamp: '2022-11-10 02:54:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/queue_operate_all_composite.test.cpp
  - test/library_checker/data_structure/vertex_set_path_composite.test.cpp
documentation_of: lib/math/modint.hpp
layout: document
redirect_from:
- /library/lib/math/modint.hpp
- /library/lib/math/modint.hpp.html
title: lib/math/modint.hpp
---
