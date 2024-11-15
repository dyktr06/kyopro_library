#pragma once

/**
 * @brief Sparse Table
 */

#include <vector>
#include <cassert>

template <class T, T (*op)(T, T)>
struct SparseTable{
    std::vector<std::vector<T>> _table;
    std::vector<int> _log2;

    SparseTable(const std::vector<T> &v){
        const int n = v.size();
        _log2.assign(n + 1, 0);
        for(int i = 2; i <= n; i++) _log2[i] = _log2[i >> 1] + 1;
        _table.assign(_log2[n] + 1, std::vector<T>(n));
        for(int i = 0; i < n; i++) _table[0][i] = v[i];
        for(int k = 1; k <= _log2[n]; k++){
            for(int i = 0; i + (1 << k) <= n; i++)
                _table[k][i] = op(_table[k - 1][i], _table[k - 1][i + (1 << (k - 1))]);
        }
    }

    inline T query(const int &l, const int &r) const {
        assert(l < r);
        const int ex = _log2[r - l];
        return op(_table[ex][l], _table[ex][r - (1 << ex)]);
    }
};
