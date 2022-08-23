#include <bits/stdc++.h>

using namespace std;

// [0 , N) 上の区間に対する Q 個のクエリを計算します。 : O(N√Q) (区間の伸縮が O(1) で行える場合)
struct Mo{
    int n;
    vector<pair<int, int>> lr;

    Mo(int n) : n(n) {}

    /* [l, r) */
    void add(int l,  int r){
        lr.push_back({l, r});
    }

    template<typename AL, typename AR, typename EL, typename ER, typename O>
    void build(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out){
        int q = (int) lr.size();
        int border = n / min(n, (int) sqrt(q));
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
        for(auto k : ord){
            while(l > lr[k].first) add_left(--l);
            while(r < lr[k].second) add_right(r++);
            while(l < lr[k].first) erase_left(l++);
            while(r > lr[k].second) erase_right(--r);
            out(k);
        }
    }

    template<typename A, typename E, typename O>
    void build(const A &add, const E &erase, const O &out){
        build(add, add, erase, erase, out);
    }
};

// example (ABC174F)
int main(){
    int n, q; cin >> n >> q;
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    Mo mo(n);
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        mo.add(l - 1, r);
    }
 
    vector<int> cnt(n + 1);
    int sum = 0;
    vector<int> res(q);
    auto add = [&](int i){
        if(cnt[c[i]] == 0) sum++;
        cnt[c[i]]++;
    };
    auto erase = [&](int i){
        cnt[c[i]]--;
        if(cnt[c[i]] == 0) sum--;
    };
    auto output = [&](int q){
        res[q] = sum;
    };
    mo.build(add, erase, output);
 
    for(auto x : res){
        cout << x << "\n";
    }
}