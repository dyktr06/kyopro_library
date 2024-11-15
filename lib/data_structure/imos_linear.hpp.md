---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/yuki_1008.test.cpp
    title: test/yukicoder/yuki_1008.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/data_structure/imos_linear.md
    document_title: "Imos Linear (\u9759\u7684\u306A\u4E00\u6B21\u95A2\u6570\u306E\
      \u52A0\u7B97)"
    links: []
  bundledCode: "#line 2 \"lib/data_structure/imos_linear.hpp\"\n\n/**\n * @brief Imos\
    \ Linear (\u9759\u7684\u306A\u4E00\u6B21\u95A2\u6570\u306E\u52A0\u7B97)\n * @docs\
    \ docs/data_structure/imos_linear.md\n */\n\n#include <vector>\n#include <algorithm>\n\
    \ntemplate <typename T>\nstruct imos_linear{\n    int N;\n    std::vector<T> imos1,\
    \ imos0;\n    imos_linear(int N) : N(N){ init(); }\n\n    void init(){\n     \
    \   imos1.resize(N + 1);\n        imos0.resize(N + 1);\n    }\n\n    // [l, r)\
    \ \u306B wX + v \u3092\u52A0\u7B97\n    // imos[l] += v, imos[l + 1] += v + w,\
    \ ...\n    void add(int l, int r, T v, T w){\n        l = std::clamp(l, 0, N),\
    \ r = std::clamp(r, 0, N);\n        imos1[l] += w;\n        imos1[r] -= w;\n \
    \       imos0[l] += v - w;\n        imos0[r] -= v + w * (r - l - 1);\n    }\n\n\
    \    void build(){\n        for(int i = 0; i < N; i++){\n            imos1[i +\
    \ 1] += imos1[i];\n            imos0[i] += imos1[i];\n            imos0[i + 1]\
    \ += imos0[i];\n        }\n    }\n\n    T &operator [](int i){\n        return\
    \ imos0[i];\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Imos Linear (\u9759\u7684\u306A\u4E00\u6B21\
    \u95A2\u6570\u306E\u52A0\u7B97)\n * @docs docs/data_structure/imos_linear.md\n\
    \ */\n\n#include <vector>\n#include <algorithm>\n\ntemplate <typename T>\nstruct\
    \ imos_linear{\n    int N;\n    std::vector<T> imos1, imos0;\n    imos_linear(int\
    \ N) : N(N){ init(); }\n\n    void init(){\n        imos1.resize(N + 1);\n   \
    \     imos0.resize(N + 1);\n    }\n\n    // [l, r) \u306B wX + v \u3092\u52A0\u7B97\
    \n    // imos[l] += v, imos[l + 1] += v + w, ...\n    void add(int l, int r, T\
    \ v, T w){\n        l = std::clamp(l, 0, N), r = std::clamp(r, 0, N);\n      \
    \  imos1[l] += w;\n        imos1[r] -= w;\n        imos0[l] += v - w;\n      \
    \  imos0[r] -= v + w * (r - l - 1);\n    }\n\n    void build(){\n        for(int\
    \ i = 0; i < N; i++){\n            imos1[i + 1] += imos1[i];\n            imos0[i]\
    \ += imos1[i];\n            imos0[i + 1] += imos0[i];\n        }\n    }\n\n  \
    \  T &operator [](int i){\n        return imos0[i];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/imos_linear.hpp
  requiredBy: []
  timestamp: '2024-11-15 16:27:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/yuki_1008.test.cpp
documentation_of: lib/data_structure/imos_linear.hpp
layout: document
redirect_from:
- /library/lib/data_structure/imos_linear.hpp
- /library/lib/data_structure/imos_linear.hpp.html
title: "Imos Linear (\u9759\u7684\u306A\u4E00\u6B21\u95A2\u6570\u306E\u52A0\u7B97)"
---
## Imos Linear

#### 使い方

- `imos_linear(N)`: コンストラクタ (N は要素数)
- `add(l, r, w, t)`: [l, r) に wX + v を加算します。
- `build()`: 加算された配列を構築します。

#### 計算量

- `imos_linear(N)`: $\mathrm{O}(N)$
- `add(l, r, w, t)`: $\mathrm{O}(1)$
- `build()`: $\mathrm{O}(N)$
