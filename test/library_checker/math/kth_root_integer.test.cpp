#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/kth_root_integer.hpp"

int main(){
    int T; cin >> T;
    while(T--){
        unsigned long long a, k; cin >> a >> k;
        cout << kthRoot(a, k) << "\n";
    }
}