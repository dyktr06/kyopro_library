---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/disjoint_sparse_table.hpp
    title: lib/data_structure/disjoint_sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/library_checker/data_structure/static_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/disjoint_sparse_table.hpp\"\
    \n\ntemplate <typename T, T (*op)(T, T)>\nstruct DisjointSparseTable{\n    int\
    \ n, log2;\n    std::vector<std::vector<T>> table;\n    std::vector<T> val;\n\
    \    DisjointSparseTable(std::vector<T> &a) : val(a) {\n        int len = a.size();\n\
    \        n = 1, log2 = 0;\n        while(n < len){\n            n *= 2;\n    \
    \        log2++;\n        }\n        val.resize(n);\n        table = std::vector<std::vector<T>>(log2,\
    \ std::vector<T>(n));\n        init();\n    }\n\n    void init(){\n        for(int\
    \ i = 0; i < log2; i++){\n            for(int j = 0; j < n; j += (n >> i)){\n\
    \                int h = n >> (i + 1);\n                // h \u3092\u4E2D\u5FC3\
    \u306B\u5DE6\u53F3\u306B\u7D2F\u7A4D\u3057\u305F\u5024\u3092\u8A08\u7B97\n   \
    \             table[i][j + h] = val[j + h];\n                for(int k = j + h\
    \ + 1; k < j + h * 2; k++){\n                    table[i][k] = op(table[i][k -\
    \ 1], val[k]);\n                }\n                table[i][j + h - 1] = val[j\
    \ + h - 1];\n                for(int k = j + h - 2; k >= j; k--){\n          \
    \          table[i][k] = op(table[i][k + 1], val[k]);\n                }\n   \
    \         }\n        }\n    }\n\n    // [l, r]\n    T query(int l, int r){\n \
    \       if(l == r){\n            return val[l];\n        }\n        // \u307E\u305F\
    \u3050\u5834\u6240\u306E\u8A08\u7B97\n        int d = __builtin_clz(l ^ r) - (32\
    \ - log2);\n        return op(table[d][l], table[d][r]);\n    }\n};\n#line 6 \"\
    test/library_checker/data_structure/static_range_sum.test.cpp\"\n\nlong long op(long\
    \ long x, long long y){\n    return x + y;\n}\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int n, q; cin >> n >> q;\n    vector<long long>\
    \ a(n);\n    for(int i = 0; i < n; i++){\n        cin >> a[i];\n    }\n    DisjointSparseTable<long\
    \ long, op> dst(a);\n    for(int i = 0; i < q; i++){\n        int l, r; cin >>\
    \ l >> r;\n        cout << dst.query(l, r - 1) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/disjoint_sparse_table.hpp\"\
    \n\nlong long op(long long x, long long y){\n    return x + y;\n}\n\nint main(){\n\
    \    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int n, q; cin\
    \ >> n >> q;\n    vector<long long> a(n);\n    for(int i = 0; i < n; i++){\n \
    \       cin >> a[i];\n    }\n    DisjointSparseTable<long long, op> dst(a);\n\
    \    for(int i = 0; i < q; i++){\n        int l, r; cin >> l >> r;\n        cout\
    \ << dst.query(l, r - 1) << '\\n';\n    }\n}\n"
  dependsOn:
  - lib/data_structure/disjoint_sparse_table.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-10-24 03:27:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/static_range_sum.test.cpp
- /verify/test/library_checker/data_structure/static_range_sum.test.cpp.html
title: test/library_checker/data_structure/static_range_sum.test.cpp
---
