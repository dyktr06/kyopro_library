#pragma once

/* 
    imos_linear<T>(n) : サイズnで構築
    add(l, r, v, w) : [l, r) に wX + v を加算します。 O(1)
    build() : 加算された配列を構築します。O(n)
*/

template <typename T>
struct imos_linear{
    int N;
    vector<T> imos1, imos0;
    imos_linear(int N) : N(N){ init(); }

    void init(){
        imos1.resize(N + 1);
        imos0.resize(N + 1);
    }

    // [l, r) に wX + v を加算 
    // imos[l] += v, imos[l + 1] += v + w, ...
    void add(int l, int r, T v, T w){
        l = clamp(l, 0, N), r = clamp(r, 0, N);
        imos1[l] += w;
        imos1[r] -= w;
        imos0[l] += v - w;
        imos0[r] -= v + w * (r - l - 1);
    }

    void build(){
        for(int i = 0; i < N; i++){
            imos1[i + 1] += imos1[i];
            imos0[i] += imos1[i];
            imos0[i + 1] += imos0[i];
        }
    }
    
    T & operator [](int i){
        return imos0[i];
    }
};