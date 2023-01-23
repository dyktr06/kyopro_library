## Count Substrings

#### 概要

配列における、連続するとは限らない部分列の種類数を数え上げます。

#### 使い方

- `substrings(s, m)`: 文字列 $s$ における、連続しない部分文字列の種類数を $m$ で割った余りを返します。(空文字列を含む)
- `subsequences(s, m)`: 列 $s$ における、連続するとは限らない部分列の種類数を $m$ で割った余りを返します。

#### 計算量

配列の要素数を $N$ とする。
- `substrings(s, m)`: $\mathrm{O}(N)$
- `subsequences(s, m)`: $\mathrm{O}(N \log N)$