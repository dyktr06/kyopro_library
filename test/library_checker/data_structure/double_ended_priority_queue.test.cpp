#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/double_ended_priority_queue.hpp"

int main(){
    int n, q; cin >> n >> q;
    DoubleEndedPriorityQueue<int> depq;
    for(int i = 0; i < n; i++){
        int s; cin >> s;
        depq.push(s);
    }
    while(q--){
        int t; cin >> t;
        if(t == 0){
            int x; cin >> x;
            depq.push(x);
        }else if(t == 1){
            cout << depq.get_min() << "\n";
            depq.pop_min();
        }else{
            cout << depq.get_max() << "\n";
            depq.pop_max();
        }
    }
}