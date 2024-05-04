#pragma once

#include "../data_structure/dynamic_binary_indexed_tree.hpp"

/*
    DynamicBinaryIndexedTree2D<S, T>(h, w) : BIT2Dをサイズh*wで構築
    add(x, y, v) : (x, y) に v を加算します。
    sum(x1, y1, x2, y2) : [(x1, y1), (x2, y2)] の和を取得します。
*/

template <typename T>
struct DynamicBinaryIndexedTree2D{
    using BIT = DynamicBinaryIndexedTree<int, T>;
    int H, W;
    vector<BIT *> bit;
    DynamicBinaryIndexedTree2D(int h, int w) : H(h + 1), W(w){
        for(int i = 0; i < H; i++){
            bit.push_back(new BIT(W));
        }
    }

    void add(int i, int j, const T &x){
        for(++i; i < H; i += i & -i) (*bit[i]).add(j, x);
    }

    T sum(int x, int y){
        if(x < 0 || y < 0){
            return 0;
        }
        T res = 0;
        while(x > 0){
            res += (*bit[x]).sum(y);
            x -= x & -x;
        }
        return res;
    }

    T sum(int x1, int y1, int x2, int y2){
        T res = 0;
        while(x1 != x2){
            if(x1 < x2){
                res += (*bit[x2]).sum(y1, y2);
                x2 -= x2 & -x2;
            } else{
                res -= (*bit[x1]).sum(y1, y2);
                x1 -= x1 & -x1;
            }
        }
        return res;
    }
};
