#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/cartesian_tree.hpp"

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    pair<vector<vector<int>>, int> ct = CartesianTree(a);
    auto [G, r] = ct;
    vector<int> ans(n);
    ans[r] = r;
    for(int i = 0; i < n; i++){
        for(auto x : G[i]){
            ans[x] = i;
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " \n"[i == n - 1];
    }
}