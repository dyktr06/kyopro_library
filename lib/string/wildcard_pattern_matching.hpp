#pragma once

/**
 * @brief Wildcard Pattern Matching
 * @see https://qiita.com/MatsuTaku/items/cd5581fab97d7e74a7b3
 */

#include "../convolution/ntt.hpp"
#include "../math/modint.hpp"

vector<bool> wildcardPatternMatching(string &s, string &t){
    using mint = ModInt<998244353>;
    auto id = [](char c) -> mint {
        // wildcard must be 0
        if(c == '*'){
            return mint(0);
        } else if(isupper(c)){
            return mint(1 + (c - 'A'));
        } else if(islower(c)){
            return mint(27 + (c - 'a'));
        }
        return mint(53);
    };
    int n = s.size(), m = t.size();
    vector<mint> a1(n), a2(n), a3(n);
    vector<mint> b1(m), b2(m), b3(m);
    for(int i = 0; i < n; i++){
        a1[i] = id(s[i]);
        a2[i] = a1[i] * a1[i];
        a3[i] = a1[i] * a1[i] * a1[i];
    }

    for(int i = 0; i < m; i++){
        b1[i] = id(t[i]);
    }
    reverse(b1.begin(), b1.end());
    for(int i = 0; i < m; i++){
        b2[i] = b1[i] * b1[i];
        b3[i] = b1[i] * b1[i] * b1[i];
    }

    vector<mint> a3b1 = NTT::convolution(a3, b1);
    vector<mint> a2b2 = NTT::convolution(a2, b2);
    vector<mint> a1b3 = NTT::convolution(a1, b3);
    vector<bool> res(n - m + 1, false);
    for(int i = m - 1; i < n; i++){
        if((a3b1[i] - 2 * a2b2[i] + a1b3[i]) == 0){
            res[i - m + 1] = true;
        }
    }
    return res;
}
