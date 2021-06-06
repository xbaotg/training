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
    int n, m, v;
    cin >> n >> m;

    int a[n];
    for (auto & v : a) cin >> v;

    bool b[100006];
    memset(b, false, sizeof b);

    int c[n+1];
    memset(c, 0, sizeof c);

    ford (i, n - 1, 0) {
        c[i] = c[i+1] + (!b[a[i]]);
        b[a[i]] = true;
    }

    while (m--) {
        cin >> v;
        cout << c[v-1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    solve();
}
