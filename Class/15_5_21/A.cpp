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
    
    int n, m, x;
    cin >> n >> m;

    vector<pair<int, int>> d (n), v (m);

    fort (i, 0, n) {
        cin >> x;
        d[i] = {i, x};
    }
    fort (i, 0, m) {
        cin >> x;
        v[i] = {i, x};
    }

    sort(d.begin(), d.end(), [](pair<int, int> f, pair<int, int> s) { return f.second < s.second; });
    sort(v.begin(), v.end(), [](pair<int, int> f, pair<int, int> s) { return f.second < s.second; });

    v.resize(n);
    reverse(v.begin(), v.end());

    ll ans = 0;
    vector<int> xe (n);

    fort (i, 0, n) {
        ans += d[i].second * v[i].second;
        xe[d[i].first] = v[i].first;
    }

    cout << ans << endl;
    fort (i, 0, n)
        cout << xe[i] + 1 << " ";
}
