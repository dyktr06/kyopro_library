#pragma once

// ある x に対し、直線集合の中で最小値をとるような直線の値を求めます。
// 追加される直線の傾きが単調増加、計算する最小値の座標が単調増加である必要があります。
// N本の直線追加 : O(N)、Q回のクエリ : O(Q)
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