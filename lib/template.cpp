#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()
#define Sort(a) sort(a.begin(), a.end())
#define RSort(a) sort(a.rbegin(), a.rend())

typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<string> vst;
typedef vector<double> vd;
typedef pair<long long, long long> P;

const long long INF = 0x1fffffffffffffff;
const long long MOD = 1000000007;
const long double PI = acos(-1);
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T, class U> inline T vin(T& vec, U n) { vec.resize(n); for(int i = 0; i < (int) n; ++i) cin >> vec[i]; return vec; }
template<class T> inline void vout(T vec, string s = "\n"){ for(auto x : vec) cout << x << s; }
template<class... T> void in(T&... a){ (cin >> ... >> a); }
void out(){ cout << '\n'; }
template<class T, class... Ts> void out(const T& a, const Ts&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T, class U> void inGraph(vector<vector<T>>& G, U n, U m, bool directed = false){ G.resize(n); for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; a--, b--; G[a].push_back(b); if(!directed) G[b].push_back(a); } }

ll n;
vll a;

void input(){
    in(n);
    vin(a, n);
}
 
void solve(){
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solve();
}