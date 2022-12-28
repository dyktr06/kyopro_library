---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/vertex_add_path_sum.test.cpp
    title: test/library_checker/data_structure/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/vertex_add_subtree_sum.test.cpp
    title: test/library_checker/data_structure/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/vertex_set_path_composite.test.cpp
    title: test/library_checker/data_structure/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/heavy_light_decomposition.hpp\"\n\n/* \n    \u6728\
    \u306B\u5BFE\u3057\u3066\u91CD\u8EFD\u5206\u89E3\u3092\u884C\u3044\u307E\u3059\
    \u3002\n    HeavyLightDecomposition(node_size) : \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n    add_edge(u, v) : \u9802\u70B9 u \u304B\u3089 \u9802\u70B9 v\
    \ \u306B\u7121\u5411\u8FBA\u3092\u8FFD\u52A0\u3057\u307E\u3059\u3002: O(1)\n \
    \   build() : \u91CD\u8EFD\u5206\u89E3\u3092\u884C\u3044\u307E\u3059\u3002: O(V\
    \ log V)\n    get(a) : a \u306E\u91CD\u8EFD\u5206\u89E3\u5F8C\u306E index \u3092\
    \u8FD4\u3057\u307E\u3059\u3002: O(1)\n    lca(a, b): a \u3068 b \u306E LCA \u3092\
    \u6C42\u3081\u307E\u3059\u3002: O(log V)\n    subtree_query(a, f): a \u306E\u90E8\
    \u5206\u6728 f \u3092\u51E6\u7406\u3057\u307E\u3059\u3002: O(log V)\n    path_query(a,\
    \ b, f): a \u3068 b \u306E\u30D1\u30B9\u306B\u5BFE\u3057\u3066 f \u3092\u51E6\u7406\
    \u3057\u307E\u3059\u3002: O(log^2 V)\n    path_noncommutative_query(a, b, f, f2):\
    \ a \u3068 b \u306E\u30D1\u30B9\u306B\u5BFE\u3057\u3066\u975E\u53EF\u63DB\u306A\
    \u5834\u5408\u306E f \u3092\u51E6\u7406\u3057\u307E\u3059\u3002(\u53CD\u8EE2\u3055\
    \u305B\u305F\u95A2\u6570\u3092 f2 \u306B\u6E21\u3057\u307E\u3059): O(log^2 V)\n\
    \n    \u30D1\u30B9\u30AF\u30A8\u30EA\u306E\u4F8B\n    // ex) hl.path_query(q,\
    \ r, [&](int l, int r){ seg.range(l, r, s); })\n    // ex) hl.query(q, r, [&](int\
    \ l, int r){ ans += seg.query(l, r); })\n*/\n\nclass HeavyLightDecomposition{\n\
    \    int V;\n    vector<vector<int>> G;\n    vector<int> stsize, parent, pathtop,\
    \ in, out;\n    int root;\n\nprivate:\n    // Subtree Size\n    void buildStsize(int\
    \ curr, int prev){\n        stsize[curr] = 1, parent[curr] = prev;\n        for(int\
    \ &v : G[curr]){\n            if(v == prev){\n                if(v == G[curr].back())\
    \ break;\n                else swap(v, G[curr].back());\n            }\n     \
    \       buildStsize(v, curr);\n            stsize[curr] += stsize[v];\n      \
    \      if(stsize[v] > stsize[G[curr][0]]){\n                swap(v, G[curr][0]);\n\
    \            }\n        }\n    }\n\n    void buildPath(int curr, int prev, int\
    \ &t){\n        in[curr] = t++;\n        for(int v : G[curr]){\n            if(v\
    \ == prev) continue;\n            \n            if(v == G[curr][0]){\n       \
    \         pathtop[v] = pathtop[curr];\n            }else{\n                pathtop[v]\
    \ = v;\n            }\n            buildPath(v, curr, t);\n        }\n       \
    \ out[curr] = t;\n    }\n\npublic:\n    HeavyLightDecomposition(int node_size)\
    \ : V(node_size), G(V), stsize(V, 0), parent(V, -1),\n    pathtop(V, -1), in(V,\
    \ -1), out(V, -1){}\n\n    void add_edge(int u, int v){\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n\n    void build(int _root = 0){\n       \
    \ root = _root;\n        int t = 0;\n        buildStsize(root, -1);\n        pathtop[root]\
    \ = root;\n        buildPath(root, -1, t);\n    }\n\n    inline int get(int a){\n\
    \        return in[a];\n    }\n\n    int lca(int a, int b){\n        int pa =\
    \ pathtop[a], pb = pathtop[b];\n        while(pathtop[a] != pathtop[b]){\n   \
    \         if(in[pa] > in[pb]){\n                a = parent[pa], pa = pathtop[a];\n\
    \            }else{\n                b = parent[pb], pb = pathtop[b];\n      \
    \      }\n        }\n        if(in[a] > in[b]) swap(a, b);\n        return a;\n\
    \    }\n\n    void subtree_query(int a, const function<void(int, int)> &func){\n\
    \        func(in[a], out[a]);\n    }\n\n    void path_query(int a, int b, const\
    \ function<void(int, int)> &func, bool include_root = true, bool reverse_path\
    \ = false){\n        vector<pair<int, int>> path;\n        int pa = pathtop[a],\
    \ pb = pathtop[b];\n        while(pathtop[a] != pathtop[b]){\n            if(in[pa]\
    \ > in[pb]){\n                path.emplace_back(in[pa], in[a] + 1);\n        \
    \        a = parent[pa], pa = pathtop[a];\n            }else{\n              \
    \  path.emplace_back(in[pb], in[b] + 1);\n                b = parent[pb], pb =\
    \ pathtop[b];\n            }\n        }\n        if(in[a] > in[b]) swap(a, b);\n\
    \n        if(include_root) path.emplace_back(in[a], in[b] + 1);\n        else\
    \ path.emplace_back(in[a] + 1, in[b] + 1);\n        \n        if(!reverse_path)\
    \ reverse(path.begin(), path.end());\n        else for(auto& p : path) p = make_pair(V\
    \ - p.second, V - p.first);\n\n        for(auto [u, v] : path){\n            func(u,\
    \ v);\n        }\n    }\n\n    void path_noncommutative_query(int a, int b, const\
    \ function<void(int, int)> &func, const function<void(int, int)> &func2){\n  \
    \      int l = lca(a, b);\n        path_query(a, l, func2, false, true);\n   \
    \     path_query(l, b, func, true, false);\n    }\n};\n"
  code: "#pragma once\n\n/* \n    \u6728\u306B\u5BFE\u3057\u3066\u91CD\u8EFD\u5206\
    \u89E3\u3092\u884C\u3044\u307E\u3059\u3002\n    HeavyLightDecomposition(node_size)\
    \ : \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    add_edge(u, v) : \u9802\u70B9\
    \ u \u304B\u3089 \u9802\u70B9 v \u306B\u7121\u5411\u8FBA\u3092\u8FFD\u52A0\u3057\
    \u307E\u3059\u3002: O(1)\n    build() : \u91CD\u8EFD\u5206\u89E3\u3092\u884C\u3044\
    \u307E\u3059\u3002: O(V log V)\n    get(a) : a \u306E\u91CD\u8EFD\u5206\u89E3\u5F8C\
    \u306E index \u3092\u8FD4\u3057\u307E\u3059\u3002: O(1)\n    lca(a, b): a \u3068\
    \ b \u306E LCA \u3092\u6C42\u3081\u307E\u3059\u3002: O(log V)\n    subtree_query(a,\
    \ f): a \u306E\u90E8\u5206\u6728 f \u3092\u51E6\u7406\u3057\u307E\u3059\u3002\
    : O(log V)\n    path_query(a, b, f): a \u3068 b \u306E\u30D1\u30B9\u306B\u5BFE\
    \u3057\u3066 f \u3092\u51E6\u7406\u3057\u307E\u3059\u3002: O(log^2 V)\n    path_noncommutative_query(a,\
    \ b, f, f2): a \u3068 b \u306E\u30D1\u30B9\u306B\u5BFE\u3057\u3066\u975E\u53EF\
    \u63DB\u306A\u5834\u5408\u306E f \u3092\u51E6\u7406\u3057\u307E\u3059\u3002(\u53CD\
    \u8EE2\u3055\u305B\u305F\u95A2\u6570\u3092 f2 \u306B\u6E21\u3057\u307E\u3059):\
    \ O(log^2 V)\n\n    \u30D1\u30B9\u30AF\u30A8\u30EA\u306E\u4F8B\n    // ex) hl.path_query(q,\
    \ r, [&](int l, int r){ seg.range(l, r, s); })\n    // ex) hl.query(q, r, [&](int\
    \ l, int r){ ans += seg.query(l, r); })\n*/\n\nclass HeavyLightDecomposition{\n\
    \    int V;\n    vector<vector<int>> G;\n    vector<int> stsize, parent, pathtop,\
    \ in, out;\n    int root;\n\nprivate:\n    // Subtree Size\n    void buildStsize(int\
    \ curr, int prev){\n        stsize[curr] = 1, parent[curr] = prev;\n        for(int\
    \ &v : G[curr]){\n            if(v == prev){\n                if(v == G[curr].back())\
    \ break;\n                else swap(v, G[curr].back());\n            }\n     \
    \       buildStsize(v, curr);\n            stsize[curr] += stsize[v];\n      \
    \      if(stsize[v] > stsize[G[curr][0]]){\n                swap(v, G[curr][0]);\n\
    \            }\n        }\n    }\n\n    void buildPath(int curr, int prev, int\
    \ &t){\n        in[curr] = t++;\n        for(int v : G[curr]){\n            if(v\
    \ == prev) continue;\n            \n            if(v == G[curr][0]){\n       \
    \         pathtop[v] = pathtop[curr];\n            }else{\n                pathtop[v]\
    \ = v;\n            }\n            buildPath(v, curr, t);\n        }\n       \
    \ out[curr] = t;\n    }\n\npublic:\n    HeavyLightDecomposition(int node_size)\
    \ : V(node_size), G(V), stsize(V, 0), parent(V, -1),\n    pathtop(V, -1), in(V,\
    \ -1), out(V, -1){}\n\n    void add_edge(int u, int v){\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n\n    void build(int _root = 0){\n       \
    \ root = _root;\n        int t = 0;\n        buildStsize(root, -1);\n        pathtop[root]\
    \ = root;\n        buildPath(root, -1, t);\n    }\n\n    inline int get(int a){\n\
    \        return in[a];\n    }\n\n    int lca(int a, int b){\n        int pa =\
    \ pathtop[a], pb = pathtop[b];\n        while(pathtop[a] != pathtop[b]){\n   \
    \         if(in[pa] > in[pb]){\n                a = parent[pa], pa = pathtop[a];\n\
    \            }else{\n                b = parent[pb], pb = pathtop[b];\n      \
    \      }\n        }\n        if(in[a] > in[b]) swap(a, b);\n        return a;\n\
    \    }\n\n    void subtree_query(int a, const function<void(int, int)> &func){\n\
    \        func(in[a], out[a]);\n    }\n\n    void path_query(int a, int b, const\
    \ function<void(int, int)> &func, bool include_root = true, bool reverse_path\
    \ = false){\n        vector<pair<int, int>> path;\n        int pa = pathtop[a],\
    \ pb = pathtop[b];\n        while(pathtop[a] != pathtop[b]){\n            if(in[pa]\
    \ > in[pb]){\n                path.emplace_back(in[pa], in[a] + 1);\n        \
    \        a = parent[pa], pa = pathtop[a];\n            }else{\n              \
    \  path.emplace_back(in[pb], in[b] + 1);\n                b = parent[pb], pb =\
    \ pathtop[b];\n            }\n        }\n        if(in[a] > in[b]) swap(a, b);\n\
    \n        if(include_root) path.emplace_back(in[a], in[b] + 1);\n        else\
    \ path.emplace_back(in[a] + 1, in[b] + 1);\n        \n        if(!reverse_path)\
    \ reverse(path.begin(), path.end());\n        else for(auto& p : path) p = make_pair(V\
    \ - p.second, V - p.first);\n\n        for(auto [u, v] : path){\n            func(u,\
    \ v);\n        }\n    }\n\n    void path_noncommutative_query(int a, int b, const\
    \ function<void(int, int)> &func, const function<void(int, int)> &func2){\n  \
    \      int l = lca(a, b);\n        path_query(a, l, func2, false, true);\n   \
    \     path_query(l, b, func, true, false);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2022-12-28 17:32:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/vertex_set_path_composite.test.cpp
  - test/library_checker/data_structure/vertex_add_subtree_sum.test.cpp
  - test/library_checker/data_structure/vertex_add_path_sum.test.cpp
documentation_of: lib/graph/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/lib/graph/heavy_light_decomposition.hpp
- /library/lib/graph/heavy_light_decomposition.hpp.html
title: lib/graph/heavy_light_decomposition.hpp
---
