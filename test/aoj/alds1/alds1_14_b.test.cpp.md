---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/rollinghash.hpp
    title: lib/string/rollinghash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/alds1/alds1_14_b.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/string/rollinghash.hpp\"\
    \n\n/* \n    RollingHash(s, base) : \u6587\u5B57\u5217 s \u306B\u3064\u3044\u3066\
    \u306E\u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\u3092\u69CB\u7BC9\u3057\
    \u307E\u3059\u3002O(n)\n    get(l, r) : [l, r) \u306E\u30CF\u30C3\u30B7\u30E5\u5024\
    \u3092\u53D6\u5F97\u3057\u307E\u3059\u3002O(1) \n    connect(h1, h2, h2len) :\
    \ \u30CF\u30C3\u30B7\u30E5\u5024 h1 \u3068\u9577\u3055 h2len \u306E\u30CF\u30C3\
    \u30B7\u30E5\u5024 h2 \u3092\u7D50\u5408\u3057\u307E\u3059\u3002\n    LCP(b, l1,\
    \ r1, l2, r2) \u533A\u9593 [l1, r1) \u3068 \u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\
    \u30D6\u30EB\u304C b \u3068\u306A\u308B\u533A\u9593 [l2, r2) \u306E\u6587\u5B57\
    \u5217\u306E\u6700\u9577\u63A5\u982D\u8F9E\u3092\u6C42\u3081\u307E\u3059\u3002\
    \ O(logN)\n*/\nstruct RollingHash{\n    vector<unsigned long long> hashed, power;\n\
    \    static constexpr unsigned long long mod = (1uL << 61) - 1;\n\t\n    unsigned\
    \ long long mul(__int128_t a, __int128_t b) const {\n\t\t__int128_t t = a * b;\n\
    \t\tt = (t >> 61) + (t & mod);\n\t\t\n\t\tif(t >= mod) return t - mod;\n\t\treturn\
    \ t;\n\t}\n\n    RollingHash(const string &s, unsigned base = 10007){\n      \
    \  int siz = (int) s.size();\n        hashed.assign(siz + 1, 0);\n        power.assign(siz\
    \ + 1, 0);\n        power[0] = 1;\n        for(int i = 0; i < siz; i++){\n   \
    \         power[i + 1] = mul(power[i], base);\n            hashed[i + 1] = mul(hashed[i],\
    \ base) + s[i];\n            if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;\n\
    \        }\n    }\n\n    unsigned long long get(int l, int r) const {\n      \
    \  unsigned long long ret = hashed[r] + mod - mul(hashed[l], power[r - l]);\n\
    \        if(ret >= mod) ret -= mod;\n        return ret;\n    }\n\n    unsigned\
    \ long long connect(unsigned h1, int h2, int h2len) const {\n        unsigned\
    \ long long ret = mul(h1, power[h2len]) + h2;\n        if(ret >= mod) ret -= mod;\n\
    \        return ret;\n    }\n\n    int LCP(const RollingHash &b, int l1, int r1,\
    \ int l2, int r2){\n        int len = min(r1 - l1, r2 - l2);\n        int low\
    \ = -1, high = len + 1;\n        while(high - low > 1){\n            int mid =\
    \ (low + high) / 2;\n            if(get(l1, l1 + mid) == b.get(l2, l2 + mid))\
    \ low = mid;\n            else high = mid;\n        }\n        return low;\n \
    \   }\n};\n#line 6 \"test/aoj/alds1/alds1_14_b.test.cpp\"\n\nint main(){\n   \
    \ string t, p; cin >> t >> p;\n    int n = t.size(), m = p.size();\n    RollingHash\
    \ rh(t), rh2(p);\n    for(int i = 0; i + m <= n; i++){\n        if(rh.get(i, i\
    \ + m) == rh2.get(0, m)){\n            cout << i << \"\\n\";\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/string/rollinghash.hpp\"\
    \n\nint main(){\n    string t, p; cin >> t >> p;\n    int n = t.size(), m = p.size();\n\
    \    RollingHash rh(t), rh2(p);\n    for(int i = 0; i + m <= n; i++){\n      \
    \  if(rh.get(i, i + m) == rh2.get(0, m)){\n            cout << i << \"\\n\";\n\
    \        }\n    }\n}"
  dependsOn:
  - lib/string/rollinghash.hpp
  isVerificationFile: true
  path: test/aoj/alds1/alds1_14_b.test.cpp
  requiredBy: []
  timestamp: '2022-11-11 03:58:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/alds1/alds1_14_b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/alds1/alds1_14_b.test.cpp
- /verify/test/aoj/alds1/alds1_14_b.test.cpp.html
title: test/aoj/alds1/alds1_14_b.test.cpp
---
