//{{
/*
 * Created at: 07/06/21 13:44:39
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

int n, m;
vector<int> G[100001]; 
bool vs[100001];
int trace[100001];
 
void dfs2(int u, int to, int depth = 0) {
  vs[u] = true;

  for (auto &v : G[u]) {
    if (vs[v]) continue;
    if (v == to) {
      if (depth == 0) {
        continue;
      }

      int cur = v;
      vector<int> ans;
      while (~cur) {
        ans.push_back(cur);
        cur = trace[cur];
      }
      ans.push_back(v);

      ps(sz(ans), nl);
      ps(ans, sz(ans));

      exit(0);
    } else {
      trace[v] = u;
      dfs2(v, to, depth + 1);
    }
  }
}
 
void dfs(int u, int p) {
  vs[u] = true;
  
  for (auto &v : G[u]) {
    if (v == p)
      continue;
 
    if (!vs[v]) {
      trace[v] = u;
      dfs(v, u);
    } else {
      memset(vs, 0, sizeof vs);
      trace[u] = -1;

      dfs2(u, v, 0);
      exit(0);
    }
  }
}
 
void solve() {
  read(n, m);
  for (int i = 0; i < m; ++i) {
    int u, v; read(u, v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
 
  memset(vs, 0, sizeof vs);
  trace[1] = -1;
  dfs(1, 0);
}
