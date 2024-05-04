#pragma once

/**
 * @brief DESWAG
 * @docs docs/data_structure/deswag.md
 */

template <typename T>
struct DESWAG{
    using Op = function<T(T, T)>;

private:
    struct node{
    public:
        T val, sum;
        node(const T &val, const T &sum) : val(val), sum(sum) {}
    };

    Op op;
    stack<node> front_stack, back_stack, temp_stack;

public:
    DESWAG(const Op &op = Op()) : op(op), front_stack(), back_stack(), temp_stack() {}

    bool empty(){
        return front_stack.empty() && back_stack.empty();
    }

    size_t size(){
        return front_stack.size() + back_stack.size();
    }

    T fold(){
        if(front_stack.empty()){
            return back_stack.top().sum;
        } else if(back_stack.empty()){
            return front_stack.top().sum;
        } else{
            return op(front_stack.top().sum, back_stack.top().sum);
        }
    }

    void push_front(const T &x){
        if(front_stack.empty()){
            front_stack.emplace(x, x);
        } else{
            T s = op(x, front_stack.top().sum);
            front_stack.emplace(x, s);
        }
    }

    void push_back(const T &x){
        if(back_stack.empty()){
            back_stack.emplace(x, x);
        } else{
            T s = op(back_stack.top().sum, x);
            back_stack.emplace(x, s);
        }
    }

    void pop_front(){
        if(front_stack.empty()){
            int half = (back_stack.size() + 1) / 2;
            while(!back_stack.empty()){
                if(back_stack.size() == half){
                    front_stack.emplace(back_stack.top().val, back_stack.top().val);
                } else if(back_stack.size() < half){
                    T s = op(back_stack.top().val, front_stack.top().sum);
                    front_stack.emplace(back_stack.top().val, s);
                } else{
                    temp_stack.emplace(back_stack.top().val, back_stack.top().val);
                }
                back_stack.pop();
            }
            if(!temp_stack.empty()){
                back_stack.emplace(temp_stack.top().val, temp_stack.top().val);
                temp_stack.pop();
                while(!temp_stack.empty()){
                    T s = op(back_stack.top().sum, temp_stack.top().val);
                    back_stack.emplace(temp_stack.top().val, s);
                    temp_stack.pop();
                }
            }
        }
        front_stack.pop();
    }

    void pop_back(){
        if(back_stack.empty()){
            int half = (front_stack.size() + 1) / 2;
            while(!front_stack.empty()){
                if(front_stack.size() == half){
                    back_stack.emplace(front_stack.top().val, front_stack.top().val);
                } else if(front_stack.size() < half){
                    T s = op(back_stack.top().sum, front_stack.top().val);
                    back_stack.emplace(front_stack.top().val, s);
                } else{
                    temp_stack.emplace(front_stack.top().val, front_stack.top().val);
                }
                front_stack.pop();
            }
            if(!temp_stack.empty()){
                front_stack.emplace(temp_stack.top().val, temp_stack.top().val);
                temp_stack.pop();
                while(!temp_stack.empty()){
                    T s = op(temp_stack.top().val, front_stack.top().sum);
                    front_stack.emplace(temp_stack.top().val, s);
                    temp_stack.pop();
                }
            }
        }
        back_stack.pop();
    }
};
