---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Radix Heap
    links:
    - https://www.slideshare.net/slideshow/ss-46612984/46612984
  bundledCode: "#line 2 \"lib/data_structure/radix_heap.hpp\"\n\n/**\n * @brief Radix\
    \ Heap\n * @see https://www.slideshare.net/slideshow/ss-46612984/46612984\n */\n\
    \n#include <vector>\n#include <cassert>\n#include <limits>\n\ntemplate <typename\
    \ T>\nstruct RadixHeap{\n    using u64 = unsigned long long;\n    using P = std::pair<u64,\
    \ T>;\n    std::vector<std::vector<P>> val;\n    u64 N, last;\n\nprivate:\n  \
    \  int bit_width(u64 x){\n        if(x == 0) return 0;\n        return 64 - __builtin_clzll(x);\n\
    \    }\n\npublic:\n    RadixHeap(){\n        N = last = 0;\n    }\n\n    void\
    \ push(P x){\n        assert(last <= x.first);\n        int i = bit_width(last\
    \ ^ x.first);\n        if((int) val.size() <= i) val.resize(i + 1);\n        val[i].push_back(x);\n\
    \        N++;\n    }\n\n    P pop(){\n        assert(N > 0);\n        if(val[0].empty()){\n\
    \            int i = 1;\n            while(val[i].empty()) i++;\n            u64\
    \ nlast = std::numeric_limits<u64>::max();\n            for(auto &v : val[i]){\n\
    \                nlast = std::min(nlast, v.first);\n            }\n          \
    \  for(auto &v : val[i]){\n                val[bit_width(nlast ^ v.first)].push_back(v);\n\
    \            }\n            last = nlast;\n            val[i].clear();\n     \
    \   }\n        P ret = val[0].back();\n        val[0].pop_back();\n        N--;\n\
    \        return ret;\n    }\n\n    size_t size(){\n        return N;\n    }\n\
    };\n"
  code: "#pragma once\n\n/**\n * @brief Radix Heap\n * @see https://www.slideshare.net/slideshow/ss-46612984/46612984\n\
    \ */\n\n#include <vector>\n#include <cassert>\n#include <limits>\n\ntemplate <typename\
    \ T>\nstruct RadixHeap{\n    using u64 = unsigned long long;\n    using P = std::pair<u64,\
    \ T>;\n    std::vector<std::vector<P>> val;\n    u64 N, last;\n\nprivate:\n  \
    \  int bit_width(u64 x){\n        if(x == 0) return 0;\n        return 64 - __builtin_clzll(x);\n\
    \    }\n\npublic:\n    RadixHeap(){\n        N = last = 0;\n    }\n\n    void\
    \ push(P x){\n        assert(last <= x.first);\n        int i = bit_width(last\
    \ ^ x.first);\n        if((int) val.size() <= i) val.resize(i + 1);\n        val[i].push_back(x);\n\
    \        N++;\n    }\n\n    P pop(){\n        assert(N > 0);\n        if(val[0].empty()){\n\
    \            int i = 1;\n            while(val[i].empty()) i++;\n            u64\
    \ nlast = std::numeric_limits<u64>::max();\n            for(auto &v : val[i]){\n\
    \                nlast = std::min(nlast, v.first);\n            }\n          \
    \  for(auto &v : val[i]){\n                val[bit_width(nlast ^ v.first)].push_back(v);\n\
    \            }\n            last = nlast;\n            val[i].clear();\n     \
    \   }\n        P ret = val[0].back();\n        val[0].pop_back();\n        N--;\n\
    \        return ret;\n    }\n\n    size_t size(){\n        return N;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/radix_heap.hpp
  requiredBy: []
  timestamp: '2024-11-15 16:06:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/radix_heap.hpp
layout: document
redirect_from:
- /library/lib/data_structure/radix_heap.hpp
- /library/lib/data_structure/radix_heap.hpp.html
title: Radix Heap
---
