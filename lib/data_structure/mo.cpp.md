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
  bundledCode: "#line 1 \"lib/data_structure/mo.cpp\"\n#include <bits/stdc++.h>\n\n\
    using namespace std;\n\n// [0 , N) \u4E0A\u306E\u533A\u9593\u306B\u5BFE\u3059\u308B\
    \ Q \u500B\u306E\u30AF\u30A8\u30EA\u3092\u8A08\u7B97\u3057\u307E\u3059\u3002 :\
    \ O(N\u221AQ) (\u533A\u9593\u306E\u4F38\u7E2E\u304C O(1) \u3067\u884C\u3048\u308B\
    \u5834\u5408)\nstruct Mo{\n    int n;\n    vector<pair<int, int>> lr;\n\n    Mo(const\
    \ int &n) : n(n) {}\n\n    /* [l, r) */\n    void add(const int &l,  const int\
    \ &r){\n        lr.push_back({l, r});\n    }\n\n    template <typename AL, typename\
    \ AR, typename EL, typename ER, typename O>\n    void build(const AL &add_left,\
    \ const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out){\n\
    \        int q = (int) lr.size();\n        int border = max<int>(1, 1.0 * n /\
    \ max<double>(1.0, sqrt(q * 2.0 / 3.0)));\n        vector<int> ord(q);\n     \
    \   iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(), ord.end(), [&](int\
    \ a, int b){\n            int ablock = lr[a].first / border, bblock = lr[b].first\
    \ / border;\n            if(ablock != bblock){\n                return ablock\
    \ < bblock;\n            }\n            return (ablock & 1) ? lr[a].second > lr[b].second\
    \ : lr[a].second < lr[b].second;\n        });\n        int l = 0, r = 0;\n   \
    \     for(auto k : ord){\n            while(l > lr[k].first) add_left(--l);\n\
    \            while(r < lr[k].second) add_right(r++);\n            while(l < lr[k].first)\
    \ erase_left(l++);\n            while(r > lr[k].second) erase_right(--r);\n  \
    \          out(k);\n        }\n    }\n\n    template <typename A, typename E,\
    \ typename O>\n    void build(const A &add, const E &erase, const O &out){\n \
    \       build(add, add, erase, erase, out);\n    }\n};\n\n// example (ABC174F)\n\
    int main(){\n    int n, q; cin >> n >> q;\n    vector<int> c(n);\n    for(int\
    \ i = 0; i < n; i++){\n        cin >> c[i];\n    }\n    Mo mo(n);\n    for(int\
    \ i = 0; i < q; i++){\n        int l, r; cin >> l >> r;\n        mo.add(l - 1,\
    \ r);\n    }\n \n    vector<int> cnt(n + 1);\n    int sum = 0;\n    vector<int>\
    \ res(q);\n    auto add = [&](int i){\n        if(cnt[c[i]] == 0) sum++;\n   \
    \     cnt[c[i]]++;\n    };\n    auto erase = [&](int i){\n        cnt[c[i]]--;\n\
    \        if(cnt[c[i]] == 0) sum--;\n    };\n    auto output = [&](int q){\n  \
    \      res[q] = sum;\n    };\n    mo.build(add, erase, output);\n \n    for(auto\
    \ x : res){\n        cout << x << \"\\n\";\n    }\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// [0 , N) \u4E0A\u306E\
    \u533A\u9593\u306B\u5BFE\u3059\u308B Q \u500B\u306E\u30AF\u30A8\u30EA\u3092\u8A08\
    \u7B97\u3057\u307E\u3059\u3002 : O(N\u221AQ) (\u533A\u9593\u306E\u4F38\u7E2E\u304C\
    \ O(1) \u3067\u884C\u3048\u308B\u5834\u5408)\nstruct Mo{\n    int n;\n    vector<pair<int,\
    \ int>> lr;\n\n    Mo(const int &n) : n(n) {}\n\n    /* [l, r) */\n    void add(const\
    \ int &l,  const int &r){\n        lr.push_back({l, r});\n    }\n\n    template\
    \ <typename AL, typename AR, typename EL, typename ER, typename O>\n    void build(const\
    \ AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right,\
    \ const O &out){\n        int q = (int) lr.size();\n        int border = max<int>(1,\
    \ 1.0 * n / max<double>(1.0, sqrt(q * 2.0 / 3.0)));\n        vector<int> ord(q);\n\
    \        iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(), ord.end(),\
    \ [&](int a, int b){\n            int ablock = lr[a].first / border, bblock =\
    \ lr[b].first / border;\n            if(ablock != bblock){\n                return\
    \ ablock < bblock;\n            }\n            return (ablock & 1) ? lr[a].second\
    \ > lr[b].second : lr[a].second < lr[b].second;\n        });\n        int l =\
    \ 0, r = 0;\n        for(auto k : ord){\n            while(l > lr[k].first) add_left(--l);\n\
    \            while(r < lr[k].second) add_right(r++);\n            while(l < lr[k].first)\
    \ erase_left(l++);\n            while(r > lr[k].second) erase_right(--r);\n  \
    \          out(k);\n        }\n    }\n\n    template <typename A, typename E,\
    \ typename O>\n    void build(const A &add, const E &erase, const O &out){\n \
    \       build(add, add, erase, erase, out);\n    }\n};\n\n// example (ABC174F)\n\
    int main(){\n    int n, q; cin >> n >> q;\n    vector<int> c(n);\n    for(int\
    \ i = 0; i < n; i++){\n        cin >> c[i];\n    }\n    Mo mo(n);\n    for(int\
    \ i = 0; i < q; i++){\n        int l, r; cin >> l >> r;\n        mo.add(l - 1,\
    \ r);\n    }\n \n    vector<int> cnt(n + 1);\n    int sum = 0;\n    vector<int>\
    \ res(q);\n    auto add = [&](int i){\n        if(cnt[c[i]] == 0) sum++;\n   \
    \     cnt[c[i]]++;\n    };\n    auto erase = [&](int i){\n        cnt[c[i]]--;\n\
    \        if(cnt[c[i]] == 0) sum--;\n    };\n    auto output = [&](int q){\n  \
    \      res[q] = sum;\n    };\n    mo.build(add, erase, output);\n \n    for(auto\
    \ x : res){\n        cout << x << \"\\n\";\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/mo.cpp
  requiredBy: []
  timestamp: '2022-11-10 01:06:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/mo.cpp
layout: document
redirect_from:
- /library/lib/data_structure/mo.cpp
- /library/lib/data_structure/mo.cpp.html
title: lib/data_structure/mo.cpp
---
