#pragma once

/**
 * @brief Compression (座標圧縮)
 * @docs docs/others/compression.md
 */

template <typename T>
struct compress{
    vector<T> sorted, compressed;

    compress(const vector<T>& vec){
        int n = vec.size();
        compressed.resize(n);
        for(T x : vec){
            sorted.emplace_back(x);
        }
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        for(int i = 0; i < n; ++i){
            compressed[i] = lower_bound(sorted.begin(), sorted.end(), vec[i]) - sorted.begin();
        }
    }

    int get(const T& x) const{
        return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
    }

    T inv(const T& x) const{
        return sorted[x];
    }

    size_t size() const{
        return sorted.size();
    }

    vector<T> getCompressed() const{
        return compressed;
    }
};