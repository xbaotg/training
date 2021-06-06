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
    int n, x;
    cin >> n;

    int ans = 0, cur = 0, ones = 0;

    fort (i, 0, n) {
        cin >> x;

        if (x == 1) {
            cur = max(0, cur - 1);
            ones++;
        } else {
            cur++;
        }

        ans = max(ans, cur);
    }

    if (ones == n) {
        cout << n - 1;
        return;
    }

    cout << ans + ones;
}
