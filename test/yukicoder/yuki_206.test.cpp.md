---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/data_structure/mergeable_set.hpp
    title: lib/data_structure/mergeable_set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/206
    links:
    - https://yukicoder.me/problems/no/206
  bundledCode: "#line 1 \"test/yukicoder/yuki_206.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/206\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/mergeable_set.hpp\"\
    \n\ntemplate <int BLOCK = 250>\nstruct MergeableSet{\n    int N, M;\n    int nxt\
    \ = 0;\n    vector<bool> isBlock, seen;\n    vector<int> idx;\n    vector<vector<int>>\
    \ s;\n    vector<vector<unsigned long long>> bit;\n\n    // N: number of sets,\
    \ M: upper limit of sets\n    MergeableSet(const int N, const int M) : N(N), M(M\
    \ + 1), isBlock(N), seen(M + 1), idx(N), s(N){\n    }\n\n    void toBlock(int\
    \ id){\n        isBlock[id] = true;\n        idx[id] = nxt++;\n        vector<unsigned\
    \ long long> emp((M + 63) / 64);\n        bit.emplace_back(emp);\n        for(auto\
    \ x : s[id]){\n            bit[idx[id]][x / 64] |= 1ULL << (x % 64);\n       \
    \ }\n    };\n\n    void insert(int id, int x){\n        assert(0 <= x && x < M);\n\
    \        if(isBlock[id]){\n            bit[idx[id]][x / 64] |= 1ULL << (x % 64);\n\
    \        } else{\n            bool isContained = false;\n            for(auto\
    \ y : s[id]){\n                if(x == y){\n                    isContained =\
    \ true;\n                }\n            }\n            if(isContained){\n    \
    \            return;\n            }\n            s[id].emplace_back(x);\n    \
    \        if((int) s[id].size() + 1 >= BLOCK){\n                toBlock(id);\n\
    \            }\n        }\n    }\n\n    void erase(int id, int x){\n        assert(0\
    \ <= x && x < M);\n        if(isBlock[id]){\n            bit[idx[id]][x / 64]\
    \ &= ~(1ULL << (x % 64));\n        } else{\n            vector<int> tmp;\n   \
    \         for(auto y : s[id]){\n                if(x != y){\n                \
    \    tmp.emplace_back(y);\n                }\n            }\n            s[id]\
    \ = tmp;\n        }\n    }\n\n    void shift(int id, int x){\n        if(isBlock[id]){\n\
    \            int siz = bit[idx[id]].size();\n            vector<unsigned long\
    \ long> emp(siz);\n            for(int i = (int) siz - 1; i >= 0; i--){\n    \
    \            int j = i + (x / 64);\n                unsigned long long tmp1 =\
    \ bit[idx[id]][i], tmp2 = bit[idx[id]][i];\n                tmp1 <<= (x % 64);\n\
    \                tmp2 >>= 64 - (x % 64);\n                if(0 <= j && j < siz){\n\
    \                    emp[j] |= tmp1;\n                }\n                if(0\
    \ <= j + 1 && j + 1 < siz){\n                    emp[j + 1] |= tmp2;\n       \
    \         }\n            }\n            bit[idx[id]] = emp;\n        } else{\n\
    \            vector<int> tmp;\n            for(auto y : s[id]){\n            \
    \    if(0 <= y + x && y + x < M){\n                    tmp.emplace_back(y + x);\n\
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
    \     return true;\n        }\n        return (s[id1] == s[id2]);\n    }\n\n \
    \   // return one of elements\n    int intersect(int id1, int id2){\n        if(isBlock[id2])\
    \ swap(id1, id2);\n        int ans = -1;\n        if(isBlock[id1] && isBlock[id2]){\n\
    \            int idx1 = idx[id1], idx2 = idx[id2];\n            for(int i = 0;\
    \ i < (int) bit[idx1].size(); i++){\n                if(ans != -1) break;\n  \
    \              if(!(bit[idx1][i] & bit[idx2][i])){\n                    continue;\n\
    \                }\n                for(int k = 0; k < 64; k++){\n           \
    \         unsigned long long flag1 = bit[idx1][i] & (1ULL << (k % 64)), flag2\
    \ = bit[idx2][i] & (1ULL << (k % 64));\n                    if(flag1 && flag2){\n\
    \                        ans = i * 64 + k;\n                        break;\n \
    \                   }\n                }\n            }\n        } else if(isBlock[id1]\
    \ && !isBlock[id2]){\n            int idx1 = idx[id1];\n            for(auto x\
    \ : s[id2]){\n                if(bit[idx1][x / 64] & (1ULL << (x % 64))){\n  \
    \                  ans = x;\n                    break;\n                }\n \
    \           }\n        } else{\n            for(auto x : s[id1]){\n          \
    \      seen[x] = true;\n            }\n            for(auto x : s[id2]){\n   \
    \             if(seen[x]){\n                    ans = x;\n                   \
    \ break;\n                }\n            }\n            for(auto x : s[id1]){\n\
    \                seen[x] = false;\n            }\n        }\n        return ans;\n\
    \    }\n\n    // size of intersect set\n    int intersectCount(int id1, int id2){\n\
    \        if(isBlock[id2]) swap(id1, id2);\n        int ans = 0;\n        if(isBlock[id1]\
    \ && isBlock[id2]){\n            int idx1 = idx[id1], idx2 = idx[id2];\n     \
    \       for(int i = 0; i < (int) bit[idx1].size(); i++){\n                ans\
    \ += __builtin_popcountll(bit[idx1][i] & bit[idx2][i]);\n            }\n     \
    \   } else if(isBlock[id1] && !isBlock[id2]){\n            int idx1 = idx[id1];\n\
    \            for(auto x : s[id2]){\n                if(bit[idx1][x / 64] & (1ULL\
    \ << (x % 64))){\n                    ans++;\n                }\n            }\n\
    \        } else{\n            for(auto x : s[id1]){\n                seen[x] =\
    \ true;\n            }\n            for(auto x : s[id2]){\n                if(seen[x]){\n\
    \                    ans++;\n                }\n            }\n            for(auto\
    \ x : s[id1]){\n                seen[x] = false;\n            }\n        }\n \
    \       return ans;\n    }\n};\n#line 6 \"test/yukicoder/yuki_206.test.cpp\"\n\
    \nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    srand(time(NULL));\n\
    \n    int l, m, n; cin >> l >> m >> n;\n    vector<int> a(l), b(m);\n    for(int\
    \ i = 0; i < l; i++){\n        cin >> a[i];\n    }\n    for(int i = 0; i < m;\
    \ i++){\n        cin >> b[i];\n    }\n    int q; cin >> q;\n    MergeableSet<250>\
    \ ms(2, n + q);\n    for(auto x : a) ms.insert(0, x);\n    for(auto x : b) ms.insert(1,\
    \ x);\n    for(int i = 0; i < q; i++){\n        cout << ms.intersectCount(0, 1)\
    \ << \"\\n\";\n        ms.shift(1, 1);\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/206\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../lib/data_structure/mergeable_set.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n   \
    \ srand(time(NULL));\n\n    int l, m, n; cin >> l >> m >> n;\n    vector<int>\
    \ a(l), b(m);\n    for(int i = 0; i < l; i++){\n        cin >> a[i];\n    }\n\
    \    for(int i = 0; i < m; i++){\n        cin >> b[i];\n    }\n    int q; cin\
    \ >> q;\n    MergeableSet<250> ms(2, n + q);\n    for(auto x : a) ms.insert(0,\
    \ x);\n    for(auto x : b) ms.insert(1, x);\n    for(int i = 0; i < q; i++){\n\
    \        cout << ms.intersectCount(0, 1) << \"\\n\";\n        ms.shift(1, 1);\n\
    \    }\n}"
  dependsOn:
  - lib/data_structure/mergeable_set.hpp
  isVerificationFile: true
  path: test/yukicoder/yuki_206.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/yuki_206.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/yuki_206.test.cpp
- /verify/test/yukicoder/yuki_206.test.cpp.html
title: test/yukicoder/yuki_206.test.cpp
---
