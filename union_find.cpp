#include <bits/stdc++.h>

using namespace std;

// Union-Find 木の実装
struct UnionFind {
    vector<int> par;
    vector<int> siz;
    vector<int> edg;

    UnionFind(int N) : par(N), siz(N), edg(N) {
        for(int i = 0; i < N; i++){
            par[i] = i;
            siz[i] = 1;
            edg[i] = 0;
        }
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry){
            edg[rx]++;
            return;
        }
        par[rx] = ry;
        siz[ry] += siz[rx];
        edg[ry] += edg[rx] + 1;
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    long long size(int x){
        return siz[root(x)];
    }

    long long edge(int x){
        return edg[root(x)];
    }
};

int n, m;

// example
int main(){
    cin >> n >> m;

    UnionFind tree(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        tree.unite(a, b);
    }
}