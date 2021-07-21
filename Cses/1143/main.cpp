//{{

/*
 * Created at: 07/13/21 18:12:59
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

#define f(i, a) for (int i = 0; i < int(a); ++i)
#define fr(i, a, b) for (int i = int(a); i < int(b); ++i)
#define tr(v, s) for (auto &v : s)

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
void init() {
  //c_input();
}

struct ST {
  vector<int> st;

  void init(int n) {
    st.resize((n << 2) + 1);
  }

  void update(int no, int l, int r, int u, int v) {
    if (u > r || u < l) 
      return;

    if (l == r) {
      st[no] = v;
      return;
    }

    int m = (l + r) >> 1;
    update(no << 1, l, m, u, v);
    update(no << 1 | 1, m + 1, r, u, v);

    st[no] = max(st[no << 1], st[no << 1 | 1]);
  }

  int get(int no, int l, int r, int u, int v) {
    if (u <= l && r <= v) {
      return st[no];
    }

    if (r < u || l > v) {
      return 0;
    }

    int m = (l + r) >> 1;
    return max(get(no << 1, l, m, u, v), get(no << 1 | 1, m + 1, r, u, v));
  }
};

int n, q;
int a[200001];

void solve() {
  read(n, q);

  ST st;
  st.init(n);

  for (int i = 1; i <= n; ++i) {
    read(a[i]);
    st.update(1, 1, n, i, a[i]);
  }


  for (int v; q; --q) {
    read(v);

    int l = 1, r = n, ok = false;
    while (l < r) {
      int m = (l + r) >> 1;

      if (st.get(1, 1, n, l, m) >= v) {
        ok = true;
        r = m;
      } else {
        l = m + 1;
      }
    }

    if (a[l] >= v || ok){
      ps(l);

      a[l] -= v;
      st.update(1, 1, n, l, a[l]);
    } else {
      ps(0);
    }
    ps(" ");
  }
}
