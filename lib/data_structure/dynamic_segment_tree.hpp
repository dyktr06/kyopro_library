#pragma once

/**
 * @brief Dynamic Segment Tree
 * @see https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644
 */

#include <cassert>
#include <memory>

template <typename T, T (*op)(T, T), T(*e)()>
struct DynamicSegTree{
    DynamicSegTree(int n) : n(n), root(nullptr) {}
private:
    struct node;
    using node_ptr = std::unique_ptr<node>;

    struct node{
        int index;
        T value, product;
        node_ptr left, right;

        node(int index, T value)
            : index(index),
                value(value),
                product(value),
                left(nullptr),
                right(nullptr) {}

        void refresh() {
            product = op(op(left ? left->product : e(), value), right ? right->product : e());
        }
    };

    const int n;
    node_ptr root;

    void update(node_ptr& t, int a, int b, int i, T x) const {
        if(!t){
            t = std::make_unique<node>(i, x);
            return;
        }
        if(t->index == i){
            t->value = x;
            t->refresh();
            return;
        }
        int c = (a + b) >> 1;
        if(i < c){
            if(t->index < i) std::swap(t->index, i), std::swap(t->value, x);
            update(t->left, a, c, i, x);
        } else {
            if(i < t->index) std::swap(i, t->index), std::swap(x, t->value);
            update(t->right, c, b, i, x);
        }
        t->refresh();
    }

    T get(const node_ptr& t, int a, int b, int i) const {
        if(!t) return e();
        if(t->index == i) return t->value;
        int c = (a + b) >> 1;
        if(i < c) return get(t->left, a, c, i);
        else return get(t->right, c, b, i);
    }

    T query(const node_ptr& t, int a, int b, int l, int r) const {
        if(!t || b <= l || r <= a) return e();
        if(l <= a && b <= r) return t->product;
        int c = (a + b) >> 1;
        T result = query(t->left, a, c, l, r);
        if(l <= t->index && t->index < r) result = op(result, t->value);
        return op(result, query(t->right, c, b, l, r));
    }

    void reset(node_ptr& t, int a, int b, int l, int r) const {
        if(!t || b <= l || r <= a) return;
        if(l <= a && b <= r){
            t.reset();
            return;
        }
        int c = (a + b) >> 1;
        reset(t->left, a, c, l, r);
        reset(t->right, c, b, l, r);
        t->refresh();
    }

    template <class F>
    int max_right(const node_ptr& t, int a, int b, int l, const F& f, T& product) const {
        if(!t || b <= l) return n;
        if(f(op(product, t->product))){
            product = op(product, t->product);
            return n;
        }
        int c = (a + b) >> 1;
        int result = max_right(t->left, a, c, l, f, product);
        if(result != n) return result;
        if(l <= t->index) {
            product = op(product, t->value);
            if(!f(product)) return t->index;
        }
        return max_right(t->right, c, b, l, f, product);
    }

    template <class F>
    int min_left(const node_ptr& t, int a, int b, int r, const F& f, T& product) const {
        if(!t || r <= a) return 0;
        if(f(op(t->product, product))){
            product = op(t->product, product);
            return 0;
        }
        int c = (a + b) >> 1;
        int result = min_left(t->right, c, b, r, f, product);
        if(result != 0) return result;
        if(t->index < r){
            product = op(t->value, product);
            if(!f(product)) return t->index + 1;
        }
        return min_left(t->left, a, c, r, f, product);
    }

public:
    void update(int i, T x) {
        assert(i < n);
        update(root, 0, n, i, x);
    }

    T get(int i) const {
        assert(i < n);
        return get(root, 0, n, i);
    }

    T query(int l, int r) const {
        assert(l <= r && r <= n);
        return query(root, 0, n, l, r);
    }

    T all_query() const {
        return root ? root->product : e();
    }

    void reset(int l, int r) {
        assert(l <= r && r <= n);
        return reset(root, 0, n, l, r);
    }

    template <bool (*f)(T)>
    int max_right(int l) const {
        return max_right(l, [](T x) { return f(x); });
    }

    template <class F>
    int max_right(int l, const F& f) const {
        assert(l <= n);
        T product = e();
        assert(f(product));
        return max_right(root, 0, n, l, f, product);
    }

    template <bool (*f)(T)>
    int min_left(int r) const {
        return min_left(r, [](T x) { return f(x); });
    }

    template <class F>
    int min_left(int r, const F& f) const {
        assert(r <= n);
        T product = e();
        assert(f(product));
        return min_left(root, 0, n, r, f, product);
    }
};
