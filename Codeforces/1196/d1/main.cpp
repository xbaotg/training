#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define         FOR(i, a, b) for (int i = int(a); i <= int(b); i++)
#define         FOD(i, a, b) for (int i = int(a); i >= int(b); i--)
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

void solve();
template<class T> void read(T &x) { cin >> x; };
template<class T> void read(vector<T> &v, int n) { FOR (i, 0, n - 1) cin >> v[i]; };
template<class T> void read(vector<T> &v, int f, int t) { FOR (i, f, t) cin >> v[i]; };

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

int c[3][100];
int base[3] = {0};
int n, k;

int getDiff() {
    return min({
            abs(c[0]['R'] - base[0]) + abs(c[1]['G'] - base[1]) + abs(c[2]['B'] - base[2]),
            abs(c[0]['G'] - base[0]) + abs(c[1]['B'] - base[1]) + abs(c[2]['R'] - base[2]),
            abs(c[0]['B'] - base[0]) + abs(c[1]['R'] - base[1]) + abs(c[2]['G'] - base[2])
            });
}

void solve() {
    read(n); read(k);
    string s;
    read(s);

    memset(c, 0, sizeof c);

    // base
    base[0] = ceil(k / 3.0);
    base[1] = ceil((k - 1) / 3.0);
    base[2] = ceil((k - 2) / 3.0);

    FOR(i, 0, k - 1) 
        c[i % 3][(int) s[i]]++;

    int ans = getDiff();
    FOR (i, k, n - 1) {
        c[(i - k) % 3][(int) s[i - k]]--;
        c[i % 3][(int) s[i]]++;
        ans = min(ans, getDiff());
    }

    cout << ans << endl;
}
