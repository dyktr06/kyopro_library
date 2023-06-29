---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/bigint.hpp
    title: lib/math/bigint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb_128bit
    links:
    - https://judge.yosupo.jp/problem/many_aplusb_128bit
  bundledCode: "#line 1 \"test/library_checker/sample/many_aplusb_128bit.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb_128bit\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/bigint.hpp\"\n\n\
    template <long long base = 1000000000LL, int digit = 9>\nstruct BigInt{\n    int\
    \ sign = 1;\n    vector<long long> val;\n\n    constexpr BigInt(const long long\
    \ &_val = 0) noexcept {\n        val.assign(1, _val);\n    }\n    constexpr BigInt(const\
    \ vector<long long> &_val) noexcept : val(_val) {}\n    constexpr BigInt(const\
    \ string &s) noexcept {\n        stoi(s);\n    }\n    void stoi(string &s){\n\
    \        int n = s.size(), idx = 0;\n        if(s[0] == '-'){\n            n -=\
    \ 1;\n            sign = -1;\n            idx = 1;\n        }\n        int len\
    \ = (n + digit - 1) / digit, rem = n % digit;\n        if(rem == 0) rem += digit;\n\
    \        val.resize(len);\n        for(int i = len - 1; i >= 0; --i){\n      \
    \      if(i == len - 1){\n                val[i] = stoll(s.substr(idx, rem));\n\
    \                idx += rem;\n            }else{\n                val[i] = stoll(s.substr(idx,\
    \ digit));\n                idx += digit;\n            }\n        }\n    }\n \
    \   string itos() const {\n        string res = \"\";\n        if(sign == -1)\
    \ res += \"-\";\n        bool flag = false;\n        for(int i = (int) val.size()\
    \ - 1; i >= 0; --i){\n            if(val[i] > 0 && !flag){\n                res\
    \ += to_string(val[i]);\n                flag = true;\n            }else if(flag){\n\
    \                string rem = to_string(val[i]);\n                res += string(digit\
    \ - rem.size(), '0') + rem;\n            }\n        }\n        return (res.empty()\
    \ || res == \"-\") ? \"0\" : res;\n    }\n    BigInt& shift(){\n        for(int\
    \ i = 0; i < (int) val.size() - 1; ++i){\n            if(val[i] >= 0){\n     \
    \           val[i + 1] += val[i] / base;\n                val[i] %= base;\n  \
    \          }else{\n                long long x = (-val[i] + base - 1) / base;\n\
    \                val[i] += x * base;\n                val[i + 1] -= x;\n     \
    \       }\n        }\n        while(val.back() >= base){\n            val.emplace_back(val.back()\
    \ / base);\n            val[val.size() - 2] %= base;\n        }\n        return\
    \ *this;\n    }\n    BigInt& operator=(const BigInt& x) = default;\n    inline\
    \ BigInt& operator+=(const BigInt& rhs) noexcept {\n        if(sign != rhs.sign)\
    \ return rhs.val.empty() ? *this : *this -= -rhs;\n        if(val.size() < rhs.val.size()){\n\
    \            val.resize(rhs.val.size());\n        }\n        for(int i = 0; i\
    \ < (int) rhs.val.size(); ++i){\n            val[i] += rhs.val[i];\n        }\n\
    \        return (*this).shift();\n    }\n    inline BigInt& operator-=(const BigInt&\
    \ rhs) noexcept {\n        if(sign != rhs.sign) return *this += -rhs;\n      \
    \  if((sign == 1 ? *this : -*this) < (rhs.sign == 1 ? rhs : -rhs)){\n        \
    \    return *this = -(rhs - *this);\n        }\n        for(int i = 0; i < (int)\
    \ rhs.val.size(); ++i){\n            val[i] -= rhs.val[i];\n        }\n      \
    \  \n        shift();\n        while(!val.empty() && val.back() == 0) val.pop_back();\n\
    \        if(val.empty()) sign = 1;\n        return *this;\n    }\n    inline BigInt&\
    \ operator++() { return *this += 1; }\n    inline BigInt operator++(int) {\n \
    \       const BigInt res = *this;\n        ++*this;\n        return res;\n   \
    \ }\n    inline BigInt& operator--() { return *this -= 1; }\n    inline BigInt\
    \ operator--(int) {\n        const BigInt res = *this;\n        --*this;\n   \
    \     return res;\n    }\n    inline BigInt operator+() const { return *this;\
    \ }\n    inline BigInt operator-() const {\n        BigInt res = *this;\n    \
    \    if (!res.val.empty()) res.sign = -res.sign;\n        return res;\n    }\n\
    \tinline bool operator<(const BigInt& rhs) const {\n        if(sign != rhs.sign)\
    \ return sign < rhs.sign;\n\t\tif(val.size() != rhs.val.size()) return sign *\
    \ val.size() < rhs.sign * rhs.val.size();\n\t\tfor(int i = (int) val.size() -\
    \ 1; i >= 0; --i){\n\t\t\tif(val[i] != rhs.val[i]) return sign * val[i] < rhs.sign\
    \ * rhs.val[i];\n\t\t}\n\t\treturn false;\n\t}\n\tinline bool operator>(const\
    \ BigInt& rhs) const { return rhs < (*this); }\n\tinline bool operator<=(const\
    \ BigInt& rhs) const { return !((*this) > rhs); }\n\tinline bool operator>=(const\
    \ BigInt& rhs) const { return !((*this) < rhs); }\n    friend inline BigInt operator+(const\
    \ BigInt& lhs, const BigInt& rhs) noexcept { return BigInt(lhs) += rhs; }\n  \
    \  friend inline BigInt operator-(const BigInt& lhs, const BigInt& rhs) noexcept\
    \ { return BigInt(lhs) -= rhs; }\n    friend inline bool operator==(const BigInt&\
    \ lhs, const BigInt& rhs) noexcept { return lhs.val == rhs.val; }\n    friend\
    \ inline bool operator!=(const BigInt& lhs, const BigInt& rhs) noexcept { return\
    \ lhs.val != rhs.val; }\n    friend inline istream& operator>>(istream& is, BigInt&\
    \ x) noexcept {\n        string s;\n        is >> s;\n        x.stoi(s);\n   \
    \     return is;\n    }\n    friend inline ostream& operator<<(ostream& os, const\
    \ BigInt& x) noexcept { return os << x.itos(); }\n};\n#line 6 \"test/library_checker/sample/many_aplusb_128bit.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int t; cin >> t;\n    while(t--){\n        BigInt a, b; cin >> a >> b;\n \
    \       cout << a + b << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb_128bit\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/bigint.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int t; cin >> t;\n    while(t--){\n        BigInt a, b; cin >> a >> b;\n \
    \       cout << a + b << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/math/bigint.hpp
  isVerificationFile: true
  path: test/library_checker/sample/many_aplusb_128bit.test.cpp
  requiredBy: []
  timestamp: '2023-06-30 01:39:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/sample/many_aplusb_128bit.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/sample/many_aplusb_128bit.test.cpp
- /verify/test/library_checker/sample/many_aplusb_128bit.test.cpp.html
title: test/library_checker/sample/many_aplusb_128bit.test.cpp
---
