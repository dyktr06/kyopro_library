#pragma once

/**
 * @brief Rational Approximation (有理数近似)
 * @docs docs/math/rational_approximation.md
 */

#include "../math/fraction.hpp"

template <typename T>
pair<fraction<T>, fraction<T>> rationalApproximation(T n, fraction<T> p){
    fraction<T> a(0, 1), b(1, 0);
    fraction<T> x(0, 1), y(1, 0);
    bool ok_left = true, ok_right = true;
    while(ok_left && ok_right){
        fraction<T> m(a.p + b.p, a.q + b.q);
        if(p < m){
            T ok = 0, ng = n;
            while(ng - ok > 1){
                T mid = (ok + ng) / 2;
                fraction<T> m2(a.p * mid + b.p, a.q * mid + b.q);
                if(p < m2 && m2.p <= n && m2.q <= n){
                    ok = mid;
                    m = m2;
                } else{
                    ng = mid;
                }
            }
            b = m;
            if(m.p <= n && m.q <= n){
                y = m;
            } else{
                ok_left = false;
            }
        } else{
            T ok = 0, ng = n;
            while(ng - ok > 1){
                T mid = (ok + ng) / 2;
                fraction<T> m2(a.p + b.p * mid, a.q + b.q * mid);
                if(p >= m2 && m2.p <= n && m2.q <= n){
                    ok = mid;
                    m = m2;
                } else{
                    ng = mid;
                }
            }
            a = m;
            if(m.p <= n && m.q <= n){
                x = m;
            } else{
                ok_right = false;
            }
        }
    }
    return make_pair(x, y);
}