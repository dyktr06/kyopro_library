#pragma once

// l <= r, ret: min
template <typename T>
pair<long long, long long> golden_section_search(long long l, long long r, T check){
    long long a = l - 1, x, b;
    {
        // fibonacci
        long long s = 1, t = 2;
        while(t < r - l + 2){
            s += t;
            swap(s, t);
        }
        x = a + t - s;
        b = a + t;
    }
    long long fx = check(x), fy;
    while(a + b != x * 2){
        long long y = a + b - x;
        if(r < y || fx < (fy = check(y))){
            b = a;
            a = y;
        }else{
            a = x;
            x = y;
            fx = fy;
        }
    }
    return {x, fx};
}
