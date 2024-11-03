---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/tree_path_composite_sum.test.cpp
    title: test/library_checker/tree/tree_path_composite_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Rerooting (\u5168\u65B9\u4F4D\u6728DP)"
    links:
    - https://trap.jp/post/1702/
  bundledCode: "#line 2 \"lib/graph/rerooting.hpp\"\n\n/**\n * @brief Rerooting (\u5168\
    \u65B9\u4F4D\u6728DP)\n * @see https://trap.jp/post/1702/\n */\n\ntemplate<typename\
    \ E, typename V>\nstruct Rerooting{\n    struct edge{\n        int from, to, idx,\
    \ rev_idx;\n    };\n    int n, root;\n    vector<vector<edge>> edges;\n    vector<int>\
    \ visited;\n    vector<vector<E>> out;\n    vector<E> reverse_edge;\n    vector<V>\
    \ ans;\n    function<E(E, E)> merge;\n    E e;\n    function<E(V, int)> put_edge;\n\
    \    function<V(E, int)> put_vertex;\n    Rerooting(int _n, const function<E(E,\
    \ E)> &_merge, const E &_e, const function<E(V, int)> &_put_edge, const function<V(E,\
    \ int)> &_put_vertex) : n(_n), merge(_merge), e(_e), put_edge(_put_edge), put_vertex(_put_vertex){\n\
    \        edges.resize(n);\n    }\n\nprivate:\n    V dfs(int v){\n        visited[v]++;\n\
    \        E val = e;\n        for(auto &p : edges[v]){\n            if(visited[p.to]\
    \ > 0 && p.to != edges[v].back().to){\n                swap(p, edges[v].back());\n\
    \            }\n            if(visited[p.to] > 0) continue;\n            E nval\
    \ = put_edge(dfs(p.to), p.idx);\n            out[v].emplace_back(nval);\n    \
    \        val = merge(val, nval);\n        }\n        return put_vertex(val, v);\n\
    \    }\n\n    void bfs(int v){\n        int siz = out[v].size();\n        vector<E>\
    \ left(siz + 1), right(siz + 1);\n        left[0] = e, right[siz] = e;\n     \
    \   for(int i = 0; i < siz; i++){\n            left[i + 1] = merge(left[i], out[v][i]);\n\
    \        }\n        for(int i = siz - 1; i >= 0; i--){\n            right[i] =\
    \ merge(out[v][i], right[i + 1]);\n        }\n        for(int i = 0; i < siz;\
    \ i++){\n            reverse_edge[edges[v][i].to] = put_edge(put_vertex(merge(merge(left[i],\
    \ right[i + 1]), reverse_edge[v]), v), edges[v][i].rev_idx);\n            bfs(edges[v][i].to);\n\
    \        }\n        ans[v] = put_vertex(merge(left[siz], reverse_edge[v]), v);\n\
    \    }\n\npublic:\n    void add_edge(int u, int v, int idx1, int idx2){\n    \
    \    edges[u].push_back({u, v, idx1, idx2});\n        edges[v].push_back({v, u,\
    \ idx2, idx1});\n    }\n\n    V build(int v = 0){\n        root = v;\n       \
    \ out.resize(n);\n        visited.assign(n, 0);\n        return dfs(root);\n \
    \   }\n\n    vector<V> reroot(){\n        reverse_edge.resize(n);\n        reverse_edge[root]\
    \ = e;\n        ans.resize(n);\n        bfs(root);\n        return ans;\n    }\n\
    };\n"
  code: "#pragma once\n\n/**\n * @brief Rerooting (\u5168\u65B9\u4F4D\u6728DP)\n *\
    \ @see https://trap.jp/post/1702/\n */\n\ntemplate<typename E, typename V>\nstruct\
    \ Rerooting{\n    struct edge{\n        int from, to, idx, rev_idx;\n    };\n\
    \    int n, root;\n    vector<vector<edge>> edges;\n    vector<int> visited;\n\
    \    vector<vector<E>> out;\n    vector<E> reverse_edge;\n    vector<V> ans;\n\
    \    function<E(E, E)> merge;\n    E e;\n    function<E(V, int)> put_edge;\n \
    \   function<V(E, int)> put_vertex;\n    Rerooting(int _n, const function<E(E,\
    \ E)> &_merge, const E &_e, const function<E(V, int)> &_put_edge, const function<V(E,\
    \ int)> &_put_vertex) : n(_n), merge(_merge), e(_e), put_edge(_put_edge), put_vertex(_put_vertex){\n\
    \        edges.resize(n);\n    }\n\nprivate:\n    V dfs(int v){\n        visited[v]++;\n\
    \        E val = e;\n        for(auto &p : edges[v]){\n            if(visited[p.to]\
    \ > 0 && p.to != edges[v].back().to){\n                swap(p, edges[v].back());\n\
    \            }\n            if(visited[p.to] > 0) continue;\n            E nval\
    \ = put_edge(dfs(p.to), p.idx);\n            out[v].emplace_back(nval);\n    \
    \        val = merge(val, nval);\n        }\n        return put_vertex(val, v);\n\
    \    }\n\n    void bfs(int v){\n        int siz = out[v].size();\n        vector<E>\
    \ left(siz + 1), right(siz + 1);\n        left[0] = e, right[siz] = e;\n     \
    \   for(int i = 0; i < siz; i++){\n            left[i + 1] = merge(left[i], out[v][i]);\n\
    \        }\n        for(int i = siz - 1; i >= 0; i--){\n            right[i] =\
    \ merge(out[v][i], right[i + 1]);\n        }\n        for(int i = 0; i < siz;\
    \ i++){\n            reverse_edge[edges[v][i].to] = put_edge(put_vertex(merge(merge(left[i],\
    \ right[i + 1]), reverse_edge[v]), v), edges[v][i].rev_idx);\n            bfs(edges[v][i].to);\n\
    \        }\n        ans[v] = put_vertex(merge(left[siz], reverse_edge[v]), v);\n\
    \    }\n\npublic:\n    void add_edge(int u, int v, int idx1, int idx2){\n    \
    \    edges[u].push_back({u, v, idx1, idx2});\n        edges[v].push_back({v, u,\
    \ idx2, idx1});\n    }\n\n    V build(int v = 0){\n        root = v;\n       \
    \ out.resize(n);\n        visited.assign(n, 0);\n        return dfs(root);\n \
    \   }\n\n    vector<V> reroot(){\n        reverse_edge.resize(n);\n        reverse_edge[root]\
    \ = e;\n        ans.resize(n);\n        bfs(root);\n        return ans;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/rerooting.hpp
  requiredBy: []
  timestamp: '2024-11-01 00:31:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/tree/tree_path_composite_sum.test.cpp
documentation_of: lib/graph/rerooting.hpp
layout: document
redirect_from:
- /library/lib/graph/rerooting.hpp
- /library/lib/graph/rerooting.hpp.html
title: "Rerooting (\u5168\u65B9\u4F4D\u6728DP)"
---
