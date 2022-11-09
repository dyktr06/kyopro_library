---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/string/rollinghash.cpp\"\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n/* \n    RollingHash(s, base) : \u6587\u5B57\u5217 s\
    \ \u306B\u3064\u3044\u3066\u306E\u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\
    \u3092\u69CB\u7BC9\u3057\u307E\u3059\u3002O(n)\n    get(l, r) : [l, r) \u306E\u30CF\
    \u30C3\u30B7\u30E5\u5024\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002O(1) \n    connect(h1,\
    \ h2, h2len) : \u30CF\u30C3\u30B7\u30E5\u5024 h1 \u3068\u9577\u3055 h2len \u306E\
    \u30CF\u30C3\u30B7\u30E5\u5024 h2 \u3092\u7D50\u5408\u3057\u307E\u3059\u3002\n\
    \    LCP(b, l1, r1, l2, r2) \u533A\u9593 [l1, r1) \u3068 \u30CF\u30C3\u30B7\u30E5\
    \u30C6\u30FC\u30D6\u30EB\u304C b \u3068\u306A\u308B\u533A\u9593 [l2, r2) \u306E\
    \u6587\u5B57\u5217\u306E\u6700\u9577\u63A5\u982D\u8F9E\u3092\u6C42\u3081\u307E\
    \u3059\u3002 O(logN)\n*/\nstruct RollingHash{\n    vector<unsigned long> hashed,\
    \ power;\n    static constexpr unsigned long mod = (1uL << 61) - 1;\n\t\n    unsigned\
    \ long mul(__int128_t a, __int128_t b) const {\n\t\t__int128_t t = a * b;\n\t\t\
    t = (t >> 61) + (t & mod);\n\t\t\n\t\tif(t >= mod) return t - mod;\n\t\treturn\
    \ t;\n\t}\n\n    RollingHash(const string &s, unsigned base = 10007){\n      \
    \  int siz = (int) s.size();\n        hashed.assign(siz + 1, 0);\n        power.assign(siz\
    \ + 1, 0);\n        power[0] = 1;\n        for(int i = 0; i < siz; i++){\n   \
    \         power[i + 1] = mul(power[i], base);\n            hashed[i + 1] = mul(hashed[i],\
    \ base) + s[i];\n            if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;\n\
    \        }\n    }\n\n    unsigned long get(int l, int r) const {\n        unsigned\
    \ long ret = hashed[r] + mod - mul(hashed[l], power[r - l]);\n        if(ret >=\
    \ mod) ret -= mod;\n        return ret;\n    }\n\n    unsigned long connect(unsigned\
    \ h1, int h2, int h2len) const {\n        unsigned long ret = mul(h1, power[h2len])\
    \ + h2;\n        if(ret >= mod) ret -= mod;\n        return ret;\n    }\n\n  \
    \  int LCP(const RollingHash &b, int l1, int r1, int l2, int r2){\n        int\
    \ len = min(r1 - l1, r2 - l2);\n        int low = -1, high = len + 1;\n      \
    \  while(high - low > 1){\n            int mid = (low + high) / 2;\n         \
    \   if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;\n            else\
    \ high = mid;\n        }\n        return low;\n    }\n};\n\n// example(ABC141E)\n\
    int main(){\n    int n; cin >> n;\n    string s; cin >> s;\n    int ans = 0;\n\
    \    RollingHash rh(s);\n    for(int l1 = 0; l1 < n; l1++){\n        for(int l2\
    \ = l1 + 1; l2 < n; l2++){\n            while(l1 + ans < l2 && l2 + ans < n){\n\
    \                if(rh.get(l1, l1 + ans + 1) == rh.get(l2, l2 + ans + 1)){\n \
    \                   ans++;\n                }else{\n                    break;\n\
    \                }\n            }\n        }\n    }\n    cout << ans << \"\\n\"\
    ;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n/* \n    RollingHash(s,\
    \ base) : \u6587\u5B57\u5217 s \u306B\u3064\u3044\u3066\u306E\u30CF\u30C3\u30B7\
    \u30E5\u30C6\u30FC\u30D6\u30EB\u3092\u69CB\u7BC9\u3057\u307E\u3059\u3002O(n)\n\
    \    get(l, r) : [l, r) \u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u53D6\u5F97\
    \u3057\u307E\u3059\u3002O(1) \n    connect(h1, h2, h2len) : \u30CF\u30C3\u30B7\
    \u30E5\u5024 h1 \u3068\u9577\u3055 h2len \u306E\u30CF\u30C3\u30B7\u30E5\u5024\
    \ h2 \u3092\u7D50\u5408\u3057\u307E\u3059\u3002\n    LCP(b, l1, r1, l2, r2) \u533A\
    \u9593 [l1, r1) \u3068 \u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\u304C\
    \ b \u3068\u306A\u308B\u533A\u9593 [l2, r2) \u306E\u6587\u5B57\u5217\u306E\u6700\
    \u9577\u63A5\u982D\u8F9E\u3092\u6C42\u3081\u307E\u3059\u3002 O(logN)\n*/\nstruct\
    \ RollingHash{\n    vector<unsigned long> hashed, power;\n    static constexpr\
    \ unsigned long mod = (1uL << 61) - 1;\n\t\n    unsigned long mul(__int128_t a,\
    \ __int128_t b) const {\n\t\t__int128_t t = a * b;\n\t\tt = (t >> 61) + (t & mod);\n\
    \t\t\n\t\tif(t >= mod) return t - mod;\n\t\treturn t;\n\t}\n\n    RollingHash(const\
    \ string &s, unsigned base = 10007){\n        int siz = (int) s.size();\n    \
    \    hashed.assign(siz + 1, 0);\n        power.assign(siz + 1, 0);\n        power[0]\
    \ = 1;\n        for(int i = 0; i < siz; i++){\n            power[i + 1] = mul(power[i],\
    \ base);\n            hashed[i + 1] = mul(hashed[i], base) + s[i];\n         \
    \   if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;\n        }\n    }\n\n    unsigned\
    \ long get(int l, int r) const {\n        unsigned long ret = hashed[r] + mod\
    \ - mul(hashed[l], power[r - l]);\n        if(ret >= mod) ret -= mod;\n      \
    \  return ret;\n    }\n\n    unsigned long connect(unsigned h1, int h2, int h2len)\
    \ const {\n        unsigned long ret = mul(h1, power[h2len]) + h2;\n        if(ret\
    \ >= mod) ret -= mod;\n        return ret;\n    }\n\n    int LCP(const RollingHash\
    \ &b, int l1, int r1, int l2, int r2){\n        int len = min(r1 - l1, r2 - l2);\n\
    \        int low = -1, high = len + 1;\n        while(high - low > 1){\n     \
    \       int mid = (low + high) / 2;\n            if(get(l1, l1 + mid) == b.get(l2,\
    \ l2 + mid)) low = mid;\n            else high = mid;\n        }\n        return\
    \ low;\n    }\n};\n\n// example(ABC141E)\nint main(){\n    int n; cin >> n;\n\
    \    string s; cin >> s;\n    int ans = 0;\n    RollingHash rh(s);\n    for(int\
    \ l1 = 0; l1 < n; l1++){\n        for(int l2 = l1 + 1; l2 < n; l2++){\n      \
    \      while(l1 + ans < l2 && l2 + ans < n){\n                if(rh.get(l1, l1\
    \ + ans + 1) == rh.get(l2, l2 + ans + 1)){\n                    ans++;\n     \
    \           }else{\n                    break;\n                }\n          \
    \  }\n        }\n    }\n    cout << ans << \"\\n\";\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/string/rollinghash.cpp
  requiredBy: []
  timestamp: '2022-09-23 04:24:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/string/rollinghash.cpp
layout: document
redirect_from:
- /library/lib/string/rollinghash.cpp
- /library/lib/string/rollinghash.cpp.html
title: lib/string/rollinghash.cpp
---
