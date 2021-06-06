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

void solve();

int plus_mod(unsigned int a, unsigned int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int minus_mod(unsigned int a, unsigned int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
int mul_mod(unsigned int a, unsigned int b) { return ((a % MOD) * 1LL * (b % MOD)) % MOD; }
int lcm(unsigned int a, unsigned int b) { return a * 1LL * b / __gcd(a, b); }
int gcd(unsigned int a, unsigned int b) { return __gcd(a, b); }

//---------------------------------------------------------------//
//                                                               //
// FB: https://facebook.com/tgbaodeeptry                         //
//                                                               //
// From Viet Nam with Love :D                                    //
//                                                               //  
//---------------------------------------------------------------//

int main() {
    fast_io;

    #ifdef _CRUN
        //freopen("input", "r", stdin);
    #endif

    int t = 1;
    cin >> t; 
    while (t--)
        solve();
}

int median(vector<int> a) {
    sort(a.begin(), a.end());
    int ave = round(1.0 * (a[1] + a[2]) / 2);

    return ave - a[0] + ave - a[1] + a[2] - ave + a[3] - ave;
}

void solve() {
    int n, m;
    cin >> n >> m;
    ll a[n][m];
    ll ans = 0;

    fort (i, 0, n) fort (j, 0, m) cin >> a[i][j];

    fort (i, 0, n / 2) {
        fort (j, 0, m / 2) {
            int n1 = a[i][j], n2 = a[i][m-j-1], n3 = a[n-i-1][j], n4 = a[n-i-1][m-j-1];
            ans += median({n1, n2, n3, n4});
        }
    }
    
    if (m & 1) {
        fort (i, 0, n / 2) {
            //ave = round(1.0 * (a[i][m / 2] + a[n - i - 1][m / 2]) / 2);
            //ans += abs(ave - a[i][m/2]) + abs(ave - a[n-i-1][m/2]);
            ans += abs(a[i][m / 2] - a[n - i - 1][m / 2]);
        }
    }
    if (n & 1) {
        fort (i, 0, m / 2) {
            //ave = round(1.0 * (a[n / 2][i] + a[n / 2][m - i - 1]) / 2);
            //ans += abs(ave - a[n / 2][i]) + abs(ave - a[n / 2][m - i - 1]);
            ans += abs(a[n / 2][i] - a[n / 2][m - i - 1]);
        }
    }

    cout << ans << endl;
}
