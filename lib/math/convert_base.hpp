#pragma once

/**
 * @brief Convert Base (進数変換)
 * @docs docs/math/convert_base.md
 */

template<typename T>
string convertBase(T x, int b) {
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
