#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/rerooting.hpp"
#include "../../../lib/math/modint.hpp"

using mint = ModInt<998244353>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<mint> a(n), b(n - 1), c(n - 1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    using T = pair<mint, mint>;
    auto merge = [&](T x, T y){
        T res = {x.first + y.first, x.second + y.second};
        return res;
    };
    auto put_edge = [&](T x, int i){
        T res = {x.first * b[i] + x.second * c[i], x.second};
        return res;
    };
    auto put_vertex = [&](T e, int v){
        T res = {e.first + a[v], e.second + 1};
        return res;
    };
    T e = {0, 0};
    Rerooting<T, T> G(n, merge, e, put_edge, put_vertex);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v >> b[i] >> c[i];
        G.add_edge(u, v, i, i);
    }
    G.build();
    for(auto &ans : G.reroot()){
        cout << ans.first << " ";
    }
    cout << "\n";
}