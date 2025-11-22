#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll MOD = 1e9+7;
const int N = 105;
int n, W;
int w[N], v[N];


#define NEED_FOR_SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int maximum(int i, int weight){
    if(i == n + 1) return 0;
    int ans = maximum(i+1, weight);
    if(weight + w[i] <= W) ans = max (ans, maximum(i+1, weight+w[i]) + v[i]);
    return ans;
}

void solve(){
    cin >> n >> W;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    cout << maximum(1, 0) << '\n';
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