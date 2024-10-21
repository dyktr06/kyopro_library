#define PROBLEM "https://judge.yosupo.jp/problem/assignment"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/assignment_problem.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<long long>> a(n, vector<long long>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    vector<int> ans = assignmentProblem(a);
    long long ret = 0;
    for(int i = 0; i < n; i++){
        ret += a[i][ans[i]];
    }
    cout << ret << '\n';
    for(int i = 0; i < n; i++){
        if(i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
}
