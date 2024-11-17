---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/ordered_set.test.cpp
    title: test/library_checker/data_structure/ordered_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_2809.test.cpp
    title: test/yukicoder/yuki_2809.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Static Ordered Set
    links: []
  bundledCode: "#line 2 \"lib/data_structure/static_ordered_set.hpp\"\n\n/**\n * @brief\
    \ Static Ordered Set\n */\n\n#include <vector>\n#include <algorithm>\n\ntemplate\
    \ <typename T>\nstruct StaticOrderedSet{\n    struct compress{\n        std::vector<T>\
    \ sorted, compressed;\n\n        compress(){}\n\n        void init(const std::vector<T>\
    \ &vec){\n            int n = vec.size();\n            compressed.resize(n);\n\
    \            for(T x : vec){\n                sorted.emplace_back(x);\n      \
    \      }\n            std::sort(sorted.begin(), sorted.end());\n            sorted.erase(unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n            for(int i = 0; i < n; ++i){\n   \
    \             compressed[i] = std::lower_bound(sorted.begin(), sorted.end(), vec[i])\
    \ - sorted.begin();\n            }\n        }\n\n        int get(const T &x) const{\n\
    \            return std::lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();\n\
    \        }\n\n        T inv(const T &x) const{\n            return sorted[x];\n\
    \        }\n\n        size_t size() const{\n            return sorted.size();\n\
    \        }\n\n        std::vector<T> getCompressed() const{\n            return\
    \ compressed;\n        }\n    };\n\n    struct BinaryIndexedTree{\n        int\
    \ N;\n        std::vector<T> BIT;\n        BinaryIndexedTree() {}\n\n        void\
    \ init(int size){\n            N = size;\n            BIT.assign(N + 1, 0);\n\
    \        }\n\n        T get(int i){\n            return sum(i + 1) - sum(i);\n\
    \        }\n\n        void add(int i, T x){\n            i++;\n            while(i\
    \ <= N){\n                BIT[i] += x;\n                i += i & -i;\n       \
    \     }\n        }\n\n        T sum(int i) const {\n            T ans = 0;\n \
    \           while(i > 0){\n                ans += BIT[i];\n                i -=\
    \ i & -i;\n            }\n            return ans;\n        }\n\n        T sum(int\
    \ L, int R) const {\n            return sum(R) - sum(L);\n        }\n\n      \
    \  int lower_bound(T x) const {\n            if(x <= 0){\n                return\
    \ 0;\n            } else{\n                int v = 0, r = 1;\n               \
    \ while(r < N) r = r << 1;\n                for(int len = r; len > 0; len = len\
    \ >> 1){\n                    if(v + len < N && BIT[v + len] < x){\n         \
    \               x -= BIT[v + len];\n                        v += len;\n      \
    \              }\n                }\n                return v;\n            }\n\
    \        }\n\n        int upper_bound(T x) const {\n            if(x < 0){\n \
    \               return 0;\n            } else{\n                int v = 0, r =\
    \ 1;\n                while(r <= N) r = r << 1;\n                for(int len =\
    \ r; len > 0; len = len >> 1){\n                    if(v + len <= N && BIT[v +\
    \ len] <= x){\n                        x -= BIT[v + len];\n                  \
    \      v += len;\n                    }\n                }\n                return\
    \ v;\n            }\n        }\n\n        T operator [](int i) const {\n     \
    \       return sum(i, i + 1);\n        }\n    };\n\n    std::vector<T> a;\n  \
    \  compress comp;\n    BinaryIndexedTree cnt, val;\n\n    StaticOrderedSet(){\
    \ }\n\n    void add(T x){\n        a.push_back(x);\n    }\n\n    void build(){\n\
    \        comp.init(a);\n        cnt.init(comp.size());\n        val.init(comp.size());\n\
    \    }\n\n    T size(){\n        return cnt.sum((int) comp.size());\n    }\n\n\
    \    void insert(T x, T count = 1){\n        cnt.add(comp.get(x), count);\n  \
    \      val.add(comp.get(x), count * x);\n    }\n\n    void erase(T x, T count\
    \ = 1){\n        T idx = comp.get(x);\n        if(cnt.get(idx) < count){\n   \
    \         count = cnt.get(idx);\n        }\n        cnt.add(idx, -count);\n  \
    \      val.add(idx, -count * x);\n    }\n\n    // 1-indexed\n    T kth_small_element(T\
    \ k){\n        if(k <= 0 || size() < k){\n            return -1;\n        }\n\
    \        T idx = cnt.lower_bound(k);\n        return comp.inv(idx);\n    }\n\n\
    \    T kth_large_element(T k){\n        if(k <= 0 || size() < k){\n          \
    \  return -1;\n        }\n        T rev_k = size() - k + 1;\n        return kth_small_element(rev_k);\n\
    \    }\n\n    // 1-indexed\n    T kth_small_sum(T k){\n        if(size() < k){\n\
    \            return val.sum((int) comp.size());\n        }\n        T idx = cnt.lower_bound(k);\n\
    \        T sum = val.sum(idx);\n        sum += comp.inv(idx) * (k - cnt.sum(idx));\n\
    \        return sum;\n    }\n\n    T kth_large_sum(T k){\n        if(size() <\
    \ k){\n            return val.sum((int) comp.size());\n        }\n        T rev_k\
    \ = size() - k;\n        return val.sum((int) comp.size()) - kth_small_sum(rev_k);\n\
    \    }\n\n    // x \u672A\u6E80\n    T count_less(T x){\n        return cnt.sum(comp.get(x));\n\
    \    }\n\n    T lower_bound(T x){\n        return kth_small_element(count_less(x)\
    \ + 1);\n    }\n\n    T upper_bound(T x){\n        return kth_small_element(count_less(x\
    \ + 1) + 1);\n    }\n\n    // x \u4EE5\u4E0B\u3067\u6700\u5927\n    T reverse_lower_bound(T\
    \ x){\n        return kth_small_element(count_less(x + 1));\n    }\n\n    bool\
    \ exist(T x){\n        return count_less(x) != count_less(x + 1);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Static Ordered Set\n */\n\n#include <vector>\n\
    #include <algorithm>\n\ntemplate <typename T>\nstruct StaticOrderedSet{\n    struct\
    \ compress{\n        std::vector<T> sorted, compressed;\n\n        compress(){}\n\
    \n        void init(const std::vector<T> &vec){\n            int n = vec.size();\n\
    \            compressed.resize(n);\n            for(T x : vec){\n            \
    \    sorted.emplace_back(x);\n            }\n            std::sort(sorted.begin(),\
    \ sorted.end());\n            sorted.erase(unique(sorted.begin(), sorted.end()),\
    \ sorted.end());\n            for(int i = 0; i < n; ++i){\n                compressed[i]\
    \ = std::lower_bound(sorted.begin(), sorted.end(), vec[i]) - sorted.begin();\n\
    \            }\n        }\n\n        int get(const T &x) const{\n            return\
    \ std::lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();\n      \
    \  }\n\n        T inv(const T &x) const{\n            return sorted[x];\n    \
    \    }\n\n        size_t size() const{\n            return sorted.size();\n  \
    \      }\n\n        std::vector<T> getCompressed() const{\n            return\
    \ compressed;\n        }\n    };\n\n    struct BinaryIndexedTree{\n        int\
    \ N;\n        std::vector<T> BIT;\n        BinaryIndexedTree() {}\n\n        void\
    \ init(int size){\n            N = size;\n            BIT.assign(N + 1, 0);\n\
    \        }\n\n        T get(int i){\n            return sum(i + 1) - sum(i);\n\
    \        }\n\n        void add(int i, T x){\n            i++;\n            while(i\
    \ <= N){\n                BIT[i] += x;\n                i += i & -i;\n       \
    \     }\n        }\n\n        T sum(int i) const {\n            T ans = 0;\n \
    \           while(i > 0){\n                ans += BIT[i];\n                i -=\
    \ i & -i;\n            }\n            return ans;\n        }\n\n        T sum(int\
    \ L, int R) const {\n            return sum(R) - sum(L);\n        }\n\n      \
    \  int lower_bound(T x) const {\n            if(x <= 0){\n                return\
    \ 0;\n            } else{\n                int v = 0, r = 1;\n               \
    \ while(r < N) r = r << 1;\n                for(int len = r; len > 0; len = len\
    \ >> 1){\n                    if(v + len < N && BIT[v + len] < x){\n         \
    \               x -= BIT[v + len];\n                        v += len;\n      \
    \              }\n                }\n                return v;\n            }\n\
    \        }\n\n        int upper_bound(T x) const {\n            if(x < 0){\n \
    \               return 0;\n            } else{\n                int v = 0, r =\
    \ 1;\n                while(r <= N) r = r << 1;\n                for(int len =\
    \ r; len > 0; len = len >> 1){\n                    if(v + len <= N && BIT[v +\
    \ len] <= x){\n                        x -= BIT[v + len];\n                  \
    \      v += len;\n                    }\n                }\n                return\
    \ v;\n            }\n        }\n\n        T operator [](int i) const {\n     \
    \       return sum(i, i + 1);\n        }\n    };\n\n    std::vector<T> a;\n  \
    \  compress comp;\n    BinaryIndexedTree cnt, val;\n\n    StaticOrderedSet(){\
    \ }\n\n    void add(T x){\n        a.push_back(x);\n    }\n\n    void build(){\n\
    \        comp.init(a);\n        cnt.init(comp.size());\n        val.init(comp.size());\n\
    \    }\n\n    T size(){\n        return cnt.sum((int) comp.size());\n    }\n\n\
    \    void insert(T x, T count = 1){\n        cnt.add(comp.get(x), count);\n  \
    \      val.add(comp.get(x), count * x);\n    }\n\n    void erase(T x, T count\
    \ = 1){\n        T idx = comp.get(x);\n        if(cnt.get(idx) < count){\n   \
    \         count = cnt.get(idx);\n        }\n        cnt.add(idx, -count);\n  \
    \      val.add(idx, -count * x);\n    }\n\n    // 1-indexed\n    T kth_small_element(T\
    \ k){\n        if(k <= 0 || size() < k){\n            return -1;\n        }\n\
    \        T idx = cnt.lower_bound(k);\n        return comp.inv(idx);\n    }\n\n\
    \    T kth_large_element(T k){\n        if(k <= 0 || size() < k){\n          \
    \  return -1;\n        }\n        T rev_k = size() - k + 1;\n        return kth_small_element(rev_k);\n\
    \    }\n\n    // 1-indexed\n    T kth_small_sum(T k){\n        if(size() < k){\n\
    \            return val.sum((int) comp.size());\n        }\n        T idx = cnt.lower_bound(k);\n\
    \        T sum = val.sum(idx);\n        sum += comp.inv(idx) * (k - cnt.sum(idx));\n\
    \        return sum;\n    }\n\n    T kth_large_sum(T k){\n        if(size() <\
    \ k){\n            return val.sum((int) comp.size());\n        }\n        T rev_k\
    \ = size() - k;\n        return val.sum((int) comp.size()) - kth_small_sum(rev_k);\n\
    \    }\n\n    // x \u672A\u6E80\n    T count_less(T x){\n        return cnt.sum(comp.get(x));\n\
    \    }\n\n    T lower_bound(T x){\n        return kth_small_element(count_less(x)\
    \ + 1);\n    }\n\n    T upper_bound(T x){\n        return kth_small_element(count_less(x\
    \ + 1) + 1);\n    }\n\n    // x \u4EE5\u4E0B\u3067\u6700\u5927\n    T reverse_lower_bound(T\
    \ x){\n        return kth_small_element(count_less(x + 1));\n    }\n\n    bool\
    \ exist(T x){\n        return count_less(x) != count_less(x + 1);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/static_ordered_set.hpp
  requiredBy: []
  timestamp: '2024-11-15 15:44:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/ordered_set.test.cpp
  - test/yukicoder/yuki_2809.test.cpp
documentation_of: lib/data_structure/static_ordered_set.hpp
layout: document
redirect_from:
- /library/lib/data_structure/static_ordered_set.hpp
- /library/lib/data_structure/static_ordered_set.hpp.html
title: Static Ordered Set
---
