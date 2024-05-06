#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/prime.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        ans += prime::isPrime(x);
    }
    cout << ans << "\n";
}
