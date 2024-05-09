#define PROBLEM "https://judge.yosupo.jp/problem/wildcard_pattern_matching"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/string/wildcard_pattern_matching.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    vector<bool> res = wildcardPatternMatching(s, t);
    string ans = "";
    for(auto e : res){
        ans += e ? '1' : '0';
    }
    cout << ans << "\n";
}
