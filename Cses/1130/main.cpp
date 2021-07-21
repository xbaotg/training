//{{

/*
 * Created at: 07/15/21 10:11:47
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
template <typename T> void dbg_out(vector<T>& a) { for (auto &c : a) cerr << ' ' << c; cerr << nl; };
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
#define c_output() freopen("output", "w", stdin)
#define ps(...) cout << "\033[0;33m"; psout(__VA_ARGS__)
#define endps() cout << "\033[0m" << endl;
#else
#define c_input()
#define c_output()
#define ps(...) psout(__VA_ARGS__)
#define endps()
#endif

void psout(){};
template <typename Head, typename... Tail> void psout(Head H, Tail... T) { cout << H; psout(T...); };
template <typename T> void psout(vector<T>& a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; };
template <typename T> void psout(vector<T>& a) { for (auto &c : a) cout << ' ' << c; cout << nl; };
template <typename T> void psout(vector<T>& a, int u, int v) { for (int i = u; i <= v; ++i) cout << ' ' << a[i]; cout << nl; };
template <typename T> void psout(vector<vector<T>>& a) { cout << nl; for (auto &v : a) { for (auto &vv : v) cout << vv << " "; cout << nl; } };
template <typename T> void psout(T a[], int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; };
template <typename T> void psout(T a[], int u, int v) { for (int i = u; i <= v; ++i) cout << ' ' << a[i]; cout << nl; };
template <typename T> void psout(set<T>& a) { for (auto c : a) cout << ' ' << c; cout << nl; };
template <typename Y, typename Z> void psout(pair<Y, Z> p) { cout << p.first << " " << p.second; }

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

  endps();
}
//}}
void init() {
  //c_input();
}

int n;
vector<vector<int>> dp;
vector<vector<int>> G;

int DP(int u, int p, int t) {
  if (~dp[u][t]) {
    return dp[u][t];
  }

  int ret = 0;

  if (t == 0) {
    for (auto &v : G[u]) {
      if (v != p) {
        ret += max(DP(v, u, 0), DP(v, u, 1));
      }
    }
  }

  if (t == 1) {
    int pre = 0, suf = 0;

    for (auto &v : G[u]) {
      if (p != v) {
        suf += max(DP(v, u, 0), DP(v, u, 1));
      }
    }

    for (auto &v : G[u]) {
      if (p != v) {
        suf -= max(DP(v, u, 0), DP(v, u, 1));
        ret = max(ret, DP(v, u, 0) + pre + suf);
        pre += max(DP(v, u, 0), DP(v, u, 1));
      }
    }

    ret += (sz(G[u]) > (p != 0));
  }

  return dp[u][t] = ret;
}

void solve() {
  read(n);

  G.resize(n + 1);
  dp.assign(n + 1, vector<int> (2, -1));

  for (int i = 0; i < n - 1; ++i) {
    int u, v; read(u, v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  ps(max(DP(1, 0, 0), DP(1, 0, 1)));
}
