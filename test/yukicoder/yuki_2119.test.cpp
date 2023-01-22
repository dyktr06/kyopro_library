#define PROBLEM "https://yukicoder.me/problems/no/2119"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/math/crt.hpp"

int main(){
    int n, m; cin >> n >> m;
    vector<long long> b(m), c(m);
    for(int i = 0; i < m; i++){
        cin >> b[i] >> c[i];
    }
    pair<long long, long long> p = CRT::chineseRem(c, b);
    if(p.second == -1 || p.first > n){
        cout << "NaN" << "\n";
    }else{
        cout << p.first << "\n";
    }
}