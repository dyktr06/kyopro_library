#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

// 乱数生成
struct RandomNumber{
    int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    uniform_int_distribution<long long> p;
    mt19937_64 rnd;

	RandomNumber(long long l = 0, long long r = 0){
        rnd = mt19937_64(seed);
        p = uniform_int_distribution<long long>(l, r);
        Sleep(1);
    }

	long long get(){
        return p(rnd);
    }
};

// example (1から100の乱数を生成)
int main(){
    RandomNumber r(1, 100);
    cout << r.get() << endl;
}