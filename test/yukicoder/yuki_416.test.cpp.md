---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/partly_persistent_union_find.hpp
    title: lib/data_structure/partly_persistent_union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/416
    links:
    - https://yukicoder.me/problems/no/416
  bundledCode: "#line 1 \"test/yukicoder/yuki_416.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/416\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/partly_persistent_union_find.hpp\"\
    \n\n/* \n    PersistentUnionFind(n) : \u90E8\u5206\u6C38\u7D9A Union-Find \u6728\
    \u3092\u30B5\u30A4\u30BAn\u3067\u69CB\u7BC9\n    \u8A08\u7B97\u91CF : O(log(n))\n\
    \    root(x, t) : \u6642\u523B t \u306B\u304A\u3051\u308B\u96C6\u5408 x \u306E\
    \u6839\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\n    unite(x, y) : \u96C6\u5408\
    \ x \u3068 y \u3092\u4F75\u5408\u3057\u307E\u3059\u3002\n    same(x, y, t) : \u6642\
    \u523B t \u306B\u304A\u3051\u308B\u96C6\u5408 x \u3068 \u96C6\u5408 y \u304C\u7B49\
    \u3057\u3044\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3057\u307E\u3059\u3002\
    \n    size(x, t) : \u6642\u523B t \u306B\u304A\u3051\u308B x \u3092\u542B\u3080\
    \u96C6\u5408\u306E\u5927\u304D\u3055\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\
    \n*/\n\nstruct PersistentUnionFind{\n    int now;\n    vector<int> par, rank,\
    \ time;\n    vector<vector<pair<int, int>>> num;\n    const int INF = 1 << 30;\n\
    \n    PersistentUnionFind(const int &N) : par(N), rank(N), time(N), num(N){\n\
    \        now = 0;\n        for(int i = 0; i < N; ++i){\n            par[i] = i;\n\
    \            num[i].emplace_back(0, 1);\n        }\n        fill(rank.begin(),\
    \ rank.begin() + N, 0);\n        fill(time.begin(), time.begin() + N, INF);\n\
    \    }\n\n    int root(const int &x, const int &t){\n        if(t < time[x]) return\
    \ x;\n        return root(par[x], t);\n    }\n\n    void unite(const int &x, const\
    \ int &y){\n        ++now;\n\n        int rx = root(x, now);\n        int ry =\
    \ root(y, now);\n        if(rx == ry) return;\n\n        if(rank[rx] < rank[ry])\
    \ swap(rx, ry);\n        num[rx].emplace_back(now, size(rx, now) + size(ry, now));\n\
    \n        par[ry] = rx;\n        time[ry] = now;\n        if(rank[rx] == rank[ry])\
    \ ++rank[rx];\n    }\n\n    bool same(const int &x, const int &y, const int &t){\n\
    \        int rx = root(x, t);\n        int ry = root(y, t);\n        return rx\
    \ == ry;\n    }\n\n    int size(const int &x, const int &t){\n        int rx =\
    \ root(x, t);\n\n        int ok = 0, ng = num[rx].size();\n        while(abs(ok\
    \ - ng) > 1){\n            int mid = (ok + ng) / 2;\n            if(num[rx][mid].first\
    \ <= t){\n                ok = mid;\n            }else{\n                ng =\
    \ mid;\n            }\n        }\n        return num[rx][ok].second;\n    }\n\
    };\n#line 6 \"test/yukicoder/yuki_416.test.cpp\"\n\nint main(){\n    int n, m,\
    \ q; cin >> n >> m >> q;\n    PersistentUnionFind tree(n);\n    vector<pair<int,\
    \ int>> p1, p2;\n    set<pair<int, int>> s;\n    for(int i = 0; i < m; i++){\n\
    \        int a, b; cin >> a >> b; a--; b--;\n        p1.emplace_back(a, b);\n\
    \    }\n    for(int i = 0; i < q; i++){\n        int c, d; cin >> c >> d; c--;\
    \ d--;\n        p2.emplace_back(c, d);\n        s.insert({c, d});\n    }\n   \
    \ for(int i = 0; i < m; i++){\n        auto [a, b] = p1[i];\n        if(s.find({a,\
    \ b}) == s.end()){\n            tree.unite(a, b);\n        }\n    }\n    for(int\
    \ i = q - 1; i >= 0; i--){\n        auto [a, b] = p2[i];\n        tree.unite(a,\
    \ b);\n    }\n    for(int i = 1; i < n; i++){\n        if(!tree.same(0, i, m)){\n\
    \            cout << 0 << \"\\n\";\n            continue;\n        }else if(tree.same(0,\
    \ i, m - q)){\n            cout << -1 << \"\\n\";\n            continue;\n   \
    \     }\n        int ok = m, ng = m - q;\n        while(abs(ok - ng) > 1){\n \
    \           int mid = (ok + ng) / 2;\n            if(tree.same(0, i, mid)){\n\
    \                ok = mid;\n            }else{\n                ng = mid;\n  \
    \          }\n        }\n        cout << m - ok + 1 << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/416\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../lib/data_structure/partly_persistent_union_find.hpp\"\
    \n\nint main(){\n    int n, m, q; cin >> n >> m >> q;\n    PersistentUnionFind\
    \ tree(n);\n    vector<pair<int, int>> p1, p2;\n    set<pair<int, int>> s;\n \
    \   for(int i = 0; i < m; i++){\n        int a, b; cin >> a >> b; a--; b--;\n\
    \        p1.emplace_back(a, b);\n    }\n    for(int i = 0; i < q; i++){\n    \
    \    int c, d; cin >> c >> d; c--; d--;\n        p2.emplace_back(c, d);\n    \
    \    s.insert({c, d});\n    }\n    for(int i = 0; i < m; i++){\n        auto [a,\
    \ b] = p1[i];\n        if(s.find({a, b}) == s.end()){\n            tree.unite(a,\
    \ b);\n        }\n    }\n    for(int i = q - 1; i >= 0; i--){\n        auto [a,\
    \ b] = p2[i];\n        tree.unite(a, b);\n    }\n    for(int i = 1; i < n; i++){\n\
    \        if(!tree.same(0, i, m)){\n            cout << 0 << \"\\n\";\n       \
    \     continue;\n        }else if(tree.same(0, i, m - q)){\n            cout <<\
    \ -1 << \"\\n\";\n            continue;\n        }\n        int ok = m, ng = m\
    \ - q;\n        while(abs(ok - ng) > 1){\n            int mid = (ok + ng) / 2;\n\
    \            if(tree.same(0, i, mid)){\n                ok = mid;\n          \
    \  }else{\n                ng = mid;\n            }\n        }\n        cout <<\
    \ m - ok + 1 << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/data_structure/partly_persistent_union_find.hpp
  isVerificationFile: true
  path: test/yukicoder/yuki_416.test.cpp
  requiredBy: []
  timestamp: '2022-12-09 18:41:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/yuki_416.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/yuki_416.test.cpp
- /verify/test/yukicoder/yuki_416.test.cpp.html
title: test/yukicoder/yuki_416.test.cpp
---