#pragma once

/**
 * @brief Union Find
 * @docs docs/data_structure/union_find.md
 */

struct UnionFind{
    vector<int> par;
    vector<int> edg;

    UnionFind(int N) : par(N), edg(N){
        for(int i = 0; i < N; ++i){
            par[i] = -1;
            edg[i] = 0;
        }
    }

    int root(int x){
        if(par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry){
            edg[rx]++;
            return;
        }
        par[ry] = par[rx] + par[ry];
        par[rx] = ry;
        edg[ry] += edg[rx] + 1;
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    long long size(int x){
        return -par[root(x)];
    }

    long long edge(int x){
        return edg[root(x)];
    }
};