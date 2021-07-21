//{{
/*
 * Created at: 06/30/21 23:00:53
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

int N, M, Q;
int X[50];
bool vs[50];
pair<int, int> bag[50];

void solve() {
  re(N, M, Q);
  REP(i, 0, N) { re(bag[i].first, bag[i].second); }
  REP(i, 0, M) { re(X[i]); }

  sort(bag, bag + N);

  while (Q--) {
    int L, R;
    re(L, R);

    --L, --R;

    vector<int> boxes;
    int ans = 0;

    REP(i, 0, M) {
      if (i < L || i > R) boxes.push_back(X[i]);
    }

    sort(all(boxes));
    memset(vs, false, sizeof vs);

    for (auto& v : boxes) {
      auto it = lower_bound(bag, bag + N, make_pair(v + 1, 0));
      int far = -1, farval = 0;

      for (int t = 0; t < distance(bag, it); ++t) {
        if (!vs[t] && bag[t].second > farval) {
          far = t;
          farval = bag[t].second;
        }
      }

      if (~far) {
        ans += farval;
        vs[far] = true;
      }
    }

    ps(ans, endl);
  }
}
