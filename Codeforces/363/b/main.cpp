#include <bits/stdc++.h>
#include <climits>
#include <numeric>
using namespace std;

#define fort(x, a, b) for (int x = a; x <= b; x++)
#define ford(x, a, b) for (int x = a; x >= b; x--)
#define printv(v, sep) if (v.size() - 2 >= 1) fort(i, 0, v.size() - 2) cout << v[i] << sep; cout << v[v.size() - 1];

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>

void solve() {
    int n, k;
    cin >> n >> k;

    vi a(n);

    for (auto &v : a) cin >> v;

    int s = accumulate(a.begin(), a.begin() + k, 0);
    int res = s;
    int idx = 1;

    fort (i, k, n - 1) {
        s += a[i] - a[i-k];
        if (s < res) {
            idx = i - k + 2;
            res = s;
        }
    }

    cout << idx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    solve();
}
