---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/graph/auxiliary_tree.hpp
    title: Auxiliary Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/jump_on_tree.test.cpp
    title: test/library_checker/tree/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/lca_hl.test.cpp
    title: test/library_checker/tree/lca_hl.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/vertex_add_path_sum.test.cpp
    title: test/library_checker/tree/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/vertex_add_subtree_sum.test.cpp
    title: test/library_checker/tree/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/vertex_set_path_composite.test.cpp
    title: test/library_checker/tree/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_901.test.cpp
    title: test/yukicoder/yuki_901.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/heavy_light_decomposition.md
    document_title: "Heavy Light Decomposition (\u91CD\u8EFD\u5206\u89E3)"
    links: []
  bundledCode: "#line 2 \"lib/graph/heavy_light_decomposition.hpp\"\n\n/**\n * @brief\
    \ Heavy Light Decomposition (\u91CD\u8EFD\u5206\u89E3)\n * @docs docs/graph/heavy_light_decomposition.md\n\
    \ */\n\nclass HeavyLightDecomposition{\nprotected:\n    int V;\n    vector<vector<int>>\
    \ G;\n    vector<int> stsize, parent, pathtop, depth, in, reverse_in, out;\n \
    \   int root;\n\nprivate:\n    // Subtree Size\n    void buildStsize(int curr,\
    \ int prev){\n        stsize[curr] = 1, parent[curr] = prev;\n        for(int\
    \ &v : G[curr]){\n            if(v == prev){\n                if(v == G[curr].back())\
    \ break;\n                else swap(v, G[curr].back());\n            }\n     \
    \       buildStsize(v, curr);\n            stsize[curr] += stsize[v];\n      \
    \      if(stsize[v] > stsize[G[curr][0]]){\n                swap(v, G[curr][0]);\n\
    \            }\n        }\n    }\n\n    void buildPath(int curr, int prev, int\
    \ &t){\n        in[curr] = t++;\n        reverse_in[in[curr]] = curr;\n      \
    \  for(int v : G[curr]){\n            if(v == prev) continue;\n\n            if(v\
    \ == G[curr][0]){\n                pathtop[v] = pathtop[curr];\n            }\
    \ else{\n                pathtop[v] = v;\n            }\n            depth[v]\
    \ = depth[curr] + 1;\n            buildPath(v, curr, t);\n        }\n        out[curr]\
    \ = t;\n    }\n\npublic:\n    HeavyLightDecomposition(int node_size) : V(node_size),\
    \ G(V), stsize(V, 0), parent(V, -1),\n        pathtop(V, -1), depth(V, 0), in(V,\
    \ -1), reverse_in(V, -1), out(V, -1){}\n\n    void add_edge(int u, int v){\n \
    \       G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\n    void build(int\
    \ _root = 0){\n        root = _root;\n        int t = 0;\n        buildStsize(root,\
    \ -1);\n        pathtop[root] = root;\n        buildPath(root, -1, t);\n    }\n\
    \n    inline int get(int a){\n        return in[a];\n    }\n\n    int la(int a,\
    \ int k) {\n        while(true){\n            int u = pathtop[a];\n          \
    \  if(in[a] - k >= in[u]) return reverse_in[in[a] - k];\n            k -= in[a]\
    \ - in[u] + 1;\n            a = parent[u];\n        }\n    }\n\n    int lca(int\
    \ a, int b){\n        int pa = pathtop[a], pb = pathtop[b];\n        while(pathtop[a]\
    \ != pathtop[b]){\n            if(in[pa] > in[pb]){\n                a = parent[pa],\
    \ pa = pathtop[a];\n            } else{\n                b = parent[pb], pb =\
    \ pathtop[b];\n            }\n        }\n        if(in[a] > in[b]) swap(a, b);\n\
    \        return a;\n    }\n\n    int dist(int a, int b){ return depth[a] + depth[b]\
    \ - 2 * depth[lca(a, b)]; }\n\n    int jump(int from, int to, int k) {\n     \
    \   if(!k) return from;\n        int l = lca(from, to);\n        int d = dist(from,\
    \ to);\n        if(d < k) return -1;\n        if(depth[from] - depth[l] >= k)\
    \ return la(from, k);\n        k -= depth[from] - depth[l];\n        return la(to,\
    \ depth[to] - depth[l] - k);\n    }\n\n    void subtree_query(int a, const function<void(int,\
    \ int)> &func){\n        func(in[a], out[a]);\n    }\n\n    void path_query(int\
    \ a, int b, const function<void(int, int)> &func, bool include_root = true, bool\
    \ reverse_path = false){\n        vector<pair<int, int>> path;\n        int pa\
    \ = pathtop[a], pb = pathtop[b];\n        while(pathtop[a] != pathtop[b]){\n \
    \           if(in[pa] > in[pb]){\n                path.emplace_back(in[pa], in[a]\
    \ + 1);\n                a = parent[pa], pa = pathtop[a];\n            } else{\n\
    \                path.emplace_back(in[pb], in[b] + 1);\n                b = parent[pb],\
    \ pb = pathtop[b];\n            }\n        }\n        if(in[a] > in[b]) swap(a,\
    \ b);\n\n        if(include_root) path.emplace_back(in[a], in[b] + 1);\n     \
    \   else path.emplace_back(in[a] + 1, in[b] + 1);\n\n        if(!reverse_path)\
    \ reverse(path.begin(), path.end());\n        else for(auto &p : path) p = make_pair(V\
    \ - p.second, V - p.first);\n\n        for(auto [u, v] : path){\n            func(u,\
    \ v);\n        }\n    }\n\n    void path_noncommutative_query(int a, int b, const\
    \ function<void(int, int)> &func, const function<void(int, int)> &func2){\n  \
    \      int l = lca(a, b);\n        path_query(a, l, func2, false, true);\n   \
    \     path_query(l, b, func, true, false);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Heavy Light Decomposition (\u91CD\u8EFD\u5206\
    \u89E3)\n * @docs docs/graph/heavy_light_decomposition.md\n */\n\nclass HeavyLightDecomposition{\n\
    protected:\n    int V;\n    vector<vector<int>> G;\n    vector<int> stsize, parent,\
    \ pathtop, depth, in, reverse_in, out;\n    int root;\n\nprivate:\n    // Subtree\
    \ Size\n    void buildStsize(int curr, int prev){\n        stsize[curr] = 1, parent[curr]\
    \ = prev;\n        for(int &v : G[curr]){\n            if(v == prev){\n      \
    \          if(v == G[curr].back()) break;\n                else swap(v, G[curr].back());\n\
    \            }\n            buildStsize(v, curr);\n            stsize[curr] +=\
    \ stsize[v];\n            if(stsize[v] > stsize[G[curr][0]]){\n              \
    \  swap(v, G[curr][0]);\n            }\n        }\n    }\n\n    void buildPath(int\
    \ curr, int prev, int &t){\n        in[curr] = t++;\n        reverse_in[in[curr]]\
    \ = curr;\n        for(int v : G[curr]){\n            if(v == prev) continue;\n\
    \n            if(v == G[curr][0]){\n                pathtop[v] = pathtop[curr];\n\
    \            } else{\n                pathtop[v] = v;\n            }\n       \
    \     depth[v] = depth[curr] + 1;\n            buildPath(v, curr, t);\n      \
    \  }\n        out[curr] = t;\n    }\n\npublic:\n    HeavyLightDecomposition(int\
    \ node_size) : V(node_size), G(V), stsize(V, 0), parent(V, -1),\n        pathtop(V,\
    \ -1), depth(V, 0), in(V, -1), reverse_in(V, -1), out(V, -1){}\n\n    void add_edge(int\
    \ u, int v){\n        G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\n\
    \    void build(int _root = 0){\n        root = _root;\n        int t = 0;\n \
    \       buildStsize(root, -1);\n        pathtop[root] = root;\n        buildPath(root,\
    \ -1, t);\n    }\n\n    inline int get(int a){\n        return in[a];\n    }\n\
    \n    int la(int a, int k) {\n        while(true){\n            int u = pathtop[a];\n\
    \            if(in[a] - k >= in[u]) return reverse_in[in[a] - k];\n          \
    \  k -= in[a] - in[u] + 1;\n            a = parent[u];\n        }\n    }\n\n \
    \   int lca(int a, int b){\n        int pa = pathtop[a], pb = pathtop[b];\n  \
    \      while(pathtop[a] != pathtop[b]){\n            if(in[pa] > in[pb]){\n  \
    \              a = parent[pa], pa = pathtop[a];\n            } else{\n       \
    \         b = parent[pb], pb = pathtop[b];\n            }\n        }\n       \
    \ if(in[a] > in[b]) swap(a, b);\n        return a;\n    }\n\n    int dist(int\
    \ a, int b){ return depth[a] + depth[b] - 2 * depth[lca(a, b)]; }\n\n    int jump(int\
    \ from, int to, int k) {\n        if(!k) return from;\n        int l = lca(from,\
    \ to);\n        int d = dist(from, to);\n        if(d < k) return -1;\n      \
    \  if(depth[from] - depth[l] >= k) return la(from, k);\n        k -= depth[from]\
    \ - depth[l];\n        return la(to, depth[to] - depth[l] - k);\n    }\n\n   \
    \ void subtree_query(int a, const function<void(int, int)> &func){\n        func(in[a],\
    \ out[a]);\n    }\n\n    void path_query(int a, int b, const function<void(int,\
    \ int)> &func, bool include_root = true, bool reverse_path = false){\n       \
    \ vector<pair<int, int>> path;\n        int pa = pathtop[a], pb = pathtop[b];\n\
    \        while(pathtop[a] != pathtop[b]){\n            if(in[pa] > in[pb]){\n\
    \                path.emplace_back(in[pa], in[a] + 1);\n                a = parent[pa],\
    \ pa = pathtop[a];\n            } else{\n                path.emplace_back(in[pb],\
    \ in[b] + 1);\n                b = parent[pb], pb = pathtop[b];\n            }\n\
    \        }\n        if(in[a] > in[b]) swap(a, b);\n\n        if(include_root)\
    \ path.emplace_back(in[a], in[b] + 1);\n        else path.emplace_back(in[a] +\
    \ 1, in[b] + 1);\n\n        if(!reverse_path) reverse(path.begin(), path.end());\n\
    \        else for(auto &p : path) p = make_pair(V - p.second, V - p.first);\n\n\
    \        for(auto [u, v] : path){\n            func(u, v);\n        }\n    }\n\
    \n    void path_noncommutative_query(int a, int b, const function<void(int, int)>\
    \ &func, const function<void(int, int)> &func2){\n        int l = lca(a, b);\n\
    \        path_query(a, l, func2, false, true);\n        path_query(l, b, func,\
    \ true, false);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/heavy_light_decomposition.hpp
  requiredBy:
  - lib/graph/auxiliary_tree.hpp
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_901.test.cpp
  - test/library_checker/tree/vertex_set_path_composite.test.cpp
  - test/library_checker/tree/lca_hl.test.cpp
  - test/library_checker/tree/vertex_add_path_sum.test.cpp
  - test/library_checker/tree/jump_on_tree.test.cpp
  - test/library_checker/tree/vertex_add_subtree_sum.test.cpp
documentation_of: lib/graph/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/lib/graph/heavy_light_decomposition.hpp
- /library/lib/graph/heavy_light_decomposition.hpp.html
title: "Heavy Light Decomposition (\u91CD\u8EFD\u5206\u89E3)"
---
## Heavy Light Decomposition (重軽分解)

#### 概要

木の重軽分解を行います。

#### 使い方

- `HeavyLightDecomposition(node_size)`: コンストラクタ (node_size は頂点数)
- `add_edge(u, v)`: 頂点 $u$ から 頂点 $v$ に無向辺を追加します。
- `build()`: 重軽分解を行います。
- `get(a)`: $a$ の重軽分解後の index を返します。
- `la(a, k)`: $a$ から根に向かって $k$ 移動した頂点を求めます。
- `lca(a, b)`: $a$ と $b$ の LCA を求めます。
- `dist(a, b)`: $a, b$ の距離を求めます。
- `jump(from, to, k)`: from から to に向かって $k$ だけ移動した頂点を求めます。
- `subtree_query(a, f)`: $a$ の部分木に対して $f$ を処理します。
- `path_query(a, b, f)`: $a$ と $b$ のパスに対して $f$ を処理します。
- `path_noncommutative_query(a, b, f, f2)`: $a$ と $b$ のパスに対して非可換な場合の f を処理します。(反転させた関数を f2 に渡します)

詳しい使い方などは verify のコードを参照してください。

#### 計算量

頂点数を $V$ とします。
- `HeavyLightDecomposition(node_size)`: $\mathrm{O}(V)$
- `add_edge(u, v)`: $\mathrm{O}(1)$
- `build()`: $\mathrm{O}(V \log V)$
- `get(a)`: $\mathrm{O}(1)$
- `la(a, k)`: $\mathrm{O}(\log V)$
- `lca(a, b)`: $\mathrm{O}(\log V)$
- `dist(a, b)`: $\mathrm{O}(\log V)$
- `jump(from, to, k)`: $\mathrm{O}(\log V)$
- `subtree_query(a, f)`: $\mathrm{O}(1)$
- `path_query(a, b, f)`: $\mathrm{O}(\log V)$
- `path_noncommutative_query(a, b, f, f2)`: $\mathrm{O}(\log V)$

subtree_query, path_query, path_noncommutative_query については、$f$ の計算量が $\mathrm{O}(f(n))$ である場合には実際の計算量は $\mathrm{O}(f(n))$ 倍になります。