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
    int n, k, x;
    cin >> n >> k >> x;

    int a[n];
    for (auto &v : a) cin >> v;

    int ans = 0;
    ford (i, n - 1, -1) {
        if (k) 
            ans += x, k--;
        else
            ans += a[i];
    }

    cout << ans;
}
