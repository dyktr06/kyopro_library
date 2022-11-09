---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/others/compression.cpp\"\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n// \u5EA7\u6A19\u5727\u7E2E\u3057\u305F\u914D\u5217\u3092\
    \u8FD4\u3057\u307E\u3059(0-indexed) : O(NlogN)\ntemplate <typename T>\nT compression(T\
    \ vec){\n    int n = vec.size();\n    T tmp = vec;\n    sort(tmp.begin(), tmp.end());\n\
    \    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());\n    T res(n);\n  \
    \  for(int i = 0; i < n; i++){\n        res[i] = lower_bound(tmp.begin(), tmp.end(),\
    \ vec[i]) - tmp.begin();\n    }\n    return res;\n}\n\n/* \n    compress<T>(vec)\
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
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// \u5EA7\u6A19\u5727\
    \u7E2E\u3057\u305F\u914D\u5217\u3092\u8FD4\u3057\u307E\u3059(0-indexed) : O(NlogN)\n\
    template <typename T>\nT compression(T vec){\n    int n = vec.size();\n    T tmp\
    \ = vec;\n    sort(tmp.begin(), tmp.end());\n    tmp.erase(unique(tmp.begin(),\
    \ tmp.end()), tmp.end());\n    T res(n);\n    for(int i = 0; i < n; i++){\n  \
    \      res[i] = lower_bound(tmp.begin(), tmp.end(), vec[i]) - tmp.begin();\n \
    \   }\n    return res;\n}\n\n/* \n    compress<T>(vec) : vec \u3092\u5EA7\u6A19\
    \u5727\u7E2E\u3057\u307E\u3059\u3002O(NlogN)\n    get(x) : x \u306E\u5EA7\u6A19\
    \u5727\u7E2E\u5F8C\u306E\u5024\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002O(log(n))\n\
    \    getCompressed() : \u5EA7\u6A19\u5727\u7E2E\u5F8C\u306E\u914D\u5217\u3092\u53D6\
    \u5F97\u3057\u307E\u3059\u3002 O(n)\n*/\n\ntemplate <typename T>\nstruct compress{\n\
    \    vector<T> sorted, compressed;\n\n    compress(const vector<T>& vec){\n  \
    \      int n = vec.size();\n        compressed.resize(n);\n        for(T x : vec){\n\
    \            sorted.push_back(x);\n        }\n        sort(sorted.begin(), sorted.end());\n\
    \        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());\n \
    \       for(int i = 0; i < n; i++){\n            compressed[i] = lower_bound(sorted.begin(),\
    \ sorted.end(), vec[i]) - sorted.begin();\n        }\n    }\n\n    int get(const\
    \ T& x) const{\n        return lower_bound(sorted.begin(), sorted.end(), x) -\
    \ sorted.begin();\n    }\n\n    size_t size() const{\n        return sorted.size();\n\
    \    }\n\n    vector<T> getCompressed() const{\n        return compressed;\n \
    \   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/compression.cpp
  requiredBy: []
  timestamp: '2022-11-01 02:14:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/compression.cpp
layout: document
redirect_from:
- /library/lib/others/compression.cpp
- /library/lib/others/compression.cpp.html
title: lib/others/compression.cpp
---
