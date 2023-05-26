#pragma once

struct SlopeTrick{
private:
    struct P{
        // x: 座標, c: 傾きの変化
        long long x, c;
        P(long long _x, long long _c) : x(_x), c(_c) {}
        friend inline bool operator<(const P &a, const P &b){ return a.x < b.x; }
        friend inline bool operator>(const P &a, const P &b){ return a.x > b.x; }
    };
    long long addL, addR, min_y;
    priority_queue<P> L;
    priority_queue<P, vector<P>, greater<P>> R;
    void pushL(long long x, long long c = 1){
        L.emplace(x - addL, c);
    }
    void pushR(long long x, long long c = 1){
        R.emplace(x - addR, c);
    }
    P getL(){
        return P{L.top().x + addL, L.top().c};
    }
    P getR(){
        return P{R.top().x + addR, R.top().c};
    }
    void popL(){ L.pop(); }
    void popR(){ R.pop(); }

public:
    SlopeTrick() : addL(0), addR(0), min_y(0) {}

    // return: x, f(x)
    pair<long long, long long> get_min(){
        long long x;
        if(L.empty()){
            if(R.empty()){
                x = 0;
            }else{
                x = getR().x;
            }
        }else{
            x = getL().x;
        }
        return make_pair(x, min_y);
    }

    void shift_L(long long a){
        addL += a;
    }

    void shift_R(long long a){
        addR += a;
    }

    // f(x) <- f(x - a)
    void shift_x(long long a){
        addL += a, addR += a;
    }

    // f(x) <- f(x) + a
    void shift_y(long long a){
        min_y += a;
    }

    // add (x - a)_+  ____/
    void add_xma(long long a, long long c = 1){
        long long used = 0;
        while(used < c && !(L.empty())){
            auto [X, C] = getL();
            if(X <= a) break;
            popL();
            long long tmp = min(c - used, C);
            pushR(X, tmp);
            if(C != tmp) pushL(X, C - tmp);
            min_y += (X - a) * tmp;
            used += tmp;
        }
        if(used) pushL(a, used);
        if(c - used) pushR(a, c - used);
    }

    // add (a - x)_+  \____
    void add_amx(long long a, long long c = 1){
        long long used = 0;
        while(used < c && !(R.empty())){
            auto [X, C] = getR();
            if(X >= a) break;
            popR();
            long long tmp = min(c - used, C);
            pushL(X, tmp);
            if(C != tmp) pushR(X, C - tmp);
            min_y += (a - X) * tmp;
            used += tmp;
        }
        if(used) pushR(a, used);
        if(c - used) pushL(a, c - used);
    }

    // add |x - a|  \____/
    void add_abs_xma(long long a, long long c = 1){
        add_xma(a, c);
        add_amx(a, c);
    }

    // chmin left side \_/ -> __/
    void chmin_left(){
        decltype(L){}.swap(L);
    }

    // chmin right side \_/ -> \__
    void chmin_right(){
        decltype(R){}.swap(R);
    }

    // return: f(x) = min_y + sum (a - x)_+ + sum (x - a)_+
    long long f(long long x){
        long long y = min_y;
        auto LL{L};
        while(!(LL.empty())){
            auto [X, C] = LL.top();
            X += addL;
            if(X < x) break;
            y += (X - x) * C;
            LL.pop();
        }
        auto RR{R};
        while(!(RR.empty())){
            auto [X, C] = RR.top();
            X += addR;
            if(X > x) break;
            y += (x - X) * C;
            RR.pop();
        }
        return y;
    }
};