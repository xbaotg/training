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
    //freopen("input", "r", stdin);
    fast_io;
    
    int n, p;
    cin >> n >> p;

    int w[n], v[n], dp[101] = {0};
    set<int> choose[101];

    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        dp[w[i]] = v[i];
        choose[w[i]] = {i};
    }

    for (int i = 1; i <= p; i++) {
        int c = -1;
        for (int j = 0; j < n; j++) {
            if (i - w[j] >= 0 && choose[i - w[j]].find(j) == choose[i - w[j]].end() && dp[i] <= dp[i - w[j]] + v[j]) {
                dp[i] = dp[i - w[j]] + v[j];
                c = j;
            }
        }
        if (c != -1) {
            choose[i] = {choose[i - w[c]].begin(), choose[i - w[c]].end()};
            choose[i].emplace(c);
        }
    }

    cout << dp[p] << endl;
    for (auto v : choose[p])
        cout << v + 1 << " ";
}
