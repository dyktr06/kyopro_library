#pragma once

/**
 * @brief Binary Basis
 * @docs docs/math/binarybasis.md
 */

template <typename T>
struct BinaryBasis{

    vector<T> basis, original, inds;
    int cnt = 0;
    BinaryBasis(const vector<T> &vec){
        for(auto x : vec){
            T v = (T) 1 << (cnt++);
            T y = x;
            int len = basis.size();
            for(int i = 0; i < len; i++){
                if((y ^ basis[i]) < y){
                    y ^= basis[i];
                    v ^= inds[i];
                }
            }
            if(y > 0){
                basis.push_back(y);
                original.push_back(x);
                inds.push_back(v);
            }
        }
        normalize();
    }

    pair<T, T> add(const T &x){
        T v = (T) 1 << (cnt++);
        T y = x;
        int len = basis.size();
        for(int i = 0; i < len; i++){
            if((y ^ basis[i]) < y){
                y ^= basis[i];
                v ^= inds[i];
            }
        }
        if(y > 0){
            basis.push_back(y);
            original.push_back(x);
            inds.push_back(v);
        }
        return make_pair(y, v);
    }

    void normalize(){
        int len = basis.size();
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len; j++){
                if(basis[j] < basis[i]){
                    swap(basis[i], basis[j]);
                    swap(original[i], original[j]);
                    swap(inds[i], inds[j]);
                }
            }
        }
        for(int i = 0; i < (int) basis.size(); ++i){
            for(int j = 0; j < i; ++j){
                if((basis[i] ^ basis[j]) < basis[i]){
                    basis[i] ^= basis[j];
                    inds[i] ^= inds[j];
                }
            }
        }
    }

    bool exist(const T &x){
        T y = x;
        for(auto z : basis){
            y = min(y, y ^ z);
        }
        return y == 0;
    }

    T kth_element(const long long &k){
        T res = 0;
        for(int i = 0; i < (int) basis.size(); ++i){
            if(k & (1LL << i)){
                res ^= basis[i];
            }
        }
        return res;
    }

    size_t size(){
        return basis.size();
    }
};
