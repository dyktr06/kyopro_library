---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../data-structure/dynamic_binary_indexed_tree.cpp:\
    \ line -1: no such header\n"
  code: "#include <bits/stdc++.h>\n#include \"../data-structure/dynamic_binary_indexed_tree.cpp\"\
    \n#include \"../other/compression.cpp\"\n\nusing namespace std;\n\n/* \n    DynamicBinaryIndexedTree2D<S,\
    \ T>(h, w) : BIT2D\u3092\u30B5\u30A4\u30BAh*w\u3067\u69CB\u7BC9\n    add(x, y,\
    \ v) : (x, y) \u306B v \u3092\u52A0\u7B97\u3057\u307E\u3059\u3002\n    sum(x1,\
    \ y1, x2, y2) : [(x1, y1), (x2, y2)] \u306E\u548C\u3092\u53D6\u5F97\u3057\u307E\
    \u3059\u3002\n*/\n\ntemplate <typename T>\nstruct DynamicBinaryIndexedTree2D{\n\
    \    using BIT = DynamicBinaryIndexedTree<int, T>;\n    int H, W;\n    vector<BIT*>\
    \ bit;\n    DynamicBinaryIndexedTree2D(int h, int w): H(h + 1), W(w){\n      \
    \  for(int i = 0; i < H; i++){\n            bit.push_back(new BIT(W));\n     \
    \   }\n    }\n\n    void add(int i, int j, const T &x){\n        for(++i; i <\
    \ H; i += i & -i) (*bit[i]).add(j, x);\n    }\n\n    T sum(int x, int y){\n  \
    \      if(x < 0 || y < 0){\n            return 0;\n        }\n        T res =\
    \ 0;\n        while(x > 0){\n            res += (*bit[x]).sum(y);\n          \
    \  x -= x & -x;\n        }\n        return res;\n    }\n\n    T sum(int x1, int\
    \ y1, int x2, int y2){\n        T res = 0;\n        while(x1 != x2){\n       \
    \     if(x1 < x2){\n                res += (*bit[x2]).sum(y1, y2);\n         \
    \       x2 -= x2 & -x2;\n            }else{\n                res -= (*bit[x1]).sum(y1,\
    \ y2);\n                x1 -= x1 & -x1;\n            }\n        }\n        return\
    \ res;\n    }\n};\n\n// example (Library Checker (Point Add Rectangle Sum))\n\
    int main(){\n    int n, q; cin >> n >> q;\n    vector<int> xl, yl;\n    vector<tuple<int,\
    \ int, int>> point;\n    vector<tuple<int, int, int, int, int>> query;\n    for(int\
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
    \\n\";\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/dynamic_binary_indexed_tree_2d.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/dynamic_binary_indexed_tree_2d.cpp
layout: document
redirect_from:
- /library/lib/data_structure/dynamic_binary_indexed_tree_2d.cpp
- /library/lib/data_structure/dynamic_binary_indexed_tree_2d.cpp.html
title: lib/data_structure/dynamic_binary_indexed_tree_2d.cpp
---
