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
    string s;
    cin >> s;

    int n = s.length();

    int pre[n] = {0}, suf[n] = {0};

    pre[0] = s[0] == 'Q';
    suf[n-1] = s[n-1] == 'Q';

    fort (i, 1, n) {
        pre[i] = pre[i - 1] + (s[i] == 'Q');
    }
    ford (i, n-2, -1) {
        suf[i] = suf[i+1] + (s[i] == 'Q');
    }

    int ans = 0;

    fort (i, 0, n) {
        if (s[i] == 'A') {
            ans += pre[i] * suf[i];
        }
    }

    cout << ans;
}
