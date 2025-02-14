#define PROBLEM "https://yukicoder.me/problems/no/3022"
#include <iostream>

#include "../../lib/math/crt.hpp"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        long long n, m; cin >> n >> m;
        cout << CRT::modEquation(n, m, 1000000000LL, true) << endl;
    }
}
