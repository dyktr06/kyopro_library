#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/string/suffix_array.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    SuffixArray sa(s);
    for(int i = 0; i < (int) s.size(); i++){
        if(i >= 1) cout << " ";
        cout << sa.SA[i];
    }
    cout << "\n";
}
