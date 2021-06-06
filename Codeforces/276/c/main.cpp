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
    int* bit;
    int n;
    
    Fenwick (int n) {
        this->n = n;
        this->bit = new int[n+1];

        fill(bit, bit + n + 1, 0);
    }

    void update(int idx, int v) {
        for (; idx <= n; bit[idx] += v, idx += (idx & -idx));
    }

    void update(int l, int r, int v) {
        update(l, v);
        update(r + 1, -v);
    }

    int get(int idx) {
        int ans = 0;
        for (; idx; ans += bit[idx], idx -= (idx & -idx));
        return ans;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

void solve() {
    int n, q, l, r;
    read(n, q);

    int a[n];
    read(a, n);

    vector<pair<int, int>> queries;
    
    Fenwick ft1 (n);

    while (q--) {
        read(l, r);
        queries.ep(l, r);
        ft1.update(l, r, 1);
    }

    vector<pair<int, int>> v;
    For (i, 0, n - 1) {
        v.ep(ft1.get(i + 1), i);
    }

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.F > b.F;
        });

    sort(a, a + n, greater<int>());

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += ((ll) v[i].F )* a[i];
    }
    
    cout << ans << endl;
}
