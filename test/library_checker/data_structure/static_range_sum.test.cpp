#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/disjoint_sparse_table.hpp"

long long op(long long x, long long y){
    return x + y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    DisjointSparseTable<long long, op> dst(a);
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        cout << dst.query(l, r - 1) << '\n';
    }
}
