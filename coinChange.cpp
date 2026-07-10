#include<bits/stdc++.h>
using namespace std;

const int N = 51, K = 1007, MOD = 100000007;
int dp[N][K];
int n, k, a[N], c[N];

int solve(int i, int curSum){
	if(curSum > k) {
		return 0;
	}
	if(i == n) {
		if(curSum == k) {
			return 1;
		}
		return 0;
	}
	if(dp[i][curSum] != -1) {
		return dp[i][curSum];
	}
	int ans = 0;
	for(int cnt = 0; cnt <= c[i]; cnt++) {
		ans = (ans + solve(i+1, curSum+cnt*a[i])) % MOD;
	}
	return dp[i][curSum] = ans;
}

int main()
{
	int t; cin >> t;
	int cnt = 1;
	while(t--){
		memset(dp, -1, sizeof dp);
		cin >> n >> k;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> c[i];
		}
		cout << "Case " << cnt << ": "<< solve(0, 0) << '\n';
		cnt++;
	}
	return 0;
}
/*
	https://lightoj.com/problem/coin-change-i
	This is bounded problem because, it has a limit
	to take the coins at most c[x]
*/