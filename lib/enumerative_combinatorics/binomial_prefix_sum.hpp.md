---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/mo.hpp
    title: lib/data_structure/mo.hpp
  - icon: ':heavy_check_mark:'
    path: lib/enumerative_combinatorics/combination_modint.hpp
    title: "Combination (\u4E8C\u9805\u4FC2\u6570)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Binomial Prefix Sum (\u4E8C\u9805\u4FC2\u6570\u306E\u7D2F\u7A4D\
      \u548C)"
    links: []
  bundledCode: "#line 2 \"lib/enumerative_combinatorics/binomial_prefix_sum.hpp\"\n\
    \n/**\n * @brief Binomial Prefix Sum (\u4E8C\u9805\u4FC2\u6570\u306E\u7D2F\u7A4D\
    \u548C)\n */\n\n#line 2 \"lib/data_structure/mo.hpp\"\n\n// [0 , N) \u4E0A\u306E\
    \u533A\u9593\u306B\u5BFE\u3059\u308B Q \u500B\u306E\u30AF\u30A8\u30EA\u3092\u8A08\
    \u7B97\u3057\u307E\u3059\u3002 : O(N\u221AQ) (\u533A\u9593\u306E\u4F38\u7E2E\u304C\
    \ O(1) \u3067\u884C\u3048\u308B\u5834\u5408)\nstruct Mo{\n    int n;\n    vector<pair<int,\
    \ int>> lr;\n\n    Mo(const int n) : n(n) {}\n\n    /* [l, r) */\n    void add(const\
    \ int l, const int r){\n        lr.emplace_back(l, r);\n    }\n\n    template\
    \ <typename AL, typename AR, typename EL, typename ER, typename O>\n    void build(const\
    \ AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right,\
    \ const O &out){\n        int q = (int) lr.size();\n        int border = max<int>(1,\
    \ 1.0 * n / max<double>(1.0, sqrt(q * 2.0 / 3.0)));\n        vector<int> ord(q);\n\
    \        iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(), ord.end(),\
    \ [&](int a, int b){\n            int ablock = lr[a].first / border, bblock =\
    \ lr[b].first / border;\n            if(ablock != bblock){\n                return\
    \ ablock < bblock;\n            }\n            return (ablock & 1) ? lr[a].second\
    \ > lr[b].second : lr[a].second < lr[b].second;\n        });\n        int l =\
    \ 0, r = 0;\n        for(const auto &k : ord){\n            while(l > lr[k].first)\
    \ add_left(--l);\n            while(r < lr[k].second) add_right(r++);\n      \
    \      while(l < lr[k].first) erase_left(l++);\n            while(r > lr[k].second)\
    \ erase_right(--r);\n            out(k);\n        }\n    }\n\n    template <typename\
    \ A, typename E, typename O>\n    void build(const A &add, const E &erase, const\
    \ O &out){\n        build(add, add, erase, erase, out);\n    }\n};\n#line 2 \"\
    lib/enumerative_combinatorics/combination_modint.hpp\"\n\n/**\n * @brief Combination\
    \ (\u4E8C\u9805\u4FC2\u6570)\n */\n\n#include <vector>\n\ntemplate <typename T>\n\
    struct Combination{\n    std::vector<T> memo, memoinv, inv;\n    Combination()\
    \ : memo(2, T(1)), memoinv(2, T(1)), inv(2, T(1)){}\n\n    void init(const int\
    \ N){\n        if((int) memo.size() >= N + 1){\n            return;\n        }\n\
    \        int prev_len = memo.size();\n        memo.resize(N + 1);\n        memoinv.resize(N\
    \ + 1);\n        inv.resize(N + 1);\n\n        T m = -1;\n        long long mod\
    \ = (m.val + 1LL);\n        for(int i = prev_len; i <= N; ++i){\n            memo[i]\
    \ = memo[i - 1] * i;\n            inv[i] = mod - inv[mod % i] * (mod / i);\n \
    \           memoinv[i] = memoinv[i - 1] * inv[i];\n        }\n    }\n\n    inline\
    \ T fact(const int n) {\n        init(n);\n        return memo[n];\n    }\n  \
    \  inline T factinv(const int n) {\n        init(n);\n        return memoinv[n];\n\
    \    }\n    inline T ncr(const int n, const int r) {\n        if(n < r || r <\
    \ 0) return 0;\n        init(n);\n        return (memo[n] * memoinv[r]) * memoinv[n\
    \ - r];\n    }\n    inline T npr(const int n, const int r) {\n        if(n < r\
    \ || r < 0) return 0;\n        init(n);\n        return memo[n] * memoinv[n -\
    \ r];\n    }\n    // \u91CD\u8907\u7D44\u307F\u5408\u308F\u305B\n    inline T\
    \ nhr(const int n, const int r) {\n        if(n == 0 && r == 0) return 1;\n  \
    \      return ncr(n + r - 1, r);\n    }\n    // \u30DC\u30FC\u30EB\u306E\u6570\
    \u3001\u4E00\u500B\u4EE5\u4E0A\u5FC5\u8981\u306A\u7BB1\u306E\u6570\u3001\u5236\
    \u9650\u304C\u306A\u3044\u7BB1\u306E\u6570 (\u7BB1\u533A\u5225\u3042\u308A)\n\
    \    // a = 0 \u306E\u5834\u5408\u306F\u91CD\u8907\u7D44\u307F\u5408\u308F\u305B\
    \n    inline T choose(const int n, const int a, const int b = 0) {\n        if(n\
    \ == 0) return !a;\n        return ncr(n + b - 1, a + b - 1);\n    }\n    // +1\
    \ n \u500B, -1 m \u500B, \u7D2F\u7A4D\u548C >= 0\n    inline T cataran(const int\
    \ n, const int m) {\n        return ncr(n + m, n) - ncr(n + m, n - 1);\n    }\n\
    \    // +1 n \u500B, -1 m \u500B, \u7D2F\u7A4D\u548C > -k\n    inline T cataran(const\
    \ int n, const int m, const int k) {\n        if(m < k) return ncr(n + m, n);\n\
    \        if(m < n + k) return ncr(n + m, n) - ncr(n + m, m - k);\n        return\
    \ 0;\n    }\n    // +1 n \u500B, -1 m \u500B, \u7D2F\u7A4D\u548C < +k\n    inline\
    \ T cataran2(const int n, const int m, const int k) {\n        return cataran(m,\
    \ n, k);\n    }\n};\n#line 9 \"lib/enumerative_combinatorics/binomial_prefix_sum.hpp\"\
    \n\n// sum_{i=0}^{r-1} binom(n, i)\ntemplate <typename T, typename U>\nstd::vector<T>\
    \ binomialPrefixSum(const std::vector<U> &query){\n    Combination<T> comb;\n\
    \    int q = query.size();\n    std::vector<T> res(q);\n    int max_n = 0;\n \
    \   for(auto [q1, q2] : query) max_n = std::max(max_n, (int) q1);\n    Mo mo(max_n\
    \ + 1);\n    for(auto [q1, q2] : query) mo.add(q1, q2);\n    T s = 0, inv2 = T(2).inv();\n\
    \    int n = 0, r = -1;\n    auto addL = [&](int i){\n        // n -> n + 1\n\
    \        //   sum_{i=0}^{r} binom(n + 1, i)\n        // = sum_{i=0}^{r} (binom(n,\
    \ i) + binom(n, i - 1))\n        // = -binom(n, r) + 2 * sum_{i=0}^{r} binom(n,\
    \ i)\n        s *= 2;\n        s -= comb.ncr(n, r);\n        n++;\n    };\n  \
    \  auto eraseL = [&](int i){\n        n--;\n        s += comb.ncr(n, r);\n   \
    \     s *= inv2;\n    };\n    auto addR = [&](int i){\n        // r -> r + 1\n\
    \        r++;\n        s += comb.ncr(n, r);\n    };\n    auto eraseR = [&](int\
    \ i){\n        // r -> r - 1\n        s -= comb.ncr(n, r);\n        r--;\n   \
    \ };\n    auto output = [&](int q){\n        res[q] = s;\n    };\n    mo.build(eraseL,\
    \ addR, addL, eraseR, output);\n    return res;\n}\n\n// sum_{i=0}^{r-1} binom(n,\
    \ i) i\ntemplate <typename T, typename U>\nstd::vector<std::pair<T, T>> binomialPrefixSum2(const\
    \ std::vector<U> &query){\n    Combination<T> comb;\n    int q = query.size();\n\
    \    std::vector<std::pair<T, T>> res(q);\n    int max_n = 0;\n    for(auto [q1,\
    \ q2] : query) max_n = std::max(max_n, (int) q1);\n    Mo mo(max_n + 1);\n   \
    \ for(auto [q1, q2] : query) mo.add(q1, q2);\n    T s1 = 0, s2 = 0, inv2 = T(2).inv()\
    \ = 0;\n    int n = 0, r = -1;\n    auto addL = [&](int i){\n        // n -> n\
    \ + 1\n        //   sum_{i=0}^{r} binom(n + 1, i) i\n        // = sum_{i=0}^{r}\
    \ (binom(n, i) i + binom(n, i - 1) (i - 1) + binom(n, i - 1) (1))\n        //\
    \ = -binom(n, r) * r + 2 * sum_{i=0}^{r} binom(n, i) i + sum_{i=0}^{r} binom(n,\
    \ i) - binom(n, r)\n        // = -binom(n, r) * (r + 1) + 2 * sum_{i=0}^{r} binom(n,\
    \ i) i + sum_{i=0}^{r} binom(n, i)\n        T binom = comb.ncr(n, r);\n      \
    \  s2 *= 2;\n        s2 -= binom * (r + 1);\n        s2 += s1;\n        s1 *=\
    \ 2;\n        s1 -= binom;\n        n++;\n    };\n    auto eraseL = [&](int i){\n\
    \        n--;\n        T binom = comb.ncr(n, r);\n        s1 += binom;\n     \
    \   s1 *= inv2;\n        s2 -= s1;\n        s2 += binom * (r + 1);\n        s2\
    \ *= inv2;\n    };\n    auto addR = [&](int i){\n        // r -> r + 1\n     \
    \   r++;\n        T binom = comb.ncr(n, r);\n        s1 += binom;\n        s2\
    \ += binom * (r);\n    };\n    auto eraseR = [&](int i){\n        // r -> r -\
    \ 1\n        T binom = comb.ncr(n, r);\n        s1 -= binom;\n        s2 -= binom\
    \ * (r);\n        r--;\n    };\n    auto output = [&](int q){\n        res[q]\
    \ = std::make_pair(s1, s2);\n    };\n    mo.build(eraseL, addR, addL, eraseR,\
    \ output);\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Binomial Prefix Sum (\u4E8C\u9805\u4FC2\u6570\
    \u306E\u7D2F\u7A4D\u548C)\n */\n\n#include \"../data_structure/mo.hpp\"\n#include\
    \ \"../enumerative_combinatorics/combination_modint.hpp\"\n\n// sum_{i=0}^{r-1}\
    \ binom(n, i)\ntemplate <typename T, typename U>\nstd::vector<T> binomialPrefixSum(const\
    \ std::vector<U> &query){\n    Combination<T> comb;\n    int q = query.size();\n\
    \    std::vector<T> res(q);\n    int max_n = 0;\n    for(auto [q1, q2] : query)\
    \ max_n = std::max(max_n, (int) q1);\n    Mo mo(max_n + 1);\n    for(auto [q1,\
    \ q2] : query) mo.add(q1, q2);\n    T s = 0, inv2 = T(2).inv();\n    int n = 0,\
    \ r = -1;\n    auto addL = [&](int i){\n        // n -> n + 1\n        //   sum_{i=0}^{r}\
    \ binom(n + 1, i)\n        // = sum_{i=0}^{r} (binom(n, i) + binom(n, i - 1))\n\
    \        // = -binom(n, r) + 2 * sum_{i=0}^{r} binom(n, i)\n        s *= 2;\n\
    \        s -= comb.ncr(n, r);\n        n++;\n    };\n    auto eraseL = [&](int\
    \ i){\n        n--;\n        s += comb.ncr(n, r);\n        s *= inv2;\n    };\n\
    \    auto addR = [&](int i){\n        // r -> r + 1\n        r++;\n        s +=\
    \ comb.ncr(n, r);\n    };\n    auto eraseR = [&](int i){\n        // r -> r -\
    \ 1\n        s -= comb.ncr(n, r);\n        r--;\n    };\n    auto output = [&](int\
    \ q){\n        res[q] = s;\n    };\n    mo.build(eraseL, addR, addL, eraseR, output);\n\
    \    return res;\n}\n\n// sum_{i=0}^{r-1} binom(n, i) i\ntemplate <typename T,\
    \ typename U>\nstd::vector<std::pair<T, T>> binomialPrefixSum2(const std::vector<U>\
    \ &query){\n    Combination<T> comb;\n    int q = query.size();\n    std::vector<std::pair<T,\
    \ T>> res(q);\n    int max_n = 0;\n    for(auto [q1, q2] : query) max_n = std::max(max_n,\
    \ (int) q1);\n    Mo mo(max_n + 1);\n    for(auto [q1, q2] : query) mo.add(q1,\
    \ q2);\n    T s1 = 0, s2 = 0, inv2 = T(2).inv() = 0;\n    int n = 0, r = -1;\n\
    \    auto addL = [&](int i){\n        // n -> n + 1\n        //   sum_{i=0}^{r}\
    \ binom(n + 1, i) i\n        // = sum_{i=0}^{r} (binom(n, i) i + binom(n, i -\
    \ 1) (i - 1) + binom(n, i - 1) (1))\n        // = -binom(n, r) * r + 2 * sum_{i=0}^{r}\
    \ binom(n, i) i + sum_{i=0}^{r} binom(n, i) - binom(n, r)\n        // = -binom(n,\
    \ r) * (r + 1) + 2 * sum_{i=0}^{r} binom(n, i) i + sum_{i=0}^{r} binom(n, i)\n\
    \        T binom = comb.ncr(n, r);\n        s2 *= 2;\n        s2 -= binom * (r\
    \ + 1);\n        s2 += s1;\n        s1 *= 2;\n        s1 -= binom;\n        n++;\n\
    \    };\n    auto eraseL = [&](int i){\n        n--;\n        T binom = comb.ncr(n,\
    \ r);\n        s1 += binom;\n        s1 *= inv2;\n        s2 -= s1;\n        s2\
    \ += binom * (r + 1);\n        s2 *= inv2;\n    };\n    auto addR = [&](int i){\n\
    \        // r -> r + 1\n        r++;\n        T binom = comb.ncr(n, r);\n    \
    \    s1 += binom;\n        s2 += binom * (r);\n    };\n    auto eraseR = [&](int\
    \ i){\n        // r -> r - 1\n        T binom = comb.ncr(n, r);\n        s1 -=\
    \ binom;\n        s2 -= binom * (r);\n        r--;\n    };\n    auto output =\
    \ [&](int q){\n        res[q] = std::make_pair(s1, s2);\n    };\n    mo.build(eraseL,\
    \ addR, addL, eraseR, output);\n    return res;\n}\n"
  dependsOn:
  - lib/data_structure/mo.hpp
  - lib/enumerative_combinatorics/combination_modint.hpp
  isVerificationFile: false
  path: lib/enumerative_combinatorics/binomial_prefix_sum.hpp
  requiredBy: []
  timestamp: '2026-06-21 04:09:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/enumerative_combinatorics/binomial_prefix_sum.hpp
layout: document
redirect_from:
- /library/lib/enumerative_combinatorics/binomial_prefix_sum.hpp
- /library/lib/enumerative_combinatorics/binomial_prefix_sum.hpp.html
title: "Binomial Prefix Sum (\u4E8C\u9805\u4FC2\u6570\u306E\u7D2F\u7A4D\u548C)"
---
