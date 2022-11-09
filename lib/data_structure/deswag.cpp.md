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
  bundledCode: "#line 1 \"lib/data_structure/deswag.cpp\"\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n/* \n    DESWAG<T>(op) : \u4E21\u7AEFSWAG \u3092\u69CB\
    \u7BC9\u3057\u307E\u3059\u3002\n    fold() : \u8981\u7D20\u5168\u3066\u306B op\
    \ \u3092\u9069\u7528\u3055\u305B\u305F\u5024\u3092\u8A08\u7B97\u3057\u307E\u3059\
    \u3002: O(1)\n    push_front(x) : x \u3092\u5148\u982D\u306B\u8FFD\u52A0\u3057\
    \u307E\u3059\u3002: O(1)\n    push_back(x) : x \u3092\u672B\u5C3E\u306B\u8FFD\u52A0\
    \u3057\u307E\u3059\u3002: O(1)\n    pop_front() : x \u3092\u5148\u982D\u304B\u3089\
    \u524A\u9664\u3057\u307E\u3059\u3002: \u511F\u5374 O(1)\n    pop_back() : x \u3092\
    \u672B\u5C3E\u304B\u3089\u524A\u9664\u3057\u307E\u3059\u3002: \u511F\u5374 O(1)\n\
    */\n\ntemplate <typename T>\nstruct DESWAG{\n    using Op = function<T(T, T)>;\n\
    \nprivate:\n    struct node{\n    public:\n        T val, sum;\n        node(const\
    \ T &val, const T &sum) : val(val), sum(sum) {}\n    };\n\n    Op op;\n    stack<node>\
    \ front_stack, back_stack, temp_stack;\n\npublic:\n    DESWAG(const Op &op = Op())\
    \ : op(op), front_stack(), back_stack(), temp_stack() {}\n\n    bool empty(){\n\
    \        return front_stack.empty() && back_stack.empty();\n    }\n\n    size_t\
    \ size(){\n        return front_stack.size() + back_stack.size();\n    }\n\n \
    \   T fold(){\n        if(front_stack.empty()){\n            return back_stack.top().sum;\n\
    \        }else if(back_stack.empty()){\n            return front_stack.top().sum;\n\
    \        }else{\n            return op(front_stack.top().sum, back_stack.top().sum);\n\
    \        }\n    }\n\n    void push_front(const T &x){\n        if(front_stack.empty()){\n\
    \            front_stack.emplace(x, x);\n        }else{\n            T s = op(x,\
    \ front_stack.top().sum);\n            front_stack.emplace(x, s);\n        }\n\
    \    }\n\n    void push_back(const T &x){\n        if(back_stack.empty()){\n \
    \           back_stack.emplace(x, x);\n        }else{\n            T s = op(back_stack.top().sum,\
    \ x);\n            back_stack.emplace(x, s);\n        }\n    }\n\n    void pop_front(){\n\
    \        if(front_stack.empty()){\n            int half = (back_stack.size() +\
    \ 1) / 2;\n            while(!back_stack.empty()){\n                if(back_stack.size()\
    \ == half){\n                    front_stack.emplace(back_stack.top().val, back_stack.top().val);\n\
    \                }else if(back_stack.size() < half){\n                    T s\
    \ = op(back_stack.top().val, front_stack.top().sum);\n                    front_stack.emplace(back_stack.top().val,\
    \ s);\n                }else{\n                    temp_stack.emplace(back_stack.top().val,\
    \ back_stack.top().val);\n                }\n                back_stack.pop();\n\
    \            }\n            if(!temp_stack.empty()){\n                back_stack.emplace(temp_stack.top().val,\
    \ temp_stack.top().val);\n                temp_stack.pop();\n                while(!temp_stack.empty()){\n\
    \                    T s = op(back_stack.top().sum, temp_stack.top().val);\n \
    \                   back_stack.emplace(temp_stack.top().val, s);\n           \
    \         temp_stack.pop();\n                }\n            }\n        }\n   \
    \     front_stack.pop();\n    }\n\n    void pop_back(){\n        if(back_stack.empty()){\n\
    \            int half = (front_stack.size() + 1) / 2;\n            while(!front_stack.empty()){\n\
    \                if(front_stack.size() == half){\n                    back_stack.emplace(front_stack.top().val,\
    \ front_stack.top().val);\n                }else if(front_stack.size() < half){\n\
    \                    T s = op(back_stack.top().sum, front_stack.top().val);\n\
    \                    back_stack.emplace(front_stack.top().val, s);\n         \
    \       }else{\n                    temp_stack.emplace(front_stack.top().val,\
    \ front_stack.top().val);\n                }\n                front_stack.pop();\n\
    \            }\n            if(!temp_stack.empty()){\n                front_stack.emplace(temp_stack.top().val,\
    \ temp_stack.top().val);\n                temp_stack.pop();\n                while(!temp_stack.empty()){\n\
    \                    T s = op(temp_stack.top().val, front_stack.top().sum);\n\
    \                    front_stack.emplace(temp_stack.top().val, s);\n         \
    \           temp_stack.pop();\n                }\n            }\n        }\n \
    \       back_stack.pop();\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n/* \n    DESWAG<T>(op)\
    \ : \u4E21\u7AEFSWAG \u3092\u69CB\u7BC9\u3057\u307E\u3059\u3002\n    fold() :\
    \ \u8981\u7D20\u5168\u3066\u306B op \u3092\u9069\u7528\u3055\u305B\u305F\u5024\
    \u3092\u8A08\u7B97\u3057\u307E\u3059\u3002: O(1)\n    push_front(x) : x \u3092\
    \u5148\u982D\u306B\u8FFD\u52A0\u3057\u307E\u3059\u3002: O(1)\n    push_back(x)\
    \ : x \u3092\u672B\u5C3E\u306B\u8FFD\u52A0\u3057\u307E\u3059\u3002: O(1)\n   \
    \ pop_front() : x \u3092\u5148\u982D\u304B\u3089\u524A\u9664\u3057\u307E\u3059\
    \u3002: \u511F\u5374 O(1)\n    pop_back() : x \u3092\u672B\u5C3E\u304B\u3089\u524A\
    \u9664\u3057\u307E\u3059\u3002: \u511F\u5374 O(1)\n*/\n\ntemplate <typename T>\n\
    struct DESWAG{\n    using Op = function<T(T, T)>;\n\nprivate:\n    struct node{\n\
    \    public:\n        T val, sum;\n        node(const T &val, const T &sum) :\
    \ val(val), sum(sum) {}\n    };\n\n    Op op;\n    stack<node> front_stack, back_stack,\
    \ temp_stack;\n\npublic:\n    DESWAG(const Op &op = Op()) : op(op), front_stack(),\
    \ back_stack(), temp_stack() {}\n\n    bool empty(){\n        return front_stack.empty()\
    \ && back_stack.empty();\n    }\n\n    size_t size(){\n        return front_stack.size()\
    \ + back_stack.size();\n    }\n\n    T fold(){\n        if(front_stack.empty()){\n\
    \            return back_stack.top().sum;\n        }else if(back_stack.empty()){\n\
    \            return front_stack.top().sum;\n        }else{\n            return\
    \ op(front_stack.top().sum, back_stack.top().sum);\n        }\n    }\n\n    void\
    \ push_front(const T &x){\n        if(front_stack.empty()){\n            front_stack.emplace(x,\
    \ x);\n        }else{\n            T s = op(x, front_stack.top().sum);\n     \
    \       front_stack.emplace(x, s);\n        }\n    }\n\n    void push_back(const\
    \ T &x){\n        if(back_stack.empty()){\n            back_stack.emplace(x, x);\n\
    \        }else{\n            T s = op(back_stack.top().sum, x);\n            back_stack.emplace(x,\
    \ s);\n        }\n    }\n\n    void pop_front(){\n        if(front_stack.empty()){\n\
    \            int half = (back_stack.size() + 1) / 2;\n            while(!back_stack.empty()){\n\
    \                if(back_stack.size() == half){\n                    front_stack.emplace(back_stack.top().val,\
    \ back_stack.top().val);\n                }else if(back_stack.size() < half){\n\
    \                    T s = op(back_stack.top().val, front_stack.top().sum);\n\
    \                    front_stack.emplace(back_stack.top().val, s);\n         \
    \       }else{\n                    temp_stack.emplace(back_stack.top().val, back_stack.top().val);\n\
    \                }\n                back_stack.pop();\n            }\n       \
    \     if(!temp_stack.empty()){\n                back_stack.emplace(temp_stack.top().val,\
    \ temp_stack.top().val);\n                temp_stack.pop();\n                while(!temp_stack.empty()){\n\
    \                    T s = op(back_stack.top().sum, temp_stack.top().val);\n \
    \                   back_stack.emplace(temp_stack.top().val, s);\n           \
    \         temp_stack.pop();\n                }\n            }\n        }\n   \
    \     front_stack.pop();\n    }\n\n    void pop_back(){\n        if(back_stack.empty()){\n\
    \            int half = (front_stack.size() + 1) / 2;\n            while(!front_stack.empty()){\n\
    \                if(front_stack.size() == half){\n                    back_stack.emplace(front_stack.top().val,\
    \ front_stack.top().val);\n                }else if(front_stack.size() < half){\n\
    \                    T s = op(back_stack.top().sum, front_stack.top().val);\n\
    \                    back_stack.emplace(front_stack.top().val, s);\n         \
    \       }else{\n                    temp_stack.emplace(front_stack.top().val,\
    \ front_stack.top().val);\n                }\n                front_stack.pop();\n\
    \            }\n            if(!temp_stack.empty()){\n                front_stack.emplace(temp_stack.top().val,\
    \ temp_stack.top().val);\n                temp_stack.pop();\n                while(!temp_stack.empty()){\n\
    \                    T s = op(temp_stack.top().val, front_stack.top().sum);\n\
    \                    front_stack.emplace(temp_stack.top().val, s);\n         \
    \           temp_stack.pop();\n                }\n            }\n        }\n \
    \       back_stack.pop();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/deswag.cpp
  requiredBy: []
  timestamp: '2022-11-10 01:06:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/deswag.cpp
layout: document
redirect_from:
- /library/lib/data_structure/deswag.cpp
- /library/lib/data_structure/deswag.cpp.html
title: lib/data_structure/deswag.cpp
---
