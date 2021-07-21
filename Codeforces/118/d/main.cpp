//{{
/*
 * Created at: 06/10/21 13:09:10
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

const int MOD = 1e8;
const int INF = INT_MAX;
const int MAXN = 1e5;

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

int main() {
  fast_io();

  int T = 1;
  //re(T); 
  FOR (i, 1, T) solve();
}

int k1, k2;
int memo[101][101][2];

int f(int a, int b, bool t) {
  if (~memo[a][b][t])
    return memo[a][b][t];

  if (a == 0 && b == 0)
    return memo[a][b][t] = 1;

  if (a == 0 && b > k2)
    return memo[a][b][t] = 0;

  if (b == 0 && a > k1)
    return memo[a][b][t] = 0;

  int ret = 0;

  if (t) {
    // last footmen
    for (int i = 1; i <= min(b, k2); ++i) {
      ret = add_mod(ret, f(a, b - i, !t));
    }
  } else {
    // last horsemen
    for (int i = 1; i <= min(a, k1); ++i) {
      ret = add_mod(ret, f(a - i, b, !t));
    }
  }

  return memo[a][b][t] = ret;
}

void solve() {
  int n1, n2;
  re(n1, n2, k1, k2);

  fill_n(&memo[0][0][0], 101*101*2, -1);
  
  int ret = add_mod(f(n1, n2, true), f(n1, n2, false));

  ps(ret);
}
