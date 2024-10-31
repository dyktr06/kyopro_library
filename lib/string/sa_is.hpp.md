---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/number_of_substrings_1.test.cpp
    title: test/library_checker/string/number_of_substrings_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/suffixarray_1.test.cpp
    title: test/library_checker/string/suffixarray_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/sa-is.html
  bundledCode: "#line 2 \"lib/string/sa_is.hpp\"\n\n#include <vector>\n\n// \u53C2\
    \u8003: https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/sa-is.html\n\
    template <typename T>\nstruct SA_IS{\n    std::vector<int> SA;\n\nprivate:\n \
    \   std::vector<int> dfs(std::vector<int> &s, const int bucket_size){\n      \
    \  if((int) s.size() == 1){\n            return {0};\n        }\n\n        const\
    \ int n = s.size();\n        s.push_back(0);\n\n        // S \u578B\u304B\u3069\
    \u3046\u304B\n        std::vector<bool> is_s(n + 1);\n        is_s[n] = true;\n\
    \        for(int i = n - 1; i >= 0; --i){\n            if(s[i] < s[i + 1]){\n\
    \                is_s[i] = true;\n            }else if(s[i] > s[i + 1]){\n   \
    \             is_s[i] = false;\n            }else{\n                is_s[i] =\
    \ is_s[i + 1];\n            }\n        }\n\n        // LMS \u304B\u3069\u3046\u304B\
    \n        std::vector<bool> is_lms(n + 1);\n        is_lms[n] = true;\n      \
    \  for(int i = 1; i <= n; ++i){\n            if(!is_s[i - 1] && is_s[i]){\n  \
    \              is_lms[i] = true;\n            }\n        }\n\n        std::vector<int>\
    \ bucket_count(bucket_size, 0);\n        for(auto i : s){\n            bucket_count[i]++;\n\
    \        }\n\n        auto induced_sort = [&](std::vector<int> &lms) -> std::vector<int>\
    \ {\n            std::vector<std::vector<int>> bucket(bucket_size);\n        \
    \    std::vector<int> bucket_l(bucket_size, 0), bucket_r(bucket_size);\n     \
    \       for(int i = 0; i < bucket_size; i++){\n                bucket[i].resize(bucket_count[i]);\n\
    \                bucket_r[i] = bucket_count[i];\n            }\n            for(int\
    \ i = (int) lms.size() - 1; i >= 0; --i){\n                int c = s[lms[i]];\n\
    \                bucket[c][--bucket_r[c]] = lms[i];\n            }\n\n       \
    \     // LMS \u3092\u3082\u3068\u306B L \u578B\u3092\u30BD\u30FC\u30C8\n     \
    \       for(int i = 0; i < bucket_size; ++i){\n                for(int k = 0;\
    \ k < bucket_l[i]; ++k){\n                    int j = bucket[i][k];\n        \
    \            if(j != 0 && !is_s[j - 1]){\n                        bucket[s[j -\
    \ 1]][bucket_l[s[j - 1]]++] = j - 1;\n                    }\n                }\n\
    \                for(int k = bucket_r[i]; k < bucket_count[i]; ++k){\n       \
    \             int j = bucket[i][k];\n                    if(j != 0 && !is_s[j\
    \ - 1]){\n                        bucket[s[j - 1]][bucket_l[s[j - 1]]++] = j -\
    \ 1;\n                    }\n                }\n            }\n\n            //\
    \ LMS \u3092\u4E00\u65E6\u524A\u9664\n            for(int i = (int) lms.size()\
    \ - 1; i >= 0; --i){\n                int c = s[lms[i]];\n                bucket_r[c]\
    \ = bucket_count[c];\n            }\n\n            // L \u578B\u3092\u3082\u3068\
    \u306B S \u578B\u3092\u30BD\u30FC\u30C8\n            for(int i = bucket_size -\
    \ 1; i >= 0; --i){\n                for(int k = bucket_count[i] - 1; k >= bucket_r[i];\
    \ --k){\n                    int j = bucket[i][k];\n                    if(j !=\
    \ 0 && is_s[j - 1]){\n                        bucket[s[j - 1]][--bucket_r[s[j\
    \ - 1]]] = j - 1;\n                    }\n                }\n                for(int\
    \ k = bucket_l[i] - 1; k >= 0; --k){\n                    int j = bucket[i][k];\n\
    \                    if(j != 0 && is_s[j - 1]){\n                        bucket[s[j\
    \ - 1]][--bucket_r[s[j - 1]]] = j - 1;\n                    }\n              \
    \  }\n            }\n\n            std::vector<int> sorted(n);\n            int\
    \ cur_pos = 0;\n            for(int i = 1; i < bucket_size; ++i){\n          \
    \      for(auto j : bucket[i]){\n                    sorted[cur_pos++] = j;\n\
    \                }\n            }\n            return sorted;\n        };\n\n\
    \        std::vector<int> lms;\n        for(int i = n; i >= 0; --i){\n       \
    \     if(is_lms[i]){\n                lms.push_back(i);\n            }\n     \
    \   }\n\n        // LMS \u3092\u5F8C\u308D\u304B\u3089\u5165\u308C\u308B -> \u3053\
    \u308C\u3067 LMS \u90E8\u5206\u6587\u5B57\u5217\u306E\u7BC4\u56F2\u306F\u30BD\u30FC\
    \u30C8\u3055\u308C\u308B\n        std::vector<int> res = induced_sort(lms);\n\n\
    \        // LMS \u90E8\u5206\u6587\u5B57\u5217\u306B ID \u3092\u632F\u308B\n \
    \       std::vector<int> id_lms(n + 1, -1);\n        {\n            id_lms[n]\
    \ = 1;\n            int prv = n;\n            auto comp = [&](int l1, int l2){\n\
    \                if(s[l1] != s[l2]){\n                    return false;\n    \
    \            }\n                for(int i = 1; (l1 + i < n + 1) && (l2 + i < n\
    \ + 1); ++i){\n                    if(s[l1 + i] != s[l2 + i]){\n             \
    \           return false;\n                    }\n                    if(is_lms[l1\
    \ + i] && is_lms[l2 + i]) return true;\n                    if(is_lms[l1 + i]\
    \ || is_lms[l2 + i]) return false;\n                }\n                return\
    \ false;\n            };\n            for(auto j : res){\n                if(is_lms[j]){\n\
    \                    id_lms[j] = id_lms[prv] + (comp(prv, j) ? 0 : 1);\n     \
    \               prv = j;\n                }\n            }\n        }\n\n    \
    \    std::vector<int> ns;\n        int nbucket_size = 1;\n        std::vector<int>\
    \ idx;\n        for(int i = 0; i < n + 1; ++i){\n            if(is_lms[i]){\n\
    \                ns.push_back(id_lms[i]);\n                idx.push_back(i);\n\
    \                nbucket_size = std::max(nbucket_size, id_lms[i] + 1);\n     \
    \       }\n        }\n\n        std::vector<int> sorted_lms;\n        // LMS \u306E\
    \ suffix_array \u3092\u6C42\u3081\u308B -> LMS \u306E suffix \u306E\u8F9E\u66F8\
    \u9806\u304C\u5206\u304B\u308B\n        for(auto i : dfs(ns, nbucket_size)){\n\
    \            sorted_lms.push_back(idx[i]);\n        }\n\n        return induced_sort(sorted_lms);\n\
    \    }\n\npublic:\n    SA_IS(const T &s){\n        std::vector<int> ns(s.size());\n\
    \        int nbucket_size = 1;\n        for(int i = 0; i < (int) s.size(); ++i){\n\
    \            ns[i] = (int) (s[i] + 1);\n            nbucket_size = std::max(nbucket_size,\
    \ ns[i] + 1);\n        }\n        SA = dfs(ns, nbucket_size);\n    }\n\n    std::vector<int>\
    \ get() const {\n        return SA;\n    }\n\n    size_t size() const {\n    \
    \    return SA.size();\n    }\n\n    int operator[](int k) const {\n        return\
    \ SA[k];\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\n// \u53C2\u8003: https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/sa-is.html\n\
    template <typename T>\nstruct SA_IS{\n    std::vector<int> SA;\n\nprivate:\n \
    \   std::vector<int> dfs(std::vector<int> &s, const int bucket_size){\n      \
    \  if((int) s.size() == 1){\n            return {0};\n        }\n\n        const\
    \ int n = s.size();\n        s.push_back(0);\n\n        // S \u578B\u304B\u3069\
    \u3046\u304B\n        std::vector<bool> is_s(n + 1);\n        is_s[n] = true;\n\
    \        for(int i = n - 1; i >= 0; --i){\n            if(s[i] < s[i + 1]){\n\
    \                is_s[i] = true;\n            }else if(s[i] > s[i + 1]){\n   \
    \             is_s[i] = false;\n            }else{\n                is_s[i] =\
    \ is_s[i + 1];\n            }\n        }\n\n        // LMS \u304B\u3069\u3046\u304B\
    \n        std::vector<bool> is_lms(n + 1);\n        is_lms[n] = true;\n      \
    \  for(int i = 1; i <= n; ++i){\n            if(!is_s[i - 1] && is_s[i]){\n  \
    \              is_lms[i] = true;\n            }\n        }\n\n        std::vector<int>\
    \ bucket_count(bucket_size, 0);\n        for(auto i : s){\n            bucket_count[i]++;\n\
    \        }\n\n        auto induced_sort = [&](std::vector<int> &lms) -> std::vector<int>\
    \ {\n            std::vector<std::vector<int>> bucket(bucket_size);\n        \
    \    std::vector<int> bucket_l(bucket_size, 0), bucket_r(bucket_size);\n     \
    \       for(int i = 0; i < bucket_size; i++){\n                bucket[i].resize(bucket_count[i]);\n\
    \                bucket_r[i] = bucket_count[i];\n            }\n            for(int\
    \ i = (int) lms.size() - 1; i >= 0; --i){\n                int c = s[lms[i]];\n\
    \                bucket[c][--bucket_r[c]] = lms[i];\n            }\n\n       \
    \     // LMS \u3092\u3082\u3068\u306B L \u578B\u3092\u30BD\u30FC\u30C8\n     \
    \       for(int i = 0; i < bucket_size; ++i){\n                for(int k = 0;\
    \ k < bucket_l[i]; ++k){\n                    int j = bucket[i][k];\n        \
    \            if(j != 0 && !is_s[j - 1]){\n                        bucket[s[j -\
    \ 1]][bucket_l[s[j - 1]]++] = j - 1;\n                    }\n                }\n\
    \                for(int k = bucket_r[i]; k < bucket_count[i]; ++k){\n       \
    \             int j = bucket[i][k];\n                    if(j != 0 && !is_s[j\
    \ - 1]){\n                        bucket[s[j - 1]][bucket_l[s[j - 1]]++] = j -\
    \ 1;\n                    }\n                }\n            }\n\n            //\
    \ LMS \u3092\u4E00\u65E6\u524A\u9664\n            for(int i = (int) lms.size()\
    \ - 1; i >= 0; --i){\n                int c = s[lms[i]];\n                bucket_r[c]\
    \ = bucket_count[c];\n            }\n\n            // L \u578B\u3092\u3082\u3068\
    \u306B S \u578B\u3092\u30BD\u30FC\u30C8\n            for(int i = bucket_size -\
    \ 1; i >= 0; --i){\n                for(int k = bucket_count[i] - 1; k >= bucket_r[i];\
    \ --k){\n                    int j = bucket[i][k];\n                    if(j !=\
    \ 0 && is_s[j - 1]){\n                        bucket[s[j - 1]][--bucket_r[s[j\
    \ - 1]]] = j - 1;\n                    }\n                }\n                for(int\
    \ k = bucket_l[i] - 1; k >= 0; --k){\n                    int j = bucket[i][k];\n\
    \                    if(j != 0 && is_s[j - 1]){\n                        bucket[s[j\
    \ - 1]][--bucket_r[s[j - 1]]] = j - 1;\n                    }\n              \
    \  }\n            }\n\n            std::vector<int> sorted(n);\n            int\
    \ cur_pos = 0;\n            for(int i = 1; i < bucket_size; ++i){\n          \
    \      for(auto j : bucket[i]){\n                    sorted[cur_pos++] = j;\n\
    \                }\n            }\n            return sorted;\n        };\n\n\
    \        std::vector<int> lms;\n        for(int i = n; i >= 0; --i){\n       \
    \     if(is_lms[i]){\n                lms.push_back(i);\n            }\n     \
    \   }\n\n        // LMS \u3092\u5F8C\u308D\u304B\u3089\u5165\u308C\u308B -> \u3053\
    \u308C\u3067 LMS \u90E8\u5206\u6587\u5B57\u5217\u306E\u7BC4\u56F2\u306F\u30BD\u30FC\
    \u30C8\u3055\u308C\u308B\n        std::vector<int> res = induced_sort(lms);\n\n\
    \        // LMS \u90E8\u5206\u6587\u5B57\u5217\u306B ID \u3092\u632F\u308B\n \
    \       std::vector<int> id_lms(n + 1, -1);\n        {\n            id_lms[n]\
    \ = 1;\n            int prv = n;\n            auto comp = [&](int l1, int l2){\n\
    \                if(s[l1] != s[l2]){\n                    return false;\n    \
    \            }\n                for(int i = 1; (l1 + i < n + 1) && (l2 + i < n\
    \ + 1); ++i){\n                    if(s[l1 + i] != s[l2 + i]){\n             \
    \           return false;\n                    }\n                    if(is_lms[l1\
    \ + i] && is_lms[l2 + i]) return true;\n                    if(is_lms[l1 + i]\
    \ || is_lms[l2 + i]) return false;\n                }\n                return\
    \ false;\n            };\n            for(auto j : res){\n                if(is_lms[j]){\n\
    \                    id_lms[j] = id_lms[prv] + (comp(prv, j) ? 0 : 1);\n     \
    \               prv = j;\n                }\n            }\n        }\n\n    \
    \    std::vector<int> ns;\n        int nbucket_size = 1;\n        std::vector<int>\
    \ idx;\n        for(int i = 0; i < n + 1; ++i){\n            if(is_lms[i]){\n\
    \                ns.push_back(id_lms[i]);\n                idx.push_back(i);\n\
    \                nbucket_size = std::max(nbucket_size, id_lms[i] + 1);\n     \
    \       }\n        }\n\n        std::vector<int> sorted_lms;\n        // LMS \u306E\
    \ suffix_array \u3092\u6C42\u3081\u308B -> LMS \u306E suffix \u306E\u8F9E\u66F8\
    \u9806\u304C\u5206\u304B\u308B\n        for(auto i : dfs(ns, nbucket_size)){\n\
    \            sorted_lms.push_back(idx[i]);\n        }\n\n        return induced_sort(sorted_lms);\n\
    \    }\n\npublic:\n    SA_IS(const T &s){\n        std::vector<int> ns(s.size());\n\
    \        int nbucket_size = 1;\n        for(int i = 0; i < (int) s.size(); ++i){\n\
    \            ns[i] = (int) (s[i] + 1);\n            nbucket_size = std::max(nbucket_size,\
    \ ns[i] + 1);\n        }\n        SA = dfs(ns, nbucket_size);\n    }\n\n    std::vector<int>\
    \ get() const {\n        return SA;\n    }\n\n    size_t size() const {\n    \
    \    return SA.size();\n    }\n\n    int operator[](int k) const {\n        return\
    \ SA[k];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/string/sa_is.hpp
  requiredBy: []
  timestamp: '2024-10-31 17:21:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/number_of_substrings_1.test.cpp
  - test/library_checker/string/suffixarray_1.test.cpp
documentation_of: lib/string/sa_is.hpp
layout: document
redirect_from:
- /library/lib/string/sa_is.hpp
- /library/lib/string/sa_is.hpp.html
title: lib/string/sa_is.hpp
---
