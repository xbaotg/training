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

int n, d, m, s;

void solve() {
    read(n, d);

    pair<int, int> p[n];
    int factor[n], factor_n[n];
    ll sum[n];
    vector<pair<int, int>> ans;

    For (i, 0, n - 1) {
        read(m, s);

        p[i].F = m;
        p[i].S = i;
        factor[i] = s;
    }

    sort(p, p + n, [](pair<int, int> a, pair<int, int> b) { return a.F < b.F; });

    For (i, 0, n - 1) {
        factor_n[i] = factor[p[i].S];
        
        if (i) 
            sum[i] = sum[i-1] + (ll) factor_n[i];
        else
            sum[i] = factor_n[i];
    }
    
    // 0 75 75 100

    For (i, 0, n - 1) {
        auto next = lower_bound(p + i + 1, p + n, make_pair(p[i].F + d, INT_MIN));
        int j;

        if (next == (p + n))
            j = n - 1;
        else
            j = distance(p + i, next) + i - 1;

        ans.ep(i, j);
    }

    ll ma = 0;
    for (auto p : ans) {
        if (p.F)
            ma = max(ma, sum[p.S] - sum[p.F - 1]);
        else
            ma = max(ma, sum[p.S]);
    }

    cout << ma;
}
