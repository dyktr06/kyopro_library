#pragma once

template <typename T>
struct PrioritySet{
    struct compress{
        vector<T> sorted, compressed;

        compress(){}

        void init(const vector<T>& vec){
            int n = vec.size();
            compressed.resize(n);
            for(T x : vec){
                sorted.emplace_back(x);
            }
            sort(sorted.begin(), sorted.end());
            sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
            for(int i = 0; i < n; ++i){
                compressed[i] = lower_bound(sorted.begin(), sorted.end(), vec[i]) - sorted.begin();
            }
        }

        int get(const T& x) const{
            return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
        }

        T inv(const T& x) const{
            return sorted[x];
        }

        size_t size() const{
            return sorted.size();
        }

        vector<T> getCompressed() const{
            return compressed;
        }
    };

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
            i++;
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

        int lower_bound(T x) const {
            if(x <= 0){
                return 0;
            }else{
                int v = 0, r = 1;
                while(r < N) r = r << 1;
                for(int len = r; len > 0; len = len >> 1){
                    if(v + len < N && BIT[v + len] < x){
                        x -= BIT[v + len];
                        v += len;
                    }
                }
                return v;
            }
        }

        int upper_bound(T x) const {
            if(x < 0){
                return 0;
            }else{
                int v = 0, r = 1;
                while(r <= N) r = r << 1;
                for(int len = r; len > 0; len = len >> 1){
                    if(v + len <= N && BIT[v + len] <= x){
                        x -= BIT[v + len];
                        v += len;
                    }
                }
                return v;
            }
        }

        T operator [](int i) const {
            return sum(i, i + 1);
        }
    };

    vector<T> a;
    compress comp;
    BinaryIndexedTree cnt, val;

    PrioritySet(){ }

    void add(T x){
        a.push_back(x);
    }

    void build(){
        comp.init(a);
        cnt.init(comp.size());
        val.init(comp.size());
    }

    T size(){
        return cnt.sum((int) comp.size());
    }

    void insert(T x, T count = 1){
        cnt.add(comp.get(x), count);
        val.add(comp.get(x), count * x);
    }

    void erase(T x, T count = 1){
        T idx = comp.get(x);
        if(cnt.get(idx) < count){
            count = cnt.get(idx);
        }
        cnt.add(idx, -count);
        val.add(idx, -count * x);
    }

    // 1-indexed
    T kth_small_element(T k){
        T idx = cnt.lower_bound(k);
        return comp.inv(idx);
    }

    T kth_large_element(T k){
        T rev_k = size() - k + 1;
        return kth_small_element(rev_k);
    }

    // 1-indexed
    T kth_small_sum(T k){
        if(size() < k){
            return val.sum((int) comp.size());
        }
        T idx = cnt.lower_bound(k);
        T sum = val.sum(idx);
        sum += comp.inv(idx) * (k - cnt.sum(idx));
        return sum;
    }

    T kth_large_sum(T k){
        if(size() < k){
            return val.sum((int) comp.size());
        }
        T rev_k = size() - k;
        return val.sum((int) comp.size()) - kth_small_sum(rev_k);
    }
};