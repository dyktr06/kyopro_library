#pragma once

#include "../data_structure/persistent_array.hpp"

struct PersistentUnionFind{
    PersistentArray<int> data;
    using node = PersistentArray<int>::Node*;

    PersistentUnionFind() {}

    node init(const int &n){
        node res = data.get_root();
        for(int i = 0; i < n; ++i){
            data.destructive_set(i, -1, res);
        }
        return res;
    }

    pair<bool, node> unite(const int &x, const int &y, node t){
        int rx = root(x, t), ry = root(y, t);
        if(rx == ry) return {false, t};

        if(data.get(ry, t) < data.get(rx, t)) swap(rx, ry);

        node n = data.set(rx, data.get(rx, t) + data.get(ry, t), t);
        node res = data.set(ry, rx, n);
        return {true, res};
    }

    int root(const int &x, node t){
        if(data.get(x, t) < 0){
            return x;
        }
        int res = root(data.get(x, t), t);
        return res;
    }

    inline bool same(const int &x, const int &y, node t){
        return root(x, t) == root(y, t);
    }

    inline int size(const int &x, node t){
        return -data.get(root(x, t), t);
    }
};

struct PersistentUnionFindv2{
    int n;
    PersistentArray<int> data;
    using node = PersistentArray<int>::Node*;

    PersistentUnionFindv2() {}

    node init(const int &_n){
        n = _n;
        node res = data.get_root();
        for(int i = 0; i < n; ++i){
            data.destructive_set(i, -1, res);
            data.destructive_set(i + n, 0, res);
        }
        return res;
    }

    pair<bool, node> unite(const int &x, const int &y, node t){
        int rx = root(x, t), ry = root(y, t);
        if(rx == ry){
            node res = data.set(rx + n, edge(rx, t) + 1, t);
            return {false, res};
        }

        if(data.get(ry, t) < data.get(rx, t)) swap(rx, ry);

        node res = data.set(rx, data.get(rx, t) + data.get(ry, t), t);
        res = data.set(ry, rx, res);
        res = data.set(rx + n, data.get(rx + n, t) + data.get(ry + n, t) + 1, res);
        return {true, res};
    }

    int root(const int &x, node t){
        if(data.get(x, t) < 0){
            return x;
        }
        int res = root(data.get(x, t), t);
        return res;
    }

    inline bool same(const int &x, const int &y, node t){
        return root(x, t) == root(y, t);
    }

    inline int size(const int &x, node t){
        return -data.get(root(x, t), t);
    }

    inline int edge(const int &x, node t){
        return data.get(root(x, t) + n, t);
    }
};