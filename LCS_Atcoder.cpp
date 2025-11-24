#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
string a, b;
int dp[N][N];

int LCS(int i, int j){
    if(i == a.size() || j == b.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(a[i] == b[j]) dp[i][j] = 1 + LCS(i+1, j+1);
    else dp[i][j] = max(LCS(i, j+1), LCS(i+1, j));
    return dp[i][j];
}

void lcs_string(int i, int j){
    if(i == a.size() || j == b.size()) return;
    if(a[i] == b[j]){
        cout << a[i];
        lcs_string(i+1, j+1);
    }
    else{
        int x = LCS(i+1, j), y = LCS(i, j+1);
        (x > y) ? lcs_string(i+1, j) : lcs_string(i, j+1);
    }
    return;
}

int main()
{
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    lcs_string(0, 0);
    cout << '\n';
    return 0;
}

// https://atcoder.jp/contests/dp/tasks/dp_f
