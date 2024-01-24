#define PROBLEM "https://judge.yosupo.jp/problem/static_range_mode_query"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/mo.hpp"
#include "../../../lib/others/compression.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    compress<int> comp(a);
    Mo mo(n);
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        mo.add(l, r);
    }
    vector<unordered_set<int>> val(n + 1);
    vector<int> cnt(n), reach(n + 1);
    for(int i = 0; i < comp.size(); i++){
        val[0].insert(i);
    }
    reach[0] = n;
    vector<pair<int, int>> res(q);
    int now = 0;
    auto add = [&](int i){
        int v = comp.compressed[i];
        val[cnt[v]].erase(v);
        reach[cnt[v]]--;
        ++cnt[v];
        val[cnt[v]].insert(v);
        reach[cnt[v]]++;

        if(now < cnt[v]){
            now = cnt[v];
        }
    };
    auto erase = [&](int i){
        int v = comp.compressed[i];
        val[cnt[v]].erase(v);
        reach[cnt[v]]--;
        --cnt[v];
        val[cnt[v]].insert(v);
        reach[cnt[v]]++;

        if(reach[now] == 0){
            now--;
        }
    };
    auto output = [&](int q){
        res[q] = {comp.inv(*val[now].begin()), now};
    };
    mo.build(add, erase, output);
 
    for(auto ans : res){
        cout << ans.first << " " << ans.second << "\n";
    }
}