#define PROBLEM "https://judge.yosupo.jp/problem/static_range_count_distinct"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/mo.hpp"
#include "../../../lib/others/compression.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vector<int> a;
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
        a.push_back(c[i]);
    }
    Mo mo(n);
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        mo.add(l, r);
    }
    compress<int> comp(a);
    vector<int> compressed = comp.getCompressed();
    vector<int> cnt(n);
    vector<int> res(q);

    int now_cnt = 0;
    auto add = [&](int i){
        if(++cnt[compressed[i]] == 1){
            now_cnt++;
        }
    };
    auto erase = [&](int i){
        if(--cnt[compressed[i]] == 0){
            now_cnt--;
        }
    };
    auto output = [&](int q){
        res[q] = now_cnt;
    };
    mo.build(add, erase, output);
 
    for(auto ans : res){
        cout << ans << "\n";
    }
}