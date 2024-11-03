#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include <iostream>

#include "../../../lib/math/modcalc.hpp"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        int y, p; cin >> y >> p;
        cout << modcalc::modsqrt(y, p) << endl;
    }
}

