#define PROBLEM "https://yukicoder.me/problems/no/2087"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/math/convert_base.hpp"

int main(){
    int n, m; cin >> n >> m;
    cout << convert_base(m, n) << "\n";
}