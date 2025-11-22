#include<bits/stdc++.h>
using namespace std;
#define inf 1e9+7


const int N = 1e5+7;
int arr[N], dp[N];
int n;

int solve(int indx){
    if(indx == n) return 0;
    if(dp[indx] != -1) return dp[indx];
    int sum1 = 0, sum2 = inf;
    if(indx + 1 < n) sum1 = abs(arr[indx+1] - arr[indx]) + solve(indx + 1);
    if(indx + 2 < n) sum2 = abs(arr[indx+2] - arr[indx]) + solve(indx + 2);
    return dp[indx] = min(sum1, sum2);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0) << '\n';
    return 0;
}
//  https://atcoder.jp/contests/dp/tasks/dp_a -
