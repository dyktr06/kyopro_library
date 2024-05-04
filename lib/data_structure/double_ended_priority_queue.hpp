#pragma once

template <typename T>
struct DoubleEndedPriorityQueue{
    priority_queue<T, vector<T>, greater<T>> min_q, removed_min;
    priority_queue<T> max_q, removed_max;
    DoubleEndedPriorityQueue(){ }

    void normalize(){
        while(!removed_min.empty() && min_q.top() == removed_min.top()) {
            removed_min.pop();
            min_q.pop();
        }
        while(!removed_max.empty() && max_q.top() == removed_max.top()) {
            removed_max.pop();
            max_q.pop();
        }
    }

    void push(const T &x){
        min_q.push(x);
        max_q.push(x);
    }

    void pop_min(){
        assert(!min_q.empty());
        normalize();
        removed_max.push(min_q.top());
        min_q.pop();
    }

    void pop_max(){
        assert(!max_q.empty());
        normalize();
        removed_min.push(max_q.top());
        max_q.pop();
    }

    T get_min(){
        assert(!min_q.empty());
        normalize();
        return min_q.top();
    }

    T get_max(){
        assert(!max_q.empty());
        normalize();
        return max_q.top();
    }
};
