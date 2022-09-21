#include <bits/stdc++.h>

using namespace std;

// それぞれの i (1 <= i <= |S|) について、S[i] を中心とする最長回文の半径を求めます。 : O(|S|) 
vector<int> manacher(const string &s){
    int n = s.size();
    vector<int> rad(n);
    int i = 0, j = 0;
    while(i < n){
        while(i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]){
            j++;
        }
        rad[i] = j;
        int k = 1;
        while(i - k >= 0 && i + k < n && k + rad[i - k] < j){
            rad[i + k] = rad[i - k];
            k++;
        }
        i += k;
        j -= k;
    }
    return rad;
}

// example
int main(){
    string s; cin >> s;
    vector<int> m = manacher(s);
    for(auto x : m){
        cout << x << endl;
    }
}