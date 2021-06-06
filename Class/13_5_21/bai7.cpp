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
bool b[30][30] = {false};
int m, n, k;

void block(int x, int y) {
    if (x) for (int i = max(0, y - 1); i <= min(y + 1, n - 1); i++) b[x-1][i] = true;
    if (x < m - 1) for (int i = max(0, y - 1); i <= min(y + 1, n - 1); i++) b[x+1][i] = true;
    if (y) b[x][y-1] = true;
    if (y < n - 1) b[x][y+1] = true;
    b[x][y] = true;
}

int main() {
    fast_io;
    
    cin >> m >> n >> k;

    while (k--) {
        int x, y;
        cin >> x >> y;

        block(--x, --y);
    }

    int count = 0;
    vector<pair<int, int>> ans;

    for (int i = 0; i < m / 2 && i < n / 2; i++) {
        // hang tren
        for (int j = 0; j < n; j++) {
            if (!b[i][j])
                count++, block(i, j), ans.emplace_back(i, j);
        }

        // ben phai
        for (int j = 0; j < m; j++) {
            if (!b[j][n-1-i])
                count++, block(j, n-1-i), ans.emplace_back(j, n-1-i);
        }

        // ben duoi
        for (int j = 0; j < n; j++) {
            if (!b[m-1-i][j])
                count++, block(m-1-i, j), ans.emplace_back(m-1-i, j);
        }

        // ben trai
        for (int j = 0; j < m; j++) {
            if (!b[j][i])
                count++, block(j, i), ans.emplace_back(j, i);
        }

    }

    if (m % 2 == 1) {
        for (int i = 0; i < n; i++) 
            if (!b[m / 2][i])
                count++, block(m / 2, i), ans.emplace_back(m / 2, i);
    }

    if (n % 2 == 1)
        for (int i = 0; i < m; i++) 
            if (!b[i][n / 2])
                count++, block(i, n / 2), ans.emplace_back(i, n / 2);

    cout << count << endl;
    for (auto p : ans)
        cout << p.F + 1 << " " << p.S + 1 << endl;
}
