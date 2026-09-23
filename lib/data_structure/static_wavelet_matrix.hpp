#pragma once

/**
 * @brief Static Wavelet Matrix
 */

template <class S, class T>
struct StaticWaveletMatrix{
    struct Point{
        S x, y;
        T weight;
    };

    std::vector<Point> points;
    std::vector<S> xs;
    std::vector<S> ys_all;

    int n = 0;
    int sigma = 0;
    int log_sigma = 0;

    // 各レベルにおける 0 側の要素数
    std::vector<int> mid;

    // pref_one[level][i]
    // = level における区間 [0, i) の 1-bit の個数
    std::vector<std::vector<int>> pref_one;

    // pref_zero_sum[level][i]
    // = level における区間 [0, i) のうち、
    //   対象 bit が 0 である要素の重み和
    std::vector<std::vector<T>> pref_zero_sum;

    std::vector<T> pref_all_sum;

    void add(const S& x, const S& y, const T& weight){
        points.push_back({x, y, weight});
    }

    int idX(const S &x) const {
        return std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    }

    int idY(const S &y) const {
        return std::lower_bound(ys_all.begin(), ys_all.end(), y) - ys_all.begin();
    }

    void build(){
        std::sort(points.begin(), points.end(),
            [](const Point& a, const Point& b){
                if (a.x != b.x) {
                    return a.x < b.x;
                }
                return a.y < b.y;
            }
        );

        n = points.size();

        xs.resize(n);
        ys_all.resize(n);
        pref_all_sum.assign(n + 1, T{});

        for(int i = 0; i < n; ++i){
            xs[i] = points[i].x;
            ys_all[i] = points[i].y;
            pref_all_sum[i + 1] = pref_all_sum[i] + points[i].weight;
        }

        std::sort(ys_all.begin(), ys_all.end());
        ys_all.erase(unique(ys_all.begin(), ys_all.end()), ys_all.end());

        sigma = ys_all.size();

        if(n == 0){
            log_sigma = 0;
            mid.clear();
            pref_one.clear();
            pref_zero_sum.clear();
            return;
        }

        log_sigma = 0;
        while((1LL << log_sigma) < sigma){
            log_sigma++;
        }

        log_sigma = std::max(log_sigma, 1);

        mid.assign(log_sigma, 0);
        pref_one.assign(log_sigma, {});
        pref_zero_sum.assign(log_sigma, {});

        std::vector<int> key(n);
        std::vector<T> weight(n);

        for(int i = 0; i < n; ++i){
            key[i] = idY(points[i].y);
            weight[i] = points[i].weight;
        }

        for(int level = 0; level < log_sigma; ++level){
            const int bit = log_sigma - 1 - level;

            pref_one[level].assign(n + 1, 0);
            pref_zero_sum[level].assign(n + 1, T{});

            std::vector<int> zero_key;
            std::vector<int> one_key;
            std::vector<T> zero_weight;
            std::vector<T> one_weight;

            zero_key.reserve(n);
            one_key.reserve(n);
            zero_weight.reserve(n);
            one_weight.reserve(n);

            for(int i = 0; i < n; ++i){
                const bool is_one = (key[i] >> bit) & 1;

                pref_one[level][i + 1] = pref_one[level][i] + (is_one ? 1 : 0);
                pref_zero_sum[level][i + 1] = pref_zero_sum[level][i] + (is_one ? T{} : weight[i]);

                if(is_one){
                    one_key.push_back(key[i]);
                    one_weight.push_back(weight[i]);
                }else{
                    zero_key.push_back(key[i]);
                    zero_weight.push_back(weight[i]);
                }
            }

            mid[level] = zero_key.size();

            key.clear();
            weight.clear();

            key.reserve(n);
            weight.reserve(n);

            key.insert(key.end(), zero_key.begin(), zero_key.end());
            key.insert(key.end(), one_key.begin(), one_key.end());

            weight.insert(weight.end(), zero_weight.begin(), zero_weight.end());
            weight.insert(weight.end(), one_weight.begin(), one_weight.end());
        }
    }

private:
    // x: [l, r)
    // y: [0, upper_index)
    T range_less_sum_index(int l, int r, int upper_index) const {
        if(l >= r || upper_index <= 0 || n == 0){
            return T{};
        }

        if(upper_index >= sigma){
            return pref_all_sum[r] - pref_all_sum[l];
        }

        T answer{};

        for(int level = 0; level < log_sigma; ++level){
            const int bit = log_sigma - 1 - level;

            const int one_l = pref_one[level][l];
            const int one_r = pref_one[level][r];

            const int zero_l = l - one_l;
            const int zero_r = r - one_r;

            if((upper_index >> bit) & 1){
                answer += pref_zero_sum[level][r] - pref_zero_sum[level][l];
                l = mid[level] + one_l;
                r = mid[level] + one_r;
            }else{
                // 0 側へ移動
                l = zero_l;
                r = zero_r;
            }
        }

        return answer;
    }

public:
    // (-INF, x) × (-INF, y)
    T sum(const S &x, const S &y) const {
        const int r = idX(x);
        const int upper_y = idY(y);
        return range_less_sum_index(0, r, upper_y);
    }

    // [xl, xr) × [yl, yr)
    T sum(const S& xl, const S& yl, const S& xr, const S& yr) const {
        if(!(xl < xr) || !(yl < yr)){
            return T{};
        }

        const int l = idX(xl);
        const int r = idX(xr);
        const int lower_y = idY(yl);
        const int upper_y = idY(yr);
        return range_less_sum_index(l, r, upper_y) - range_less_sum_index(l, r, lower_y);
    }
};
