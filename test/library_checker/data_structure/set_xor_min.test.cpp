#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/binary_trie.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q; cin >> q;
    BinaryTrie<int, 29, 1 << 24> bt;
    while(q--){
        int t, x; cin >> t >> x;
        if(t == 0){
            if(bt.find(x).first == 0){
                bt.insert(x);
            }
        }else if(t == 1){
            if(bt.find(x).first > 0){
                bt.erase(x);
            }
        }else{
            bt.operate_xor(x);
            cout << bt.min_element().first << "\n";
            bt.operate_xor(x);
        }
    }
}