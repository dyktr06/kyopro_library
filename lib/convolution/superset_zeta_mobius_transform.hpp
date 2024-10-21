#pragma once

template <typename T>
void superset_zeta_transform(vector<T> &f){
    const int n = f.size();
    assert((n & (n - 1)) == 0);
    for(int i = 1; i < n; i <<= 1){
        for(int j = 0; j < n; ++j){
            if((j & i) == 0){
                f[j] += f[j | i];
            }
        }
    }
}

template <typename T>
void superset_mobius_transform(vector<T> &f){
    const int n = f.size();
    assert((n & (n - 1)) == 0);
    for(int i = 1; i < n; i <<= 1){
        for(int j = 0; j < n; ++j){
            if((j & i) == 0){
                f[j] -= f[j | i];
            }
        }
    }
}
