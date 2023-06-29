#pragma once

template <long long base = 1000000000LL, int digit = 9>
struct BigInt{
    int sign = 1;
    vector<long long> val;

    constexpr BigInt(const long long &_val = 0) noexcept {
        val.assign(1, _val);
    }
    constexpr BigInt(const vector<long long> &_val) noexcept : val(_val) {}
    constexpr BigInt(const string &s) noexcept {
        stoi(s);
    }
    void stoi(string &s){
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
        if(sign != rhs.sign) return rhs.val.empty() ? *this : *this -= -rhs;
        if(val.size() < rhs.val.size()){
            val.resize(rhs.val.size());
        }
        for(int i = 0; i < (int) rhs.val.size(); ++i){
            val[i] += rhs.val[i];
        }
        return (*this).shift();
    }
    inline BigInt& operator-=(const BigInt& rhs) noexcept {
        if(sign != rhs.sign) return *this += -rhs;
        if((sign == 1 ? *this : -*this) < (rhs.sign == 1 ? rhs : -rhs)){
            return *this = -(rhs - *this);
        }
        for(int i = 0; i < (int) rhs.val.size(); ++i){
            val[i] -= rhs.val[i];
        }
        
        shift();
        while(!val.empty() && val.back() == 0) val.pop_back();
        if(val.empty()) sign = 1;
        return *this;
    }
    inline BigInt& operator++() { return *this += 1; }
    inline BigInt operator++(int) {
        const BigInt res = *this;
        ++*this;
        return res;
    }
    inline BigInt& operator--() { return *this -= 1; }
    inline BigInt operator--(int) {
        const BigInt res = *this;
        --*this;
        return res;
    }
    inline BigInt operator+() const { return *this; }
    inline BigInt operator-() const {
        BigInt res = *this;
        if (!res.val.empty()) res.sign = -res.sign;
        return res;
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