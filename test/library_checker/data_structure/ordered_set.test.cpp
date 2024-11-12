#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"

#include <iostream>
#include <vector>

#include "../../../lib/data_structure/priority_set.hpp"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    PrioritySet<long long> ps;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        ps.add(a[i]);
    }
    using T = pair<int, int>;
    vector<T> query(q);
    for(int i = 0; i < q; ++i){
        cin >> query[i].first >> query[i].second;
        if(query[i].first != 2){
            ps.add(query[i].second);
        }
    }
    ps.build();

    for(int i = 0; i < n; ++i){
        ps.insert(a[i]);
    }
    for(int i = 0; i < q; i++){
        auto [type, x] = query[i];
        if(type == 0){
            if(!ps.exist(x)) ps.insert(x);
        } else if(type == 1){
            if(ps.exist(x)) ps.erase(x);
        } else if(type == 2){
            cout << ps.kth_small_element(x) << "\n";
        } else if(type == 3){
            cout << ps.count_less(x + 1) << "\n";
        } else if(type == 4){
            cout << ps.reverse_lower_bound(x) << "\n";
        } else if(type == 5){
            cout << ps.lower_bound(x) << "\n";
        }
    }
}
