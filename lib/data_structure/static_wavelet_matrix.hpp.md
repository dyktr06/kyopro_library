---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Static Wavelet Matrix
    links: []
  bundledCode: "#line 2 \"lib/data_structure/static_wavelet_matrix.hpp\"\n\n/**\n\
    \ * @brief Static Wavelet Matrix\n */\n\ntemplate <class S, class T>\nstruct StaticWaveletMatrix{\n\
    \    struct Point{\n        S x, y;\n        T weight;\n    };\n\n    std::vector<Point>\
    \ points;\n    std::vector<S> xs;\n    std::vector<S> ys_all;\n\n    int n = 0;\n\
    \    int sigma = 0;\n    int log_sigma = 0;\n\n    // \u5404\u30EC\u30D9\u30EB\
    \u306B\u304A\u3051\u308B 0 \u5074\u306E\u8981\u7D20\u6570\n    std::vector<int>\
    \ mid;\n\n    // pref_one[level][i]\n    // = level \u306B\u304A\u3051\u308B\u533A\
    \u9593 [0, i) \u306E 1-bit \u306E\u500B\u6570\n    std::vector<std::vector<int>>\
    \ pref_one;\n\n    // pref_zero_sum[level][i]\n    // = level \u306B\u304A\u3051\
    \u308B\u533A\u9593 [0, i) \u306E\u3046\u3061\u3001\n    //   \u5BFE\u8C61 bit\
    \ \u304C 0 \u3067\u3042\u308B\u8981\u7D20\u306E\u91CD\u307F\u548C\n    std::vector<std::vector<T>>\
    \ pref_zero_sum;\n\n    std::vector<T> pref_all_sum;\n\n    void add(const S&\
    \ x, const S& y, const T& weight){\n        points.push_back({x, y, weight});\n\
    \    }\n\n    int idX(const S &x) const {\n        return std::lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n    }\n\n    int idY(const S &y) const {\n     \
    \   return std::lower_bound(ys_all.begin(), ys_all.end(), y) - ys_all.begin();\n\
    \    }\n\n    void build(){\n        std::sort(points.begin(), points.end(),\n\
    \            [](const Point& a, const Point& b){\n                if (a.x != b.x)\
    \ {\n                    return a.x < b.x;\n                }\n              \
    \  return a.y < b.y;\n            }\n        );\n\n        n = points.size();\n\
    \n        xs.resize(n);\n        ys_all.resize(n);\n        pref_all_sum.assign(n\
    \ + 1, T{});\n\n        for(int i = 0; i < n; ++i){\n            xs[i] = points[i].x;\n\
    \            ys_all[i] = points[i].y;\n            pref_all_sum[i + 1] = pref_all_sum[i]\
    \ + points[i].weight;\n        }\n\n        std::sort(ys_all.begin(), ys_all.end());\n\
    \        ys_all.erase(unique(ys_all.begin(), ys_all.end()), ys_all.end());\n\n\
    \        sigma = ys_all.size();\n\n        if(n == 0){\n            log_sigma\
    \ = 0;\n            mid.clear();\n            pref_one.clear();\n            pref_zero_sum.clear();\n\
    \            return;\n        }\n\n        log_sigma = 0;\n        while((1LL\
    \ << log_sigma) < sigma){\n            log_sigma++;\n        }\n\n        log_sigma\
    \ = std::max(log_sigma, 1);\n\n        mid.assign(log_sigma, 0);\n        pref_one.assign(log_sigma,\
    \ {});\n        pref_zero_sum.assign(log_sigma, {});\n\n        std::vector<int>\
    \ key(n);\n        std::vector<T> weight(n);\n\n        for(int i = 0; i < n;\
    \ ++i){\n            key[i] = idY(points[i].y);\n            weight[i] = points[i].weight;\n\
    \        }\n\n        for(int level = 0; level < log_sigma; ++level){\n      \
    \      const int bit = log_sigma - 1 - level;\n\n            pref_one[level].assign(n\
    \ + 1, 0);\n            pref_zero_sum[level].assign(n + 1, T{});\n\n         \
    \   std::vector<int> zero_key;\n            std::vector<int> one_key;\n      \
    \      std::vector<T> zero_weight;\n            std::vector<T> one_weight;\n\n\
    \            zero_key.reserve(n);\n            one_key.reserve(n);\n         \
    \   zero_weight.reserve(n);\n            one_weight.reserve(n);\n\n          \
    \  for(int i = 0; i < n; ++i){\n                const bool is_one = (key[i] >>\
    \ bit) & 1;\n\n                pref_one[level][i + 1] = pref_one[level][i] + (is_one\
    \ ? 1 : 0);\n                pref_zero_sum[level][i + 1] = pref_zero_sum[level][i]\
    \ + (is_one ? T{} : weight[i]);\n\n                if(is_one){\n             \
    \       one_key.push_back(key[i]);\n                    one_weight.push_back(weight[i]);\n\
    \                }else{\n                    zero_key.push_back(key[i]);\n   \
    \                 zero_weight.push_back(weight[i]);\n                }\n     \
    \       }\n\n            mid[level] = zero_key.size();\n\n            key.clear();\n\
    \            weight.clear();\n\n            key.reserve(n);\n            weight.reserve(n);\n\
    \n            key.insert(key.end(), zero_key.begin(), zero_key.end());\n     \
    \       key.insert(key.end(), one_key.begin(), one_key.end());\n\n           \
    \ weight.insert(weight.end(), zero_weight.begin(), zero_weight.end());\n     \
    \       weight.insert(weight.end(), one_weight.begin(), one_weight.end());\n \
    \       }\n    }\n\nprivate:\n    // x: [l, r)\n    // y: [0, upper_index)\n \
    \   T range_less_sum_index(int l, int r, int upper_index) const {\n        if(l\
    \ >= r || upper_index <= 0 || n == 0){\n            return T{};\n        }\n\n\
    \        if(upper_index >= sigma){\n            return pref_all_sum[r] - pref_all_sum[l];\n\
    \        }\n\n        T answer{};\n\n        for(int level = 0; level < log_sigma;\
    \ ++level){\n            const int bit = log_sigma - 1 - level;\n\n          \
    \  const int one_l = pref_one[level][l];\n            const int one_r = pref_one[level][r];\n\
    \n            const int zero_l = l - one_l;\n            const int zero_r = r\
    \ - one_r;\n\n            if((upper_index >> bit) & 1){\n                answer\
    \ += pref_zero_sum[level][r] - pref_zero_sum[level][l];\n                l = mid[level]\
    \ + one_l;\n                r = mid[level] + one_r;\n            }else{\n    \
    \            // 0 \u5074\u3078\u79FB\u52D5\n                l = zero_l;\n    \
    \            r = zero_r;\n            }\n        }\n\n        return answer;\n\
    \    }\n\npublic:\n    // (-INF, x) \xD7 (-INF, y)\n    T sum(const S &x, const\
    \ S &y) const {\n        const int r = idX(x);\n        const int upper_y = idY(y);\n\
    \        return range_less_sum_index(0, r, upper_y);\n    }\n\n    // [xl, xr)\
    \ \xD7 [yl, yr)\n    T sum(const S& xl, const S& yl, const S& xr, const S& yr)\
    \ const {\n        if(!(xl < xr) || !(yl < yr)){\n            return T{};\n  \
    \      }\n\n        const int l = idX(xl);\n        const int r = idX(xr);\n \
    \       const int lower_y = idY(yl);\n        const int upper_y = idY(yr);\n \
    \       return range_less_sum_index(l, r, upper_y) - range_less_sum_index(l, r,\
    \ lower_y);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Static Wavelet Matrix\n */\n\ntemplate <class\
    \ S, class T>\nstruct StaticWaveletMatrix{\n    struct Point{\n        S x, y;\n\
    \        T weight;\n    };\n\n    std::vector<Point> points;\n    std::vector<S>\
    \ xs;\n    std::vector<S> ys_all;\n\n    int n = 0;\n    int sigma = 0;\n    int\
    \ log_sigma = 0;\n\n    // \u5404\u30EC\u30D9\u30EB\u306B\u304A\u3051\u308B 0\
    \ \u5074\u306E\u8981\u7D20\u6570\n    std::vector<int> mid;\n\n    // pref_one[level][i]\n\
    \    // = level \u306B\u304A\u3051\u308B\u533A\u9593 [0, i) \u306E 1-bit \u306E\
    \u500B\u6570\n    std::vector<std::vector<int>> pref_one;\n\n    // pref_zero_sum[level][i]\n\
    \    // = level \u306B\u304A\u3051\u308B\u533A\u9593 [0, i) \u306E\u3046\u3061\
    \u3001\n    //   \u5BFE\u8C61 bit \u304C 0 \u3067\u3042\u308B\u8981\u7D20\u306E\
    \u91CD\u307F\u548C\n    std::vector<std::vector<T>> pref_zero_sum;\n\n    std::vector<T>\
    \ pref_all_sum;\n\n    void add(const S& x, const S& y, const T& weight){\n  \
    \      points.push_back({x, y, weight});\n    }\n\n    int idX(const S &x) const\
    \ {\n        return std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n\
    \    }\n\n    int idY(const S &y) const {\n        return std::lower_bound(ys_all.begin(),\
    \ ys_all.end(), y) - ys_all.begin();\n    }\n\n    void build(){\n        std::sort(points.begin(),\
    \ points.end(),\n            [](const Point& a, const Point& b){\n           \
    \     if (a.x != b.x) {\n                    return a.x < b.x;\n             \
    \   }\n                return a.y < b.y;\n            }\n        );\n\n      \
    \  n = points.size();\n\n        xs.resize(n);\n        ys_all.resize(n);\n  \
    \      pref_all_sum.assign(n + 1, T{});\n\n        for(int i = 0; i < n; ++i){\n\
    \            xs[i] = points[i].x;\n            ys_all[i] = points[i].y;\n    \
    \        pref_all_sum[i + 1] = pref_all_sum[i] + points[i].weight;\n        }\n\
    \n        std::sort(ys_all.begin(), ys_all.end());\n        ys_all.erase(unique(ys_all.begin(),\
    \ ys_all.end()), ys_all.end());\n\n        sigma = ys_all.size();\n\n        if(n\
    \ == 0){\n            log_sigma = 0;\n            mid.clear();\n            pref_one.clear();\n\
    \            pref_zero_sum.clear();\n            return;\n        }\n\n      \
    \  log_sigma = 0;\n        while((1LL << log_sigma) < sigma){\n            log_sigma++;\n\
    \        }\n\n        log_sigma = std::max(log_sigma, 1);\n\n        mid.assign(log_sigma,\
    \ 0);\n        pref_one.assign(log_sigma, {});\n        pref_zero_sum.assign(log_sigma,\
    \ {});\n\n        std::vector<int> key(n);\n        std::vector<T> weight(n);\n\
    \n        for(int i = 0; i < n; ++i){\n            key[i] = idY(points[i].y);\n\
    \            weight[i] = points[i].weight;\n        }\n\n        for(int level\
    \ = 0; level < log_sigma; ++level){\n            const int bit = log_sigma - 1\
    \ - level;\n\n            pref_one[level].assign(n + 1, 0);\n            pref_zero_sum[level].assign(n\
    \ + 1, T{});\n\n            std::vector<int> zero_key;\n            std::vector<int>\
    \ one_key;\n            std::vector<T> zero_weight;\n            std::vector<T>\
    \ one_weight;\n\n            zero_key.reserve(n);\n            one_key.reserve(n);\n\
    \            zero_weight.reserve(n);\n            one_weight.reserve(n);\n\n \
    \           for(int i = 0; i < n; ++i){\n                const bool is_one = (key[i]\
    \ >> bit) & 1;\n\n                pref_one[level][i + 1] = pref_one[level][i]\
    \ + (is_one ? 1 : 0);\n                pref_zero_sum[level][i + 1] = pref_zero_sum[level][i]\
    \ + (is_one ? T{} : weight[i]);\n\n                if(is_one){\n             \
    \       one_key.push_back(key[i]);\n                    one_weight.push_back(weight[i]);\n\
    \                }else{\n                    zero_key.push_back(key[i]);\n   \
    \                 zero_weight.push_back(weight[i]);\n                }\n     \
    \       }\n\n            mid[level] = zero_key.size();\n\n            key.clear();\n\
    \            weight.clear();\n\n            key.reserve(n);\n            weight.reserve(n);\n\
    \n            key.insert(key.end(), zero_key.begin(), zero_key.end());\n     \
    \       key.insert(key.end(), one_key.begin(), one_key.end());\n\n           \
    \ weight.insert(weight.end(), zero_weight.begin(), zero_weight.end());\n     \
    \       weight.insert(weight.end(), one_weight.begin(), one_weight.end());\n \
    \       }\n    }\n\nprivate:\n    // x: [l, r)\n    // y: [0, upper_index)\n \
    \   T range_less_sum_index(int l, int r, int upper_index) const {\n        if(l\
    \ >= r || upper_index <= 0 || n == 0){\n            return T{};\n        }\n\n\
    \        if(upper_index >= sigma){\n            return pref_all_sum[r] - pref_all_sum[l];\n\
    \        }\n\n        T answer{};\n\n        for(int level = 0; level < log_sigma;\
    \ ++level){\n            const int bit = log_sigma - 1 - level;\n\n          \
    \  const int one_l = pref_one[level][l];\n            const int one_r = pref_one[level][r];\n\
    \n            const int zero_l = l - one_l;\n            const int zero_r = r\
    \ - one_r;\n\n            if((upper_index >> bit) & 1){\n                answer\
    \ += pref_zero_sum[level][r] - pref_zero_sum[level][l];\n                l = mid[level]\
    \ + one_l;\n                r = mid[level] + one_r;\n            }else{\n    \
    \            // 0 \u5074\u3078\u79FB\u52D5\n                l = zero_l;\n    \
    \            r = zero_r;\n            }\n        }\n\n        return answer;\n\
    \    }\n\npublic:\n    // (-INF, x) \xD7 (-INF, y)\n    T sum(const S &x, const\
    \ S &y) const {\n        const int r = idX(x);\n        const int upper_y = idY(y);\n\
    \        return range_less_sum_index(0, r, upper_y);\n    }\n\n    // [xl, xr)\
    \ \xD7 [yl, yr)\n    T sum(const S& xl, const S& yl, const S& xr, const S& yr)\
    \ const {\n        if(!(xl < xr) || !(yl < yr)){\n            return T{};\n  \
    \      }\n\n        const int l = idX(xl);\n        const int r = idX(xr);\n \
    \       const int lower_y = idY(yl);\n        const int upper_y = idY(yr);\n \
    \       return range_less_sum_index(l, r, upper_y) - range_less_sum_index(l, r,\
    \ lower_y);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/static_wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2026-09-23 21:34:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/static_wavelet_matrix.hpp
layout: document
redirect_from:
- /library/lib/data_structure/static_wavelet_matrix.hpp
- /library/lib/data_structure/static_wavelet_matrix.hpp.html
title: Static Wavelet Matrix
---
