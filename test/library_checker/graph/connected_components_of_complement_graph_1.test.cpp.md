---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/fast_deque.hpp
    title: lib/data_structure/fast_deque.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/connected_components_of_complement_graph
    links:
    - https://judge.yosupo.jp/problem/connected_components_of_complement_graph
  bundledCode: "#line 1 \"test/library_checker/graph/connected_components_of_complement_graph_1.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/connected_components_of_complement_graph\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/fast_deque.hpp\"\
    \n\ntemplate <typename T>\nstruct FastDeque{\n    int l = 1, r = 0;\n    vector<T>\
    \ L, R;\n\n    FastDeque(){}\n\n    T front(){\n        if(l <= 0){\n        \
    \    return L[-l];\n        } else{\n            return R[l - 1];\n        }\n\
    \    }\n\n    void push_front(int v){\n        l--;\n        if(l <= 0){\n   \
    \         if((int) L.size() == -l){\n                L.push_back(v);\n       \
    \     } else{\n                L[-l] = v;\n            }\n        } else{\n  \
    \          R[l - 1] = v;\n        }\n    }\n\n    void pop_front(){\n        l++;\n\
    \    }\n\n    T back(){\n        if(r <= 0){\n            return L[-r];\n    \
    \    } else{\n            return R[r - 1];\n        }\n    }\n\n    void push_back(int\
    \ v){\n        if(r < 0){\n            L[-r - 1] = v;\n        } else{\n     \
    \       if((int) R.size() == r){\n                R.push_back(v);\n          \
    \  } else{\n                R[r] = v;\n            }\n        }\n        r++;\n\
    \    }\n\n    void pop_back(){\n        r--;\n    }\n\n    bool empty(){\n   \
    \     return (r - l + 1) == 0;\n    }\n\n    size_t size(){\n        return (r\
    \ - l + 1);\n    }\n};\n#line 6 \"test/library_checker/graph/connected_components_of_complement_graph_1.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n   \
    \ srand(time(NULL));\n\n    int n, m; cin >> n >> m;\n    vector<vector<int>>\
    \ G(n);\n    for(int i = 0; i < m; i++){\n        int a, b; cin >> a >> b;\n \
    \       G[a].push_back(b);\n        G[b].push_back(a);\n    }\n\n    vector<vector<int>>\
    \ ans;\n    vector<bool> used(n), reach(n, true);\n    vector<int> s(n);\n   \
    \ iota(s.begin(), s.end(), 0);\n    for(int i = 0; i < n; i++){\n        if(used[i])\
    \ continue;\n        vector<int> v;\n        FastDeque<int> q;\n        q.push_back(i);\n\
    \        while(!q.empty()){\n            int x = q.front(); q.pop_front();\n \
    \           if(used[x]) continue;\n            used[x] = true;\n            v.push_back(x);\n\
    \            for(auto y : G[x]){\n                reach[y] = false;\n        \
    \    }\n            vector<int> ts;\n            while(!s.empty()){\n        \
    \        if(reach[s.back()]){\n                    q.push_back(s.back());\n  \
    \              } else{\n                    ts.push_back(s.back());\n        \
    \        }\n                s.pop_back();\n            }\n            swap(s,\
    \ ts);\n            for(auto y : G[x]){\n                reach[y] = true;\n  \
    \          }\n        }\n        ans.push_back(v);\n    }\n    cout << ans.size()\
    \ << \"\\n\";\n    for(auto &v : ans){\n        cout << v.size() << \" \";\n \
    \       for(auto x : v){\n            cout << x << \" \";\n        }\n       \
    \ cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/connected_components_of_complement_graph\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/fast_deque.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n   \
    \ srand(time(NULL));\n\n    int n, m; cin >> n >> m;\n    vector<vector<int>>\
    \ G(n);\n    for(int i = 0; i < m; i++){\n        int a, b; cin >> a >> b;\n \
    \       G[a].push_back(b);\n        G[b].push_back(a);\n    }\n\n    vector<vector<int>>\
    \ ans;\n    vector<bool> used(n), reach(n, true);\n    vector<int> s(n);\n   \
    \ iota(s.begin(), s.end(), 0);\n    for(int i = 0; i < n; i++){\n        if(used[i])\
    \ continue;\n        vector<int> v;\n        FastDeque<int> q;\n        q.push_back(i);\n\
    \        while(!q.empty()){\n            int x = q.front(); q.pop_front();\n \
    \           if(used[x]) continue;\n            used[x] = true;\n            v.push_back(x);\n\
    \            for(auto y : G[x]){\n                reach[y] = false;\n        \
    \    }\n            vector<int> ts;\n            while(!s.empty()){\n        \
    \        if(reach[s.back()]){\n                    q.push_back(s.back());\n  \
    \              } else{\n                    ts.push_back(s.back());\n        \
    \        }\n                s.pop_back();\n            }\n            swap(s,\
    \ ts);\n            for(auto y : G[x]){\n                reach[y] = true;\n  \
    \          }\n        }\n        ans.push_back(v);\n    }\n    cout << ans.size()\
    \ << \"\\n\";\n    for(auto &v : ans){\n        cout << v.size() << \" \";\n \
    \       for(auto x : v){\n            cout << x << \" \";\n        }\n       \
    \ cout << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/data_structure/fast_deque.hpp
  isVerificationFile: true
  path: test/library_checker/graph/connected_components_of_complement_graph_1.test.cpp
  requiredBy: []
  timestamp: '2024-05-06 22:04:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/connected_components_of_complement_graph_1.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/connected_components_of_complement_graph_1.test.cpp
- /verify/test/library_checker/graph/connected_components_of_complement_graph_1.test.cpp.html
title: test/library_checker/graph/connected_components_of_complement_graph_1.test.cpp
---
