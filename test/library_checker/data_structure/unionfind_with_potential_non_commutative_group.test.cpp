#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/weighted_union_find.hpp"
#include "../../../lib/math/modint.hpp"

using mint = ModInt<998244353>;

struct Potential{
    mint A[2][2];
};
Potential operator+(Potential r, Potential l){
    Potential res;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                res.A[i][k] += l.A[i][j] * r.A[j][k];
            }
        }
    }
    return res;
}
Potential operator-(Potential r){
    swap(r.A[0][0], r.A[1][1]);
    r.A[0][1] = -r.A[0][1];
    r.A[1][0] = -r.A[1][0];
    return r;
}
Potential operator-(Potential l, Potential r){
    return l + (-r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    WeightedUnionFind<Potential> uf(n, {{{1,0},{0,1}}});
    while(q--){
        int t; cin >> t;
        if(t == 0){
            int u, v; cin >> u >> v;
            Potential x;
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    cin >> x.A[i][j];
                }
            }
            if(uf.same(u, v)){
                Potential y = uf.diff(u, v);
                int is_ok = 1;
                for(int i = 0; i < 2; i++){
                    for(int j = 0; j < 2; j++){
                        if(x.A[i][j] != y.A[i][j]){
                            is_ok = 0;
                        }
                    }
                }
                cout << is_ok << "\n";
            } else{
                uf.unite(u, v, x);
                cout << 1 << "\n";
            }
        } else{
            int u, v; cin >> u >> v;
            if(uf.same(u, v)){
                Potential x = uf.diff(u, v);
                cout << x.A[0][0] << " " << x.A[0][1] << " " << x.A[1][0] << " " << x.A[1][1] << "\n";
            } else{
                cout << -1 << "\n";
            }
        }
    }
}
