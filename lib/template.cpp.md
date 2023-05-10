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
    \nusing namespace std;\nusing namespace atcoder;\n\n#define overload4(_1, _2,\
    \ _3, _4, name, ...) name\n#define rep1(n) for(int i = 0; i < (int)(n); ++i)\n\
    #define rep2(i, n) for(int i = 0; i < (int)(n); ++i)\n#define rep3(i, a, b) for(int\
    \ i = (a); i < (int)(b); ++i)\n#define rep4(i, a, b, c) for(int i = (a); i < (int)(b);\
    \ i += (c))\n#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\
    \n#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; --i)\n#define ALL(a) a.begin(),\
    \ a.end()\n#define Sort(a) sort(a.begin(), a.end())\n#define RSort(a) sort(a.rbegin(),\
    \ a.rend())\n\ntypedef long long int ll;\ntypedef unsigned long long ul;\ntypedef\
    \ long double ld;\ntypedef vector<int> vi;\ntypedef vector<long long> vll;\ntypedef\
    \ vector<char> vc;\ntypedef vector<string> vst;\ntypedef vector<double> vd;\n\
    typedef vector<long double> vld;\ntypedef pair<long long, long long> P;\n\ntemplate<class\
    \ T> long long sum(const T& a){ return accumulate(a.begin(), a.end(), 0LL); }\n\
    template<class T> auto min(const T& a){ return *min_element(a.begin(), a.end());\
    \ }\ntemplate<class T> auto max(const T& a){ return *max_element(a.begin(), a.end());\
    \ }\n\nconst long long MINF = 0x7fffffffffff;\nconst long long INF = 0x1fffffffffffffff;\n\
    const long long MOD = 998244353;\nconst long double EPS = 1e-9;\nconst long double\
    \ PI = acos(-1);\n \ntemplate<class T> inline bool chmax(T& a, T b) { if (a <\
    \ b) { a = b; return 1; } return 0; }\ntemplate<class T> inline bool chmin(T&\
    \ a, T b) { if (a > b) { a = b; return 1; } return 0; }\n\ntemplate<typename T1,\
    \ typename T2> istream &operator>>(istream &is, pair<T1, T2> &p){ is >> p.first\
    \ >> p.second; return is; }\ntemplate<typename T1, typename T2> ostream &operator<<(ostream\
    \ &os, const pair<T1, T2> &p){ os << \"(\" << p.first << \", \" << p.second <<\
    \ \")\"; return os; }\ntemplate<typename T> istream &operator>>(istream &is, vector<T>\
    \ &v){ for(T &in : v) is >> in; return is; }\ntemplate<typename T> ostream &operator<<(ostream\
    \ &os, const vector<T> &v){ for(int i = 0; i < (int) v.size(); ++i){ os << v[i]\
    \ << (i + 1 != (int) v.size() ? \" \" : \"\"); } return os; }\ntemplate <typename\
    \ T, typename S> ostream &operator<<(ostream &os, const map<T, S> &mp){ for(auto\
    \ &[key, val] : mp){ os << key << \":\" << val << \" \"; } return os; }\ntemplate\
    \ <typename T> ostream &operator<<(ostream &os, const set<T> &st){ auto itr =\
    \ st.begin(); for(int i = 0; i < (int)st.size(); ++i){ os << *itr << (i + 1 !=\
    \ (int)st.size() ? \" \" : \"\"); itr++; } return os; }\ntemplate <typename T>\
    \ ostream &operator<<(ostream &os, const multiset<T> &st){ auto itr = st.begin();\
    \ for(int i = 0; i < (int)st.size(); ++i){ os << *itr << (i + 1 != (int)st.size()\
    \ ? \" \" : \"\"); itr++; } return os; }\ntemplate <typename T> ostream &operator<<(ostream\
    \ &os, queue<T> q){ while(q.size()){ os << q.front() << \" \"; q.pop(); } return\
    \ os; }\ntemplate <typename T> ostream &operator<<(ostream &os, deque<T> q){ while(q.size()){\
    \ os << q.front() << \" \"; q.pop_front(); } return os; }\ntemplate <typename\
    \ T> ostream &operator<<(ostream &os, stack<T> st){ while(st.size()){ os << st.top()\
    \ << \" \"; st.pop(); } return os; }\ntemplate <class T, class Container, class\
    \ Compare> ostream &operator<<(ostream &os, priority_queue<T, Container, Compare>\
    \ pq){ while(pq.size()){ os << pq.top() << \" \"; pq.pop(); } return os; }\n\n\
    template<class T, class U> inline T vin(T& vec, U n) { vec.resize(n); for(int\
    \ i = 0; i < (int) n; ++i) cin >> vec[i]; return vec; }\ntemplate<class T> inline\
    \ void vout(T vec, string s = \"\\n\"){ for(auto x : vec) cout << x << s; }\n\
    template<class... T> void in(T&... a){ (cin >> ... >> a); }\nvoid out(){ cout\
    \ << '\\n'; }\ntemplate<class T, class... Ts> void out(const T& a, const Ts&...\
    \ b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\\n'; }\ntemplate<class\
    \ T, class U> void inGraph(vector<vector<T>>& G, U n, U m, bool directed = false){\
    \ G.resize(n); for(int i = 0; i < m; ++i){ int a, b; cin >> a >> b; a--, b--;\
    \ G[a].push_back(b); if(!directed) G[b].push_back(a); } }\n\nll n;\nvll a;\n\n\
    void input(){\n    in(n);\n    vin(a, n);\n}\n \nvoid solve(){\n    \n}\n\nint\
    \ main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    cout <<\
    \ fixed << setprecision(20);\n    \n    input();\n    solve();\n}\n"
  code: "#include <bits/stdc++.h>\n#include <atcoder/all>\n\nusing namespace std;\n\
    using namespace atcoder;\n\n#define overload4(_1, _2, _3, _4, name, ...) name\n\
    #define rep1(n) for(int i = 0; i < (int)(n); ++i)\n#define rep2(i, n) for(int\
    \ i = 0; i < (int)(n); ++i)\n#define rep3(i, a, b) for(int i = (a); i < (int)(b);\
    \ ++i)\n#define rep4(i, a, b, c) for(int i = (a); i < (int)(b); i += (c))\n#define\
    \ rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\n#define\
    \ rrep(i,n) for(int i = (int)(n) - 1; i >= 0; --i)\n#define ALL(a) a.begin(),\
    \ a.end()\n#define Sort(a) sort(a.begin(), a.end())\n#define RSort(a) sort(a.rbegin(),\
    \ a.rend())\n\ntypedef long long int ll;\ntypedef unsigned long long ul;\ntypedef\
    \ long double ld;\ntypedef vector<int> vi;\ntypedef vector<long long> vll;\ntypedef\
    \ vector<char> vc;\ntypedef vector<string> vst;\ntypedef vector<double> vd;\n\
    typedef vector<long double> vld;\ntypedef pair<long long, long long> P;\n\ntemplate<class\
    \ T> long long sum(const T& a){ return accumulate(a.begin(), a.end(), 0LL); }\n\
    template<class T> auto min(const T& a){ return *min_element(a.begin(), a.end());\
    \ }\ntemplate<class T> auto max(const T& a){ return *max_element(a.begin(), a.end());\
    \ }\n\nconst long long MINF = 0x7fffffffffff;\nconst long long INF = 0x1fffffffffffffff;\n\
    const long long MOD = 998244353;\nconst long double EPS = 1e-9;\nconst long double\
    \ PI = acos(-1);\n \ntemplate<class T> inline bool chmax(T& a, T b) { if (a <\
    \ b) { a = b; return 1; } return 0; }\ntemplate<class T> inline bool chmin(T&\
    \ a, T b) { if (a > b) { a = b; return 1; } return 0; }\n\ntemplate<typename T1,\
    \ typename T2> istream &operator>>(istream &is, pair<T1, T2> &p){ is >> p.first\
    \ >> p.second; return is; }\ntemplate<typename T1, typename T2> ostream &operator<<(ostream\
    \ &os, const pair<T1, T2> &p){ os << \"(\" << p.first << \", \" << p.second <<\
    \ \")\"; return os; }\ntemplate<typename T> istream &operator>>(istream &is, vector<T>\
    \ &v){ for(T &in : v) is >> in; return is; }\ntemplate<typename T> ostream &operator<<(ostream\
    \ &os, const vector<T> &v){ for(int i = 0; i < (int) v.size(); ++i){ os << v[i]\
    \ << (i + 1 != (int) v.size() ? \" \" : \"\"); } return os; }\ntemplate <typename\
    \ T, typename S> ostream &operator<<(ostream &os, const map<T, S> &mp){ for(auto\
    \ &[key, val] : mp){ os << key << \":\" << val << \" \"; } return os; }\ntemplate\
    \ <typename T> ostream &operator<<(ostream &os, const set<T> &st){ auto itr =\
    \ st.begin(); for(int i = 0; i < (int)st.size(); ++i){ os << *itr << (i + 1 !=\
    \ (int)st.size() ? \" \" : \"\"); itr++; } return os; }\ntemplate <typename T>\
    \ ostream &operator<<(ostream &os, const multiset<T> &st){ auto itr = st.begin();\
    \ for(int i = 0; i < (int)st.size(); ++i){ os << *itr << (i + 1 != (int)st.size()\
    \ ? \" \" : \"\"); itr++; } return os; }\ntemplate <typename T> ostream &operator<<(ostream\
    \ &os, queue<T> q){ while(q.size()){ os << q.front() << \" \"; q.pop(); } return\
    \ os; }\ntemplate <typename T> ostream &operator<<(ostream &os, deque<T> q){ while(q.size()){\
    \ os << q.front() << \" \"; q.pop_front(); } return os; }\ntemplate <typename\
    \ T> ostream &operator<<(ostream &os, stack<T> st){ while(st.size()){ os << st.top()\
    \ << \" \"; st.pop(); } return os; }\ntemplate <class T, class Container, class\
    \ Compare> ostream &operator<<(ostream &os, priority_queue<T, Container, Compare>\
    \ pq){ while(pq.size()){ os << pq.top() << \" \"; pq.pop(); } return os; }\n\n\
    template<class T, class U> inline T vin(T& vec, U n) { vec.resize(n); for(int\
    \ i = 0; i < (int) n; ++i) cin >> vec[i]; return vec; }\ntemplate<class T> inline\
    \ void vout(T vec, string s = \"\\n\"){ for(auto x : vec) cout << x << s; }\n\
    template<class... T> void in(T&... a){ (cin >> ... >> a); }\nvoid out(){ cout\
    \ << '\\n'; }\ntemplate<class T, class... Ts> void out(const T& a, const Ts&...\
    \ b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\\n'; }\ntemplate<class\
    \ T, class U> void inGraph(vector<vector<T>>& G, U n, U m, bool directed = false){\
    \ G.resize(n); for(int i = 0; i < m; ++i){ int a, b; cin >> a >> b; a--, b--;\
    \ G[a].push_back(b); if(!directed) G[b].push_back(a); } }\n\nll n;\nvll a;\n\n\
    void input(){\n    in(n);\n    vin(a, n);\n}\n \nvoid solve(){\n    \n}\n\nint\
    \ main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    cout <<\
    \ fixed << setprecision(20);\n    \n    input();\n    solve();\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/template.cpp
  requiredBy: []
  timestamp: '2022-12-22 03:26:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/template.cpp
layout: document
redirect_from:
- /library/lib/template.cpp
- /library/lib/template.cpp.html
title: lib/template.cpp
---