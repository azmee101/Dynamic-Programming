#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll MOD = 1e9+7;
const int N = 105;
const int x = 1e5+7;
ll n, W;
ll w[N], v[N];
ll dp[N][x];


#define NEED_FOR_SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll maximum(int i, int weight){
    if(i == n + 1) return 0;
    if(dp[i][weight] != -1) return dp[i][weight];
    ll ans = maximum(i+1, weight);
    if(weight + w[i] <= W) ans = max (ans, maximum(i+1, weight+w[i]) + v[i]);
    return dp[i][weight] = ans;
}

void solve(){
    cin >> n >> W;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    memset(dp, -1, sizeof dp);
    cout << maximum(1, 0) << '\n';
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

// https://atcoder.jp/contests/dp/tasks/dp_d
