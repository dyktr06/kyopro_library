#pragma once

#include "../math/modint.hpp"
#include "../math/crt.hpp"

namespace NTT{
    // @param n `0 <= n`
    // @return minimum non-negative `x` s.t. `n <= 2**x`
    int ceil_pow2(int n) {
        int x = 0;
        while((1U << x) < (unsigned int) (n)) x++;
        return x;
    }

    // @param n `1 <= n`
    // @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
    int bsf(unsigned int n) {
        return __builtin_ctz(n);
    }

    int primitive_root(int m) {
        if(m == 2) return 1;
        if(m == 167772161) return 3;
        if(m == 469762049) return 3;
        if(m == 754974721) return 11;
        if(m == 998244353) return 3;
        return 1;
    }

    template <typename T>
    void butterfly(vector<T> &a){
        int g = primitive_root(T::mod());
        int n = int(a.size());
        int h = ceil_pow2(n);

        static bool first = true;
        static T sum_e[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]
        if(first){
            first = false;
            T es[30], ies[30];  // es[i]^(2^(2+i)) == 1
            int cnt2 = bsf(T::mod() - 1);
            T e = T(g).pow((T::mod() - 1) >> cnt2), ie = e.inv();
            for(int i = cnt2; i >= 2; i--){
                // e^(2^i) == 1
                es[i - 2] = e;
                ies[i - 2] = ie;
                e *= e;
                ie *= ie;
            }
            T now = 1;
            for(int i = 0; i <= cnt2 - 2; i++){
                sum_e[i] = es[i] * now;
                now *= ies[i];
            }
        }
        for(int ph = 1; ph <= h; ph++){
            int w = 1 << (ph - 1), p = 1 << (h - ph);
            T now = 1;
            for(int s = 0; s < w; s++){
                int offset = s << (h - ph + 1);
                for(int i = 0; i < p; i++){
                    auto l = a[i + offset];
                    auto r = a[i + offset + p] * now;
                    a[i + offset] = l + r;
                    a[i + offset + p] = l - r;
                }
                now *= sum_e[bsf(~(unsigned int) (s))];
            }
        }
    }

    template <typename T>
    void butterfly_inv(vector<T> &a) {
        int g = primitive_root(T::mod());
        int n = int(a.size());
        int h = ceil_pow2(n);

        static bool first = true;
        static T sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]
        if(first){
            first = false;
            T es[30], ies[30];  // es[i]^(2^(2+i)) == 1
            int cnt2 = bsf(T::mod() - 1);
            T e = T(g).pow((T::mod() - 1) >> cnt2), ie = e.inv();
            for(int i = cnt2; i >= 2; i--){
                // e^(2^i) == 1
                es[i - 2] = e;
                ies[i - 2] = ie;
                e *= e;
                ie *= ie;
            }
            T now = 1;
            for(int i = 0; i <= cnt2 - 2; i++){
                sum_ie[i] = ies[i] * now;
                now *= es[i];
            }
        }

        for(int ph = h; ph >= 1; ph--){
            int w = 1 << (ph - 1), p = 1 << (h - ph);
            T inow = 1;
            for(int s = 0; s < w; s++){
                int offset = s << (h - ph + 1);
                for(int i = 0; i < p; i++){
                    auto l = a[i + offset];
                    auto r = a[i + offset + p];
                    a[i + offset] = l + r;
                    a[i + offset + p] = (unsigned long long) (T::mod() + l.val - r.val) * inow.val;
                }
                inow *= sum_ie[bsf(~(unsigned int) (s))];
            }
        }
    }

    template <typename T>
    vector<T> convolution(vector<T> a, vector<T> b){
        int n = int(a.size()), m = int(b.size());
        if(!n || !m) return {};
        if(min(n, m) <= 60) {
            if(n < m) {
                swap(n, m);
                swap(a, b);
            }
            vector<T> ans(n + m - 1);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    ans[i + j] += a[i] * b[j];
                }
            }
            return ans;
        }
        int z = 1 << ceil_pow2(n + m - 1);
        a.resize(z);
        butterfly(a);
        b.resize(z);
        butterfly(b);
        for(int i = 0; i < z; i++){
            a[i] *= b[i];
        }
        butterfly_inv(a);
        a.resize(n + m - 1);
        T iz = T(z).inv();
        for(int i = 0; i < n + m - 1; i++) a[i] *= iz;
        return a;
    }

    template <typename T>
    vector<T> convolution_mod(const vector<T> &a, const vector<T> &b, const long long MOD){
        constexpr long long m0 = 167772161;
        constexpr long long m1 = 469762049;
        constexpr long long m2 = 754974721;
        using mint0 = ModInt<m0>;
        using mint1 = ModInt<m1>;
        using mint2 = ModInt<m2>;
        int n = a.size(), m = b.size();
        vector<mint0> a0(n), b0(m);
        vector<mint1> a1(n), b1(m);
        vector<mint2> a2(n), b2(m);
        for(int i = 0; i < n; i++){
            a0[i] = a[i].val;
            a1[i] = a[i].val;
            a2[i] = a[i].val;
        }
        for(int i = 0; i < m; i++){
            b0[i] = b[i].val;
            b1[i] = b[i].val;
            b2[i] = b[i].val;
        }
        auto c0 = convolution(a0, b0);
        auto c1 = convolution(a1, b1);
        auto c2 = convolution(a2, b2);
        vector<T> ret(n + m - 1);
        for(int i = 0; i < n + m - 1; i++){
            ret[i] = CRT::garner({c0[i].val, c1[i].val, c2[i].val}, {m0, m1, m2}, MOD);
        }
        return ret;
    }
};
