#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fort(i, a, b) for (int i = int(a); i < int(b); i++)
#define ford(i, a, b) for (int i = int(a) - 1; i >= b; i--)
#define SZ(x) ((int) x.size())
#define ALL(x) (x).begin(), (x).end()
#define F first
#define S second

using ll = long long;
const int MOD = 1000000007;
const int INF = INT_MAX;
//-----------------------------------------------------------------------------

int main() {
    fast_io;
    
    int n, a, b, c;
    cin >> n;

    unordered_map<ll, int> cnt;
    fort (i, 0, n) {
        cin >> a >> b >> c;
        ll t = (1.0 * a / b) * int(1e9);

        if (cnt.find(t) == cnt.end()) 
            cnt[t] = 0;
        cnt[t]++;
    }

    // nA2 = n! / (n - 2)!  = n*(n-1)

    int ss = 0;
    for (auto p : cnt) {
        if (p.second >= 2) 
            ss += p.second * (p.second - 1);
    }

    cout << (n*(n-1) - ss) / 2 << endl;
}
