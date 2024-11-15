#pragma once

/**
 * @brief Convex Hull Trick
 * @docs docs/data_structure/convex_hull_trick.md
 */

#include <deque>
#include <utility>

// ax + by + c = 0 -> y = -b/a x - c/a
template <typename T>
struct Line{
    T a, b, c;
    Line(T A = 0, T B = 0, T C = 0) : a(A), b(B), c(C) {}
    // 傾き
    inline bool operator<(const Line &other) const {
        return -a * other.b < -other.a * b;
    }
    inline bool operator>(const Line &other) const {
        return -a * other.b > -other.a * b;
    }
    inline bool operator<=(const Line &other) const {
        return -a * other.b <= -other.a * b;
    }
    inline bool operator>=(const Line &other) const {
        return -a * other.b >= -other.a * b;
    }
};

template <typename T>
struct ConvexHullTrick{
    std::deque<Line<T>> deq;

    ConvexHullTrick() : deq(){
    }

    bool check(Line<T> l1, Line<T> l2, Line<T> l3){
        T a = ((-l3.c * l2.b) - (-l2.c * l3.b)) * ((-l2.a * l1.b) - (-l1.a * l2.b));
        T b = ((-l2.c * l1.b) - (-l1.c * l2.b)) * ((-l3.a * l2.b) - (-l2.a * l3.b));
        return a >= b;
    }

    // l1(x) < l2(x)
    bool comp(Line<T> l1, Line<T> l2, T x){
        // -(ax + c)/b < -(dx + f)/e
        return -(l1.a * x + l1.c) * l2.b < -(l2.a * x + l2.c) * l1.b;
    };

    // first/second
    std::pair<T, T> f(Line<T> l, T x){
        T a = -l.a * x - l.c;
        T b = l.b;
        if(b < 0) a *= -1, b *= -1;
        return std::make_pair(a, b);
    };

    // y = ax + b
    void add(T a, T b){
        Line<T> p(a, -1, b);
        while((int) deq.size() >= 2 && check(deq.at((int) deq.size() - 2), deq.at((int) deq.size() - 1), p)){
            deq.pop_back();
        }
        deq.push_back(p);
    }

    // ax + by + c = 0
    void add(T a, T b, T c){
        Line<T> p(a, b, c);
        while((int) deq.size() >= 2 && check(deq.at((int) deq.size() - 2), deq.at((int) deq.size() - 1), p)){
            deq.pop_back();
        }
        deq.push_back(p);
    }

    std::pair<T, T> query(T x){
        while((int) deq.size() >= 2 && !comp(deq.at(0), deq.at(1), x)){
            deq.pop_front();
        }
        return f(deq.at(0), x);
    }
};
