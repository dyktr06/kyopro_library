#define PROBLEM "https://yukicoder.me/problems/no/184"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/math/binarybasis.hpp"

int main(){
    int n; cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    BinaryBasis<long long> basis(a);
    cout << (1LL << (basis.size())) << "\n";
}