#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include <iostream>
#include <string>

#include "../../../lib/string/sa_is.hpp"
#include "../../../lib/string/lcp_array.hpp"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    SA_IS<string> sa(s);
    vector<int> la = LCPArray(s, sa.get());
    long long ans = (long long) s.size() * (s.size() + 1) / 2;
    for(auto x : la){
        ans -= x;
    }
    cout << ans << '\n';
}
