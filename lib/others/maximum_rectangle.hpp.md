---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/others/maximum_rectangle.md
    document_title: "Maximum Rectangle (\u6700\u5927\u9577\u65B9\u5F62)"
    links: []
  bundledCode: "#line 2 \"lib/others/maximum_rectangle.hpp\"\n\n/**\n * @brief Maximum\
    \ Rectangle (\u6700\u5927\u9577\u65B9\u5F62)\n * @docs docs/others/maximum_rectangle.md\n\
    \ */\n\n // [(x1, y1), (x2, y2)]\nvector<tuple<int, int, int, int>> getMaximumRectangle(vector<vector<bool>>\
    \ &a){\n    vector<tuple<int, int, int, int>> res;\n    int n = a.size(), m =\
    \ a[0].size();\n    vector<int> max_row(m), sorted(m);\n    iota(sorted.begin(),\
    \ sorted.end(), 0);\n    for(int i = 0; i < n; ++i){\n        vector<bool> is_changed(m);\n\
    \        vector<int> nsorted;\n        for(int j = 0; j < m; ++j){\n         \
    \   if(!a[i][j]){\n                max_row[j] = i + 1;\n                is_changed[j]\
    \ = true;\n                nsorted.emplace_back(j);\n            }\n        }\n\
    \        // {l, r}\n        vector<pair<int, int>> lr(m);\n        for(int j =\
    \ 0; j < m; ++j){\n            if(!is_changed[sorted[j]]){\n                nsorted.emplace_back(sorted[j]);\n\
    \            }\n            lr[j] = make_pair(j, j);\n        }\n        for(int\
    \ j = m - 1; j >= 0; --j){\n            int k = nsorted[j];\n            auto\
    \ [l, r] = lr[k];\n            int nl = n + 1, nr = n + 1;\n            if(l !=\
    \ 0) nl = max_row[l - 1];\n            if(r != m - 1) nr = max_row[r + 1];\n \
    \           if(nl <= max_row[k]) l = get<0>(lr[l - 1]);\n            if(nr <=\
    \ max_row[k]) r = get<1>(lr[r + 1]);\n            if(max_row[k] <= i && l <= r)\
    \ res.emplace_back(max_row[k], l, i, r);\n            lr[l] = {l, r}, lr[r] =\
    \ {l, r};\n        }\n        swap(sorted, nsorted);\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n\n/**\n * @brief Maximum Rectangle (\u6700\u5927\u9577\u65B9\
    \u5F62)\n * @docs docs/others/maximum_rectangle.md\n */\n\n // [(x1, y1), (x2,\
    \ y2)]\nvector<tuple<int, int, int, int>> getMaximumRectangle(vector<vector<bool>>\
    \ &a){\n    vector<tuple<int, int, int, int>> res;\n    int n = a.size(), m =\
    \ a[0].size();\n    vector<int> max_row(m), sorted(m);\n    iota(sorted.begin(),\
    \ sorted.end(), 0);\n    for(int i = 0; i < n; ++i){\n        vector<bool> is_changed(m);\n\
    \        vector<int> nsorted;\n        for(int j = 0; j < m; ++j){\n         \
    \   if(!a[i][j]){\n                max_row[j] = i + 1;\n                is_changed[j]\
    \ = true;\n                nsorted.emplace_back(j);\n            }\n        }\n\
    \        // {l, r}\n        vector<pair<int, int>> lr(m);\n        for(int j =\
    \ 0; j < m; ++j){\n            if(!is_changed[sorted[j]]){\n                nsorted.emplace_back(sorted[j]);\n\
    \            }\n            lr[j] = make_pair(j, j);\n        }\n        for(int\
    \ j = m - 1; j >= 0; --j){\n            int k = nsorted[j];\n            auto\
    \ [l, r] = lr[k];\n            int nl = n + 1, nr = n + 1;\n            if(l !=\
    \ 0) nl = max_row[l - 1];\n            if(r != m - 1) nr = max_row[r + 1];\n \
    \           if(nl <= max_row[k]) l = get<0>(lr[l - 1]);\n            if(nr <=\
    \ max_row[k]) r = get<1>(lr[r + 1]);\n            if(max_row[k] <= i && l <= r)\
    \ res.emplace_back(max_row[k], l, i, r);\n            lr[l] = {l, r}, lr[r] =\
    \ {l, r};\n        }\n        swap(sorted, nsorted);\n    }\n    return res;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/maximum_rectangle.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/maximum_rectangle.hpp
layout: document
redirect_from:
- /library/lib/others/maximum_rectangle.hpp
- /library/lib/others/maximum_rectangle.hpp.html
title: "Maximum Rectangle (\u6700\u5927\u9577\u65B9\u5F62)"
---
## Maximum Rectangle (最大長方形)

#### 概要

$N \times M$ の領域における最大長方形を列挙します。

true の部分における最大長方形を列挙することに注意してください。
また、閉区間で列挙します。

#### 計算量

$\mathrm{O}(NM)$