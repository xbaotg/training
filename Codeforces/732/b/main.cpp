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

int n, k;
int a[501];
int memo[501] = {-1};
int ans[501] = {0};

int f(int idx) {
    if (idx >= n - 1)
        return 0;

    if (memo[idx] != -1)
        return memo[idx];

    int t1 = INT_MAX, t2 = INT_MAX;

    if (idx)
        t1 = max({0, k - a[idx] - a[idx-1], k - a[idx] - a[idx+1]});

    if (idx < n - 1) {
        t1 = max(t1, k - a[idx] - a[idx + 1]);
        t2 = max(0, k - a[idx+1] - a[idx]);
    }
    
    if (idx < n - 2) 
        t2 = max(t2, k - a[idx + 1] - a[idx + 2]);

    if (t1 < t2)
        return ans[idx] = t1, memo[idx] = t1 + f(idx + 2);

    return ans[idx + 1] = t2, memo[idx + 1] = t2 + f(idx + 3);
}

void solve() {
    read(n, k);
    read(a, n);

    cout << f(0) << endl;
    FOR (i, 0, n - 1)
        cout << a[i] + ans[i] << " ";
}
