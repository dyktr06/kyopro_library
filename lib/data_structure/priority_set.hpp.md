---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/priority_set.hpp\"\n\ntemplate <typename\
    \ T>\nstruct PrioritySet{\n    struct compress{\n        vector<T> sorted, compressed;\n\
    \n        compress(){}\n\n        void init(const vector<T> &vec){\n         \
    \   int n = vec.size();\n            compressed.resize(n);\n            for(T\
    \ x : vec){\n                sorted.emplace_back(x);\n            }\n        \
    \    sort(sorted.begin(), sorted.end());\n            sorted.erase(unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n            for(int i = 0; i < n; ++i){\n   \
    \             compressed[i] = lower_bound(sorted.begin(), sorted.end(), vec[i])\
    \ - sorted.begin();\n            }\n        }\n\n        int get(const T &x) const{\n\
    \            return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();\n\
    \        }\n\n        T inv(const T &x) const{\n            return sorted[x];\n\
    \        }\n\n        size_t size() const{\n            return sorted.size();\n\
    \        }\n\n        vector<T> getCompressed() const{\n            return compressed;\n\
    \        }\n    };\n\n    struct BinaryIndexedTree{\n        int N;\n        vector<T>\
    \ BIT;\n        BinaryIndexedTree() {}\n\n        void init(int size){\n     \
    \       N = size;\n            BIT.assign(N + 1, 0);\n        }\n\n        T get(int\
    \ i){\n            return sum(i + 1) - sum(i);\n        }\n\n        void add(int\
    \ i, T x){\n            i++;\n            while(i <= N){\n                BIT[i]\
    \ += x;\n                i += i & -i;\n            }\n        }\n\n        T sum(int\
    \ i) const {\n            T ans = 0;\n            while(i > 0){\n            \
    \    ans += BIT[i];\n                i -= i & -i;\n            }\n           \
    \ return ans;\n        }\n\n        T sum(int L, int R) const {\n            return\
    \ sum(R) - sum(L);\n        }\n\n        int lower_bound(T x) const {\n      \
    \      if(x <= 0){\n                return 0;\n            } else{\n         \
    \       int v = 0, r = 1;\n                while(r < N) r = r << 1;\n        \
    \        for(int len = r; len > 0; len = len >> 1){\n                    if(v\
    \ + len < N && BIT[v + len] < x){\n                        x -= BIT[v + len];\n\
    \                        v += len;\n                    }\n                }\n\
    \                return v;\n            }\n        }\n\n        int upper_bound(T\
    \ x) const {\n            if(x < 0){\n                return 0;\n            }\
    \ else{\n                int v = 0, r = 1;\n                while(r <= N) r =\
    \ r << 1;\n                for(int len = r; len > 0; len = len >> 1){\n      \
    \              if(v + len <= N && BIT[v + len] <= x){\n                      \
    \  x -= BIT[v + len];\n                        v += len;\n                   \
    \ }\n                }\n                return v;\n            }\n        }\n\n\
    \        T operator [](int i) const {\n            return sum(i, i + 1);\n   \
    \     }\n    };\n\n    vector<T> a;\n    compress comp;\n    BinaryIndexedTree\
    \ cnt, val;\n\n    PrioritySet(){ }\n\n    void add(T x){\n        a.push_back(x);\n\
    \    }\n\n    void build(){\n        comp.init(a);\n        cnt.init(comp.size());\n\
    \        val.init(comp.size());\n    }\n\n    T size(){\n        return cnt.sum((int)\
    \ comp.size());\n    }\n\n    void insert(T x, T count = 1){\n        cnt.add(comp.get(x),\
    \ count);\n        val.add(comp.get(x), count * x);\n    }\n\n    void erase(T\
    \ x, T count = 1){\n        T idx = comp.get(x);\n        if(cnt.get(idx) < count){\n\
    \            count = cnt.get(idx);\n        }\n        cnt.add(idx, -count);\n\
    \        val.add(idx, -count * x);\n    }\n\n    // 1-indexed\n    T kth_small_element(T\
    \ k){\n        T idx = cnt.lower_bound(k);\n        return comp.inv(idx);\n  \
    \  }\n\n    T kth_large_element(T k){\n        T rev_k = size() - k + 1;\n   \
    \     return kth_small_element(rev_k);\n    }\n\n    // 1-indexed\n    T kth_small_sum(T\
    \ k){\n        if(size() < k){\n            return val.sum((int) comp.size());\n\
    \        }\n        T idx = cnt.lower_bound(k);\n        T sum = val.sum(idx);\n\
    \        sum += comp.inv(idx) * (k - cnt.sum(idx));\n        return sum;\n   \
    \ }\n\n    T kth_large_sum(T k){\n        if(size() < k){\n            return\
    \ val.sum((int) comp.size());\n        }\n        T rev_k = size() - k;\n    \
    \    return val.sum((int) comp.size()) - kth_small_sum(rev_k);\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct PrioritySet{\n    struct compress{\n\
    \        vector<T> sorted, compressed;\n\n        compress(){}\n\n        void\
    \ init(const vector<T> &vec){\n            int n = vec.size();\n            compressed.resize(n);\n\
    \            for(T x : vec){\n                sorted.emplace_back(x);\n      \
    \      }\n            sort(sorted.begin(), sorted.end());\n            sorted.erase(unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n            for(int i = 0; i < n; ++i){\n   \
    \             compressed[i] = lower_bound(sorted.begin(), sorted.end(), vec[i])\
    \ - sorted.begin();\n            }\n        }\n\n        int get(const T &x) const{\n\
    \            return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();\n\
    \        }\n\n        T inv(const T &x) const{\n            return sorted[x];\n\
    \        }\n\n        size_t size() const{\n            return sorted.size();\n\
    \        }\n\n        vector<T> getCompressed() const{\n            return compressed;\n\
    \        }\n    };\n\n    struct BinaryIndexedTree{\n        int N;\n        vector<T>\
    \ BIT;\n        BinaryIndexedTree() {}\n\n        void init(int size){\n     \
    \       N = size;\n            BIT.assign(N + 1, 0);\n        }\n\n        T get(int\
    \ i){\n            return sum(i + 1) - sum(i);\n        }\n\n        void add(int\
    \ i, T x){\n            i++;\n            while(i <= N){\n                BIT[i]\
    \ += x;\n                i += i & -i;\n            }\n        }\n\n        T sum(int\
    \ i) const {\n            T ans = 0;\n            while(i > 0){\n            \
    \    ans += BIT[i];\n                i -= i & -i;\n            }\n           \
    \ return ans;\n        }\n\n        T sum(int L, int R) const {\n            return\
    \ sum(R) - sum(L);\n        }\n\n        int lower_bound(T x) const {\n      \
    \      if(x <= 0){\n                return 0;\n            } else{\n         \
    \       int v = 0, r = 1;\n                while(r < N) r = r << 1;\n        \
    \        for(int len = r; len > 0; len = len >> 1){\n                    if(v\
    \ + len < N && BIT[v + len] < x){\n                        x -= BIT[v + len];\n\
    \                        v += len;\n                    }\n                }\n\
    \                return v;\n            }\n        }\n\n        int upper_bound(T\
    \ x) const {\n            if(x < 0){\n                return 0;\n            }\
    \ else{\n                int v = 0, r = 1;\n                while(r <= N) r =\
    \ r << 1;\n                for(int len = r; len > 0; len = len >> 1){\n      \
    \              if(v + len <= N && BIT[v + len] <= x){\n                      \
    \  x -= BIT[v + len];\n                        v += len;\n                   \
    \ }\n                }\n                return v;\n            }\n        }\n\n\
    \        T operator [](int i) const {\n            return sum(i, i + 1);\n   \
    \     }\n    };\n\n    vector<T> a;\n    compress comp;\n    BinaryIndexedTree\
    \ cnt, val;\n\n    PrioritySet(){ }\n\n    void add(T x){\n        a.push_back(x);\n\
    \    }\n\n    void build(){\n        comp.init(a);\n        cnt.init(comp.size());\n\
    \        val.init(comp.size());\n    }\n\n    T size(){\n        return cnt.sum((int)\
    \ comp.size());\n    }\n\n    void insert(T x, T count = 1){\n        cnt.add(comp.get(x),\
    \ count);\n        val.add(comp.get(x), count * x);\n    }\n\n    void erase(T\
    \ x, T count = 1){\n        T idx = comp.get(x);\n        if(cnt.get(idx) < count){\n\
    \            count = cnt.get(idx);\n        }\n        cnt.add(idx, -count);\n\
    \        val.add(idx, -count * x);\n    }\n\n    // 1-indexed\n    T kth_small_element(T\
    \ k){\n        T idx = cnt.lower_bound(k);\n        return comp.inv(idx);\n  \
    \  }\n\n    T kth_large_element(T k){\n        T rev_k = size() - k + 1;\n   \
    \     return kth_small_element(rev_k);\n    }\n\n    // 1-indexed\n    T kth_small_sum(T\
    \ k){\n        if(size() < k){\n            return val.sum((int) comp.size());\n\
    \        }\n        T idx = cnt.lower_bound(k);\n        T sum = val.sum(idx);\n\
    \        sum += comp.inv(idx) * (k - cnt.sum(idx));\n        return sum;\n   \
    \ }\n\n    T kth_large_sum(T k){\n        if(size() < k){\n            return\
    \ val.sum((int) comp.size());\n        }\n        T rev_k = size() - k;\n    \
    \    return val.sum((int) comp.size()) - kth_small_sum(rev_k);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/priority_set.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/priority_set.hpp
layout: document
redirect_from:
- /library/lib/data_structure/priority_set.hpp
- /library/lib/data_structure/priority_set.hpp.html
title: lib/data_structure/priority_set.hpp
---
