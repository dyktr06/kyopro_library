#pragma once


template <typename T, int MAX_LOG, int NODES = 1 << 24>
struct BinaryTrie{
    struct Node{
        Node *nxt[2];
        int exist;
        vector<int> accept;
        Node() {}
    };
    Node *pool;
    int pid;
    T lazy;
    Node *nil;
    Node *root;

    BinaryTrie() : pid(0), lazy(0), nil(nullptr){
        pool = new Node[NODES];
        nil = _new();
        nil->nxt[0] = nil->nxt[1] = root = nil;
    }

    Node *_new(const int exist_ = 0, const int id = -1){
        pool[pid].nxt[0] = pool[pid].nxt[1] = nil;
        pool[pid].exist = exist_;
        if(id != -1) pool[pid].accept.push_back(id);
        return &(pool[pid++]);
    }

    Node *merge(Node *l, Node *r){
        pool[pid].nxt[0] = l;
        pool[pid].nxt[1] = r;
        pool[pid].exist = l->exist + r->exist;
        return &(pool[pid++]);
    }

private:
    Node *insert_(const T &x, const int id, Node *n, const int bit_idx){
        if(bit_idx == -1) {
            if(n == nil){
                return _new(1, id);
            }
            n->exist++;
            n->accept.push_back(id);
            return n;
        }
        if(((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1)){
            return merge(insert_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);
        } else{
            return merge(n->nxt[0], insert_(x, id, n->nxt[1], bit_idx - 1));
        }
    }

    Node *erase_(const T &x, const int id, Node *n, const int bit_idx){
        if(bit_idx == -1){
            n->exist--;
            return n;
        }
        if(((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1)){
            return merge(erase_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);
        } else{
            return merge(n->nxt[0], erase_(x, id, n->nxt[1], bit_idx - 1));
        }
    }

    pair<int, vector<int> &> find_(const T &x, Node *n, const int bit_idx){
        if(bit_idx == -1){
            return pair<int, vector<int> &>(n->exist, n->accept);
        }
        if(((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1)){
            return find_(x, n->nxt[0], bit_idx - 1);
        } else{
            return find_(x, n->nxt[1], bit_idx - 1);
        }
    }

    pair<T, vector<int> &> max_element_(Node *n, const int bit_idx) {
        if(bit_idx == -1){
            return pair<T, vector<int> &>(0, n->accept);
        }
        if(n->nxt[~(lazy >> bit_idx) & 1]->exist){
            auto ret = max_element_(n->nxt[~(lazy >> bit_idx) & 1], bit_idx - 1);
            ret.first |= T(1) << bit_idx;
            return ret;
        }
        return max_element_(n->nxt[(lazy >> bit_idx) & 1], bit_idx - 1);
    }

    pair<T, vector<int> &> min_element_(Node *n, const int bit_idx){
        if(bit_idx == -1){
            return pair<T, vector<int> &>(0, n->accept);
        }

        if(n->nxt[(lazy >> bit_idx) & 1]->exist){
            return min_element_(n->nxt[(lazy >> bit_idx) & 1], bit_idx - 1);
        }

        auto ret = min_element_(n->nxt[~(lazy >> bit_idx) & 1], bit_idx - 1);
        ret.first |= T(1) << bit_idx;
        return ret;
    }

    // 1-indexed, minimum-kth
    pair<T, vector<int> &> kth_element_(Node *n, const int k, const int bit_idx){
        if(bit_idx == -1){
            return pair<T, vector<int> &>(0, n->accept);
        }

        int ex0 = n->nxt[(lazy >> bit_idx) & 1]->exist;
        if(ex0 < k){
            auto ret = kth_element_(n->nxt[~(lazy >> bit_idx) & 1], k - ex0, bit_idx - 1);
            ret.first |= T(1) << bit_idx;
            return ret;
        }
        return kth_element_(n->nxt[(lazy >> bit_idx) & 1], k, bit_idx - 1);
    }

    int count_less_(Node *n, const T &x, const int bit_idx) {
        if(bit_idx == -1){
            return 0;
        }

        int ret = 0;
        bool f = (lazy >> bit_idx) & 1;
        if((x >> bit_idx & 1) && n->nxt[f]){
            ret += n->nxt[f]->exist;
        }
        if(n->nxt[f ^ (x >> bit_idx & 1)]){
            ret += count_less_(n->nxt[f ^ (x >> bit_idx & 1)], x, bit_idx - 1);
        }
        return ret;
    }

public:
    void insert(const T &x, const int id = -1){
        root = insert_(x, id, root, MAX_LOG);
    }

    void erase(const T &x, const int id = -1){
        root = erase_(x, id, root, MAX_LOG);
    }

    pair<int, vector<int> &> find(const T &x){
        return find_(x, root, MAX_LOG);
    }

    pair<T, vector<int> &> max_element(){
        return max_element_(root, MAX_LOG);
    }

    pair<T, vector<int> &> min_element(){
        return min_element_(root, MAX_LOG);
    }

    pair<T, vector<int> &> kth_element(const int k){
        return kth_element_(root, k, MAX_LOG);
    }

    int count_less(const T &x){
        return count_less_(root, x, MAX_LOG);
    }

    size_t size() const {
        if(root->exist <= 0){
            return 0;
        }
        return root->exist;
    }

    bool empty() const {
        return size() == 0;
    }

    void operate_xor(const T &x){
        lazy ^= x;
    }
};
