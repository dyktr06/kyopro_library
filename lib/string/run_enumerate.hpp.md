---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/z_algorithm.hpp
    title: Z Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/runenumerate.test.cpp
    title: test/library_checker/string/runenumerate.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/run_enumerate.md
    document_title: Run Enumerate
    links:
    - https://pazzle1230.hatenablog.com/entry/2019/11/27/234632
  bundledCode: "#line 2 \"lib/string/run_enumerate.hpp\"\n\n/**\n * @brief Run Enumerate\n\
    \ * @docs docs/string/run_enumerate.md\n * @see https://pazzle1230.hatenablog.com/entry/2019/11/27/234632\n\
    \ */\n\n#line 2 \"lib/string/z_algorithm.hpp\"\n\n/**\n * @brief Z Algorithm\n\
    \ * @docs docs/string/z_algorithm.md\n */\n\ntemplate <typename T>\nvector<int>\
    \ z_algorithm(const T &s) {\n    int n = s.size();\n    vector<int> res(n, 0);\n\
    \    for(int i = 1, j = 0; i < n; ++i){\n        if(i + res[i - j] < j + res[j]){\n\
    \            res[i] = res[i - j];\n        } else{\n            res[i] = max(j\
    \ + res[j] - i, 0);\n            while(i + res[i] < n && s[i + res[i]] == s[res[i]])\
    \ ++res[i];\n            j = i;\n        }\n    }\n    res[0] = n;\n    return\
    \ res;\n}\n#line 10 \"lib/string/run_enumerate.hpp\"\n\nvector<tuple<int, int,\
    \ int>> run_enumerate(const string &s){\n    int n = s.size();\n    vector<tuple<int,\
    \ int, int>> res;\n    auto dfs = [&](auto &self, int l, int r) -> void {\n  \
    \      if(r - l < 2){\n            return;\n        }\n        int mid = (l +\
    \ r) / 2;\n        self(self, l, mid);\n        self(self, mid, r);\n\n      \
    \  string ns = s.substr(l, r - l);\n        int lenl = mid - l, lenr = r - mid;\n\
    \        string sl = s.substr(l, lenl);\n        reverse(sl.begin(), sl.end());\n\
    \        string sr = s.substr(mid, lenr);\n        sr += ns;\n        reverse(ns.begin(),\
    \ ns.end());\n        sl += ns;\n        auto zl = z_algorithm(sl);\n        auto\
    \ zr = z_algorithm(sr);\n        {\n            for(int i = l; i < mid; i++){\n\
    \                // [i, mid) \u3092\u5468\u671F\n                int len = mid\
    \ - i;\n                int nl = i, nr = mid;\n                if(i > l) nl =\
    \ max(l, nl - zl[len]);\n                nr = min(r, nr + zr[lenr + (i - l)]);\n\
    \                if(nr - nl >= len * 2){\n                    if(nl >= 1 && s[nl\
    \ - 1] == s[nl - 1 + len]){\n                        continue;\n             \
    \       }\n                    if(nr < n && s[nr] == s[nr - len]){\n         \
    \               continue;\n                    }\n                    res.emplace_back(nl,\
    \ nr, len);\n                }\n            }\n        }\n        {\n        \
    \    for(int i = mid + 1; i <= r; i++){\n                // [mid, i) \u3092\u5468\
    \u671F\n                int len = i - mid;\n                int nl = mid, nr =\
    \ i;\n                if(i < r) nr = min(r, nr + zr[len]);\n                nl\
    \ = max(l, nl - zl[lenl + (r - i)]);\n                if(nr - nl >= len * 2){\n\
    \                    if(nl >= 1 && s[nl - 1] == s[nl - 1 + len]){\n          \
    \              continue;\n                    }\n                    if(nr < n\
    \ && s[nr] == s[nr - len]){\n                        continue;\n             \
    \       }\n                    res.emplace_back(nl, nr, len);\n              \
    \  }\n            }\n        }\n    };\n    dfs(dfs, 0, n);\n    sort(res.begin(),\
    \ res.end());\n    vector<tuple<int, int, int>> ans;\n    int pl = -1, pr = -1;\n\
    \    for(auto [l, r, len] : res){\n        if(l == pl && r == pr){\n         \
    \   continue;\n        }\n        pl = l, pr = r;\n        ans.emplace_back(len,\
    \ l, r);\n    }\n    sort(ans.begin(), ans.end());\n    return ans;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Run Enumerate\n * @docs docs/string/run_enumerate.md\n\
    \ * @see https://pazzle1230.hatenablog.com/entry/2019/11/27/234632\n */\n\n#include\
    \ \"z_algorithm.hpp\"\n\nvector<tuple<int, int, int>> run_enumerate(const string\
    \ &s){\n    int n = s.size();\n    vector<tuple<int, int, int>> res;\n    auto\
    \ dfs = [&](auto &self, int l, int r) -> void {\n        if(r - l < 2){\n    \
    \        return;\n        }\n        int mid = (l + r) / 2;\n        self(self,\
    \ l, mid);\n        self(self, mid, r);\n\n        string ns = s.substr(l, r -\
    \ l);\n        int lenl = mid - l, lenr = r - mid;\n        string sl = s.substr(l,\
    \ lenl);\n        reverse(sl.begin(), sl.end());\n        string sr = s.substr(mid,\
    \ lenr);\n        sr += ns;\n        reverse(ns.begin(), ns.end());\n        sl\
    \ += ns;\n        auto zl = z_algorithm(sl);\n        auto zr = z_algorithm(sr);\n\
    \        {\n            for(int i = l; i < mid; i++){\n                // [i,\
    \ mid) \u3092\u5468\u671F\n                int len = mid - i;\n              \
    \  int nl = i, nr = mid;\n                if(i > l) nl = max(l, nl - zl[len]);\n\
    \                nr = min(r, nr + zr[lenr + (i - l)]);\n                if(nr\
    \ - nl >= len * 2){\n                    if(nl >= 1 && s[nl - 1] == s[nl - 1 +\
    \ len]){\n                        continue;\n                    }\n         \
    \           if(nr < n && s[nr] == s[nr - len]){\n                        continue;\n\
    \                    }\n                    res.emplace_back(nl, nr, len);\n \
    \               }\n            }\n        }\n        {\n            for(int i\
    \ = mid + 1; i <= r; i++){\n                // [mid, i) \u3092\u5468\u671F\n \
    \               int len = i - mid;\n                int nl = mid, nr = i;\n  \
    \              if(i < r) nr = min(r, nr + zr[len]);\n                nl = max(l,\
    \ nl - zl[lenl + (r - i)]);\n                if(nr - nl >= len * 2){\n       \
    \             if(nl >= 1 && s[nl - 1] == s[nl - 1 + len]){\n                 \
    \       continue;\n                    }\n                    if(nr < n && s[nr]\
    \ == s[nr - len]){\n                        continue;\n                    }\n\
    \                    res.emplace_back(nl, nr, len);\n                }\n     \
    \       }\n        }\n    };\n    dfs(dfs, 0, n);\n    sort(res.begin(), res.end());\n\
    \    vector<tuple<int, int, int>> ans;\n    int pl = -1, pr = -1;\n    for(auto\
    \ [l, r, len] : res){\n        if(l == pl && r == pr){\n            continue;\n\
    \        }\n        pl = l, pr = r;\n        ans.emplace_back(len, l, r);\n  \
    \  }\n    sort(ans.begin(), ans.end());\n    return ans;\n}\n"
  dependsOn:
  - lib/string/z_algorithm.hpp
  isVerificationFile: false
  path: lib/string/run_enumerate.hpp
  requiredBy: []
  timestamp: '2024-10-31 22:40:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/runenumerate.test.cpp
documentation_of: lib/string/run_enumerate.hpp
layout: document
redirect_from:
- /library/lib/string/run_enumerate.hpp
- /library/lib/string/run_enumerate.hpp.html
title: Run Enumerate
---
## Run Enumerate

#### 概要

文字列 $S$ について、Run の列挙を行います。

#### 計算量

$\mathrm{O}(\lvert S\lvert \log \lvert S\lvert)$
