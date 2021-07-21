//{{
/*
 * Created at: 07/04/21 13:22:22
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

using int64 = long long;

int MOD = 1e9 + 7;
int MAXN = 1e5;
int INF = INT_MAX;
double ESP = 1e-9;

template <class T>
void read(T& x) {
  cin >> x;
};

template <class T>
void read(vector<T>& v, int n) {
  for (int i = 0; i < n; ++i)
    cin >> v[i];
};

template <class T>
void read(vector<T>& v, int f, int t) {
  FOR(i, f, t) cin >> v[i];
};

template <class T>
void read(T v[], int n) {
  FOR(i, 0, n - 1) cin >> v[i];
};

template <class T>
void read(T* v, int f, int t) {
  FOR(i, f, t) cin >> v[i];
};

template <class H, class... T>
void read(H& v, T&... args) {
  read(v);
  read(args...);
};

void dbg_out() {
  cerr << endl;
}

template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

template <typename T>
void dbg_out(vector<T>& a) {
  for (auto c : a)
    cerr << ' ' << c;
  cerr << endl;
};

template <typename T>
void dbg_out(vector<T>& a, int n) {
  FOR(i, 0, n - 1) cerr << ' ' << a[i];
  cerr << endl;
};

template <typename T>
void dbg_out(vector<T>& a, int u, int v) {
  FOR(i, u, v) cerr << ' ' << a[i];
  cerr << endl;
};

template <typename T>
void dbg_out(T a[]) {
  for (auto c : a)
    cerr << ' ' << c;
  cerr << endl;
};

template <typename T>
void dbg_out(T a[], int n) {
  FOR(i, 0, n - 1) cerr << ' ' << a[i];
  cerr << endl;
};

template <typename T>
void dbg_out(T a[], int u, int v) {
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

template <typename Head, typename... Tail>
void ps(Head H, Tail... T) {
  cout << H;
  ps(T...);
};

template <typename T>
void ps(vector<T>& a, int n) {
  FOR(i, 0, n - 1) cout << a[i] << ' ';
};

template <typename T>
void ps(T a[], int n) {
  FOR(i, 0, n - 1) cout << a[i] << ' ';
};

int add_mod(int a, int b) {
  if (a >= MOD) a %= MOD;
  if (b >= MOD) b %= MOD;
  return (a + b) % MOD;
}

int sub_mod(int a, int b) {
  if (a >= MOD) a %= MOD;
  if (b >= MOD) b %= MOD;
  return (a - b + MOD) % MOD;
}

int mul_mod(int a, int b) {
  if (a >= MOD) a %= MOD;
  if (b >= MOD) b %= MOD;
  return (int64(a) * b) % MOD;
}

int64 cpow_mod(int64 a, int64 b) {
  int64 ans = 1;
  while (b) {
    if (b & 1) ans = mul_mod(ans, a);
    a = mul_mod(a, a);
    b >>= 1;
  };
  return ans;
};

int64 lcm(int64 a, int64 b) {
  return a * b / __gcd(a, b);
}

int64 cpow(int64 a, int64 b) {
  int64 ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b >>= 1;
  };
  return ans;
};

void solve();
void init();
bool TESTS = false;
// ---- main below ----- ///

int main() {
  fast_io();
  init();

  int T = 1;
  if (TESTS) read(T);

  FOR(i, 1, T) solve();
}
//}}

void init() {
  // TESTS = true;
  // MOD = 998244353;
  // MAXN = 1e6;
}

void solve() {
  // chia ra cho so >= n / 2, ma min

  int N; read(N);
  vector<pair<int, int>> v;

  int A[N << 1], B[N << 1];

  int a, b;
  REP (i, 0, N << 1) {
    read(a, b);
    A[i] = a;
    B[i] = b;

    v.push_back({a - b, i});
  }

  sort(all(v));

  int ans = 0;
  REP (i, 0, N) {
    ans += A[v[i].second];
  }
  REP (i, N, 2*N) {
    ans += B[v[i].second];
  }

  ps(ans);
}
