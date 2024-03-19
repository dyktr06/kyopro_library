#define PROBLEM "https://yukicoder.me/problems/no/1464"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/math/fraction.hpp"

int main(){
    long double x; cin >> x;
    long long n = x * 100000000 + 0.1;
    fraction<long long> f(n, 100000000);
    cout << f << endl;
}