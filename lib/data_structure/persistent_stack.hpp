#pragma once

/**
 * @brief Persistent Stack (永続スタック)
 */

template<typename T>
struct PersistentStack{
    T val;
    PersistentStack *next = nullptr;
    int exist = 0;

    PersistentStack(const T &_val, PersistentStack *_next) : val(_val), next(_next){
        exist = _next->exist + 1;
    }

    PersistentStack(){
    }

    int size() const {
        return exist;
    }

    bool empty() const {
        return size() == 0;
    }

    T top() const {
        return val;
    }

    PersistentStack *pop() const {
        return next;
    }

    PersistentStack *push(const T &x){
        return new PersistentStack(x, this);
    }
};
