---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/others/val_range.hpp\"\n\n// 0-indexed, (l, i], [i,\
    \ r)\ntemplate<typename T>\npair<vector<int>, vector<int>> val_range(const vector<T>\
    \ &v, bool is_min){\n    pair<vector<int>, vector<int>> res;\n    int n = v.size();\n\
    \    res.first.assign(n, -1);\n    res.second.assign(n, n);\n    stack<int> st;\n\
    \    st.push(-1);\n    for(int i = 0; i < n; ++i){\n        while(st.top() !=\
    \ -1){\n            if(is_min ^ (v[st.top()] < v[i])){\n                res.second[st.top()]\
    \ = i;\n                st.pop();\n            }else{\n                break;\n\
    \            }\n        }\n        res.first[i] = st.top();\n        st.push(i);\n\
    \    }\n    return res;\n}\n"
  code: "#pragma once\n\n// 0-indexed, (l, i], [i, r)\ntemplate<typename T>\npair<vector<int>,\
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
  timestamp: '2023-10-27 17:53:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/val_range.hpp
layout: document
redirect_from:
- /library/lib/others/val_range.hpp
- /library/lib/others/val_range.hpp.html
title: lib/others/val_range.hpp
---
