#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/dp/LIS.hpp"

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> LIS = construct_LIS(a);
    cout << (int) LIS.size() << "\n";
    for(auto x : LIS){
        cout << x << " ";
    }
    cout << "\n";
}