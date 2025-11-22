#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll MOD = 1e9+7;

#define NEED_FOR_SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve(){
    
    int n; cin >> n;
    int fib[n+1] = {0};
    
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i <= n; i++){
    	fib[i] = fib[i-1] + fib[i-2];
    }

    cout << fib[n] << '\n';
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
