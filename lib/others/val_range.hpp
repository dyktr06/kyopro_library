#pragma once

/**
 * @brief val_range
 * @docs docs/others/val_range.md
 */

 // 0-indexed, (l, i], [i, r)
template<typename T>
pair<vector<int>, vector<int>> val_range(const vector<T> &v, bool is_min){
    pair<vector<int>, vector<int>> res;
    int n = v.size();
    res.first.assign(n, -1);
    res.second.assign(n, n);
    stack<int> st;
    st.push(-1);
    for(int i = 0; i < n; ++i){
        while(st.top() != -1){
            if(is_min ^ (v[st.top()] < v[i])){
                res.second[st.top()] = i;
                st.pop();
            } else{
                break;
            }
        }
        res.first[i] = st.top();
        st.push(i);
    }
    return res;
}
