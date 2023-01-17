#define PROBLEM "https://yukicoder.me/problems/no/888"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/math/rho.hpp"

int main(){
    int n; cin >> n;
    long long ans = 0;
    for(auto x : Rho::divisor(n)){
        ans += x;
    }
    cout << ans << "\n";
}