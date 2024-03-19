---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/cartesian_tree.hpp
    title: lib/graph/cartesian_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"test/library_checker/tree/cartesian_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 3 \"lib/graph/cartesian_tree.hpp\"\nusing namespace\
    \ std;\n\ntemplate <typename T>\npair<vector<vector<int>>, int> CartesianTree(vector<T>\
    \ &a){\n    int n = a.size();\n    vector<vector<int>> G(n);\n    vector<int>\
    \ par(n, -1), st;\n    for(int i = 0; i < n; ++i){\n        int prev = -1;\n \
    \       while(!st.empty() && a[i] < a[st.back()]){\n            prev = st.back();\n\
    \            st.pop_back();\n        }\n        if(prev != -1){\n            par[prev]\
    \ = i;\n        }\n        if(!st.empty()){\n            par[i] = st.back();\n\
    \        }\n        st.emplace_back(i);\n    }\n    int root = -1;\n    for(int\
    \ i = 0; i < n; ++i){\n        if(par[i] != -1){\n            G[par[i]].emplace_back(i);\n\
    \        }else{\n            root = i;\n        }\n    }\n    return make_pair(G,\
    \ root);\n}\n#line 6 \"test/library_checker/tree/cartesian_tree.test.cpp\"\n\n\
    int main(){\n    int n; cin >> n;\n    vector<int> a(n);\n    for(int i = 0; i\
    \ < n; i++){\n        cin >> a[i];\n    }\n    pair<vector<vector<int>>, int>\
    \ ct = CartesianTree(a);\n    auto [G, r] = ct;\n    vector<int> ans(n);\n   \
    \ ans[r] = r;\n    for(int i = 0; i < n; i++){\n        for(auto x : G[i]){\n\
    \            ans[x] = i;\n        }\n    }\n    for(int i = 0; i < n; i++){\n\
    \        cout << ans[i] << \" \\n\"[i == n - 1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/cartesian_tree.hpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    vector<int> a(n);\n    for(int i =\
    \ 0; i < n; i++){\n        cin >> a[i];\n    }\n    pair<vector<vector<int>>,\
    \ int> ct = CartesianTree(a);\n    auto [G, r] = ct;\n    vector<int> ans(n);\n\
    \    ans[r] = r;\n    for(int i = 0; i < n; i++){\n        for(auto x : G[i]){\n\
    \            ans[x] = i;\n        }\n    }\n    for(int i = 0; i < n; i++){\n\
    \        cout << ans[i] << \" \\n\"[i == n - 1];\n    }\n}"
  dependsOn:
  - lib/graph/cartesian_tree.hpp
  isVerificationFile: true
  path: test/library_checker/tree/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2024-03-20 02:54:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/tree/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/tree/cartesian_tree.test.cpp
- /verify/test/library_checker/tree/cartesian_tree.test.cpp.html
title: test/library_checker/tree/cartesian_tree.test.cpp
---
