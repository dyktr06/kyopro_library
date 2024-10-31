#pragma once

#include <vector>
#include <cassert>

template <typename T, T (*op)(T, T), T(*e)()>
struct SegTree{
    int n;
    std::vector<T> dat;

    SegTree(int n_){
        int x = 1;
        while(n_ > x){
            x *= 2;
        }
        n = x;
        dat.resize(n * 2);
        for(int i = 0; i < n * 2; ++i){
            dat[i] = e();
        }
    }
    SegTree(std::vector<T> &v){
        int x = 1;
        while((int) v.size() > x){
            x *= 2;
        }
        n = x;
        dat.resize(n * 2);
        for(int i = 0; i < n; ++i){
            set(i, (i < (int) v.size() ? v[i] : e()));
        }
        build();
    }

private:
    void set(int i, const T &x){ dat[i + n] = x; }

    void build(){
        for(int k = n - 1; k >= 1; k--) dat[k] = op(dat[k * 2], dat[k * 2 + 1]);
    }

public:
    T get(int i) const {
        assert(0 <= i && i < n);
        return dat[i + n];
    }

    void update(int i, const T &x){
        assert(0 <= i && i < n);
        i += n;
        dat[i] = x;
        while(i > 0){
            i >>= 1;  // parent
            dat[i] = op(dat[i * 2], dat[i * 2 + 1]);
        }
    }

    T query(int a, int b){
        assert(0 <= a && a <= b && b <= n);
        T vl = e();
        T vr = e();
        int l = a + n;
        int r = b + n;
        while(l < r){
            if(l & 1) vl = op(vl, dat[l++]);
            if(r & 1) vr = op(dat[--r], vr);
            l >>= 1;
            r >>= 1;
        }
        return op(vl, vr);
    }
};
