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
    PROBLEM: https://judge.yosupo.jp/problem/count_points_in_triangle
    links:
    - https://judge.yosupo.jp/problem/count_points_in_triangle
  bundledCode: "#line 1 \"test/library_checker/geometry/count_points_in_triangle.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/count_points_in_triangle\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/geometry/geometry.hpp\"\
    \n\nnamespace Geometry{\n    using T = long long;\n    inline constexpr int type(T\
    \ x, T y){\n        if(!x && !y) return 0;\n        if(y < 0 || (y == 0 && x >\
    \ 0)) return -1;\n        return 1;\n    }\n\n    T abs(T x){\n        if(x <\
    \ 0) return -x;\n        return x;\n    }\n\n    struct Point{\n        T x, y;\n\
    \        Point(T X = 0, T Y = 0) : x(X), y(Y){}\n\n        inline bool operator==(const\
    \ Point &other) const {\n            return ((x == other.x) && (y == other.y));\n\
    \        }\n        inline bool operator!=(const Point &other) const {\n     \
    \       return ((x != other.x) || (y != other.y));\n        }\n        inline\
    \ bool operator<(const Point &other) const {\n            int L = type(x, y),\
    \ R = type(other.x, other.y);\n            if(L != R) return L < R;\n        \
    \    if(x * other.y == other.x * y) return abs(x + y) < abs(other.x + other.y);\n\
    \            return x * other.y > other.x * y;\n        }\n        inline bool\
    \ operator>(const Point &other) const {\n            int L = type(x, y), R = type(other.x,\
    \ other.y);\n            if(L != R) return L > R;\n            if(x * other.y\
    \ == other.x * y) return abs(x + y) > abs(other.x + other.y);\n            return\
    \ x * other.y < other.x * y;\n        }\n        inline Point operator+() const\
    \ noexcept { return *this; }\n        inline Point operator-() const noexcept\
    \ { return Point(-x, -y); }\n        inline Point operator+(const Point &p) const\
    \ { return Point(x + p.x, y + p.y); }\n        inline Point operator-(const Point\
    \ &p) const { return Point(x - p.x, y - p.y); }\n        inline Point &operator+=(const\
    \ Point &p) { return x += p.x, y += p.y, *this; }\n        inline Point &operator-=(const\
    \ Point &p) { return x -= p.x, y -= p.y, *this; }\n        inline T operator*(const\
    \ Point &p) const { return x * p.x + y * p.y; }\n        inline Point &operator*=(const\
    \ T &k) { return x *= k, y *= k, *this; }\n        inline Point operator*(const\
    \ T &k) { return (*this *= k); }\n        // floor\n        inline Point &operator/=(const\
    \ T &k) { return x /= k, y /= k, *this; }\n        inline Point operator/(const\
    \ T &k) { return (*this /= k); }\n\n        friend inline ostream &operator<<(ostream\
    \ &os, const Point &p) noexcept { return os << p.x << \" \" << p.y; }\n    };\n\
    \n    bool angle_equal(const Point &p, const Point &q){\n        int L = type(p.x,\
    \ p.y), R = type(q.x, q.y);\n        if(L != R) return false;\n        return\
    \ p.x * q.y == q.x * p.y;\n    }\n\n    long double rad2deg(long double rad){\n\
    \        return rad * (long double) 180 / acos(-1);\n    }\n\n    long double\
    \ deg2rad(long double deg){\n        return deg * acosl(-1) / (long double) 180;\n\
    \    }\n\n    Point rotate(Point &p, long double deg){\n        complex<T> comp(p.x,\
    \ p.y);\n        comp *= exp(complex<T>(.0, deg2rad(deg)));\n        return Point(comp.real(),\
    \ comp.imag());\n    }\n\n    T cross(const Point &p, const Point &q){\n     \
    \   return p.x * q.y - p.y * q.x;\n    }\n\n    T dot(const Point &p, const Point\
    \ &q){\n        return p.x * q.x + p.y * q.y;\n    }\n\n    // 2\u4E57\n    T\
    \ dist(const Point &p, const Point &q){\n        return (p.x - q.x) * (p.x - q.x)\
    \ + (p.y - q.y) * (p.y - q.y);\n    }\n\n    // 2\u500D\n    T polygonArea(const\
    \ vector<Point> &points){\n        const int n = points.size();\n        T res\
    \ = 0;\n        for(int i = 0; i < n - 1; i++){\n            res += cross(points[i],\
    \ points[i + 1]);\n        }\n        res += cross(points[n - 1], points[0]);\n\
    \        return res;\n    }\n\n    vector<Point> convexHull(vector<Point> points){\n\
    \        vector<Point> U, L, res;\n        sort(points.begin(), points.end(),\
    \ [](Point p, Point q){\n            return (p.x != q.x ? p.x < q.x : p.y < q.y);\n\
    \        });\n        points.erase(unique(points.begin(), points.end()), points.end());\n\
    \        const int n = points.size();\n        if((int) points.size() <= 2){\n\
    \            return points;\n        }\n\n        // lower\n        for(int i\
    \ = 0; i < n; i++){\n            int j = L.size();\n            // \u50BE\u304D\
    \u3067\u5DE6\u56DE\u308A\u304B\u3092\u30C1\u30A7\u30C3\u30AF\n            while(j\
    \ >= 2 && cross(L[j - 1] - L[j - 2], points[i] - L[j - 2]) <= 0){\n          \
    \      L.pop_back();\n                j--;\n            }\n            L.push_back(points[i]);\n\
    \        }\n\n        // upper\n        for(int i = n - 1; i >= 0; i--){\n   \
    \         int j = U.size();\n            while(j >= 2 && cross(U[j - 1] - U[j\
    \ - 2], points[i] - U[j - 2]) <= 0){\n                U.pop_back();\n        \
    \        j--;\n            }\n            U.push_back(points[i]);\n        }\n\
    \n        res = L;\n        for(int i = 1; i < (int) U.size() - 1; i++){\n   \
    \         res.push_back(U[i]);\n        }\n        return res;\n    }\n\n    //\
    \ \u70B9\u304C\u9818\u57DF\u5916\u90E8: 0, \u5185\u90E8: 1, \u5883\u754C\u4E0A\
    : 2\n    int inCcwConvex(Point p, const vector<Point> &points) {\n        const\
    \ int n = points.size();\n        T cr1 = cross(points[1] - points[0], p - points[0]);\n\
    \        T cr2 = cross(points[n - 1] - points[0], p - points[0]);\n        if(cr1\
    \ < 0 || 0 < cr2){\n            return 0;\n        }\n\n        int l = 1, r =\
    \ n - 1;\n        while(abs(r - l) > 1){\n            int mid = (l + r) / 2;\n\
    \            if(cross(p - points[0], points[mid] - points[0]) >= 0){\n       \
    \         r = mid;\n            } else{\n                l = mid;\n          \
    \  }\n        }\n\n        T cr = cross(points[l] - p, points[r] - p);\n     \
    \   if(cr == 0){\n            return 2;\n        } else if(cr > 0){\n        \
    \    if(cr1 == 0 || cr2 == 0){\n                return 2;\n            } else{\n\
    \                return 1;\n            }\n        } else{\n            return\
    \ 0;\n        }\n    }\n}\n#line 6 \"test/library_checker/geometry/count_points_in_triangle.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int n; cin >> n;\n    vector<Geometry::Point> d(n);\n    for(int i = 0; i\
    \ < n; i++){\n        cin >> d[i].x >> d[i].y;\n    }\n    int m; cin >> m;\n\
    \    vector<Geometry::Point> e(m);\n    for(int i = 0; i < m; i++){\n        cin\
    \ >> e[i].x >> e[i].y;\n    }\n    int q; cin >> q;\n    while(q--){\n       \
    \ int a, b, c; cin >> a >> b >> c;\n        vector<Geometry::Point> conv = Geometry::convexHull({d[a],\
    \ d[b], d[c]});\n        if((int) conv.size() <= 2){\n            cout << 0 <<\
    \ \"\\n\";\n            continue;\n        }\n        int ans = 0;\n        for(int\
    \ i = 0; i < m; i++){\n            if(Geometry::cross(conv[1] - conv[0], e[i]\
    \ - conv[0]) <= 0){\n                continue;\n            }\n            if(Geometry::cross(conv[2]\
    \ - conv[1], e[i] - conv[1]) <= 0){\n                continue;\n            }\n\
    \            if(Geometry::cross(conv[0] - conv[2], e[i] - conv[2]) <= 0){\n  \
    \              continue;\n            }\n            ans++;\n        }\n     \
    \   cout << ans << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/count_points_in_triangle\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/geometry/geometry.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int n; cin >> n;\n    vector<Geometry::Point> d(n);\n    for(int i = 0; i\
    \ < n; i++){\n        cin >> d[i].x >> d[i].y;\n    }\n    int m; cin >> m;\n\
    \    vector<Geometry::Point> e(m);\n    for(int i = 0; i < m; i++){\n        cin\
    \ >> e[i].x >> e[i].y;\n    }\n    int q; cin >> q;\n    while(q--){\n       \
    \ int a, b, c; cin >> a >> b >> c;\n        vector<Geometry::Point> conv = Geometry::convexHull({d[a],\
    \ d[b], d[c]});\n        if((int) conv.size() <= 2){\n            cout << 0 <<\
    \ \"\\n\";\n            continue;\n        }\n        int ans = 0;\n        for(int\
    \ i = 0; i < m; i++){\n            if(Geometry::cross(conv[1] - conv[0], e[i]\
    \ - conv[0]) <= 0){\n                continue;\n            }\n            if(Geometry::cross(conv[2]\
    \ - conv[1], e[i] - conv[1]) <= 0){\n                continue;\n            }\n\
    \            if(Geometry::cross(conv[0] - conv[2], e[i] - conv[2]) <= 0){\n  \
    \              continue;\n            }\n            ans++;\n        }\n     \
    \   cout << ans << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/geometry/geometry.hpp
  isVerificationFile: true
  path: test/library_checker/geometry/count_points_in_triangle.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/geometry/count_points_in_triangle.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/geometry/count_points_in_triangle.test.cpp
- /verify/test/library_checker/geometry/count_points_in_triangle.test.cpp.html
title: test/library_checker/geometry/count_points_in_triangle.test.cpp
---