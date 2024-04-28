#pragma once

template <typename T, int BLOCK = 500>
struct MergeableSet{
    int N;
    int nxt = 0;
    vector<bool> isBlock, seen;
    vector<int> idx;
    vector<vector<T>> s;
    vector<vector<unsigned long long>> bit;

    MergeableSet(const int N) : N(N), isBlock(N), seen(N), idx(N), s(N){
    }

    void toBlock(int id){
        isBlock[id] = true;
        idx[id] = nxt++;
        vector<unsigned long long> emp((N + 63) / 64);
        bit.emplace_back(emp);
        for(auto x : s[id]){
            bit[idx[id]][x / 64] |= 1ULL << (x % 64);
        }
    };

    void insert(int id, T x){
        if(isBlock[id]){
            bit[idx[id]][x / 64] |= 1ULL << (x % 64);
        } else{
            s[id].emplace_back(x);
            if((int) s[id].size() + 1 >= BLOCK){
                toBlock(id);
            }
        }
    }

    void erase(int id, T x){
        if(isBlock[id]){
            bit[idx[id]][x / 64] &= ~(1ULL << (x % 64));
        } else{
            vector<T> tmp;
            for(auto &y : s[id]){
                if(x != y){
                    tmp.emplace_back(y);
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
    
    T intersect(int id1, int id2){
        if(isBlock[id2]) swap(id1, id2);
        T ans = -1;
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
};
