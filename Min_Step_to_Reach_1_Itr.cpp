#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll MOD = 1e9+7;

#define NEED_FOR_SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve(){
    
    int n; cin >> n;
    int steps[n+1];

    steps[1] = 0;
    int ans = 0;

    for(int i = 2; i <= n; i++){
        
        ans = steps[i-1] + 1;

        if(i % 2 == 0){
            ans = min(ans, steps[i/2] + 1);
        }
        if(i % 3 == 0){
            ans = min(ans, steps[i/3] + 1);
        }

        steps[i] = ans;
    }

    cout << steps[n] << '\n';

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

/*

You can:

Subtract 1 (n → n-1)

Divide by 2 if divisible

Divide by 3 if divisible

Goal: minimum number of operations to reach 1.

*/
