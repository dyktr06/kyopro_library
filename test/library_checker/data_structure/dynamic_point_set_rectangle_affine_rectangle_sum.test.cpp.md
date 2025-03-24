---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/kd_tree.hpp
    title: k-d Tree
  - icon: ':heavy_check_mark:'
    path: lib/math/modint.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum
  bundledCode: "#line 1 \"test/library_checker/data_structure/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum\"\
    \n#include <iostream>\n#include <vector>\n#include <array>\n\n#line 1 \"lib/data_structure/kd_tree.hpp\"\
    \n\n/**\n * @brief k-d Tree\n * @see https://trap.jp/post/1489/\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <limits>\n#include <queue>\n#line\
    \ 12 \"lib/data_structure/kd_tree.hpp\"\n\ntemplate <class S,\n    S(*op)(S, S),\n\
    \    S(*e)(),\n    class F,\n    S(*mapping)(F, S, int),\n    F(*composition)(F,\
    \ F),\n    F(*id)()>\nstruct KdTree{\n    static constexpr long long INF = std::numeric_limits<long\
    \ long>::max() / 3;\n    static constexpr long long NINF = -INF;\n\n    struct\
    \ Point{\n        long long x, y;\n        S val;\n        Point() {}\n      \
    \  Point(long long x, long long y, S val) : x(x), y(y), val(val) {}\n    };\n\n\
    private:\n    struct Node{\n        long long min_x, max_x, min_y, max_y;\n  \
    \      int size, index;\n        S sum;\n        F lazy;\n        Node() : min_x(INF),\
    \ max_x(NINF), min_y(INF), max_y(NINF), size(0), index(-1), sum(e()), lazy(id())\
    \ {}\n        Node(Point p, int i = -1) : min_x(p.x), max_x(p.x), min_y(p.y),\
    \ max_y(p.y), size(1), index(i), sum(p.val), lazy(id()) {}\n    };\n\n    int\
    \ _n, size, log;\n    std::vector<Node> nodes;\n    std::vector<std::pair<S, int>>\
    \ info;\n\n    void pull(int k){\n        if(k == 0) return;\n        nodes[k].size\
    \ = nodes[2 * k].size + nodes[2 * k + 1].size;\n        nodes[k].min_x = std::min(nodes[2\
    \ * k].min_x, nodes[2 * k + 1].min_x);\n        nodes[k].max_x = std::max(nodes[2\
    \ * k].max_x, nodes[2 * k + 1].max_x);\n        nodes[k].min_y = std::min(nodes[2\
    \ * k].min_y, nodes[2 * k + 1].min_y);\n        nodes[k].max_y = std::max(nodes[2\
    \ * k].max_y, nodes[2 * k + 1].max_y);\n        nodes[k].sum = op(nodes[2 * k].sum,\
    \ nodes[2 * k + 1].sum);\n    }\n\n    void all_apply(int k, F f){\n        nodes[k].sum\
    \ = mapping(f, nodes[k].sum, nodes[k].size);\n        if(k < size) nodes[k].lazy\
    \ = composition(f, nodes[k].lazy);\n    }\n\n    void push(int k){\n        all_apply(2\
    \ * k, nodes[k].lazy);\n        all_apply(2 * k + 1, nodes[k].lazy);\n       \
    \ nodes[k].lazy = id();\n    }\n\n    void build(std::vector<std::pair<Point,\
    \ int>> &v, int l, int r, bool div_x = true){\n        int len = r - l;\n    \
    \    if(len == 1){\n            nodes[size + l] = Node(v[l].first, v[l].second);\n\
    \            if(v[l].second != -1){\n                info[v[l].second].second\
    \ = l;\n            }\n            return;\n        }\n        int m = (l + r)\
    \ / 2;\n        if(div_x){\n            std::nth_element(v.begin() + l, v.begin()\
    \ + m, v.begin() + r, [](const std::pair<Point, int> &p, const std::pair<Point,\
    \ int> &q){\n                return p.first.x < q.first.x;\n            });\n\
    \        }else{\n            std::nth_element(v.begin() + l, v.begin() + m, v.begin()\
    \ + r, [](const std::pair<Point, int> &p, const std::pair<Point, int> &q){\n \
    \               return p.first.y < q.first.y;\n            });\n        }\n  \
    \      build(v, l, m, !div_x);\n        build(v, m, r, !div_x);\n    }\n\n   \
    \ bool inside(long long dx, long long dy, long long dist){\n        using i128\
    \ = __int128_t;\n        return i128(dx) * dx + i128(dy) * dy <= i128(dist) *\
    \ dist;\n    }\n\npublic:\n    KdTree(const std::vector<std::pair<long long, long\
    \ long>> &point) : _n(point.size()){\n        std::vector<S> val(_n, e());\n \
    \       init(point, val);\n    }\n\n    KdTree(const std::vector<std::pair<long\
    \ long, long long>> &point, const std::vector<S> &val) : _n(point.size()){\n \
    \       init(point, val);\n    }\n\n    void init(const std::vector<std::pair<long\
    \ long, long long>> &point, const std::vector<S> &val){\n        assert(point.size()\
    \ == val.size());\n        size = 1, log = 0;\n        while(size < _n) size *=\
    \ 2, log++;\n        nodes.resize(size * 2);\n        info.resize(size, {e(),\
    \ -1});\n        std::vector<std::pair<Point, int>> P(size, {Point{INF, INF, e()},\
    \ -1});\n        for(int i = 0; i < _n; i++){\n            P[i] = {Point(point[i].first,\
    \ point[i].second, val[i]), i};\n        }\n        build(P, 0, size);\n     \
    \   for(int i = size - 1; i >= 1; i--) pull(i);\n    }\n\n    void on(int k){\n\
    \        assert(0 <= k && k < _n);\n        int p = info[k].second + size;\n \
    \       for(int i = log; i >= 1; i--) push(p >> i);\n        if(nodes[p].size\
    \ == 1){\n            return;\n        }\n        nodes[p].size = 1;\n       \
    \ nodes[p].sum = info[k].first;\n        for(int i = 1; i <= log; i++) pull(p\
    \ >> i);\n    }\n\n    void off(int k){\n        assert(0 <= k && k < _n);\n \
    \       int p = info[k].second + size;\n        for(int i = log; i >= 1; i--)\
    \ push(p >> i);\n        info[k].first = nodes[p].sum;\n        nodes[p].size\
    \ = 0;\n        nodes[p].sum = e();\n        for(int i = 1; i <= log; i++) pull(p\
    \ >> i);\n    }\n\n    void update(int k, const S &x){\n        assert(0 <= k\
    \ && k < _n);\n        int p = info[k].second + size;\n        for(int i = log;\
    \ i >= 1; i--) push(p >> i);\n        nodes[p].sum = x;\n        for(int i = 1;\
    \ i <= log; i++) pull(p >> i);\n    }\n\n    // [sx, tx] x [sy, ty]\n    void\
    \ apply(long long sx, long long sy, long long tx, long long ty, const F &f){\n\
    \        if(sx > tx || sy > ty) return;\n        std::queue<int> que;\n      \
    \  std::vector<int> st;\n        que.push(1);\n        while(que.size()){\n  \
    \          int p = que.front();\n            que.pop();\n            if(nodes[p].size\
    \ == 0 || nodes[p].max_x < sx || tx < nodes[p].min_x || nodes[p].max_y < sy ||\
    \ ty < nodes[p].min_y) continue;\n            if(sx <= nodes[p].min_x && nodes[p].max_x\
    \ <= tx && sy <= nodes[p].min_y && nodes[p].max_y <= ty){\n                all_apply(p,\
    \ f);\n                continue;\n            }\n            push(p);\n      \
    \      que.push(2 * p);\n            que.push(2 * p + 1);\n            st.push_back(p);\n\
    \        }\n        while(st.size()){\n            pull(st.back());\n        \
    \    st.pop_back();\n        }\n    }\n\n    // [sx, tx] x [sy, ty]\n    S query(long\
    \ long sx, long long sy, long long tx, long long ty){\n        if(sx > tx || sy\
    \ > ty) return e();\n        std::queue<int> que;\n        que.push(1);\n    \
    \    S res = e();\n        while(que.size()){\n            int p = que.front();\n\
    \            que.pop();\n            if(nodes[p].size == 0 || nodes[p].max_x <\
    \ sx || tx < nodes[p].min_x || nodes[p].max_y < sy || ty < nodes[p].min_y) continue;\n\
    \            if(sx <= nodes[p].min_x && nodes[p].max_x <= tx && sy <= nodes[p].min_y\
    \ && nodes[p].max_y <= ty){\n                res = op(res, nodes[p].sum);\n  \
    \              continue;\n            }\n            push(p);\n            que.push(2\
    \ * p);\n            que.push(2 * p + 1);\n        }\n        return res;\n  \
    \  }\n\n    // \u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u8DDD\u96E2\n    template\
    \ <typename T>\n    void getNearbyPoints(long long x, long long y, long long dist,\
    \ const T &f){\n        std::queue<int> que;\n        que.push(1);\n        while(que.size()){\n\
    \            int p = que.front();\n            que.pop();\n            if(nodes[p].size\
    \ == 0 || !inside(std::clamp(x, nodes[p].min_x, nodes[p].max_x) - x, std::clamp(y,\
    \ nodes[p].min_y, nodes[p].max_y) - y, dist)) continue;\n            if(nodes[p].size\
    \ == 1){\n                f(nodes[p].index);\n                continue;\n    \
    \        }\n            que.push(2 * p);\n            que.push(2 * p + 1);\n \
    \       }\n    }\n};\n#line 2 \"lib/math/modint.hpp\"\n\n#line 5 \"lib/math/modint.hpp\"\
    \n\n/**\n * @brief ModInt\n * @docs docs/math/modint.md\n */\n\ntemplate <long\
    \ long Modulus>\nstruct ModInt{\n    long long val;\n    static constexpr int\
    \ mod() { return Modulus; }\n    constexpr ModInt(const long long _val = 0) noexcept\
    \ : val(_val) {\n        normalize();\n    }\n    void normalize(){\n        val\
    \ = (val % Modulus + Modulus) % Modulus;\n    }\n    inline ModInt &operator+=(const\
    \ ModInt &rhs) noexcept {\n        if(val += rhs.val, val >= Modulus) val -= Modulus;\n\
    \        return *this;\n    }\n    inline ModInt &operator-=(const ModInt &rhs)\
    \ noexcept {\n        if(val -= rhs.val, val < 0) val += Modulus;\n        return\
    \ *this;\n    }\n    inline ModInt &operator*=(const ModInt &rhs) noexcept {\n\
    \        val = val * rhs.val % Modulus;\n        return *this;\n    }\n    inline\
    \ ModInt &operator/=(const ModInt &rhs) noexcept {\n        val = val * inv(rhs.val).val\
    \ % Modulus;\n        return *this;\n    }\n    inline ModInt &operator++() noexcept\
    \ {\n        if(++val >= Modulus) val -= Modulus;\n        return *this;\n   \
    \ }\n    inline ModInt operator++(int) noexcept {\n        ModInt t = val;\n \
    \       if(++val >= Modulus) val -= Modulus;\n        return t;\n    }\n    inline\
    \ ModInt &operator--() noexcept {\n        if(--val < 0) val += Modulus;\n   \
    \     return *this;\n    }\n    inline ModInt operator--(int) noexcept {\n   \
    \     ModInt t = val;\n        if(--val < 0) val += Modulus;\n        return t;\n\
    \    }\n    inline ModInt operator-() const noexcept { return (Modulus - val)\
    \ % Modulus; }\n    inline ModInt inv(void) const { return inv(val); }\n    ModInt\
    \ pow(long long n) const {\n        assert(0 <= n);\n        ModInt x = *this,\
    \ r = 1;\n        while(n){\n            if(n & 1) r *= x;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return r;\n    }\n    ModInt inv(const\
    \ long long n) const {\n        long long a = n, b = Modulus, u = 1, v = 0;\n\
    \        while(b){\n            long long t = a / b;\n            a -= t * b;\
    \ std::swap(a, b);\n            u -= t * v; std::swap(u, v);\n        }\n    \
    \    u %= Modulus;\n        if(u < 0) u += Modulus;\n        return u;\n    }\n\
    \    friend inline ModInt operator+(const ModInt &lhs, const ModInt &rhs) noexcept\
    \ { return ModInt(lhs) += rhs; }\n    friend inline ModInt operator-(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept { return ModInt(lhs) -= rhs; }\n    friend\
    \ inline ModInt operator*(const ModInt &lhs, const ModInt &rhs) noexcept { return\
    \ ModInt(lhs) *= rhs; }\n    friend inline ModInt operator/(const ModInt &lhs,\
    \ const ModInt &rhs) noexcept { return ModInt(lhs) /= rhs; }\n    friend inline\
    \ bool operator==(const ModInt &lhs, const ModInt &rhs) noexcept { return lhs.val\
    \ == rhs.val; }\n    friend inline bool operator!=(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept { return lhs.val != rhs.val; }\n    friend inline std::istream\
    \ &operator>>(std::istream &is, ModInt &x) noexcept {\n        is >> x.val;\n\
    \        x.normalize();\n        return is;\n    }\n    friend inline std::ostream\
    \ &operator<<(std::ostream &os, const ModInt &x) noexcept { return os << x.val;\
    \ }\n};\n#line 8 \"test/library_checker/data_structure/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp\"\
    \n\nusing namespace std;\n\nusing mint = ModInt<998244353>;\n\nusing S = mint;\n\
    \nstruct F{\n    mint a, b;\n};\n\nS op(S l, S r){ return l + r; }\n\nS e(){ return\
    \ S{0}; }\n\nS mapping(F l, S r, int size){ return S{r * l.a + size * l.b}; }\n\
    \nF composition(F l, F r){ return F{r.a * l.a, r.b * l.a + l.b}; }\n\nF id(){\
    \ return F{1, 0}; }\n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int n, q; cin >> n >> q;\n    vector<pair<long long, long long>> p(n);\n\
    \    vector<S> w(n);\n    for(int i = 0; i < n; i++){\n        cin >> p[i].first\
    \ >> p[i].second >> w[i];\n    }\n    using T = array<long long, 7>;\n    vector<T>\
    \ query(q);\n    for(int i = 0; i < q; i++){\n        int t; cin >> t;\n     \
    \   query[i][0] = t;\n        if(t == 0){\n            cin >> query[i][1] >> query[i][2]\
    \ >> query[i][3];\n            p.emplace_back(query[i][1], query[i][2]);\n   \
    \         w.emplace_back(query[i][3]);\n        }else if(t == 1){\n          \
    \  cin >> query[i][1] >> query[i][2];\n        }else if(t == 2){\n           \
    \ cin >> query[i][1] >> query[i][2] >> query[i][3] >> query[i][4];\n        }else{\n\
    \            cin >> query[i][1] >> query[i][2] >> query[i][3] >> query[i][4] >>\
    \ query[i][5] >> query[i][6];\n        }\n    }\n    KdTree<S, op, e, F, mapping,\
    \ composition, id> tree(p, w);\n    for(int i = n; i < (int) p.size(); i++){\n\
    \        tree.off(i);\n    }\n    int cur = n;\n    for(int i = 0; i < q; i++){\n\
    \        int t = query[i][0];\n        if(t == 0){\n            tree.on(cur);\n\
    \            tree.update(cur, S{query[i][3]});\n            cur++;\n        }else\
    \ if(t == 1){\n            tree.update(query[i][1], S{query[i][2]});\n       \
    \ }else if(t == 2){\n            long long l = query[i][1], d = query[i][2], r\
    \ = query[i][3], u = query[i][4];\n            cout << tree.query(l, d, r - 1,\
    \ u - 1) << '\\n';\n        }else{\n            long long l = query[i][1], d =\
    \ query[i][2], r = query[i][3], u = query[i][4];\n            mint a = query[i][5],\
    \ b = query[i][6];\n            tree.apply(l, d, r - 1, u - 1, F{a, b});\n   \
    \     }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum\"\
    \n#include <iostream>\n#include <vector>\n#include <array>\n\n#include \"../../../lib/data_structure/kd_tree.hpp\"\
    \n#include \"../../../lib/math/modint.hpp\"\n\nusing namespace std;\n\nusing mint\
    \ = ModInt<998244353>;\n\nusing S = mint;\n\nstruct F{\n    mint a, b;\n};\n\n\
    S op(S l, S r){ return l + r; }\n\nS e(){ return S{0}; }\n\nS mapping(F l, S r,\
    \ int size){ return S{r * l.a + size * l.b}; }\n\nF composition(F l, F r){ return\
    \ F{r.a * l.a, r.b * l.a + l.b}; }\n\nF id(){ return F{1, 0}; }\n\nint main(){\n\
    \    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int n, q; cin\
    \ >> n >> q;\n    vector<pair<long long, long long>> p(n);\n    vector<S> w(n);\n\
    \    for(int i = 0; i < n; i++){\n        cin >> p[i].first >> p[i].second >>\
    \ w[i];\n    }\n    using T = array<long long, 7>;\n    vector<T> query(q);\n\
    \    for(int i = 0; i < q; i++){\n        int t; cin >> t;\n        query[i][0]\
    \ = t;\n        if(t == 0){\n            cin >> query[i][1] >> query[i][2] >>\
    \ query[i][3];\n            p.emplace_back(query[i][1], query[i][2]);\n      \
    \      w.emplace_back(query[i][3]);\n        }else if(t == 1){\n            cin\
    \ >> query[i][1] >> query[i][2];\n        }else if(t == 2){\n            cin >>\
    \ query[i][1] >> query[i][2] >> query[i][3] >> query[i][4];\n        }else{\n\
    \            cin >> query[i][1] >> query[i][2] >> query[i][3] >> query[i][4] >>\
    \ query[i][5] >> query[i][6];\n        }\n    }\n    KdTree<S, op, e, F, mapping,\
    \ composition, id> tree(p, w);\n    for(int i = n; i < (int) p.size(); i++){\n\
    \        tree.off(i);\n    }\n    int cur = n;\n    for(int i = 0; i < q; i++){\n\
    \        int t = query[i][0];\n        if(t == 0){\n            tree.on(cur);\n\
    \            tree.update(cur, S{query[i][3]});\n            cur++;\n        }else\
    \ if(t == 1){\n            tree.update(query[i][1], S{query[i][2]});\n       \
    \ }else if(t == 2){\n            long long l = query[i][1], d = query[i][2], r\
    \ = query[i][3], u = query[i][4];\n            cout << tree.query(l, d, r - 1,\
    \ u - 1) << '\\n';\n        }else{\n            long long l = query[i][1], d =\
    \ query[i][2], r = query[i][3], u = query[i][4];\n            mint a = query[i][5],\
    \ b = query[i][6];\n            tree.apply(l, d, r - 1, u - 1, F{a, b});\n   \
    \     }\n    }\n}\n"
  dependsOn:
  - lib/data_structure/kd_tree.hpp
  - lib/math/modint.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2024-11-20 20:38:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp
- /verify/test/library_checker/data_structure/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp.html
title: test/library_checker/data_structure/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp
---
