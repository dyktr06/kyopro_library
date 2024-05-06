#define PROBLEM "https://yukicoder.me/problems/no/888"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/math/prime.hpp"

int main(){
    long long n; cin >> n;
    long long ans = 0;
    for(auto x : prime::divisor(n)){
        ans += x;
    }
    cout << ans << "\n";
}
