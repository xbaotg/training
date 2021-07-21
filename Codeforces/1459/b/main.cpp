//{{
/*
 * Created at: 06/08/21 17:40:43
 *
 * FB: https://facebook.com/tgbaodeeptry
 * From Viet Nam with Love :D 
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io()      ios_base::sync_with_stdio(false); cin.tie(NULL);
#define For(i, a, b)   for (int i = int(a); i <= int(b); i++)
#define Fod(i, a, b)   for (int i = int(a); i >= int(b); i--)
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
const int MAXN = 1e5;

template<class T> void read(T &x) { cin >> x; };
template<class T> void read(vector<T> &v, int n) { For (i, 0, n - 1) cin >> v[i]; };
template<class T> void read(vector<T> &v, int f, int t) { For (i, f, t) cin >> v[i]; };
template<class T> void read(T v[], int n) { For(i, 0, n - 1) cin >> v[i]; }; 
template<class H, class... T> void read(H &v, T&... args) { read(v); read(args...); };

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
template<typename T> void dbg_out(vector<T> a) { for (auto c : a) cerr << ' ' << c; cerr << endl; };
template<typename T> void dbg_out(T a[]) { for (auto c : a) cerr << ' ' << c; cerr << endl; };
template<typename T> void dbg_out(vector<T> a, int n) { For (i, 0, n - 1) cerr << ' ' << a[i]; cerr << endl; };
template<typename T> void dbg_out(T a[], int n) { For (i, 0, n - 1) cerr << ' ' << a[i]; cerr << endl; };
template<typename T> void dbg_out(vector<T> a, int u, int v) { For (i, u, v) cerr << ' ' << a[i]; cerr << endl; };
template<typename T> void dbg_out(T a[], int u, int v) { For (i, u, v) cerr << ' ' << a[i]; cerr << endl; };

#if defined(_CRUN) || defined(_RUN)
#define dbg(...) cerr << "(L:" << __LINE__ << "): " << "[" << #__VA_ARGS__ << "] =", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#if defined(_CRUN)
#define c_input() freopen("input", "r", stdin)
#define c_output() freopen("output", "r", stdin)
#else
#define c_input()
#define c_output()
#endif

void print() {};
template<typename Head, typename... Tail> void print(Head H, Tail... T) { cout << H; print(T...); }; 
template<typename T> void print(vector<T> a, int n) { For (i, 0, n - 1) cout << a[i] << ' '; }; 
template<typename T> void print(T a[], int n) { For (i, 0, n - 1) cout << a[i] << ' '; }; 

ll add_mod(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll sub_mod(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
ll mul_mod(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }

void solve();
//}}


int main() {
  fast_io();

  int n;
  read(n);

  // 1 2 3  4 5  6  7  8  9  10 11 12 13  14 15
  // 4,4,12,9,24,16,40,25,60,36,84,49,112,64,144
  //
  // 1 4  = 4*1
  // 3 12 = 4*3
  // 5 24 = 4*6
  // 7 40 = 4*10
  // 9 60 = 4*15
  // 11   = 4*21

  if (n & 1) {
    int m = ceil(1.0 * n / 2);
    print(2 * m * (m + 1));
  } else {
    print((n / 2 + 1) * (n / 2 + 1));
  }
}
