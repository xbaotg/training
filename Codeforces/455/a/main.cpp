#include <bits/stdc++.h>
using namespace std;

#define fort(i, a, b) for (int i = a; i < b; i++)
#define ford(i, a, b) for (int i = a; i > b; i--)

typedef long long ll;

void solve();

//---------------------------------------------------------------//
//                                                               //
// FB: https://facebook.com/tgbaodeeptry                         //
//                                                               //
// From Viet Nam :D                                              //
//                                                               //  
//---------------------------------------------------------------//

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t; 
    while (t--)
        solve();
}

void solve() {
    int n, x, m = 0;
    ll freq[100001] = {0};

    cin >> n;
    while (n--)
        cin >> x, m = max(m, x), freq[x]++;

    ll dp[m+1];
    dp[0] = 0;
    dp[1] = freq[1];

    fort (i, 2, m + 1) 
        dp[i] = max(dp[i-2] + freq[i]*i, dp[i-1]);

    cout << dp[m];
}
