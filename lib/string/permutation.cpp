#include <bits/stdc++.h>

using namespace std;

// 並び変えてできる文字列としてありえるものを辞書順ですべて列挙します : O(N*N!)
vector<string> getPermutation(string s){
    int n = s.size();
    vector<int> array(n);
    iota(array.begin(), array.end(), 0);
    vector<string> res;
    do{
        string t = "";
        for(int i = 0; i < n; i++){
            t.push_back(s[array[i]]);
        }
        res.push_back(t);
    }while(next_permutation(array.begin(), array.end()));
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

// example (ABC225A)
int main(){
    string s; cin >> s;
    vector<string> p = getPermutation(s);
    cout << (int) p.size() << "\n";
}