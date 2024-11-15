#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <iostream>

#include "../../../lib/data_structure/sparse_table.hpp"

using namespace std;

int op(int a, int b){
    return min(a, b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    SparseTable<int, op> rmq(a);
    while(q--){
        int l, r; cin >> l >> r;
        cout << rmq.query(l, r) << "\n";
    }
}
