---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/graph/dinic.hpp
    title: lib/graph/dinic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/library_checker/graph/bipartitematching.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/dinic.hpp\"\n\n\
    template<typename T>\nstruct Dinic{\nprivate:\n    int V;\n    vector<int> level,\
    \ iter;\n\n    void bfs(int s, int t){\n        fill(level.begin(), level.end(),\
    \ -1);\n        level[s] = 0;\n        queue<int> q;\n        q.push(s);\n   \
    \     while(!(q.empty())){\n            int f = q.front();\n            q.pop();\n\
    \            for(auto &e : G[f]){\n                if(e.cap > 0 && level[e.to]\
    \ < 0){\n                    level[e.to] = level[f] + 1;\n                   \
    \ if(e.to == t) return;\n                    q.push(e.to);\n                }\n\
    \            }\n        }\n    }\n\n    T dfs(int v, int t, T f){\n        if(v\
    \ == t){\n            return f;\n        }\n        for(int &i = iter[v]; i <\
    \ (int) G[v].size(); i++){\n            edge &e = G[v][i];\n            if(e.cap\
    \ > 0 && level[v] < level[e.to]){\n                T d = dfs(e.to, t, min(f, e.cap));\n\
    \                if(d > 0){\n                    e.cap -= d;\n               \
    \     e.flow += d;\n                    G[e.to][e.rev].cap += d;\n           \
    \         G[e.to][e.rev].flow -= d;\n                    return d;\n         \
    \       }\n            }\n        }\n        return 0;\n    }\n\npublic:\n   \
    \ struct edge{\n        int to, rev;\n        T cap, flow = 0;\n    };\n    vector<vector<edge>>\
    \ G;\n\n    Dinic(const int n) : V(n), level(n), iter(n), G(n){}\n\n    void add_edge(int\
    \ from, int to, T cap){\n        G[from].push_back({to, (int) G[to].size(), cap});\n\
    \        G[to].push_back({from, (int) G[from].size() - 1, (T) 0});\n    }\n\n\
    \    T flow(int s, int t){\n        T flow = 0;\n        while(true){\n      \
    \      bfs(s, t);\n            if(level[t] < 0) return flow;\n            fill(iter.begin(),\
    \ iter.end(), 0);\n            T f;\n            while((f = dfs(s, t, numeric_limits<T>::max()))\
    \ > 0){\n                flow += f;\n            }\n        }\n    }\n};\n#line\
    \ 6 \"test/library_checker/graph/bipartitematching.test.cpp\"\n\nint main(){\n\
    \    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int l, r, m; cin\
    \ >> l >> r >> m;\n    Dinic<long long> G(l + r + 2);\n    int s = l + r;\n  \
    \  int t = s + 1;\n    for(int i = 0; i < m; i++){\n        int a, b; cin >> a\
    \ >> b;\n        G.add_edge(a, b + l, 1);\n    }\n    for(int i = 0; i < l; i++){\n\
    \        G.add_edge(s, i, 1);\n    }\n    for(int i = 0; i < r; i++){\n      \
    \  G.add_edge(i + l, t, 1);\n    }\n    long long res = G.flow(s, t);\n    cout\
    \ << res << \"\\n\";\n\n    for(int i = 0; i < l + r + 2; i++){\n        for(auto\
    \ &e : G.G[i]){\n            if(res == 0) break;\n            if(e.flow > 0){\n\
    \                cout << i << \" \" << e.to - l << \"\\n\";\n                res--;\n\
    \            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/dinic.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int l, r, m; cin >> l >> r >> m;\n    Dinic<long long> G(l + r + 2);\n   \
    \ int s = l + r;\n    int t = s + 1;\n    for(int i = 0; i < m; i++){\n      \
    \  int a, b; cin >> a >> b;\n        G.add_edge(a, b + l, 1);\n    }\n    for(int\
    \ i = 0; i < l; i++){\n        G.add_edge(s, i, 1);\n    }\n    for(int i = 0;\
    \ i < r; i++){\n        G.add_edge(i + l, t, 1);\n    }\n    long long res = G.flow(s,\
    \ t);\n    cout << res << \"\\n\";\n\n    for(int i = 0; i < l + r + 2; i++){\n\
    \        for(auto &e : G.G[i]){\n            if(res == 0) break;\n           \
    \ if(e.flow > 0){\n                cout << i << \" \" << e.to - l << \"\\n\";\n\
    \                res--;\n            }\n        }\n    }\n}"
  dependsOn:
  - lib/graph/dinic.hpp
  isVerificationFile: true
  path: test/library_checker/graph/bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/bipartitematching.test.cpp
- /verify/test/library_checker/graph/bipartitematching.test.cpp.html
title: test/library_checker/graph/bipartitematching.test.cpp
---
