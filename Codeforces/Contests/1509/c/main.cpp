#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define deb(x) cout<<"LINE("<<__LINE__<<"): "<<(#x)<<" = "<<(x)<<endl; 
#else
    #define deb(...)
#endif

const double pi = acos(-1.0);

#define fort(i, a, b) for (int i = a; i < b; i++)
#define ford(i, a, b) for (int i = a; i > b; i--)

void solve();
//-----------------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

#ifndef ONLINE_JUDGE
    //freopen("input", "r", stdin);
#endif

    //int t;
    //while (cin >> t)
        solve();
}

void solve() {
    int n;
    cin >> n;

    int a[n];
    for (auto &v : a)
        cin >> v;

    sort(a, a + n);
    long long res = 1e18;

    for (int i = 0; i < n; i++) {
        long long r1 = 0, r2 = 0;
        // a
        for (int j = i + 1; j < n; j++) {
            r1 += a[j] - a[i];
        }
        for (int j = i - 1; j >= 0; j--) {
            r1 += a[n-1] - a[j];
        }

        // b
        for (int j = i - 1; j >= 0; j--) {
            r2 += a[i] - a[j];
        }
        for (int j = i+1; j < n; j++) {
            r2 += a[j] - a[0];
        }

        res = min({res, r1, r2});
    }

    cout << res;
}
