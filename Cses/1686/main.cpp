//{{
/*
 * Created at: 07/09/21 12:44:03
 *
 * FB: https://facebook.com/tgbaodeeptry
 * From Viet Nam with Love :D
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define nl '\n'

using int64 = long long;

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
template <typename T> void dbg_out(T a[], int n) { for (int i = 0; i < n; ++i) cerr << ' ' << a[i]; cerr << nl; };
template <typename T> void dbg_out(T a[], int u, int v) { for (int i = u; i <= v; ++i) cerr << ' ' << a[i]; cerr << nl; };
template <typename Y, typename Z> void dbg_out(pair<Y, Z> p) { cerr << p.first << " " << p.second; cerr << nl; }
#if defined(_CRUN) || defined(_RUN)
#define pd(...) cerr << "(L:" << __LINE__ << "): " << "[" << #__VA_ARGS__ << "] =", dbg_out(__VA_ARGS__)
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
int mul_mod(int a, int b) { if (a >= MOD) a %= MOD; if (b >= MOD) b %= MOD; return (int64(a) * b) % MOD; }
int64 cpow_mod(int64 a, int64 b) { int64 ans = 1; while (b) { if (b & 1) ans = mul_mod(ans, a); a = mul_mod(a, a); b >>= 1; }; return ans; };
int64 lcm(int64 a, int64 b) { return a * b / __gcd(a, b); }
int64 cpow(int64 a, int64 b) { int64 ans = 1; while (b) { if (b & 1) ans *= a; a *= a; b >>= 1; }; return ans; };

void solve();
void init();
bool TESTS = false;
// ---- main below ----- ///

int main() {
  fast_io();
  init();

  int T = 1;
  if (TESTS) read(T);

  for (int i = 1; i <= T; ++i) solve();
}
//}}

void init() {
  // TESTS = true;
  // MOD = 998244353;
}

int n, m, k[100001], cscc = 0;
vector<vector<int>> G, R;
vector<int> root;
vector<int64> sum, dp;
vector<set<int>> CSCC;

struct SCC {
  vector<int> used, del, comp;
  stack<int> order;

  SCC() {
    used.resize(n + 1);
    del.resize(n + 1);
    root.resize(n + 1);
    sum.resize(n + 1);
  }

  void dfs1(int u) {
    used[u] = true;
    for (auto &v : G[u]) {
      if (!used[v]) {
        dfs1(v);
      }
    }
    order.push(u);
  }

  void dfs2(int u) {
    del[u] = true;
    comp.push_back(u);

    for (auto &v : R[u]) {
      if (!del[v]) {
        dfs2(v);
      }
    }
  } 
  
  void init() {
    for (int i = 1; i <= n; ++i) {
      if (!used[i]) {
        dfs1(i);
      }
    }

    while (!order.empty()) {
      auto t = order.top(); order.pop();
      if (!del[t]) {
        dfs2(t);

        ++cscc;
        for (auto &v : comp) {
          root[v] = cscc;
          sum[cscc] += k[v];
        }

        comp.clear();
      }
    }

    for (int u = 1; u <= n; ++u) {
      for (auto &v : G[u]) {
        if (root[u] != root[v]) {
          CSCC[root[u]].insert(root[v]);
        }
      } 
    }
  }
};

int64 trace(int u) {
  if (~dp[u]) return dp[u];

  auto cur = sum[u];
  for (auto &v : CSCC[u]) {
    cur = max(cur, sum[u] + trace(v));
  } 

  return dp[u] = cur;
}

void solve() {
  read(n, m);
  read(k, 1, n);

  G.resize(n + 1);
  R.resize(n + 1);

  for (int i = 0; i < m; ++i) {
    int u, v; read(u, v);
    G[u].push_back(v);
    R[v].push_back(u);
  }

  SCC scc;
  scc.init();

  dp.assign(cscc + 1, -1);
  int64 ans = 0;

  for (int i = 1; i <= cscc; ++i) {
    ans = max(ans, trace(i));
  }

  ps(ans);
}
