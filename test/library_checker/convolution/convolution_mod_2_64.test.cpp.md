---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/convolution/karatsuba_algorithm.hpp
    title: Karatsuba Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_2_64
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_2_64
  bundledCode: "#line 1 \"test/library_checker/convolution/convolution_mod_2_64.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_2_64\"\n#include\
    \ <iostream>\n#include <vector>\n\n#line 2 \"lib/convolution/karatsuba_algorithm.hpp\"\
    \n\n/**\n * @brief Karatsuba Algorithm\n */\n\n#line 8 \"lib/convolution/karatsuba_algorithm.hpp\"\
    \n#include <cassert>\n\ntemplate <typename T>\nstd::vector<T> karatsuba_algorithm(std::vector<T>\
    \ &a, std::vector<T> &b){\n    const int n = (int) a.size();\n    const int h\
    \ = n >> 1;\n    assert(a.size() == b.size());\n    assert((n & (n - 1)) == 0);\n\
    \    if(n <= 64){\n        std::vector<T> res(2 * n - 1);\n        for(int i =\
    \ 0; i < n; ++i){\n            for(int j = 0; j < n; ++j){\n                res[i\
    \ + j] += a[i] * b[j];\n            }\n        }\n        return res;\n    }\n\
    \    std::vector<T> p(h), q(h), r(h), s(h), t(h), u(h);\n    for(int i = 0; i\
    \ < h; ++i){\n        p[i] = a[i + h];\n        q[i] = a[i];\n        r[i] = b[i\
    \ + h];\n        s[i] = b[i];\n        t[i] = p[i] + q[i];\n        u[i] = r[i]\
    \ + s[i];\n    }\n    p = karatsuba_algorithm(p, r);\n    q = karatsuba_algorithm(q,\
    \ s);\n    t = karatsuba_algorithm(t, u);\n    std::vector<T> res(2 * n - 1, 0);\n\
    \    for(int i = 0; i < n - 1; ++i){\n        res[i] += q[i];\n        res[i +\
    \ h] += t[i] - p[i] - q[i];\n        res[i + n] += p[i];\n    }\n    return res;\n\
    }\n#line 6 \"test/library_checker/convolution/convolution_mod_2_64.test.cpp\"\n\
    \nusing namespace std;\n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int n, m; cin >> n >> m;\n    vector<unsigned long long> a(n), b(m);\n \
    \   for(int i = 0; i < n; i++){\n        cin >> a[i];\n    }\n    for(int i =\
    \ 0; i < m; i++){\n        cin >> b[i];\n    }\n    int k = 1;\n    while(k <\
    \ max(n, m)){\n        k *= 2;\n    }\n    a.resize(k), b.resize(k);\n    vector<unsigned\
    \ long long> c = karatsuba_algorithm(a, b);\n    for(int i = 0; i < n + m - 1;\
    \ i++){\n        cout << c[i] << \" \\n\"[i == n + m - 1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_2_64\"\n\
    #include <iostream>\n#include <vector>\n\n#include \"../../../lib/convolution/karatsuba_algorithm.hpp\"\
    \n\nusing namespace std;\n\nint main(){\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n\n    int n, m; cin >> n >> m;\n    vector<unsigned long\
    \ long> a(n), b(m);\n    for(int i = 0; i < n; i++){\n        cin >> a[i];\n \
    \   }\n    for(int i = 0; i < m; i++){\n        cin >> b[i];\n    }\n    int k\
    \ = 1;\n    while(k < max(n, m)){\n        k *= 2;\n    }\n    a.resize(k), b.resize(k);\n\
    \    vector<unsigned long long> c = karatsuba_algorithm(a, b);\n    for(int i\
    \ = 0; i < n + m - 1; i++){\n        cout << c[i] << \" \\n\"[i == n + m - 1];\n\
    \    }\n}\n"
  dependsOn:
  - lib/convolution/karatsuba_algorithm.hpp
  isVerificationFile: true
  path: test/library_checker/convolution/convolution_mod_2_64.test.cpp
  requiredBy: []
  timestamp: '2024-11-13 13:43:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/convolution/convolution_mod_2_64.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/convolution/convolution_mod_2_64.test.cpp
- /verify/test/library_checker/convolution/convolution_mod_2_64.test.cpp.html
title: test/library_checker/convolution/convolution_mod_2_64.test.cpp
---
