---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/graph/rerooting.hpp
    title: lib/graph/rerooting.hpp
  - icon: ':question:'
    path: lib/math/modint.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
  bundledCode: "#line 1 \"test/library_checker/tree/tree_path_composite_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/rerooting.hpp\"\
    \n\ntemplate<typename E, typename V>\nstruct Rerooting{\n    struct edge{\n  \
    \      int from, to, idx, rev_idx;\n    };\n    int n, root;\n    vector<vector<edge>>\
    \ edges;\n    vector<int> visited;\n    vector<vector<E>> out;\n    vector<E>\
    \ reverse_edge;\n    vector<V> ans;\n    function<E(E, E)> merge;\n    E e;\n\
    \    function<E(V, int)> put_edge;\n    function<V(E, int)> put_vertex;\n    Rerooting(int\
    \ _n, const function<E(E, E)> &_merge, const E &_e, const function<E(V, int)>\
    \ &_put_edge, const function<V(E, int)> &_put_vertex) : n(_n), merge(_merge),\
    \ e(_e), put_edge(_put_edge), put_vertex(_put_vertex){\n        edges.resize(n);\n\
    \    }\n\nprivate:\n    V dfs(int v){\n        visited[v]++;\n        E val =\
    \ e;\n        for(auto &p : edges[v]){\n            if(visited[p.to] > 0 && p.to\
    \ != edges[v].back().to){\n                swap(p, edges[v].back());\n       \
    \     }\n            if(visited[p.to] > 0) continue;\n            E nval = put_edge(dfs(p.to),\
    \ p.idx);\n            out[v].emplace_back(nval);\n            val = merge(val,\
    \ nval);\n        }\n        return put_vertex(val, v);\n    }\n\n    void bfs(int\
    \ v){\n        int siz = out[v].size();\n        vector<E> left(siz + 1), right(siz\
    \ + 1);\n        left[0] = e, right[siz] = e;\n        for(int i = 0; i < siz;\
    \ i++){\n            left[i + 1] = merge(left[i], out[v][i]);\n        }\n   \
    \     for(int i = siz - 1; i >= 0; i--){\n            right[i] = merge(out[v][i],\
    \ right[i + 1]);\n        }\n        for(int i = 0; i < siz; i++){\n         \
    \   reverse_edge[edges[v][i].to] = put_edge(put_vertex(merge(merge(left[i], right[i\
    \ + 1]), reverse_edge[v]), v), edges[v][i].rev_idx);\n            bfs(edges[v][i].to);\n\
    \        }\n        ans[v] = put_vertex(merge(left[siz], reverse_edge[v]), v);\n\
    \    }\n\npublic:\n    void add_edge(int u, int v, int idx1, int idx2){\n    \
    \    edges[u].push_back({u, v, idx1, idx2});\n        edges[v].push_back({v, u,\
    \ idx2, idx1});\n    }\n\n    V build(int v = 0){\n        root = v;\n       \
    \ out.resize(n);\n        visited.assign(n, 0);\n        return dfs(root);\n \
    \   }\n\n    vector<V> reroot(){\n        reverse_edge.resize(n);\n        reverse_edge[root]\
    \ = e;\n        ans.resize(n);\n        bfs(root);\n        return ans;\n    }\n\
    };\n#line 2 \"lib/math/modint.hpp\"\n\n#line 4 \"lib/math/modint.hpp\"\n\n/**\n\
    \ * @brief ModInt\n * @docs docs/math/modint.md\n */\n\ntemplate <long long Modulus>\n\
    struct ModInt{\n    long long val;\n    static constexpr int mod() { return Modulus;\
    \ }\n    constexpr ModInt(const long long _val = 0) noexcept : val(_val) {\n \
    \       normalize();\n    }\n    void normalize(){\n        val = (val % Modulus\
    \ + Modulus) % Modulus;\n    }\n    inline ModInt &operator+=(const ModInt &rhs)\
    \ noexcept {\n        if(val += rhs.val, val >= Modulus) val -= Modulus;\n   \
    \     return *this;\n    }\n    inline ModInt &operator-=(const ModInt &rhs) noexcept\
    \ {\n        if(val -= rhs.val, val < 0) val += Modulus;\n        return *this;\n\
    \    }\n    inline ModInt &operator*=(const ModInt &rhs) noexcept {\n        val\
    \ = val * rhs.val % Modulus;\n        return *this;\n    }\n    inline ModInt\
    \ &operator/=(const ModInt &rhs) noexcept {\n        val = val * inv(rhs.val).val\
    \ % Modulus;\n        return *this;\n    }\n    inline ModInt &operator++() noexcept\
    \ {\n        if(++val >= Modulus) val -= Modulus;\n        return *this;\n   \
    \ }\n    inline ModInt operator++(int) noexcept {\n        ModInt t = val;\n \
    \       if(++val >= Modulus) val -= Modulus;\n        return t;\n    }\n    inline\
    \ ModInt &operator--() noexcept {\n        if(--val < 0) val += Modulus;\n   \
    \     return *this;\n    }\n    inline ModInt operator--(int) noexcept {\n   \
    \     ModInt t = val;\n        if(--val < 0) val += Modulus;\n        return t;\n\
    \    }\n    inline ModInt operator-() const noexcept { return (Modulus - val)\
    \ % Modulus; }\n    inline ModInt inv(void) const { return inv(val); }\n    ModInt\
    \ pow(long long n){\n        assert(0 <= n);\n        ModInt x = *this, r = 1;\n\
    \        while(n){\n            if(n & 1) r *= x;\n            x *= x;\n     \
    \       n >>= 1;\n        }\n        return r;\n    }\n    ModInt inv(const long\
    \ long n) const {\n        long long a = n, b = Modulus, u = 1, v = 0;\n     \
    \   while(b){\n            long long t = a / b;\n            a -= t * b; std::swap(a,\
    \ b);\n            u -= t * v; std::swap(u, v);\n        }\n        u %= Modulus;\n\
    \        if(u < 0) u += Modulus;\n        return u;\n    }\n    friend inline\
    \ ModInt operator+(const ModInt &lhs, const ModInt &rhs) noexcept { return ModInt(lhs)\
    \ += rhs; }\n    friend inline ModInt operator-(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept { return ModInt(lhs) -= rhs; }\n    friend inline ModInt operator*(const\
    \ ModInt &lhs, const ModInt &rhs) noexcept { return ModInt(lhs) *= rhs; }\n  \
    \  friend inline ModInt operator/(const ModInt &lhs, const ModInt &rhs) noexcept\
    \ { return ModInt(lhs) /= rhs; }\n    friend inline bool operator==(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept { return lhs.val == rhs.val; }\n    friend\
    \ inline bool operator!=(const ModInt &lhs, const ModInt &rhs) noexcept { return\
    \ lhs.val != rhs.val; }\n    friend inline std::istream &operator>>(std::istream\
    \ &is, ModInt &x) noexcept {\n        is >> x.val;\n        x.normalize();\n \
    \       return is;\n    }\n    friend inline std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &x) noexcept { return os << x.val; }\n};\n#line 7 \"test/library_checker/tree/tree_path_composite_sum.test.cpp\"\
    \n\nusing mint = ModInt<998244353>;\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    \n    int n; cin >> n;\n    vector<mint> a(n), b(n\
    \ - 1), c(n - 1);\n    for(int i = 0; i < n; i++){\n        cin >> a[i];\n   \
    \ }\n    using T = pair<mint, mint>;\n    auto merge = [&](T x, T y){\n      \
    \  T res = {x.first + y.first, x.second + y.second};\n        return res;\n  \
    \  };\n    auto put_edge = [&](T x, int i){\n        T res = {x.first * b[i] +\
    \ x.second * c[i], x.second};\n        return res;\n    };\n    auto put_vertex\
    \ = [&](T e, int v){\n        T res = {e.first + a[v], e.second + 1};\n      \
    \  return res;\n    };\n    T e = {0, 0};\n    Rerooting<T, T> G(n, merge, e,\
    \ put_edge, put_vertex);\n    for(int i = 0; i < n - 1; i++){\n        int u,\
    \ v; cin >> u >> v >> b[i] >> c[i];\n        G.add_edge(u, v, i, i);\n    }\n\
    \    G.build();\n    for(auto &ans : G.reroot()){\n        cout << ans.first <<\
    \ \" \";\n    }\n    cout << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/rerooting.hpp\"\
    \n#include \"../../../lib/math/modint.hpp\"\n\nusing mint = ModInt<998244353>;\n\
    \nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    \n\
    \    int n; cin >> n;\n    vector<mint> a(n), b(n - 1), c(n - 1);\n    for(int\
    \ i = 0; i < n; i++){\n        cin >> a[i];\n    }\n    using T = pair<mint, mint>;\n\
    \    auto merge = [&](T x, T y){\n        T res = {x.first + y.first, x.second\
    \ + y.second};\n        return res;\n    };\n    auto put_edge = [&](T x, int\
    \ i){\n        T res = {x.first * b[i] + x.second * c[i], x.second};\n       \
    \ return res;\n    };\n    auto put_vertex = [&](T e, int v){\n        T res =\
    \ {e.first + a[v], e.second + 1};\n        return res;\n    };\n    T e = {0,\
    \ 0};\n    Rerooting<T, T> G(n, merge, e, put_edge, put_vertex);\n    for(int\
    \ i = 0; i < n - 1; i++){\n        int u, v; cin >> u >> v >> b[i] >> c[i];\n\
    \        G.add_edge(u, v, i, i);\n    }\n    G.build();\n    for(auto &ans : G.reroot()){\n\
    \        cout << ans.first << \" \";\n    }\n    cout << \"\\n\";\n}"
  dependsOn:
  - lib/graph/rerooting.hpp
  - lib/math/modint.hpp
  isVerificationFile: true
  path: test/library_checker/tree/tree_path_composite_sum.test.cpp
  requiredBy: []
  timestamp: '2024-10-31 17:18:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/tree/tree_path_composite_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/tree/tree_path_composite_sum.test.cpp
- /verify/test/library_checker/tree/tree_path_composite_sum.test.cpp.html
title: test/library_checker/tree/tree_path_composite_sum.test.cpp
---
