#pragma once

/**
 * @brief Weighted Union Find
 * @docs docs/data_structure/weighted_union_find.md
 */

#include <vector>
#include <cassert>

template <typename T>
struct WeightedUnionFind{
    int V;
    std::vector<int> par;
    std::vector<T> diff_weight;
    T ex;

    WeightedUnionFind(const int N, const T &e = 0) : V(N), par(N), diff_weight(N), ex(e){
        for(int i = 0; i < N; ++i){
            par[i] = -1;
            diff_weight[i] = e;
        }
    }

    int root(const int x){
        assert(0 <= x && x < V);
        if(par[x] < 0){
            return x;
        }
        int px = par[x];
        int rx = root(par[x]);
        diff_weight[x] = diff_weight[x] + diff_weight[px];
        return par[x] = rx;
    }

    T weight(const int x){
        root(x);
        return diff_weight[x];
    }

    T diff(const int x, const int y){
        return weight(x) - weight(y);
    }

    void unite(const int x, const int y, const T &w){
        int tx = x, ty = y;
        T tw = w;
        int rx = root(x), ry = root(y);
        if(rx == ry) return;

        if(par[rx] < par[ry]){
            std::swap(rx, ry);
            std::swap(tx, ty);
            tw = ex - tw;
        }

        par[ry] = par[rx] + par[ry];
        par[rx] = ry;
        diff_weight[rx] = ex - diff_weight[tx] + tw + diff_weight[ty];
    }

    bool same(const int x, const int y){
        return root(x) == root(y);
    }

    int size(const int x){
        return -par[root(x)];
    }
};
