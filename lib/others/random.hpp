#pragma once

#include <bits/stdc++.h>

using namespace std;

struct RandomNumber{
    int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    uniform_int_distribution<long long> p;
    mt19937_64 rnd;

	RandomNumber(long long l = 0, long long r = 0){
        rnd = mt19937_64(seed);
        p = uniform_int_distribution<long long>(l, r);
    }

	long long get(){
        return p(rnd);
    }
};
