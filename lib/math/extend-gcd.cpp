#include <bits/stdc++.h>

using namespace std;

// ax + by = gcd(x, y) となる x, y を求めます : O(log a)
long long extGCD(long long a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}