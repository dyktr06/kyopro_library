#pragma once

template<typename T>
struct PersistentArray{
    struct Node{
        T data;
        Node *ch[20] = {};
    };
    Node *root = nullptr;

    PersistentArray() {}

    Node *get_root(){
        return root;
    }

    void destructive_set(const int i, const T &val, Node *&t){
        if(!t) t = new Node();
        if(i == 0){
            t->data = val;
        } else{
            destructive_set(i / 20, val, t->ch[i % 20]);
        }
    }

    Node *set(const int i, const T &val, Node *&t){
        Node *res = new Node();
        if(t){
            memcpy(res->ch, t->ch, sizeof(t->ch));
            res->data = t->data;
        }
        if(i == 0){
            res->data = val;
        } else{
            res->ch[i % 20] = set(i / 20, val, res->ch[i % 20]);
        }
        return res;
    }

    T get(const int i, Node *t){
        if(!t) return T();
        if(i == 0){
            return t->data;
        } else{
            return get(i / 20, t->ch[i % 20]);
        }
    }
};
