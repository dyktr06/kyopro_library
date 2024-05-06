#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/modcalc.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long m, n; cin >> m >> n;
    cout << modcalc::modpow(m, n, 1000000007LL) << "\n";
}
