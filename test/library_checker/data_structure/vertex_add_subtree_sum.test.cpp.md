---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/binary_indexed_tree.hpp
    title: lib/data_structure/binary_indexed_tree.hpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/heavy_light_decomposition.hpp
    title: lib/graph/heavy_light_decomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/library_checker/data_structure/vertex_add_subtree_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/binary_indexed_tree.hpp\"\
    \n\n/* \n    binary_indexed_tree<T>(n) : BIT\u3092\u30B5\u30A4\u30BAn\u3067\u69CB\
    \u7BC9\n    get(i)    : i \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002 O(log(n))\n    add(i, x) : i \u756A\u76EE\u306E\u8981\u7D20\
    \u306B\u52A0\u7B97\u3057\u307E\u3059\u3002 O(log(n))\n    sum(l, r) : [l, r) \u306E\
    \u533A\u9593\u548C\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002O(log(n))\n    \n\
    \    (\u4EE5\u4E0B\u306E\u6A5F\u80FD\u3092\u4F7F\u3046\u306B\u306F\u30010 <= i\
    \ < N \u306B\u304A\u3044\u3066\u3001A_i >= 0 \u3067\u3042\u308B\u5FC5\u8981\u304C\
    \u3042\u308A\u307E\u3059\u3002)\n    lower_bound(x) : A_0 + A_1 + ... + A_y >=\
    \ x \u3068\u306A\u308B\u6700\u5C0F\u306E y \u3092\u6C42\u3081\u307E\u3059\u3002\
    O(log(n))\n    upper_bound(x) : A_0 + A_1 + ... + A_y > x \u3068\u306A\u308B\u6700\
    \u5C0F\u306E y \u3092\u6C42\u3081\u307E\u3059\u3002O(log(n))\n*/\n\ntemplate <typename\
    \ T>\nstruct BinaryIndexedTree{\n    int N;\n    vector<T> BIT;\n    BinaryIndexedTree(const\
    \ int &N): N(N), BIT(N + 1, 0){\n    }\n\n    T get(int i){\n        return sum(i\
    \ + 1) - sum(i);\n    }\n\n    void add(int i, T x){\n        i++;\n        while(i\
    \ <= N){\n            BIT[i] += x;\n            i += i & -i;\n        }\n    }\n\
    \n    T sum(int i) const {\n        T ans = 0;\n        while(i > 0){\n      \
    \      ans += BIT[i];\n            i -= i & -i;\n        }\n        return ans;\n\
    \    }\n\n    T sum(int L, int R) const {\n        return sum(R) - sum(L);\n \
    \   }\n\n    int lower_bound(T x) const {\n        if(x <= 0){\n            return\
    \ 0;\n        }else{\n            int v = 0, r = 1;\n            while(r < N)\
    \ r = r << 1;\n            for(int len = r; len > 0; len = len >> 1){\n      \
    \          if(v + len < N && BIT[v + len] < x){\n                    x -= BIT[v\
    \ + len];\n                    v += len;\n                }\n            }\n \
    \           return v;\n        }\n    }\n\n    int upper_bound(T x) const {\n\
    \        if(x < 0){\n            return 0;\n        }else{\n            int v\
    \ = 0, r = 1;\n            while(r <= N) r = r << 1;\n            for(int len\
    \ = r; len > 0; len = len >> 1){\n                if(v + len <= N && BIT[v + len]\
    \ <= x){\n                    x -= BIT[v + len];\n                    v += len;\n\
    \                }\n            }\n            return v;\n        }\n    }\n};\n\
    #line 2 \"lib/graph/heavy_light_decomposition.hpp\"\n\n/* \n    \u6728\u306B\u5BFE\
    \u3057\u3066\u91CD\u8EFD\u5206\u89E3\u3092\u884C\u3044\u307E\u3059\u3002\n   \
    \ HeavyLightDecomposition(node_size) : \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n    add_edge(u, v) : \u9802\u70B9 u \u304B\u3089 \u9802\u70B9 v \u306B\u7121\
    \u5411\u8FBA\u3092\u8FFD\u52A0\u3057\u307E\u3059\u3002: O(1)\n    build() : \u91CD\
    \u8EFD\u5206\u89E3\u3092\u884C\u3044\u307E\u3059\u3002: O(V log V)\n    get(a)\
    \ : a \u306E\u91CD\u8EFD\u5206\u89E3\u5F8C\u306E index \u3092\u8FD4\u3057\u307E\
    \u3059\u3002: O(1)\n    la(a, k): a \u304B\u3089\u6839\u306B\u5411\u304B\u3063\
    \u3066 k \u79FB\u52D5\u3057\u305F\u9802\u70B9\u3092\u6C42\u3081\u307E\u3059\u3002\
    : O(log V)\n    lca(a, b): a \u3068 b \u306E LCA \u3092\u6C42\u3081\u307E\u3059\
    \u3002: O(log V)\n    dist(a, b): a, b \u306E\u8DDD\u96E2\u3092\u6C42\u3081\u307E\
    \u3059\u3002: O(log V)\n    jump(from, to, k): from \u304B\u3089 to \u306B\u5411\
    \u304B\u3063\u3066 k \u79FB\u52D5\u3057\u305F\u9802\u70B9\u3092\u6C42\u3081\u307E\
    \u3059\u3002: O(log V)\n    subtree_query(a, f): a \u306E\u90E8\u5206\u6728 f\
    \ \u3092\u51E6\u7406\u3057\u307E\u3059\u3002: O(log V)\n    path_query(a, b, f):\
    \ a \u3068 b \u306E\u30D1\u30B9\u306B\u5BFE\u3057\u3066 f \u3092\u51E6\u7406\u3057\
    \u307E\u3059\u3002: O(log^2 V)\n    path_noncommutative_query(a, b, f, f2): a\
    \ \u3068 b \u306E\u30D1\u30B9\u306B\u5BFE\u3057\u3066\u975E\u53EF\u63DB\u306A\u5834\
    \u5408\u306E f \u3092\u51E6\u7406\u3057\u307E\u3059\u3002(\u53CD\u8EE2\u3055\u305B\
    \u305F\u95A2\u6570\u3092 f2 \u306B\u6E21\u3057\u307E\u3059): O(log^2 V)\n\n  \
    \  \u30D1\u30B9\u30AF\u30A8\u30EA\u306E\u4F8B\n    // ex) hl.path_query(q, r,\
    \ [&](int l, int r){ seg.range(l, r, s); })\n    // ex) hl.query(q, r, [&](int\
    \ l, int r){ ans += seg.query(l, r); })\n*/\n\nclass HeavyLightDecomposition{\n\
    \    int V;\n    vector<vector<int>> G;\n    vector<int> stsize, parent, pathtop,\
    \ depth, in, reverse_in, out;\n    int root;\n\nprivate:\n    // Subtree Size\n\
    \    void buildStsize(int curr, int prev){\n        stsize[curr] = 1, parent[curr]\
    \ = prev;\n        for(int &v : G[curr]){\n            if(v == prev){\n      \
    \          if(v == G[curr].back()) break;\n                else swap(v, G[curr].back());\n\
    \            }\n            buildStsize(v, curr);\n            stsize[curr] +=\
    \ stsize[v];\n            if(stsize[v] > stsize[G[curr][0]]){\n              \
    \  swap(v, G[curr][0]);\n            }\n        }\n    }\n\n    void buildPath(int\
    \ curr, int prev, int &t){\n        in[curr] = t++;\n        reverse_in[in[curr]]\
    \ = curr;\n        for(int v : G[curr]){\n            if(v == prev) continue;\n\
    \            \n            if(v == G[curr][0]){\n                pathtop[v] =\
    \ pathtop[curr];\n            }else{\n                pathtop[v] = v;\n      \
    \      }\n            depth[v] = depth[curr] + 1;\n            buildPath(v, curr,\
    \ t);\n        }\n        out[curr] = t;\n    }\n\npublic:\n    HeavyLightDecomposition(int\
    \ node_size) : V(node_size), G(V), stsize(V, 0), parent(V, -1),\n    pathtop(V,\
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
    \              a = parent[pa], pa = pathtop[a];\n            }else{\n        \
    \        b = parent[pb], pb = pathtop[b];\n            }\n        }\n        if(in[a]\
    \ > in[b]) swap(a, b);\n        return a;\n    }\n\n    int dist(int a, int b){\
    \ return depth[a] + depth[b] - 2 * depth[lca(a, b)]; }\n\n    int jump(int from,\
    \ int to, int k) {\n        if(!k) return from;\n        int l = lca(from, to);\n\
    \        int d = dist(from, to);\n        if(d < k) return -1;\n        if(depth[from]\
    \ - depth[l] >= k) return la(from, k);\n        k -= depth[from] - depth[l];\n\
    \        return la(to, depth[to] - depth[l] - k);\n    }\n\n    void subtree_query(int\
    \ a, const function<void(int, int)> &func){\n        func(in[a], out[a]);\n  \
    \  }\n\n    void path_query(int a, int b, const function<void(int, int)> &func,\
    \ bool include_root = true, bool reverse_path = false){\n        vector<pair<int,\
    \ int>> path;\n        int pa = pathtop[a], pb = pathtop[b];\n        while(pathtop[a]\
    \ != pathtop[b]){\n            if(in[pa] > in[pb]){\n                path.emplace_back(in[pa],\
    \ in[a] + 1);\n                a = parent[pa], pa = pathtop[a];\n            }else{\n\
    \                path.emplace_back(in[pb], in[b] + 1);\n                b = parent[pb],\
    \ pb = pathtop[b];\n            }\n        }\n        if(in[a] > in[b]) swap(a,\
    \ b);\n\n        if(include_root) path.emplace_back(in[a], in[b] + 1);\n     \
    \   else path.emplace_back(in[a] + 1, in[b] + 1);\n        \n        if(!reverse_path)\
    \ reverse(path.begin(), path.end());\n        else for(auto& p : path) p = make_pair(V\
    \ - p.second, V - p.first);\n\n        for(auto [u, v] : path){\n            func(u,\
    \ v);\n        }\n    }\n\n    void path_noncommutative_query(int a, int b, const\
    \ function<void(int, int)> &func, const function<void(int, int)> &func2){\n  \
    \      int l = lca(a, b);\n        path_query(a, l, func2, false, true);\n   \
    \     path_query(l, b, func, true, false);\n    }\n};\n#line 7 \"test/library_checker/data_structure/vertex_add_subtree_sum.test.cpp\"\
    \n\nint main(){\n    int n, q; cin >> n >> q;\n    vector<int> a(n);\n    for(int\
    \ i = 0; i < n; i++){\n        cin >> a[i];\n    }\n    HeavyLightDecomposition\
    \ hl(n);\n    for(int i = 1; i < n; i++){\n        int p; cin >> p;\n        hl.add_edge(p,\
    \ i);\n    }\n    hl.build();\n    BinaryIndexedTree<long long> BIT(n);\n    for(int\
    \ i = 0; i < n; i++){\n        BIT.add(hl.get(i), a[i]);\n    }\n    long long\
    \ ans = 0;\n    auto query = [&](int l, int r){\n        ans += BIT.sum(l, r);\n\
    \    };\n    while(q--){\n        int t; cin >> t;\n        if(t == 0){\n    \
    \        int p, x; cin >> p >> x;\n            BIT.add(hl.get(p), x);\n      \
    \  }else{\n            int u; cin >> u;\n            ans = 0;\n            hl.subtree_query(u,\
    \ query);\n            cout << ans << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/binary_indexed_tree.hpp\"\
    \n#include \"../../../lib/graph/heavy_light_decomposition.hpp\"\n\nint main(){\n\
    \    int n, q; cin >> n >> q;\n    vector<int> a(n);\n    for(int i = 0; i < n;\
    \ i++){\n        cin >> a[i];\n    }\n    HeavyLightDecomposition hl(n);\n   \
    \ for(int i = 1; i < n; i++){\n        int p; cin >> p;\n        hl.add_edge(p,\
    \ i);\n    }\n    hl.build();\n    BinaryIndexedTree<long long> BIT(n);\n    for(int\
    \ i = 0; i < n; i++){\n        BIT.add(hl.get(i), a[i]);\n    }\n    long long\
    \ ans = 0;\n    auto query = [&](int l, int r){\n        ans += BIT.sum(l, r);\n\
    \    };\n    while(q--){\n        int t; cin >> t;\n        if(t == 0){\n    \
    \        int p, x; cin >> p >> x;\n            BIT.add(hl.get(p), x);\n      \
    \  }else{\n            int u; cin >> u;\n            ans = 0;\n            hl.subtree_query(u,\
    \ query);\n            cout << ans << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - lib/data_structure/binary_indexed_tree.hpp
  - lib/graph/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2022-12-28 20:23:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/vertex_add_subtree_sum.test.cpp
- /verify/test/library_checker/data_structure/vertex_add_subtree_sum.test.cpp.html
title: test/library_checker/data_structure/vertex_add_subtree_sum.test.cpp
---
