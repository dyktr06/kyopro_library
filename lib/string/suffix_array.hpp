#pragma once

template <typename T>
struct SuffixArray{
    vector<int> SA;
    const T s;

    SuffixArray(const T &str) : s(str){
        SA.resize(s.size());
        iota(SA.begin(), SA.end(), 0);
        sort(SA.begin(), SA.end(), [&](int a, int b){
            return s[a] == s[b] ? a > b : s[a] < s[b];
        });
        vector<int> classes(s.size()), c(s.begin(), s.end()), cnt(s.size());
        for(int len = 1; len < (int) s.size(); len <<= 1){
            for(int i = 0; i < (int) s.size(); i++){
                if(i > 0 && c[SA[i - 1]] == c[SA[i]] && SA[i - 1] + len < (int) s.size() && c[SA[i - 1] + len / 2] == c[SA[i] + len / 2]){
                    classes[SA[i]] = classes[SA[i - 1]];
                } else{
                    classes[SA[i]] = i;
                }
            }
            iota(cnt.begin(), cnt.end(), 0);
            copy(SA.begin(), SA.end(), c.begin());
            for(int i = 0; i < (int) s.size(); i++){
                int s1 = c[i] - len;
                if(s1 >= 0) SA[cnt[classes[s1]]++] = s1;
            }
            classes.swap(c);
        }
    }

    int operator[](int k) const{
        return SA[k];
    }

    size_t size() const{
        return s.size();
    }

    bool lt_substr(const T &t, int si = 0, int ti = 0){
        int sn = (int) s.size(), tn = (int) t.size();
        while(si < sn && ti < tn){
            if(s[si] < t[ti]) return true;
            if(s[si] > t[ti]) return false;
            ++si, ++ti;
        }
        return si >= sn && ti < tn;
    }

    int lower_bound(const T &t){
        int low = -1, high = (int) SA.size();
        while(high - low > 1){
            int mid = (low + high) / 2;
            if(lt_substr(t, SA[mid])) low = mid;
            else high = mid;
        }
        return high;
    }

    pair<int, int> lower_upper_bound(T &t){
        int idx = lower_bound(t);
        int low = idx - 1, high = (int) SA.size();
        t.back()++;
        while(high - low > 1){
            int mid = (low + high) / 2;
            if(lt_substr(t, SA[mid])) low = mid;
            else high = mid;
        }
        t.back()--;
        return {idx, high};
    }
};

template <typename T>
struct LCPArray{
    const SuffixArray<T> &SA;
    vector<int> LCP, rank;

    LCPArray(const SuffixArray<T> &SA) : SA(SA), LCP(SA.size()){
        rank.resize(SA.size());
        for(int i = 0; i < (int) SA.size(); i++){
            rank[SA[i]] = i;
        }
        for(int i = 0, h = 0; i < (int) SA.size(); i++){
            if(rank[i] + 1 < (int) SA.size()){
                for(int j = SA[rank[i] + 1]; max(i, j) + h < (int) SA.size() && SA.s[i + h] == SA.s[j + h]; ++h);
                LCP[rank[i] + 1] = h;
                if(h > 0) --h;
            }
        }
    }

    int operator[](int k) const {
        return LCP[k];
    }

    size_t size() const {
        return LCP.size();
    }
};
