---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1_14_b.test.cpp
    title: test/aoj/alds1/alds1_14_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/rolling_hash.md
    document_title: Rolling Hash
    links: []
  bundledCode: "#line 2 \"lib/string/rolling_hash.hpp\"\n\n/**\n * @brief Rolling\
    \ Hash\n * @docs docs/string/rolling_hash.md\n */\n\nstruct RollingHash{\n   \
    \ vector<unsigned long long> hashed, power;\n    const unsigned long long mod\
    \ = (1uLL << 61) - 1;\n\n    unsigned long long mul(unsigned long long a, unsigned\
    \ long long b) const {\n        long long ret = a * b - mod * (unsigned long long)(1.0L\
    \ / mod * a * b);\n        return ret + mod * (ret < 0) - mod * (ret >= (long\
    \ long) mod);\n    }\n\n    RollingHash(const string &s, unsigned base = 10007){\n\
    \        int siz = (int) s.size();\n        hashed.assign(siz + 1, 0);\n     \
    \   power.assign(siz + 1, 0);\n        power[0] = 1;\n        for(int i = 0; i\
    \ < siz; i++){\n            power[i + 1] = mul(power[i], base);\n            hashed[i\
    \ + 1] = mul(hashed[i], base) + s[i];\n            if(hashed[i + 1] >= mod) hashed[i\
    \ + 1] -= mod;\n        }\n    }\n\n    // [l, r)\n    unsigned long long get(int\
    \ l, int r) const {\n        unsigned long long ret = hashed[r] + mod - mul(hashed[l],\
    \ power[r - l]);\n        if(ret >= mod) ret -= mod;\n        return ret;\n  \
    \  }\n\n    unsigned long long connect(unsigned long long h1, unsigned long long\
    \ h2, int h2len) const {\n        unsigned long long ret = mul(h1, power[h2len])\
    \ + h2;\n        if(ret >= mod) ret -= mod;\n        return ret;\n    }\n\n  \
    \  int LCP(const RollingHash &b, int l1, int r1, int l2, int r2){\n        int\
    \ len = min(r1 - l1, r2 - l2);\n        int low = -1, high = len + 1;\n      \
    \  while(high - low > 1){\n            int mid = (low + high) / 2;\n         \
    \   if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;\n            else\
    \ high = mid;\n        }\n        return low;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Rolling Hash\n * @docs docs/string/rolling_hash.md\n\
    \ */\n\nstruct RollingHash{\n    vector<unsigned long long> hashed, power;\n \
    \   const unsigned long long mod = (1uLL << 61) - 1;\n\n    unsigned long long\
    \ mul(unsigned long long a, unsigned long long b) const {\n        long long ret\
    \ = a * b - mod * (unsigned long long)(1.0L / mod * a * b);\n        return ret\
    \ + mod * (ret < 0) - mod * (ret >= (long long) mod);\n    }\n\n    RollingHash(const\
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
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/alds1/alds1_14_b.test.cpp
documentation_of: lib/string/rolling_hash.hpp
layout: document
redirect_from:
- /library/lib/string/rolling_hash.hpp
- /library/lib/string/rolling_hash.hpp.html
title: Rolling Hash
---
## Rolling Hash

#### 使い方

- `RollingHash(s, base)`: 文字列 s について、基数を base としたハッシュテーブルを構築します。
- `get(l, r)`: [l, r) のハッシュ値を取得します。
- `connect(h1, h2, h2len)`: ハッシュ値 h1 と長さ h2len のハッシュ値 h2 を結合します。
- `LCP(b, l1, r1, l2, r2)`: 区間 [l1, r1) と ハッシュテーブルが b となる区間 [l2, r2) の文字列の最長接頭辞を求めます。

#### 計算量

- `RollingHash(s, base)`: $\mathrm{O}(\lvert S\lvert)$
- `get(l, r)`: $\mathrm{O}(1)$
- `connect(h1, h2, h2len)`: $\mathrm{O}(1)$
- `LCP(b, l1, r1, l2, r2)`: $\mathrm{O}(\log \lvert S\lvert)$