#define PROBLEM "https://yukicoder.me/problems/no/2078"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/data_structure/convexhulltrick.hpp"

int main(){
    int t; cin >> t;
    while(t--){
        long long x, a; cin >> x >> a;
        vector<long long> dp(a + 1, 1LL << 60);
        dp[0] = 0;
        ConvexHullTrick<long long> CHT;
        for(long long i = 0; i <= a; i++){
            if(i >= 1){
                dp[i] = min(dp[i], CHT.query(i) + i * i + x);    
            }
            CHT.add(-2 * i, i * i + dp[i]);
        }
        cout << dp[a] << "\n";
    }
}