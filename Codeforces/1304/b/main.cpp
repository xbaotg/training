/*
 * Created at: 06/06/21 18:34:17
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

void print() {};
template<typename Head, typename... Tail> void print(Head H, Tail... T) { cout << H; print(T...); }; 
template<typename T> void print(vector<T> a, int n) { For (i, 0, n - 1) cout << a[i] << ' '; }; 
template<typename T> void print(T a[], int n) { For (i, 0, n - 1) cout << a[i] << ' '; }; 

ll add_mod(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll sub_mod(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
ll mul_mod(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }

void solve();
/***********************************************************/

int main() {
    fast_io();

    #ifdef _CRUN 
        freopen("input", "r", stdin);
    #endif

    int t = 1; 
    //cin >> t; 
    while (t--) solve();
}

void solve() {
    int n, m;
    read(n, m);

    string s[n];
    read(s, n);

    auto isSame = [](string a, string b) {
        reverse(all(b));
        return a == b;
    };

    auto isPindrome = [](string a) {
        string b = a;
        reverse(all(b));

        return a == b;
    };

    unordered_set<int> t;
    vector<int> vals;

    For (i, 0, n - 2) {
        if (t.find(i) != t.end())
            continue;

        For (j, i + 1, n - 1) {
            if (t.find(j) != t.end())
                continue;

            if (!isSame(s[i], s[j]))
                continue;

            t.emplace(i);
            t.emplace(j);

            vals.push_back(i);
            vals.push_back(j);

            break;
        }
    }

    int z = -1;

    For (i, 0, n - 1) {
        if (isPindrome(s[i]) && t.find(i) == t.end()) {
            z = i;
            break;
        }
    }

    print(sz(vals) * m + (z >= 0 ? m : 0), "\n");

    string res = "";

    for (int i = 0; i < sz(vals); i += 2)
        res += s[vals[i]];

    if (z >= 0) 
        res += s[z];

    for (int i = sz(vals) - 1; i >= 0; i -= 2) {
        res += s[vals[i]];
    }

    print(res);
}
