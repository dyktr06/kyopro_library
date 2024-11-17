#pragma once

/**
 * @brief Union-Find
 * @docs docs/data_structure/union_find.md
 */

#include <vector>
#include <cassert>

struct UnionFind{
    int V;
    std::vector<int> par;
    std::vector<int> edg;

    UnionFind(const int N) : V(N), par(N), edg(N){
        for(int i = 0; i < N; ++i){
            par[i] = -1;
            edg[i] = 0;
        }
    }

    int root(int x){
        assert(0 <= x && x < V);
        if(par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    int unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry){
            edg[rx]++;
            return rx;
        }
        if(-par[rx] < -par[ry]) std::swap(rx, ry);
        par[rx] = par[rx] + par[ry];
        par[ry] = rx;
        edg[rx] += edg[ry] + 1;
        return rx;
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
