#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 1e5 + 7;

int arr[N], dp[N];

int solve(int indx){
    if(indx <= 0) return 0;
    if(dp[indx] != -1) return dp[indx];
    dp[indx] = abs(arr[indx]-arr[indx-1]) + solve(indx-1);
    if(indx - 2 >= 0) dp[indx] = min(dp[indx], abs(arr[indx]-arr[indx-2])+solve(indx-2));
    return dp[indx];
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    memset(dp, -1, sizeof dp);

    cout << solve(n-1) << '\n';

    return 0;
}
//  https://atcoder.jp/contests/dp/tasks/dp_a -
