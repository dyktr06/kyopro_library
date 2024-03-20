#pragma once

/**
 * @brief Maximum Rectangle (最大長方形)
 * @docs docs/others/maximum_rectangle.md
 */

// [(x1, y1), (x2, y2)] 
vector<tuple<int, int, int, int>> getMaximumRectangle(vector<vector<bool>> &a){
    vector<tuple<int, int, int, int>> res;
    int n = a.size(), m = a[0].size();
    vector<int> max_row(m), sorted(m);
    iota(sorted.begin(), sorted.end(), 0);
    for(int i = 0; i < n; ++i){
        vector<bool> is_changed(m);
        vector<int> nsorted;
        for(int j = 0; j < m; ++j){
            if(!a[i][j]){
                max_row[j] = i + 1;
                is_changed[j] = true;
                nsorted.emplace_back(j);
            }
        }
        // {l, r}
        vector<pair<int, int>> lr(m);
        for(int j = 0; j < m; ++j){
            if(!is_changed[sorted[j]]){
                nsorted.emplace_back(sorted[j]);
            }
            lr[j] = make_pair(j, j);
        }
        for(int j = m - 1; j >= 0; --j){
            int k = nsorted[j];
            auto [l, r] = lr[k];
            int nl = n + 1, nr = n + 1;
            if(l != 0) nl = max_row[l - 1];
            if(r != m - 1) nr = max_row[r + 1];
            if(nl <= max_row[k]) l = get<0>(lr[l - 1]);
            if(nr <= max_row[k]) r = get<1>(lr[r + 1]);
            if(max_row[k] <= i && l <= r) res.emplace_back(max_row[k], l, i, r);
            lr[l] = {l, r}, lr[r] = {l, r};
        }
        swap(sorted, nsorted);
    }
    return res;
}
