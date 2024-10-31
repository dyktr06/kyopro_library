---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/enumerate_cliques.hpp
    title: lib/graph/enumerate_cliques.hpp
  - icon: ':question:'
    path: lib/math/modint.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_cliques
    links:
    - https://judge.yosupo.jp/problem/enumerate_cliques
  bundledCode: "#line 1 \"test/library_checker/graph/enumerate_cliques.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_cliques\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/enumerate_cliques.hpp\"\
    \n\nvector<vector<int>> enumerateCliques(vector<vector<int>> &G){\n    int n =\
    \ G.size();\n    int m = 0;\n    vector<pair<int, int>> deg(n);\n    for(int i\
    \ = 0; i < n; i++){\n        m += (int) G[i].size();\n        deg[i] = {(int)\
    \ G[i].size(), i};\n    }\n    m /= 2;\n\n    vector<vector<bool>> adj(n, vector<bool>(n));\n\
    \    for(int i = 0; i < n; i++){\n        for(auto &j : G[i]){\n            adj[i][j]\
    \ = adj[j][i] = true;\n        }\n    }\n\n    // \u6B21\u6570\u304C \u221A2m\
    \ \u672A\u6E80\u304B\u3069\u3046\u304B\u3067\u5834\u5408\u5206\u3051 -> \u6B21\
    \u6570\u304C\u4F4E\u3044\u9802\u70B9\u304B\u3089\u51E6\u7406\u3092\u3057\u3066\
    \u3082\u5341\u5206\u9AD8\u901F (O(2^(\u221A2m) * n^2))\n    sort(deg.begin(),\
    \ deg.end());\n    vector<vector<int>> res;\n    for(int i = 0; i < n; i++){\n\
    \        int cur = deg[i].second;\n        vector<int> nxt;\n        for(int j\
    \ = 0; j < n; j++){\n            if(adj[cur][j]){\n                nxt.push_back(j);\n\
    \            }\n        }\n        int d = nxt.size();\n        for(int bit =\
    \ 0; bit < (1 << d); bit++){\n            vector<int> s = {cur};\n           \
    \ for(int j = 0; j < d; j++){\n                if(bit & (1 << j)){\n         \
    \           s.push_back(nxt[j]);\n                }\n            }\n         \
    \   bool is_ok = true;\n            for(auto x : s){\n                for(auto\
    \ y : s){\n                    if(x == y) continue;\n                    if(adj[x][y]\
    \ == 0){\n                        is_ok = false;\n                    }\n    \
    \            }\n            }\n            if(is_ok){\n                res.push_back(s);\n\
    \            }\n        }\n        for(int j = 0; j < d; j++){\n            adj[cur][nxt[j]]\
    \ = adj[nxt[j]][cur] = false;\n        }\n    }\n    return res;\n}\n#line 2 \"\
    lib/math/modint.hpp\"\n\n#line 4 \"lib/math/modint.hpp\"\n\n/**\n * @brief ModInt\n\
    \ * @docs docs/math/modint.md\n */\n\ntemplate <long long Modulus>\nstruct ModInt{\n\
    \    long long val;\n    static constexpr int mod() { return Modulus; }\n    constexpr\
    \ ModInt(const long long _val = 0) noexcept : val(_val) {\n        normalize();\n\
    \    }\n    void normalize(){\n        val = (val % Modulus + Modulus) % Modulus;\n\
    \    }\n    inline ModInt &operator+=(const ModInt &rhs) noexcept {\n        if(val\
    \ += rhs.val, val >= Modulus) val -= Modulus;\n        return *this;\n    }\n\
    \    inline ModInt &operator-=(const ModInt &rhs) noexcept {\n        if(val -=\
    \ rhs.val, val < 0) val += Modulus;\n        return *this;\n    }\n    inline\
    \ ModInt &operator*=(const ModInt &rhs) noexcept {\n        val = val * rhs.val\
    \ % Modulus;\n        return *this;\n    }\n    inline ModInt &operator/=(const\
    \ ModInt &rhs) noexcept {\n        val = val * inv(rhs.val).val % Modulus;\n \
    \       return *this;\n    }\n    inline ModInt &operator++() noexcept {\n   \
    \     if(++val >= Modulus) val -= Modulus;\n        return *this;\n    }\n   \
    \ inline ModInt operator++(int) noexcept {\n        ModInt t = val;\n        if(++val\
    \ >= Modulus) val -= Modulus;\n        return t;\n    }\n    inline ModInt &operator--()\
    \ noexcept {\n        if(--val < 0) val += Modulus;\n        return *this;\n \
    \   }\n    inline ModInt operator--(int) noexcept {\n        ModInt t = val;\n\
    \        if(--val < 0) val += Modulus;\n        return t;\n    }\n    inline ModInt\
    \ operator-() const noexcept { return (Modulus - val) % Modulus; }\n    inline\
    \ ModInt inv(void) const { return inv(val); }\n    ModInt pow(long long n){\n\
    \        assert(0 <= n);\n        ModInt x = *this, r = 1;\n        while(n){\n\
    \            if(n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n  \
    \      }\n        return r;\n    }\n    ModInt inv(const long long n) const {\n\
    \        long long a = n, b = Modulus, u = 1, v = 0;\n        while(b){\n    \
    \        long long t = a / b;\n            a -= t * b; std::swap(a, b);\n    \
    \        u -= t * v; std::swap(u, v);\n        }\n        u %= Modulus;\n    \
    \    if(u < 0) u += Modulus;\n        return u;\n    }\n    friend inline ModInt\
    \ operator+(const ModInt &lhs, const ModInt &rhs) noexcept { return ModInt(lhs)\
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
    \ &os, const ModInt &x) noexcept { return os << x.val; }\n};\n#line 7 \"test/library_checker/graph/enumerate_cliques.test.cpp\"\
    \n\nusing mint = ModInt<998244353>;\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int n, m; cin >> n >> m;\n    vector<mint> x(n);\n\
    \    for(int i = 0; i < n; i++){\n        cin >> x[i];\n    }\n    vector<vector<int>>\
    \ G(n);\n    for(int i = 0; i < m; i++) {\n        int u, v; cin >> u >> v;\n\
    \        G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\n    mint ans\
    \ = 0;\n    for(auto &s : enumerateCliques(G)){\n        mint mul = 1;\n     \
    \   for(auto &i : s){\n            mul *= x[i];\n        }\n        ans += mul;\n\
    \    }\n    cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_cliques\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/enumerate_cliques.hpp\"\
    \n#include \"../../../lib/math/modint.hpp\"\n\nusing mint = ModInt<998244353>;\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n  \
    \  int n, m; cin >> n >> m;\n    vector<mint> x(n);\n    for(int i = 0; i < n;\
    \ i++){\n        cin >> x[i];\n    }\n    vector<vector<int>> G(n);\n    for(int\
    \ i = 0; i < m; i++) {\n        int u, v; cin >> u >> v;\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n\n    mint ans = 0;\n    for(auto &s : enumerateCliques(G)){\n\
    \        mint mul = 1;\n        for(auto &i : s){\n            mul *= x[i];\n\
    \        }\n        ans += mul;\n    }\n    cout << ans << '\\n';\n}\n"
  dependsOn:
  - lib/graph/enumerate_cliques.hpp
  - lib/math/modint.hpp
  isVerificationFile: true
  path: test/library_checker/graph/enumerate_cliques.test.cpp
  requiredBy: []
  timestamp: '2024-10-31 17:40:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/enumerate_cliques.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/enumerate_cliques.test.cpp
- /verify/test/library_checker/graph/enumerate_cliques.test.cpp.html
title: test/library_checker/graph/enumerate_cliques.test.cpp
---
