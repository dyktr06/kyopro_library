#define PROBLEM "https://yukicoder.me/problems/no/2809"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/data_structure/static_ordered_set.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    using T = tuple<long long, long long, long long>;
    vector<T> query(q);
    StaticOrderedSet<long long> ps;
    for(auto v : a) ps.add(v);
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 1){
            int k; long long x; cin >> k >> x;
            k--;
            query[i] = {t, k, x};
            ps.add(x);
        } else if(t == 2){
            query[i] = {t, -1, -1};
        } else{
            int k; cin >> k;
            k--;
            query[i] = {t, k, -1};
        }
    }
    ps.build();

    map<int, long long> mp;
    for(int i = 0; i < n; i++){
        ps.insert(a[i]);
        mp[i] = a[i];
    }
    for(int i = 0; i < q; i++){
        long long t, k, x; tie(t, k, x) = query[i];
        if(t == 1){
            mp[k] = x;
        } else if(t == 2){
            vector<long long> erase, add;
            for(auto [key, val] : mp){
                erase.push_back(ps.kth_small_element(key + 1));
                add.push_back(val);
            }
            for(auto v : erase){
                ps.erase(v);
            }
            for(auto v : add){
                ps.insert(v);
            }
            mp.clear();
        } else{
            if(mp.count(k)){
                cout << mp[k] << '\n';
                continue;
            }
            cout << ps.kth_small_element(k + 1) << '\n';
        }
    }
}
