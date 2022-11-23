#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/persistent_queue.hpp"

int main(){
    int q; cin >> q;
    PersistentQueue<int> que(q + 1);
    while(q--){
        int num, t; cin >> num >> t;
        t++;
        if(num == 0){
            int x; cin >> x;
            que.push(x, t);
        }else{
            cout << que.top(t) << "\n";
            que.pop(t);
        }
    }
}