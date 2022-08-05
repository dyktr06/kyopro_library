#include <bits/stdc++.h>

using namespace std;

// 並び変えてできる文字列としてありえるものを辞書順ですべて列挙します : O(N*N!)
vector<string> getPermutation(string s){
    int n = s.size();
    vector<int> array;
    for(int i = 0; i < n; i++) array.push_back(i);
    sort(s.begin(), s.end());
    unordered_map<string, int> check;
    vector<string> res;
    do{
        string a = "";
        for(int i = 0; i < n; i++){
            a.push_back(s[array[i]]);
        }
        if(check[a] == 0){
            res.push_back(a);
            check[a] = 1;
        }
    }while(next_permutation(array.begin(), array.end()));
    return res;
}
