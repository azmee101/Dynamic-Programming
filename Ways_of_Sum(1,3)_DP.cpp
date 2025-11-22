#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll MOD = 1e9+7;

const int N = 1e5 + 9;
const ll mod = 1e9+7; 
int dp[N];

#define NEED_FOR_SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int ways(int i){
    if(dp[i] != -1) return dp[i];
    if(i == 1 || i == 2) return 1;
    if(i == 3) return 2;
    return dp[i] = (ways(i-1) + ways(i-3)) % mod;
}

void solve(){
    int n; cin >> n;
    memset(dp, -1, sizeof dp);
    cout << ways(n) << '\n';
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