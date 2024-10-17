#define PROBLEM "https://judge.yosupo.jp/problem/lyndon_factorization"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/string/lyndon_factorization.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    auto ans = lyndon_factorization(s);
    int len = ans.size();
    for(int i = 0; i < len; i++){
        if(i >= 1) cout << ' ';
        cout << ans[i];
    }
}
