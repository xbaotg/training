#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fort(i, a, b) for (int i = a; i < b; i++)
#define ford(i, a, b) for (int i = a; i > b; i--)

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
// vector<pair<int, int>> res;
unordered_map<int, bool> block;
ll ans = 0;
int n, k;

void f(int idx, int ch) {
    if (ch > k) 
        return;

    if (idx > 2*n - 1) {
        if (ch == k) {
            ans++;

            //bool d[n][n];
            //memset(d, false, sizeof d);

            //fort (i, 0, 2*n - 1) {
                //auto p = res[i + 1];
                //if (p.first == -1) 
                    //continue;
                //d[p.first][p.second] = true;
            //}

            //fort (i, 0, n) {
                //fort (j, 0, n) {
                    //cout << "|";
                    //if (d[i][j]) 
                        //cout << "x";
                    //else
                        //cout << " ";
                //}
                //cout << "|";
                //cout << endl;
            //} cout << endl;
        }
        return;
    }

    if (idx <= n) {
        if (2*n - idx > k - ch) {
            //res[idx] = {-1, -1}; 
            f(idx + 1, ch);
        }
        fort (i, 0, idx) {
            int r = i;
            int c = idx - i - 1;

            if (block[r - c])
                continue;

            //res[idx] = {r, c};
            block[r-c] = true;
            f(idx+1, ch+1);
            block[r-c] = false;
        }
    } else {
        if (2*n - idx > k - ch) {
            //res[idx] = {-1,-1}; 
            f(idx + 1, ch);
        }
        fort (i, 0, 2*n - idx) {
            int r = idx - n + i;
            int c = n - i - 1;

            // r - c = idx - n + i - n + i + 1 = idx - 2*n + 2*i + 1

            if (block[r - c])
                continue;

            //res[idx] = {r, c};
            block[r-c] = true;
            f(idx+1, ch+1);
            block[r-c] = false;
        }
    }
}

int main() {
    fast_io;

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;

        if (k > 2*(n-1)) {
            cout << 0 << "\n";
            continue;
        }

        ans = 0;
        //res.assign(2*n + 1, {-1, -1});
        //unordered_map<int, bool> block;
        //fort (i, n - 1, n) 
            //block[i] = false;

        f(1, 0);

        cout << ans << endl;
    }
}
