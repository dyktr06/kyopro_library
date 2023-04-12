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
    \n\ntemplate <typename T>\nstruct DoubleEndedPriorityQueue{\n    priority_queue<T,\
    \ vector<T>, greater<T>> min_q, removed_min;\n    priority_queue<T> max_q, removed_max;\n\
    \    DoubleEndedPriorityQueue(){ }\n    \n    void normalize(){\n        while(!removed_min.empty()\
    \ && min_q.top() == removed_min.top()) {\n            removed_min.pop();\n   \
    \         min_q.pop();\n        }\n        while(!removed_max.empty() && max_q.top()\
    \ == removed_max.top()) {\n            removed_max.pop();\n            max_q.pop();\n\
    \        }\n    }\n\n    void push(const T &x){\n        min_q.push(x);\n    \
    \    max_q.push(x);\n    }\n    \n    void pop_min(){\n        assert(!min_q.empty());\n\
    \        normalize();\n        removed_max.push(min_q.top());\n        min_q.pop();\n\
    \    }\n    \n    void pop_max(){\n        assert(!max_q.empty());\n        normalize();\n\
    \        removed_min.push(max_q.top());\n        max_q.pop();\n    }\n    \n \
    \   T get_min(){\n        assert(!min_q.empty());\n        normalize();\n    \
    \    return min_q.top();\n    }\n    \n    T get_max(){\n        assert(!max_q.empty());\n\
    \        normalize();\n        return max_q.top();\n    }\n};\n#line 6 \"test/library_checker/data_structure/double_ended_priority_queue.test.cpp\"\
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
  timestamp: '2023-04-13 08:33:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/double_ended_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/double_ended_priority_queue.test.cpp
- /verify/test/library_checker/data_structure/double_ended_priority_queue.test.cpp.html
title: test/library_checker/data_structure/double_ended_priority_queue.test.cpp
---
