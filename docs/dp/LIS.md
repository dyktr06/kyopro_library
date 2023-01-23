## Longest Increasing Subsequence

#### 概要

配列の最長増加部分列の長さを求めます。

$dp[i]$: 長さが i の増加部分列として最後尾の要素のとりうる最小値
とすると計算できる。

#### 使い方

- `LIS(a, is_strong)`: 配列 a の最長増加部分列の長さを求めます。(is_strong = false のとき、広義最長増加部分列)
- `construct_LIS(a, is_strong)`: 配列 a の最長増加部分列を構築します。

#### 計算量

配列の要素数を $N$ とする。
- `LIS(a, is_strong)`: $\mathrm{O}(N \log N)$
- `construct_LIS(a, is_strong)`: $\mathrm{O}(N \log N)$