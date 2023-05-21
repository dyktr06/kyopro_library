#define PROBLEM "https://judge.yosupo.jp/problem/manhattanmst"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/manhattanMST.hpp"

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    vector<pair<int, int>> ans = manhattanMST(x, y);
    long long sum = 0;
    for(auto [i, j] : ans){
        sum += abs(x[i] - x[j]) + abs(y[i] - y[j]);
    }
    cout << sum << "\n";
    for(auto [i, j] : ans){
        cout << i << " " << j << "\n";
    }
}