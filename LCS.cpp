#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll MOD = 1e9+7;

#define NEED_FOR_SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

string a, b;
int dp[1000][1000];

int lcs(int i, int j){
    if(i == a.size() || j == b.size()) return 0;
    if(dp[i][j] != 0) return dp[i][j];
    if(a[i] == b[j]) dp[i][j] =  1 + lcs(i+1, j+1); 
    else dp[i][j] = max(lcs(i+1, j), lcs(i, j+1));
    return dp[i][j];
}

void ans(int i, int j){
    if(i == a.size() || j == b.size()) return;
    if(a[i] == b[j]){
        cout << a[i];
    }
    int x = lcs(i+1, j), y = lcs(i, j+1);
    if(x > y) ans(i+1, j);
    else ans(i, j+1);
}

int32_t main()
{
    int t; cin >> t;
    int cnt = 0;

    while(t--){
        memset(dp, 0, sizeof dp);
        cin >> a >> b;
        cout << "Case "<< ++cnt << ": "<< lcs(0, 0) << '\n';
    }

    // ans(0, 0); <- for output tracing (use it for a single test case)

    return 0;
}

// https://www.spoj.com/K50CL/problems/NAJLG/
