#pragma once

namespace Geometry{
    inline constexpr int type(long long x, long long y){
        if(!x && !y) return 0;
        if(y < 0 || (y == 0 && x > 0)) return -1;
        return 1;
    }

    struct Point{
        long long x, y;
        Point(long long X = 0, long long Y = 0) : x(X), y(Y){}

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
        inline long long operator*(const Point &p) const { return x * p.x + y * p.y; }
        inline Point &operator*=(const long long &k) { return x *= k, y *= k, *this; }
        inline Point operator*(const long long &k) { return (*this *= k); }
        friend inline ostream& operator<<(ostream& os, const Point& p) noexcept { return os << p.x << " " << p.y; }
    };

    long long cross(const Point &p, const Point &q){
        return p.x * q.y - p.y * q.x; 
    }

    long long polygonArea(const vector<Point> &points){
        long long res = 0;
        const int n = points.size();
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
}