#include<bits/stdc++.h>
using namespace std;
 
int max_digit(int n){
    int y = -1;
    while(n >= 10){
        y = max(y, n % 10);
        n /= 10;
    }
    return y = max(y, n);
}
 
int main()
{
    int n; cin >> n;
    int dp[n+1];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; i++){
        int mx = max_digit(i);
        dp[i] = 1 + dp[i-mx];
    }
    cout << dp[n] << '\n';
    return 0;
}

// https://cses.fi/problemset/task/1637
