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
    \n#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; --i)\n#define ALL(a) (a).begin(),\
    \ (a).end()\n#define Sort(a) (sort((a).begin(), (a).end()))\n#define RSort(a)\
    \ (sort((a).rbegin(), (a).rend()))\n#define UNIQUE(a) (a.erase(unique((a).begin(),\
    \ (a).end()), (a).end()))\n\nusing i64 = int64_t;\nusing i128 = __int128_t;\n\n\
    using ll = long long;\nusing ul = unsigned long long;\nusing ld = long double;\n\
    using vi = vector<int>;\nusing vll = vector<long long>;\nusing vc = vector<char>;\n\
    using vst = vector<string>;\nusing vd = vector<double>;\nusing vld = vector<long\
    \ double>;\nusing P = pair<long long, long long>;\n\ntemplate<class T> long long\
    \ sum(const T &a){ return accumulate(a.begin(), a.end(), 0LL); }\ntemplate<class\
    \ T> auto min(const T &a){ return *min_element(a.begin(), a.end()); }\ntemplate<class\
    \ T> auto max(const T &a){ return *max_element(a.begin(), a.end()); }\n\nconst\
    \ long long MINF = 0x7fffffffffff;\nconst long long INF = 0x1fffffffffffffff;\n\
    const long long MOD = 998244353;\nconst long double EPS = 1e-9;\nconst long double\
    \ PI = acos(-1);\n\ntemplate<class T> inline bool chmax(T &a, T b) { if(a < b)\
    \ { a = b; return 1; } return 0; }\ntemplate<class T> inline bool chmin(T &a,\
    \ T b) { if(a > b) { a = b; return 1; } return 0; }\n\ntemplate<typename T1, typename\
    \ T2> istream &operator>>(istream &is, pair<T1, T2> &p){ is >> p.first >> p.second;\
    \ return is; }\ntemplate<typename T1, typename T2> ostream &operator<<(ostream\
    \ &os, const pair<T1, T2> &p){ os << \"(\" << p.first << \", \" << p.second <<\
    \ \")\"; return os; }\ntemplate<typename T> istream &operator>>(istream &is, vector<T>\
    \ &v){ for(T &in : v) is >> in; return is; }\ntemplate<typename T> ostream &operator<<(ostream\
    \ &os, const vector<T> &v){ for(int i = 0; i < (int) v.size(); ++i){ os << v[i]\
    \ << (i + 1 != (int) v.size() ? \" \" : \"\"); } return os; }\ntemplate <typename\
    \ T, typename S> ostream &operator<<(ostream &os, const map<T, S> &mp){ for(auto\
    \ &[key, val] : mp){ os << key << \":\" << val << \" \"; } return os; }\ntemplate\
    \ <typename T> ostream &operator<<(ostream &os, const set<T> &st){ auto itr =\
    \ st.begin(); for(int i = 0; i < (int) st.size(); ++i){ os << *itr << (i + 1 !=\
    \ (int) st.size() ? \" \" : \"\"); itr++; } return os; }\ntemplate <typename T>\
    \ ostream &operator<<(ostream &os, const multiset<T> &st){ auto itr = st.begin();\
    \ for(int i = 0; i < (int) st.size(); ++i){ os << *itr << (i + 1 != (int) st.size()\
    \ ? \" \" : \"\"); itr++; } return os; }\ntemplate <typename T> ostream &operator<<(ostream\
    \ &os, queue<T> q){ while(q.size()){ os << q.front() << \" \"; q.pop(); } return\
    \ os; }\ntemplate <typename T> ostream &operator<<(ostream &os, deque<T> q){ while(q.size()){\
    \ os << q.front() << \" \"; q.pop_front(); } return os; }\ntemplate <typename\
    \ T> ostream &operator<<(ostream &os, stack<T> st){ while(st.size()){ os << st.top()\
    \ << \" \"; st.pop(); } return os; }\ntemplate <class T, class Container, class\
    \ Compare> ostream &operator<<(ostream &os, priority_queue<T, Container, Compare>\
    \ pq){ while(pq.size()){ os << pq.top() << \" \"; pq.pop(); } return os; }\n\n\
    template<class T, class U>\nvoid inGraph(vector<vector<T>> &G, U n, U m, bool\
    \ directed = true, bool zero_index = true){\n    G.resize(n);\n    for(int i =\
    \ 0; i < m; i++){\n        int a, b;\n        cin >> a >> b;\n        if(!zero_index)\
    \ a--, b--;\n        G[a].push_back(b);\n        if(!directed) G[b].push_back(a);\n\
    \    }\n}\n\ntemplate <typename T>\nlong long binary_search(long long ok, long\
    \ long ng, T check){\n    while(abs(ok - ng) > 1){\n        long long mid = (ok\
    \ + ng) / 2;\n        if(check(mid)) ok = mid;\n        else ng = mid;\n    }\n\
    \    return ok;\n}\n\ntemplate <typename T>\nlong double binary_search_real(long\
    \ double ok, long double ng, T check, int iter = 100){\n    for(int i = 0; i <\
    \ iter; ++i){\n        long double mid = (ok + ng) / 2;\n        if(check(mid))\
    \ ok = mid;\n        else ng = mid;\n    }\n    return ok;\n}\n\ntemplate <typename\
    \ T>\nlong long trisum(T a, T b){\n    long long res = ((b - a + 1) * (a + b))\
    \ / 2;\n    return res;\n}\n\ntemplate <typename T>\nT intpow(T x, int n){\n \
    \   T ret = 1;\n    while(n > 0) {\n        if(n & 1) (ret *= x);\n        (x\
    \ *= x);\n        n >>= 1;\n    }\n    return ret;\n}\n\ntemplate <typename T>\n\
    T getReminder(T a, T b){\n    if(b == 0) return -1;\n    if(a >= 0 && b > 0){\n\
    \        return a % b;\n    } else if(a < 0 && b > 0){\n        return ((a % b)\
    \ + b) % b;\n    } else if(a >= 0 && b < 0){\n        return a % b;\n    } else{\n\
    \        return (abs(b) - abs(a % b)) % b;\n    }\n}\n\ntemplate<class T, class\
    \ U> inline T vin(T &vec, U n) { vec.resize(n); for(int i = 0; i < (int) n; ++i)\
    \ cin >> vec[i]; return vec; }\ntemplate<class T> inline void vout(T vec, string\
    \ s = \"\\n\"){ for(auto x : vec) cout << x << s; }\ntemplate<class... T> void\
    \ in(T&... a){ (cin >> ... >> a); }\nvoid out(){ cout << '\\n'; }\ntemplate<class\
    \ T, class... Ts> void out(const T &a, const Ts&... b){ cout << a; (cout << ...\
    \ << (cout << ' ', b)); cout << '\\n'; }\nvoid fout(){ cout << endl; }\ntemplate<class\
    \ T, class... Ts> void fout(const T &a, const Ts&... b){ cout << a; (cout << ...\
    \ << (cout << ' ', b)); cout << endl; }\nvoid debug(){ cerr << '\\n'; }\ntemplate<class\
    \ T, class... Ts> void debug(const T &a, const Ts&... b){ cerr << a; (cerr <<\
    \ ... << (cerr << ' ', b)); cerr << '\\n'; }\n\nll T;\n\nvoid input(){\n    in(T);\n\
    }\n\nvoid solve(){\n\n}\n\nint main(){\n    ios::sync_with_stdio(false);\n   \
    \ cin.tie(nullptr);\n    cout << fixed << setprecision(20);\n\n    T = 1;\n  \
    \  // input();\n    while(T--) solve();\n}\n"
  code: "#include <bits/stdc++.h>\n#include <atcoder/all>\n\nusing namespace std;\n\
    using namespace atcoder;\n\n#define overload4(_1, _2, _3, _4, name, ...) name\n\
    #define rep1(n) for(int i = 0; i < (int)(n); ++i)\n#define rep2(i, n) for(int\
    \ i = 0; i < (int)(n); ++i)\n#define rep3(i, a, b) for(int i = (a); i < (int)(b);\
    \ ++i)\n#define rep4(i, a, b, c) for(int i = (a); i < (int)(b); i += (c))\n#define\
    \ rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\n#define\
    \ rrep(i,n) for(int i = (int)(n) - 1; i >= 0; --i)\n#define ALL(a) (a).begin(),\
    \ (a).end()\n#define Sort(a) (sort((a).begin(), (a).end()))\n#define RSort(a)\
    \ (sort((a).rbegin(), (a).rend()))\n#define UNIQUE(a) (a.erase(unique((a).begin(),\
    \ (a).end()), (a).end()))\n\nusing i64 = int64_t;\nusing i128 = __int128_t;\n\n\
    using ll = long long;\nusing ul = unsigned long long;\nusing ld = long double;\n\
    using vi = vector<int>;\nusing vll = vector<long long>;\nusing vc = vector<char>;\n\
    using vst = vector<string>;\nusing vd = vector<double>;\nusing vld = vector<long\
    \ double>;\nusing P = pair<long long, long long>;\n\ntemplate<class T> long long\
    \ sum(const T &a){ return accumulate(a.begin(), a.end(), 0LL); }\ntemplate<class\
    \ T> auto min(const T &a){ return *min_element(a.begin(), a.end()); }\ntemplate<class\
    \ T> auto max(const T &a){ return *max_element(a.begin(), a.end()); }\n\nconst\
    \ long long MINF = 0x7fffffffffff;\nconst long long INF = 0x1fffffffffffffff;\n\
    const long long MOD = 998244353;\nconst long double EPS = 1e-9;\nconst long double\
    \ PI = acos(-1);\n\ntemplate<class T> inline bool chmax(T &a, T b) { if(a < b)\
    \ { a = b; return 1; } return 0; }\ntemplate<class T> inline bool chmin(T &a,\
    \ T b) { if(a > b) { a = b; return 1; } return 0; }\n\ntemplate<typename T1, typename\
    \ T2> istream &operator>>(istream &is, pair<T1, T2> &p){ is >> p.first >> p.second;\
    \ return is; }\ntemplate<typename T1, typename T2> ostream &operator<<(ostream\
    \ &os, const pair<T1, T2> &p){ os << \"(\" << p.first << \", \" << p.second <<\
    \ \")\"; return os; }\ntemplate<typename T> istream &operator>>(istream &is, vector<T>\
    \ &v){ for(T &in : v) is >> in; return is; }\ntemplate<typename T> ostream &operator<<(ostream\
    \ &os, const vector<T> &v){ for(int i = 0; i < (int) v.size(); ++i){ os << v[i]\
    \ << (i + 1 != (int) v.size() ? \" \" : \"\"); } return os; }\ntemplate <typename\
    \ T, typename S> ostream &operator<<(ostream &os, const map<T, S> &mp){ for(auto\
    \ &[key, val] : mp){ os << key << \":\" << val << \" \"; } return os; }\ntemplate\
    \ <typename T> ostream &operator<<(ostream &os, const set<T> &st){ auto itr =\
    \ st.begin(); for(int i = 0; i < (int) st.size(); ++i){ os << *itr << (i + 1 !=\
    \ (int) st.size() ? \" \" : \"\"); itr++; } return os; }\ntemplate <typename T>\
    \ ostream &operator<<(ostream &os, const multiset<T> &st){ auto itr = st.begin();\
    \ for(int i = 0; i < (int) st.size(); ++i){ os << *itr << (i + 1 != (int) st.size()\
    \ ? \" \" : \"\"); itr++; } return os; }\ntemplate <typename T> ostream &operator<<(ostream\
    \ &os, queue<T> q){ while(q.size()){ os << q.front() << \" \"; q.pop(); } return\
    \ os; }\ntemplate <typename T> ostream &operator<<(ostream &os, deque<T> q){ while(q.size()){\
    \ os << q.front() << \" \"; q.pop_front(); } return os; }\ntemplate <typename\
    \ T> ostream &operator<<(ostream &os, stack<T> st){ while(st.size()){ os << st.top()\
    \ << \" \"; st.pop(); } return os; }\ntemplate <class T, class Container, class\
    \ Compare> ostream &operator<<(ostream &os, priority_queue<T, Container, Compare>\
    \ pq){ while(pq.size()){ os << pq.top() << \" \"; pq.pop(); } return os; }\n\n\
    template<class T, class U>\nvoid inGraph(vector<vector<T>> &G, U n, U m, bool\
    \ directed = true, bool zero_index = true){\n    G.resize(n);\n    for(int i =\
    \ 0; i < m; i++){\n        int a, b;\n        cin >> a >> b;\n        if(!zero_index)\
    \ a--, b--;\n        G[a].push_back(b);\n        if(!directed) G[b].push_back(a);\n\
    \    }\n}\n\ntemplate <typename T>\nlong long binary_search(long long ok, long\
    \ long ng, T check){\n    while(abs(ok - ng) > 1){\n        long long mid = (ok\
    \ + ng) / 2;\n        if(check(mid)) ok = mid;\n        else ng = mid;\n    }\n\
    \    return ok;\n}\n\ntemplate <typename T>\nlong double binary_search_real(long\
    \ double ok, long double ng, T check, int iter = 100){\n    for(int i = 0; i <\
    \ iter; ++i){\n        long double mid = (ok + ng) / 2;\n        if(check(mid))\
    \ ok = mid;\n        else ng = mid;\n    }\n    return ok;\n}\n\ntemplate <typename\
    \ T>\nlong long trisum(T a, T b){\n    long long res = ((b - a + 1) * (a + b))\
    \ / 2;\n    return res;\n}\n\ntemplate <typename T>\nT intpow(T x, int n){\n \
    \   T ret = 1;\n    while(n > 0) {\n        if(n & 1) (ret *= x);\n        (x\
    \ *= x);\n        n >>= 1;\n    }\n    return ret;\n}\n\ntemplate <typename T>\n\
    T getReminder(T a, T b){\n    if(b == 0) return -1;\n    if(a >= 0 && b > 0){\n\
    \        return a % b;\n    } else if(a < 0 && b > 0){\n        return ((a % b)\
    \ + b) % b;\n    } else if(a >= 0 && b < 0){\n        return a % b;\n    } else{\n\
    \        return (abs(b) - abs(a % b)) % b;\n    }\n}\n\ntemplate<class T, class\
    \ U> inline T vin(T &vec, U n) { vec.resize(n); for(int i = 0; i < (int) n; ++i)\
    \ cin >> vec[i]; return vec; }\ntemplate<class T> inline void vout(T vec, string\
    \ s = \"\\n\"){ for(auto x : vec) cout << x << s; }\ntemplate<class... T> void\
    \ in(T&... a){ (cin >> ... >> a); }\nvoid out(){ cout << '\\n'; }\ntemplate<class\
    \ T, class... Ts> void out(const T &a, const Ts&... b){ cout << a; (cout << ...\
    \ << (cout << ' ', b)); cout << '\\n'; }\nvoid fout(){ cout << endl; }\ntemplate<class\
    \ T, class... Ts> void fout(const T &a, const Ts&... b){ cout << a; (cout << ...\
    \ << (cout << ' ', b)); cout << endl; }\nvoid debug(){ cerr << '\\n'; }\ntemplate<class\
    \ T, class... Ts> void debug(const T &a, const Ts&... b){ cerr << a; (cerr <<\
    \ ... << (cerr << ' ', b)); cerr << '\\n'; }\n\nll T;\n\nvoid input(){\n    in(T);\n\
    }\n\nvoid solve(){\n\n}\n\nint main(){\n    ios::sync_with_stdio(false);\n   \
    \ cin.tie(nullptr);\n    cout << fixed << setprecision(20);\n\n    T = 1;\n  \
    \  // input();\n    while(T--) solve();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/template.cpp
  requiredBy: []
  timestamp: '2024-12-15 12:48:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/template.cpp
layout: document
redirect_from:
- /library/lib/template.cpp
- /library/lib/template.cpp.html
title: lib/template.cpp
---
