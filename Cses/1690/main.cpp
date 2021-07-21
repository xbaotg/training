//{{
/*
 * Created at: 06/27/21 14:17:44
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
#define allong(x) (x).begin(), (x).end()
#define f first
#define s second
#define eb emplace_back
#define pb push_back
#define endl '\n'

using llong = long long;
using veci = vector<int>;
using vecveci = vector<vector<int>>;
using pairii = pair<int, int>;

const int MOD = 1e9 + 7;
const int MAXN = 1e5;
const int INF = INT_MAX;

template <class T>
void re(T& x) {
  cin >> x;
};
template <class T>
void re(vector<T>& v, int n) {
  for (int i = 0; i < n; ++i)
    cin >> v[i];
};
template <class T>
void re(vector<T>& v, int f, int t) {
  FOR(i, f, t)
  cin >> v[i];
};
template <class T>
void re(T v[], int n) {
  FOR(i, 0, n - 1)
  cin >> v[i];
};
template <class T>
void re(T* v, int f, int t) {
  FOR(i, f, t)
  cin >> v[i];
};
template <class H, class... T>
void re(H& v, T&... args) {
  re(v);
  re(args...);
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
  FOR(i, 0, n - 1)
  cerr << ' ' << a[i];
  cerr << endl;
};

template <typename T>
void dbg_out(vector<T>& a, int u, int v) {
  FOR(i, u, v)
  cerr << ' ' << a[i];
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
  FOR(i, 0, n - 1)
  cerr << ' ' << a[i];
  cerr << endl;
};

template <typename T>
void dbg_out(T a[], int u, int v) {
  FOR(i, u, v)
  cerr << ' ' << a[i];
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
  FOR(i, 0, n - 1)
  cout << a[i] << ' ';
};

template <typename T>
void ps(T a[], int n) {
  FOR(i, 0, n - 1)
  cout << a[i] << ' ';
};

int add_mod(int a, int b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}

int sub_mod(int a, int b) {
  return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

int mul_mod(int a, int b) {
  return ((llong)(a % MOD) * (b % MOD)) % MOD;
}

llong pow_mod(llong a, llong b) {
  llong ans = 1;
  while (b) {
    if (b & 1) ans = mul_mod(ans, a);
    a = mul_mod(a, a);
    b >>= 1;
  };
  return ans;
};

llong lcm(llong a, llong b) {
  return a * b / __gcd(a, b);
}

llong pow(llong a, llong b) {
  llong ans = 1;
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

int N, M;
int lim = 0;
vector<int> G[20];
int dp[20][1 << 20];

int dfs(int u, int vs) {
  if (~dp[u][vs]) {
    return dp[u][vs];
  }

  if (u == N - 1) {
    return dp[u][vs] = vs == lim;
  }

  int ret = 0;
  for (auto &v : G[u]) {
    if (!(vs & (1 << v))) {
      ret = (ret + dfs(v, vs | (1 << v))) % MOD;
    }
  }

  return dp[u][vs] = ret;
}

void solve() {
  re(N, M);
  REP(i, 0, M) {
    int a, b;
    re(a, b);

    --a, --b;
    G[a].push_back(b);
  }

  memset(dp, -1, sizeof dp);
  lim = (1 << N) - 1;

  ps(dfs(0, 1));
}
