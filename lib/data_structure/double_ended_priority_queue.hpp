#pragma once

template <typename T>
struct DoubleEndedPriorityQueue{
    multiset<T> q;
    DoubleEndedPriorityQueue(){ }
    
    void push(const T &x){
        q.insert(x);
    }
    
    void pop_min(){
        assert(!q.empty());
        q.erase(q.begin());
    }
    
    void pop_max(){
        assert(!q.empty());
        q.erase(--q.end());
    }
    
    T get_min() const{
        return *q.begin();
    }
    
    T get_max() const{
        return *(--q.end());
    }
    
    size_t size() const{
        return q.size();
    }
};