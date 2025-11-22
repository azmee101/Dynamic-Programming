#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll MOD = 1e9+7;

#define NEED_FOR_SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int N = 1e5 + 9;

int dp[N];

int fib(int n){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
}

void solve(){
    int n; cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << fib(n) << '\n';
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