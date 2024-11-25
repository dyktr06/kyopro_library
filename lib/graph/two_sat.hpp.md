---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/scc.hpp
    title: "Strongly Connected Component (\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/other/two_sat.test.cpp
    title: test/library_checker/other/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: 2-SAT
    links:
    - https://noshi91.hatenablog.com/entry/2019/10/03/184812
    - https://zenn.dev/magurofly/articles/9d8417a17231db
  bundledCode: "#line 2 \"lib/graph/two_sat.hpp\"\n\n/**\n * @brief 2-SAT\n * @see\
    \ https://zenn.dev/magurofly/articles/9d8417a17231db https://noshi91.hatenablog.com/entry/2019/10/03/184812\n\
    \ */\n\n#line 2 \"lib/graph/scc.hpp\"\n\n/**\n * @brief Strongly Connected Component\
    \ (\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)\n * @docs docs/graph/scc.md\n */\n\
    \n#include <vector>\n#include <cassert>\n#include <algorithm>\n\nstruct SCC{\n\
    \    int siz;\n    std::vector<std::vector<int>> G, G_reverse, G_compress;\n \
    \   std::vector<bool> check;\n    std::vector<int> memo, id;\n    std::vector<int>\
    \ s;\n    std::vector<std::vector<int>> result;\n\n    SCC(const int N) : siz(N),\
    \ G(N), G_reverse(N), check(N), id(N){ }\n\n    void add_edge(int u, int v){\n\
    \        assert(0 <= u && u < siz);\n        assert(0 <= v && v < siz);\n    \
    \    G[u].emplace_back(v);\n    }\n\n    void build(){\n        for(int i = 0;\
    \ i < siz; ++i){\n            for(const auto &x : G[i]){\n                G_reverse[x].emplace_back(i);\n\
    \            }\n        }\n\n        for(int i = 0; i < siz; ++i){\n         \
    \   if(!check[i]){\n                dfs(G, i);\n            }\n        }\n   \
    \     reverse(memo.begin(), memo.end());\n\n        for(int i = 0; i < siz; ++i)\
    \ check[i] = false;\n        for(const auto &x : memo){\n            if(!check[x]){\n\
    \                s = {};\n                dfs2(G_reverse, x);\n              \
    \  for(const auto &y : s){\n                    id[y] = (int) result.size();\n\
    \                }\n                result.emplace_back(s);\n            }\n \
    \       }\n\n        G_compress.resize(result.size());\n        for(int i = 0;\
    \ i < siz; ++i){\n            for(const auto &x : G[i]){\n                if(id[i]\
    \ != id[x]){\n                    G_compress[id[i]].emplace_back(id[x]);\n   \
    \             }\n            }\n        }\n    }\n\n    void dfs(const std::vector<std::vector<int>>\
    \ &G, int curr){\n        check[curr] = true;\n        for(const auto &x : G[curr]){\n\
    \            if(check[x]){\n                continue;\n            }\n       \
    \     dfs(G, x);\n        }\n        memo.emplace_back(curr);\n    }\n\n    void\
    \ dfs2(const std::vector<std::vector<int>> &G, int curr){\n        s.emplace_back(curr);\n\
    \        check[curr] = true;\n        for(const auto &x : G[curr]){\n        \
    \    if(check[x]){\n                continue;\n            }\n            dfs2(G,\
    \ x);\n        }\n    }\n\n    std::vector<std::vector<int>> get() const {\n \
    \       return result;\n    }\n\n    std::vector<std::vector<int>> getCompressed()\
    \ const {\n        return G_compress;\n    }\n\n    int getId(int x) const {\n\
    \        return id[x];\n    }\n};\n#line 9 \"lib/graph/two_sat.hpp\"\n\n#line\
    \ 12 \"lib/graph/two_sat.hpp\"\n\nstruct TwoSAT{\n    int N;\n    SCC scc;\n \
    \   std::vector<bool> ans;\n    TwoSAT(const int N) : N(N), scc(2 * N){ }\n\n\
    \    // ((x = f) or (y = g))\n    void add_clause(int x, bool f, int y, bool g){\n\
    \        assert(0 <= x && x < N);\n        assert(0 <= y && y < N);\n        int\
    \ px = x * 2 + f, py = y * 2 + g;\n        int nx = x * 2 + !f, ny = y * 2 + !g;\n\
    \        scc.add_edge(nx, py);\n        scc.add_edge(ny, px);\n    }\n\n    void\
    \ build(){\n        scc.build();\n        for(int i = 0; i < N; i++){\n      \
    \      // x -> !x \u3068 !x -> x \u306E\u30D1\u30B9\u304C\u5B58\u5728\u3059\u308B\
    \u5834\u5408\u306F\u89E3\u306A\u3057\n            if(scc.getId(i * 2) == scc.getId(i\
    \ * 2 + 1)){\n                return;\n            }\n        }\n        int len\
    \ = (int) scc.result.size();\n        ans.resize(N);\n        std::vector<bool>\
    \ used(2 * N);\n        for(int i = 0; i < len; i++){\n            for(auto x\
    \ : scc.result[i]){\n                used[x] = 1;\n                // x \u304C\
    \ \u771F \u304B\u3064 !x \u304C\u8A2A\u554F\u6E08\u307F -> !x -> x \u306E\u30D1\
    \u30B9\u304C\u5B58\u5728\u3059\u308B\u53EF\u80FD\u6027\u304C\u3042\u308B\u305F\
    \u3081 \u771F \u3092\u5272\u308A\u5F53\u3066\u308B\n                if(x % 2 ==\
    \ 1 && used[x ^ 1]){\n                    ans[x / 2] = 1;\n                  \
    \  continue;\n                }\n            }\n        }\n    }\n\n    std::vector<bool>\
    \ getAnswer() const {\n        return ans;\n    }\n\n};\n"
  code: "#pragma once\n\n/**\n * @brief 2-SAT\n * @see https://zenn.dev/magurofly/articles/9d8417a17231db\
    \ https://noshi91.hatenablog.com/entry/2019/10/03/184812\n */\n\n#include \"../graph/scc.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n\nstruct TwoSAT{\n    int N;\n    SCC\
    \ scc;\n    std::vector<bool> ans;\n    TwoSAT(const int N) : N(N), scc(2 * N){\
    \ }\n\n    // ((x = f) or (y = g))\n    void add_clause(int x, bool f, int y,\
    \ bool g){\n        assert(0 <= x && x < N);\n        assert(0 <= y && y < N);\n\
    \        int px = x * 2 + f, py = y * 2 + g;\n        int nx = x * 2 + !f, ny\
    \ = y * 2 + !g;\n        scc.add_edge(nx, py);\n        scc.add_edge(ny, px);\n\
    \    }\n\n    void build(){\n        scc.build();\n        for(int i = 0; i <\
    \ N; i++){\n            // x -> !x \u3068 !x -> x \u306E\u30D1\u30B9\u304C\u5B58\
    \u5728\u3059\u308B\u5834\u5408\u306F\u89E3\u306A\u3057\n            if(scc.getId(i\
    \ * 2) == scc.getId(i * 2 + 1)){\n                return;\n            }\n   \
    \     }\n        int len = (int) scc.result.size();\n        ans.resize(N);\n\
    \        std::vector<bool> used(2 * N);\n        for(int i = 0; i < len; i++){\n\
    \            for(auto x : scc.result[i]){\n                used[x] = 1;\n    \
    \            // x \u304C \u771F \u304B\u3064 !x \u304C\u8A2A\u554F\u6E08\u307F\
    \ -> !x -> x \u306E\u30D1\u30B9\u304C\u5B58\u5728\u3059\u308B\u53EF\u80FD\u6027\
    \u304C\u3042\u308B\u305F\u3081 \u771F \u3092\u5272\u308A\u5F53\u3066\u308B\n \
    \               if(x % 2 == 1 && used[x ^ 1]){\n                    ans[x / 2]\
    \ = 1;\n                    continue;\n                }\n            }\n    \
    \    }\n    }\n\n    std::vector<bool> getAnswer() const {\n        return ans;\n\
    \    }\n\n};\n"
  dependsOn:
  - lib/graph/scc.hpp
  isVerificationFile: false
  path: lib/graph/two_sat.hpp
  requiredBy: []
  timestamp: '2024-11-25 23:33:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/other/two_sat.test.cpp
documentation_of: lib/graph/two_sat.hpp
layout: document
redirect_from:
- /library/lib/graph/two_sat.hpp
- /library/lib/graph/two_sat.hpp.html
title: 2-SAT
---
