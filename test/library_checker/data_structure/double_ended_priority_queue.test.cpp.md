---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/double_ended_priority_queue.hpp
    title: lib/data_structure/double_ended_priority_queue.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"test/library_checker/data_structure/double_ended_priority_queue.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/double_ended_priority_queue.hpp\"\
    \n\ntemplate <typename T>\nstruct DoubleEndedPriorityQueue{\n    multiset<T> q;\n\
    \    DoubleEndedPriorityQueue(){ }\n    \n    void push(const T &x){\n       \
    \ q.insert(x);\n    }\n    \n    void pop_min(){\n        assert(!q.empty());\n\
    \        q.erase(q.begin());\n    }\n    \n    void pop_max(){\n        assert(!q.empty());\n\
    \        q.erase(--q.end());\n    }\n    \n    T get_min() const{\n        return\
    \ *q.begin();\n    }\n    \n    T get_max() const{\n        return *(--q.end());\n\
    \    }\n    \n    size_t size() const{\n        return q.size();\n    }\n};\n\
    #line 6 \"test/library_checker/data_structure/double_ended_priority_queue.test.cpp\"\
    \n\nint main(){\n    int n, q; cin >> n >> q;\n    DoubleEndedPriorityQueue<int>\
    \ depq;\n    for(int i = 0; i < n; i++){\n        int s; cin >> s;\n        depq.push(s);\n\
    \    }\n    while(q--){\n        int t; cin >> t;\n        if(t == 0){\n     \
    \       int x; cin >> x;\n            depq.push(x);\n        }else if(t == 1){\n\
    \            cout << depq.get_min() << \"\\n\";\n            depq.pop_min();\n\
    \        }else{\n            cout << depq.get_max() << \"\\n\";\n            depq.pop_max();\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/double_ended_priority_queue.hpp\"\
    \n\nint main(){\n    int n, q; cin >> n >> q;\n    DoubleEndedPriorityQueue<int>\
    \ depq;\n    for(int i = 0; i < n; i++){\n        int s; cin >> s;\n        depq.push(s);\n\
    \    }\n    while(q--){\n        int t; cin >> t;\n        if(t == 0){\n     \
    \       int x; cin >> x;\n            depq.push(x);\n        }else if(t == 1){\n\
    \            cout << depq.get_min() << \"\\n\";\n            depq.pop_min();\n\
    \        }else{\n            cout << depq.get_max() << \"\\n\";\n            depq.pop_max();\n\
    \        }\n    }\n}"
  dependsOn:
  - lib/data_structure/double_ended_priority_queue.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/double_ended_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2022-11-10 09:23:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/double_ended_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/double_ended_priority_queue.test.cpp
- /verify/test/library_checker/data_structure/double_ended_priority_queue.test.cpp.html
title: test/library_checker/data_structure/double_ended_priority_queue.test.cpp
---
