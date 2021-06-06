#include <bits/stdc++.h>
#include <climits>
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
    ll v;
    cin >> n;

    cin >> v;

    // true, cur is positive else negative
    bool cur = v > 0;
    ll res = 0;
    ll ma = v;

    fort (i, 0, n - 2) {
        cin >> v;
        if (v > 0 == cur) {
            ma = max(ma, v);
        } else {
            res += ma;
            ma = v;
            cur = v > 0;
        }
    }
    res += ma;

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
