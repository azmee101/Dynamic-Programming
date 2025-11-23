#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int arr[N][3], dp[N][3];
int n;

int solve(int r, int c){

    if(r == n-1) return dp[r][c] = arr[r][c];
    if(dp[r][c] != -1) return dp[r][c];

    if(c == 0) dp[r][c] = arr[r][c] + max(solve(r+1, c+1), solve(r+1, c+2));
    else if(c == 1) dp[r][c] = arr[r][c] + max(solve(r+1, c-1), solve(r+1, c+1));
    else dp[r][c] = arr[r][c] + max(solve(r+1, c-1), solve(r+1, c-2));

    return dp[r][c];
}

void path(int r, int c){

    if(r == n-1){
        cout << '(' << r << ", " << c << ')' << '\n';
        return;
    }

    cout << '(' << r << ", " << c << ')' << "-> ";

    if(c == 0){

        int x = arr[r][c] + solve(r+1, c+1);
        int y = arr[r][c] + solve(r+1, c+2);

        (x > y) ? path(r+1, c+1) : path(r+1, c+2);
    }

    else if(c == 1){

        int x = arr[r][c] + solve(r+1, c-1);
        int y = arr[r][c] + solve(r+1, c+1);

        (x > y) ? path(r+1, c-1) : path(r+1, c+1);
    }

    else{

        int x = arr[r][c] + solve(r+1, c-2);
        int y = arr[r][c] + solve(r+1, c-1);

        (x > y) ? path(r+1, c-2) : path(r+1, c-1);
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }

    memset(dp, -1, sizeof dp);
/*
    for output tracing

    if(solve(0, 0) > solve(0, 1) && solve(0, 0) > solve(0, 2)) path(0, 0);
    else if(solve(0, 1) > solve(0, 0) && solve(0, 1) > solve(0, 2)) path(0, 1);
    else path(0, 2);
*/
    cout << max(solve(0, 0), max(solve(0, 1), solve(0, 2))) << '\n';

    return 0;
}

// https://atcoder.jp/contests/dp/tasks/dp_c
