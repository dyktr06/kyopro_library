#pragma once

/**
 * @brief Segment Tree
 * @docs docs/data_structure/segment_tree.md
 */

template <typename X>
struct SegTree{
    using FX = function<X(X, X)>; // X•X -> X となる関数の型
    int n;
    FX fx;
    const X ex;
    vector<X> dat;

    SegTree(int n_, const FX &fx_, const X &ex_) : n(), fx(fx_), ex(ex_){
        int x = 1;
        while(n_ > x){
            x *= 2;
        }
        n = x;
        dat.assign(n * 2, ex);
    }

    X get(int i) const {
        return dat[i + n];
    }
    
    void set(int i, const X &x){ dat[i + n] = x; }

    void build(){
        for(int k = n - 1; k >= 1; k--) dat[k] = fx(dat[k * 2], dat[k * 2 + 1]);
    }

    void update(int i, const X &x){
        i += n;
        dat[i] = x;
        while(i > 0){
            i >>= 1;  // parent
            dat[i] = fx(dat[i * 2], dat[i * 2 + 1]);
        }
    }

    X query(int a, int b){
        X vl = ex;
        X vr = ex;
        int l = a + n;
        int r = b + n;
        while(l < r){
            if(l & 1) vl = fx(vl, dat[l++]);
            if(r & 1) vr = fx(dat[--r], vr);
            l >>= 1;
            r >>= 1;
        }
        return fx(vl, vr);
    }
    
    X operator [](int i) const {
        return dat[i + n];
    }
};