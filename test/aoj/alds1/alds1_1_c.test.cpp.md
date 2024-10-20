---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A\u3001\u7D04\u6570\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"test/aoj/alds1/alds1_1_c.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/prime.hpp\"\n\n\
    /**\n * @brief \u7D20\u6570\u5224\u5B9A\u3001\u7D04\u6570\u5217\u6319\n * @docs\
    \ docs/math/prime.md\n */\n\nnamespace prime{\n\n    template <typename T>\n \
    \   bool isPrime(T n){\n        switch(n) {\n        case 0: // fall-through\n\
    \        case 1: return false;\n        case 2: return true;\n        }\n\n  \
    \      if(n % 2 == 0) return false;\n\n        for(T i = 3; i * i <= n; i += 2){\n\
    \            if(n % i == 0){\n                return false;\n            }\n \
    \       }\n        return true;\n    }\n\n    template <typename T>\n    vector<pair<T,\
    \ T>> factorize(T n) {\n        vector<pair<T, T>> ret;\n        for(T i = 2;\
    \ i * i <= n; i++) {\n            if(n % i != 0) continue;\n            T tmp\
    \ = 0;\n            while(n % i == 0) {\n                tmp++;\n            \
    \    n /= i;\n            }\n            ret.push_back(make_pair(i, tmp));\n \
    \       }\n        if(n != 1) ret.push_back(make_pair(n, 1));\n        return\
    \ ret;\n    }\n\n    template <typename T>\n    vector<T> divisor(T n){\n    \
    \    T rt = sqrt(n);\n        vector<T> res, resB;\n        for(T i = 1; i * i\
    \ <= n; i++){\n            if(n % i == 0){\n                res.push_back(i);\n\
    \                T j = n / i;\n                if(j != rt){\n                \
    \    resB.push_back(j);\n                }\n            }\n        }\n       \
    \ for(int i = (int) resB.size() - 1; i >= 0; i--){\n            res.push_back(resB[i]);\n\
    \        }\n        return res;\n    }\n}\n#line 6 \"test/aoj/alds1/alds1_1_c.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int n; cin >> n;\n    int ans = 0;\n    for(int i = 0; i < n; i++){\n    \
    \    int x; cin >> x;\n        ans += prime::isPrime(x);\n    }\n    cout << ans\
    \ << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/prime.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int n; cin >> n;\n    int ans = 0;\n    for(int i = 0; i < n; i++){\n    \
    \    int x; cin >> x;\n        ans += prime::isPrime(x);\n    }\n    cout << ans\
    \ << \"\\n\";\n}\n"
  dependsOn:
  - lib/math/prime.hpp
  isVerificationFile: true
  path: test/aoj/alds1/alds1_1_c.test.cpp
  requiredBy: []
  timestamp: '2024-10-21 04:45:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/alds1/alds1_1_c.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/alds1/alds1_1_c.test.cpp
- /verify/test/aoj/alds1/alds1_1_c.test.cpp.html
title: test/aoj/alds1/alds1_1_c.test.cpp
---
