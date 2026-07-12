#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 107;
int n, W, w[N], v[N];
ll dp[N][100007];

ll solve(int inx, ll val) {
	if (inx == n) {
		if (val == 0) {
			return 0;
		}
		return 1e18;
	}
	if(dp[inx][val] != -1) {
		return dp[inx][val];
	}
	if(inx == n) {
		return 1e18;
	}
	dp[inx][val] = solve(inx+1, val);
	if(val >= v[inx]) {
		dp[inx][val] = min(dp[inx][val], solve(inx+1, val-v[inx])+w[inx]);
	}
	return dp[inx][val];
}

int main()
{
	cin >> n >> W;
	ll mxVal = 0;
	for(int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
		mxVal += v[i];
	}
	ll ans = 0;
	memset(dp, -1, sizeof dp);
	for(int i = mxVal; i >= 0; i--) {
		if(solve(0, i) <= W) {
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
}

/*
	problem link : https://atcoder.jp/contests/dp/tasks/dp_e
	state explanation : dp[inx][val]
	inx theke val pete amr minimum koto weight lagbe such that
	shei weight ta <= W hoy
	je maximum val ei condition fullfill korbe shei val tai ans
*/