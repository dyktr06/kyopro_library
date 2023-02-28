#pragma once

template<typename T, T INF>
struct SegmentTreeBeats{
    int n, n0;
    vector<T> max_v, smax_v, max_c;
    vector<T> min_v, smin_v, min_c;
    vector<T> sum;
    vector<T> len, ladd, lval;

    void update_node_max(int k, T x) {
        sum[k] += (x - max_v[k]) * max_c[k];

        if(max_v[k] == min_v[k]){
            max_v[k] = min_v[k] = x;
        }else if(max_v[k] == smin_v[k]){
            max_v[k] = smin_v[k] = x;
        }else{
            max_v[k] = x;
        }

        if(lval[k] != INF && x < lval[k]){
            lval[k] = x;
        }
    }

    void update_node_min(int k, T x) {
        sum[k] += (x - min_v[k]) * min_c[k];

        if(max_v[k] == min_v[k]){
            max_v[k] = min_v[k] = x;
        }else if(smax_v[k] == min_v[k]){
            min_v[k] = smax_v[k] = x;
        }else{
            min_v[k] = x;
        }

        if(lval[k] != INF && lval[k] < x){
            lval[k] = x;
        }
    }

    void push(int k){
        if(n0 - 1 <= k) return;

        if(lval[k] != INF){
            updateall(2 * k + 1, lval[k]);
            updateall(2 * k + 2, lval[k]);
            lval[k] = INF;
            return;
        }

        if(ladd[k] != 0){
            addall(2 * k + 1, ladd[k]);
            addall(2 * k + 2, ladd[k]);
            ladd[k] = 0;
        }

        if(max_v[k] < max_v[2 * k + 1]){
            update_node_max(2 * k + 1, max_v[k]);
        }
        if(min_v[2 * k + 1] < min_v[k]){
            update_node_min(2 * k + 1, min_v[k]);
        }

        if(max_v[k] < max_v[2 * k + 2]){
            update_node_max(2 * k + 2, max_v[k]);
        }
        if(min_v[2 * k + 2] < min_v[k]){
            update_node_min(2 * k + 2, min_v[k]);
        }
    }

    void update(int k){
        sum[k] = sum[2 * k + 1] + sum[2 * k + 2];

        if(max_v[2 * k + 1] < max_v[2 * k + 2]){
            max_v[k] = max_v[2 * k + 2];
            max_c[k] = max_c[2 * k + 2];
            smax_v[k] = max(max_v[2 * k + 1], smax_v[2 * k + 2]);
        }else if(max_v[2 * k + 1] > max_v[2 * k + 2]){
            max_v[k] = max_v[2 * k + 1];
            max_c[k] = max_c[2 * k + 1];
            smax_v[k] = max(smax_v[2 * k + 1], max_v[2 * k + 2]);
        }else{
            max_v[k] = max_v[2 * k + 1];
            max_c[k] = max_c[2 * k + 1] + max_c[2 * k + 2];
            smax_v[k] = max(smax_v[2 * k + 1], smax_v[2 * k + 2]);
        }

        if(min_v[2 * k + 1] < min_v[2 * k + 2]){
            min_v[k] = min_v[2 * k + 1];
            min_c[k] = min_c[2 * k + 1];
            smin_v[k] = min(smin_v[2 * k + 1], min_v[2 * k + 2]);
        }else if(min_v[2 * k + 1] > min_v[2 * k + 2]){
            min_v[k] = min_v[2 * k + 2];
            min_c[k] = min_c[2 * k + 2];
            smin_v[k] = min(min_v[2 * k + 1], smin_v[2 * k + 2]);
        }else{
            min_v[k] = min_v[2 * k + 1];
            min_c[k] = min_c[2 * k + 1] + min_c[2 * k + 2];
            smin_v[k] = min(smin_v[2 * k + 1], smin_v[2 * k + 2]);
        }
    }

    void _query_chmin(T x, int a, int b, int k, int l, int r) {
        if(b <= l || r <= a || max_v[k] <= x){
            return;
        }
        if(a <= l && r <= b && smax_v[k] < x){
            update_node_max(k, x);
            return;
        }

        push(k);
        _query_chmin(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _query_chmin(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _query_chmax(T x, int a, int b, int k, int l, int r) {
        if(b <= l || r <= a || x <= min_v[k]){
            return;
        }
        if(a <= l && r <= b && x < smin_v[k]){
            update_node_min(k, x);
            return;
        }

        push(k);
        _query_chmax(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _query_chmax(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void addall(int k, T x) {
        max_v[k] += x;
        if(smax_v[k] != -INF) smax_v[k] += x;
        min_v[k] += x;
        if(smin_v[k] != INF) smin_v[k] += x;

        sum[k] += len[k] * x;
        if(lval[k] != INF){
            lval[k] += x;
        }else{
            ladd[k] += x;
        }
    }

    void updateall(int k, T x) {
        max_v[k] = x; smax_v[k] = -INF;
        min_v[k] = x; smin_v[k] = INF;
        max_c[k] = min_c[k] = len[k];

        sum[k] = x * len[k];
        lval[k] = x; ladd[k] = 0;
    }

    void _query_add(T x, int a, int b, int k, int l, int r) {
        if(b <= l || r <= a){
            return;
        }
        if(a <= l && r <= b){
            addall(k, x);
            return;
        }

        push(k);
        _query_add(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _query_add(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _query_update(T x, int a, int b, int k, int l, int r) {
        if(b <= l || r <= a){
            return;
        }
        if(a <= l && r <= b){
            updateall(k, x);
            return;
        }

        push(k);
        _query_update(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _query_update(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    T _query_max(int a, int b, int k, int l, int r) {
        if(b <= l || r <= a){
            return -INF;
        }
        if(a <= l && r <= b){
            return max_v[k];
        }
        push(k);
        T lv = _query_max(a, b, 2 * k + 1, l, (l + r) / 2);
        T rv = _query_max(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(lv, rv);
    }

    T _query_min(int a, int b, int k, int l, int r) {
        if(b <= l || r <= a){
            return INF;
        }
        if(a <= l && r <= b){
            return min_v[k];
        }
        push(k);
        T lv = _query_min(a, b, 2 * k + 1, l, (l + r) / 2);
        T rv = _query_min(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(lv, rv);
    }

    T _query_sum(int a, int b, int k, int l, int r) {
        if(b <= l || r <= a){
            return 0;
        }
        if(a <= l && r <= b){
            return sum[k];
        }
        push(k);
        T lv = _query_sum(a, b, 2 * k + 1, l, (l + r) / 2);
        T rv = _query_sum(a, b, 2 * k + 2, (l + r) / 2, r);
        return lv + rv;
    }

public:
    SegmentTreeBeats(int n) : n(n){
        vector<T> a;
        init(n, a);
    }

    SegmentTreeBeats(int n, vector<T> &a) : n(n){
        init(n, a);
    }

    void init(int n, vector<T> &a){
        max_v.assign(4 * n, 0), smax_v.assign(4 * n, 0), max_c.assign(4 * n, 0);
        min_v.assign(4 * n, 0), smin_v.assign(4 * n, 0), min_c.assign(4 * n, 0);
        sum.assign(4 * n, 0);
        len.assign(4 * n, 0), ladd.assign(4 * n, 0); lval.assign(4 * n, 0);

        n0 = 1;
        while(n0 < n) n0 <<= 1;

        for(int i = 0; i < 2 * n0; ++i) ladd[i] = 0, lval[i] = INF;
        len[0] = n0;
        for(int i = 0; i < n0 - 1; ++i) len[2 * i + 1] = len[2 * i + 2] = (len[i] >> 1);

        for(int i = 0; i < n; ++i){
            max_v[n0 - 1 + i] = min_v[n0 - 1 + i] = sum[n0 - 1 + i] = (!a.empty() ? a[i] : 0);
            smax_v[n0 - 1 + i] = -INF;
            smin_v[n0 - 1 + i] = INF;
            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 1;
        }

        for(int i = n; i < n0; ++i){
            max_v[n0 - 1 + i] = smax_v[n0 - 1 + i] = -INF;
            min_v[n0 - 1 + i] = smin_v[n0 - 1 + i] = INF;
            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 0;
        }
        for(int i = n0 - 2; i >= 0; --i){
            update(i);
        }
    }

    // range minimize query
    void query_chmin(int a, int b, T x){
        _query_chmin(x, a, b, 0, 0, n0);
    }

    // range maximize query
    void query_chmax(int a, int b, T x){
        _query_chmax(x, a, b, 0, 0, n0);
    }

    // range add query
    void query_add(int a, int b, T x){
        _query_add(x, a, b, 0, 0, n0);
    }

    // range update query
    void query_update(int a, int b, T x){
        _query_update(x, a, b, 0, 0, n0);
    }

    // range minimum query
    T query_max(int a, int b){
        return _query_max(a, b, 0, 0, n0);
    }

    // range maximum query
    T query_min(int a, int b){
        return _query_min(a, b, 0, 0, n0);
    }

    // range sum query
    T query_sum(int a, int b){
        return _query_sum(a, b, 0, 0, n0);
    }

    T get(int x){
        return _query_sum(x, x + 1, 0, 0, n0);
    }
};