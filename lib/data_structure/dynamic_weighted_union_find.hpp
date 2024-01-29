#pragma once

template <typename T>
struct DynamicWeightedUnionFind{
    map<long long, long long> par, rank, siz;
    map<T, T> diff_weight;
    T e;

    DynamicWeightedUnionFind(const T &_e = 0) : e(_e){
    }

    void init(const T &x){
        par[x] = x;
        rank[x] = 0;
        siz[x] = 1;
        diff_weight[x] = e;
    }

    int root(const int x){
        if(par.find(x) == par.end()){
            init(x);
        }
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
        if(par.find(x) == par.end()){
            init(x);
        }
        if(par.find(y) == par.end()){
            init(y);
        }
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