#include <bits/stdc++.h>
using namespace std;

#define fort(x, a, b) for (int x = a; x <= b; x++)
#define ford(x, a, b) for (int x = a; x >= b; x--)
#define printv(v, sep) fort(i, 0, v.size() - 2) cout << v[i] << sep; cout << v[v.size() - 1];

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>

void solve() {
    int n, m;
    cin >> n >> m;

    if (m == n) 
        cout << 0;
    else if (m < n) 
        cout << (n - m);
    else {
        int res = 0;

        while (m > n) {
            if ((m & 1) == 0) m >>= 1; else m++;
            res ++;
        }

        if (m == n) 
            cout << res;
        else {
            cout << n - m + res;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();

    solve();
}
