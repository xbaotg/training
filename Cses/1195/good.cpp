//{{

/*
 * Created at: 07/16/21 21:48:41
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
#define c_output() freopen("output", "r", stdin)
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
void init() {}

int n, m;
vector<vector<int>> G, R, W;
vector<tuple<int, int, int>> E;

void dijkstra(int u, vector<vector<int>>& G, vector<llong> &dis) {
  priority_queue<pair<llong, int>> pq;

  dis[u] = 0;
  pq.push({ 0, u });

  while (!pq.empty()) {
    auto t = pq.top(); pq.pop();
    auto d = t.F;
    auto v = t.S;

    if (d > dis[v]) continue;

    for (auto &vv : G[v]) {
      if (dis[v] + W[v][vv] < dis[vv]) {
        dis[vv] = dis[v] + W[v][vv];
        pq.push({ dis[vv], vv });
      }
    }
  }
}

void solve() {
  read(n, m);
  
  G.resize(n + 1);
  R.resize(n + 1);
  W.assign(n + 1, vector<int> (n + 1, INF));

  for (int i = 0; i < m; ++i) {
    int u, v, w; read(u, v, w);
    G[u].push_back(v);
    R[v].push_back(u);
    W[u][v] = W[v][u] = min(W[u][v], w);
    E.push_back({ u, v, w });
  }

  vector<llong> dis (n + 1, LLONG_MAX), disR (n + 1, LLONG_MAX);

  dijkstra(1, G, dis);
  dijkstra(n, R, disR);

  llong ans = LLONG_MAX;
  for (auto &p : E) {
    int u, v, w; tie(u, v, w) = p;

    auto f = dis[u];
    auto s = disR[v];

    if (f == LLONG_MAX || s == LLONG_MAX) 
      continue;

    ans = min(ans, w / 2 + f + s);
  }

  ps(ans);
}
