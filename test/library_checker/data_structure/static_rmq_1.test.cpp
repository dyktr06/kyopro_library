#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/sparse_table.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q; cin >> n >> q;
    auto fx = [](int x1, int x2) -> int { return min(x1, x2); };
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    SparseTable<int> rmq(a, fx);
    while(q--){
        int l, r; cin >> l >> r;
        cout << rmq.query(l, r) << "\n";
    }
}