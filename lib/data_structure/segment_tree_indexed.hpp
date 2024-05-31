#pragma once

template <typename T>
struct SegTree{
    using FX = function<T(T, T)>; // T•T -> T となる関数の型
    int n;
    const FX fx;
    const T ex;
    shared_ptr<T[]> dat;

    SegTree(int n_, const FX &fx_, const T &ex_) : n(), fx(fx_), ex(ex_){
        int x = 1;
        while(n_ > x){
            x *= 2;
        }
        n = x;
        dat = make_shared<T[]>(n * 2);
        for(int i = 0; i < n * 2; ++i){
            dat[i] = ex;
        }
    }
    SegTree(vector<T> &v, const FX &fx_, const T &ex_) : n(), fx(fx_), ex(ex_){
        int x = 1;
        while((int) v.size() > x){
            x *= 2;
        }
        n = x;
        dat = make_shared<T[]>(n * 2);
        for(int i = 0; i < n; ++i){
            set(i, (i < (int) v.size() ? v[i] : ex));
        }
        build();
    }

    void set(int i, const T &x){ dat[i + n] = x; }

    void build(){
        for(int k = n - 1; k >= 1; k--) dat[k] = fx(dat[k * 2], dat[k * 2 + 1]);
    }

    T get(int i) const {
        return dat[i + n];
    }

    void update(int i, const T &x){
        i += n;
        dat[i] = x;
        while(i > 0){
            i >>= 1;  // parent
            dat[i] = fx(dat[i * 2], dat[i * 2 + 1]);
        }
    }

    T query(int a, int b){
        T vl = ex;
        T vr = ex;
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

    class Index{
        const shared_ptr<T[]> data;
        const int pos;
        const FX fx;

    public:
        Index(const shared_ptr<T[]> &data_, const int index, const int size, const FX &fx_) : data(data_), pos(index + size), fx(fx_) {}
        void operator=(const T value){
            data[pos] = value;
            for(int i = (pos >> 1); i > 0; i >>= 1) {
                data[i] = fx(data[2 * i], data[2 * i + 1]);
            }
        }
        operator T() const {
            return data[pos];
        }
    };

    Index operator[](const int index) const {
        assert((uint) index < (uint) n);
        return Index(dat, index, n, fx);
    }
};
