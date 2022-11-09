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
  bundledCode: "#line 1 \"lib/template.cpp\"\n#include <bits/stdc++.h>\n#include <atcoder/all>\n\
    \nusing namespace std;\nusing namespace atcoder;\n\n#define rep(i,n) for(int i\
    \ = 0; i < (int)(n); ++i)\n#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0;\
    \ --i)\n#define ALL(a) a.begin(), a.end()\n#define Sort(a) sort(a.begin(), a.end())\n\
    #define RSort(a) sort(a.rbegin(), a.rend())\n\ntypedef long long int ll;\ntypedef\
    \ unsigned long long ul;\ntypedef long double ld;\ntypedef vector<int> vi;\ntypedef\
    \ vector<long long> vll;\ntypedef vector<char> vc;\ntypedef vector<string> vst;\n\
    typedef vector<double> vd;\ntypedef pair<long long, long long> P;\n\nconst long\
    \ long INF = 0x1fffffffffffffff;\nconst long long MOD = 998244353;\nconst long\
    \ double PI = acos(-1);\n \ntemplate<class T> inline bool chmax(T& a, T b) { if\
    \ (a < b) { a = b; return 1; } return 0; }\ntemplate<class T> inline bool chmin(T&\
    \ a, T b) { if (a > b) { a = b; return 1; } return 0; }\ntemplate<class T, class\
    \ U> inline T vin(T& vec, U n) { vec.resize(n); for(int i = 0; i < (int) n; ++i)\
    \ cin >> vec[i]; return vec; }\ntemplate<class T> inline void vout(T vec, string\
    \ s = \"\\n\"){ for(auto x : vec) cout << x << s; }\ntemplate<class... T> void\
    \ in(T&... a){ (cin >> ... >> a); }\nvoid out(){ cout << '\\n'; }\ntemplate<class\
    \ T, class... Ts> void out(const T& a, const Ts&... b){ cout << a; (cout << ...\
    \ << (cout << ' ', b)); cout << '\\n'; }\ntemplate<class T, class U> void inGraph(vector<vector<T>>&\
    \ G, U n, U m, bool directed = false){ G.resize(n); for(int i = 0; i < m; i++){\
    \ int a, b; cin >> a >> b; a--, b--; G[a].push_back(b); if(!directed) G[b].push_back(a);\
    \ } }\n\nll n;\nvll a;\n\nvoid input(){\n    in(n);\n    vin(a, n);\n}\n \nvoid\
    \ solve(){\n    \n}\n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    \n    input();\n    solve();\n}\n"
  code: "#include <bits/stdc++.h>\n#include <atcoder/all>\n\nusing namespace std;\n\
    using namespace atcoder;\n\n#define rep(i,n) for(int i = 0; i < (int)(n); ++i)\n\
    #define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; --i)\n#define ALL(a) a.begin(),\
    \ a.end()\n#define Sort(a) sort(a.begin(), a.end())\n#define RSort(a) sort(a.rbegin(),\
    \ a.rend())\n\ntypedef long long int ll;\ntypedef unsigned long long ul;\ntypedef\
    \ long double ld;\ntypedef vector<int> vi;\ntypedef vector<long long> vll;\ntypedef\
    \ vector<char> vc;\ntypedef vector<string> vst;\ntypedef vector<double> vd;\n\
    typedef pair<long long, long long> P;\n\nconst long long INF = 0x1fffffffffffffff;\n\
    const long long MOD = 998244353;\nconst long double PI = acos(-1);\n \ntemplate<class\
    \ T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;\
    \ }\ntemplate<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return\
    \ 1; } return 0; }\ntemplate<class T, class U> inline T vin(T& vec, U n) { vec.resize(n);\
    \ for(int i = 0; i < (int) n; ++i) cin >> vec[i]; return vec; }\ntemplate<class\
    \ T> inline void vout(T vec, string s = \"\\n\"){ for(auto x : vec) cout << x\
    \ << s; }\ntemplate<class... T> void in(T&... a){ (cin >> ... >> a); }\nvoid out(){\
    \ cout << '\\n'; }\ntemplate<class T, class... Ts> void out(const T& a, const\
    \ Ts&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\\n'; }\n\
    template<class T, class U> void inGraph(vector<vector<T>>& G, U n, U m, bool directed\
    \ = false){ G.resize(n); for(int i = 0; i < m; i++){ int a, b; cin >> a >> b;\
    \ a--, b--; G[a].push_back(b); if(!directed) G[b].push_back(a); } }\n\nll n;\n\
    vll a;\n\nvoid input(){\n    in(n);\n    vin(a, n);\n}\n \nvoid solve(){\n   \
    \ \n}\n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    \n    input();\n    solve();\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/template.cpp
  requiredBy: []
  timestamp: '2022-10-19 03:16:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/template.cpp
layout: document
redirect_from:
- /library/lib/template.cpp
- /library/lib/template.cpp.html
title: lib/template.cpp
---
