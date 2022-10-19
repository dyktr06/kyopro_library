#include <bits/stdc++.h>

using namespace std;

// CRT::extGCD(a, b, x, y) : ax + by = gcd(a, b) となる x, y を求めます : O(log a)
// CRT::ChineseRem(b, m) : 中国剰余定理、返り値を (r, m) とすると解は x ≡ r (mod. m)、解なしの場合は (0, -1) を返します
namespace CRT{
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

    pair<long long, long long> ChineseRem(const vector<long long> &b, const vector<long long> &m) {
        long long r = 0, M = 1;
        for(int i = 0; i < (int) b.size(); i++){
            long long p, q;
            long long d = extGCD(M, m[i], p, q);
            if((b[i] - r) % d != 0) return {0, -1};
            long long tmp = (b[i] - r) / d * p % (m[i] / d);
            r += M * tmp;
            M *= m[i] / d;
        }
        r %= M;
        if(r < 0) r += M;
        return {r, M};
    }
}

// example (中華風 (Easy) (yukicoder))
int main(){
    vector<long long> b(3), m(3);
    int cnt = 0;
    for(int i = 0; i < 3; i++){
        cin >> b[i] >> m[i];
        if(b[i] == 0) cnt++;
    }
    pair<long long, long long> p = CRT::ChineseRem(b, m);
    if(p.second == -1){
        cout << -1 << endl;
    }else if(cnt == 3){
        cout << p.second << endl;
    }else{
        cout << p.first << endl;
    }
}