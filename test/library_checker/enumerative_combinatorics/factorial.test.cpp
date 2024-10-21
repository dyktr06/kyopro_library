#define PROBLEM "https://judge.yosupo.jp/problem/factorial"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/factorial.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        cout << factorial_998244353(n) << "\n";
    }
}
