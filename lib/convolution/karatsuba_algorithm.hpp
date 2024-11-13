#pragma once

/**
 * @brief Karatsuba Algorithm
 */

#include <vector>
#include <cassert>

template <typename T>
std::vector<T> karatsuba_algorithm(std::vector<T> &a, std::vector<T> &b){
    const int n = (int) a.size();
    const int h = n >> 1;
    assert(a.size() == b.size());
    assert((n & (n - 1)) == 0);
    if(n <= 64){
        std::vector<T> res(2 * n - 1);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                res[i + j] += a[i] * b[j];
            }
        }
        return res;
    }
    std::vector<T> p(h), q(h), r(h), s(h), t(h), u(h);
    for(int i = 0; i < h; ++i){
        p[i] = a[i + h];
        q[i] = a[i];
        r[i] = b[i + h];
        s[i] = b[i];
        t[i] = p[i] + q[i];
        u[i] = r[i] + s[i];
    }
    p = karatsuba_algorithm(p, r);
    q = karatsuba_algorithm(q, s);
    t = karatsuba_algorithm(t, u);
    std::vector<T> res(2 * n - 1, 0);
    for(int i = 0; i < n - 1; ++i){
        res[i] += q[i];
        res[i + h] += t[i] - p[i] - q[i];
        res[i + n] += p[i];
    }
    return res;
}
