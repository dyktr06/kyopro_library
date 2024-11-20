
/**
 * @brief k-d Tree
 */

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>

template <class S,
    S(*op)(S, S),
    S(*e)(),
    class F,
    S(*mapping)(F, S, int),
    F(*composition)(F, F),
    F(*id)()>
struct KdTree{
    static constexpr long long INF = std::numeric_limits<long long>::max() / 3;
    static constexpr long long NINF = -INF;

    struct Point{
        long long x, y;
        S val;
        Point() {}
        Point(long long x, long long y, S val) : x(x), y(y), val(val) {}
    };

private:
    struct Node{
        long long min_x, max_x, min_y, max_y;
        int size, index;
        S sum;
        F lazy;
        Node() : min_x(INF), max_x(NINF), min_y(INF), max_y(NINF), size(0), index(-1), sum(e()), lazy(id()) {}
        Node(Point p, int i = -1) : min_x(p.x), max_x(p.x), min_y(p.y), max_y(p.y), size(1), index(i), sum(p.val), lazy(id()) {}
    };

    int _n, size, log;
    std::vector<Node> nodes;
    std::vector<std::pair<S, int>> info;

    void pull(int k){
        if(k == 0) return;
        nodes[k].size = nodes[2 * k].size + nodes[2 * k + 1].size;
        nodes[k].min_x = std::min(nodes[2 * k].min_x, nodes[2 * k + 1].min_x);
        nodes[k].max_x = std::max(nodes[2 * k].max_x, nodes[2 * k + 1].max_x);
        nodes[k].min_y = std::min(nodes[2 * k].min_y, nodes[2 * k + 1].min_y);
        nodes[k].max_y = std::max(nodes[2 * k].max_y, nodes[2 * k + 1].max_y);
        nodes[k].sum = op(nodes[2 * k].sum, nodes[2 * k + 1].sum);
    }

    void all_apply(int k, F f){
        nodes[k].sum = mapping(f, nodes[k].sum, nodes[k].size);
        if(k < size) nodes[k].lazy = composition(f, nodes[k].lazy);
    }

    void push(int k){
        all_apply(2 * k, nodes[k].lazy);
        all_apply(2 * k + 1, nodes[k].lazy);
        nodes[k].lazy = id();
    }

    void build(std::vector<std::pair<Point, int>> &v, int l, int r, bool div_x = true){
        int len = r - l;
        if(len == 1){
            nodes[size + l] = Node(v[l].first, v[l].second);
            if(v[l].second != -1){
                info[v[l].second].second = l;
            }
            return;
        }
        int m = (l + r) / 2;
        if(div_x){
            std::nth_element(v.begin() + l, v.begin() + m, v.begin() + r, [](const std::pair<Point, int> &p, const std::pair<Point, int> &q){
                return p.first.x < q.first.x;
            });
        }else{
            std::nth_element(v.begin() + l, v.begin() + m, v.begin() + r, [](const std::pair<Point, int> &p, const std::pair<Point, int> &q){
                return p.first.y < q.first.y;
            });
        }
        build(v, l, m, !div_x);
        build(v, m, r, !div_x);
    }

public:
    KdTree(const std::vector<std::pair<long long, long long>> &point) : _n(point.size()){
        std::vector<S> val(_n, e());
        init(point, val);
    }

    KdTree(const std::vector<std::pair<long long, long long>> &point, const std::vector<S> &val) : _n(point.size()){
        init(point, val);
    }

    void init(const std::vector<std::pair<long long, long long>> &point, const std::vector<S> &val){
        assert(point.size() == val.size());
        size = 1, log = 0;
        while(size < _n) size *= 2, log++;
        nodes.resize(size * 2);
        info.resize(size, {e(), -1});
        std::vector<std::pair<Point, int>> P(size, {Point{INF, INF, e()}, -1});
        for(int i = 0; i < _n; i++){
            P[i] = {Point(point[i].first, point[i].second, val[i]), i};
        }
        build(P, 0, size);
        for(int i = size - 1; i >= 1; i--) pull(i);
    }

    void on(int k){
        assert(0 <= k && k < _n);
        int p = info[k].second + size;
        for(int i = log; i >= 1; i--) push(p >> i);
        if(nodes[p].size == 1){
            return;
        }
        nodes[p].size = 1;
        nodes[p].sum = info[k].first;
        for(int i = 1; i <= log; i++) pull(p >> i);
    }

    void off(int k){
        assert(0 <= k && k < _n);
        int p = info[k].second + size;
        for(int i = log; i >= 1; i--) push(p >> i);
        info[k].first = nodes[p].sum;
        nodes[p].size = 0;
        nodes[p].sum = e();
        for(int i = 1; i <= log; i++) pull(p >> i);
    }

    void update(int k, const S &x){
        assert(0 <= k && k < _n);
        int p = info[k].second + size;
        for(int i = log; i >= 1; i--) push(p >> i);
        nodes[p].sum = x;
        for(int i = 1; i <= log; i++) pull(p >> i);
    }

    // [sx, tx] x [sy, ty]
    void apply(long long sx, long long tx, long long sy, long long ty, const F &f){
        if(sx > tx || sy > ty) return;
        std::queue<int> que;
        std::vector<int> st;
        que.push(1);
        while(que.size()){
            int p = que.front();
            que.pop();
            if(nodes[p].size == 0 || nodes[p].max_x < sx || tx < nodes[p].min_x || nodes[p].max_y < sy || ty < nodes[p].min_y) continue;
            if(sx <= nodes[p].min_x && nodes[p].max_x <= tx && sy <= nodes[p].min_y && nodes[p].max_y <= ty){
                all_apply(p, f);
                continue;
            }
            push(p);
            que.push(2 * p);
            que.push(2 * p + 1);
            st.push_back(p);
        }
        while(st.size()){
            pull(st.back());
            st.pop_back();
        }
    }

    // [sx, tx] x [sy, ty]
    S query(long long sx, long long tx, long long sy, long long ty){
        if(sx > tx || sy > ty) return e();
        std::queue<int> que;
        que.push(1);
        S res = e();
        while(que.size()){
            int p = que.front();
            que.pop();
            if(nodes[p].size == 0 || nodes[p].max_x < sx || tx < nodes[p].min_x || nodes[p].max_y < sy || ty < nodes[p].min_y) continue;
            if(sx <= nodes[p].min_x && nodes[p].max_x <= tx && sy <= nodes[p].min_y && nodes[p].max_y <= ty){
                res = op(res, nodes[p].sum);
                continue;
            }
            push(p);
            que.push(2 * p);
            que.push(2 * p + 1);
        }
        return res;
    }

    bool inside(long long dx, long long dy, long long dist){
        using i128 = __int128_t;
        return i128(dx) * dx + i128(dy) * dy <= i128(dist) * dist;
    }

    // ユークリッド距離
    template <typename T>
    void getNearbyPoints(long long x, long long y, long long dist, const T &f){
        std::queue<int> que;
        que.push(1);
        while(que.size()){
            int p = que.front();
            que.pop();
            if(nodes[p].size == 0 || !inside(std::clamp(x, nodes[p].min_x, nodes[p].max_x) - x, std::clamp(y, nodes[p].min_y, nodes[p].max_y) - y, dist)) continue;
            if(nodes[p].size == 1){
                f(nodes[p].index);
                continue;
            }
            que.push(2 * p);
            que.push(2 * p + 1);
        }
    }
};
