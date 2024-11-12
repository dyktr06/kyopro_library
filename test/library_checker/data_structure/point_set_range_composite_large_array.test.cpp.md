---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../lib/math/ModInt.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite_large_array\"\
    \n\n#include <iostream>\n#include <vector>\n#include <tuple>\n\n#include \"../../../lib/data_structure/segment_tree_func.hpp\"\
    \n#include \"../../../lib/math/ModInt.hpp\"\n#include \"../../../lib/others/compression.hpp\"\
    \n\nusing namespace std;\n\nusing mint = ModInt<998244353>;\nusing F = pair<mint,\
    \ mint>;\n\nF op(F a, F b){\n    return {a.first * b.first, a.second * b.first\
    \ + b.second};\n}\n\nF e(){\n    return {1, 0};\n}\n\nint main(){\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int n, q; cin >> n >> q;\n    using T\
    \ = tuple<int, int, int, int>;\n    vector<T> query(q);\n    vector<int> c;\n\
    \    for(int i = 0; i < q; i++){\n        int t, x, y, z; cin >> t >> x >> y >>\
    \ z;\n        query[i] = {t, x, y, z};\n        if(t == 0){\n            c.push_back(x);\n\
    \        }else{\n            c.push_back(x);\n            c.push_back(y);\n  \
    \      }\n    }\n    compress<int> comp(c);\n    SegTree<F, op, e> seg(comp.size());\n\
    \    for(int i = 0; i < q; i++){\n        auto [t, x, y, z] = query[i];\n    \
    \    if(t == 0){\n            seg.update(comp.get(x), {y, z});\n        }else{\n\
    \            F res = seg.query(comp.get(x), comp.get(y));\n            cout <<\
    \ res.first * z + res.second << \"\\n\";\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp
- /verify/test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp.html
title: test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp
---
