---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/yuki_416.test.cpp
    title: test/yukicoder/yuki_416.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/data_structure/partly_persistent_union_find.md
    document_title: Partly Persistent Union-Find
    links: []
  bundledCode: "#line 2 \"lib/data_structure/partly_persistent_union_find.hpp\"\n\n\
    /**\n * @brief Partly Persistent Union-Find\n * @docs docs/data_structure/partly_persistent_union_find.md\n\
    \ */\n\n#include <vector>\n#include <algorithm>\n\nstruct PersistentUnionFind{\n\
    \    int now;\n    std::vector<int> par, rank, time;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> num;\n    const int INF = 1 << 30;\n\n    PersistentUnionFind(const int\
    \ N) : par(N), rank(N), time(N), num(N){\n        now = 0;\n        for(int i\
    \ = 0; i < N; ++i){\n            par[i] = i;\n            num[i].emplace_back(0,\
    \ 1);\n        }\n        std::fill(rank.begin(), rank.begin() + N, 0);\n    \
    \    std::fill(time.begin(), time.begin() + N, INF);\n    }\n\n    int root(const\
    \ int x, const int t){\n        if(t < time[x]) return x;\n        return root(par[x],\
    \ t);\n    }\n\n    void unite(const int x, const int y){\n        ++now;\n\n\
    \        int rx = root(x, now);\n        int ry = root(y, now);\n        if(rx\
    \ == ry) return;\n\n        if(rank[rx] < rank[ry]) std::swap(rx, ry);\n     \
    \   num[rx].emplace_back(now, size(rx, now) + size(ry, now));\n\n        par[ry]\
    \ = rx;\n        time[ry] = now;\n        if(rank[rx] == rank[ry]) ++rank[rx];\n\
    \    }\n\n    bool same(const int x, const int y, const int t){\n        int rx\
    \ = root(x, t);\n        int ry = root(y, t);\n        return rx == ry;\n    }\n\
    \n    int size(const int x, const int t){\n        int rx = root(x, t);\n\n  \
    \      int ok = 0, ng = num[rx].size();\n        while(abs(ok - ng) > 1){\n  \
    \          int mid = (ok + ng) / 2;\n            if(num[rx][mid].first <= t){\n\
    \                ok = mid;\n            } else{\n                ng = mid;\n \
    \           }\n        }\n        return num[rx][ok].second;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Partly Persistent Union-Find\n * @docs docs/data_structure/partly_persistent_union_find.md\n\
    \ */\n\n#include <vector>\n#include <algorithm>\n\nstruct PersistentUnionFind{\n\
    \    int now;\n    std::vector<int> par, rank, time;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> num;\n    const int INF = 1 << 30;\n\n    PersistentUnionFind(const int\
    \ N) : par(N), rank(N), time(N), num(N){\n        now = 0;\n        for(int i\
    \ = 0; i < N; ++i){\n            par[i] = i;\n            num[i].emplace_back(0,\
    \ 1);\n        }\n        std::fill(rank.begin(), rank.begin() + N, 0);\n    \
    \    std::fill(time.begin(), time.begin() + N, INF);\n    }\n\n    int root(const\
    \ int x, const int t){\n        if(t < time[x]) return x;\n        return root(par[x],\
    \ t);\n    }\n\n    void unite(const int x, const int y){\n        ++now;\n\n\
    \        int rx = root(x, now);\n        int ry = root(y, now);\n        if(rx\
    \ == ry) return;\n\n        if(rank[rx] < rank[ry]) std::swap(rx, ry);\n     \
    \   num[rx].emplace_back(now, size(rx, now) + size(ry, now));\n\n        par[ry]\
    \ = rx;\n        time[ry] = now;\n        if(rank[rx] == rank[ry]) ++rank[rx];\n\
    \    }\n\n    bool same(const int x, const int y, const int t){\n        int rx\
    \ = root(x, t);\n        int ry = root(y, t);\n        return rx == ry;\n    }\n\
    \n    int size(const int x, const int t){\n        int rx = root(x, t);\n\n  \
    \      int ok = 0, ng = num[rx].size();\n        while(abs(ok - ng) > 1){\n  \
    \          int mid = (ok + ng) / 2;\n            if(num[rx][mid].first <= t){\n\
    \                ok = mid;\n            } else{\n                ng = mid;\n \
    \           }\n        }\n        return num[rx][ok].second;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/partly_persistent_union_find.hpp
  requiredBy: []
  timestamp: '2024-11-18 03:54:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/yuki_416.test.cpp
documentation_of: lib/data_structure/partly_persistent_union_find.hpp
layout: document
redirect_from:
- /library/lib/data_structure/partly_persistent_union_find.hpp
- /library/lib/data_structure/partly_persistent_union_find.hpp.html
title: Partly Persistent Union-Find
---
## Partly Persistent Union Find

#### 使い方

- `PersistentUnionFind(N)`: コンストラクタ (N は要素数)
- `root(x, t)`: 時刻 t において集合 x の根を取得します。
- `unite(x, y)`: 集合 x と y を併合します。
- `same(x, y, t)`: 時刻 t において x と y の属する集合が等しいかどうかを判定します。
- `size(x, t)`:  時刻 t において x の属する集合の大きさを取得します。

#### 計算量

- `PersistentUnionFind(N)`: $\mathrm{O}(N)$
- `root(x, t)`: $\alpha(\log N)$
- `unite(x, y)`: $\alpha(\log N)$
- `same(x, y)`: $\alpha(\log N)$
- `size(x)`: $\alpha(\log N)$
