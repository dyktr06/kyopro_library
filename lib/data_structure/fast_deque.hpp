#pragma once

template <typename T>
struct FastDeque{
    int l = 1, r = 0;
    vector<T> L, R;
    
    FastDeque(){}

    T front(){
        if(l <= 0){
            return L[-l];
        }else{
            return R[l - 1];
        }
    }

    void push_front(int v){
        l--;
        if(l <= 0){
            if((int) L.size() == -l){
                L.push_back(v);
            }else{
                L[-l] = v;
            }
        }else{
            R[l - 1] = v;
        }
    }

    void pop_front(){
        l++;
    }

    T back(){
        if(r <= 0){
            return L[-r];
        }else{
            return R[r - 1];
        }
    }

    void push_back(int v){
        if(r < 0){
            L[-r - 1] = v;
        }else{
            if((int) R.size() == r){
                R.push_back(v);
            }else{
                R[r] = v;
            }
        }
        r++;
    }

    void pop_back(){
        r--;
    }

    bool empty(){
        return (r - l + 1) == 0;
    }

    size_t size(){
        return (r - l + 1);
    }
};