#include <bits/stdc++.h>

using namespace std;

// それぞれの i (1 <= i <= |S|) について、S[1] + S[2] + ... と S[i] + S[i + 1] + ... の最長共通接頭辞の長さ を求めます。 : O(|S|) 
template <typename T>
vector<int> z_algorithm(T &s) {
    int n = s.size();
    vector<int> res(n, 0);
    for(int i = 1, j = 0; i < n; ++i){
        if(i + res[i - j] < j + res[j]){
            res[i] = res[i - j];
        }else{
            res[i] = max(j + res[j] - i, 0);
            while(i + res[i] < n && s[i + res[i]] == s[res[i]]) ++res[i];
            j = i;
        }
    }
    res[0] = n;
    return res;
}

string s;

// example
int main(){
    cin >> s;
    vector<int> z = z_algorithm(s);
    int n = s.size();
    for(int i = 0; i < n; i++){
        cout << z[i] << endl;
    }
}
