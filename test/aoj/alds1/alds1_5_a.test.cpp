#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/others/exhaustive_search.hpp"

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<long long> s = sum_subsets(a);
    vector<int> check(4001);
    for(auto x : s) check[x] = 1;
    int q; cin >> q;
    while(q--){
        int m; cin >> m;
        if(check[m]){
            cout << "yes" << "\n";
        }else{
            cout << "no" << "\n";
        }
    }
}