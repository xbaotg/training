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

void solve() {
    int n;
    read(n);

    int x[n], h[n];
    FOR (i, 0, n - 1)
        read(x[i], h[i]);

    int fL[n], fR[n], fS[n];

    memset(fL, 0, sizeof fL);
    memset(fS, 0, sizeof fS);
    memset(fR, 0, sizeof fR);

    fL[0] = 1;

    FOR (i, 1, n - 1) {
        // right
        fR[i] = fS[i] = fL[i] = max({ fL[i-1], fS[i-1], fR[i-1] });
        
        if (i == n - 1 || x[i] + h[i] < x[i+1])
            fR[i]++;
            
        // not fall

        // left
        if (x[i] - h[i] > x[i-1] + h[i-1])
            fL[i]++;
        else if (x[i] - h[i] > x[i-1]) 
            fS[i] = max({ fL[i-1], fS[i-1], fR[i-1] - 1 }) + 1;
    }

    cout << max({fL[n-1], fS[n-1], fR[n-1]});
}
