#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/bigint.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        BigInt a, b; cin >> a >> b;
        cout << a + b << "\n";
    }
}
