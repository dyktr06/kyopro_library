---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../others/random.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../math/rho.hpp\"\n#include \"../others/random.hpp\"\
    \n\nlong long primitiveRoot(long long p){\n    auto modpow = [](__int128_t x,\
    \ long long n, const long long &m){\n        __int128_t ret = 1 % m;\n       \
    \ x %= m;\n        while(n > 0){\n            if(n & 1) (ret *= x) %= m;\n   \
    \         (x *= x) %= m;\n            n >>= 1;\n        }\n        return ret;\n\
    \    };\n\n    RandomNumber rnd(1, p - 1);\n    vector<unsigned long long> f =\
    \ Rho::factorize(p - 1);\n    while(true){\n        long long a = rnd.get();\n\
    \        bool is_ok = true;\n        for(auto x : f){\n            if(modpow(a,\
    \ (p - 1) / x, p) == 1){\n                is_ok = false;\n                break;\n\
    \            }\n        }\n        if(is_ok){\n            return a;\n       \
    \ }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/primitive_root.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/primitive_root.hpp
layout: document
redirect_from:
- /library/lib/math/primitive_root.hpp
- /library/lib/math/primitive_root.hpp.html
title: lib/math/primitive_root.hpp
---
