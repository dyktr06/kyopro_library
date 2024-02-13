#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/string/rolling_hash.hpp"

int main(){
    string t, p; cin >> t >> p;
    int n = t.size(), m = p.size();
    RollingHash rh(t), rh2(p);
    for(int i = 0; i + m <= n; i++){
        if(rh.get(i, i + m) == rh2.get(0, m)){
            cout << i << "\n";
        }
    }
}