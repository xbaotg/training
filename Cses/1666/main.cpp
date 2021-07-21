//{{
/*
 * Created at: 07/05/21 14:03:31
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
void dbg_out(T a[], int n) {
  FOR(i, 0, n - 1) cerr << ' ' << a[i];
  cerr << endl;
};

template <typename T>
void dbg_out(T a[], int u, int v) {
  FOR(i, u, v) cerr << ' ' << a[i];
  cerr << endl;
};

template <typename Y, typename Z>
void dbg_out(pair<Y, Z> p) {
  cerr << p.first << " " << p.second;
  cerr << endl;
}

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

template <typename Y, typename Z>
void ps(pair<Y, Z> p) {
  cout << p.first << " " << p.second;
}

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

int n, m;
vector<int> G[100000];

struct UnionFind {
  vector<int> parents;
  vector<int> sz;

  void init(int n) {
    REP(i, 0, n) parents.emplace_back(i);
    sz.assign(n, 1);
  }

  int find(int u) {
    if (u == parents[u]) return u;
    return parents[u] = find(parents[u]);
  }

  void join(int u, int v) {
    int a = find(u);
    int b = find(v);

    if (a == b) return;
    if (sz[a] > sz[b]) swap(a, b);

    parents[a] = b;
    sz[b] += sz[a];
  }
};

void solve() {
  read(n, m);

  UnionFind UF;
  UF.init(n);

  REP(i, 0, m) {
    int u, v;
    read(u, v);
    --u, --v;

    UF.join(u, v);
  }

  set<int> s;
  REP(i, 0, n) { s.insert(UF.find(i)); }

  ps(sz(s) - 1, endl);
  for (auto it = next(s.begin()); it != s.end(); ++it) {
    ps((*s.begin()) + 1, " ", (*it) + 1, endl);
  }
}
