#include <bits/stdc++.h>
using namespace std;

#define fast_io        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FOR(i, a, b)   for (int i = int(a); i <= int(b); i++)
#define FOD(i, a, b)   for (int i = int(a); i >= int(b); i--)
#define SZ(x)          ((int) x.size())
#define ALL(x)         (x).begin(), (x).end()
#define F              first
#define S              second
#define ep             emplace_back
#define pb             push_back

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

const int MOD = 1000000007;

template<class T> void read(T &x) { cin >> x; };
template<class T> void read(vector<T> &v, int n) { FOR (i, 0, n - 1) cin >> v[i]; };
template<class T> void read(vector<T> &v, int f, int t) { FOR (i, f, t) cin >> v[i]; };
template<class T> void read(T v[], int n) { FOR(i, 0, n - 1) cin >> v[i]; }; 
template<class H, class... T> void read(H &v, T&... args) { read(v); read(args...); };

int plus_mod(unsigned int a, unsigned int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int minus_mod(unsigned int a, unsigned int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
int mul_mod(unsigned int a, unsigned int b) { return ((a % MOD) * 1LL * (b % MOD)) % MOD; }
int lcm(unsigned int a, unsigned int b) { return a * 1LL * b / __gcd(a, b); }

void solve();
//-----------------------------------------------------//
//                                                     //
// FB: https://facebook.com/tgbaodeeptry               //
//                                                     //
// From Viet Nam with Love :D                          //
//                                                     //  
//-----------------------------------------------------//

int main() {
    fast_io;

#ifdef _CRUN 
    //freopen("input", "r", stdin);
#endif

    int t = 1; 
    //cin >> t; 
    while (t--)
        solve();
}

const int MAX = 100001;

int n;
int x[MAX], h[MAX], choice[MAX];
int l[MAX], s[MAX], r[MAX];

int f(int i) {
    if (i >= n)
        return 0;

    if (i == 0) {
        choice[i] = -1;
        return l[i] = f(i+1) + 1;
    }

    if (i == n - 1) {
        choice[i] = 1;
        return r[i] = 1;
    }

    int ans[3] = { 0, 0, 0 };

    // stand
    {
        choice[i] = 0;
        if (s[i] == -1)
            s[i] = ans[1] = f(i+1);
        else
            ans[1] = s[i];
    }

    // fall left
    if (x[i] - h[i] > x[i-1] + choice[i-1]*h[i-1]) {
        choice[i] = -1;
        if (l[i] == -1)
            l[i] = ans[0] = f(i+1) + 1;
        else
            ans[0] = l[i];
    }

    // fall right 
    if (x[i] + h[i] < x[i+1]) {
        choice[i] = 1;
        if (r[i] == -1)
            r[i] = ans[2] = f(i+1) + 1;
        else
            ans[2] = r[i];
    }

    return max({ ans[0], ans[1], ans[2] });
}

void solve() {
    read(n);

    for (int i = 0; i < n; ++i) 
        read(x[i], h[i]);

    memset(choice, 0, sizeof choice);
    memset(l, -1, sizeof l);
    memset(s, -1, sizeof s);
    memset(r, -1, sizeof r);

    cout << f(0);
}
