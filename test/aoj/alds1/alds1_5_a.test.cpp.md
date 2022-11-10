---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/others/exhaustive_search.hpp
    title: lib/others/exhaustive_search.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A
  bundledCode: "#line 1 \"test/aoj/alds1/alds1_5_a.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/others/exhaustive_search.hpp\"\
    \n\n// a\u306E\u90E8\u5206\u96C6\u5408\u306E\u548C\u306E\u7D44\u307F\u5408\u308F\
    \u305B\u3092\u3059\u3079\u3066\u5217\u6319\u3057\u307E\u3059\u3002: O(2^N)\ntemplate<typename\
    \ T>\nvector<long long> sum_subsets(T a){\n    vector<long long> res;\n    int\
    \ n = a.size();\n    for(int bit = 0; bit < (1 << n); bit++){\n        long long\
    \ sum = 0;\n        for(int i = 0; i < n; i++){\n            int mask = 1 << i;\n\
    \            if(bit & mask){\n                sum += a[i];\n            }\n  \
    \      }\n        res.emplace_back(sum);\n    }\n    return res;\n}\n#line 6 \"\
    test/aoj/alds1/alds1_5_a.test.cpp\"\n\nint main(){\n    int n; cin >> n;\n   \
    \ vector<int> a(n);\n    for(int i = 0; i < n; i++){\n        cin >> a[i];\n \
    \   }\n    vector<long long> s = sum_subsets(a);\n    vector<int> check(4001);\n\
    \    for(auto x : s) check[x] = 1;\n    int q; cin >> q;\n    while(q--){\n  \
    \      int m; cin >> m;\n        if(check[m]){\n            cout << \"yes\" <<\
    \ \"\\n\";\n        }else{\n            cout << \"no\" << \"\\n\";\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/others/exhaustive_search.hpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    vector<int> a(n);\n    for(int i =\
    \ 0; i < n; i++){\n        cin >> a[i];\n    }\n    vector<long long> s = sum_subsets(a);\n\
    \    vector<int> check(4001);\n    for(auto x : s) check[x] = 1;\n    int q; cin\
    \ >> q;\n    while(q--){\n        int m; cin >> m;\n        if(check[m]){\n  \
    \          cout << \"yes\" << \"\\n\";\n        }else{\n            cout << \"\
    no\" << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - lib/others/exhaustive_search.hpp
  isVerificationFile: true
  path: test/aoj/alds1/alds1_5_a.test.cpp
  requiredBy: []
  timestamp: '2022-11-11 03:58:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/alds1/alds1_5_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/alds1/alds1_5_a.test.cpp
- /verify/test/aoj/alds1/alds1_5_a.test.cpp.html
title: test/aoj/alds1/alds1_5_a.test.cpp
---
