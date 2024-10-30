#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include <iostream>
#include <string>

#include "../../../lib/string/sa_is.hpp"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    SA_IS<string> sa(s);
    for(int i = 0; i < (int) sa.size(); ++i){
        cout << sa[i] << " \n"[i == (int) sa.size() - 1];
    }
}
