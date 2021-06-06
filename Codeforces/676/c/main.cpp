#include <bits/stdc++.h>
using namespace std;

#define fast_io        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define For(i, a, b)   for (int i = int(a); i <= int(b); i++)
#define Fod(i, a, b)   for (int i = int(a); i >= int(b); i--)
#define sz(x)          ((int) x.size())
#define ALL(x)         (x).begin(), (x).end()
#define F              first
#define S              second
#define eb             emplace_back
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

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
template<typename T> void dbg_out(vector<T> v) { for (auto c : v) cerr << ' ' << c; cout << endl; };
template<typename T> void dbg_out(T v[]) { for (auto c : v) cerr << ' ' << c; };
template<typename T> void dbg_out(vector<T> v, int n) { For (i, 0, n - 1) cerr << ' ' << v[i]; };
template<typename T> void dbg_out(T v[], int n) { For (i, 0, n - 1) cerr << ' ' << v[i]; };

#if defined(_CRUN) || defined(_RUN)
#define dbg(...) cerr << "(L:" << __LINE__ << "): " << "[" << # __VA_ARGS__ << "] =", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

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

    //#ifdef _CRUN 
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    //#endif

    int t = 1; 
    //cin >> t; 
    while (t--) solve();
}

int n, k;
string s;

int compute(vector<int> a) {
    int m = 0;
    for (int i = 0, j = k - 1; j < sz(a); ++i, ++j) {
        m = max(m, a[j] - a[i] + 1 + (i ? a[i] - a[i-1] - 1 : a[i]) + (j < sz(a) - 1 ? a[j+1] - a[j] - 1 : n - a[j] - 1));
    }

    return m;
}

void solve() {
    read(n, k);
    read(s);

    vector<int> a, b;

    For (i, 0, n - 1) {
        if (s[i] == 'a')
            a.eb(i);
        else
            b.eb(i);
    }

    if (sz(a) <= k || sz(b) <= k)
        cout << n << endl;
    else {
        int m = compute(a);
        int n = compute(b);

        cout << max(m, n) << endl;
    }
}
