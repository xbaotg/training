//{{
 
/*
 * Created at: 07/12/21 18:21:02
 * Problem: $LINK
 *
 * FB: https://facebook.com/tgbaodeeptry
 *
 * From Viet Nam with Love :D
 */
 
#include <bits/stdc++.h>
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define nl '\n'
 
using llong = long long;
 
int MOD = 1e9 + 7;
int INF = INT_MAX;
double ESP = 1e-9;
 
template <class T> void read(T& x) { cin >> x; };
template <class T> void read(vector<T>& v, int n) { for (int i = 0; i < n; ++i) cin >> v[i]; };
template <class T> void read(vector<T>& v, int f, int t) { for (int i = f; i <= t; ++i) cin >> v[i]; };
template <class T> void read(T v[], int n) { for (int i = 0; i < n; ++i) cin >> v[i]; };
template <class T> void read(T* v, int f, int t) { for (int i = f; i <= t; ++i) cin >> v[i]; };
template <class H, class... T> void read(H& v, T&... args) { read(v); read(args...); };
void dbg_out() { cerr << nl; } 
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
template <typename T> void dbg_out(vector<T>& a) { for (auto c : a) cerr << ' ' << c; cerr << nl; };
template <typename T> void dbg_out(vector<T>& a, int n) { for (int i = 0; i < n; ++i) cerr << ' ' << a[i]; cerr << nl; };
template <typename T> void dbg_out(vector<T>& a, int u, int v) { for (int i = u; i <= v; ++i) cerr << ' ' << a[i]; cerr << nl; };
template <typename T> void dbg_out(vector<vector<T>>& a) { cerr << nl; for (auto &v : a) { cerr << "| "; for (auto &vv : v) cerr << vv << " "; cerr << "|" << nl; } };
template <typename T> void dbg_out(T a[], int n) { for (int i = 0; i < n; ++i) cerr << ' ' << a[i]; cerr << nl; };
template <typename T> void dbg_out(T a[], int u, int v) { for (int i = u; i <= v; ++i) cerr << ' ' << a[i]; cerr << nl; };
template <typename T> void dbg_out(set<T>& a) { for (auto c : a) cerr << ' ' << c; cerr << nl; };
template <typename Y, typename Z> void dbg_out(pair<Y, Z> p) { cerr << p.first << " " << p.second; cerr << nl; }
#if defined(_CRUN) || defined(_RUN)
#define pd(...) cerr << "\033[0;31m[" << #__VA_ARGS__ << "]\033[0m =", dbg_out(__VA_ARGS__)
#else
#define pd(...)
#endif
#if defined(_CRUN)
#define c_input() freopen("input", "r", stdin)
#define c_output() freopen("output", "r", stdin)
#else
#define c_input()
#define c_output()
#endif
void ps(){};
template <typename Head, typename... Tail> void ps(Head H, Tail... T) { cout << H; ps(T...); };
template <typename T> void ps(vector<T>& a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; };
template <typename T> void ps(T a[], int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; };
template <typename Y, typename Z> void ps(pair<Y, Z> p) { cout << p.first << " " << p.second; }
 
int add_mod(int a, int b) { if (a >= MOD) a %= MOD; if (b >= MOD) b %= MOD; return (a + b) % MOD; }
int sub_mod(int a, int b) { if (a >= MOD) a %= MOD; if (b >= MOD) b %= MOD; return (a - b + MOD) % MOD; }
int mul_mod(int a, int b) { if (a >= MOD) a %= MOD; if (b >= MOD) b %= MOD; return (llong(a) * b) % MOD; }
llong cpow_mod(llong a, llong b) { llong ans = 1; while (b) { if (b & 1) ans = mul_mod(ans, a); a = mul_mod(a, a); b >>= 1; }; return ans; };
llong lcm(llong a, llong b) { return a * b / __gcd(a, b); }
llong cpow(llong a, llong b) { llong ans = 1; while (b) { if (b & 1) ans *= a; a *= a; b >>= 1; }; return ans; };
 
void solve();
void init();
bool TESTS = false;
 
int main() {
  fast_io();
  init();
 
  int T = 1;
  if (TESTS) read(T);
 
  for (int i = 1; i <= T; ++i) solve();
}
//}}
void init() {}
 
void solve() {
  int n, q; read(n, q);
  vector<string> a (n + 1, string(n + 1, ' '));
 
  for (int i = 1; i <= n; ++i) {
    for (int k = 1; k <= n; ++k) {
      read(a[i][k]);
    }
  }
 
  vector<vector<int>> dp (n + 1, vector<int> (n + 1));
 
  for (int i = 1; i <= n; ++i) {
    for (int k = 1; k <= n; ++k) {
      dp[i][k] = dp[i-1][k] + dp[i][k-1] - dp[i-1][k-1] + (a[i][k] == '*');
    }
  }
 
  while (q--) {
    int y1, x1, y2, x2; read(y1, x1, y2, x2);
 
    ps(dp[y2][x2] - dp[y1-1][x2] - dp[y2][x1-1] + dp[y1-1][x1-1], nl);
  }
}
