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

// Debug
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#if defined(_CRUN) || defined(_RUN)
#define dbg(...) cerr << "(L:" << __LINE__ << "): " << "[" << #__VA_ARGS__ << "] =", dbg_out(__VA_ARGS__)
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

    #ifdef _CRUN 
        //freopen("input", "r", stdin);
    #endif

    int t = 1; 
    cin >> t; 
    while (t--) solve();
}

void solve() {
    string s;
    int x;
    read(s, x);

    int n = sz(s);
    string w (n, '?');

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (i - x >= 0) w[i - x] = '0';
            if (i + x < n) w[i+x] = '0';
        } else {
            if (i - x >= 0 && w[i - x] == '?')
                w[i - x] = '1';
            if (i + x < n && w[i + x] == '?')
                w[i + x] = '1';
        }
    }

    for (int i = 0; i < n; ++i) {
        if (w[i] == '?') {
            if ((i - x >= 0 && s[i - x] == '1') || (i + x < n && s[i + x] == '1')) {
                w[i] = '1';
            } else {
                w[i] = '0';
            }
        }
    }
 
    // check
    bool ok = true;
 
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if ((i - x >= 0 && w[i - x] == '1') || (i + x < n && w[i + x] == '1')) {
                ok = false;
                break;
            }
        } else {
            if ((i - x >= 0 && w[i - x] != '0') || (i + x < n && w[i + x] != '0')) {
            } else {
                ok = false;
                break;
            }
        }
    }
 
    dbg(w);

    //if (ok)
        //cout << w << endl;
    //else
        //cout << -1 << endl;
}
