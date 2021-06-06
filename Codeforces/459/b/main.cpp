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
    unordered_map<int, ll> m;
    int n, x, mi = INT_MAX, ma = INT_MIN;
    
    cin >> n;
    fort(i, 0, n - 1) {
        cin >> x;
        if (m.find(x) == m.end()) 
            m[x] = 1;
        else
            m[x]++;

        mi = min(mi, x);
        ma = max(ma, x);
    }

    int diff = ma - mi;
    ll res = 0;

    if (diff == 0) {
        for (auto p : m) {
            res += (p.second * (p.second - 1) / 2);
        }
    } else 
        for (auto p : m) {
            if (m.find(p.first + diff) != m.end()) {
                res += p.second * m[p.first + diff];
            }
        }

    printf("%d %lld", diff, res);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    solve();
}
