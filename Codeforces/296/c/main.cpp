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

struct Fenwick {
    ll n;
    ll bit[100001];

    Fenwick (ll n) {
        this->n = n;
        memset(bit, 0, sizeof bit);
    }

    void update(ll idx, ll value) {
        for (; idx <= n; bit[idx] += value, idx += (idx & -idx));
    }

    void update(ll l, ll r, ll v) {
        update(l, v);
        update(r + 1, -v);
    }

    ll query(ll idx) {
        ll ans = 0;
        for (; idx; ans += bit[idx], idx -= idx & -idx);
        return ans;
    }
};

ll n, m, k, l, r, d, c;

void solve() {
    read(n, m, k);

    int a[n];
    read(a, n);

    vector<tuple<int, int, int>> ms;

    Fenwick ft1 (m);
    Fenwick ft2 (n);
    
    For (i, 0, m - 1) {
        read(l, r, d);
        ms.ep(l, r, d);
    }

    while (k--) {
        read(l, r);
        ft1.update(l, r, 1);
    }

    For (i, 0, m - 1) {
        c = ft1.query(i + 1);
        tie(l, r, d) = ms[i];

        ft2.update(l, r, d * c);
    }

    for (int i = 0; i < n; i++) {
        c = ft2.query(i + 1);
        cout << a[i] + c << " ";
    }
}
