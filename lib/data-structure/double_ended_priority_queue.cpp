#include <bits/stdc++.h>

using namespace std;

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

// example
int main(){
    int n, q; cin >> n >> q;
    DoubleEndedPriorityQueue<int> depq;
    for(int i = 0; i < n; i++){
        int s; cin >> s;
        depq.push(s);
    }
    while(q--){
        int t; cin >> t;
        if(t == 0){
            int x; cin >> x;
            depq.push(x);
        }else if(t == 1){
            cout << depq.get_min() << "\n";
            depq.pop_min();
        }else{
            cout << depq.get_max() << "\n";
            depq.pop_max();
        }
    }
}