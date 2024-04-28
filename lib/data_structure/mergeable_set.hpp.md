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
  bundledCode: "#line 2 \"lib/data_structure/mergeable_set.hpp\"\n\ntemplate <typename\
    \ T, int BLOCK = 500>\nstruct MergeableSet{\n    int N;\n    int nxt = 0;\n  \
    \  vector<bool> isBlock, seen;\n    vector<int> idx;\n    vector<vector<T>> s;\n\
    \    vector<vector<unsigned long long>> bit;\n\n    MergeableSet(const int N)\
    \ : N(N), isBlock(N), seen(N), idx(N), s(N){\n    }\n\n    void toBlock(int id){\n\
    \        isBlock[id] = true;\n        idx[id] = nxt++;\n        vector<unsigned\
    \ long long> emp((N + 63) / 64);\n        bit.emplace_back(emp);\n        for(auto\
    \ x : s[id]){\n            bit[idx[id]][x / 64] |= 1ULL << (x % 64);\n       \
    \ }\n    };\n\n    void insert(int id, T x){\n        if(isBlock[id]){\n     \
    \       bit[idx[id]][x / 64] |= 1ULL << (x % 64);\n        } else{\n         \
    \   s[id].emplace_back(x);\n            if((int) s[id].size() + 1 >= BLOCK){\n\
    \                toBlock(id);\n            }\n        }\n    }\n\n    void erase(int\
    \ id, T x){\n        if(isBlock[id]){\n            bit[idx[id]][x / 64] &= ~(1ULL\
    \ << (x % 64));\n        } else{\n            vector<T> tmp;\n            for(auto\
    \ &y : s[id]){\n                if(x != y){\n                    tmp.emplace_back(y);\n\
    \                }\n            }\n            s[id] = tmp;\n        }\n    }\n\
    \n    bool equal(int id1, int id2){\n        if(isBlock[id2]) swap(id1, id2);\n\
    \        if(isBlock[id1] && isBlock[id2]){\n            return (bit[idx[id1]]\
    \ == bit[idx[id2]]);\n        } else if(isBlock[id1] && !isBlock[id2]){\n    \
    \        int idx1 = idx[id1];\n            vector<unsigned long long> tmp = bit[idx1];\n\
    \            for(auto x : s[id2]){\n                if(!(bit[idx1][x / 64] & (1ULL\
    \ << (x % 64)))){\n                    return false;\n                }\n    \
    \            tmp[x / 64] &= ~(1ULL << (x % 64));\n            }\n            for(int\
    \ i = 0; i < (int) bit[idx1].size(); i++){\n                if(tmp[i] != 0ULL){\n\
    \                    return false;\n                }\n            }\n       \
    \     return true;\n        }\n        return (s[id1] == s[id2]);\n    }\n   \
    \ \n    T intersect(int id1, int id2){\n        if(isBlock[id2]) swap(id1, id2);\n\
    \        T ans = -1;\n        if(isBlock[id1] && isBlock[id2]){\n            int\
    \ idx1 = idx[id1], idx2 = idx[id2];\n            for(int i = 0; i < (int) bit[idx1].size();\
    \ i++){\n                if(ans != -1) break;\n                if(!(bit[idx1][i]\
    \ & bit[idx2][i])){\n                    continue;\n                }\n      \
    \          for(int k = 0; k < 64; k++){\n                    unsigned long long\
    \ flag1 = bit[idx1][i] & (1ULL << (k % 64)), flag2 = bit[idx2][i] & (1ULL << (k\
    \ % 64));\n                    if(flag1 && flag2){\n                        ans\
    \ = i * 64 + k;\n                        break;\n                    }\n     \
    \           }\n            }\n        } else if(isBlock[id1] && !isBlock[id2]){\n\
    \            int idx1 = idx[id1];\n            for(auto x : s[id2]){\n       \
    \         if(bit[idx1][x / 64] & (1ULL << (x % 64))){\n                    ans\
    \ = x;\n                    break;\n                }\n            }\n       \
    \ } else{\n            for(auto x : s[id1]){\n                seen[x] = true;\n\
    \            }\n            for(auto x : s[id2]){\n                if(seen[x]){\n\
    \                    ans = x;\n                    break;\n                }\n\
    \            }\n            for(auto x : s[id1]){\n                seen[x] = false;\n\
    \            }\n        }\n        return ans;\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T, int BLOCK = 500>\nstruct MergeableSet{\n\
    \    int N;\n    int nxt = 0;\n    vector<bool> isBlock, seen;\n    vector<int>\
    \ idx;\n    vector<vector<T>> s;\n    vector<vector<unsigned long long>> bit;\n\
    \n    MergeableSet(const int N) : N(N), isBlock(N), seen(N), idx(N), s(N){\n \
    \   }\n\n    void toBlock(int id){\n        isBlock[id] = true;\n        idx[id]\
    \ = nxt++;\n        vector<unsigned long long> emp((N + 63) / 64);\n        bit.emplace_back(emp);\n\
    \        for(auto x : s[id]){\n            bit[idx[id]][x / 64] |= 1ULL << (x\
    \ % 64);\n        }\n    };\n\n    void insert(int id, T x){\n        if(isBlock[id]){\n\
    \            bit[idx[id]][x / 64] |= 1ULL << (x % 64);\n        } else{\n    \
    \        s[id].emplace_back(x);\n            if((int) s[id].size() + 1 >= BLOCK){\n\
    \                toBlock(id);\n            }\n        }\n    }\n\n    void erase(int\
    \ id, T x){\n        if(isBlock[id]){\n            bit[idx[id]][x / 64] &= ~(1ULL\
    \ << (x % 64));\n        } else{\n            vector<T> tmp;\n            for(auto\
    \ &y : s[id]){\n                if(x != y){\n                    tmp.emplace_back(y);\n\
    \                }\n            }\n            s[id] = tmp;\n        }\n    }\n\
    \n    bool equal(int id1, int id2){\n        if(isBlock[id2]) swap(id1, id2);\n\
    \        if(isBlock[id1] && isBlock[id2]){\n            return (bit[idx[id1]]\
    \ == bit[idx[id2]]);\n        } else if(isBlock[id1] && !isBlock[id2]){\n    \
    \        int idx1 = idx[id1];\n            vector<unsigned long long> tmp = bit[idx1];\n\
    \            for(auto x : s[id2]){\n                if(!(bit[idx1][x / 64] & (1ULL\
    \ << (x % 64)))){\n                    return false;\n                }\n    \
    \            tmp[x / 64] &= ~(1ULL << (x % 64));\n            }\n            for(int\
    \ i = 0; i < (int) bit[idx1].size(); i++){\n                if(tmp[i] != 0ULL){\n\
    \                    return false;\n                }\n            }\n       \
    \     return true;\n        }\n        return (s[id1] == s[id2]);\n    }\n   \
    \ \n    T intersect(int id1, int id2){\n        if(isBlock[id2]) swap(id1, id2);\n\
    \        T ans = -1;\n        if(isBlock[id1] && isBlock[id2]){\n            int\
    \ idx1 = idx[id1], idx2 = idx[id2];\n            for(int i = 0; i < (int) bit[idx1].size();\
    \ i++){\n                if(ans != -1) break;\n                if(!(bit[idx1][i]\
    \ & bit[idx2][i])){\n                    continue;\n                }\n      \
    \          for(int k = 0; k < 64; k++){\n                    unsigned long long\
    \ flag1 = bit[idx1][i] & (1ULL << (k % 64)), flag2 = bit[idx2][i] & (1ULL << (k\
    \ % 64));\n                    if(flag1 && flag2){\n                        ans\
    \ = i * 64 + k;\n                        break;\n                    }\n     \
    \           }\n            }\n        } else if(isBlock[id1] && !isBlock[id2]){\n\
    \            int idx1 = idx[id1];\n            for(auto x : s[id2]){\n       \
    \         if(bit[idx1][x / 64] & (1ULL << (x % 64))){\n                    ans\
    \ = x;\n                    break;\n                }\n            }\n       \
    \ } else{\n            for(auto x : s[id1]){\n                seen[x] = true;\n\
    \            }\n            for(auto x : s[id2]){\n                if(seen[x]){\n\
    \                    ans = x;\n                    break;\n                }\n\
    \            }\n            for(auto x : s[id1]){\n                seen[x] = false;\n\
    \            }\n        }\n        return ans;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/mergeable_set.hpp
  requiredBy: []
  timestamp: '2024-04-29 04:16:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/mergeable_set.hpp
layout: document
redirect_from:
- /library/lib/data_structure/mergeable_set.hpp
- /library/lib/data_structure/mergeable_set.hpp.html
title: lib/data_structure/mergeable_set.hpp
---
