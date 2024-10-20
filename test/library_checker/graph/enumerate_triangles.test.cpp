#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/enumerate_triangles.hpp"
#include "../../../lib/math/modint.hpp"

using mint = ModInt<998244353>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<mint> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    vector<vector<int>> G(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    mint ans = 0;
    for(auto &s : enumerateTriangles(G)){
        mint mul = 1;
        for(auto &i : s){
            mul *= x[i];
        }
        ans += mul;
    }
    cout << ans << '\n';
}
