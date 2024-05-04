#pragma once

template <int BLOCK = 250>
struct MergeableSet{
    int N, M;
    int nxt = 0;
    vector<bool> isBlock, seen;
    vector<int> idx;
    vector<vector<int>> s;
    vector<vector<unsigned long long>> bit;

    // N: number of sets, M: upper limit of sets
    MergeableSet(const int N, const int M) : N(N), M(M + 1), isBlock(N), seen(M + 1), idx(N), s(N){
    }

    void toBlock(int id){
        isBlock[id] = true;
        idx[id] = nxt++;
        vector<unsigned long long> emp((M + 63) / 64);
        bit.emplace_back(emp);
        for(auto x : s[id]){
            bit[idx[id]][x / 64] |= 1ULL << (x % 64);
        }
    };

    void insert(int id, int x){
        assert(0 <= x && x < M);
        if(isBlock[id]){
            bit[idx[id]][x / 64] |= 1ULL << (x % 64);
        } else{
            bool isContained = false;
            for(auto y : s[id]){
                if(x == y){
                    isContained = true;
                }
            }
            if(isContained){
                return;
            }
            s[id].emplace_back(x);
            if((int) s[id].size() + 1 >= BLOCK){
                toBlock(id);
            }
        }
    }

    void erase(int id, int x){
        assert(0 <= x && x < M);
        if(isBlock[id]){
            bit[idx[id]][x / 64] &= ~(1ULL << (x % 64));
        } else{
            vector<int> tmp;
            for(auto y : s[id]){
                if(x != y){
                    tmp.emplace_back(y);
                }
            }
            s[id] = tmp;
        }
    }

    void shift(int id, int x){
        if(isBlock[id]){
            int siz = bit[idx[id]].size();
            vector<unsigned long long> emp(siz);
            for(int i = (int) siz - 1; i >= 0; i--){
                int j = i + (x / 64);
                unsigned long long tmp1 = bit[idx[id]][i], tmp2 = bit[idx[id]][i];
                tmp1 <<= (x % 64);
                tmp2 >>= 64 - (x % 64);
                if(0 <= j && j < siz){
                    emp[j] |= tmp1;
                }
                if(0 <= j + 1 && j + 1 < siz){
                    emp[j + 1] |= tmp2;
                }
            }
            bit[idx[id]] = emp;
        } else{
            vector<int> tmp;
            for(auto y : s[id]){
                if(0 <= y + x && y + x < M){
                    tmp.emplace_back(y + x);
                }
            }
            s[id] = tmp;
        }
    }

    bool equal(int id1, int id2){
        if(isBlock[id2]) swap(id1, id2);
        if(isBlock[id1] && isBlock[id2]){
            return (bit[idx[id1]] == bit[idx[id2]]);
        } else if(isBlock[id1] && !isBlock[id2]){
            int idx1 = idx[id1];
            vector<unsigned long long> tmp = bit[idx1];
            for(auto x : s[id2]){
                if(!(bit[idx1][x / 64] & (1ULL << (x % 64)))){
                    return false;
                }
                tmp[x / 64] &= ~(1ULL << (x % 64));
            }
            for(int i = 0; i < (int) bit[idx1].size(); i++){
                if(tmp[i] != 0ULL){
                    return false;
                }
            }
            return true;
        }
        return (s[id1] == s[id2]);
    }

    // return one of elements
    int intersect(int id1, int id2){
        if(isBlock[id2]) swap(id1, id2);
        int ans = -1;
        if(isBlock[id1] && isBlock[id2]){
            int idx1 = idx[id1], idx2 = idx[id2];
            for(int i = 0; i < (int) bit[idx1].size(); i++){
                if(ans != -1) break;
                if(!(bit[idx1][i] & bit[idx2][i])){
                    continue;
                }
                for(int k = 0; k < 64; k++){
                    unsigned long long flag1 = bit[idx1][i] & (1ULL << (k % 64)), flag2 = bit[idx2][i] & (1ULL << (k % 64));
                    if(flag1 && flag2){
                        ans = i * 64 + k;
                        break;
                    }
                }
            }
        } else if(isBlock[id1] && !isBlock[id2]){
            int idx1 = idx[id1];
            for(auto x : s[id2]){
                if(bit[idx1][x / 64] & (1ULL << (x % 64))){
                    ans = x;
                    break;
                }
            }
        } else{
            for(auto x : s[id1]){
                seen[x] = true;
            }
            for(auto x : s[id2]){
                if(seen[x]){
                    ans = x;
                    break;
                }
            }
            for(auto x : s[id1]){
                seen[x] = false;
            }
        }
        return ans;
    }

    // size of intersect set
    int intersectCount(int id1, int id2){
        if(isBlock[id2]) swap(id1, id2);
        int ans = 0;
        if(isBlock[id1] && isBlock[id2]){
            int idx1 = idx[id1], idx2 = idx[id2];
            for(int i = 0; i < (int) bit[idx1].size(); i++){
                ans += __builtin_popcountll(bit[idx1][i] & bit[idx2][i]);
            }
        } else if(isBlock[id1] && !isBlock[id2]){
            int idx1 = idx[id1];
            for(auto x : s[id2]){
                if(bit[idx1][x / 64] & (1ULL << (x % 64))){
                    ans++;
                }
            }
        } else{
            for(auto x : s[id1]){
                seen[x] = true;
            }
            for(auto x : s[id2]){
                if(seen[x]){
                    ans++;
                }
            }
            for(auto x : s[id1]){
                seen[x] = false;
            }
        }
        return ans;
    }
};
