#pragma once

/**
 * @brief Imos Linear (静的な一次関数の加算)
 * @docs docs/data_structure/imos_linear.md
 */

#include <vector>
#include <algorithm>

template <typename T>
struct imos_linear{
    int N;
    std::vector<T> imos1, imos0;
    imos_linear(int N) : N(N){ init(); }

    void init(){
        imos1.resize(N + 1);
        imos0.resize(N + 1);
    }

    // [l, r) に wX + v を加算
    // imos[l] += v, imos[l + 1] += v + w, ...
    void add(int l, int r, T v, T w){
        l = std::clamp(l, 0, N), r = std::clamp(r, 0, N);
        imos1[l] += w;
        imos1[r] -= w;
        imos0[l] += v - w;
        imos0[r] -= v + w * (r - l - 1);
    }

    void build(){
        for(int i = 0; i < N; i++){
            imos1[i + 1] += imos1[i];
            imos0[i] += imos1[i];
            imos0[i + 1] += imos0[i];
        }
    }

    T &operator [](int i){
        return imos0[i];
    }
};

template <class T, class Index = long long>
struct StaticImosLinear {
private:
    struct Event {
        Index x;
        T da;
        T db;
    };

    Index N;
    std::vector<Event> events;

    Index clamp_index(Index x) const {
        return std::clamp(x, Index(0), N);
    }

public:
    explicit StaticImosLinear(Index n) : N(n) {}

    // [l, r) に wX + v を加算
    // imos[l] += v, imos[l + 1] += v + w, ...
    void add(Index l, Index r, T v, T w) {
        l = clamp_index(l);
        r = clamp_index(r);

        if (l >= r) {
            return;
        }

        // v + w(x-l) = wx + (v-wl)
        const T a = w;
        const T b = v - w * T(l);

        events.push_back({l, a, b});
        events.push_back({r, -a, -b});
    }

    // [l, r) に wX + v を加算
    // imos[l] += wl + v, imos[l + 1] += w(l + 1) + v, ...
    void add_absolute(Index l, Index r, T v, T w) {
        l = clamp_index(l);
        r = clamp_index(r);

        if (l >= r) {
            return;
        }

        events.push_back({l, w, v});
        events.push_back({r, -w, -v});
    }

    std::vector<T> build(const std::vector<Index>& query) const {
        std::vector<Event> sorted_events = events;

        std::sort(
            sorted_events.begin(),
            sorted_events.end(),
            [](const Event& lhs, const Event& rhs) {
                return lhs.x < rhs.x;
            }
        );

        std::vector<int> order(query.size());
        std::iota(order.begin(), order.end(), 0);

        std::sort(
            order.begin(),
            order.end(),
            [&](int lhs, int rhs) {
                return query[lhs] < query[rhs];
            }
        );

        std::vector<T> answer(query.size(), T{});

        T a{};
        T b{};
        std::size_t event_index = 0;

        for (int query_index : order) {
            const Index x = query[query_index];
            while (
                event_index < sorted_events.size() &&
                sorted_events[event_index].x <= x
            ) {
                a += sorted_events[event_index].da;
                b += sorted_events[event_index].db;
                ++event_index;
            }

            answer[query_index] = a * T(x) + b;
        }
        return answer;
    }
};
