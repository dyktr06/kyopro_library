#pragma once

/**
 * @brief Binary Indexed Tree 2D
 * @docs docs/data_structure/binary_indexed_tree_2d.md
 */

#include <vector>
#include <cassert>

template <typename T>
struct BinaryIndexedTree2D{
    int H, W;
    std::vector<std::vector<T>> BIT;
    BinaryIndexedTree2D(const int _H, const int _W) : H(_H + 1), W(_W + 1){
        BIT.resize(H + 3, std::vector<T>(W + 3, 0));
    }

    void add(const int x, const int y, const T v){
        assert(0 <= x && x < H && 0 <= y && y < W);
        for(int a = x + 1; a <= H; a += a & -a){
            for(int b = y + 1; b <= W; b += b & -b){
                BIT[a][b] += v;
            }
        }
    }

    void imos(const int x1, const int y1, const int x2, const int y2, const T v){
        add(x1, y1, v);
        add(x1, y2 + 1, -v);
        add(x2 + 1, y1, -v);
        add(x2 + 1, y2 + 1, v);
    }

    T sum(const int x, const int y){
        assert(x < H && y < W);
        if(x < 0 || y < 0) return 0;
        T res = 0;
        for(int a = x + 1; a > 0; a -= a & -a){
            for(int b = y + 1; b > 0; b -= b & -b){
                res += BIT[a][b];
            }
        }
        return res;
    }

    T sum(const int x1, const int y1, const int x2, const int y2){
        if(x1 > x2 || y1 > y2) return T(0);
        return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
    }
};
