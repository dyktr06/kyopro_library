---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/data_structure/mo.hpp
    title: lib/data_structure/mo.hpp
  - icon: ':question:'
    path: lib/others/compression.hpp
    title: "Compression (\u5EA7\u6A19\u5727\u7E2E)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_count_distinct
    links:
    - https://judge.yosupo.jp/problem/static_range_count_distinct
  bundledCode: "#line 1 \"test/library_checker/data_structure/static_range_count_distinct.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_count_distinct\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/mo.hpp\"\
    \n\n// [0 , N) \u4E0A\u306E\u533A\u9593\u306B\u5BFE\u3059\u308B Q \u500B\u306E\
    \u30AF\u30A8\u30EA\u3092\u8A08\u7B97\u3057\u307E\u3059\u3002 : O(N\u221AQ) (\u533A\
    \u9593\u306E\u4F38\u7E2E\u304C O(1) \u3067\u884C\u3048\u308B\u5834\u5408)\nstruct\
    \ Mo{\n    int n;\n    vector<pair<int, int>> lr;\n\n    Mo(const int n) : n(n)\
    \ {}\n\n    /* [l, r) */\n    void add(const int l, const int r){\n        lr.emplace_back(l,\
    \ r);\n    }\n\n    template <typename AL, typename AR, typename EL, typename\
    \ ER, typename O>\n    void build(const AL &add_left, const AR &add_right, const\
    \ EL &erase_left, const ER &erase_right, const O &out){\n        int q = (int)\
    \ lr.size();\n        int border = max<int>(1, 1.0 * n / max<double>(1.0, sqrt(q\
    \ * 2.0 / 3.0)));\n        vector<int> ord(q);\n        iota(ord.begin(), ord.end(),\
    \ 0);\n        sort(ord.begin(), ord.end(), [&](int a, int b){\n            int\
    \ ablock = lr[a].first / border, bblock = lr[b].first / border;\n            if(ablock\
    \ != bblock){\n                return ablock < bblock;\n            }\n      \
    \      return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;\n\
    \        });\n        int l = 0, r = 0;\n        for(const auto &k : ord){\n \
    \           while(l > lr[k].first) add_left(--l);\n            while(r < lr[k].second)\
    \ add_right(r++);\n            while(l < lr[k].first) erase_left(l++);\n     \
    \       while(r > lr[k].second) erase_right(--r);\n            out(k);\n     \
    \   }\n    }\n\n    template <typename A, typename E, typename O>\n    void build(const\
    \ A &add, const E &erase, const O &out){\n        build(add, add, erase, erase,\
    \ out);\n    }\n};\n#line 2 \"lib/others/compression.hpp\"\n\n/**\n * @brief Compression\
    \ (\u5EA7\u6A19\u5727\u7E2E)\n * @docs docs/others/compression.md\n */\n\n#line\
    \ 10 \"lib/others/compression.hpp\"\n\ntemplate <typename T>\nstruct compress{\n\
    \    std::vector<T> sorted;\n    std::vector<int> compressed;\n\n    compress(const\
    \ std::vector<T> &vec){\n        int n = vec.size();\n        compressed.resize(n);\n\
    \        for(T x : vec){\n            sorted.emplace_back(x);\n        }\n   \
    \     std::sort(sorted.begin(), sorted.end());\n        sorted.erase(std::unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n        for(int i = 0; i < n; ++i){\n       \
    \     compressed[i] = std::lower_bound(sorted.begin(), sorted.end(), vec[i]) -\
    \ sorted.begin();\n        }\n    }\n\n    int get(const T &x) const{\n      \
    \  return std::lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();\n\
    \    }\n\n    T inv(const int x) const{\n        return sorted[x];\n    }\n\n\
    \    size_t size() const{\n        return sorted.size();\n    }\n\n    std::vector<T>\
    \ getCompressed() const{\n        return compressed;\n    }\n};\n#line 7 \"test/library_checker/data_structure/static_range_count_distinct.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n \
    \   int n, q; cin >> n >> q;\n    vector<int> a;\n    vector<int> c(n);\n    for(int\
    \ i = 0; i < n; i++){\n        cin >> c[i];\n        a.push_back(c[i]);\n    }\n\
    \    Mo mo(n);\n    for(int i = 0; i < q; i++){\n        int l, r; cin >> l >>\
    \ r;\n        mo.add(l, r);\n    }\n    compress<int> comp(a);\n    vector<int>\
    \ compressed = comp.getCompressed();\n    vector<int> cnt(n);\n    vector<int>\
    \ res(q);\n\n    int now_cnt = 0;\n    auto add = [&](int i){\n        if(++cnt[compressed[i]]\
    \ == 1){\n            now_cnt++;\n        }\n    };\n    auto erase = [&](int\
    \ i){\n        if(--cnt[compressed[i]] == 0){\n            now_cnt--;\n      \
    \  }\n    };\n    auto output = [&](int q){\n        res[q] = now_cnt;\n    };\n\
    \    mo.build(add, erase, output);\n \n    for(auto ans : res){\n        cout\
    \ << ans << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_count_distinct\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/mo.hpp\"\
    \n#include \"../../../lib/others/compression.hpp\"\n\nint main(){\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int n, q; cin >> n >> q;\n    vector<int>\
    \ a;\n    vector<int> c(n);\n    for(int i = 0; i < n; i++){\n        cin >> c[i];\n\
    \        a.push_back(c[i]);\n    }\n    Mo mo(n);\n    for(int i = 0; i < q; i++){\n\
    \        int l, r; cin >> l >> r;\n        mo.add(l, r);\n    }\n    compress<int>\
    \ comp(a);\n    vector<int> compressed = comp.getCompressed();\n    vector<int>\
    \ cnt(n);\n    vector<int> res(q);\n\n    int now_cnt = 0;\n    auto add = [&](int\
    \ i){\n        if(++cnt[compressed[i]] == 1){\n            now_cnt++;\n      \
    \  }\n    };\n    auto erase = [&](int i){\n        if(--cnt[compressed[i]] ==\
    \ 0){\n            now_cnt--;\n        }\n    };\n    auto output = [&](int q){\n\
    \        res[q] = now_cnt;\n    };\n    mo.build(add, erase, output);\n \n   \
    \ for(auto ans : res){\n        cout << ans << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/data_structure/mo.hpp
  - lib/others/compression.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/static_range_count_distinct.test.cpp
  requiredBy: []
  timestamp: '2024-11-13 13:43:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/static_range_count_distinct.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/static_range_count_distinct.test.cpp
- /verify/test/library_checker/data_structure/static_range_count_distinct.test.cpp.html
title: test/library_checker/data_structure/static_range_count_distinct.test.cpp
---
