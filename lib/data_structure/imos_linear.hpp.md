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
    \ imos0[i];\n    }\n};\n\ntemplate <class T, class Index = long long>\nstruct\
    \ StaticImosLinear {\nprivate:\n    struct Event {\n        Index x;\n       \
    \ T da;\n        T db;\n    };\n\n    Index N;\n    std::vector<Event> events;\n\
    \n    Index clamp_index(Index x) const {\n        return std::clamp(x, Index(0),\
    \ N);\n    }\n\npublic:\n    explicit StaticImosLinear(Index n) : N(n) {}\n\n\
    \    // [l, r) \u306B wX + v \u3092\u52A0\u7B97\n    // imos[l] += v, imos[l +\
    \ 1] += v + w, ...\n    void add(Index l, Index r, T v, T w) {\n        l = clamp_index(l);\n\
    \        r = clamp_index(r);\n\n        if (l >= r) {\n            return;\n \
    \       }\n\n        // v + w(x-l) = wx + (v-wl)\n        const T a = w;\n   \
    \     const T b = v - w * T(l);\n\n        events.push_back({l, a, b});\n    \
    \    events.push_back({r, -a, -b});\n    }\n\n    // [l, r) \u306B wX + v \u3092\
    \u52A0\u7B97\n    // imos[l] += wl + v, imos[l + 1] += w(l + 1) + v, ...\n   \
    \ void add_absolute(Index l, Index r, T v, T w) {\n        l = clamp_index(l);\n\
    \        r = clamp_index(r);\n\n        if (l >= r) {\n            return;\n \
    \       }\n\n        events.push_back({l, w, v});\n        events.push_back({r,\
    \ -w, -v});\n    }\n\n    std::vector<T> build(const std::vector<Index>& query)\
    \ const {\n        std::vector<Event> sorted_events = events;\n\n        std::sort(\n\
    \            sorted_events.begin(),\n            sorted_events.end(),\n      \
    \      [](const Event& lhs, const Event& rhs) {\n                return lhs.x\
    \ < rhs.x;\n            }\n        );\n\n        std::vector<int> order(query.size());\n\
    \        std::iota(order.begin(), order.end(), 0);\n\n        std::sort(\n   \
    \         order.begin(),\n            order.end(),\n            [&](int lhs, int\
    \ rhs) {\n                return query[lhs] < query[rhs];\n            }\n   \
    \     );\n\n        std::vector<T> answer(query.size(), T{});\n\n        T a{};\n\
    \        T b{};\n        std::size_t event_index = 0;\n\n        for (int query_index\
    \ : order) {\n            const Index x = query[query_index];\n            while\
    \ (\n                event_index < sorted_events.size() &&\n                sorted_events[event_index].x\
    \ <= x\n            ) {\n                a += sorted_events[event_index].da;\n\
    \                b += sorted_events[event_index].db;\n                ++event_index;\n\
    \            }\n\n            answer[query_index] = a * T(x) + b;\n        }\n\
    \        return answer;\n    }\n};\n"
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
    \  T &operator [](int i){\n        return imos0[i];\n    }\n};\n\ntemplate <class\
    \ T, class Index = long long>\nstruct StaticImosLinear {\nprivate:\n    struct\
    \ Event {\n        Index x;\n        T da;\n        T db;\n    };\n\n    Index\
    \ N;\n    std::vector<Event> events;\n\n    Index clamp_index(Index x) const {\n\
    \        return std::clamp(x, Index(0), N);\n    }\n\npublic:\n    explicit StaticImosLinear(Index\
    \ n) : N(n) {}\n\n    // [l, r) \u306B wX + v \u3092\u52A0\u7B97\n    // imos[l]\
    \ += v, imos[l + 1] += v + w, ...\n    void add(Index l, Index r, T v, T w) {\n\
    \        l = clamp_index(l);\n        r = clamp_index(r);\n\n        if (l >=\
    \ r) {\n            return;\n        }\n\n        // v + w(x-l) = wx + (v-wl)\n\
    \        const T a = w;\n        const T b = v - w * T(l);\n\n        events.push_back({l,\
    \ a, b});\n        events.push_back({r, -a, -b});\n    }\n\n    // [l, r) \u306B\
    \ wX + v \u3092\u52A0\u7B97\n    // imos[l] += wl + v, imos[l + 1] += w(l + 1)\
    \ + v, ...\n    void add_absolute(Index l, Index r, T v, T w) {\n        l = clamp_index(l);\n\
    \        r = clamp_index(r);\n\n        if (l >= r) {\n            return;\n \
    \       }\n\n        events.push_back({l, w, v});\n        events.push_back({r,\
    \ -w, -v});\n    }\n\n    std::vector<T> build(const std::vector<Index>& query)\
    \ const {\n        std::vector<Event> sorted_events = events;\n\n        std::sort(\n\
    \            sorted_events.begin(),\n            sorted_events.end(),\n      \
    \      [](const Event& lhs, const Event& rhs) {\n                return lhs.x\
    \ < rhs.x;\n            }\n        );\n\n        std::vector<int> order(query.size());\n\
    \        std::iota(order.begin(), order.end(), 0);\n\n        std::sort(\n   \
    \         order.begin(),\n            order.end(),\n            [&](int lhs, int\
    \ rhs) {\n                return query[lhs] < query[rhs];\n            }\n   \
    \     );\n\n        std::vector<T> answer(query.size(), T{});\n\n        T a{};\n\
    \        T b{};\n        std::size_t event_index = 0;\n\n        for (int query_index\
    \ : order) {\n            const Index x = query[query_index];\n            while\
    \ (\n                event_index < sorted_events.size() &&\n                sorted_events[event_index].x\
    \ <= x\n            ) {\n                a += sorted_events[event_index].da;\n\
    \                b += sorted_events[event_index].db;\n                ++event_index;\n\
    \            }\n\n            answer[query_index] = a * T(x) + b;\n        }\n\
    \        return answer;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/imos_linear.hpp
  requiredBy: []
  timestamp: '2026-09-23 21:32:55+09:00'
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
