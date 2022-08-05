#include <bits/stdc++.h>

using namespace std;

// 分数(p/q) の構造体
struct fraction{
    long long p, q;
    fraction(long long P = 0, long long Q = 1): p(P), q(Q){}
    bool operator<(const fraction &other)const{
        return p * other.q < other.p * q;
    }
    bool operator<=(const fraction &other)const{
        return p * other.q <= other.p * q;
    }
};

void example(){
    int n; cin >> n;
    vector<fraction> k(n);
    k[0] = fraction(10, 3); // 10/3
    k[1] = fraction(24, 7); // 24/7
    if(k[0] < k[1]){
        // 
    }
}