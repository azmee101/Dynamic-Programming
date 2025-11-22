#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int dp[n];
    dp[n-1] = 0;
    dp[n-2] = abs(arr[n-1]-arr[n-2]);
    for(int i = n-3; i >= 0; i--){
        dp[i] = min((abs(arr[i]-arr[i+1])+dp[i+1]), (abs(arr[i]-arr[i+2])+dp[i+2]));
    }
    cout << dp[0] << '\n';
}
//  https://atcoder.jp/contests/dp/tasks/dp_a -
