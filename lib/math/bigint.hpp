#pragma once

/**
 * @brief BigInt (多倍長整数)
 * @docs docs/math/bigint.md
 */

template <long long base = 1000000LL, int digit = 6>
struct BigInt{
    int sign = 1;
    vector<long long> val;

    constexpr BigInt(const long long _val = 0) noexcept {
        if(_val != 0){
            val.assign(1, abs(_val));
            shift();
        }
        if(_val < 0) sign = -1;
    }
    constexpr BigInt(const vector<long long> &_val) noexcept : val(_val) {}
    constexpr BigInt(const string &s) noexcept {
        stoi(s);
    }

private:
    void normalize(){
        while(!val.empty() && val.back() == 0) val.pop_back();
        if(val.empty()) sign = 1;
    }
    vector<long long> karatsuba_algorithm(vector<long long> &a, vector<long long> &b){
        const int n = (int) a.size();
        const int h = n >> 1;
        assert(a.size() == b.size());
        assert((n & (n - 1)) == 0);
        if(n <= 64){
            vector<long long> res(2 * n - 1);
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    res[i + j] += a[i] * b[j];
                }
            }
            return res;
        }
        vector<long long> p(h), q(h), r(h), s(h), t(h), u(h);
        for(int i = 0; i < h; ++i){
            p[i] = a[i + h];
            q[i] = a[i];
            r[i] = b[i + h];
            s[i] = b[i];
            t[i] = p[i] + q[i];
            u[i] = r[i] + s[i];
        }
        p = karatsuba_algorithm(p, r);
        q = karatsuba_algorithm(q, s);
        t = karatsuba_algorithm(t, u);
        vector<long long> res(2 * n - 1, 0);
        for(int i = 0; i < n - 1; ++i){
            res[i] += q[i];
            res[i + h] += t[i] - p[i] - q[i];
            res[i + n] += p[i];
        }
        return res;
    }

    pair<BigInt, BigInt> divide_naive(const BigInt& rhs) const {
        assert(!rhs.val.empty());
        const int k = base / (rhs.val.back() + 1);
        const BigInt dividend = (sign == 1 ? *this : -(*this)) * k;
        const BigInt divisor = (rhs.sign == 1 ? rhs : -rhs) * k;
        BigInt quo, rem = 0;
        quo.val.resize(dividend.val.size());
        const int n = divisor.val.size();
        for(int i = (int) dividend.val.size() - 1; i >= 0; --i){
            rem.val.emplace(rem.val.begin(), dividend.val[i]);
            quo.val[i] = ((n < (int) rem.val.size() ? rem.val[n] * base : 0) + ((n - 1) < (int) rem.val.size() ? rem.val[n - 1] : 0)) / divisor.val.back();
            rem -= divisor * quo.val[i];
            while (rem.sign == -1) {
                rem += divisor;
                --quo.val[i];
            }
        }
        quo.sign = sign * rhs.sign;
        quo.normalize();
        rem.sign = sign;
        rem.normalize();
        return {quo, rem / k};
    }

    pair<BigInt, BigInt> divide_newton(const BigInt& rhs) const {
        assert(!rhs.val.empty());
        int preci = val.size() - rhs.val.size();
        BigInt t(1);
        BigInt two = BigInt(2) << rhs.val.size();
        BigInt pre;
        int lim = min(preci, 3);
        int rhslim = min(int(rhs.val.size()), 6);
        t <<= lim;
        while(pre != t){
            BigInt rb = rhs >> (rhs.val.size() - rhslim);
            if(rhslim != (int) rhs.val.size()) rb += BigInt(1);
            pre = t;
            t *= (BigInt(2) << (rhslim + lim)) - rb * t;
            t.val = vector<long long>(t.val.begin() + lim + rhslim, t.val.end());
        }
        if(lim != preci){
            pre = BigInt();
            while(pre != t){
                BigInt rb = rhs >> (rhs.val.size() - rhslim);
                if(rhslim != (int) rhs.val.size()) rb += BigInt(1);
                pre = t;
                t *= (BigInt(2) << (rhslim + lim)) - rb * t;
                t.val = vector<long long>(t.val.begin() + lim + rhslim, t.val.end());
                int next_lim = min(lim * 2 + 1, preci);
                if (next_lim != lim) t <<= next_lim - lim;
                int next_rhslim = min(rhslim * 2 + 1, int(rhs.val.size()));
                lim = next_lim;
                rhslim = next_rhslim;
            }
        }
        BigInt quo = (*this) * t;
        quo.val = vector<long long>(quo.val.begin() + val.size(), quo.val.end());
        BigInt mul = quo * rhs;
        while(mul + rhs <= (*this)){
            quo += BigInt(1);
            mul += rhs;
        }
        BigInt rem = *this - quo * rhs;
        return {quo, rem};
    }

public:
    void stoi(string &s){
        if(s == "0") return;
        int n = s.size(), idx = 0;
        if(s[0] == '-'){
            n -= 1;
            sign = -1;
            idx = 1;
        }
        int len = (n + digit - 1) / digit, rem = n % digit;
        if(rem == 0) rem += digit;
        val.resize(len);
        for(int i = len - 1; i >= 0; --i){
            if(i == len - 1){
                val[i] = stoll(s.substr(idx, rem));
                idx += rem;
            }else{
                val[i] = stoll(s.substr(idx, digit));
                idx += digit;
            }
        }
    }
    string itos() const {
        string res = "";
        if(sign == -1) res += "-";
        bool flag = false;
        for(int i = (int) val.size() - 1; i >= 0; --i){
            if(val[i] > 0 && !flag){
                res += to_string(val[i]);
                flag = true;
            }else if(flag){
                string rem = to_string(val[i]);
                res += string(digit - rem.size(), '0') + rem;
            }
        }
        return (res.empty() || res == "-") ? "0" : res;
    }
    pair<BigInt, BigInt> divide_mod(const BigInt& rhs){
        assert(!rhs.val.empty());
        BigInt div = *this / rhs;
        return make_pair(div, *this - div * rhs);
    }
    BigInt& shift(){
        for(int i = 0; i < (int) val.size() - 1; ++i){
            if(val[i] >= 0){
                val[i + 1] += val[i] / base;
                val[i] %= base;
            }else{
                long long x = (-val[i] + base - 1) / base;
                val[i] += x * base;
                val[i + 1] -= x;
            }
        }
        while(val.back() >= base){
            val.emplace_back(val.back() / base);
            val[val.size() - 2] %= base;
        }
        return *this;
    }
    BigInt& operator=(const BigInt& x) = default;
    inline BigInt& operator+=(const BigInt& rhs) noexcept {
        if(rhs.val.empty()) return *this;
        if(sign != rhs.sign) return *this -= -rhs;
        if(val.size() < rhs.val.size()){
            val.resize(rhs.val.size());
        }
        for(int i = 0; i < (int) rhs.val.size(); ++i){
            val[i] += rhs.val[i];
        }
        return (*this).shift();
    }
    inline BigInt& operator-=(const BigInt& rhs) noexcept {
        if(rhs.val.empty()) return *this;
        if(sign != rhs.sign) return *this += -rhs;
        if((sign == 1 ? *this : -(*this)) < (rhs.sign == 1 ? rhs : -rhs)){
            return *this = -(rhs - *this);
        }
        for(int i = 0; i < (int) rhs.val.size(); ++i){
            val[i] -= rhs.val[i];
        }
        
        shift();
        normalize();
        return *this;
    }
    // Karatsuba Algorithm (O(N^(1.58)))
    inline BigInt& operator*=(const BigInt& rhs) noexcept {
        if(val.empty() || rhs.val.empty()){
            return *this = BigInt();
        }

        sign *= rhs.sign;
        vector<long long> rhsval = rhs.val;
        int k = 1;
        while(k < (int) max(val.size(), rhsval.size())){
            k *= 2;
        }
        val.resize(k), rhsval.resize(k);
        val = karatsuba_algorithm(val, rhsval);

        shift();
        normalize();
        return *this;
    }
    // Newton method
    inline BigInt& operator/=(const BigInt& rhst) noexcept {
        assert(!rhst.val.empty());
        if(val.empty()) return *this;
        if((int) val.size() <= 32 && (int) rhst.val.size() <= 32){
            return *this = divide_naive(rhst).first;
        }

        BigInt rhs = rhst;
        int mulsign = sign * rhs.sign;
        sign = 1, rhs.sign = 1;
        if(*this < rhs){
            return *this = BigInt();
        }

        *this = divide_newton(rhs).first;
        sign = mulsign;
        normalize();
        return *this;
    }
    inline BigInt& operator%=(const BigInt& rhs) noexcept {
        assert(!rhs.val.empty());
        return *this = *this - (*this / rhs) * rhs;
    }
    inline BigInt& operator++() { return *this += 1; }
    inline BigInt operator++(int) {
        const BigInt res = *this;
        ++(*this);
        return res;
    }
    inline BigInt& operator--() { return *this -= 1; }
    inline BigInt operator--(int) {
        const BigInt res = *this;
        --(*this);
        return res;
    }
    inline BigInt operator+() const { return *this; }
    inline BigInt operator-() const {
        BigInt res = *this;
        if (!res.val.empty()) res.sign = -res.sign;
        return res;
    }
    inline BigInt& operator<<=(const unsigned int rhs){
        if(val.back() >= 1 || (int) val.size() >= 2){
            vector<long long> tmp(rhs, 0);
            val.insert(val.begin(), tmp.begin(), tmp.end());
        }
        return *this;
    }
    inline BigInt& operator>>=(const unsigned int rhs){
        if(rhs == 0) return *this;
        if(rhs > val.size()) val = {0};
        else val = vector<long long>(val.begin() + rhs, val.end()); 
        return *this;
    }
    inline bool operator<(const BigInt& rhs) const {
        if(sign != rhs.sign) return sign < rhs.sign;
        if(val.size() != rhs.val.size()) return sign * val.size() < rhs.sign * rhs.val.size();
        for(int i = (int) val.size() - 1; i >= 0; --i){
            if(val[i] != rhs.val[i]) return sign * val[i] < rhs.sign * rhs.val[i];
        }
        return false;
    }
    inline bool operator>(const BigInt& rhs) const { return rhs < (*this); }
    inline bool operator<=(const BigInt& rhs) const { return !((*this) > rhs); }
    inline bool operator>=(const BigInt& rhs) const { return !((*this) < rhs); }
    friend inline BigInt operator+(const BigInt& lhs, const BigInt& rhs) noexcept { return BigInt(lhs) += rhs; }
    friend inline BigInt operator-(const BigInt& lhs, const BigInt& rhs) noexcept { return BigInt(lhs) -= rhs; }
    friend inline BigInt operator*(const BigInt& lhs, const BigInt& rhs) noexcept { return BigInt(lhs) *= rhs; }
    friend inline BigInt operator/(const BigInt& lhs, const BigInt& rhs) noexcept { return BigInt(lhs) /= rhs; }
    friend inline BigInt operator%(const BigInt& lhs, const BigInt& rhs) noexcept { return BigInt(lhs) %= rhs; }
    friend inline BigInt operator<<(const BigInt& lhs, const unsigned int rhs) noexcept { return BigInt(lhs) <<= rhs; }
    friend inline BigInt operator>>(const BigInt& lhs, const unsigned int rhs) noexcept { return BigInt(lhs) >>= rhs; }
    friend inline bool operator==(const BigInt& lhs, const BigInt& rhs) noexcept { return lhs.val == rhs.val; }
    friend inline bool operator!=(const BigInt& lhs, const BigInt& rhs) noexcept { return lhs.val != rhs.val; }
    friend inline istream& operator>>(istream& is, BigInt& x) noexcept {
        string s;
        is >> s;
        x.stoi(s);
        return is;
    }
    friend inline ostream& operator<<(ostream& os, const BigInt& x) noexcept { return os << x.itos(); }
};