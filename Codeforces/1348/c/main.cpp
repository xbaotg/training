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

#ifdef _CRUN 
    //freopen("input", "r", stdin);
#endif

    int t = 1; 
    cin >> t; 
    while (t--) solve();
}

int n, k;
int m[26];
string s;

void solve() {
    read(n, k, s);
    memset(m, 0, sizeof m);

    char f = 'z';
    int c = 0;

    for (auto v : s) ++m[v - 'a'], f = min(f, v);
    for (auto v : m) c += v > 0;

    sort(ALL(s));

    if (m[f-'a'] < k) {
        cout << string(1, s[k-1]);
    } else {
        if (c == 1 || (m[f-'a'] - k == 0 && c == 2)) {
            m[f - 'a'] -= k;
            int ch = f - 'a';

            if (m[f-'a'] == 0) {
                For (i, f - 'a' + 1, 25) 
                    if (m[i]) { 
                        ch = i;
                        break;
                    }
            }

            cout << string(1, f);
            For (i, 1, ceil(1.0 * m[ch] / k))
                cout << string(1, ch + 'a');
        } else {
            m[f - 'a'] -= k;
            
            cout << string(1, f);
            for (int i = 0; i < 26; ++i)
                while (m[i]--)
                    cout << string(1, 'a' + i);
        }
    }

    cout << endl;
}
