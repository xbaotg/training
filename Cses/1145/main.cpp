//{{

/*
 * Created at: 07/11/21 20:53:25
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

int n;
vector<int> a;

void compress() {
  vector<pair<int, int>> b;

  for (int i = 0; i < n; ++i) {
    b.push_back( { a[i], i } );
  }

  sort(all(b));
  int cur = 1;

  for (int i = 0; i < n; ++i) {
    if (i && b[i].first != b[i-1].first)
      ++cur;

    a[b[i].second] = cur;
  }
}

struct ST {
  vector<int> st;

  void init(int n) {
    st.resize(n << 2);
  }

  void update(int no, int l, int r, int i, int v) {
    if (l == r) {
      st[i] = v;
      return;
    }

    int m = l + r >> 1;
    if (i <= m) 
      update(no << 1, l, m, i, v);
    else 
      update(no << 1 | 1, m + 1, r, i, v);

    st[no] = max(st[no << 1], st[no << 1 | 1]);
  }

  int query(int no, int l, int r, int u, int v) {
    if (u <= l && r <= v) return st[no];
    if (l > v || r < u) return 0;

    int m = l + r >> 1;
    return max(query(no << 1, l, m, u, v), query(no << 1 | 1, m + 1, r, u, v));
  }
};

void solve() {
  read(n); 

  a.resize(n);
  read(a, n);

  compress();

  ST st;
  st.init(n);

  int ans = 0;
  for (auto &v : a) {
    auto b = st.query(1, 1, n, 0, v - 1);
    st.update(1, 1, n, v, b + 1);
    ans = max(ans, b + 1);
  } 

  ps(ans);
}
