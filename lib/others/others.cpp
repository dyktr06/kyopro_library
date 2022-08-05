#include <bits/stdc++.h>

using namespace std;

// aよりb が大き/小さかったら、aをbに置き換える
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 複数の入力を受け取る
template<class... T>
void in(T&... a){
    (cin >> ... >> a);
}

// 複数の出力を行う
void out(){
    cout << '\n';
}
template<class T, class... Ts>
void out(const T& a, const Ts&... b){
    cout << a;
    (cout << ... << (cout << ' ', b));
    cout << '\n';
}

// n個の入力をvecの中に格納
template<class T, class U> inline 
T vin(T& vec, U n){
    vec.resize(n);
    for(int i = 0; i < (int) n; ++i) cin >> vec[i]; 
    return vec;
}

// vecの要素をすべて出力
template<class T> inline 
void vout(T vec, string s = "\n"){
    for(auto x : vec) cout << x << s;
}