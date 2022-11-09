#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/string/manacher.hpp"

int main(){
    string s; cin >> s;
    int n = s.size();
    string t = "";
    for(int i = 0; i < n; i++){
        t += s[i];
        if(i < n - 1) t += '$';
    }
    vector<int> m1 = manacher(s), m2 = manacher(t);
    for(int i = 0; i < 2 * n - 1; i++){
        int ans;
        if(i % 2 == 0){
            ans = 2 * m1[i / 2] - 1;
        }else{
            ans = m2[i] / 2;
        }
        if(i >= 1) cout << " ";
        cout << ans;
    }
    cout << "\n";
}