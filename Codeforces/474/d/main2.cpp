#include <bits/stdc++.h>
using namespace std;

#define fast_io        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define For(i, a, b)   for (int i = int(a); i <= int(b); i++)
#define Fod(i, a, b)   for (int i = int(a); i >= int(b); i--)
#define sz(x)          ((int) x.size())
#define ALL(x)         (x).begin(), (x).end()
#define F              first
#define S              second
#define ep             emplace_back
#define pb             push_back

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

const int MOD = 1000000007;

template<class T> void read(T &x) { cin >> x; };
template<class T> void read(vector<T> &v, int n) { For (i, 0, n - 1) cin >> v[i]; };
template<class T> void read(vector<T> &v, int f, int t) { For (i, f, t) cin >> v[i]; };
template<class T> void read(T v[], int n) { For(i, 0, n - 1) cin >> v[i]; }; 
template<class H, class... T> void read(H &v, T&... args) { read(v); read(args...); };

int add_mod(unsigned int a, unsigned int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int sub_mod(unsigned int a, unsigned int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
int mul_mod(unsigned int a, unsigned int b) { return ((a % MOD) * 1LL * (b % MOD)) % MOD; }
int lcm(unsigned int a, unsigned int b) { return a * 1LL * b / __gcd(a, b); }

void solve();
//-----------------------------------------------------//
//                                                     //
// FB: https://facebook.com/tgbaodeeptry               //
//                                                     //
// From Viet Nam with Love :D                          //
//                                                     //  
//-----------------------------------------------------//
int logs[100001];
int table[100001][17];

int main() {
    fast_io;

    #ifdef _CRUN 
        //freopen("input", "r", stdin);
    #endif

    int t, k; 
    cin >> t >> k; 

    // init before
    int dp[100001];
    dp[0] = 1;
    
    For (i, 1, 100000) {
        if (i - k >= 0)
            dp[i] = add_mod(dp[i-1], dp[i-k]);
        else
            dp[i] = dp[i-1];
    }

    // sparse table
    logs[1] = 0;
    For (i, 2, 100000) 
        logs[i] = logs[i / 2] + 1;

    for (int i = 0; i <= 100000; ++i)
        table[i][0] = dp[i];

    // i + (1 << j) - 1 < n (with n is count of elements)

    For (j, 1, logs[100000]) {
        int c = 1 << (j - 1);
        for (int i = 1; i + (1 << j) - 1 < 100001; ++i) {
            table[i][j] = add_mod(table[i][j-1], table[i+c][j-1]);
        }
    }

    while (t--) solve();
}

void solve() {
    int a, b;
    cin >> a >> b;

    int ans = 0;

    while (a <= b) {
        int len = b - a + 1;
        int c = logs[len];

        ans = add_mod(ans, table[a][c]);
        a += 1 << c;
    }

    cout << ans << endl;
}
