#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll MOD = 1e9+7;

#define NEED_FOR_SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e5+9;
int dp[N];

int ans(int n){
    if(n == 1) return 0;
    if(dp[n] != -1) return dp[n];
    if(n % 2 == 0 && n % 3 == 0){
        dp[n] = 1 + min(ans(n-1), min(ans(n/2), ans(n/3)));
    }
    else if(n % 2 == 0){
        dp[n] = 1 + min(ans(n-1), ans(n/2));
    }
    else if(n % 3 == 0){
        dp[n] = 1 + min(ans(n-1), ans(n/3));
    }
    else{
        dp[n] = 1 + ans(n-1);
    }
    return dp[n];
}

void solve(){
    int n; cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << ans(n) << '\n';
    return;
}

int32_t main()
{
    NEED_FOR_SPEED;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

/*

You can:

Subtract 1 (n → n-1)

Divide by 2 if divisible

Divide by 3 if divisible

Goal: minimum number of operations to reach 1.

*/
