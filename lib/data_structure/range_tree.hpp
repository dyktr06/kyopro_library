#pragma once

template <typename S, typename T>
struct RangeTree{
    struct BinaryIndexedTree{
        int N;
        vector<T> BIT;
        BinaryIndexedTree() {}

        void init(int size){
            N = size;
            BIT.assign(N + 1, 0);
        }

        T get(int i){
            return sum(i + 1) - sum(i);
        }

        void add(int i, T x){
            ++i;
            while(i <= N){
                BIT[i] += x;
                i += i & -i;
            }
        }

        T sum(int i) const {
            T ans = 0;
            while(i > 0){
                ans += BIT[i];
                i -= i & -i;
            }
            return ans;
        }

        T sum(int L, int R) const {
            return sum(R) - sum(L);
        }
    };

    using P = pair<S, S>;
    S N, M;
    vector<BinaryIndexedTree> bit;
    vector<vector<S>> ys;
    vector<P> ps;

    RangeTree() {}

    void add_point(S x, S y){
        ps.push_back(make_pair(x, y));
    }

    void build(){
        sort(ps.begin(), ps.end());
        ps.erase(unique(ps.begin(), ps.end()), ps.end());

        N = ps.size();
        bit.resize(N + 1);
        ys.resize(N + 1);
        for(int i = 0; i <= N; ++i){
            int j = i + 1;
            while(j <= N){
                ys[j].push_back(ps[i].second);
                j += j & -j;
            }

            sort(ys[i].begin(), ys[i].end());
            ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());
            bit[i].init(ys[i].size());
        }
    }

    int id(S x) const {
        auto f = [](const P& a, const P& b){
            return a.first < b.first;
        };
        return lower_bound(ps.begin(), ps.end(), make_pair(x, S()), f) - ps.begin();
    }

    int id(int i, S y) const {
        return lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();
    }

    void add(S x, S y, T a){
        int i = lower_bound(ps.begin(), ps.end(), make_pair(x, y)) - ps.begin();
        assert(ps[i] == make_pair(x, y));
        ++i;
        while(i <= N){
            bit[i].add(id(i, y), a);
            i += i & -i;
        }
    }

    T sum(S x, S y) const {
        T ret = T();
        int a = id(x);
        while(a > 0){
            ret += bit[a].sum(id(a, y));
            a -= a & -a;
        }
        return ret;
    }

    // [(xl, yl), (xr, yr))
    T sum(S xl, S yl, S xr, S yr) const {
        T ret = T();
        int a = id(xl), b = id(xr);
        while(a != b) {
            if(a < b){
                ret += bit[b].sum(id(b, yl), id(b, yr));
                b -= b & -b;
            }else{
                ret -= bit[a].sum(id(a, yl), id(a, yr));
                a -= a & -a;
            }
        }
        return ret;
    }
};