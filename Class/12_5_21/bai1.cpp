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
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

const int MOD = 1000000007;
const int INF = INT_MAX;

int plus_mod(unsigned int a, unsigned int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int minus_mod(unsigned int a, unsigned int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
int mul_mod(unsigned int a, unsigned int b) { return ((a % MOD) * 1LL * (b % MOD)) % MOD; }
int lcm(unsigned int a, unsigned int b) { return a * 1LL * b / __gcd(a, b); }
int gcd(unsigned int a, unsigned int b) { return __gcd(a, b); }

//-----------------------------------------------------------------------------

int main() {
    freopen("input", "r", stdin);
    fast_io;
    
    int n;
    cin >> n;

    int a[n][n];
    for (auto &v : a)
        for (auto &z : v)
            cin >> z;

    ll ans = 0;

    fort (i, 0, n - 1)
        fort (j, 0, n - 1) {
            vector<int> t = {a[i][j], a[i][j+1], a[i+1][j+1], a[i+1][j]};
            fort (i, 0, 4)
                t.emplace_back(t[i]);

            //int idx = distance(t.begin(), lower_bound(ALL(t), *min_element(ALL(t))));
            int idx = distance(t.begin(), find(ALL(t), *min_element(ALL(t))));
            
            bool ok = true;
            fort (i, idx + 1, idx + 4) 
                ok = ok & (t[i] > t[i-1]);

            ans += ok;
        }

    cout << ans;
}
