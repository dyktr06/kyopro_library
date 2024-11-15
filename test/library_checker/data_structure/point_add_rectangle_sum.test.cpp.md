---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/dynamic_binary_indexed_tree.hpp
    title: lib/data_structure/dynamic_binary_indexed_tree.hpp
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/dynamic_binary_indexed_tree_2d.hpp
    title: lib/data_structure/dynamic_binary_indexed_tree_2d.hpp
  - icon: ':question:'
    path: lib/others/compression.hpp
    title: "Compression (\u5EA7\u6A19\u5727\u7E2E)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/library_checker/data_structure/point_add_rectangle_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/dynamic_binary_indexed_tree_2d.hpp\"\
    \n\n#line 2 \"lib/data_structure/dynamic_binary_indexed_tree.hpp\"\n\n/*\n   \
    \ DynamicBinaryIndexedTree<S, T>(n) : BIT\u3092\u30B5\u30A4\u30BAn\u3067\u69CB\
    \u7BC9\n    add(i, x) : i \u756A\u76EE\u306E\u8981\u7D20\u306B\u52A0\u7B97\u3057\
    \u307E\u3059\u3002 O(log(n)^2)\n    sum(l, r) : [l, r) \u306E\u533A\u9593\u548C\
    \u3092\u53D6\u5F97\u3057\u307E\u3059\u3002O(log(n)^2)\n\n    (\u4EE5\u4E0B\u306E\
    \u6A5F\u80FD\u3092\u4F7F\u3046\u306B\u306F\u30010 <= i < N \u306B\u304A\u3044\u3066\
    \u3001A_i >= 0 \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308A\u307E\u3059\u3002\
    )\n    lower_bound(x) : A_0 + A_1 + ... + A_y >= x \u3068\u306A\u308B\u6700\u5C0F\
    \u306E y \u3092\u6C42\u3081\u307E\u3059\u3002O(log(n))\n*/\n\ntemplate <typename\
    \ S, typename T>\nstruct DynamicBinaryIndexedTree{\n    S N;\n    unordered_map<S,\
    \ T> data;\n    DynamicBinaryIndexedTree(S _N) : N(_N + 1){\n    }\n\n    void\
    \ add(S i, const T &x){\n        for(++i; i < N; i += i & -i) data[i] += x;\n\
    \    }\n\n    T sum(int i){\n        if(i < 0){\n            return 0;\n     \
    \   }\n        T ans = 0;\n        while(i > 0){\n            const auto iter\
    \ = data.find(i);\n            if(iter != data.end()){\n                ans +=\
    \ iter->second;\n            }\n            i -= i & -i;\n        }\n        return\
    \ ans;\n    }\n\n    T sum(int L, int R){\n        return sum(R) - sum(L);\n \
    \   }\n\n    T operator[](S i){\n        return sum(i + 1) - sum(i);\n    }\n\n\
    \    S lower_bound(T x){\n        if(x <= 0){\n            return 0;\n       \
    \ }\n        S v = 0, r = 1;\n        while(r < N) r = r << 1;\n        for(S\
    \ len = r; len > 0; len = len >> 1){\n            if(v + len < N && data[v + len]\
    \ < x){\n                x -= data[v + len];\n                v += len;\n    \
    \        }\n        }\n        return v;\n    }\n};\n#line 4 \"lib/data_structure/dynamic_binary_indexed_tree_2d.hpp\"\
    \n\n/*\n    DynamicBinaryIndexedTree2D<S, T>(h, w) : BIT2D\u3092\u30B5\u30A4\u30BA\
    h*w\u3067\u69CB\u7BC9\n    add(x, y, v) : (x, y) \u306B v \u3092\u52A0\u7B97\u3057\
    \u307E\u3059\u3002\n    sum(x1, y1, x2, y2) : [(x1, y1), (x2, y2)] \u306E\u548C\
    \u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\n*/\n\ntemplate <typename T>\nstruct\
    \ DynamicBinaryIndexedTree2D{\n    using BIT = DynamicBinaryIndexedTree<int, T>;\n\
    \    int H, W;\n    vector<BIT *> bit;\n    DynamicBinaryIndexedTree2D(int h,\
    \ int w) : H(h + 1), W(w){\n        for(int i = 0; i < H; i++){\n            bit.push_back(new\
    \ BIT(W));\n        }\n    }\n\n    void add(int i, int j, const T &x){\n    \
    \    for(++i; i < H; i += i & -i) (*bit[i]).add(j, x);\n    }\n\n    T sum(int\
    \ x, int y){\n        if(x < 0 || y < 0){\n            return 0;\n        }\n\
    \        T res = 0;\n        while(x > 0){\n            res += (*bit[x]).sum(y);\n\
    \            x -= x & -x;\n        }\n        return res;\n    }\n\n    T sum(int\
    \ x1, int y1, int x2, int y2){\n        T res = 0;\n        while(x1 != x2){\n\
    \            if(x1 < x2){\n                res += (*bit[x2]).sum(y1, y2);\n  \
    \              x2 -= x2 & -x2;\n            } else{\n                res -= (*bit[x1]).sum(y1,\
    \ y2);\n                x1 -= x1 & -x1;\n            }\n        }\n        return\
    \ res;\n    }\n};\n#line 2 \"lib/others/compression.hpp\"\n\n/**\n * @brief Compression\
    \ (\u5EA7\u6A19\u5727\u7E2E)\n * @docs docs/others/compression.md\n */\n\n#line\
    \ 10 \"lib/others/compression.hpp\"\n\ntemplate <typename T>\nstruct compress{\n\
    \    std::vector<T> sorted;\n    std::vector<int> compressed;\n\n    compress(const\
    \ std::vector<T> &vec){\n        int n = vec.size();\n        compressed.resize(n);\n\
    \        for(T x : vec){\n            sorted.emplace_back(x);\n        }\n   \
    \     std::sort(sorted.begin(), sorted.end());\n        sorted.erase(std::unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n        for(int i = 0; i < n; ++i){\n       \
    \     compressed[i] = std::lower_bound(sorted.begin(), sorted.end(), vec[i]) -\
    \ sorted.begin();\n        }\n    }\n\n    int get(const T &x) const{\n      \
    \  return std::lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();\n\
    \    }\n\n    T inv(const int x) const{\n        return sorted[x];\n    }\n\n\
    \    size_t size() const{\n        return sorted.size();\n    }\n\n    std::vector<T>\
    \ getCompressed() const{\n        return compressed;\n    }\n};\n#line 7 \"test/library_checker/data_structure/point_add_rectangle_sum.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n \
    \   int n, q; cin >> n >> q;\n    vector<int> xl, yl;\n    vector<tuple<int, int,\
    \ int>> point;\n    vector<tuple<int, int, int, int, int>> query;\n    for(int\
    \ i = 0; i < n; i++){\n        int x, y, w; cin >> x >> y >> w;\n        point.emplace_back(x,\
    \ y, w);\n        xl.push_back(x);\n        yl.push_back(y);\n    }\n    for(int\
    \ i = 0; i < q; i++){\n        int t; cin >> t;\n        if(t == 0){\n       \
    \     int x, y, w; cin >> x >> y >> w;\n            xl.push_back(x);\n       \
    \     yl.push_back(y);\n            query.emplace_back(t, x, y, w, 0);\n     \
    \   }else{\n            int l, d, r, u; cin >> l >> d >> r >> u;\n           \
    \ xl.push_back(l);\n            xl.push_back(r);\n            yl.push_back(d);\n\
    \            yl.push_back(u);\n            query.emplace_back(t, l, d, r, u);\n\
    \        }\n    }\n    compress<int> xc(xl), yc(yl);\n    DynamicBinaryIndexedTree2D<long\
    \ long> BIT(xc.size(), yc.size());\n    for(int i = 0; i < n; i++){\n        auto\
    \ [x, y, w] = point[i];\n        BIT.add(xc.get(x), yc.get(y), w);\n    }\n  \
    \  for(int i = 0; i < q; i++){\n        auto [t, a, b, c, d] = query[i];\n   \
    \     if(t == 0){\n            BIT.add(xc.get(a), yc.get(b), c);\n        }else{\n\
    \            cout << BIT.sum(xc.get(a), yc.get(b), xc.get(c), yc.get(d)) << \"\
    \\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/dynamic_binary_indexed_tree_2d.hpp\"\
    \n#include \"../../../lib/others/compression.hpp\"\n\nint main(){\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int n, q; cin >> n >> q;\n    vector<int>\
    \ xl, yl;\n    vector<tuple<int, int, int>> point;\n    vector<tuple<int, int,\
    \ int, int, int>> query;\n    for(int i = 0; i < n; i++){\n        int x, y, w;\
    \ cin >> x >> y >> w;\n        point.emplace_back(x, y, w);\n        xl.push_back(x);\n\
    \        yl.push_back(y);\n    }\n    for(int i = 0; i < q; i++){\n        int\
    \ t; cin >> t;\n        if(t == 0){\n            int x, y, w; cin >> x >> y >>\
    \ w;\n            xl.push_back(x);\n            yl.push_back(y);\n           \
    \ query.emplace_back(t, x, y, w, 0);\n        }else{\n            int l, d, r,\
    \ u; cin >> l >> d >> r >> u;\n            xl.push_back(l);\n            xl.push_back(r);\n\
    \            yl.push_back(d);\n            yl.push_back(u);\n            query.emplace_back(t,\
    \ l, d, r, u);\n        }\n    }\n    compress<int> xc(xl), yc(yl);\n    DynamicBinaryIndexedTree2D<long\
    \ long> BIT(xc.size(), yc.size());\n    for(int i = 0; i < n; i++){\n        auto\
    \ [x, y, w] = point[i];\n        BIT.add(xc.get(x), yc.get(y), w);\n    }\n  \
    \  for(int i = 0; i < q; i++){\n        auto [t, a, b, c, d] = query[i];\n   \
    \     if(t == 0){\n            BIT.add(xc.get(a), yc.get(b), c);\n        }else{\n\
    \            cout << BIT.sum(xc.get(a), yc.get(b), xc.get(c), yc.get(d)) << \"\
    \\n\";\n        }\n    }\n}"
  dependsOn:
  - lib/data_structure/dynamic_binary_indexed_tree_2d.hpp
  - lib/data_structure/dynamic_binary_indexed_tree.hpp
  - lib/others/compression.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/point_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2024-11-13 13:43:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/point_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/point_add_rectangle_sum.test.cpp
- /verify/test/library_checker/data_structure/point_add_rectangle_sum.test.cpp.html
title: test/library_checker/data_structure/point_add_rectangle_sum.test.cpp
---
