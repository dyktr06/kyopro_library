#pragma once

/*
    DynamicUnionFind(n) : Union-Find 木をサイズnで構築
    計算量 : O(a(n)) -> アッカーマンの逆関数
    root(x) : 集合 x の根を取得します。
    unite(x, y) : 集合 x と y を併合します。
    same(x, y) : 集合 x と 集合 y が等しいかどうかを判定します。
    size(x) : x を含む集合の大きさを取得します。
*/

template <typename T>
struct DynamicUnionFind{
    unordered_map<T, T> par, siz;

    DynamicUnionFind(){
    }

    void init(const T &x){
        par[x] = x;
        siz[x] = 1;
    }

    T root(const T &x){
        if(par.find(x) == par.end()){
            init(x);
        }
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(const T &x, const T &y){
        if(par.find(x) == par.end()){
            init(x);
        }
        if(par.find(y) == par.end()){
            init(y);
        }
        int rx = root(x);
        int ry = root(y);
        if(size(rx) < size(ry)) swap(rx, ry);
        par[rx] = ry;
        siz[ry] += siz[rx];
    }

    bool same(const T &x, const T &y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    T size(const T &x){
        if(par.find(x) == par.end()){
            init(x);
        }
        return siz[root(x)];
    }
};
