#pragma once

/**
 * @brief Run Enumerate
 * @docs docs/string/run_enumerate.md
 * @see https://pazzle1230.hatenablog.com/entry/2019/11/27/234632
 */

#include "z_algorithm.hpp"

vector<tuple<int, int, int>> run_enumerate(const string &s){
    int n = s.size();
    vector<tuple<int, int, int>> res;
    auto dfs = [&](auto &self, int l, int r) -> void {
        if(r - l < 2){
            return;
        }
        int mid = (l + r) / 2;
        self(self, l, mid);
        self(self, mid, r);

        string ns = s.substr(l, r - l);
        int lenl = mid - l, lenr = r - mid;
        string sl = s.substr(l, lenl);
        reverse(sl.begin(), sl.end());
        string sr = s.substr(mid, lenr);
        sr += ns;
        reverse(ns.begin(), ns.end());
        sl += ns;
        auto zl = z_algorithm(sl);
        auto zr = z_algorithm(sr);
        {
            for(int i = l; i < mid; i++){
                // [i, mid) を周期
                int len = mid - i;
                int nl = i, nr = mid;
                if(i > l) nl = max(l, nl - zl[len]);
                nr = min(r, nr + zr[lenr + (i - l)]);
                if(nr - nl >= len * 2){
                    if(nl >= 1 && s[nl - 1] == s[nl - 1 + len]){
                        continue;
                    }
                    if(nr < n && s[nr] == s[nr - len]){
                        continue;
                    }
                    res.emplace_back(nl, nr, len);
                }
            }
        }
        {
            for(int i = mid + 1; i <= r; i++){
                // [mid, i) を周期
                int len = i - mid;
                int nl = mid, nr = i;
                if(i < r) nr = min(r, nr + zr[len]);
                nl = max(l, nl - zl[lenl + (r - i)]);
                if(nr - nl >= len * 2){
                    if(nl >= 1 && s[nl - 1] == s[nl - 1 + len]){
                        continue;
                    }
                    if(nr < n && s[nr] == s[nr - len]){
                        continue;
                    }
                    res.emplace_back(nl, nr, len);
                }
            }
        }
    };
    dfs(dfs, 0, n);
    sort(res.begin(), res.end());
    vector<tuple<int, int, int>> ans;
    int pl = -1, pr = -1;
    for(auto [l, r, len] : res){
        if(l == pl && r == pr){
            continue;
        }
        pl = l, pr = r;
        ans.emplace_back(len, l, r);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
