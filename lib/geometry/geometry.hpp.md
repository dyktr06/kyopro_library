---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/cgl/cgl_3_a.test.cpp
    title: test/aoj/cgl/cgl_3_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/closest_pair.test.cpp
    title: test/library_checker/geometry/closest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/count_points_in_triangle.test.cpp
    title: test/library_checker/geometry/count_points_in_triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/furthest_pair.test.cpp
    title: test/library_checker/geometry/furthest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/sort_points_by_argument.test.cpp
    title: test/library_checker/geometry/sort_points_by_argument.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/static_convex_hull.test.cpp
    title: test/library_checker/geometry/static_convex_hull.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/geometry/geometry.hpp\"\n\nnamespace Geometry{\n   \
    \ using T = long long;\n    const T INFT = 9e18;\n    inline constexpr int type(T\
    \ x, T y){\n        if(!x && !y) return 0;\n        if(y < 0 || (y == 0 && x >\
    \ 0)) return -1;\n        return 1;\n    }\n\n    T absT(T x){\n        if(x <\
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
    \ T &k) { return (*this /= k); }\n        friend inline istream &operator>>(istream\
    \ &is, Point &p) noexcept {\n            is >> p.x >> p.y;\n            return\
    \ is;\n        }\n        friend inline ostream &operator<<(ostream &os, const\
    \ Point &p) noexcept { return os << p.x << \" \" << p.y; }\n    };\n\n    bool\
    \ angle_equal(const Point &p, const Point &q){\n        int L = type(p.x, p.y),\
    \ R = type(q.x, q.y);\n        if(L != R) return false;\n        return p.x *\
    \ q.y == q.x * p.y;\n    }\n\n    long double rad2deg(long double rad){\n    \
    \    return rad * (long double) 180 / acos(-1);\n    }\n\n    long double deg2rad(long\
    \ double deg){\n        return deg * acosl(-1) / (long double) 180;\n    }\n\n\
    \    Point rotate(Point &p, long double deg){\n        complex<T> comp(p.x, p.y);\n\
    \        comp *= exp(complex<T>(.0, deg2rad(deg)));\n        return Point(comp.real(),\
    \ comp.imag());\n    }\n\n    T cross(const Point &p, const Point &q){\n     \
    \   return p.x * q.y - p.y * q.x;\n    }\n\n    T dot(const Point &p, const Point\
    \ &q){\n        return p.x * q.x + p.y * q.y;\n    }\n\n    T manhattanDist(const\
    \ Point &p, const Point &q){\n        return absT(p.x - q.x) + absT(p.y - q.y);\n\
    \    }\n\n    // 2\u4E57\n    T dist(const Point &p, const Point &q){\n      \
    \  return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);\n    }\n\n  \
    \  // \u7DDA\u5206 p1-p2 \u3068\u7DDA\u5206 q1-q2\n    bool intersection(const\
    \ Point &p1, const Point &p2, const Point &q1, const Point &q2){\n        T a\
    \ = cross(p2 - p1, q1 - p1);\n        T b = cross(p2 - p1, q2 - p1);\n       \
    \ T c = cross(q2 - q1, p1 - q1);\n        T d = cross(q2 - q1, p2 - q1);\n   \
    \     if(a == 0 && b == 0){\n            T e = dot(p2 - p1, q1 - p1);\n      \
    \      T f = dot(p2 - p1, q2 - p1);\n            if(e > f) swap(e, f);\n     \
    \       return e <= dist(p1, p2) && 0 <= f;\n        }\n        return a * b <=\
    \ 0 && c * d <= 0;\n    }\n\n    // 2\u500D\n    T polygonArea(const vector<Point>\
    \ &points){\n        const int n = points.size();\n        T res = 0;\n      \
    \  for(int i = 0; i < n - 1; i++){\n            res += cross(points[i], points[i\
    \ + 1]);\n        }\n        res += cross(points[n - 1], points[0]);\n       \
    \ return absT(res);\n    }\n\n    vector<Point> convexHull(vector<Point> points){\n\
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
    \ 0;\n        }\n    }\n\n    pair<T, pair<int, int>> closestPair(vector<Point>\
    \ &points){\n        const int n = points.size();\n        assert(n >= 2);\n \
    \       vector<pair<Point, int>> sortp(n);\n        for(int i = 0; i < n; i++){\n\
    \            sortp[i] = {points[i], i};\n        }\n\n        sort(sortp.begin(),\
    \ sortp.end(), [](pair<Point, int> p, pair<Point, int> q){\n            return\
    \ (p.first.x != q.first.x ? p.first.x < q.first.x : p.first.y < q.first.y);\n\
    \        });\n\n        int ans1 = -1, ans2 = -1;\n        T min_dist = INFT;\n\
    \        auto dfs = [&](auto &self, int l, int r) -> T {\n            if(r - l\
    \ <= 1){\n                return INFT;\n            }\n            int mid = (l\
    \ + r) / 2;\n            T d = min(self(self, l, mid), self(self, mid, r));\n\
    \            vector<pair<Point, int>> tmp;\n            for(int i = l; i < r;\
    \ i++){\n                T dx = sortp[mid].first.x - sortp[i].first.x;\n     \
    \           if(dx * dx < d){\n                    tmp.push_back(sortp[i]);\n \
    \               }\n            }\n            sort(tmp.begin(), tmp.end(), [](pair<Point,\
    \ int> p, pair<Point, int> q){\n                return p.first.y < q.first.y;\n\
    \            });\n            for(int i = 0; i < (int) tmp.size(); i++){\n   \
    \             for(int j = i + 1; j < (int) tmp.size(); j++){\n               \
    \     T dy = tmp[j].first.y - tmp[i].first.y;\n                    if(dy * dy\
    \ >= d){\n                        break;\n                    }\n            \
    \        T td = dist(tmp[i].first, tmp[j].first);\n                    if(td <\
    \ d){\n                        d = td;\n                        if(d < min_dist){\n\
    \                            min_dist = d;\n                            ans1 =\
    \ tmp[i].second;\n                            ans2 = tmp[j].second;\n        \
    \                }\n                    }\n                }\n            }\n\
    \            return d;\n        };\n        dfs(dfs, 0, n);\n        return {min_dist,\
    \ {ans1, ans2}};\n    }\n\n    pair<T, pair<int, int>> furthestPair(vector<Point>\
    \ &points){\n        const int n = points.size();\n        assert(n >= 2);\n \
    \       vector<Point> convex = convexHull(points);\n        const int m = convex.size();\n\
    \n        map<pair<T, T>, int> mp;\n        for(int i = 0; i < n; i++){\n    \
    \        mp[{points[i].x, points[i].y}] = i;\n        }\n\n        vector<int>\
    \ idx(m);\n        for(int i = 0; i < m; i++){\n            idx[i] = mp[{convex[i].x,\
    \ convex[i].y}];\n        }\n\n        if(m == 1){\n            return {dist(points[0],\
    \ points[1]), {0, 1}};\n        }else if(m == 2){\n            return {dist(convex[0],\
    \ convex[1]), {idx[0], idx[1]}};\n        }\n\n        auto compare = [](Point\
    \ p, Point q){\n            return p.x != q.x ? p.x < q.x : p.y < q.y;\n     \
    \   };\n\n        int i = 0, j = 0;\n        for(int k = 0; k < m; k++){\n   \
    \         if(compare(convex[k], convex[i])) i = k;\n            if(compare(convex[j],\
    \ convex[k])) j = k;\n        }\n\n        int i0 = i, j0 = j;\n        T max_dist\
    \ = 0;\n        int ans1 = -1, ans2 = -1;\n        while(i != j0 || j != i0){\n\
    \            T d = dist(convex[i], convex[j]);\n            if(d > max_dist){\n\
    \                max_dist = d;\n                ans1 = idx[i];\n             \
    \   ans2 = idx[j];\n            }\n            if(cross(convex[(i + 1) % m] -\
    \ convex[i], convex[(j + 1) % m] - convex[j]) < 0){\n                i = (i +\
    \ 1) % m;\n            }else{\n                j = (j + 1) % m;\n            }\n\
    \        }\n        return {max_dist, {ans1, ans2}};\n    }\n}\n"
  code: "#pragma once\n\nnamespace Geometry{\n    using T = long long;\n    const\
    \ T INFT = 9e18;\n    inline constexpr int type(T x, T y){\n        if(!x && !y)\
    \ return 0;\n        if(y < 0 || (y == 0 && x > 0)) return -1;\n        return\
    \ 1;\n    }\n\n    T absT(T x){\n        if(x < 0) return -x;\n        return\
    \ x;\n    }\n\n    struct Point{\n        T x, y;\n        Point(T X = 0, T Y\
    \ = 0) : x(X), y(Y){}\n\n        inline bool operator==(const Point &other) const\
    \ {\n            return ((x == other.x) && (y == other.y));\n        }\n     \
    \   inline bool operator!=(const Point &other) const {\n            return ((x\
    \ != other.x) || (y != other.y));\n        }\n        inline bool operator<(const\
    \ Point &other) const {\n            int L = type(x, y), R = type(other.x, other.y);\n\
    \            if(L != R) return L < R;\n            if(x * other.y == other.x *\
    \ y) return abs(x + y) < abs(other.x + other.y);\n            return x * other.y\
    \ > other.x * y;\n        }\n        inline bool operator>(const Point &other)\
    \ const {\n            int L = type(x, y), R = type(other.x, other.y);\n     \
    \       if(L != R) return L > R;\n            if(x * other.y == other.x * y) return\
    \ abs(x + y) > abs(other.x + other.y);\n            return x * other.y < other.x\
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
    \ T &k) { return (*this /= k); }\n        friend inline istream &operator>>(istream\
    \ &is, Point &p) noexcept {\n            is >> p.x >> p.y;\n            return\
    \ is;\n        }\n        friend inline ostream &operator<<(ostream &os, const\
    \ Point &p) noexcept { return os << p.x << \" \" << p.y; }\n    };\n\n    bool\
    \ angle_equal(const Point &p, const Point &q){\n        int L = type(p.x, p.y),\
    \ R = type(q.x, q.y);\n        if(L != R) return false;\n        return p.x *\
    \ q.y == q.x * p.y;\n    }\n\n    long double rad2deg(long double rad){\n    \
    \    return rad * (long double) 180 / acos(-1);\n    }\n\n    long double deg2rad(long\
    \ double deg){\n        return deg * acosl(-1) / (long double) 180;\n    }\n\n\
    \    Point rotate(Point &p, long double deg){\n        complex<T> comp(p.x, p.y);\n\
    \        comp *= exp(complex<T>(.0, deg2rad(deg)));\n        return Point(comp.real(),\
    \ comp.imag());\n    }\n\n    T cross(const Point &p, const Point &q){\n     \
    \   return p.x * q.y - p.y * q.x;\n    }\n\n    T dot(const Point &p, const Point\
    \ &q){\n        return p.x * q.x + p.y * q.y;\n    }\n\n    T manhattanDist(const\
    \ Point &p, const Point &q){\n        return absT(p.x - q.x) + absT(p.y - q.y);\n\
    \    }\n\n    // 2\u4E57\n    T dist(const Point &p, const Point &q){\n      \
    \  return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);\n    }\n\n  \
    \  // \u7DDA\u5206 p1-p2 \u3068\u7DDA\u5206 q1-q2\n    bool intersection(const\
    \ Point &p1, const Point &p2, const Point &q1, const Point &q2){\n        T a\
    \ = cross(p2 - p1, q1 - p1);\n        T b = cross(p2 - p1, q2 - p1);\n       \
    \ T c = cross(q2 - q1, p1 - q1);\n        T d = cross(q2 - q1, p2 - q1);\n   \
    \     if(a == 0 && b == 0){\n            T e = dot(p2 - p1, q1 - p1);\n      \
    \      T f = dot(p2 - p1, q2 - p1);\n            if(e > f) swap(e, f);\n     \
    \       return e <= dist(p1, p2) && 0 <= f;\n        }\n        return a * b <=\
    \ 0 && c * d <= 0;\n    }\n\n    // 2\u500D\n    T polygonArea(const vector<Point>\
    \ &points){\n        const int n = points.size();\n        T res = 0;\n      \
    \  for(int i = 0; i < n - 1; i++){\n            res += cross(points[i], points[i\
    \ + 1]);\n        }\n        res += cross(points[n - 1], points[0]);\n       \
    \ return absT(res);\n    }\n\n    vector<Point> convexHull(vector<Point> points){\n\
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
    \ 0;\n        }\n    }\n\n    pair<T, pair<int, int>> closestPair(vector<Point>\
    \ &points){\n        const int n = points.size();\n        assert(n >= 2);\n \
    \       vector<pair<Point, int>> sortp(n);\n        for(int i = 0; i < n; i++){\n\
    \            sortp[i] = {points[i], i};\n        }\n\n        sort(sortp.begin(),\
    \ sortp.end(), [](pair<Point, int> p, pair<Point, int> q){\n            return\
    \ (p.first.x != q.first.x ? p.first.x < q.first.x : p.first.y < q.first.y);\n\
    \        });\n\n        int ans1 = -1, ans2 = -1;\n        T min_dist = INFT;\n\
    \        auto dfs = [&](auto &self, int l, int r) -> T {\n            if(r - l\
    \ <= 1){\n                return INFT;\n            }\n            int mid = (l\
    \ + r) / 2;\n            T d = min(self(self, l, mid), self(self, mid, r));\n\
    \            vector<pair<Point, int>> tmp;\n            for(int i = l; i < r;\
    \ i++){\n                T dx = sortp[mid].first.x - sortp[i].first.x;\n     \
    \           if(dx * dx < d){\n                    tmp.push_back(sortp[i]);\n \
    \               }\n            }\n            sort(tmp.begin(), tmp.end(), [](pair<Point,\
    \ int> p, pair<Point, int> q){\n                return p.first.y < q.first.y;\n\
    \            });\n            for(int i = 0; i < (int) tmp.size(); i++){\n   \
    \             for(int j = i + 1; j < (int) tmp.size(); j++){\n               \
    \     T dy = tmp[j].first.y - tmp[i].first.y;\n                    if(dy * dy\
    \ >= d){\n                        break;\n                    }\n            \
    \        T td = dist(tmp[i].first, tmp[j].first);\n                    if(td <\
    \ d){\n                        d = td;\n                        if(d < min_dist){\n\
    \                            min_dist = d;\n                            ans1 =\
    \ tmp[i].second;\n                            ans2 = tmp[j].second;\n        \
    \                }\n                    }\n                }\n            }\n\
    \            return d;\n        };\n        dfs(dfs, 0, n);\n        return {min_dist,\
    \ {ans1, ans2}};\n    }\n\n    pair<T, pair<int, int>> furthestPair(vector<Point>\
    \ &points){\n        const int n = points.size();\n        assert(n >= 2);\n \
    \       vector<Point> convex = convexHull(points);\n        const int m = convex.size();\n\
    \n        map<pair<T, T>, int> mp;\n        for(int i = 0; i < n; i++){\n    \
    \        mp[{points[i].x, points[i].y}] = i;\n        }\n\n        vector<int>\
    \ idx(m);\n        for(int i = 0; i < m; i++){\n            idx[i] = mp[{convex[i].x,\
    \ convex[i].y}];\n        }\n\n        if(m == 1){\n            return {dist(points[0],\
    \ points[1]), {0, 1}};\n        }else if(m == 2){\n            return {dist(convex[0],\
    \ convex[1]), {idx[0], idx[1]}};\n        }\n\n        auto compare = [](Point\
    \ p, Point q){\n            return p.x != q.x ? p.x < q.x : p.y < q.y;\n     \
    \   };\n\n        int i = 0, j = 0;\n        for(int k = 0; k < m; k++){\n   \
    \         if(compare(convex[k], convex[i])) i = k;\n            if(compare(convex[j],\
    \ convex[k])) j = k;\n        }\n\n        int i0 = i, j0 = j;\n        T max_dist\
    \ = 0;\n        int ans1 = -1, ans2 = -1;\n        while(i != j0 || j != i0){\n\
    \            T d = dist(convex[i], convex[j]);\n            if(d > max_dist){\n\
    \                max_dist = d;\n                ans1 = idx[i];\n             \
    \   ans2 = idx[j];\n            }\n            if(cross(convex[(i + 1) % m] -\
    \ convex[i], convex[(j + 1) % m] - convex[j]) < 0){\n                i = (i +\
    \ 1) % m;\n            }else{\n                j = (j + 1) % m;\n            }\n\
    \        }\n        return {max_dist, {ans1, ans2}};\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/geometry/geometry.hpp
  requiredBy: []
  timestamp: '2024-09-29 04:33:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/geometry/count_points_in_triangle.test.cpp
  - test/library_checker/geometry/furthest_pair.test.cpp
  - test/library_checker/geometry/sort_points_by_argument.test.cpp
  - test/library_checker/geometry/closest_pair.test.cpp
  - test/library_checker/geometry/static_convex_hull.test.cpp
  - test/aoj/cgl/cgl_3_a.test.cpp
documentation_of: lib/geometry/geometry.hpp
layout: document
redirect_from:
- /library/lib/geometry/geometry.hpp
- /library/lib/geometry/geometry.hpp.html
title: lib/geometry/geometry.hpp
---
