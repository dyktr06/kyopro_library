---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/suffix_array.hpp
    title: lib/string/suffix_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"test/library_checker/string/number_of_substrings.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/string/suffix_array.hpp\"\
    \n\ntemplate <typename T>\nstruct SuffixArray{\n    vector<int> SA;\n    const\
    \ T s;\n\n    SuffixArray(const T &str) : s(str){\n        SA.resize(s.size());\n\
    \        iota(SA.begin(), SA.end(), 0);\n        sort(SA.begin(), SA.end(), [&](int\
    \ a, int b){\n            return s[a] == s[b] ? a > b : s[a] < s[b];\n       \
    \ });\n        vector<int> classes(s.size()), c(s.begin(), s.end()), cnt(s.size());\n\
    \        for(int len = 1; len < (int) s.size(); len <<= 1){\n            for(int\
    \ i = 0; i < (int) s.size(); i++){\n                if(i > 0 && c[SA[i - 1]] ==\
    \ c[SA[i]] && SA[i - 1] + len < (int) s.size() && c[SA[i - 1] + len / 2] == c[SA[i]\
    \ + len / 2]){\n                    classes[SA[i]] = classes[SA[i - 1]];\n   \
    \             } else{\n                    classes[SA[i]] = i;\n             \
    \   }\n            }\n            iota(cnt.begin(), cnt.end(), 0);\n         \
    \   copy(SA.begin(), SA.end(), c.begin());\n            for(int i = 0; i < (int)\
    \ s.size(); i++){\n                int s1 = c[i] - len;\n                if(s1\
    \ >= 0) SA[cnt[classes[s1]]++] = s1;\n            }\n            classes.swap(c);\n\
    \        }\n    }\n\n    int operator[](int k) const{\n        return SA[k];\n\
    \    }\n\n    size_t size() const{\n        return s.size();\n    }\n\n    bool\
    \ lt_substr(const T &t, int si = 0, int ti = 0){\n        int sn = (int) s.size(),\
    \ tn = (int) t.size();\n        while(si < sn && ti < tn){\n            if(s[si]\
    \ < t[ti]) return true;\n            if(s[si] > t[ti]) return false;\n       \
    \     ++si, ++ti;\n        }\n        return si >= sn && ti < tn;\n    }\n\n \
    \   int lower_bound(const T &t){\n        int low = -1, high = (int) SA.size();\n\
    \        while(high - low > 1){\n            int mid = (low + high) / 2;\n   \
    \         if(lt_substr(t, SA[mid])) low = mid;\n            else high = mid;\n\
    \        }\n        return high;\n    }\n\n    pair<int, int> lower_upper_bound(T\
    \ &t){\n        int idx = lower_bound(t);\n        int low = idx - 1, high = (int)\
    \ SA.size();\n        t.back()++;\n        while(high - low > 1){\n          \
    \  int mid = (low + high) / 2;\n            if(lt_substr(t, SA[mid])) low = mid;\n\
    \            else high = mid;\n        }\n        t.back()--;\n        return\
    \ {idx, high};\n    }\n};\n\ntemplate <typename T>\nstruct LCPArray{\n    const\
    \ SuffixArray<T> &SA;\n    vector<int> LCP, rank;\n\n    LCPArray(const SuffixArray<T>\
    \ &SA) : SA(SA), LCP(SA.size()){\n        rank.resize(SA.size());\n        for(int\
    \ i = 0; i < (int) SA.size(); i++){\n            rank[SA[i]] = i;\n        }\n\
    \        for(int i = 0, h = 0; i < (int) SA.size(); i++){\n            if(rank[i]\
    \ + 1 < (int) SA.size()){\n                for(int j = SA[rank[i] + 1]; max(i,\
    \ j) + h < (int) SA.size() && SA.s[i + h] == SA.s[j + h]; ++h);\n            \
    \    LCP[rank[i] + 1] = h;\n                if(h > 0) --h;\n            }\n  \
    \      }\n    }\n\n    int operator[](int k) const {\n        return LCP[k];\n\
    \    }\n\n    size_t size() const {\n        return LCP.size();\n    }\n};\n#line\
    \ 6 \"test/library_checker/string/number_of_substrings.test.cpp\"\n\nint main(){\n\
    \    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    string s; cin\
    \ >> s;\n    long long n = s.size();\n    SuffixArray sa(s);\n    LCPArray la(sa);\n\
    \    long long ans = n * (n + 1) / 2;\n    for(auto x : la.LCP){\n        ans\
    \ -= x;\n    }\n    cout << ans << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/string/suffix_array.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   string s; cin >> s;\n    long long n = s.size();\n    SuffixArray sa(s);\n\
    \    LCPArray la(sa);\n    long long ans = n * (n + 1) / 2;\n    for(auto x :\
    \ la.LCP){\n        ans -= x;\n    }\n    cout << ans << \"\\n\";\n}\n"
  dependsOn:
  - lib/string/suffix_array.hpp
  isVerificationFile: true
  path: test/library_checker/string/number_of_substrings.test.cpp
  requiredBy: []
  timestamp: '2024-02-14 05:45:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/string/number_of_substrings.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/string/number_of_substrings.test.cpp
- /verify/test/library_checker/string/number_of_substrings.test.cpp.html
title: test/library_checker/string/number_of_substrings.test.cpp
---
