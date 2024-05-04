---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/deque_operate_all_composite.test.cpp
    title: test/library_checker/data_structure/deque_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/deswag.md
    document_title: DESWAG
    links: []
  bundledCode: "#line 2 \"lib/data_structure/deswag.hpp\"\n\n/**\n * @brief DESWAG\n\
    \ * @docs docs/data_structure/deswag.md\n */\n\ntemplate <typename T>\nstruct\
    \ DESWAG{\n    using Op = function<T(T, T)>;\n\nprivate:\n    struct node{\n \
    \   public:\n        T val, sum;\n        node(const T &val, const T &sum) : val(val),\
    \ sum(sum) {}\n    };\n\n    Op op;\n    stack<node> front_stack, back_stack,\
    \ temp_stack;\n\npublic:\n    DESWAG(const Op &op = Op()) : op(op), front_stack(),\
    \ back_stack(), temp_stack() {}\n\n    bool empty(){\n        return front_stack.empty()\
    \ && back_stack.empty();\n    }\n\n    size_t size(){\n        return front_stack.size()\
    \ + back_stack.size();\n    }\n\n    T fold(){\n        if(front_stack.empty()){\n\
    \            return back_stack.top().sum;\n        } else if(back_stack.empty()){\n\
    \            return front_stack.top().sum;\n        } else{\n            return\
    \ op(front_stack.top().sum, back_stack.top().sum);\n        }\n    }\n\n    void\
    \ push_front(const T &x){\n        if(front_stack.empty()){\n            front_stack.emplace(x,\
    \ x);\n        } else{\n            T s = op(x, front_stack.top().sum);\n    \
    \        front_stack.emplace(x, s);\n        }\n    }\n\n    void push_back(const\
    \ T &x){\n        if(back_stack.empty()){\n            back_stack.emplace(x, x);\n\
    \        } else{\n            T s = op(back_stack.top().sum, x);\n           \
    \ back_stack.emplace(x, s);\n        }\n    }\n\n    void pop_front(){\n     \
    \   if(front_stack.empty()){\n            int half = (back_stack.size() + 1) /\
    \ 2;\n            while(!back_stack.empty()){\n                if(back_stack.size()\
    \ == half){\n                    front_stack.emplace(back_stack.top().val, back_stack.top().val);\n\
    \                } else if(back_stack.size() < half){\n                    T s\
    \ = op(back_stack.top().val, front_stack.top().sum);\n                    front_stack.emplace(back_stack.top().val,\
    \ s);\n                } else{\n                    temp_stack.emplace(back_stack.top().val,\
    \ back_stack.top().val);\n                }\n                back_stack.pop();\n\
    \            }\n            if(!temp_stack.empty()){\n                back_stack.emplace(temp_stack.top().val,\
    \ temp_stack.top().val);\n                temp_stack.pop();\n                while(!temp_stack.empty()){\n\
    \                    T s = op(back_stack.top().sum, temp_stack.top().val);\n \
    \                   back_stack.emplace(temp_stack.top().val, s);\n           \
    \         temp_stack.pop();\n                }\n            }\n        }\n   \
    \     front_stack.pop();\n    }\n\n    void pop_back(){\n        if(back_stack.empty()){\n\
    \            int half = (front_stack.size() + 1) / 2;\n            while(!front_stack.empty()){\n\
    \                if(front_stack.size() == half){\n                    back_stack.emplace(front_stack.top().val,\
    \ front_stack.top().val);\n                } else if(front_stack.size() < half){\n\
    \                    T s = op(back_stack.top().sum, front_stack.top().val);\n\
    \                    back_stack.emplace(front_stack.top().val, s);\n         \
    \       } else{\n                    temp_stack.emplace(front_stack.top().val,\
    \ front_stack.top().val);\n                }\n                front_stack.pop();\n\
    \            }\n            if(!temp_stack.empty()){\n                front_stack.emplace(temp_stack.top().val,\
    \ temp_stack.top().val);\n                temp_stack.pop();\n                while(!temp_stack.empty()){\n\
    \                    T s = op(temp_stack.top().val, front_stack.top().sum);\n\
    \                    front_stack.emplace(temp_stack.top().val, s);\n         \
    \           temp_stack.pop();\n                }\n            }\n        }\n \
    \       back_stack.pop();\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief DESWAG\n * @docs docs/data_structure/deswag.md\n\
    \ */\n\ntemplate <typename T>\nstruct DESWAG{\n    using Op = function<T(T, T)>;\n\
    \nprivate:\n    struct node{\n    public:\n        T val, sum;\n        node(const\
    \ T &val, const T &sum) : val(val), sum(sum) {}\n    };\n\n    Op op;\n    stack<node>\
    \ front_stack, back_stack, temp_stack;\n\npublic:\n    DESWAG(const Op &op = Op())\
    \ : op(op), front_stack(), back_stack(), temp_stack() {}\n\n    bool empty(){\n\
    \        return front_stack.empty() && back_stack.empty();\n    }\n\n    size_t\
    \ size(){\n        return front_stack.size() + back_stack.size();\n    }\n\n \
    \   T fold(){\n        if(front_stack.empty()){\n            return back_stack.top().sum;\n\
    \        } else if(back_stack.empty()){\n            return front_stack.top().sum;\n\
    \        } else{\n            return op(front_stack.top().sum, back_stack.top().sum);\n\
    \        }\n    }\n\n    void push_front(const T &x){\n        if(front_stack.empty()){\n\
    \            front_stack.emplace(x, x);\n        } else{\n            T s = op(x,\
    \ front_stack.top().sum);\n            front_stack.emplace(x, s);\n        }\n\
    \    }\n\n    void push_back(const T &x){\n        if(back_stack.empty()){\n \
    \           back_stack.emplace(x, x);\n        } else{\n            T s = op(back_stack.top().sum,\
    \ x);\n            back_stack.emplace(x, s);\n        }\n    }\n\n    void pop_front(){\n\
    \        if(front_stack.empty()){\n            int half = (back_stack.size() +\
    \ 1) / 2;\n            while(!back_stack.empty()){\n                if(back_stack.size()\
    \ == half){\n                    front_stack.emplace(back_stack.top().val, back_stack.top().val);\n\
    \                } else if(back_stack.size() < half){\n                    T s\
    \ = op(back_stack.top().val, front_stack.top().sum);\n                    front_stack.emplace(back_stack.top().val,\
    \ s);\n                } else{\n                    temp_stack.emplace(back_stack.top().val,\
    \ back_stack.top().val);\n                }\n                back_stack.pop();\n\
    \            }\n            if(!temp_stack.empty()){\n                back_stack.emplace(temp_stack.top().val,\
    \ temp_stack.top().val);\n                temp_stack.pop();\n                while(!temp_stack.empty()){\n\
    \                    T s = op(back_stack.top().sum, temp_stack.top().val);\n \
    \                   back_stack.emplace(temp_stack.top().val, s);\n           \
    \         temp_stack.pop();\n                }\n            }\n        }\n   \
    \     front_stack.pop();\n    }\n\n    void pop_back(){\n        if(back_stack.empty()){\n\
    \            int half = (front_stack.size() + 1) / 2;\n            while(!front_stack.empty()){\n\
    \                if(front_stack.size() == half){\n                    back_stack.emplace(front_stack.top().val,\
    \ front_stack.top().val);\n                } else if(front_stack.size() < half){\n\
    \                    T s = op(back_stack.top().sum, front_stack.top().val);\n\
    \                    back_stack.emplace(front_stack.top().val, s);\n         \
    \       } else{\n                    temp_stack.emplace(front_stack.top().val,\
    \ front_stack.top().val);\n                }\n                front_stack.pop();\n\
    \            }\n            if(!temp_stack.empty()){\n                front_stack.emplace(temp_stack.top().val,\
    \ temp_stack.top().val);\n                temp_stack.pop();\n                while(!temp_stack.empty()){\n\
    \                    T s = op(temp_stack.top().val, front_stack.top().sum);\n\
    \                    front_stack.emplace(temp_stack.top().val, s);\n         \
    \           temp_stack.pop();\n                }\n            }\n        }\n \
    \       back_stack.pop();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/deswag.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/deque_operate_all_composite.test.cpp
documentation_of: lib/data_structure/deswag.hpp
layout: document
redirect_from:
- /library/lib/data_structure/deswag.hpp
- /library/lib/data_structure/deswag.hpp.html
title: DESWAG
---
## DESWAG

#### 使い方

- `DESWAG<T>(op)`: 両端 SWAG を構築します。
- `fold()`: 要素全てに op を適用させた値を計算します。
- `push_front(x)`: x を先頭に追加します。
- `push_back(x)`: x を末尾に追加します。
- `pop_front()`: 先頭の要素を削除します。
- `pop_back()`: 末尾の要素を削除します。

#### 計算量

- `fold()`: $\mathrm{O}(1)$
- `push_front(x)`: $\mathrm{O}(1)$
- `push_back(x)`: $\mathrm{O}(1)$
- `pop_front()`: 償却 $\mathrm{O}(1)$
- `pop_back()`: 償却 $\mathrm{O}(1)$