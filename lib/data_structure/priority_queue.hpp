#pragma once

/**
 * @brief Eraseable　Priority Queue (削除可能優先度付きキュー)
 */

#include <queue>
#include <cassert>

template <typename T>
struct PriorityQueue{
    std::priority_queue<T> q, removed_q;

    PriorityQueue(){ }

    void normalize(){
        while(!q.empty() && !removed_q.empty()){
            if(q.top() == removed_q.top()){
                q.pop();
                removed_q.pop();
            } else{
                break;
            }
        }
    }

    void push(const T &x){
        q.push(x);
    }

    void erase(const T &x){
        removed_q.push(x);
    }

    size_t size(){
        return q.size() - removed_q.size();
    }

    bool empty(){
        return (size() == 0);
    }

    T top(){
        normalize();
        assert(!q.empty());
        return q.top();
    }
};
