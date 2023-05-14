#pragma once

template <typename T>
vector<tuple<T, T, T>> enumerate_quotients(const T &n){
    vector<tuple<T, T, T>> res;
    for(T l = 1; l <= n;){
        const T quotient = n / l;
        const T r = n / quotient + 1;

        // [l, r)
        res.emplace_back(l, r, quotient);
        l = r;
    }
    return res;
}