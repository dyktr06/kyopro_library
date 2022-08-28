#include <bits/stdc++.h>

using namespace std;

// 10進数での x を b 進数に変換します。: O(logx)
template<typename T>
string convert_base(T x, T b) {
    string res;
    T t = 1, k = abs(b);
    while(x){
        T num = (x * t) % k;
        if(num < 0) num += k;
        res += num + (num < 10 ? 48 : 87);
        x -= num * t;
        x /= k;
        t *= b / k;
    }
    if(res.empty()) res = '0';
    reverse(res.begin(), res.end());
    return res;
}

// example (ABC234C)
int main(){
    long long k; cin >> k;
    string s = convert_base(k, 2LL);
    s = regex_replace(s, regex("1"), "2");
    cout << s << "\n";
}