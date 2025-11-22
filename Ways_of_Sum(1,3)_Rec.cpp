#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll MOD = 1e9+7;

#define NEED_FOR_SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int ways(int i){
    if(i == 1 || i == 2) return 1;
    if(i == 3) return 2;
    return ways(i-1) + ways(i-3);
}

void solve(){
    int n; cin >> n;
    cout << ways(n) << '\n';
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


// Count of different ways to express N as the sum of 1, 3
