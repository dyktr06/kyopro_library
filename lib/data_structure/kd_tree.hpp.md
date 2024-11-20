---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp
    title: test/library_checker/data_structure/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: k-d Tree
    links: []
  bundledCode: "#line 1 \"lib/data_structure/kd_tree.hpp\"\n\n/**\n * @brief k-d Tree\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include\
    \ <queue>\n#include <vector>\n\ntemplate <class S,\n    S(*op)(S, S),\n    S(*e)(),\n\
    \    class F,\n    S(*mapping)(F, S, int),\n    F(*composition)(F, F),\n    F(*id)()>\n\
    struct KdTree{\n    static constexpr long long INF = std::numeric_limits<long\
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
    \      build(v, l, m, !div_x);\n        build(v, m, r, !div_x);\n    }\n\npublic:\n\
    \    KdTree(const std::vector<std::pair<long long, long long>> &point) : _n(point.size()){\n\
    \        std::vector<S> val(_n, e());\n        init(point, val);\n    }\n\n  \
    \  KdTree(const std::vector<std::pair<long long, long long>> &point, const std::vector<S>\
    \ &val) : _n(point.size()){\n        init(point, val);\n    }\n\n    void init(const\
    \ std::vector<std::pair<long long, long long>> &point, const std::vector<S> &val){\n\
    \        assert(point.size() == val.size());\n        size = 1, log = 0;\n   \
    \     while(size < _n) size *= 2, log++;\n        nodes.resize(size * 2);\n  \
    \      info.resize(size, {e(), -1});\n        std::vector<std::pair<Point, int>>\
    \ P(size, {Point{INF, INF, e()}, -1});\n        for(int i = 0; i < _n; i++){\n\
    \            P[i] = {Point(point[i].first, point[i].second, val[i]), i};\n   \
    \     }\n        build(P, 0, size);\n        for(int i = size - 1; i >= 1; i--)\
    \ pull(i);\n    }\n\n    void on(int k){\n        assert(0 <= k && k < _n);\n\
    \        int p = info[k].second + size;\n        for(int i = log; i >= 1; i--)\
    \ push(p >> i);\n        if(nodes[p].size == 1){\n            return;\n      \
    \  }\n        nodes[p].size = 1;\n        nodes[p].sum = info[k].first;\n    \
    \    for(int i = 1; i <= log; i++) pull(p >> i);\n    }\n\n    void off(int k){\n\
    \        assert(0 <= k && k < _n);\n        int p = info[k].second + size;\n \
    \       for(int i = log; i >= 1; i--) push(p >> i);\n        info[k].first = nodes[p].sum;\n\
    \        nodes[p].size = 0;\n        nodes[p].sum = e();\n        for(int i =\
    \ 1; i <= log; i++) pull(p >> i);\n    }\n\n    void update(int k, const S &x){\n\
    \        assert(0 <= k && k < _n);\n        int p = info[k].second + size;\n \
    \       for(int i = log; i >= 1; i--) push(p >> i);\n        nodes[p].sum = x;\n\
    \        for(int i = 1; i <= log; i++) pull(p >> i);\n    }\n\n    // [sx, tx]\
    \ x [sy, ty]\n    void apply(long long sx, long long sy, long long tx, long long\
    \ ty, const F &f){\n        if(sx > tx || sy > ty) return;\n        std::queue<int>\
    \ que;\n        std::vector<int> st;\n        que.push(1);\n        while(que.size()){\n\
    \            int p = que.front();\n            que.pop();\n            if(nodes[p].size\
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
    \  }\n\n    bool inside(long long dx, long long dy, long long dist){\n       \
    \ using i128 = __int128_t;\n        return i128(dx) * dx + i128(dy) * dy <= i128(dist)\
    \ * dist;\n    }\n\n    // \u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u8DDD\u96E2\n\
    \    template <typename T>\n    void getNearbyPoints(long long x, long long y,\
    \ long long dist, const T &f){\n        std::queue<int> que;\n        que.push(1);\n\
    \        while(que.size()){\n            int p = que.front();\n            que.pop();\n\
    \            if(nodes[p].size == 0 || !inside(std::clamp(x, nodes[p].min_x, nodes[p].max_x)\
    \ - x, std::clamp(y, nodes[p].min_y, nodes[p].max_y) - y, dist)) continue;\n \
    \           if(nodes[p].size == 1){\n                f(nodes[p].index);\n    \
    \            continue;\n            }\n            que.push(2 * p);\n        \
    \    que.push(2 * p + 1);\n        }\n    }\n};\n"
  code: "\n/**\n * @brief k-d Tree\n */\n\n#include <algorithm>\n#include <cassert>\n\
    #include <limits>\n#include <queue>\n#include <vector>\n\ntemplate <class S,\n\
    \    S(*op)(S, S),\n    S(*e)(),\n    class F,\n    S(*mapping)(F, S, int),\n\
    \    F(*composition)(F, F),\n    F(*id)()>\nstruct KdTree{\n    static constexpr\
    \ long long INF = std::numeric_limits<long long>::max() / 3;\n    static constexpr\
    \ long long NINF = -INF;\n\n    struct Point{\n        long long x, y;\n     \
    \   S val;\n        Point() {}\n        Point(long long x, long long y, S val)\
    \ : x(x), y(y), val(val) {}\n    };\n\nprivate:\n    struct Node{\n        long\
    \ long min_x, max_x, min_y, max_y;\n        int size, index;\n        S sum;\n\
    \        F lazy;\n        Node() : min_x(INF), max_x(NINF), min_y(INF), max_y(NINF),\
    \ size(0), index(-1), sum(e()), lazy(id()) {}\n        Node(Point p, int i = -1)\
    \ : min_x(p.x), max_x(p.x), min_y(p.y), max_y(p.y), size(1), index(i), sum(p.val),\
    \ lazy(id()) {}\n    };\n\n    int _n, size, log;\n    std::vector<Node> nodes;\n\
    \    std::vector<std::pair<S, int>> info;\n\n    void pull(int k){\n        if(k\
    \ == 0) return;\n        nodes[k].size = nodes[2 * k].size + nodes[2 * k + 1].size;\n\
    \        nodes[k].min_x = std::min(nodes[2 * k].min_x, nodes[2 * k + 1].min_x);\n\
    \        nodes[k].max_x = std::max(nodes[2 * k].max_x, nodes[2 * k + 1].max_x);\n\
    \        nodes[k].min_y = std::min(nodes[2 * k].min_y, nodes[2 * k + 1].min_y);\n\
    \        nodes[k].max_y = std::max(nodes[2 * k].max_y, nodes[2 * k + 1].max_y);\n\
    \        nodes[k].sum = op(nodes[2 * k].sum, nodes[2 * k + 1].sum);\n    }\n\n\
    \    void all_apply(int k, F f){\n        nodes[k].sum = mapping(f, nodes[k].sum,\
    \ nodes[k].size);\n        if(k < size) nodes[k].lazy = composition(f, nodes[k].lazy);\n\
    \    }\n\n    void push(int k){\n        all_apply(2 * k, nodes[k].lazy);\n  \
    \      all_apply(2 * k + 1, nodes[k].lazy);\n        nodes[k].lazy = id();\n \
    \   }\n\n    void build(std::vector<std::pair<Point, int>> &v, int l, int r, bool\
    \ div_x = true){\n        int len = r - l;\n        if(len == 1){\n          \
    \  nodes[size + l] = Node(v[l].first, v[l].second);\n            if(v[l].second\
    \ != -1){\n                info[v[l].second].second = l;\n            }\n    \
    \        return;\n        }\n        int m = (l + r) / 2;\n        if(div_x){\n\
    \            std::nth_element(v.begin() + l, v.begin() + m, v.begin() + r, [](const\
    \ std::pair<Point, int> &p, const std::pair<Point, int> &q){\n               \
    \ return p.first.x < q.first.x;\n            });\n        }else{\n           \
    \ std::nth_element(v.begin() + l, v.begin() + m, v.begin() + r, [](const std::pair<Point,\
    \ int> &p, const std::pair<Point, int> &q){\n                return p.first.y\
    \ < q.first.y;\n            });\n        }\n        build(v, l, m, !div_x);\n\
    \        build(v, m, r, !div_x);\n    }\n\npublic:\n    KdTree(const std::vector<std::pair<long\
    \ long, long long>> &point) : _n(point.size()){\n        std::vector<S> val(_n,\
    \ e());\n        init(point, val);\n    }\n\n    KdTree(const std::vector<std::pair<long\
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
    \  }\n\n    bool inside(long long dx, long long dy, long long dist){\n       \
    \ using i128 = __int128_t;\n        return i128(dx) * dx + i128(dy) * dy <= i128(dist)\
    \ * dist;\n    }\n\n    // \u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u8DDD\u96E2\n\
    \    template <typename T>\n    void getNearbyPoints(long long x, long long y,\
    \ long long dist, const T &f){\n        std::queue<int> que;\n        que.push(1);\n\
    \        while(que.size()){\n            int p = que.front();\n            que.pop();\n\
    \            if(nodes[p].size == 0 || !inside(std::clamp(x, nodes[p].min_x, nodes[p].max_x)\
    \ - x, std::clamp(y, nodes[p].min_y, nodes[p].max_y) - y, dist)) continue;\n \
    \           if(nodes[p].size == 1){\n                f(nodes[p].index);\n    \
    \            continue;\n            }\n            que.push(2 * p);\n        \
    \    que.push(2 * p + 1);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/kd_tree.hpp
  requiredBy: []
  timestamp: '2024-11-20 20:20:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp
documentation_of: lib/data_structure/kd_tree.hpp
layout: document
redirect_from:
- /library/lib/data_structure/kd_tree.hpp
- /library/lib/data_structure/kd_tree.hpp.html
title: k-d Tree
---
