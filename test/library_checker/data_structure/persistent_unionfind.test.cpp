#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/persistent_union_find.hpp"

using pa = PersistentArray<int>::Node*;

int main(){
    int n, q; cin >> n >> q;
    PersistentUnionFind tree;
    vector<pa> p(q + 1);
    p[0] = tree.init(n);
    int nxt = 1;
    while(q--){
        int t, k, u, v; cin >> t >> k >> u >> v;
        k++;
        if(t == 0){
            p[nxt] = tree.unite(u, v, p[k]).second;
        }else{
            cout << (int) tree.same(u, v, p[k]) << "\n";
        }
        nxt++;
    }
}