#define PROBLEM "https://judge.yosupo.jp/problem/number_of_subsequences"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/dp/substring.hpp"

constexpr long long MOD = 998244353;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long ans = subsequences(a, MOD) + MOD - 1;
    ans %= MOD;
    cout << ans << "\n";
}