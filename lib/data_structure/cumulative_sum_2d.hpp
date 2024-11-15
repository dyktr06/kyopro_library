#pragma once

/**
 * @brief Cumulative Sum 2D
 * @docs docs/data_structure/cumulative_sum_2d.md
 */

#include <vector>
#include <cassert>

template <typename T>
struct CumulativeSum2D{
    int H, W;
    std::vector<std::vector<T>> data;

    CumulativeSum2D(const int _H, const int _W) : H(_H), W(_W), data(_H + 3, std::vector<T>(_W + 3, 0)) {}

    void add(int i, int j, const T &z){
        ++i, ++j;
        if(i >= (int) data.size() || j >= (int) data[0].size()) return;
        data[i][j] += z;
    }

    void imos(const int i1, const int j1, const int i2, const int j2, const T &z = 1) {
        assert(0 <= i1 && i1 <= i2 && i2 <= H);
        assert(0 <= j1 && j1 <= j2 && j2 <= W);
        add(i1, j1, z);
        add(i1, j2, -z);
        add(i2, j1, -z);
        add(i2, j2, z);
    }

    void build(){
        for(int i = 1; i < (int) data.size(); ++i){
            for(int j = 1; j < (int) data[i].size(); ++j){
                data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
            }
        }
    }

    inline T imos_get(const int i, const int j) const{
        return data[i + 1][j + 1];
    }

    inline T sum(const int i1, const int j1, const int i2, const int j2) const {
        assert(0 <= i1 && i1 <= i2 && i2 <= H);
        assert(0 <= j1 && j1 <= j2 && j2 <= W);
        return (data[i2][j2] - data[i1][j2] - data[i2][j1] + data[i1][j1]);
    }
};
