---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/point_add_rectangle_sum.test.cpp
    title: test/library_checker/data_structure/point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/range_kth_smallest.test.cpp
    title: test/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/static_range_frequency.test.cpp
    title: test/library_checker/data_structure/static_range_frequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/static_range_inversions_query.test.cpp
    title: test/library_checker/data_structure/static_range_inversions_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/others/compression.hpp\"\n\n/* \n    compress<T>(vec)\
    \ : vec \u3092\u5EA7\u6A19\u5727\u7E2E\u3057\u307E\u3059\u3002O(NlogN)\n    get(x)\
    \ : x \u306E\u5EA7\u6A19\u5727\u7E2E\u5F8C\u306E\u5024\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002O(log(n))\n    getCompressed() : \u5EA7\u6A19\u5727\u7E2E\u5F8C\
    \u306E\u914D\u5217\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002 O(n)\n*/\n\ntemplate\
    \ <typename T>\nstruct compress{\n    vector<T> sorted, compressed;\n\n    compress(const\
    \ vector<T>& vec){\n        int n = vec.size();\n        compressed.resize(n);\n\
    \        for(T x : vec){\n            sorted.push_back(x);\n        }\n      \
    \  sort(sorted.begin(), sorted.end());\n        sorted.erase(unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n        for(int i = 0; i < n; i++){\n       \
    \     compressed[i] = lower_bound(sorted.begin(), sorted.end(), vec[i]) - sorted.begin();\n\
    \        }\n    }\n\n    int get(const T& x) const{\n        return lower_bound(sorted.begin(),\
    \ sorted.end(), x) - sorted.begin();\n    }\n\n    size_t size() const{\n    \
    \    return sorted.size();\n    }\n\n    vector<T> getCompressed() const{\n  \
    \      return compressed;\n    }\n};\n"
  code: "#pragma once\n\n/* \n    compress<T>(vec) : vec \u3092\u5EA7\u6A19\u5727\u7E2E\
    \u3057\u307E\u3059\u3002O(NlogN)\n    get(x) : x \u306E\u5EA7\u6A19\u5727\u7E2E\
    \u5F8C\u306E\u5024\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002O(log(n))\n    getCompressed()\
    \ : \u5EA7\u6A19\u5727\u7E2E\u5F8C\u306E\u914D\u5217\u3092\u53D6\u5F97\u3057\u307E\
    \u3059\u3002 O(n)\n*/\n\ntemplate <typename T>\nstruct compress{\n    vector<T>\
    \ sorted, compressed;\n\n    compress(const vector<T>& vec){\n        int n =\
    \ vec.size();\n        compressed.resize(n);\n        for(T x : vec){\n      \
    \      sorted.push_back(x);\n        }\n        sort(sorted.begin(), sorted.end());\n\
    \        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());\n \
    \       for(int i = 0; i < n; i++){\n            compressed[i] = lower_bound(sorted.begin(),\
    \ sorted.end(), vec[i]) - sorted.begin();\n        }\n    }\n\n    int get(const\
    \ T& x) const{\n        return lower_bound(sorted.begin(), sorted.end(), x) -\
    \ sorted.begin();\n    }\n\n    size_t size() const{\n        return sorted.size();\n\
    \    }\n\n    vector<T> getCompressed() const{\n        return compressed;\n \
    \   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/compression.hpp
  requiredBy: []
  timestamp: '2022-11-10 02:54:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/point_add_rectangle_sum.test.cpp
  - test/library_checker/data_structure/range_kth_smallest.test.cpp
  - test/library_checker/data_structure/static_range_inversions_query.test.cpp
  - test/library_checker/data_structure/static_range_frequency.test.cpp
documentation_of: lib/others/compression.hpp
layout: document
redirect_from:
- /library/lib/others/compression.hpp
- /library/lib/others/compression.hpp.html
title: lib/others/compression.hpp
---
