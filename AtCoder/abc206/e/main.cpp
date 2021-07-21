//{{
/*
 * Created at: 06/22/21 23:06:43
 *
 * FB: https://futps://fcom/tgbaodeeptry
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

int L, R;
int SPF[int(1e6) + 1];

void sieve() {
  FOR(i, 1, R) SPF[i] = i;

  int lim = sqrt(R);
  for (int i = 4; i <= R; i += 2) SPF[i] = 2;
  for (int i = 3; i <= lim; i += 2) {
    if (SPF[i] == i) {
      for (int j = i * i; j <= R; j += i) {
        if (SPF[j] == j) {
          SPF[j] = i;
        }
      }
    }
  }
}

int f(int mx, int *fac, int n) {
  int ret = 0;

  for (int i = 1; i < (1 << n); ++i) {
    int bit = 0, mul = 1;

    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        ++bit;
        mul *= fac[j];
      }
    }

    if (bit & 1) {
      ret += mx / mul;
    } else {
      ret -= mx / mul;
    }
  }

  return mx - ret;
}

void solve() {
  re(L, R);
  sieve();

  int c = R - L + 1;
  long long ret = (ll)c * (c - 1) / 2;

  FOR(i, max(2, L), R) {
    int fac[10];
    int idx = -1;

    {
      int num = i;

      while (num != 1) {
        if (idx == -1 || fac[idx] != SPF[num]) {
          fac[++idx] = SPF[num];
        }

        num /= SPF[num];
      }
    }

    // g == 1
    int a = f(R, fac, idx + 1) - f(i, fac, idx + 1);
    int b = (R - i) / i;

    // x == g
    ret -= a;
    ret -= b;

    // pd(a, b, ret);
  }

  ps(2 * ret);
}
