#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/baby-step_giant-step.hpp"

int main(){
    int t; cin >> t;
    while(t--){
        long long x, y, m; cin >> x >> y >> m;
        cout << babyStepGiantStep(x, y, m) << "\n";
    }
}