---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/geometry/geometry.hpp
    title: lib/geometry/geometry.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
  bundledCode: "#line 1 \"test/aoj/cgl/cgl_3_a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/geometry/geometry.hpp\"\
    \n\nnamespace Geometry{\n    inline constexpr int type(long long x, long long\
    \ y){\n        if(!x && !y) return 0;\n        if(y < 0 || (y == 0 && x > 0))\
    \ return -1;\n        return 1;\n    }\n\n    struct Point{\n        long long\
    \ x, y;\n        Point(long long X = 0, long long Y = 0) : x(X), y(Y){}\n\n  \
    \      inline bool operator==(const Point &other) const {\n            return\
    \ ((x == other.x) && (y == other.y));\n        }\n        inline bool operator!=(const\
    \ Point &other) const {\n            return ((x != other.x) || (y != other.y));\n\
    \        }\n        inline bool operator<(const Point &other) const {\n      \
    \      int L = type(x, y), R = type(other.x, other.y);\n            if(L != R)\
    \ return L < R;\n            return x * other.y > other.x * y;\n        }\n  \
    \      inline bool operator>(const Point &other) const {\n            int L =\
    \ type(x, y), R = type(other.x, other.y);\n            if(L != R) return L > R;\n\
    \            return x * other.y < other.x * y;\n        }\n        inline Point\
    \ operator+() const noexcept { return *this; }\n        inline Point operator-()\
    \ const noexcept { return Point(-x, -y); }\n        inline Point operator+(const\
    \ Point &p) const { return Point(x + p.x, y + p.y); }\n        inline Point operator-(const\
    \ Point &p) const { return Point(x - p.x, y - p.y); }\n        inline Point &operator+=(const\
    \ Point &p) { return x += p.x, y += p.y, *this; }\n        inline Point &operator-=(const\
    \ Point &p) { return x -= p.x, y -= p.y, *this; }\n        inline long long operator*(const\
    \ Point &p) const { return x * p.x + y * p.y; }\n        inline Point &operator*=(const\
    \ long long &k) { return x *= k, y *= k, *this; }\n        inline Point operator*(const\
    \ long long &k) { return (*this *= k); }\n        friend inline ostream& operator<<(ostream&\
    \ os, const Point& p) noexcept { return os << p.x << \" \" << p.y; }\n    };\n\
    \n    long long cross(const Point &p, const Point &q){\n        return p.x * q.y\
    \ - p.y * q.x; \n    }\n\n    long long polygonArea(const vector<Point> &points){\n\
    \        long long res = 0;\n        const int n = points.size();\n        for(int\
    \ i = 0; i < n - 1; i++){\n            res += cross(points[i], points[i + 1]);\n\
    \        }\n        res += cross(points[n - 1], points[0]);\n        return res;\n\
    \    }\n\n    vector<Point> convexHull(vector<Point> points){\n        const int\
    \ n = points.size();\n        if(n <= 2){\n            return points;\n      \
    \  }\n        vector<Point> U, L, res;\n        sort(points.begin(), points.end(),\
    \ [](Point p, Point q){\n            return (p.x == q.x ? p.x < q.x : p.y < q.y);\n\
    \        });\n\n        // lower \n        for(int i = 0; i < n; i++){\n     \
    \       int j = L.size();\n            // \u50BE\u304D\u3067\u5DE6\u56DE\u308A\
    \u304B\u3092\u30C1\u30A7\u30C3\u30AF\n            while(j >= 2 && cross(L[j -\
    \ 1] - L[j - 2], points[i] - L[j - 2]) <= 0){\n                L.pop_back();\n\
    \                j--;\n            }\n            L.push_back(points[i]);\n  \
    \      }\n\n        // upper\n        for(int i = n - 1; i >= 0; i--){\n     \
    \       int j = U.size();\n            while(j >= 2 && cross(U[j - 1] - U[j -\
    \ 2], points[i] - U[j - 2]) <= 0){\n                U.pop_back();\n          \
    \      j--;\n            }\n            U.push_back(points[i]);\n        }\n\n\
    \        res = L;\n        for(int i = 1; i < (int) U.size() - 1; i++){\n    \
    \        res.push_back(U[i]);\n        }\n        return res;\n    }\n}\n#line\
    \ 6 \"test/aoj/cgl/cgl_3_a.test.cpp\"\n\nint main(){\n    int n; cin >> n;\n \
    \   vector<Geometry::Point> xy(n);\n    for(int i = 0; i < n; i++){\n        int\
    \ x, y; cin >> x >> y;\n        xy[i] = Geometry::Point(x, y);\n    }\n    long\
    \ double ans = Geometry::polygonArea(xy);\n    ans /= 2;\n    printf(\"%.1Lf\\\
    n\", ans);\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/geometry/geometry.hpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    vector<Geometry::Point> xy(n);\n  \
    \  for(int i = 0; i < n; i++){\n        int x, y; cin >> x >> y;\n        xy[i]\
    \ = Geometry::Point(x, y);\n    }\n    long double ans = Geometry::polygonArea(xy);\n\
    \    ans /= 2;\n    printf(\"%.1Lf\\n\", ans);\n}"
  dependsOn:
  - lib/geometry/geometry.hpp
  isVerificationFile: true
  path: test/aoj/cgl/cgl_3_a.test.cpp
  requiredBy: []
  timestamp: '2023-06-03 01:59:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/cgl/cgl_3_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/cgl/cgl_3_a.test.cpp
- /verify/test/aoj/cgl/cgl_3_a.test.cpp.html
title: test/aoj/cgl/cgl_3_a.test.cpp
---
