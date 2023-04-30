#pragma once

/**
 * @brief Binary Basis
 * @docs docs/math/binarybasis.md
 */

template <typename T>
struct BinaryBasis{

    vector<T> basis, original;
    BinaryBasis(const vector<T>& vec){
        for(auto x : vec){
            T y = x;
            for(auto z : basis){
                y = min(y, y ^ z);
            }
            if(y > 0){
                basis.push_back(y);
                original.push_back(x);
            }
        }
        normalize();
    }

    void add(const T &x){
        T y = x;
        for(auto z : basis){
            y = min(y, y ^ z);
        }
        if(y > 0){
            basis.push_back(y);
            original.push_back(x);
        }
    }

    void normalize(){
        sort(basis.begin(), basis.end());
        for(int i = 0; i < (int) basis.size(); ++i){
            for(int j = 0; j < i; ++j){
                basis[i] = min(basis[i], basis[i] ^ basis[j]);
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