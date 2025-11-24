#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int n, k;
int arr[N], dp[N];


int main()
{
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    dp[0] = 0;
    int mn = INT_MAX, ans;
    for(int i = 1; i < n; i++){
        for(int j = k; j >= 1; j--){
            if(i - j >= 0){
                ans = dp[i-j] + abs(arr[i]-arr[i-j]);
                mn = min(mn, ans);
            }
        }
        dp[i] = mn;
        mn = INT_MAX;
    }

    cout << dp[n-1] << '\n';

    return 0;
}

// https://atcoder.jp/contests/dp/tasks/dp_b
