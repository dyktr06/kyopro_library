#include <bits/stdc++.h>

using namespace std;

/* 
    SWAG<T>(op) : SWAG を構築します。
    fold() : 要素全てに op を適用させた値を計算します。: O(1)
    push(x) : x を末尾に追加します。: O(1)
    pop() : x を先頭から削除します。: 償却 O(1)
*/

template <typename T>
struct SWAG{
    using Op = function<T(T, T)>;

private:
    struct node{
    public:
        T val, sum;
        node(const T &val, const T &sum) : val(val), sum(sum) {}
    };

    Op op;
    stack<node> front_stack, back_stack;

public:
    SWAG(const Op &op = Op()) : op(op), front_stack(), back_stack() {}

    bool empty(){
        return front_stack.empty() && back_stack.empty();
    }

    size_t size(){
        return front_stack.size() + back_stack.size();
    }

    T fold(){
        if(front_stack.empty()){
            return back_stack.top().sum;
        }else if(back_stack.empty()){
            return front_stack.top().sum;
        }else{
            return op(front_stack.top().sum, back_stack.top().sum);
        }
    }

    void push(const T &x){
        if(back_stack.empty()){
            back_stack.emplace(x, x);
        }else{
            T s = op(back_stack.top().sum, x);
            back_stack.emplace(x, s);
        }
    }

    void pop(){
        if(front_stack.empty()){
            front_stack.emplace(back_stack.top().val, back_stack.top().val);
            back_stack.pop();
            while(!back_stack.empty()){
                T s = op(back_stack.top().val, front_stack.top().sum);
                front_stack.emplace(back_stack.top().val, s);
                back_stack.pop();
            }
        }
        front_stack.pop();
    }
};

// example (AOJ DSL_3_D)
int main(){
    int n, l; cin >> n >> l;
    auto op = [](int x1, int x2) -> int { return min(x1, x2); };
    SWAG<int> swag(op);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        swag.push(a);
        if(i >= l - 1){
            if(i >= l) cout << " ";
            cout << swag.fold();
            swag.pop();
        }
    }
    cout << "\n";
}