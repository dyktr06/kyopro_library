#include <bits/stdc++.h>

using namespace std;

// 約数を昇順にして配列にして出力します : O(√n)
template <typename T>
vector<T> getDivisor(T n){
    T rt = sqrt(n);
    vector<T> res, resB;
    for(T i = 1; i*i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            T j = n / i;
            if(j != rt){
                resB.push_back(j);
            }
        }
    }
    for(T i = (int) resB.size() - 1; i >= 0; i--){
        res.push_back(resB[i]);
    }
    return res;
}

// 素数かどうかを判定します : O(√n)
template <typename T>
bool isPrime(T n){
    switch(n) {
        case 0: // fall-through
        case 1: return false;
        case 2: return true;
    }

    if(n % 2 == 0) return false;

    for(T i = 3; i*i <= n; i += 2){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

// N について素因数分解をします : O(√N)
template <typename T>
vector<pair<T, T>> prime_factor(T n) {
    vector<pair<T, T>> ret;
    for (T i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        T tmp = 0;
        while (n % i == 0) {
            tmp++;
            n /= i;
        }
        ret.push_back(make_pair(i, tmp));
    }
    if (n != 1) ret.push_back(make_pair(n, 1));
    return ret;
}

// 2からNまでの素因数の個数を返します (エラトステネスのふるい) : O(NloglogN)
template <typename T>
vector<T> getSieve(T n){
    vector<T> c(n+1);
    for(int i = 2; i <= n; i++){
        if(c[i] != 0) continue;
        for(int j = i; j <= n; j += i){
            c[j] += 1;
        }
    }
    return c;
}

// aからbまでの和をもとめます : O(1)
template <typename T>
long long sum(T a, T b){
    long long res = ((b - a + 1) * (a + b)) / 2;
    return res;
}

// x^nをもとめます : O(logN)
template< typename T >
T intpow(T x, T n){
  T ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x);
    (x *= x);
    n >>= 1;
  }
  return ret;
}

// a を b で割った正のあまりを求めます : O(1)
template< typename T >
T getReminder(T a, T b){
    if(b == 0) return -1;
    if(a >= 0 && b > 0){
        return a % b;
    }else if(a < 0 && b > 0){
        return ((a % b) + b) % b;
    }else if(a >= 0 && b < 0){
        return a % b;
    }else{
        return (abs(b) - abs(a % b)) % b;
    }
}

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