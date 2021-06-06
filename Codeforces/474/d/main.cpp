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

int k;
int dp[100001][2];

// 0 - red, 1 - white
int f(int idx) {
    if (idx <= 0)
        return idx == 0;

    if (dp[idx][0] == -1)
        dp[idx][0] = f(idx - 1);

    if (dp[idx][1] == -1)
        dp[idx][1] = f(idx - k);

    return add_mod(dp[idx][0], dp[idx][1]);
}

struct Seg {
    int *v;
    int zz[400001];

    int build(int node, int l, int r) {
        if (l == r)
            return zz[node] = v[l];

        int m = (l + r) >> 1;
        return zz[node] = add_mod(build(2*node, l, m), build(2*node + 1, m+1, r));
    }

    int query(int node, int l, int r, int s, int e) {
        if (r < s || l > e)
            return 0;

        if (s <= l && r <= e)
            return zz[node];

        int m = (l + r) >> 1;
        return add_mod(query(2*node, l, m, s, e), query(2*node + 1, m + 1, r, s, e));
    }
};

Seg s;

int main() {
    fast_io;

    #ifdef _CRUN 
        //freopen("input", "r", stdin);
    #endif

    int t = 1; 
    cin >> t >> k; 

    // init before
    memset(dp, -1, sizeof dp);
    f(100000);

    int v[100001];
    For (i, 1, 100000)
        v[i-1] = add_mod(dp[i][0], dp[i][1]);

    s.v = v;
    s.build(1, 0, 99999);

    while (t--)
        solve();
}

void solve() {
    int a, b;
    read(a, b);

    --a, --b;

    cout << s.query(1, 0, 99999, a, b) << endl;
}
