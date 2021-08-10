// template {{{

/*
 * Created at: 08/01/21 21:08:23
 * Problem: $LINK
 *
 * FB: https://facebook.com/tgbaodeeptry
 * From Viet Nam with Love :D
 */

#include "bits/stdc++.h"
#include <vector>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define nl '\n'

using llong = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<llong>;
using pii = pair<int, int>;

int MOD = 1e9 + 7;
int INF = INT_MAX;
llong LINF = LLONG_MAX;
double ESP = 1e-9;

void dbg_out() { cerr << nl; };
void psout() {};
template < typename T > void read(T & x) { cin >> x; };
template < typename T > void read(vector <T > & v, int n) { for (int i = 0; i < n; ++i) cin >> v[i]; };
template < typename T > void read(vector < T > & v, int f, int t) { for (int i = f; i <= t; ++i) cin >> v[i]; };
template < typename T > void read(T v[], int n) { for (int i = 0; i < n; ++i) cin >> v[i]; };
template < typename T > void read(T * v, int f, int t) { for (int i = f; i <= t; ++i) cin >> v[i]; };
template < typename H, typename...T > void read(H & v, T & ...args) { read(v); read(args...); };
template < typename Head, typename...Tail > void dbg_out(Head H, Tail...T) { cerr << ' ' << H; dbg_out(T...); }
template < typename T > void dbg_out(vector < T > & a) { for (auto & c: a) cerr << ' ' << c; cerr << nl; };
template < typename T > void dbg_out(vector < T > & a, int n) { for (int i = 0; i < n; ++i) cerr << ' ' << a[i]; cerr << nl; };
template < typename T > void dbg_out(vector < T > & a, int u, int v) { for (int i = u; i <= v; ++i) cerr << ' ' << a[i]; cerr << nl; };
template < typename T > void dbg_out(vector < vector < T >> & a) { cerr << nl; for (auto & v: a) { cerr << "| "; for (auto & vv: v) cerr << vv << " "; cerr << "|" << nl; } };
template < typename T > void dbg_out(T a[], int n) { for (int i = 0; i < n; ++i) cerr << ' ' << a[i]; cerr << nl; };
template < typename T > void dbg_out(T a[], int u, int v) { for (int i = u; i <= v; ++i) cerr << ' ' << a[i]; cerr << nl; };
template < typename T > void dbg_out(set < T > & a) { for (auto c: a) cerr << ' ' << c; cerr << nl; };
template < typename Y, typename Z > void dbg_out(pair < Y, Z > p) { cerr << p.first << " " << p.second; cerr << nl; }
template < typename Head, typename...Tail > void psout(Head H, Tail...T) { cout << H; psout(T...); };
template < typename T > void psout(vector < T > & a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; };
template < typename T > void psout(vector < T > & a) { for (auto & c: a) cout << c << ' '; cout << nl; };
template < typename T > void psout(vector < T > & a, int u, int v) { for (int i = u; i <= v; ++i) cout << a[i] << ' '; cout << nl; };
template < typename T > void psout(vector < vector < T >> & a) { cout << nl; for (auto & v: a) { for (auto & vv: v) cout << vv << " "; cout << nl; } };
template < typename T > void psout(T a[], int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; };
template < typename T > void psout(T a[], int u, int v) { for (int i = u; i <= v; ++i) cout << a[i] << ' '; cout << nl; };
template < typename T > void psout(set < T > & a) { for (auto c: a) cout << c << ' '; cout << nl; };
template < typename Y, typename Z > void psout(pair < Y, Z > p) { cout << p.first << " " << p.second; }; 
#define ps(...) psout(__VA_ARGS__)

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

void solve();
void init();
bool TESTS = false;

int main() { fast_io(); init(); int T = 1; if (TESTS) read(T); for (int i = 1; i <= T; ++i) solve(); }
// }}}
void init() {}

struct Edge {
  int u, v, w;
};

int n, m;
vector<Edge> eds;
vector<vector<pair<int, int>>> G;

void dijkstra(vector<llong>& dis, int u) {
  dis[u] = 0;
  priority_queue<pair<llong, int>, vector<pair<llong, int>>, greater<pair<llong, int>>> pq;

  pq.push({ 0, u });
  while (!pq.empty()) {
    auto cd = pq.top().F; 
    auto cu = pq.top().S; 
    pq.pop();
    
    if (cd > dis[cu]) {
      continue;
    }

    for (auto &p : G[cu]) {
      auto v = p.F, d = p.S;

      if (dis[v] > dis[cu] + d) {
        dis[v] = dis[cu] + d;
        pq.push({ dis[v], v });
      }
    }
  }
}

void solve() {
  read(n, m);

  G.resize(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v, w; read(u, v, w);
    eds.push_back({ u, v, w });
    eds.push_back({ v, u, w });
    G[u].push_back({ v, w });
    G[v].push_back({ u, w });
  }

  vector<llong> xuoi (n + 1, LINF), nguoc (n + 1, LINF);
  dijkstra(xuoi, 1);
  dijkstra(nguoc, n);

  auto ans = LINF;

  for (auto &e : eds) {
    auto f = xuoi[e.u];
    auto s = nguoc[e.v];
    
    if (f != LINF && s != LINF) {
      ans = min(ans, f + s + e.w / 2);
    }
  }

  ps(ans);
}
