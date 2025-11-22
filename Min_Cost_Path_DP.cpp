#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll MOD = 1e9+7;

#define NEED_FOR_SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define inf 1e9
int n, m;
int dp[10][10];
int arr[100][100];

int min_cost(int i, int j){
    if(i == n-1 && j == m-1) return arr[i][j];
    if(i == n || j == m) return inf;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = arr[i][j] + min(min_cost(i+1, j), min_cost(i, j+1));
}

void path(int i, int j){
    if(i == n-1 && j == m-1){
        cout << '(' << i << ' ' << j << ")";
        return;
    }
    cout << '(' << i << ' ' << j << ")-> ";
    int cost1 = arr[i][j] + min_cost(i, j+1);
    int cost2 = arr[i][j] + min_cost(i+1, j);
    if(cost1 > cost2) path(i+1, j);
    else path(i, j+1);
}

int32_t main()
{
    NEED_FOR_SPEED;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    // path(0, 0); <- for ouput tracing
    cout << min_cost(0, 0) << '\n';
    return 0;
}

// https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1
