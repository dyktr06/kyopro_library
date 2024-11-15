---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/auxiliary_tree.hpp
    title: Auxiliary Tree
  - icon: ':question:'
    path: lib/graph/heavy_light_decomposition.hpp
    title: "Heavy Light Decomposition (\u91CD\u8EFD\u5206\u89E3)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/901
    links:
    - https://yukicoder.me/problems/no/901
  bundledCode: "#line 1 \"test/yukicoder/yuki_901.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/901\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/auxiliary_tree.hpp\"\
    \n\n/**\n * @brief Auxiliary Tree\n * @see https://smijake3.hatenablog.com/entry/2019/09/15/200200\n\
    \ */\n\n#line 2 \"lib/graph/heavy_light_decomposition.hpp\"\n\n/**\n * @brief\
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
    \     path_query(l, b, func, true, false);\n    }\n};\n#line 9 \"lib/graph/auxiliary_tree.hpp\"\
    \n\nstruct AuxiliaryTree : HeavyLightDecomposition{\n    using super = HeavyLightDecomposition;\n\
    \nprivate:\n    void add_aux_edge(int u, int v){\n        T[u].emplace_back(v);\n\
    \        T[v].emplace_back(u);\n    }\n\npublic:\n    vector<vector<int>> T;\n\
    \    AuxiliaryTree(int n) : super(n), T(n){}\n\n    void build(int _root = 0){\n\
    \        super::build(_root);\n    }\n\n    void query(vector<int> &vs){\n   \
    \     assert(!vs.empty());\n        sort(vs.begin(), vs.end(),\n            [&](int\
    \ a, int b){ return in[a] < in[b]; });\n        vs.erase(unique(vs.begin(), vs.end()),\
    \ vs.end());\n\n        int k = vs.size();\n        vector<int> st;\n        st.emplace_back(vs[0]);\n\
    \        for(int i = 0; i + 1 < k; i++){\n            int p = lca(vs[i], vs[i\
    \ + 1]);\n            if(p != vs[i]){\n                int l = st.back(); st.pop_back();\n\
    \                while(!st.empty() && depth[p] < depth[st.back()]){\n        \
    \            add_aux_edge(st.back(), l);\n                    l = st.back(); st.pop_back();\n\
    \                }\n                if(st.empty() || st.back() != p){\n      \
    \              st.emplace_back(p);\n                    vs.emplace_back(p);\n\
    \                }\n                add_aux_edge(p, l);\n            }\n     \
    \       st.emplace_back(vs[i + 1]);\n        }\n\n        while(st.size() > 1){\n\
    \            int c = st.back(); st.pop_back();\n            add_aux_edge(st.back(),\
    \ c);\n        }\n    }\n\n    void clear(const vector<int> &ws){\n        for(int\
    \ w : ws){\n            T[w].clear();\n        }\n    }\n};\n#line 6 \"test/yukicoder/yuki_901.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int n; cin >> n;\n    AuxiliaryTree G(n);\n    vector<int> u(n - 1), v(n -\
    \ 1), w(n - 1);\n    for(int i = 0; i < n - 1; i++){\n        cin >> u[i] >> v[i]\
    \ >> w[i];\n        G.add_edge(u[i], v[i]);\n    }\n    G.build();\n\n    vector<long\
    \ long> a(n);\n    for(int i = 0; i < n - 1; i++){\n        int idx = max(G.get(u[i]),\
    \ G.get(v[i]));\n        a[idx] = w[i];\n    }\n    vector<long long> cs(n + 1);\n\
    \    for(int i = 0; i < n; i++){\n        cs[i + 1] = cs[i] + a[i];\n    }\n\n\
    \    long long ans = 0;\n    auto query = [&](int l, int r){\n        ans += cs[r]\
    \ - cs[l];\n    };\n    auto dfs = [&](auto self, int curr, int prev) -> void\
    \ {\n        for(auto v : G.T[curr]){\n            if(v == prev) continue;\n \
    \           G.path_query(curr, v, query, false, false);\n            self(self,\
    \ v, curr);\n        }\n    };\n\n    int q; cin >> q;\n    while(q--){\n    \
    \    int k; cin >> k;\n        vector<int> x(k);\n        for(int i = 0; i < k;\
    \ i++) cin >> x[i];\n        G.query(x);\n        ans = 0;\n        dfs(dfs, x[0],\
    \ -1);\n        G.clear(x);\n        cout << ans << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/901\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../lib/graph/auxiliary_tree.hpp\"\n\nint\
    \ main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int\
    \ n; cin >> n;\n    AuxiliaryTree G(n);\n    vector<int> u(n - 1), v(n - 1), w(n\
    \ - 1);\n    for(int i = 0; i < n - 1; i++){\n        cin >> u[i] >> v[i] >> w[i];\n\
    \        G.add_edge(u[i], v[i]);\n    }\n    G.build();\n\n    vector<long long>\
    \ a(n);\n    for(int i = 0; i < n - 1; i++){\n        int idx = max(G.get(u[i]),\
    \ G.get(v[i]));\n        a[idx] = w[i];\n    }\n    vector<long long> cs(n + 1);\n\
    \    for(int i = 0; i < n; i++){\n        cs[i + 1] = cs[i] + a[i];\n    }\n\n\
    \    long long ans = 0;\n    auto query = [&](int l, int r){\n        ans += cs[r]\
    \ - cs[l];\n    };\n    auto dfs = [&](auto self, int curr, int prev) -> void\
    \ {\n        for(auto v : G.T[curr]){\n            if(v == prev) continue;\n \
    \           G.path_query(curr, v, query, false, false);\n            self(self,\
    \ v, curr);\n        }\n    };\n\n    int q; cin >> q;\n    while(q--){\n    \
    \    int k; cin >> k;\n        vector<int> x(k);\n        for(int i = 0; i < k;\
    \ i++) cin >> x[i];\n        G.query(x);\n        ans = 0;\n        dfs(dfs, x[0],\
    \ -1);\n        G.clear(x);\n        cout << ans << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/graph/auxiliary_tree.hpp
  - lib/graph/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: test/yukicoder/yuki_901.test.cpp
  requiredBy: []
  timestamp: '2024-11-01 00:31:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/yuki_901.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/yuki_901.test.cpp
- /verify/test/yukicoder/yuki_901.test.cpp.html
title: test/yukicoder/yuki_901.test.cpp
---
