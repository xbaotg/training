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
    int n, t;
    cin >> n >> t;

    int s = 0;
    vi a(n);

    for (auto &v : a) {
        cin >> v;
        s += v;
    }

    int ps = 0, pe = n - 1;

    while (ps <= pe && s > t) {
        if (a[ps] > a[pe]) { 
            s -= a[ps];
            ps++;
        }
        else {
            s -= a[pe];
            pe--;
        }
    }

    cout << (pe - ps + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    solve();
}
