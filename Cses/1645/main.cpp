// template {{{

/*
 * Created at: 07/31/21 21:37:17
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

struct ST {
  vector<int> st;

  void init(int n) {
    st.resize(n << 2);
  }

  void update(int no, int l, int r, int i, int v) {
    if (i < l || i > r) 
      return;

    if (l == r) {
      st[no] = v;
      return;
    }

    int m = (l + r) >> 1;
    update(no << 1, l, m, i, v); 
    update(no << 1 | 1, m + 1, r, i, v); 

    st[no] = max(st[no << 1], st[no << 1 | 1]);
  }

  int get(int no, int l, int r, int u, int v) {
    if (u <= l && r <= v) {
      return st[no];
    }

    if (l > v || r < u) {
      return 0;
    }

    int m = (l + r) >> 1;
    return max(get(no << 1, l, m, u, v), get(no << 1 | 1, m + 1, r, u, v));
  }
};

void solve() {
  int n; read(n);
  vector<int> a(n); read(a, n);

  // compress
  vector<pair<int, int>> t;
  for (int i = 0; i < n; ++i) {
    t.emplace_back(a[i], i);
  }
  sort(all(t));

  int cur = 0, l = -1;
  for (auto &p : t) {
    if (p.F != l) {
      a[p.S] = ++cur;
      l = p.F;
    }
  }

  pd(a);

  // core
  ST st;
  st.init(cur);

  for (int i = 0; i < n; ++i) {
    st.update(1, 1, cur, a[i], i + 1);
  }

  for (auto &v : a) {
    ps(st.get(1, 1, cur, 1, v - 1), " ");
  }
}
