//{{
/*
 * Created at: 06/12/21 15:03:20
 *
 * FB: https://facebook.com/tgbaodeeptry
 * From Viet Nam with Love :D 
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io()      ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FOR(i, a, b)   for (int i = int(a); i <= int(b); i++)
#define FOD(i, a, b)   for (int i = int(a); i >= int(b); i--)
#define sz(x)          ((int) x.size())
#define all(x)         (x).begin(), (x).end()
#define FF             first
#define SS             second
#define eb             emplace_back
#define pb             push_back
#define endl           '\n'

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const int MAXN = 1e5 + 1;

template<class T> void re(T &x) { cin >> x; };
template<class T> void re(vector<T> &v, int n) { FOR (i, 0, n - 1) cin >> v[i]; };
template<class T> void re(vector<T> &v, int f, int t) { FOR (i, f, t) cin >> v[i]; };
template<class T> void re(T v[], int n) { FOR(i, 0, n - 1) cin >> v[i]; }; 
template<class H, class... T> void re(H &v, T&... args) { re(v); re(args...); };

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
template<typename T> void dbg_out(vector<T> a) { for (auto c : a) cerr << ' ' << c; cerr << endl; };
template<typename T> void dbg_out(T a[]) { for (auto c : a) cerr << ' ' << c; cerr << endl; };
template<typename T> void dbg_out(vector<T> a, int n) { FOR (i, 0, n - 1) cerr << ' ' << a[i]; cerr << endl; };
template<typename T> void dbg_out(T a[], int n) { FOR (i, 0, n - 1) cerr << ' ' << a[i]; cerr << endl; };
template<typename T> void dbg_out(vector<T> a, int u, int v) { FOR (i, u, v) cerr << ' ' << a[i]; cerr << endl; };
template<typename T> void dbg_out(T a[], int u, int v) { FOR (i, u, v) cerr << ' ' << a[i]; cerr << endl; };

#if defined(_CRUN) || defined(_RUN)
#define pd(...) cerr << "(L:" << __LINE__ << "): " << "[" << #__VA_ARGS__ << "] =", dbg_out(__VA_ARGS__)
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

void ps() {};
template<typename Head, typename... Tail> void ps(Head H, Tail... T) { cout << H; ps(T...); }; 
template<typename T> void ps(vector<T> a, int n) { FOR (i, 0, n - 1) cout << a[i] << ' '; }; 
template<typename T> void ps(T a[], int n) { FOR (i, 0, n - 1) cout << a[i] << ' '; }; 

ll add_mod(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll sub_mod(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
ll mul_mod(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }

void solve();
//}}

const int MAX = 1e7;
int SPF[MAX + 1];

void seive() {
  FOR (i, 0, MAX)
    SPF[i] = i;

  SPF[0] = SPF[1] = 1;

  for (int i = 4; i <= MAX; i += 2) SPF[i] = 2;
  for (int i = 3; i*i <= MAX; i += 2) {
    if (SPF[i] == i) {
      for (int j = i*i; j <= MAX; j += i) {
        if (SPF[j] == j) {
          SPF[j] = i;
        }
      }
    }
  }
}

int main() {
  fast_io();
  seive();

  int T = 1;
  re(T); 
  FOR (i, 1, T) solve();
}

set<int> factorize(int x) {
  set<int> ret;
  int l = -1, c = 0;

  while (x != 1) {
    if (l != SPF[x]) {
      if (~l) {
        if (c & 1) 
          ret.emplace(l);
      }
      l = SPF[x];
      c = 1;
    } else {
      ++c;
    }

    x /= SPF[x];
  }

  if (c & 1)
    ret.emplace(l);

  return ret;
}

void solve() {
  int n, x, k;
  re(n, k);

  int ans = 0;
  set<set<int>> s;
  set<int> t;

  for (int i = 0; i < n; ++i) {
    re(x);

    t = factorize(x);
    if (s.find(t) != s.end()) {
      s.clear();
      ++ans;
    }

    s.emplace(t);
  }

  ++ans;

  ps(ans, endl);
}
