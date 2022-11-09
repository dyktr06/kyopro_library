#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/string/z_algorithm.hpp"

int main(){
    string s; cin >> s;
    vector<int> z = z_algorithm(s);
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(i >= 1) cout << " ";
        cout << z[i];
    }
    cout << endl;
}