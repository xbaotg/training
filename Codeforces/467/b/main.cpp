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
    int n, k, m;
    cin >> n >> m >> k;
    
    int a[m+1];
    for (auto &v : a) cin >> v;

    int t = a[m];
    int res = 0;

    for (auto &v : a) {
        int c = v ^ t;
        int r = 0;
        while (c) {
            r += (c & 1);
            c >>= 1;
        }
        res += r <= k;
    }

    printf("%d", res - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    solve();
}
