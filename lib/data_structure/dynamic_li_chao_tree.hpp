#pragma once

/**
 * @brief Dynamic Li Chao Tree
 * @docs docs/data_structure/dynamic_li_chao_tree.md
 */

template<typename T, T x_low, T x_high, T id>
struct DynamicLiChaoTree{
    struct Line{
        T a, b;

        Line(T _a, T _b) : a(_a), b(_b) {}

        inline T get(T x) const {
            return a * x + b;
        }
    };

    struct Node{
        Line x;
        Node *l, *r;

        Node(const Line &x) : x{x}, l{nullptr}, r{nullptr} {}
    };

    Node *root = nullptr;

    DynamicLiChaoTree() {}

private:
    Node *add_line_(Node *t, Line &x, const T &l, const T &r, const T &x_l, const T &x_r){
        if(!t){
            return new Node(x);
        }

        T t_l = t->x.get(l), t_r = t->x.get(r);

        if(t_l <= x_l && t_r <= x_r){
            return t;
        }else if(t_l >= x_l && t_r >= x_r){
            t->x = x;
            return t;
        }else{
            T m = (l + r) / 2;
            if(m == r) --m;
            T t_m = t->x.get(m), x_m = x.get(m);
            if(t_m > x_m){
                swap(t->x, x);
                if(t_l <= x_l){
                    t->l = add_line_(t->l, x, l, m, t_l, t_m);
                }else{
                    t->r = add_line_(t->r, x, m + 1, r, t_m + x.a, t_r);
                } 
            }else{
                if(x_l <= t_l){
                    t->l = add_line_(t->l, x, l, m, x_l, x_m);
                }else{
                    t->r = add_line_(t->r, x, m + 1, r, x_m + x.a, x_r);
                } 
            }
            return t;
        }
    }

    Node *add_segment_(Node *t, Line &x, const T &a, const T &b, const T &l, const T &r, const T &x_l, const T &x_r){
        if(r < a || b < l) return t;
        if(a <= l && r <= b){
            Line y{x};
            return add_line_(t, y, l, r, x_l, x_r);
        }
        if(t){
            T t_l = t->x.get(l), t_r = t->x.get(r);
            if(t_l <= x_l && t_r <= x_r) return t;
        }else{
            t = new Node(Line(0, id));
        }

        T m = (l + r) / 2;
        if(m == r) --m;
        T x_m = x.get(m);
        t->l = add_segment_(t->l, x, a, b, l, m, x_l, x_m);
        t->r = add_segment_(t->r, x, a, b, m + 1, r, x_m + x.a, x_r);
        return t;
    }

    T query_(const Node *t, const T &l, const T &r, const T &x_c) const {
        if(!t) return id;
        if(l == r) return t->x.get(x_c);
        T m = (l + r) / 2;
        if(m == r) --m;
        if(x_c <= m){
            return min(t->x.get(x_c), query_(t->l, l, m, x_c));
        }else{
            return min(t->x.get(x_c), query_(t->r, m + 1, r, x_c));
        }
    }

public:
    void add_line(const T &a, const T &b){
        Line x(a, b);
        root = add_line_(root, x, x_low, x_high, x.get(x_low), x.get(x_high));
    }

    void add_segment(const T &l, const T &r, const T &a, const T &b){
        Line x(a, b);
        root = add_segment_(root, x, l, r - 1, x_low, x_high, x.get(x_low), x.get(x_high));
    }

    T query(const T &x) const {
        return query_(root, x_low, x_high, x);
    }
};