#pragma once

/**
 * @brief Geometry (幾何ライブラリ)
 */

namespace Geometry{
    using T = long long;
    const T INFT = 9e18;
    inline constexpr int type(T x, T y){
        if(!x && !y) return 0;
        if(y < 0 || (y == 0 && x > 0)) return -1;
        return 1;
    }

    T absT(T x){
        if(x < 0) return -x;
        return x;
    }

    struct Point{
        T x, y;
        Point(T X = 0, T Y = 0) : x(X), y(Y){}

        inline bool operator==(const Point &other) const {
            return ((x == other.x) && (y == other.y));
        }
        inline bool operator!=(const Point &other) const {
            return ((x != other.x) || (y != other.y));
        }
        inline bool operator<(const Point &other) const {
            int L = type(x, y), R = type(other.x, other.y);
            if(L != R) return L < R;
            if(x * other.y == other.x * y) return abs(x + y) < abs(other.x + other.y);
            return x * other.y > other.x * y;
        }
        inline bool operator>(const Point &other) const {
            int L = type(x, y), R = type(other.x, other.y);
            if(L != R) return L > R;
            if(x * other.y == other.x * y) return abs(x + y) > abs(other.x + other.y);
            return x * other.y < other.x * y;
        }
        inline Point operator+() const noexcept { return *this; }
        inline Point operator-() const noexcept { return Point(-x, -y); }
        inline Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
        inline Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
        inline Point &operator+=(const Point &p) { return x += p.x, y += p.y, *this; }
        inline Point &operator-=(const Point &p) { return x -= p.x, y -= p.y, *this; }
        inline T operator*(const Point &p) const { return x * p.x + y * p.y; }
        inline Point &operator*=(const T &k) { return x *= k, y *= k, *this; }
        inline Point operator*(const T &k) { return (*this *= k); }
        // floor
        inline Point &operator/=(const T &k) { return x /= k, y /= k, *this; }
        inline Point operator/(const T &k) { return (*this /= k); }
        friend inline istream &operator>>(istream &is, Point &p) noexcept {
            is >> p.x >> p.y;
            return is;
        }
        friend inline ostream &operator<<(ostream &os, const Point &p) noexcept { return os << p.x << " " << p.y; }
    };

    bool angle_equal(const Point &p, const Point &q){
        int L = type(p.x, p.y), R = type(q.x, q.y);
        if(L != R) return false;
        return p.x * q.y == q.x * p.y;
    }

    long double rad2deg(long double rad){
        return rad * (long double) 180 / acos(-1);
    }

    long double deg2rad(long double deg){
        return deg * acosl(-1) / (long double) 180;
    }

    Point rotate(Point &p, long double deg){
        complex<T> comp(p.x, p.y);
        comp *= exp(complex<T>(.0, deg2rad(deg)));
        return Point(comp.real(), comp.imag());
    }

    T cross(const Point &p, const Point &q){
        return p.x * q.y - p.y * q.x;
    }

    T dot(const Point &p, const Point &q){
        return p.x * q.x + p.y * q.y;
    }

    T manhattanDist(const Point &p, const Point &q){
        return absT(p.x - q.x) + absT(p.y - q.y);
    }

    // 2乗
    T dist(const Point &p, const Point &q){
        return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
    }

    // 線分 p1-p2 と線分 q1-q2
    bool intersection(const Point &p1, const Point &p2, const Point &q1, const Point &q2){
        T a = cross(p2 - p1, q1 - p1);
        T b = cross(p2 - p1, q2 - p1);
        T c = cross(q2 - q1, p1 - q1);
        T d = cross(q2 - q1, p2 - q1);
        if(a == 0 && b == 0){
            T e = dot(p2 - p1, q1 - p1);
            T f = dot(p2 - p1, q2 - p1);
            if(e > f) swap(e, f);
            return e <= dist(p1, p2) && 0 <= f;
        }
        return a * b <= 0 && c * d <= 0;
    }

    // 2倍
    T polygonArea(const vector<Point> &points){
        const int n = points.size();
        T res = 0;
        for(int i = 0; i < n - 1; i++){
            res += cross(points[i], points[i + 1]);
        }
        res += cross(points[n - 1], points[0]);
        return absT(res);
    }

    vector<Point> convexHull(vector<Point> points){
        vector<Point> U, L, res;
        sort(points.begin(), points.end(), [](Point p, Point q){
            return (p.x != q.x ? p.x < q.x : p.y < q.y);
        });
        points.erase(unique(points.begin(), points.end()), points.end());
        const int n = points.size();
        if((int) points.size() <= 2){
            return points;
        }

        // lower
        for(int i = 0; i < n; i++){
            int j = L.size();
            // 傾きで左回りかをチェック
            while(j >= 2 && cross(L[j - 1] - L[j - 2], points[i] - L[j - 2]) <= 0){
                L.pop_back();
                j--;
            }
            L.push_back(points[i]);
        }

        // upper
        for(int i = n - 1; i >= 0; i--){
            int j = U.size();
            while(j >= 2 && cross(U[j - 1] - U[j - 2], points[i] - U[j - 2]) <= 0){
                U.pop_back();
                j--;
            }
            U.push_back(points[i]);
        }

        res = L;
        for(int i = 1; i < (int) U.size() - 1; i++){
            res.push_back(U[i]);
        }
        return res;
    }

    // 点が領域外部: 0, 内部: 1, 境界上: 2
    int inCcwConvex(Point p, const vector<Point> &points) {
        const int n = points.size();
        T cr1 = cross(points[1] - points[0], p - points[0]);
        T cr2 = cross(points[n - 1] - points[0], p - points[0]);
        if(cr1 < 0 || 0 < cr2){
            return 0;
        }

        int l = 1, r = n - 1;
        while(abs(r - l) > 1){
            int mid = (l + r) / 2;
            if(cross(p - points[0], points[mid] - points[0]) >= 0){
                r = mid;
            } else{
                l = mid;
            }
        }

        T cr = cross(points[l] - p, points[r] - p);
        if(cr == 0){
            return 2;
        } else if(cr > 0){
            if(cr1 == 0 || cr2 == 0){
                return 2;
            } else{
                return 1;
            }
        } else{
            return 0;
        }
    }

    pair<T, pair<int, int>> closestPair(vector<Point> &points){
        const int n = points.size();
        assert(n >= 2);
        vector<pair<Point, int>> sortp(n);
        for(int i = 0; i < n; i++){
            sortp[i] = {points[i], i};
        }

        sort(sortp.begin(), sortp.end(), [](pair<Point, int> p, pair<Point, int> q){
            return (p.first.x != q.first.x ? p.first.x < q.first.x : p.first.y < q.first.y);
        });

        int ans1 = -1, ans2 = -1;
        T min_dist = INFT;
        auto dfs = [&](auto &self, int l, int r) -> T {
            if(r - l <= 1){
                return INFT;
            }
            int mid = (l + r) / 2;
            T d = min(self(self, l, mid), self(self, mid, r));
            vector<pair<Point, int>> tmp;
            for(int i = l; i < r; i++){
                T dx = sortp[mid].first.x - sortp[i].first.x;
                if(dx * dx < d){
                    tmp.push_back(sortp[i]);
                }
            }
            sort(tmp.begin(), tmp.end(), [](pair<Point, int> p, pair<Point, int> q){
                return p.first.y < q.first.y;
            });
            for(int i = 0; i < (int) tmp.size(); i++){
                for(int j = i + 1; j < (int) tmp.size(); j++){
                    T dy = tmp[j].first.y - tmp[i].first.y;
                    if(dy * dy >= d){
                        break;
                    }
                    T td = dist(tmp[i].first, tmp[j].first);
                    if(td < d){
                        d = td;
                        if(d < min_dist){
                            min_dist = d;
                            ans1 = tmp[i].second;
                            ans2 = tmp[j].second;
                        }
                    }
                }
            }
            return d;
        };
        dfs(dfs, 0, n);
        return {min_dist, {ans1, ans2}};
    }

    pair<T, pair<int, int>> furthestPair(vector<Point> &points){
        const int n = points.size();
        assert(n >= 2);
        vector<Point> convex = convexHull(points);
        const int m = convex.size();

        map<pair<T, T>, int> mp;
        for(int i = 0; i < n; i++){
            mp[{points[i].x, points[i].y}] = i;
        }

        vector<int> idx(m);
        for(int i = 0; i < m; i++){
            idx[i] = mp[{convex[i].x, convex[i].y}];
        }

        if(m == 1){
            return {dist(points[0], points[1]), {0, 1}};
        }else if(m == 2){
            return {dist(convex[0], convex[1]), {idx[0], idx[1]}};
        }

        auto compare = [](Point p, Point q){
            return p.x != q.x ? p.x < q.x : p.y < q.y;
        };

        int i = 0, j = 0;
        for(int k = 0; k < m; k++){
            if(compare(convex[k], convex[i])) i = k;
            if(compare(convex[j], convex[k])) j = k;
        }

        int i0 = i, j0 = j;
        T max_dist = 0;
        int ans1 = -1, ans2 = -1;
        while(i != j0 || j != i0){
            T d = dist(convex[i], convex[j]);
            if(d > max_dist){
                max_dist = d;
                ans1 = idx[i];
                ans2 = idx[j];
            }
            if(cross(convex[(i + 1) % m] - convex[i], convex[(j + 1) % m] - convex[j]) < 0){
                i = (i + 1) % m;
            }else{
                j = (j + 1) % m;
            }
        }
        return {max_dist, {ans1, ans2}};
    }
}
