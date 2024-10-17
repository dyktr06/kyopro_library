#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/string/run_enumerate.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    auto ans = run_enumerate(s);
    cout << ans.size() << '\n';
    for(auto [len, l, r] : ans){
        cout << len << ' ' << l << ' ' << r << '\n';
    }
}
