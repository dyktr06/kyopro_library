---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/run_enumerate.hpp
    title: Run Enumerate
  - icon: ':heavy_check_mark:'
    path: lib/string/z_algorithm.hpp
    title: Z Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/runenumerate
    links:
    - https://judge.yosupo.jp/problem/runenumerate
  bundledCode: "#line 1 \"test/library_checker/string/runenumerate.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/runenumerate\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"lib/string/run_enumerate.hpp\"\n\n/**\n * @brief\
    \ Run Enumerate\n * @docs docs/string/run_enumerate.md\n * @see https://pazzle1230.hatenablog.com/entry/2019/11/27/234632\n\
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
    \ l, r);\n    }\n    sort(ans.begin(), ans.end());\n    return ans;\n}\n#line\
    \ 6 \"test/library_checker/string/runenumerate.test.cpp\"\n\nint main(){\n   \
    \ ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    string s; cin >>\
    \ s;\n    auto ans = run_enumerate(s);\n    cout << ans.size() << '\\n';\n   \
    \ for(auto [len, l, r] : ans){\n        cout << len << ' ' << l << ' ' << r <<\
    \ '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/runenumerate\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/string/run_enumerate.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   string s; cin >> s;\n    auto ans = run_enumerate(s);\n    cout << ans.size()\
    \ << '\\n';\n    for(auto [len, l, r] : ans){\n        cout << len << ' ' << l\
    \ << ' ' << r << '\\n';\n    }\n}\n"
  dependsOn:
  - lib/string/run_enumerate.hpp
  - lib/string/z_algorithm.hpp
  isVerificationFile: true
  path: test/library_checker/string/runenumerate.test.cpp
  requiredBy: []
  timestamp: '2024-10-31 22:40:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/string/runenumerate.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/string/runenumerate.test.cpp
- /verify/test/library_checker/string/runenumerate.test.cpp.html
title: test/library_checker/string/runenumerate.test.cpp
---
