---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/bigint.hpp
    title: "BigInt (\u591A\u500D\u9577\u6574\u6570)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_D
  bundledCode: "#line 1 \"test/aoj/ntl/ntl_2_d.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_D\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/bigint.hpp\"\
    \n\n/**\n * @brief BigInt (\u591A\u500D\u9577\u6574\u6570)\n * @docs docs/math/bigint.md\n\
    \ */\n\ntemplate <long long base = 1000000LL, int digit = 6>\nstruct BigInt{\n\
    \    int sign = 1;\n    vector<long long> val;\n\n    constexpr BigInt(const long\
    \ long _val = 0) noexcept {\n        if(_val != 0){\n            val.assign(1,\
    \ abs(_val));\n            shift();\n        }\n        if(_val < 0) sign = -1;\n\
    \    }\n    constexpr BigInt(const vector<long long> &_val) noexcept : val(_val)\
    \ {}\n    constexpr BigInt(const string &s) noexcept {\n        stoi(s);\n   \
    \ }\n\nprivate:\n    void normalize(){\n        while(!val.empty() && val.back()\
    \ == 0) val.pop_back();\n        if(val.empty()) sign = 1;\n    }\n    vector<long\
    \ long> karatsuba_algorithm(vector<long long> &a, vector<long long> &b){\n   \
    \     const int n = (int) a.size();\n        const int h = n >> 1;\n        assert(a.size()\
    \ == b.size());\n        assert((n & (n - 1)) == 0);\n        if(n <= 64){\n \
    \           vector<long long> res(2 * n - 1);\n            for(int i = 0; i <\
    \ n; ++i){\n                for(int j = 0; j < n; ++j){\n                    res[i\
    \ + j] += a[i] * b[j];\n                }\n            }\n            return res;\n\
    \        }\n        vector<long long> p(h), q(h), r(h), s(h), t(h), u(h);\n  \
    \      for(int i = 0; i < h; ++i){\n            p[i] = a[i + h];\n           \
    \ q[i] = a[i];\n            r[i] = b[i + h];\n            s[i] = b[i];\n     \
    \       t[i] = p[i] + q[i];\n            u[i] = r[i] + s[i];\n        }\n    \
    \    p = karatsuba_algorithm(p, r);\n        q = karatsuba_algorithm(q, s);\n\
    \        t = karatsuba_algorithm(t, u);\n        vector<long long> res(2 * n -\
    \ 1, 0);\n        for(int i = 0; i < n - 1; ++i){\n            res[i] += q[i];\n\
    \            res[i + h] += t[i] - p[i] - q[i];\n            res[i + n] += p[i];\n\
    \        }\n        return res;\n    }\n\n    pair<BigInt, BigInt> divide_naive(const\
    \ BigInt& rhs) const {\n        assert(!rhs.val.empty());\n        const int k\
    \ = base / (rhs.val.back() + 1);\n        const BigInt dividend = (sign == 1 ?\
    \ *this : -(*this)) * k;\n        const BigInt divisor = (rhs.sign == 1 ? rhs\
    \ : -rhs) * k;\n        BigInt quo, rem = 0;\n        quo.val.resize(dividend.val.size());\n\
    \        const int n = divisor.val.size();\n        for(int i = (int) dividend.val.size()\
    \ - 1; i >= 0; --i){\n            rem.val.emplace(rem.val.begin(), dividend.val[i]);\n\
    \            quo.val[i] = ((n < (int) rem.val.size() ? rem.val[n] * base : 0)\
    \ + ((n - 1) < (int) rem.val.size() ? rem.val[n - 1] : 0)) / divisor.val.back();\n\
    \            rem -= divisor * quo.val[i];\n            while (rem.sign == -1)\
    \ {\n                rem += divisor;\n                --quo.val[i];\n        \
    \    }\n        }\n        quo.sign = sign * rhs.sign;\n        quo.normalize();\n\
    \        rem.sign = sign;\n        rem.normalize();\n        return {quo, rem\
    \ / k};\n    }\n\n    pair<BigInt, BigInt> divide_newton(const BigInt& rhs) const\
    \ {\n        assert(!rhs.val.empty());\n        int preci = val.size() - rhs.val.size();\n\
    \        BigInt t(1);\n        BigInt two = BigInt(2) << rhs.val.size();\n   \
    \     BigInt pre;\n        int lim = min(preci, 3);\n        int rhslim = min(int(rhs.val.size()),\
    \ 6);\n        t <<= lim;\n        while(pre != t){\n            BigInt rb = rhs\
    \ >> (rhs.val.size() - rhslim);\n            if(rhslim != (int) rhs.val.size())\
    \ rb += BigInt(1);\n            pre = t;\n            t *= (BigInt(2) << (rhslim\
    \ + lim)) - rb * t;\n            t.val = vector<long long>(t.val.begin() + lim\
    \ + rhslim, t.val.end());\n        }\n        if(lim != preci){\n            pre\
    \ = BigInt();\n            while(pre != t){\n                BigInt rb = rhs >>\
    \ (rhs.val.size() - rhslim);\n                if(rhslim != (int) rhs.val.size())\
    \ rb += BigInt(1);\n                pre = t;\n                t *= (BigInt(2)\
    \ << (rhslim + lim)) - rb * t;\n                t.val = vector<long long>(t.val.begin()\
    \ + lim + rhslim, t.val.end());\n                int next_lim = min(lim * 2 +\
    \ 1, preci);\n                if (next_lim != lim) t <<= next_lim - lim;\n   \
    \             int next_rhslim = min(rhslim * 2 + 1, int(rhs.val.size()));\n  \
    \              lim = next_lim;\n                rhslim = next_rhslim;\n      \
    \      }\n        }\n        BigInt quo = (*this) * t;\n        quo.val = vector<long\
    \ long>(quo.val.begin() + val.size(), quo.val.end());\n        BigInt mul = quo\
    \ * rhs;\n        while(mul + rhs <= (*this)){\n            quo += BigInt(1);\n\
    \            mul += rhs;\n        }\n        BigInt rem = *this - quo * rhs;\n\
    \        return {quo, rem};\n    }\n\npublic:\n    void stoi(const string &s){\n\
    \        if(s == \"0\") return;\n        int n = s.size(), idx = 0;\n        if(s[0]\
    \ == '-'){\n            n -= 1;\n            sign = -1;\n            idx = 1;\n\
    \        }\n        int len = (n + digit - 1) / digit, rem = n % digit;\n    \
    \    if(rem == 0) rem += digit;\n        val.resize(len);\n        for(int i =\
    \ len - 1; i >= 0; --i){\n            if(i == len - 1){\n                val[i]\
    \ = stoll(s.substr(idx, rem));\n                idx += rem;\n            }else{\n\
    \                val[i] = stoll(s.substr(idx, digit));\n                idx +=\
    \ digit;\n            }\n        }\n    }\n    string itos() const {\n       \
    \ string res = \"\";\n        if(sign == -1) res += \"-\";\n        bool flag\
    \ = false;\n        for(int i = (int) val.size() - 1; i >= 0; --i){\n        \
    \    if(val[i] > 0 && !flag){\n                res += to_string(val[i]);\n   \
    \             flag = true;\n            }else if(flag){\n                string\
    \ rem = to_string(val[i]);\n                res += string(digit - rem.size(),\
    \ '0') + rem;\n            }\n        }\n        return (res.empty() || res ==\
    \ \"-\") ? \"0\" : res;\n    }\n    pair<BigInt, BigInt> divide_mod(const BigInt&\
    \ rhs){\n        assert(!rhs.val.empty());\n        BigInt div = *this / rhs;\n\
    \        return make_pair(div, *this - div * rhs);\n    }\n    BigInt& shift(){\n\
    \        for(int i = 0; i < (int) val.size() - 1; ++i){\n            if(val[i]\
    \ >= 0){\n                val[i + 1] += val[i] / base;\n                val[i]\
    \ %= base;\n            }else{\n                long long x = (-val[i] + base\
    \ - 1) / base;\n                val[i] += x * base;\n                val[i + 1]\
    \ -= x;\n            }\n        }\n        while(val.back() >= base){\n      \
    \      val.emplace_back(val.back() / base);\n            val[val.size() - 2] %=\
    \ base;\n        }\n        return *this;\n    }\n    BigInt& operator=(const\
    \ BigInt& x) = default;\n    inline BigInt& operator+=(const BigInt& rhs) noexcept\
    \ {\n        if(rhs.val.empty()) return *this;\n        if(sign != rhs.sign) return\
    \ *this -= -rhs;\n        if(val.size() < rhs.val.size()){\n            val.resize(rhs.val.size());\n\
    \        }\n        for(int i = 0; i < (int) rhs.val.size(); ++i){\n         \
    \   val[i] += rhs.val[i];\n        }\n        return (*this).shift();\n    }\n\
    \    inline BigInt& operator-=(const BigInt& rhs) noexcept {\n        if(rhs.val.empty())\
    \ return *this;\n        if(sign != rhs.sign) return *this += -rhs;\n        if((sign\
    \ == 1 ? *this : -(*this)) < (rhs.sign == 1 ? rhs : -rhs)){\n            return\
    \ *this = -(rhs - *this);\n        }\n        for(int i = 0; i < (int) rhs.val.size();\
    \ ++i){\n            val[i] -= rhs.val[i];\n        }\n        \n        shift();\n\
    \        normalize();\n        return *this;\n    }\n    // Karatsuba Algorithm\
    \ (O(N^(1.58)))\n    inline BigInt& operator*=(const BigInt& rhs) noexcept {\n\
    \        if(val.empty() || rhs.val.empty()){\n            return *this = BigInt();\n\
    \        }\n\n        sign *= rhs.sign;\n        vector<long long> rhsval = rhs.val;\n\
    \        int k = 1;\n        while(k < (int) max(val.size(), rhsval.size())){\n\
    \            k *= 2;\n        }\n        val.resize(k), rhsval.resize(k);\n  \
    \      val = karatsuba_algorithm(val, rhsval);\n\n        shift();\n        normalize();\n\
    \        return *this;\n    }\n    // Newton method\n    inline BigInt& operator/=(const\
    \ BigInt& rhst) noexcept {\n        assert(!rhst.val.empty());\n        if(val.empty())\
    \ return *this;\n        if((int) val.size() <= 32 && (int) rhst.val.size() <=\
    \ 32){\n            return *this = divide_naive(rhst).first;\n        }\n\n  \
    \      BigInt rhs = rhst;\n        int mulsign = sign * rhs.sign;\n        sign\
    \ = 1, rhs.sign = 1;\n        if(*this < rhs){\n            return *this = BigInt();\n\
    \        }\n\n        *this = divide_newton(rhs).first;\n        sign = mulsign;\n\
    \        normalize();\n        return *this;\n    }\n    inline BigInt& operator%=(const\
    \ BigInt& rhs) noexcept {\n        assert(!rhs.val.empty());\n        return *this\
    \ = *this - (*this / rhs) * rhs;\n    }\n    inline BigInt& operator++() { return\
    \ *this += 1; }\n    inline BigInt operator++(int) {\n        const BigInt res\
    \ = *this;\n        ++(*this);\n        return res;\n    }\n    inline BigInt&\
    \ operator--() { return *this -= 1; }\n    inline BigInt operator--(int) {\n \
    \       const BigInt res = *this;\n        --(*this);\n        return res;\n \
    \   }\n    inline BigInt operator+() const { return *this; }\n    inline BigInt\
    \ operator-() const {\n        BigInt res = *this;\n        if (!res.val.empty())\
    \ res.sign = -res.sign;\n        return res;\n    }\n    inline BigInt& operator<<=(const\
    \ unsigned int rhs){\n        if(val.back() >= 1 || (int) val.size() >= 2){\n\
    \            vector<long long> tmp(rhs, 0);\n            val.insert(val.begin(),\
    \ tmp.begin(), tmp.end());\n        }\n        return *this;\n    }\n    inline\
    \ BigInt& operator>>=(const unsigned int rhs){\n        if(rhs == 0) return *this;\n\
    \        if(rhs > val.size()) val = {0};\n        else val = vector<long long>(val.begin()\
    \ + rhs, val.end()); \n        return *this;\n    }\n    inline bool operator<(const\
    \ BigInt& rhs) const {\n        if(sign != rhs.sign) return sign < rhs.sign;\n\
    \        if(val.size() != rhs.val.size()) return sign * val.size() < rhs.sign\
    \ * rhs.val.size();\n        for(int i = (int) val.size() - 1; i >= 0; --i){\n\
    \            if(val[i] != rhs.val[i]) return sign * val[i] < rhs.sign * rhs.val[i];\n\
    \        }\n        return false;\n    }\n    inline bool operator>(const BigInt&\
    \ rhs) const { return rhs < (*this); }\n    inline bool operator<=(const BigInt&\
    \ rhs) const { return !((*this) > rhs); }\n    inline bool operator>=(const BigInt&\
    \ rhs) const { return !((*this) < rhs); }\n    friend inline BigInt operator+(const\
    \ BigInt& lhs, const BigInt& rhs) noexcept { return BigInt(lhs) += rhs; }\n  \
    \  friend inline BigInt operator-(const BigInt& lhs, const BigInt& rhs) noexcept\
    \ { return BigInt(lhs) -= rhs; }\n    friend inline BigInt operator*(const BigInt&\
    \ lhs, const BigInt& rhs) noexcept { return BigInt(lhs) *= rhs; }\n    friend\
    \ inline BigInt operator/(const BigInt& lhs, const BigInt& rhs) noexcept { return\
    \ BigInt(lhs) /= rhs; }\n    friend inline BigInt operator%(const BigInt& lhs,\
    \ const BigInt& rhs) noexcept { return BigInt(lhs) %= rhs; }\n    friend inline\
    \ BigInt operator<<(const BigInt& lhs, const unsigned int rhs) noexcept { return\
    \ BigInt(lhs) <<= rhs; }\n    friend inline BigInt operator>>(const BigInt& lhs,\
    \ const unsigned int rhs) noexcept { return BigInt(lhs) >>= rhs; }\n    friend\
    \ inline bool operator==(const BigInt& lhs, const BigInt& rhs) noexcept { return\
    \ lhs.val == rhs.val; }\n    friend inline bool operator!=(const BigInt& lhs,\
    \ const BigInt& rhs) noexcept { return lhs.val != rhs.val; }\n    friend inline\
    \ istream& operator>>(istream& is, BigInt& x) noexcept {\n        string s;\n\
    \        is >> s;\n        x.stoi(s);\n        return is;\n    }\n    friend inline\
    \ ostream& operator<<(ostream& os, const BigInt& x) noexcept { return os << x.itos();\
    \ }\n};\n#line 6 \"test/aoj/ntl/ntl_2_d.test.cpp\"\n\nint main(){\n    BigInt\
    \ a, b; cin >> a >> b;\n    cout << a / b << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_D\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/bigint.hpp\"\
    \n\nint main(){\n    BigInt a, b; cin >> a >> b;\n    cout << a / b << \"\\n\"\
    ;\n}"
  dependsOn:
  - lib/math/bigint.hpp
  isVerificationFile: true
  path: test/aoj/ntl/ntl_2_d.test.cpp
  requiredBy: []
  timestamp: '2024-03-21 03:54:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ntl/ntl_2_d.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ntl/ntl_2_d.test.cpp
- /verify/test/aoj/ntl/ntl_2_d.test.cpp.html
title: test/aoj/ntl/ntl_2_d.test.cpp
---
