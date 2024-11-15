## Binary Indexed Tree 2D

#### 使い方

- `BinaryIndexedTree2D<T>(H, W)`: コンストラクタ
- `add(x, y, v)`: (x, y) に v を加算します。
- `imos(x1, y1, x2, y2, v)`: いもす法において、[(x1, y1), (x2, y2)] に v を加算します。
- `sum(x1, y1, x2, y2)`: [(x1, y1), (x2, y2)] の和を取得します。

閉区間なことに注意してください。

#### 計算量

- `BinaryIndexedTree2D<T>(H, W)`: $\mathrm{O}(HW)$
- `add(x, y, v)`: $\mathrm{O}(\log H \log W)$
- `imos(x1, y1, x2, y2, v)`: $\mathrm{O}(\log H \log W)$
- `sum(x1, y1, x2, y2)`: $\mathrm{O}(\log H \log W)$
