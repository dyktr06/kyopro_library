---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/data_structure/queue_operate_all_composite.test.cpp
    title: test/library_checker/data_structure/queue_operate_all_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/data_structure/swag.md
    document_title: SWAG
    links: []
  bundledCode: "#line 2 \"lib/data_structure/swag.hpp\"\n\n#include <stack>\n#include\
    \ <cassert>\n\n/**\n * @brief SWAG\n * @docs docs/data_structure/swag.md\n */\n\
    \ntemplate <typename T, T (*op)(T, T)>\nstruct SWAG{\nprivate:\n    struct node{\n\
    \    public:\n        T val, sum;\n        node(const T &val, const T &sum) :\
    \ val(val), sum(sum) {}\n    };\n\n    std::stack<node> front_stack, back_stack;\n\
    \npublic:\n    SWAG() : front_stack(), back_stack() {}\n\n    bool empty(){\n\
    \        return front_stack.empty() && back_stack.empty();\n    }\n\n    size_t\
    \ size(){\n        return front_stack.size() + back_stack.size();\n    }\n\n \
    \   T fold(){\n        if(front_stack.empty()){\n            return back_stack.top().sum;\n\
    \        } else if(back_stack.empty()){\n            return front_stack.top().sum;\n\
    \        } else{\n            return op(front_stack.top().sum, back_stack.top().sum);\n\
    \        }\n    }\n\n    void push(const T &x){\n        if(back_stack.empty()){\n\
    \            back_stack.emplace(x, x);\n        } else{\n            T s = op(back_stack.top().sum,\
    \ x);\n            back_stack.emplace(x, s);\n        }\n    }\n\n    void pop(){\n\
    \        assert(!empty());\n        if(front_stack.empty()){\n            front_stack.emplace(back_stack.top().val,\
    \ back_stack.top().val);\n            back_stack.pop();\n            while(!back_stack.empty()){\n\
    \                T s = op(back_stack.top().val, front_stack.top().sum);\n    \
    \            front_stack.emplace(back_stack.top().val, s);\n                back_stack.pop();\n\
    \            }\n        }\n        front_stack.pop();\n    }\n};\n"
  code: "#pragma once\n\n#include <stack>\n#include <cassert>\n\n/**\n * @brief SWAG\n\
    \ * @docs docs/data_structure/swag.md\n */\n\ntemplate <typename T, T (*op)(T,\
    \ T)>\nstruct SWAG{\nprivate:\n    struct node{\n    public:\n        T val, sum;\n\
    \        node(const T &val, const T &sum) : val(val), sum(sum) {}\n    };\n\n\
    \    std::stack<node> front_stack, back_stack;\n\npublic:\n    SWAG() : front_stack(),\
    \ back_stack() {}\n\n    bool empty(){\n        return front_stack.empty() &&\
    \ back_stack.empty();\n    }\n\n    size_t size(){\n        return front_stack.size()\
    \ + back_stack.size();\n    }\n\n    T fold(){\n        if(front_stack.empty()){\n\
    \            return back_stack.top().sum;\n        } else if(back_stack.empty()){\n\
    \            return front_stack.top().sum;\n        } else{\n            return\
    \ op(front_stack.top().sum, back_stack.top().sum);\n        }\n    }\n\n    void\
    \ push(const T &x){\n        if(back_stack.empty()){\n            back_stack.emplace(x,\
    \ x);\n        } else{\n            T s = op(back_stack.top().sum, x);\n     \
    \       back_stack.emplace(x, s);\n        }\n    }\n\n    void pop(){\n     \
    \   assert(!empty());\n        if(front_stack.empty()){\n            front_stack.emplace(back_stack.top().val,\
    \ back_stack.top().val);\n            back_stack.pop();\n            while(!back_stack.empty()){\n\
    \                T s = op(back_stack.top().val, front_stack.top().sum);\n    \
    \            front_stack.emplace(back_stack.top().val, s);\n                back_stack.pop();\n\
    \            }\n        }\n        front_stack.pop();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/swag.hpp
  requiredBy: []
  timestamp: '2024-11-01 15:41:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/data_structure/queue_operate_all_composite.test.cpp
documentation_of: lib/data_structure/swag.hpp
layout: document
redirect_from:
- /library/lib/data_structure/swag.hpp
- /library/lib/data_structure/swag.hpp.html
title: SWAG
---
## SWAG

#### 使い方

- `SWAG<T>(op)`: SWAG を構築します。
- `fold()`: 要素全てに op を適用させた値を計算します。
- `push(x)`: x を先頭に追加します。
- `pop()`: 先頭の要素を削除します。

#### 計算量

- `fold()`: $\mathrm{O}(1)$
- `push(x)`: $\mathrm{O}(1)$
- `pop()`: 償却 $\mathrm{O}(1)$