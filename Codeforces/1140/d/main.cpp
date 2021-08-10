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

void solve();
template<class T> void read(T &x) { cin >> x; };
template<class T> void read(vector<T> &v, int n) { fort (i, 0, n) cin >> v[i]; };
template<class T> void read(vector<T> &v, int f, int t) { fort (i, f, t + 1) cin >> v[i]; };

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
    //cin >> t; 
    while (t--)
    solve();
}

void solve() {
    ll n;
    read(n);

    // 1*2*3, 1*3*4, ..., 1*(n-1)*n
    // 2*3 + 3*4 + ... + (n-1)*n
    // 2 + 3 + ... + n - 1
    //
    ll ans = (n-1)*n*(2*n - 1)/6 + (n + 1)*(n - 2)/2 - 1;

    cout << ans;
}
