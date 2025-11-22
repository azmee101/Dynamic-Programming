#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll MOD = 1e9+7;

#define NEED_FOR_SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define inf 1e9+7;

const int N = 1e5 + 7;
int arr[N], dp[N];
int n, k;


int solve(int indx){
    if(indx == n-1) return dp[indx] = 0;
    if(dp[indx] != -1) return dp[indx];

    int mn = INT_MAX, ans;
    
    for(int j = 1; j <= k; j++){
        if(indx + j < n){
            ans = abs(arr[indx] - arr[indx + j]) + solve(indx + j);
            mn = min(mn, ans);
        }
    }
    return dp[indx] = mn;
}

int32_t main()
{
    NEED_FOR_SPEED;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0) << '\n';
    return 0;
}

// https://atcoder.jp/contests/dp/tasks/dp_b
