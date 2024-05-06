#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/prime.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    cout << n << ":";
    for(auto [p, q] : prime::factorize(n)){
        for(int i = 0; i < q; i++){
            cout << " " << p;
        }
    }
    cout << "\n";
}
