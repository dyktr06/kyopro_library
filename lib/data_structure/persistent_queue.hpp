#pragma once

#include "../data_structure/persistent_array.hpp"

template<typename T>
struct PersistentQueue{
    PersistentArray<T> data;
    using node = typename PersistentArray<T>::Node*;
    vector<node> nodes;
    vector<int> front, back;
    int nxt = 1;

    PersistentQueue(int N) : nodes(N), front(N), back(N){
        nodes[0] = data.get_root();
    }

    int size(const int t) const {
        return back[t] - front[t];
    }

    bool empty(const int t) const {
        return size(t) == 0;
    }

    T top(const int t) {
        return data.get(front[t], nodes[t]);
    }

    int pop(const int t){
        nodes[nxt] = nodes[t];
        front[nxt] = front[t] + 1;
        back[nxt] = back[t];
        return nxt++;
    }
    
    int push(const T &x, const int t){
        nodes[nxt] = data.set(back[t], x, nodes[t]);
        front[nxt] = front[t];
        back[nxt] = back[t] + 1;
        return nxt++;
    }
};