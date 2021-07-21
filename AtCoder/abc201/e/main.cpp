//{{
/*
 * Created at: 07/01/21 23:04:30
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
  FOR(i, f, t) cin >> v[i];
};

template <class T>
void re(T v[], int n) {
  FOR(i, 0, n - 1) cin >> v[i];
};

template <class T>
void re(T* v, int f, int t) {
  FOR(i, f, t) cin >> v[i];
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
  return ((a % MOD) + (b % MOD)) % MOD;
}

int sub_mod(int a, int b) {
  return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

int mul_mod(int a, int b) {
  return ((int64)(a % MOD) * (b % MOD)) % MOD;
}

int64 pow_mod(int64 a, int64 b) {
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

int N;
vector<pair<int, int64>> G[MAXN << 1];
int dp[(MAXN << 1) + 1][60][2];
int64 dist[MAXN << 1];

void dfs1(int u, int p, int64 cur) {
  for (auto& v : G[u]) {
    if (v.first != p) {
      int64 t = cur ^ v.second;

      dist[v.first] = t;
      dfs1(v.first, u, t);
    }
  }
}

void solve() {
  re(N);

  int a, b;
  int64 w;

  REP(i, 1, N) {
    re(a, b, w);
    --a, --b;

    G[a].push_back({b, w});
    G[b].push_back({a, w});
  }

  dfs1(0, -1, 0);
  memset(dp, 0, sizeof dp);

  REP(i, 0, 60) {
    REP(k, 0, 2) {
      FOD(j, N - 1, 0) {
        dp[j][i][k] =
            dp[j + 1][i][k] + (((dist[j] & (1LL << i)) > 0) == (k > 0));
      }
    }
  }

  int ans = 0;
  REP(i, 0, N - 1) {
    REP(j, 0, 60) {
      if (dist[i] & (1LL << j)) {
        ans = (ans + mul_mod((1LL << j) % MOD, dp[i + 1][j][0])) % MOD;
      } else {
        ans = (ans + mul_mod((1LL << j) % MOD, dp[i + 1][j][1])) % MOD;
      }
    }
  }

  ps(ans);
}
