---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/scc.hpp
    title: "Strongly Connected Component (\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/library_checker/graph/scc.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/scc\"\n#include <iostream>\n\n#line 2 \"lib/graph/scc.hpp\"\
    \n\n/**\n * @brief Strongly Connected Component (\u5F37\u9023\u7D50\u6210\u5206\
    \u5206\u89E3)\n * @docs docs/graph/scc.md\n */\n\n#include <vector>\n#include\
    \ <cassert>\n#include <algorithm>\n\nstruct SCC{\n    int siz;\n    std::vector<std::vector<int>>\
    \ G, G_reverse, G_compress;\n    std::vector<bool> check;\n    std::vector<int>\
    \ memo, id;\n    std::vector<int> s;\n    std::vector<std::vector<int>> result;\n\
    \n    SCC(const int N) : siz(N), G(N), G_reverse(N), check(N), id(N){ }\n\n  \
    \  void add_edge(int u, int v){\n        assert(0 <= u && u < siz);\n        assert(0\
    \ <= v && v < siz);\n        G[u].emplace_back(v);\n    }\n\n    void build(){\n\
    \        for(int i = 0; i < siz; ++i){\n            for(const auto &x : G[i]){\n\
    \                G_reverse[x].emplace_back(i);\n            }\n        }\n\n \
    \       for(int i = 0; i < siz; ++i){\n            if(!check[i]){\n          \
    \      dfs(G, i);\n            }\n        }\n        reverse(memo.begin(), memo.end());\n\
    \n        for(int i = 0; i < siz; ++i) check[i] = false;\n        for(const auto\
    \ &x : memo){\n            if(!check[x]){\n                s = {};\n         \
    \       dfs2(G_reverse, x);\n                for(const auto &y : s){\n       \
    \             id[y] = (int) result.size();\n                }\n              \
    \  result.emplace_back(s);\n            }\n        }\n\n        G_compress.resize(result.size());\n\
    \        for(int i = 0; i < siz; ++i){\n            for(const auto &x : G[i]){\n\
    \                if(id[i] != id[x]){\n                    G_compress[id[i]].emplace_back(id[x]);\n\
    \                }\n            }\n        }\n    }\n\n    void dfs(const std::vector<std::vector<int>>\
    \ &G, int curr){\n        check[curr] = true;\n        for(const auto &x : G[curr]){\n\
    \            if(check[x]){\n                continue;\n            }\n       \
    \     dfs(G, x);\n        }\n        memo.emplace_back(curr);\n    }\n\n    void\
    \ dfs2(const std::vector<std::vector<int>> &G, int curr){\n        s.emplace_back(curr);\n\
    \        check[curr] = true;\n        for(const auto &x : G[curr]){\n        \
    \    if(check[x]){\n                continue;\n            }\n            dfs2(G,\
    \ x);\n        }\n    }\n\n    std::vector<std::vector<int>> get() const {\n \
    \       return result;\n    }\n\n    std::vector<std::vector<int>> getCompressed()\
    \ const {\n        return G_compress;\n    }\n\n    int getId(int x) const {\n\
    \        return id[x];\n    }\n};\n#line 5 \"test/library_checker/graph/scc.test.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n    int n, m;\n    cin >> n >> m;\n \
    \   SCC scc(n);\n    for(int i = 0; i < m; i++){\n        int a, b;\n        cin\
    \ >> a >> b;\n        scc.add_edge(a, b);\n    }\n    scc.build();\n    vector<vector<int>>\
    \ v = scc.get();\n    cout << (int) v.size() << \"\\n\";\n    for(auto s : v){\n\
    \        cout << (int) s.size() << \" \";\n        for(auto x : s){\n        \
    \    cout << x << \" \";\n        }\n        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include <iostream>\n\
    \n#include \"../../../lib/graph/scc.hpp\"\n\nusing namespace std;\n\nint main(){\n\
    \    int n, m;\n    cin >> n >> m;\n    SCC scc(n);\n    for(int i = 0; i < m;\
    \ i++){\n        int a, b;\n        cin >> a >> b;\n        scc.add_edge(a, b);\n\
    \    }\n    scc.build();\n    vector<vector<int>> v = scc.get();\n    cout <<\
    \ (int) v.size() << \"\\n\";\n    for(auto s : v){\n        cout << (int) s.size()\
    \ << \" \";\n        for(auto x : s){\n            cout << x << \" \";\n     \
    \   }\n        cout << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/graph/scc.hpp
  isVerificationFile: true
  path: test/library_checker/graph/scc.test.cpp
  requiredBy: []
  timestamp: '2024-11-25 23:10:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/scc.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/scc.test.cpp
- /verify/test/library_checker/graph/scc.test.cpp.html
title: test/library_checker/graph/scc.test.cpp
---
