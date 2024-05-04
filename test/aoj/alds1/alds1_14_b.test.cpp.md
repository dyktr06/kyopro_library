---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/rolling_hash.hpp
    title: Rolling Hash
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
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/string/rolling_hash.hpp\"\
    \n\n/**\n * @brief Rolling Hash\n * @docs docs/string/rolling_hash.md\n */\n\n\
    struct RollingHash{\n    vector<unsigned long long> hashed, power;\n    const\
    \ unsigned long long mod = (1uLL << 61) - 1;\n\n    unsigned long long mul(unsigned\
    \ long long a, unsigned long long b) const {\n        long long ret = a * b -\
    \ mod * (unsigned long long)(1.0L / mod * a * b);\n        return ret + mod *\
    \ (ret < 0) - mod * (ret >= (long long) mod);\n    }\n\n    RollingHash(const\
    \ string &s, unsigned base = 10007){\n        int siz = (int) s.size();\n    \
    \    hashed.assign(siz + 1, 0);\n        power.assign(siz + 1, 0);\n        power[0]\
    \ = 1;\n        for(int i = 0; i < siz; i++){\n            power[i + 1] = mul(power[i],\
    \ base);\n            hashed[i + 1] = mul(hashed[i], base) + s[i];\n         \
    \   if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;\n        }\n    }\n\n    //\
    \ [l, r)\n    unsigned long long get(int l, int r) const {\n        unsigned long\
    \ long ret = hashed[r] + mod - mul(hashed[l], power[r - l]);\n        if(ret >=\
    \ mod) ret -= mod;\n        return ret;\n    }\n\n    unsigned long long connect(unsigned\
    \ long long h1, unsigned long long h2, int h2len) const {\n        unsigned long\
    \ long ret = mul(h1, power[h2len]) + h2;\n        if(ret >= mod) ret -= mod;\n\
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
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/string/rolling_hash.hpp\"\
    \n\nint main(){\n    string t, p; cin >> t >> p;\n    int n = t.size(), m = p.size();\n\
    \    RollingHash rh(t), rh2(p);\n    for(int i = 0; i + m <= n; i++){\n      \
    \  if(rh.get(i, i + m) == rh2.get(0, m)){\n            cout << i << \"\\n\";\n\
    \        }\n    }\n}"
  dependsOn:
  - lib/string/rolling_hash.hpp
  isVerificationFile: true
  path: test/aoj/alds1/alds1_14_b.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/alds1/alds1_14_b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/alds1/alds1_14_b.test.cpp
- /verify/test/aoj/alds1/alds1_14_b.test.cpp.html
title: test/aoj/alds1/alds1_14_b.test.cpp
---
