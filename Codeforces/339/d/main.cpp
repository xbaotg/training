#include <bits/stdc++.h>
using namespace std;

#define fast_io        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FOR(i, a, b)   for (int i = int(a); i <= int(b); i++)
#define FOD(i, a, b)   for (int i = int(a); i >= int(b); i--)
#define SZ(x)          ((int) x.size())
#define ALL(x)         (x).begin(), (x).end()
#define F              first
#define S              second
#define ep             emplace_back

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
template<class T> void read(T v[], int n) { FOR(i, 0, n - 1) cin >> v[i]; }; 
template<class H, class... T> void read(H &v, T&... args) { read(v); read(args...); };

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

struct Seg {
    int n;
    int *z;
    int *a;
    
    Seg(int n, int *a) {
        this->n = n;
        this->z = new int[4*n+1];
        this->a = a;
    }

    int build(int node, int l, int r, int level) {
        if (l == r)
            return z[node] = a[l];

        int m = (l + r) >> 1;

        if ((level & 1) == 0)
            return z[node] = build(node<<1, l, m, level - 1) | build(node<<1|1, m+1, r, level - 1);

        return z[node] = build(node<<1, l, m, level - 1) ^ build(node<<1|1, m+1, r, level - 1);
    }

    int update(int node, int l, int r, int idx, int v, int level) {
        if (idx > r || idx < l)
            return z[node];

        if (l == r)
            return a[idx] = v, z[node] = v;

        int m = (l + r) >> 1;

        if ((level & 1) == 0)
            return z[node] = update(node<<1, l, m, idx, v, level - 1) | update(node<<1|1, m+1, r, idx, v, level - 1);

        return z[node] = update(node<<1, l, m, idx, v, level - 1) ^ update(node<<1|1, m+1, r, idx, v, level - 1);
    }
};

void solve() {
    int n, m;
    read(n, m);

    int t = n;
    n = 1 << n;

    int a[n];
    for (auto &v : a)
        cin >> v;

    Seg seg(n, a);
    seg.build(1, 0, n - 1, t + 1);

    while (m--) {
        int p, b;
        read(p, b);

        int ans = seg.update(1, 0, n-1, p-1, b, t + 1);
        cout << ans << endl;
    }
}
