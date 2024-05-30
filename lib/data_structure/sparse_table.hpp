#pragma once

template <class T>
struct SparseTable{
    using FX = function<T(T, T)>;
    const FX op;
    vector<vector<T>> _table;
    vector<int> _log2;

    SparseTable(const vector<T> &v, const FX &fx_) : op(fx_){
        const int n = v.size();
        _log2.assign(n + 1, 0);
        for(int i = 2; i <= n; i++) _log2[i] = _log2[i >> 1] + 1;
        _table.assign(_log2[n] + 1, vector<T>(n));
        for(int i = 0; i < n; i++) _table[0][i] = v[i];
        for(int k = 1; k <= _log2[n]; k++){
            for(int i = 0; i + (1 << k) <= n; i++)
                _table[k][i] = op(_table[k - 1][i], _table[k - 1][i + (1 << (k - 1))]);
        }
    }

    inline T query(const int &l, const int &r) const {
        const int ex = _log2[r - l];
        return op(_table[ex][l], _table[ex][r - (1 << ex)]);
    }
};
