#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fort(i, a, b) for (int i = a; i < b; i++)
#define ford(i, a, b) for (int i = int(a) - 1; i >= b; i--)

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

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n][m], c[n + m - 1][2];
    fill(&c[0][0], &c[0][0] + (n + m - 1)*2, 0);
    
    fort (i, 0, n)
        fort (j, 0, m) {
            cin >> a[i][j], c[i + j][a[i][j]]++;
        }

    int ans = 0;
    fort (i, 0, n + m - 1) {
        int j = n + m - 2 - i;
        if (j <= i) 
            break;
        ans += min(c[i][1] + c[j][1], c[i][0] + c[j][0]);
    }

    cout << ans << endl;
}
