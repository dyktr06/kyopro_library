#pragma once

/**
 * @brief Compression (座標圧縮)
 * @docs docs/others/compression.md
 */

#include <vector>
#include <algorithm>

template <typename T>
struct compress{
    std::vector<T> sorted;
    std::vector<int> compressed;

    compress(const std::vector<T> &vec){
        int n = vec.size();
        compressed.resize(n);
        for(T x : vec){
            sorted.emplace_back(x);
        }
        std::sort(sorted.begin(), sorted.end());
        sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
        for(int i = 0; i < n; ++i){
            compressed[i] = std::lower_bound(sorted.begin(), sorted.end(), vec[i]) - sorted.begin();
        }
    }

    int get(const T &x) const{
        return std::lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
    }

    T inv(const int x) const{
        return sorted[x];
    }

    size_t size() const{
        return sorted.size();
    }

    std::vector<T> getCompressed() const{
        return compressed;
    }
};
