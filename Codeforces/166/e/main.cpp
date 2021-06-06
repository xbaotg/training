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
    #ifdef _CRUN 
        freopen("input", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t; 
    while (t--)
        solve();
}

int n;
int m = 1e9 + 7;

void solve() {
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    if (n == 2) {
        cout << 3 << endl;
        return;
    }

    // 0
    // 3 = 3 
    // 6 = 3 + 3               (n = 1)
    // 21 = 3.2 + 3.5          (n = 2)
    // 60 = 3.7 + 3.13
    // 183 = 3.20 + 3.41
    // 546 = 3.61 + 3.121
    //
    // 1 5 13 41 121
    // so thu n: 3*last + (0 if n % 2 == 1 else 4) + 1
    //
    // n + 0 4 12 40 120
    // n + 
    //
    // l = l + 3*()

    //int l[4] = {1, 1, 1, 0};
    //int f[n];

    //fort (i, 2, n) {
        //fort (j, 0, 4) {
            //f[j] = 0;
            //fort (k, 0, 4) 
                //if (j != k)
                    //f[j] = ( f[j] % m + l[k] % m ) % m;
        //}
        //fort (j, 0, 4)
            //l[j]3 = f[j];
    //}

    //int ans = 0;
    //fort (i, 0, 3) {
        //ans = (ans % m + l[i] % m) % m;
    //}

    int l = 3;
    ll lt = 1;

    fort (i, 1, n - 1) {
        lt = ( 3*( lt - 1 ) + (i % 2 == 1 ? 0 : 4) + 1 ) % m;
        //assert(lt >= 1e9);
        l = ( l % m + (3 * (lt % m)) % m ) % m;
    }

    cout << l << endl;
}
