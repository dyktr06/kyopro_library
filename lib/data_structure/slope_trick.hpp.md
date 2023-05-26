---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_2304.test.cpp
    title: test/yukicoder/yuki_2304.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/slope_trick.hpp\"\n\nstruct SlopeTrick{\n\
    private:\n    struct P{\n        // x: \u5EA7\u6A19, c: \u50BE\u304D\u306E\u5909\
    \u5316\n        long long x, c;\n        P(long long _x, long long _c) : x(_x),\
    \ c(_c) {}\n        friend inline bool operator<(const P &a, const P &b){ return\
    \ a.x < b.x; }\n        friend inline bool operator>(const P &a, const P &b){\
    \ return a.x > b.x; }\n    };\n    long long addL, addR, min_y;\n    priority_queue<P>\
    \ L;\n    priority_queue<P, vector<P>, greater<P>> R;\n    void pushL(long long\
    \ x, long long c = 1){\n        L.emplace(x - addL, c);\n    }\n    void pushR(long\
    \ long x, long long c = 1){\n        R.emplace(x - addR, c);\n    }\n    P getL(){\n\
    \        return P{L.top().x + addL, L.top().c};\n    }\n    P getR(){\n      \
    \  return P{R.top().x + addR, R.top().c};\n    }\n    void popL(){ L.pop(); }\n\
    \    void popR(){ R.pop(); }\n\npublic:\n    SlopeTrick() : addL(0), addR(0),\
    \ min_y(0) {}\n\n    // return: x, f(x)\n    pair<long long, long long> get_min(){\n\
    \        long long x;\n        if(L.empty()){\n            if(R.empty()){\n  \
    \              x = 0;\n            }else{\n                x = getR().x;\n   \
    \         }\n        }else{\n            x = getL().x;\n        }\n        return\
    \ make_pair(x, min_y);\n    }\n\n    void shift_L(long long a){\n        addL\
    \ += a;\n    }\n\n    void shift_R(long long a){\n        addR += a;\n    }\n\n\
    \    // f(x) <- f(x - a)\n    void shift_x(long long a){\n        addL += a, addR\
    \ += a;\n    }\n\n    // f(x) <- f(x) + a\n    void shift_y(long long a){\n  \
    \      min_y += a;\n    }\n\n    // add (x - a)_+  ____/\n    void add_xma(long\
    \ long a, long long c = 1){\n        long long used = 0;\n        while(used <\
    \ c && !(L.empty())){\n            auto [X, C] = getL();\n            if(X <=\
    \ a) break;\n            popL();\n            long long tmp = min(c - used, C);\n\
    \            pushR(X, tmp);\n            if(C != tmp) pushL(X, C - tmp);\n   \
    \         min_y += (X - a) * tmp;\n            used += tmp;\n        }\n     \
    \   if(used) pushL(a, used);\n        if(c - used) pushR(a, c - used);\n    }\n\
    \n    // add (a - x)_+  \\____\n    void add_amx(long long a, long long c = 1){\n\
    \        long long used = 0;\n        while(used < c && !(R.empty())){\n     \
    \       auto [X, C] = getR();\n            if(X >= a) break;\n            popR();\n\
    \            long long tmp = min(c - used, C);\n            pushL(X, tmp);\n \
    \           if(C != tmp) pushR(X, C - tmp);\n            min_y += (a - X) * tmp;\n\
    \            used += tmp;\n        }\n        if(used) pushR(a, used);\n     \
    \   if(c - used) pushL(a, c - used);\n    }\n\n    // add |x - a|  \\____/\n \
    \   void add_abs_xma(long long a, long long c = 1){\n        add_xma(a, c);\n\
    \        add_amx(a, c);\n    }\n\n    // chmin left side \\_/ -> __/\n    void\
    \ chmin_left(){\n        decltype(L){}.swap(L);\n    }\n\n    // chmin right side\
    \ \\_/ -> \\__\n    void chmin_right(){\n        decltype(R){}.swap(R);\n    }\n\
    \n    // return: f(x) = min_y + sum (a - x)_+ + sum (x - a)_+\n    long long f(long\
    \ long x){\n        long long y = min_y;\n        auto LL{L};\n        while(!(LL.empty())){\n\
    \            auto [X, C] = LL.top();\n            X += addL;\n            if(X\
    \ < x) break;\n            y += (X - x) * C;\n            LL.pop();\n        }\n\
    \        auto RR{R};\n        while(!(RR.empty())){\n            auto [X, C] =\
    \ RR.top();\n            X += addR;\n            if(X > x) break;\n          \
    \  y += (x - X) * C;\n            RR.pop();\n        }\n        return y;\n  \
    \  }\n};\n"
  code: "#pragma once\n\nstruct SlopeTrick{\nprivate:\n    struct P{\n        // x:\
    \ \u5EA7\u6A19, c: \u50BE\u304D\u306E\u5909\u5316\n        long long x, c;\n \
    \       P(long long _x, long long _c) : x(_x), c(_c) {}\n        friend inline\
    \ bool operator<(const P &a, const P &b){ return a.x < b.x; }\n        friend\
    \ inline bool operator>(const P &a, const P &b){ return a.x > b.x; }\n    };\n\
    \    long long addL, addR, min_y;\n    priority_queue<P> L;\n    priority_queue<P,\
    \ vector<P>, greater<P>> R;\n    void pushL(long long x, long long c = 1){\n \
    \       L.emplace(x - addL, c);\n    }\n    void pushR(long long x, long long\
    \ c = 1){\n        R.emplace(x - addR, c);\n    }\n    P getL(){\n        return\
    \ P{L.top().x + addL, L.top().c};\n    }\n    P getR(){\n        return P{R.top().x\
    \ + addR, R.top().c};\n    }\n    void popL(){ L.pop(); }\n    void popR(){ R.pop();\
    \ }\n\npublic:\n    SlopeTrick() : addL(0), addR(0), min_y(0) {}\n\n    // return:\
    \ x, f(x)\n    pair<long long, long long> get_min(){\n        long long x;\n \
    \       if(L.empty()){\n            if(R.empty()){\n                x = 0;\n \
    \           }else{\n                x = getR().x;\n            }\n        }else{\n\
    \            x = getL().x;\n        }\n        return make_pair(x, min_y);\n \
    \   }\n\n    void shift_L(long long a){\n        addL += a;\n    }\n\n    void\
    \ shift_R(long long a){\n        addR += a;\n    }\n\n    // f(x) <- f(x - a)\n\
    \    void shift_x(long long a){\n        addL += a, addR += a;\n    }\n\n    //\
    \ f(x) <- f(x) + a\n    void shift_y(long long a){\n        min_y += a;\n    }\n\
    \n    // add (x - a)_+  ____/\n    void add_xma(long long a, long long c = 1){\n\
    \        long long used = 0;\n        while(used < c && !(L.empty())){\n     \
    \       auto [X, C] = getL();\n            if(X <= a) break;\n            popL();\n\
    \            long long tmp = min(c - used, C);\n            pushR(X, tmp);\n \
    \           if(C != tmp) pushL(X, C - tmp);\n            min_y += (X - a) * tmp;\n\
    \            used += tmp;\n        }\n        if(used) pushL(a, used);\n     \
    \   if(c - used) pushR(a, c - used);\n    }\n\n    // add (a - x)_+  \\____\n\
    \    void add_amx(long long a, long long c = 1){\n        long long used = 0;\n\
    \        while(used < c && !(R.empty())){\n            auto [X, C] = getR();\n\
    \            if(X >= a) break;\n            popR();\n            long long tmp\
    \ = min(c - used, C);\n            pushL(X, tmp);\n            if(C != tmp) pushR(X,\
    \ C - tmp);\n            min_y += (a - X) * tmp;\n            used += tmp;\n \
    \       }\n        if(used) pushR(a, used);\n        if(c - used) pushL(a, c -\
    \ used);\n    }\n\n    // add |x - a|  \\____/\n    void add_abs_xma(long long\
    \ a, long long c = 1){\n        add_xma(a, c);\n        add_amx(a, c);\n    }\n\
    \n    // chmin left side \\_/ -> __/\n    void chmin_left(){\n        decltype(L){}.swap(L);\n\
    \    }\n\n    // chmin right side \\_/ -> \\__\n    void chmin_right(){\n    \
    \    decltype(R){}.swap(R);\n    }\n\n    // return: f(x) = min_y + sum (a - x)_+\
    \ + sum (x - a)_+\n    long long f(long long x){\n        long long y = min_y;\n\
    \        auto LL{L};\n        while(!(LL.empty())){\n            auto [X, C] =\
    \ LL.top();\n            X += addL;\n            if(X < x) break;\n          \
    \  y += (X - x) * C;\n            LL.pop();\n        }\n        auto RR{R};\n\
    \        while(!(RR.empty())){\n            auto [X, C] = RR.top();\n        \
    \    X += addR;\n            if(X > x) break;\n            y += (x - X) * C;\n\
    \            RR.pop();\n        }\n        return y;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/slope_trick.hpp
  requiredBy: []
  timestamp: '2023-05-26 19:46:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_2304.test.cpp
documentation_of: lib/data_structure/slope_trick.hpp
layout: document
redirect_from:
- /library/lib/data_structure/slope_trick.hpp
- /library/lib/data_structure/slope_trick.hpp.html
title: lib/data_structure/slope_trick.hpp
---
