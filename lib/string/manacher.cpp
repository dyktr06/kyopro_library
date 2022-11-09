#include <bits/stdc++.h>

using namespace std;

// それぞれの i (1 <= i <= |S|) について、S[i] を中心とする最長回文の半径を求めます。 : O(|S|) 
template <typename T>
vector<int> manacher(const T &s){
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

// example (Library Checker: Enumerate Palindromes)
int main(){
    string s; cin >> s;
    int n = s.size();
    string t = "";
    for(int i = 0; i < n; i++){
        t += s[i];
        if(i < n - 1) t += '$';
    }
    vector<int> m1 = manacher(s), m2 = manacher(t);
    for(int i = 0; i < 2 * n - 1; i++){
        int ans;
        if(i % 2 == 0){
            ans = 2 * m1[i / 2] - 1;
        }else{
            ans = m2[i] / 2 * 2;
        }
        if(i >= 1) cout << " ";
        cout << ans;
    }
    cout << "\n";
}