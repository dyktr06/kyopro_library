#define PROBLEM "https://yukicoder.me/problems/no/416"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/data_structure/partly_persistent_union_find.hpp"

int main(){
    int n, m, q; cin >> n >> m >> q;
    PersistentUnionFind tree(n);
    vector<pair<int, int>> p1, p2;
    set<pair<int, int>> s;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        p1.emplace_back(a, b);
    }
    for(int i = 0; i < q; i++){
        int c, d; cin >> c >> d; c--; d--;
        p2.emplace_back(c, d);
        s.insert({c, d});
    }
    for(int i = 0; i < m; i++){
        auto [a, b] = p1[i];
        if(s.find({a, b}) == s.end()){
            tree.unite(a, b);
        }
    }
    for(int i = q - 1; i >= 0; i--){
        auto [a, b] = p2[i];
        tree.unite(a, b);
    }
    for(int i = 1; i < n; i++){
        if(!tree.same(0, i, m)){
            cout << 0 << "\n";
            continue;
        }else if(tree.same(0, i, m - q)){
            cout << -1 << "\n";
            continue;
        }
        int ok = m, ng = m - q;
        while(abs(ok - ng) > 1){
            int mid = (ok + ng) / 2;
            if(tree.same(0, i, mid)){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        cout << m - ok + 1 << "\n";
    }
}