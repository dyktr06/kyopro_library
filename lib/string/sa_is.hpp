#pragma once

#include <vector>

// 参考: https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/sa-is.html
template <typename T>
struct SA_IS{
    std::vector<int> SA;

private:
    std::vector<int> dfs(std::vector<int> &s, const int bucket_size){
        if((int) s.size() == 1){
            return {0};
        }

        int n = s.size();
        s.push_back(0);

        // S 型かどうか
        std::vector<bool> is_s(n + 1);
        is_s[n] = 1;
        for(int i = n - 1; i >= 0; --i){
            if(s[i] < s[i + 1]){
                is_s[i] = 1;
            }else if(s[i] > s[i + 1]){
                is_s[i] = 0;
            }else{
                is_s[i] = is_s[i + 1];
            }
        }

        // LMS かどうか
        std::vector<bool> is_lms(n + 1);
        is_lms[n] = 1;
        for(int i = 1; i <= n; ++i){
            if(!is_s[i - 1] && is_s[i]){
                is_lms[i] = 1;
            }
        }

        std::vector<int> bucket_count(bucket_size, 0);
        for(auto i : s){
            bucket_count[i]++;
        }

        auto induced_sort = [&](std::vector<int> &lms) -> std::vector<int> {
            std::vector<std::vector<int>> bucket(bucket_size);
            std::vector<int> bucket_l(bucket_size, 0), bucket_r(bucket_size);
            for(int i = 0; i < bucket_size; i++){
                bucket[i].resize(bucket_count[i]);
                bucket_r[i] = bucket_count[i];
            }
            for(int i = (int) lms.size() - 1; i >= 0; --i){
                int c = s[lms[i]];
                bucket[c][--bucket_r[c]] = lms[i];
            }

            // LMS をもとに L 型をソート
            for(int i = 0; i < bucket_size; ++i){
                for(int k = 0; k < bucket_l[i]; ++k){
                    int j = bucket[i][k];
                    if(j != 0 && !is_s[j - 1]){
                        bucket[s[j - 1]][bucket_l[s[j - 1]]++] = j - 1;
                    }
                }
                for(int k = bucket_r[i]; k < bucket_count[i]; ++k){
                    int j = bucket[i][k];
                    if(j != 0 && !is_s[j - 1]){
                        bucket[s[j - 1]][bucket_l[s[j - 1]]++] = j - 1;
                    }
                }
            }

            // LMS を一旦削除
            for(int i = (int) lms.size() - 1; i >= 0; --i){
                int c = s[lms[i]];
                bucket_r[c] = bucket_count[c];
            }

            // L 型をもとに S 型をソート
            for(int i = bucket_size - 1; i >= 0; --i){
                for(int k = bucket_count[i] - 1; k >= bucket_r[i]; --k){
                    int j = bucket[i][k];
                    if(j != 0 && is_s[j - 1]){
                        bucket[s[j - 1]][--bucket_r[s[j - 1]]] = j - 1;
                    }
                }
                for(int k = bucket_l[i] - 1; k >= 0; --k){
                    int j = bucket[i][k];
                    if(j != 0 && is_s[j - 1]){
                        bucket[s[j - 1]][--bucket_r[s[j - 1]]] = j - 1;
                    }
                }
            }

            std::vector<int> res;
            for(int i = 1; i < bucket_size; ++i){
                for(auto j : bucket[i]){
                    res.push_back(j);
                }
            }
            return res;
        };

        std::vector<int> lms;
        for(int i = n; i >= 0; --i){
            if(is_lms[i]){
                lms.push_back(i);
            }
        }

        // LMS を後ろから入れる -> これで LMS 部分文字列の範囲はソートされる
        std::vector<int> res = induced_sort(lms);

        // LMS 部分文字列に ID を振る
        std::vector<int> id_lms(n + 1, -1);
        {
            id_lms[n] = 1;
            int prv = n;
            auto comp = [&](int l1, int l2){
                if(s[l1] != s[l2]){
                    return false;
                }
                for(int i = 1; (l1 + i < n + 1) && (l2 + i < n + 1); ++i){
                    if(s[l1 + i] != s[l2 + i]){
                        return false;
                    }
                    if(is_lms[l1 + i] && is_lms[l2 + i]) return true;
                    if(is_lms[l1 + i] || is_lms[l2 + i]) return false;
                }
                return false;
            };
            for(auto j : res){
                if(is_lms[j]){
                    if(comp(prv, j)){
                        id_lms[j] = id_lms[prv];
                    }else{
                        id_lms[j] = id_lms[prv] + 1;
                    }
                    prv = j;
                }
            }
        }

        std::vector<int> ns;
        int nbucket_size = 1;
        std::vector<int> idx;
        for(int i = 0; i < n + 1; ++i){
            if(is_lms[i]){
                ns.push_back(id_lms[i]);
                idx.push_back(i);
                nbucket_size = std::max(nbucket_size, id_lms[i] + 1);
            }
        }

        std::vector<int> sorted_lms;
        // LMS の suffix_array を求める -> LMS の suffix の辞書順が分かる
        for(auto i : dfs(ns, nbucket_size)){
            sorted_lms.push_back(idx[i]);
        }

        return induced_sort(sorted_lms);
    }

public:
    SA_IS(const T &s){
        std::vector<int> ns(s.size());
        int nbucket_size = 1;
        for(int i = 0; i < (int) s.size(); ++i){
            ns[i] = (int) (s[i] + 1);
            nbucket_size = std::max(nbucket_size, ns[i] + 1);
        }
        SA = dfs(ns, nbucket_size);
    }

    std::vector<int> get() const {
        return SA;
    }

    size_t size() const {
        return SA.size();
    }

    int operator[](int k) const {
        return SA[k];
    }
};
