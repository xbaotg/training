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

    int l = 0, c = 0, ans = 0;

    while (n--) {
        cin >> x;

        if (x > l) {
            c++;
        } else {
            c = 1;
        }

        l = x;
        ans = max(c, ans);
    }

    cout << ans;
}
