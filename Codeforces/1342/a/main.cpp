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
    unsigned ll x, y, a, b;
    unsigned ll res = ULLONG_MAX;

    cin >> x >> y >> a >> b;

    if (x == 0 && y == 0) 
        res = 0;

    res = min({
        res,
        min(x, y) * b + a * (max(x, y) - min(x, y)),
        x * a + y * a,
    });

    printf("%lld\n", res);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
