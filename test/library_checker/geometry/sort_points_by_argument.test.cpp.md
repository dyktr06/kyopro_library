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
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#line 1 \"test/library_checker/geometry/sort_points_by_argument.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/geometry/geometry.hpp\"\
    \n\nnamespace Geometry{\n    using T = long long;\n    inline constexpr int type(T\
    \ x, T y){\n        if(!x && !y) return 0;\n        if(y < 0 || (y == 0 && x >\
    \ 0)) return -1;\n        return 1;\n    }\n\n    struct Point{\n        T x,\
    \ y;\n        Point(T X = 0, T Y = 0) : x(X), y(Y){}\n\n        inline bool operator==(const\
    \ Point &other) const {\n            return ((x == other.x) && (y == other.y));\n\
    \        }\n        inline bool operator!=(const Point &other) const {\n     \
    \       return ((x != other.x) || (y != other.y));\n        }\n        inline\
    \ bool operator<(const Point &other) const {\n            int L = type(x, y),\
    \ R = type(other.x, other.y);\n            if(L != R) return L < R;\n        \
    \    return x * other.y > other.x * y;\n        }\n        inline bool operator>(const\
    \ Point &other) const {\n            int L = type(x, y), R = type(other.x, other.y);\n\
    \            if(L != R) return L > R;\n            return x * other.y < other.x\
    \ * y;\n        }\n        inline Point operator+() const noexcept { return *this;\
    \ }\n        inline Point operator-() const noexcept { return Point(-x, -y); }\n\
    \        inline Point operator+(const Point &p) const { return Point(x + p.x,\
    \ y + p.y); }\n        inline Point operator-(const Point &p) const { return Point(x\
    \ - p.x, y - p.y); }\n        inline Point &operator+=(const Point &p) { return\
    \ x += p.x, y += p.y, *this; }\n        inline Point &operator-=(const Point &p)\
    \ { return x -= p.x, y -= p.y, *this; }\n        inline T operator*(const Point\
    \ &p) const { return x * p.x + y * p.y; }\n        inline Point &operator*=(const\
    \ T &k) { return x *= k, y *= k, *this; }\n        inline Point operator*(const\
    \ T &k) { return (*this *= k); }\n        // floor\n        inline Point &operator/=(const\
    \ T &k) { return x /= k, y /= k, *this; }\n        inline Point operator/(const\
    \ T &k) { return (*this /= k); }\n\n        friend inline ostream& operator<<(ostream&\
    \ os, const Point& p) noexcept { return os << p.x << \" \" << p.y; }\n    };\n\
    \n    T cross(const Point &p, const Point &q){\n        return p.x * q.y - p.y\
    \ * q.x; \n    }\n\n    T dot(const Point &p, const Point &q){\n        return\
    \ p.x * q.x + p.y * q.y; \n    }\n\n    // 2\u4E57\n    T dist(const Point &p,\
    \ const Point &q){\n        return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y\
    \ - q.y);\n    }\n\n    // 2\u500D\n    T polygonArea(const vector<Point> &points){\n\
    \        const int n = points.size();\n        T res = 0;\n        for(int i =\
    \ 0; i < n - 1; i++){\n            res += cross(points[i], points[i + 1]);\n \
    \       }\n        res += cross(points[n - 1], points[0]);\n        return res;\n\
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
    \        res.push_back(U[i]);\n        }\n        return res;\n    }\n\n    //\
    \ \u70B9\u304C\u9818\u57DF\u5185\u90E8: 1, \u5883\u754C\u4E0A: 2, \u5916\u90E8\
    : 0\n    int inCcwConvex(Point p, const vector<Point> &points) {\n        const\
    \ int n = points.size();\n        Point g = (points[0] + points[n / 3] + points[n\
    \ * 2 / 3]);\n        p *= 3;\n        if(g == p) return 1;\n        Point gp\
    \ = p - g;\n\n        int l = 0, r = n;\n        while(abs(r - l) > 1) {\n   \
    \         int mid = (l + r) / 2;\n            Point gl = points[l];\n        \
    \    gl *= 3, gl -= g;\n            Point gm = points[mid];\n            gm *=\
    \ 3, gm -= g;\n            if(cross(gl, gm) > 0) {\n                if(cross(gl,\
    \ gp) >= 0 && cross(gm, gp) <= 0) r = mid;\n                else l = mid;\n  \
    \          }else{\n                if(cross(gl, gp) <= 0 && cross(gm, gp) >= 0)\
    \ l = mid;\n                else r = mid;\n            }\n        }\n        r\
    \ %= n;\n        Point pl = points[l], pr = points[r];\n        pl *= 3, pr *=\
    \ 3;\n        T cr = cross(pl - p, pr - p);\n        return (cr == 0) ? 2 : cr\
    \ < 0 ? 0 : 1;\n    }\n}\n#line 6 \"test/library_checker/geometry/sort_points_by_argument.test.cpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    vector<Geometry::Point> xy(n);\n  \
    \  for(int i = 0; i < n; i++){\n        int x, y; cin >> x >> y;\n        xy[i]\
    \ = Geometry::Point(x, y);\n    }\n    sort(xy.begin(), xy.end());\n    for(auto\
    \ p : xy){\n        cout << p << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/geometry/geometry.hpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    vector<Geometry::Point> xy(n);\n  \
    \  for(int i = 0; i < n; i++){\n        int x, y; cin >> x >> y;\n        xy[i]\
    \ = Geometry::Point(x, y);\n    }\n    sort(xy.begin(), xy.end());\n    for(auto\
    \ p : xy){\n        cout << p << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/geometry/geometry.hpp
  isVerificationFile: true
  path: test/library_checker/geometry/sort_points_by_argument.test.cpp
  requiredBy: []
  timestamp: '2023-06-05 06:59:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/geometry/sort_points_by_argument.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/geometry/sort_points_by_argument.test.cpp
- /verify/test/library_checker/geometry/sort_points_by_argument.test.cpp.html
title: test/library_checker/geometry/sort_points_by_argument.test.cpp
---
