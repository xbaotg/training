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

ll base[100];

int main() {
    fast_io;

    #ifdef _CRUN 
        freopen("input", "r", stdin);
    #endif

    base[0] = 1;
    int i = 1;

    while (base[i-1]*2 <= 2e9) {
        base[i] = base[i-1]*2;
        ++i;
    }

    int t = 1; 
    cin >> t; 
    while (t--)
        solve();
}

void solve() {
    int n;
    read(n);
    ll a[n];
    read(a, n);

    int res = 0;
    for (int i = 1; i < n; i++)
        if (a[i] < a[i-1]) {
            int y = ceil(log2(a[i-1] + 1 - a[i]));
            int n = a[i] + (1 << y) - 1;

            res = max(res, y);

            a[i] = n;
            int j = 32; 

            while (j >= 0) { 
                if (a[i] - base[j] >= a[i-1])
                    a[i] -= base[j]; 

                j--;
            }
        }

    cout << res << endl;
}
