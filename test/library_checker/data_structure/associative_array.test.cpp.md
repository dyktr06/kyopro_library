---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/others/compression.hpp
    title: "Compression (\u5EA7\u6A19\u5727\u7E2E)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"test/library_checker/data_structure/associative_array.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/others/compression.hpp\"\
    \n\n/**\n * @brief Compression (\u5EA7\u6A19\u5727\u7E2E)\n * @docs docs/others/compression.md\n\
    \ */\n\n#line 10 \"lib/others/compression.hpp\"\n\ntemplate <typename T>\nstruct\
    \ compress{\n    std::vector<T> sorted;\n    std::vector<int> compressed;\n\n\
    \    compress(const std::vector<T> &vec){\n        int n = vec.size();\n     \
    \   compressed.resize(n);\n        for(T x : vec){\n            sorted.emplace_back(x);\n\
    \        }\n        std::sort(sorted.begin(), sorted.end());\n        sorted.erase(std::unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n        for(int i = 0; i < n; ++i){\n       \
    \     compressed[i] = std::lower_bound(sorted.begin(), sorted.end(), vec[i]) -\
    \ sorted.begin();\n        }\n    }\n\n    int get(const T &x) const{\n      \
    \  return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();\n   \
    \ }\n\n    T inv(const int x) const{\n        return sorted[x];\n    }\n\n   \
    \ size_t size() const{\n        return sorted.size();\n    }\n\n    std::vector<T>\
    \ getCompressed() const{\n        return compressed;\n    }\n};\n#line 6 \"test/library_checker/data_structure/associative_array.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int q; cin >> q;\n    using T = tuple<int, long long, long long>;\n    vector<T>\
    \ query(q);\n    vector<long long> x(q);\n    for(int i = 0; i < q; i++){\n  \
    \      int t; cin >> t;\n        long long k = -1, v = -1;\n        if(t == 0){\n\
    \            cin >> k >> v;\n        }else{\n            cin >> k;\n        }\n\
    \        query[i] = {t, k, v};\n        x[i] = k;\n    }\n    compress<long long>\
    \ cp(x);\n    vector<long long> a(cp.size(), 0);\n    for(int i = 0; i < q; i++){\n\
    \        auto [t, k, v] = query[i];\n        if(t == 0){\n            a[cp.get(k)]\
    \ = v;\n        }else{\n            cout << a[cp.get(k)] << \"\\n\";\n       \
    \ }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/others/compression.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int q; cin >> q;\n    using T = tuple<int, long long, long long>;\n    vector<T>\
    \ query(q);\n    vector<long long> x(q);\n    for(int i = 0; i < q; i++){\n  \
    \      int t; cin >> t;\n        long long k = -1, v = -1;\n        if(t == 0){\n\
    \            cin >> k >> v;\n        }else{\n            cin >> k;\n        }\n\
    \        query[i] = {t, k, v};\n        x[i] = k;\n    }\n    compress<long long>\
    \ cp(x);\n    vector<long long> a(cp.size(), 0);\n    for(int i = 0; i < q; i++){\n\
    \        auto [t, k, v] = query[i];\n        if(t == 0){\n            a[cp.get(k)]\
    \ = v;\n        }else{\n            cout << a[cp.get(k)] << \"\\n\";\n       \
    \ }\n    }\n}\n"
  dependsOn:
  - lib/others/compression.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/associative_array.test.cpp
  requiredBy: []
  timestamp: '2024-11-12 11:47:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/associative_array.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/associative_array.test.cpp
- /verify/test/library_checker/data_structure/associative_array.test.cpp.html
title: test/library_checker/data_structure/associative_array.test.cpp
---
