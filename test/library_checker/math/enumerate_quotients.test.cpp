#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/enumerate_quotients.hpp"

int main(){
    long long n; cin >> n;
    vector<tuple<long long, long long, long long>> a = enumerate_quotients(n);
    reverse(a.begin(), a.end());
    cout << (int) a.size() << "\n";
    for(auto [l, r, q] : a){
        cout << q << " ";
    }
    cout << "\n";
}