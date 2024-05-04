#pragma once

/**
 * @brief Weighted Union Find
 * @docs docs/data_structure/weighted_union_find.md
 */

template <typename T>
struct WeightedUnionFind{
    vector<int> par, rank, siz;
    vector<T> diff_weight;

    WeightedUnionFind(const int N, const T &e = 0) : par(N), rank(N), siz(N), diff_weight(N){
        for(int i = 0; i < N; ++i){
            par[i] = i;
            rank[i] = 0;
            siz[i] = 1;
            diff_weight[i] = e;
        }
    }

    int root(const int x){
        if(par[x] == x){
            return x;
        }
        int rx = root(par[x]);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = rx;
    }

    T weight(const int x){
        root(x);
        return diff_weight[x];
    }

    T diff(const int x, const int y){
        return weight(y) - weight(x);
    }

    void unite(const int x, const int y, T w){
        w += weight(x);
        w -= weight(y);

        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;

        if(rank[rx] < rank[ry]){
            swap(rx, ry);
            w = -w;
        }

        par[ry] = rx;
        siz[rx] += siz[ry];
        diff_weight[ry] = w;
        if(rank[rx] == rank[ry]) ++rank[rx];
    }

    bool same(const int x, const int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(const int x){
        return siz[root(x)];
    }
};
