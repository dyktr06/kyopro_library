#include <bits/stdc++.h>

using namespace std;

// 座標圧縮した配列を返します(0-indexed) : O(NlogN)
template <typename T>
T compression(T vec){
    int n = vec.size();
    T tmp = vec;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    T res(n);
    for(int i = 0; i < n; i++){
        res[i] = lower_bound(tmp.begin(), tmp.end(), vec[i]) - tmp.begin();
    }
    return res;
}

/* 
    compress<T>(vec) : vec を座標圧縮します。O(NlogN)
    get(x) : x の座標圧縮後の値を取得します。O(log(n))
    getCompressed() : 座標圧縮後の配列を取得します。 O(n)
*/

template <typename T>
struct compress{
    vector<T> sorted, compressed;

    compress(const vector<T>& vec){
        int n = vec.size();
        compressed.resize(n);
        for(T x : vec){
            sorted.push_back(x);
        }
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        for(int i = 0; i < n; i++){
            compressed[i] = lower_bound(sorted.begin(), sorted.end(), vec[i]) - sorted.begin();
        }
    }

    int get(const T& x) const{
        return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
    }

    size_t size() const{
        return sorted.size();
    }

    vector<T> getCompressed() const{
        return compressed;
    }
};