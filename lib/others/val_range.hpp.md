---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/others/val_range.md
    document_title: val_range
    links: []
  bundledCode: "#line 2 \"lib/others/val_range.hpp\"\n\n/**\n * @brief val_range\n\
    \ * @docs docs/others/val_range.md\n */\n\n// 0-indexed, (l, i], [i, r)\ntemplate<typename\
    \ T>\npair<vector<int>, vector<int>> val_range(const vector<T> &v, bool is_min){\n\
    \    pair<vector<int>, vector<int>> res;\n    int n = v.size();\n    res.first.assign(n,\
    \ -1);\n    res.second.assign(n, n);\n    stack<int> st;\n    st.push(-1);\n \
    \   for(int i = 0; i < n; ++i){\n        while(st.top() != -1){\n            if(is_min\
    \ ^ (v[st.top()] < v[i])){\n                res.second[st.top()] = i;\n      \
    \          st.pop();\n            }else{\n                break;\n           \
    \ }\n        }\n        res.first[i] = st.top();\n        st.push(i);\n    }\n\
    \    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @brief val_range\n * @docs docs/others/val_range.md\n\
    \ */\n\n// 0-indexed, (l, i], [i, r)\ntemplate<typename T>\npair<vector<int>,\
    \ vector<int>> val_range(const vector<T> &v, bool is_min){\n    pair<vector<int>,\
    \ vector<int>> res;\n    int n = v.size();\n    res.first.assign(n, -1);\n   \
    \ res.second.assign(n, n);\n    stack<int> st;\n    st.push(-1);\n    for(int\
    \ i = 0; i < n; ++i){\n        while(st.top() != -1){\n            if(is_min ^\
    \ (v[st.top()] < v[i])){\n                res.second[st.top()] = i;\n        \
    \        st.pop();\n            }else{\n                break;\n            }\n\
    \        }\n        res.first[i] = st.top();\n        st.push(i);\n    }\n   \
    \ return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/val_range.hpp
  requiredBy: []
  timestamp: '2024-03-21 03:03:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/val_range.hpp
layout: document
redirect_from:
- /library/lib/others/val_range.hpp
- /library/lib/others/val_range.hpp.html
title: val_range
---
## val_range

#### 概要

要素数 $N$ の数列 $v$ において、以下のものが求められます。

$i \: (0 \leq i \leq N - 1)$ について、
$\min(v_{l + 1}, ..., v_{i - 1}, v_{i}) = v_i$ が成り立つ最小の $l$ と
$\min(v_i, v_{i + 1}, ..., v_{r - 1}) = v_i$ が成り立つ最大の $r$ 

引数における is_min = false とすれば、$\max$ についても同様に求められます。

#### 計算量

$\mathrm{O}(N)$