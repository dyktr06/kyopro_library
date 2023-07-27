#pragma once

template <typename X>
struct SquareDiv{
    using FX = function<X(X, X)>;
    int n, bn;
    const int block;
    FX fx;
    const X ex;
    int nowt = 0;
    vector<int> t, block_t;
    vector<X> dat, block_dat, lazy;

    SquareDiv(int n_, int block_, const FX &fx_, const X &ex_) : n(n_), block(block_), fx(fx_), ex(ex_){
        init();
        dat.assign(n, ex);
    }

    SquareDiv(vector<X> v, int block_, const FX &fx_, const X &ex_) : block(block_), fx(fx_), ex(ex_), dat(v){
        n = v.size();
        init();
        while((int) dat.size() < n){
            dat.emplace_back(ex);
        }
        for(int i = 0; i < bn; ++i){
            apply(i);
        }
    }

    void init(){
        bn = (n + block - 1) / block;
        n = bn * block;
        t.assign(n, 0);
        block_t.assign(bn, 0);
        block_dat.assign(bn, ex);
        lazy.assign(bn, ex);
    }

    X get(int i) const {
        if(t[i] < block_t[i / block]) return lazy[i / block];
        else return dat[i];
    }

    void apply(int k){
        X s = ex;
        for(int i = k * block; i < (k + 1) * block; ++i){
            s = fx(s, get(i));
        }
        block_dat[k] = s;
    }

    // [l, r)
    void update(int l, int r, X x){
        nowt++;

        int lb = (l + block - 1) / block, rb = r / block;
        if(rb - lb < 0){
            for(int i = l; i < r; ++i){
                dat[i] = x;
                t[i] = nowt;
            }
            apply(l / block);
            return;
        }

        for(int i = l; i < lb * block; ++i){
            dat[i] = x;
            t[i] = nowt;
        }
        if(lb * block - l) apply(l / block);

        if(rb - lb){
            X s = ex;
            for(int i = 0; i < block; ++i){
                s = fx(s, x);
            }
            for(int i = lb; i < rb; ++i){
                block_dat[i] = s;
                lazy[i] = x;
                block_t[i] = nowt;
            }
        }

        for(int i = rb * block; i < r; ++i){
            dat[i] = x;
            t[i] = nowt;
        }
        if(r - rb * block) apply(rb);
    }

    // [l, r)
    X query(int l, int r){
        int lb = (l + block - 1) / block, rb = r / block;
        X res = ex;
        if(rb - lb < 0){
            for(int i = l; i < r; i++){
                res = fx(res, get(i));
            }
            return res;
        }
        
        for(int i = l; i < lb * block; ++i){
            res = fx(res, get(i));
        }
        for(int i = lb; i < rb; ++i){
            res = fx(res, block_dat[i]);
        }
        for(int i = rb * block; i < r; ++i){
            res = fx(res, get(i));
        }
        return res;
    }
    
    X operator [](int i) const {
        return get(i);
    }
};