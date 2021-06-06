#include <bits/stdc++.h>
using namespace std;

#define fort(x, a, b) for (int x = a; x <= b; x++)
#define ford(x, a, b) for (int x = a; x >= b; x--)

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>

int s(int x[], int n, int v) {
    int l = 0;
    int r = n - 1;
    int m;
    int res = 0;

    while (l <= r) {
        m = (l + r) >> 1;
        
        if (v >= x[m]) {
            l = m + 1;
            res = l;
        } else {
            r = m - 1;
        }
    }

    return res;
}

void solve() {
    int n, q;

    cin >> n;
    int x[n]; 
    for (auto &v : x) cin >> v;

    sort(x, x + n);
    
    cin >> q;
    while (q--) {
        int v;
        cin >> v;
        cout << s(x, n, v) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();

    solve();
}
