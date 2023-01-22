#pragma once

// [0 , N) 上の区間に対する Q 個のクエリを計算します。 : O(N√Q) (区間の伸縮が O(1) で行える場合)
struct Mo{
    int n;
    vector<pair<int, int>> lr;

    Mo(const int &n) : n(n) {}

    /* [l, r) */
    void add(const int &l,  const int &r){
        lr.push_back({l, r});
    }

    template <typename AL, typename AR, typename EL, typename ER, typename O>
    void build(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out){
        int q = (int) lr.size();
        int border = max<int>(1, 1.0 * n / max<double>(1.0, sqrt(q * 2.0 / 3.0)));
        vector<int> ord(q);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int a, int b){
            int ablock = lr[a].first / border, bblock = lr[b].first / border;
            if(ablock != bblock){
                return ablock < bblock;
            }
            return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;
        });
        int l = 0, r = 0;
        for(const auto &k : ord){
            while(l > lr[k].first) add_left(--l);
            while(r < lr[k].second) add_right(r++);
            while(l < lr[k].first) erase_left(l++);
            while(r > lr[k].second) erase_right(--r);
            out(k);
        }
    }

    template <typename A, typename E, typename O>
    void build(const A &add, const E &erase, const O &out){
        build(add, add, erase, erase, out);
    }
};