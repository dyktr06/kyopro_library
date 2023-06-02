#pragma once

/**
 * @brief Convex Hull Trick
 * @docs docs/data_structure/convexhulltrick.md
 */

template <typename T>
struct ConvexHullTrick{
    deque<pair<T, T>> deq;

    ConvexHullTrick(): deq(){
    }

    bool check(pair<T, T> line1, pair<T, T> line2, pair<T, T> line3){
        return (line2.first - line1.first) * (line3.second - line2.second) >= (line2.second - line1.second) * (line3.first - line2.first);
    }

    T f(pair<T, T> line, T x){
        return line.first * x + line.second;
    }

    // ax + b
    void add(T a, T b){
        pair<T, T> p = {a, b};
        while((int) deq.size() >= 2 && check(deq.at((int) deq.size() - 2), deq.at((int) deq.size() - 1), p)){
            deq.pop_back();
        }
        deq.push_back(p);
    }

    T query(T x){
        while((int) deq.size() >= 2 && f(deq.at(0), x) >= f(deq.at(1), x)){
            deq.pop_front();
        }
        return f(deq.at(0), x);
    }
};