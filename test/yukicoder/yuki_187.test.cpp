#define PROBLEM "https://yukicoder.me/problems/no/187"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/math/crt.hpp"

const long long MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<long long> x(n), y(n);
    int all_zero = 1;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        if(x[i] != 0) all_zero = 0;
    }

    long long l = CRT::preGarner(x, y, MOD);
    if(l == -1) cout << -1 << "\n";
    else if(all_zero) cout << l << "\n";
    else cout << CRT::garner(x, y, MOD) << "\n";
}
