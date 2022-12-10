#define PROBLEM "https://yukicoder.me/problems/no/117"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/math/modcalc.hpp"

const long long MOD = 1000000007;

int main(){
    int t; cin >> t;
    Combination comb(2000000, MOD);

    while(t--){
        char s[10];
        int n, k;
        scanf("%1s(%d,%d)", s, &n, &k);
		long long ans = 0;
		if(s[0] == 'C') ans = comb.ncr(n, k);
		else if(s[0] == 'P') ans = comb.npr(n, k);
		else if(s[0] == 'H') ans = comb.nhr(n, k);
		cout << ans << endl;
    }
}