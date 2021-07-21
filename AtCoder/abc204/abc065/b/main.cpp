//{{
/*
 * Created at: 06/21/21 22:38:05
 *
 * FB: https://facebook.com/tgbaodeeptry
 * From Viet Nam with Love :D
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define REP(i, a, b) for (int i = int(a); i < int(b); ++i)
#define RED(i, a, b) for (int i = int(a); i > int(b); --i)
#define FOR(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define FOD(i, a, b) for (int i = int(a); i >= int(b); --i)
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define eb emplace_back
#define pb push_back
#define endl '\n'

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const int MAXN = 1e5;
const int INF = INT_MAX;

template <class T> void re(T &x) { cin >> x; };
template <class T> void re(vector<T> &v, int n) {
  FOR(i, 0, n - 1) cin >> v[i];
};
template <class T> void re(vector<T> &v, int f, int t) {
  FOR(i, f, t) cin >> v[i];
};
template <class T> void re(T v[], int n) { FOR(i, 0, n - 1) cin >> v[i]; };
template <class T> void re(T *v, int f, int t) { FOR(i, f, t) cin >> v[i]; };
template <class H, class... T> void re(H &v, T &... args) {
  re(v);
  re(args...);
};

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
template <typename T> void dbg_out(vector<T> a) {
  for (auto c : a) cerr << ' ' << c;
  cerr << endl;
};
template <typename T> void dbg_out(vector<T> a, int n) {
  FOR(i, 0, n - 1) cerr << ' ' << a[i];
  cerr << endl;
};
template <typename T> void dbg_out(vector<T> a, int u, int v) {
  FOR(i, u, v) cerr << ' ' << a[i];
  cerr << endl;
};
template <typename T> void dbg_out(T a[]) {
  for (auto c : a) cerr << ' ' << c;
  cerr << endl;
};
template <typename T> void dbg_out(T a[], int n) {
  FOR(i, 0, n - 1) cerr << ' ' << a[i];
  cerr << endl;
};
template <typename T> void dbg_out(T a[], int u, int v) {
  FOR(i, u, v) cerr << ' ' << a[i];
  cerr << endl;
};

#if defined(_CRUN) || defined(_RUN)
#define pd(...)                         \
  cerr << "(L:" << __LINE__ << "): "    \
       << "[" << #__VA_ARGS__ << "] =", \
      dbg_out(__VA_ARGS__)
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
template <typename Head, typename... Tail> void ps(Head H, Tail... T) {
  cout << H;
  ps(T...);
};
template <typename T> void ps(vector<T> a, int n) {
  FOR(i, 0, n - 1) cout << a[i] << ' ';
};
template <typename T> void ps(T a[], int n) {
  FOR(i, 0, n - 1) cout << a[i] << ' ';
};

ll add_mod(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll sub_mod(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
ll mul_mod(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll pow_mod(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans = mul_mod(ans, a);
    a = mul_mod(a, a);
    b >>= 1;
  };
  return ans;
};

ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }
ll pow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b >>= 1;
  };
  return ans;
};

void solve();
void init();
bool multi_test = false;
// ---- main below ----- ///

int main() {
  fast_io();
  init();

  int T = 1;
  if (multi_test) re(T);

  FOR(i, 1, T) solve();
}
//}}

void init() {
  // multi_test = true;
}

void solve() {
  int n;
  re(n);
  int a[n+1];
  re(a, 1, n);

  int cur = 1;
  int ret = 0;
  int vs[MAXN + 1] = {true};

  while (cur != 2) {
    vs[cur] = true;
    
    if (vs[a[cur]]) {
      return ps(-1);
    }

    ++ret, cur = a[cur];
  }

  ps(ret);
}
