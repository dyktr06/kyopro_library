## Mod Calculation

### 概要

Mod に関する計算のアルゴリズムの詰め合わせです。

#### 使い方

- `modcalc::modpow(x, n, m)`: $x^n$ (mod. m) を計算します。
- `modcalc::modinv(a, m)`: $a$ の逆元 (mod. m) を計算します。
- `modcalc::modarithmeticsum(a, m)`: 初項 $a$, 公差 $d$, 項数 $n$ の等差数列の和 (mod. m) を計算します。
- `modcalc::modgeometricsum(a, m)`: 初項 $a$, 公比 $r$, 項数 $n$ の等比数列の和 (mod. m) を計算します。

#### 計算量

- `modcalc::modpow(x, n, m)`: $\mathrm{O}(\log n)$
- `modcalc::modinv(a, m)`: $\mathrm{O}(\log m)$
- `modcalc::modarithmeticsum(a, m)`: $\mathrm{O}(\log m)$
- `modcalc::modgeometricsum(a, m)`: $\mathrm{O}(\log nm)$