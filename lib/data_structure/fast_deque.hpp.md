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
  bundledCode: "#line 2 \"lib/data_structure/fast_deque.hpp\"\n\ntemplate <typename\
    \ T>\nstruct FastDeque{\n    int l = 1, r = 0;\n    vector<T> L, R;\n\n    FastDeque(){}\n\
    \n    T front(){\n        if(l <= 0){\n            return L[-l];\n        } else{\n\
    \            return R[l - 1];\n        }\n    }\n\n    void push_front(int v){\n\
    \        l--;\n        if(l <= 0){\n            if((int) L.size() == -l){\n  \
    \              L.push_back(v);\n            } else{\n                L[-l] = v;\n\
    \            }\n        } else{\n            R[l - 1] = v;\n        }\n    }\n\
    \n    void pop_front(){\n        l++;\n    }\n\n    T back(){\n        if(r <=\
    \ 0){\n            return L[-r];\n        } else{\n            return R[r - 1];\n\
    \        }\n    }\n\n    void push_back(int v){\n        if(r < 0){\n        \
    \    L[-r - 1] = v;\n        } else{\n            if((int) R.size() == r){\n \
    \               R.push_back(v);\n            } else{\n                R[r] = v;\n\
    \            }\n        }\n        r++;\n    }\n\n    void pop_back(){\n     \
    \   r--;\n    }\n\n    bool empty(){\n        return (r - l + 1) == 0;\n    }\n\
    \n    size_t size(){\n        return (r - l + 1);\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct FastDeque{\n    int l = 1,\
    \ r = 0;\n    vector<T> L, R;\n\n    FastDeque(){}\n\n    T front(){\n       \
    \ if(l <= 0){\n            return L[-l];\n        } else{\n            return\
    \ R[l - 1];\n        }\n    }\n\n    void push_front(int v){\n        l--;\n \
    \       if(l <= 0){\n            if((int) L.size() == -l){\n                L.push_back(v);\n\
    \            } else{\n                L[-l] = v;\n            }\n        } else{\n\
    \            R[l - 1] = v;\n        }\n    }\n\n    void pop_front(){\n      \
    \  l++;\n    }\n\n    T back(){\n        if(r <= 0){\n            return L[-r];\n\
    \        } else{\n            return R[r - 1];\n        }\n    }\n\n    void push_back(int\
    \ v){\n        if(r < 0){\n            L[-r - 1] = v;\n        } else{\n     \
    \       if((int) R.size() == r){\n                R.push_back(v);\n          \
    \  } else{\n                R[r] = v;\n            }\n        }\n        r++;\n\
    \    }\n\n    void pop_back(){\n        r--;\n    }\n\n    bool empty(){\n   \
    \     return (r - l + 1) == 0;\n    }\n\n    size_t size(){\n        return (r\
    \ - l + 1);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/fast_deque.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/fast_deque.hpp
layout: document
redirect_from:
- /library/lib/data_structure/fast_deque.hpp
- /library/lib/data_structure/fast_deque.hpp.html
title: lib/data_structure/fast_deque.hpp
---
