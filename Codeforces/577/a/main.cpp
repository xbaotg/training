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
    int n, x;
    cin >> n >> x;

    // x = 2^a . 3^b . 5^c ....
    
    // 1 | 2 | 3 | 4 | 5 | 6
    // 2 | 4 | 6 | 8 | 10 | 12
    // 3 | 6 | 9 | 12 | 15 | 18
    // ....
    //
    // on a row, it have most 1 value x
    //

    int res = 0;
    for (ll i = 1; i <= n; i++) {
        if (x <= i*n && x % i == 0) 
            res++;
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
