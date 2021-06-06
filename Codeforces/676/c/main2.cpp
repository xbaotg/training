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
template<typename T> void dbg_out(vector<T> a) { for (auto c : a) cerr << ' ' << c; cerr << endl; };
template<typename T> void dbg_out(T a[]) { for (auto c : a) cerr << ' ' << c; cerr << endl; };
template<typename T> void dbg_out(vector<T> a, int n) { For (i, 0, n - 1) cerr << ' ' << a[i]; cerr << endl; };
template<typename T> void dbg_out(T a[], int n) { For (i, 0, n - 1) cerr << ' ' << a[i]; cerr << endl; };
template<typename T> void dbg_out(vector<T> a, int u, int v) { For (i, u, v) cerr << ' ' << a[i]; cerr << endl; };
template<typename T> void dbg_out(T a[], int u, int v) { For (i, u, v) cerr << ' ' << a[i]; cerr << endl; };

#if defined(_CRUN) || defined(_RUN)
#define dbg(...) cerr << "(L:" << __LINE__ << "): " << "[" << #__VA_ARGS__ << "] =", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

ll add_mod(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll sub_mod(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
ll mul_mod(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }

void solve();

//-----------------------------------------------//
//                                               //
// FB: https://facebook.com/tgbaodeeptry         //
//                                               //
// From Viet Nam with Love :D                    //
//                                               //  
//-----------------------------------------------//

int main() {
    fast_io;

    //#ifdef _CRUN 
        freopen("input", "r", stdin);
        freopen("output2", "w", stdout);
    //#endif

    int t = 1; 
    //cin >> t; 
    while (t--) solve();

    fclose(stdout);
}

int n, k;
string s;

// doi a thanh b
int compute(char a, char b) {
    int l = 0, r = 0, c = s[0] == a, m = 0;

    while (r < n) {
        // lon hon
        if (c > k) {
            c -= s[l++] == a;
        } else {
            m = max(m, r - l + 1);
            
            if (r < n - 1)
                c += s[++r] == a;
            else
                break;
        }

        if (l > r) {
            r = l;
            if (l < n)
                c = s[l] == a;
        }
    }

    if (c <= k)
        m = max(m, r - l + 1);

    return m;
}

void solve() {
    read(n, k, s);

    cout << max(compute('a', 'b'), compute('b', 'a')) << endl;
}
