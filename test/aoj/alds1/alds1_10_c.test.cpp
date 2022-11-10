#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=ja"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/dp/LCS.hpp"

int main(){
    int q; cin >> q;
    while(q--){
        string s, t; cin >> s >> t;
        cout << (int) LCS(s, t).size() << "\n";
    }
}