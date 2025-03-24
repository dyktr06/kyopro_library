#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(int i = 0; i < (int)(n); ++i)
#define rep2(i, n) for(int i = 0; i < (int)(n); ++i)
#define rep3(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep4(i, a, b, c) for(int i = (a); i < (int)(b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
#define Sort(a) (sort((a).begin(), (a).end()))
#define RSort(a) (sort((a).rbegin(), (a).rend()))
#define UNIQUE(a) (a.erase(unique((a).begin(), (a).end()), (a).end()))

using i64 = int64_t;
using i128 = __int128_t;

using ll = long long;
using ul = unsigned long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long>;
using vull = vector<unsigned long long>;
using vc = vector<char>;
using vst = vector<string>;
using vd = vector<double>;
using vld = vector<long double>;
using P = pair<long long, long long>;

template<class T> long long sum(const T &a){ return accumulate(a.begin(), a.end(), 0LL); }
template<class T> auto min(const T &a){ return *min_element(a.begin(), a.end()); }
template<class T> auto max(const T &a){ return *max_element(a.begin(), a.end()); }

const long long MINF = 0x7fffffffffff;
const long long INF = 0x1fffffffffffffff;
const long long MOD = 998244353;
const long double EPS = 1e-9;
const long double PI = acos(-1);

template<class T> inline bool chmax(T &a, T b) { if(a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if(a > b) { a = b; return 1; } return 0; }

template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p){ is >> p.first >> p.second; return is; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){ os << "(" << p.first << ", " << p.second << ")"; return os; }
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for(T &in : v) is >> in; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v){ for(int i = 0; i < (int) v.size(); ++i){ os << v[i] << (i + 1 != (int) v.size() ? " " : ""); } return os; }
template <typename T, typename S> ostream &operator<<(ostream &os, const map<T, S> &mp){ for(auto &[key, val] : mp){ os << key << ":" << val << " "; } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &st){ auto itr = st.begin(); for(int i = 0; i < (int) st.size(); ++i){ os << *itr << (i + 1 != (int) st.size() ? " " : ""); itr++; } return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &st){ auto itr = st.begin(); for(int i = 0; i < (int) st.size(); ++i){ os << *itr << (i + 1 != (int) st.size() ? " " : ""); itr++; } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> q){ while(q.size()){ os << q.front() << " "; q.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, deque<T> q){ while(q.size()){ os << q.front() << " "; q.pop_front(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> st){ while(st.size()){ os << st.top() << " "; st.pop(); } return os; }
template <class T, class Container, class Compare> ostream &operator<<(ostream &os, priority_queue<T, Container, Compare> pq){ while(pq.size()){ os << pq.top() << " "; pq.pop(); } return os; }

template<class T, class U>
void inGraph(vector<vector<T>> &G, U n, U m, bool directed = true, bool zero_index = true){
    G.resize(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(!zero_index) a--, b--;
        G[a].push_back(b);
        if(!directed) G[b].push_back(a);
    }
}

template <typename T>
long long binary_search(long long ok, long long ng, T check){
    while(abs(ok - ng) > 1){
        long long mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

template <typename T>
long double binary_search_real(long double ok, long double ng, T check, int iter = 100){
    for(int i = 0; i < iter; ++i){
        long double mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

long long trisum(long long a, long long b){
    if(a > b) return 0;
    long long res = ((b - a + 1) * (a + b)) / 2;
    return res;
}

template <typename T>
T intpow(T x, int n){
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x);
        (x *= x);
        n >>= 1;
    }
    return ret;
}

template <typename T>
T getDivision(T a, T b){
    if(b == 0) return -1;
    if(a >= 0 && b > 0){
        return a / b;
    } else if(a < 0 && b > 0){
        return a / b - (a % b != 0);
    } else if(a >= 0 && b < 0){
        return a / b;
    } else{
        return a / b + (a % b != 0);
    }
}

template <typename T>
T getReminder(T a, T b){
    if(b == 0) return -1;
    if(a >= 0 && b > 0){
        return a % b;
    } else if(a < 0 && b > 0){
        return ((a % b) + b) % b;
    } else if(a >= 0 && b < 0){
        return a % b;
    } else{
        return (abs(b) - abs(a % b)) % b;
    }
}

template<class T, class U> inline T vin(T &vec, U n) { vec.resize(n); for(int i = 0; i < (int) n; ++i) cin >> vec[i]; return vec; }
template<class T> inline void vout(T vec, string s = "\n"){ for(auto x : vec) cout << x << s; }
template<class... T> void in(T&... a){ (cin >> ... >> a); }
void out(){ cout << '\n'; }
template<class T, class... Ts> void out(const T &a, const Ts&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
void fout(){ cout << endl; }
template<class T, class... Ts> void fout(const T &a, const Ts&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << endl; }
void debug(){ cerr << '\n'; }
template<class T, class... Ts> void debug(const T &a, const Ts&... b){ cerr << a; (cerr << ... << (cerr << ' ', b)); cerr << '\n'; }

ll T;

void input(){
    in(T);
}

void solve(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

    T = 1;
    // input();
    while(T--) solve();
}
