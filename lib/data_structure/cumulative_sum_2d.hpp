#pragma once

/*
    CumulativeSum2D<T>(H, W) : CumulativeSum2Dをサイズ H * W で構築
    add(i, j, z) : (i, j) に z を加算します。 O(1)
    imos(i1, j1, i2, j2, v) : いもす法において、[(i1, j1), (i2, j2) ) に z を加算します。O(1)
    build() : 加算された配列を構築します。O(HW)
    sum(i1, j1, i2, j2) : [(x1, y1), (x2, y2) ) の和を取得します。O(1)
*/

template <typename T>
struct CumulativeSum2D{
    vector<vector<T>> data;

    CumulativeSum2D(const int H, const int W) : data(H + 3, vector<T>(W + 3, 0)) {}

    void add(int i, int j, const T &z){
        ++i, ++j;
        if(i >= (int) data.size() || j >= (int) data[0].size()) return;
        data[i][j] += z;
    }

    void imos(const int i1, const int j1, const int i2, const int j2, const T &z = 1) {
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
        return (data[i2][j2] - data[i1][j2] - data[i2][j1] + data[i1][j1]);
    }
};
