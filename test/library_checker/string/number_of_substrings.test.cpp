#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/string/suffix_array.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    long long n = s.size();
    SuffixArray sa(s);
    LCPArray la(sa);
    long long ans = n * (n - 1) / 2;
    for(auto x : la.LCP){
        ans -= x;
    }
    cout << ans << "\n";
}
