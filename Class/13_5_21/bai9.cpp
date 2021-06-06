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
    fast_io;
    
    int m, n;
    char ch;
    cin >> m >> n;

    int a[m+2][n+2];
    memset(a, 0, sizeof a);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ch;
            a[i][j] = (ch == '*') ? 1 : 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1)
                cout << '*';
            else
                cout << a[i-1][j-1] + a[i-1][j] + a[i-1][j+1] + a[i][j-1] + a[i][j+1] + a[i+1][j-1] + a[i+1][j] + a[i+1][j+1];
        }
        cout << endl;
    }
}
