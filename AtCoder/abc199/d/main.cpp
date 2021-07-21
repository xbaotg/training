//{{
/*
 * Created at: 06/25/21 22:16:16
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

ll add_mod(ll a, ll b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}

ll sub_mod(ll a, ll b) {
  return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll mul_mod(ll a, ll b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}

ll pow_mod(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans = mul_mod(ans, a);
    a = mul_mod(a, a);
    b >>= 1;
  };
  return ans;
};

ll lcm(ll a, ll b) {
  return a * b / __gcd(a, b);
}

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

struct UnionFind {
  int parents[21];
  int size[21];

  void init(int n) {
    memset(size, 0, sizeof size);
    FOR(i, 1, n) parents[i] = i;
  }

  int find(int u) {
    if (u == parents[u]) return u;
    return parents[u] = find(parents[u]);
  }

  void unite(int u, int v) {
    int a = find(u);
    int b = find(v);

    if (a == b) return;
    if (size[a] == size[b]) ++size[a];
    if (size[a] < size[b])
      parents[a] = b;
    else
      parents[b] = a;
  }
};

vector<int> G[21];
int color[21];
bool vs[21];
int cur = 0;
long long ans = 1;

void dfs1(vector<int>& road, int u) {
  vs[u] = true;
  road.push_back(u);

  for (auto& v : G[u]) {
    if (!vs[v]) {
      dfs1(road, v);
    }
  }
}

void dfs2(int i, vector<int>& road) {
  if (i == sz(road)) {
    ++cur;
    return;
  }

  int u = road[i];

  REP(j, 0, 3) {
    bool can = true;

    for (auto& v : G[u]) {
      if (color[v] == j) {
        can = false;
        break;
      }
    }

    if (can) {
      color[u] = j;
      dfs2(i + 1, road);
    }
  }

  color[u] = -1;
}

void solve() {
  int n, m;
  re(n, m);

  UnionFind UF;
  UF.init(n);

  REP(i, 0, m) {
    int a, b;
    re(a, b);

    UF.unite(a, b);

    G[a].push_back(b);
    G[b].push_back(a);
  }

  memset(vs, false, sizeof vs);
  memset(color, -1, sizeof color);

  FOR(i, 1, n) {
    if (UF.find(i) != i) continue;

    cur = 0;
    vector<int> road;

    dfs1(road, i);
    dfs2(0, road);

    ans *= cur;
  }

  ps(ans);
}
