#define PROBLEM "https://yukicoder.me/problems/no/186"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/math/crt.hpp"

int main(){
    vector<long long> b(3), m(3);
    int cnt = 0;
    for(int i = 0; i < 3; i++){
        cin >> b[i] >> m[i];
        if(b[i] == 0) cnt++;
    }
    pair<long long, long long> p = CRT::chineseRem(b, m);
    if(p.second == -1){
        cout << -1 << "\n";
    }else if(cnt == 3){
        cout << p.second << "\n";
    }else{
        cout << p.first << "\n";
    }
}