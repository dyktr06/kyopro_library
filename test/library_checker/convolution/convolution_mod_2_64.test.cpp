#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_2_64"
#include <iostream>
#include <vector>

#include "../../../lib/convolution/karatsuba_algorithm.hpp"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<unsigned long long> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int k = 1;
    while(k < max(n, m)){
        k *= 2;
    }
    a.resize(k), b.resize(k);
    vector<unsigned long long> c = karatsuba_algorithm(a, b);
    for(int i = 0; i < n + m - 1; i++){
        cout << c[i] << " \n"[i == n + m - 1];
    }
}
