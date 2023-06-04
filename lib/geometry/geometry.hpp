#pragma once

namespace Geometry{
    using T = long long;
    inline constexpr int type(T x, T y){
        if(!x && !y) return 0;
        if(y < 0 || (y == 0 && x > 0)) return -1;
        return 1;
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
            return x * other.y > other.x * y;
        }
        inline bool operator>(const Point &other) const {
            int L = type(x, y), R = type(other.x, other.y);
            if(L != R) return L > R;
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

        friend inline ostream& operator<<(ostream& os, const Point& p) noexcept { return os << p.x << " " << p.y; }
    };

    T cross(const Point &p, const Point &q){
        return p.x * q.y - p.y * q.x; 
    }

    T dot(const Point &p, const Point &q){
        return p.x * q.x + p.y * q.y; 
    }

    // 2乗
    T dist(const Point &p, const Point &q){
        return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
    }

    // 2倍
    T polygonArea(const vector<Point> &points){
        const int n = points.size();
        T res = 0;
        for(int i = 0; i < n - 1; i++){
            res += cross(points[i], points[i + 1]);
        }
        res += cross(points[n - 1], points[0]);
        return res;
    }

    vector<Point> convexHull(vector<Point> points){
        const int n = points.size();
        if(n <= 2){
            return points;
        }
        vector<Point> U, L, res;
        sort(points.begin(), points.end(), [](Point p, Point q){
            return (p.x == q.x ? p.x < q.x : p.y < q.y);
        });

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

    // 点が領域内部: 1, 境界上: 2, 外部: 0
    int inCcwConvex(Point p, const vector<Point> &points) {
        const int n = points.size();
        Point g = (points[0] + points[n / 3] + points[n * 2 / 3]);
        p *= 3;
        if(g == p) return 1;
        Point gp = p - g;

        int l = 0, r = n;
        while(abs(r - l) > 1) {
            int mid = (l + r) / 2;
            Point gl = points[l];
            gl *= 3, gl -= g;
            Point gm = points[mid];
            gm *= 3, gm -= g;
            if(cross(gl, gm) > 0) {
                if(cross(gl, gp) >= 0 && cross(gm, gp) <= 0) r = mid;
                else l = mid;
            }else{
                if(cross(gl, gp) <= 0 && cross(gm, gp) >= 0) l = mid;
                else r = mid;
            }
        }
        r %= n;
        Point pl = points[l], pr = points[r];
        pl *= 3, pr *= 3;
        T cr = cross(pl - p, pr - p);
        return (cr == 0) ? 2 : cr < 0 ? 0 : 1;
    }
}