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
    ll n, k;
    cin >> n >> k;

    if (k < n) {
        cout << k << endl;
        return;
    } 

    // 3
    // | 1 2 | 4 5 | 7 8 | 10 11 |

    ll a = ceil(1.0 * k / (n - 1));
    ll b = k % (n - 1);

    if (b == 0) {
        b = n - 1;
    }

    b = n - b;

    cout << n*a - b << endl;    
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
