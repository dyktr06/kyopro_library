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
  bundledCode: "#line 1 \"lib/data_structure/double_ended_priority_queue.cpp\"\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\ntemplate <typename T>\nstruct DoubleEndedPriorityQueue{\n\
    \    multiset<T> q;\n    DoubleEndedPriorityQueue(){ }\n    \n    void push(const\
    \ T &x){\n        q.insert(x);\n    }\n    \n    void pop_min(){\n        assert(!q.empty());\n\
    \        q.erase(q.begin());\n    }\n    \n    void pop_max(){\n        assert(!q.empty());\n\
    \        q.erase(--q.end());\n    }\n    \n    T get_min() const{\n        return\
    \ *q.begin();\n    }\n    \n    T get_max() const{\n        return *(--q.end());\n\
    \    }\n    \n    size_t size() const{\n        return q.size();\n    }\n};\n\n\
    // example\nint main(){\n    int n, q; cin >> n >> q;\n    DoubleEndedPriorityQueue<int>\
    \ depq;\n    for(int i = 0; i < n; i++){\n        int s; cin >> s;\n        depq.push(s);\n\
    \    }\n    while(q--){\n        int t; cin >> t;\n        if(t == 0){\n     \
    \       int x; cin >> x;\n            depq.push(x);\n        }else if(t == 1){\n\
    \            cout << depq.get_min() << \"\\n\";\n            depq.pop_min();\n\
    \        }else{\n            cout << depq.get_max() << \"\\n\";\n            depq.pop_max();\n\
    \        }\n    }\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\ntemplate <typename T>\n\
    struct DoubleEndedPriorityQueue{\n    multiset<T> q;\n    DoubleEndedPriorityQueue(){\
    \ }\n    \n    void push(const T &x){\n        q.insert(x);\n    }\n    \n   \
    \ void pop_min(){\n        assert(!q.empty());\n        q.erase(q.begin());\n\
    \    }\n    \n    void pop_max(){\n        assert(!q.empty());\n        q.erase(--q.end());\n\
    \    }\n    \n    T get_min() const{\n        return *q.begin();\n    }\n    \n\
    \    T get_max() const{\n        return *(--q.end());\n    }\n    \n    size_t\
    \ size() const{\n        return q.size();\n    }\n};\n\n// example\nint main(){\n\
    \    int n, q; cin >> n >> q;\n    DoubleEndedPriorityQueue<int> depq;\n    for(int\
    \ i = 0; i < n; i++){\n        int s; cin >> s;\n        depq.push(s);\n    }\n\
    \    while(q--){\n        int t; cin >> t;\n        if(t == 0){\n            int\
    \ x; cin >> x;\n            depq.push(x);\n        }else if(t == 1){\n       \
    \     cout << depq.get_min() << \"\\n\";\n            depq.pop_min();\n      \
    \  }else{\n            cout << depq.get_max() << \"\\n\";\n            depq.pop_max();\n\
    \        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/double_ended_priority_queue.cpp
  requiredBy: []
  timestamp: '2022-11-10 01:06:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/double_ended_priority_queue.cpp
layout: document
redirect_from:
- /library/lib/data_structure/double_ended_priority_queue.cpp
- /library/lib/data_structure/double_ended_priority_queue.cpp.html
title: lib/data_structure/double_ended_priority_queue.cpp
---
