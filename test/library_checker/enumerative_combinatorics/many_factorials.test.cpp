#define PROBLEM "https://judge.yosupo.jp/problem/many_factorials"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/factorial.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ManyFactorials<long long> fact(998244353LL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        cout << fact.factorial(n) << "\n";
    }
}
