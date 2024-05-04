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
  bundledCode: "#line 2 \"lib/others/others.hpp\"\n\n// a\u3088\u308Ab \u304C\u5927\
    \u304D/\u5C0F\u3055\u304B\u3063\u305F\u3089\u3001a\u3092b\u306B\u7F6E\u304D\u63DB\
    \u3048\u308B\ntemplate<class T> inline bool chmax(T &a, T b) { if(a < b) { a =\
    \ b; return 1; } return 0; }\ntemplate<class T> inline bool chmin(T &a, T b) {\
    \ if(a > b) { a = b; return 1; } return 0; }\n\n// \u8907\u6570\u306E\u5165\u529B\
    \u3092\u53D7\u3051\u53D6\u308B\ntemplate<class... T>\nvoid in(T&... a){\n    (cin\
    \ >> ... >> a);\n}\n\n// \u8907\u6570\u306E\u51FA\u529B\u3092\u884C\u3046\nvoid\
    \ out(){\n    cout << '\\n';\n}\ntemplate<class T, class... Ts>\nvoid out(const\
    \ T &a, const Ts&... b){\n    cout << a;\n    (cout << ... << (cout << ' ', b));\n\
    \    cout << '\\n';\n}\n\n// n\u500B\u306E\u5165\u529B\u3092vec\u306E\u4E2D\u306B\
    \u683C\u7D0D\ntemplate<class T, class U> inline\nT vin(T &vec, U n){\n    vec.resize(n);\n\
    \    for(int i = 0; i < (int) n; ++i) cin >> vec[i];\n    return vec;\n}\n\n//\
    \ vec\u306E\u8981\u7D20\u3092\u3059\u3079\u3066\u51FA\u529B\ntemplate<class T>\
    \ inline\nvoid vout(T vec, string s = \"\\n\"){\n    for(auto x : vec) cout <<\
    \ x << s;\n}\n"
  code: "#pragma once\n\n// a\u3088\u308Ab \u304C\u5927\u304D/\u5C0F\u3055\u304B\u3063\
    \u305F\u3089\u3001a\u3092b\u306B\u7F6E\u304D\u63DB\u3048\u308B\ntemplate<class\
    \ T> inline bool chmax(T &a, T b) { if(a < b) { a = b; return 1; } return 0; }\n\
    template<class T> inline bool chmin(T &a, T b) { if(a > b) { a = b; return 1;\
    \ } return 0; }\n\n// \u8907\u6570\u306E\u5165\u529B\u3092\u53D7\u3051\u53D6\u308B\
    \ntemplate<class... T>\nvoid in(T&... a){\n    (cin >> ... >> a);\n}\n\n// \u8907\
    \u6570\u306E\u51FA\u529B\u3092\u884C\u3046\nvoid out(){\n    cout << '\\n';\n\
    }\ntemplate<class T, class... Ts>\nvoid out(const T &a, const Ts&... b){\n   \
    \ cout << a;\n    (cout << ... << (cout << ' ', b));\n    cout << '\\n';\n}\n\n\
    // n\u500B\u306E\u5165\u529B\u3092vec\u306E\u4E2D\u306B\u683C\u7D0D\ntemplate<class\
    \ T, class U> inline\nT vin(T &vec, U n){\n    vec.resize(n);\n    for(int i =\
    \ 0; i < (int) n; ++i) cin >> vec[i];\n    return vec;\n}\n\n// vec\u306E\u8981\
    \u7D20\u3092\u3059\u3079\u3066\u51FA\u529B\ntemplate<class T> inline\nvoid vout(T\
    \ vec, string s = \"\\n\"){\n    for(auto x : vec) cout << x << s;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/others.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/others.hpp
layout: document
redirect_from:
- /library/lib/others/others.hpp
- /library/lib/others/others.hpp.html
title: lib/others/others.hpp
---
