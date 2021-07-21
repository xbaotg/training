//{{
/*
 * Created at: 06/11/21 22:51:07
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

int main() {
  fast_io();
  //c_input();

  int T = 1;
  re(T); 
  FOR (i, 1, T) solve();
}

map<char, char> rev {
  { '0', '0' },
    { '1', '1' },
    { '2', '5' }, 
    { '3', '-' },
    { '4', '-' },
    { '5', '2' },
    { '6', '-' },
    { '7', '-' },
    { '8', '8' },
    { '9', '-' },
};

string ok(int h, int m, int th, int tm) {
  string hs = to_string(h);
  string ms = to_string(m);

  while (sz(hs) < 2) hs = "0" + hs;
  while (sz(ms) < 2) ms = "0" + ms;

  string rh = "", rm = "";
  rh += rev[ms[1]];
  rh += rev[ms[0]];
  rm += rev[hs[1]];
  rm += rev[hs[0]];

  string ret = rh + ":" + rm;

  for (auto &v : ret) {
    if (!isdigit(v) && v != ':') {
      return "";
    }
  }

  if (stoi(rh) >= th || stoi(rm) >= tm) {
    return "";
  }

  return ret;
};

void solve() {
  int th, tm;
  re(th, tm);

  string h, m, t;
  re(t);
  h = t.substr(0, 2);
  m = t.substr(3);

  int ch = stoi(h);
  int cm = stoi(m);

  while (true) {
    string ret = ok(ch, cm, th, tm);
    if (sz(ret)) {
      string ht = to_string(ch); 
      string mt = to_string(cm);

      if (sz(ht) == 1) ht = "0" + ht;
      if (sz(mt) == 1) mt = "0" + mt;

      ps(ht, ":", mt, endl);
      return;
    }

    ++cm;
    if (cm == tm) {
      ++ch;
      cm = 0;
    }

    if (ch == th) {
      ps("00:00\n");
      return;
    }
  }
}
