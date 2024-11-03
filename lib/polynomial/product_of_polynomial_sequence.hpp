#pragma once

#include "../polynomial/formal_power_series.hpp"
#include <vector>

template <typename T>
FormalPowerSeries<T> product(const std::vector<FormalPowerSeries<T>> &f){
    auto dfs = [&](auto &self, int l, int r) -> FormalPowerSeries<T> {
        if(r - l == 1) return f[l];
        if(r - l == 0) return {T(1)};
        int mid = (l + r) / 2;
        return self(self, l, mid) * self(self, mid, r);
    };
    return dfs(dfs, 0, (int) f.size());
}
