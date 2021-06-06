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
    ll x, y;
    cin >> n;

    ll m[n];
    ll d[n];
    int cm = -1, cd = -1;

    fort (i, 0, 2*n - 1) {
        cin >> x >> y;
        if (x == 0) {
            cm++;
            m[cm] = abs(y);
        } else {
            cd++;
            d[cd] = abs(x);
        } 
    }

    sort(m, m + n);
    sort(d, d + n);

    double res = 0;
    double t = 0;

    fort (i, 0, n - 1) {
        res += sqrtl(m[i]*m[i] + d[n - i - 1]*d[n - i - 1]);
        t += sqrtl(m[i]*m[i] + d[i]*d[i]);
    }

    if (t < res) 
        res = t;

    cout << fixed << setprecision(15) << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
