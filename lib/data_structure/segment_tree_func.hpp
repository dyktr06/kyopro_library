#pragma once

#include <vector>
#include <cassert>

template <typename T, T (*op)(T, T), T(*e)()>
struct SegTree{
    int _n, n;
    std::vector<T> dat;

    SegTree(int _n) : _n(_n) {
        int x = 1;
        while(_n > x){
            x *= 2;
        }
        n = x;
        dat.resize(n * 2);
        for(int i = 0; i < n * 2; ++i){
            dat[i] = e();
        }
    }
    SegTree(std::vector<T> &v) : _n((int) v.size()) {
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

    template <class F>
    int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if(l == _n) return _n;
        l += n;
        T sm = e();
        do{
            while(l % 2 == 0) l >>= 1;
            if(!f(op(sm, dat[l]))){
                while(l < n){
                    l = (2 * l);
                    if(f(op(sm, dat[l]))){
                        sm = op(sm, dat[l]);
                        l++;
                    }
                }
                return l - n;
            }
            sm = op(sm, dat[l]);
            l++;
        }while((l & -l) != l);
        return _n;
    }

    template <class F>
    int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if(r == 0) return 0;
        r += n;
        T sm = e();
        do{
            r--;
            while(r > 1 && (r % 2)) r >>= 1;
            if(!f(op(dat[r], sm))){
                while(r < n){
                    r = (2 * r + 1);
                    if(f(op(dat[r], sm))){
                        sm = op(dat[r], sm);
                        r--;
                    }
                }
                return r + 1 - n;
            }
            sm = op(dat[r], sm);
        }while((r & -r) != r);
        return 0;
    }
};
