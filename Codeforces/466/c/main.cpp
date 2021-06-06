#include <bits/stdc++.h>
using namespace std;

#define fort(x, a, b) for (int x = a; x <= b; x++)
#define ford(x, a, b) for (int x = a; x >= b; x--)
#define printv(v, sep) if (v.size() - 2 >= 1) fort(i, 0, v.size() - 2) cout << v[i] << sep; cout << v[v.size() - 1];

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>

void solve() {
    int n;
    cin >> n;

    int a[n];
    ll res = 0;
    ll s = 0;

    fort (i, 0, n - 1) {
        cin >> a[i];
        s += a[i];
    }

    // same three parts => so call s is sum of array => s is divisible 3
    if (s % 3 == 0) {
        // call c[i] is count subarray equal to s / 3 from i...n
        int c[n+1];
        memset(c, 0, sizeof c);

        ll t = 0;

        ford (i, n - 1, 0) {
            t += a[i];
            c[i] = c[i+1] + (t == s / 3);
        }

        t = 0;
        fort (i, 0, n - 3) {
            t += a[i];
            if (t == s / 3) 
                res += c[i+2];
        }
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    solve();
}
