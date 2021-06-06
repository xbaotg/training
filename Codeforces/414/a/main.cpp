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

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

const int MOD = 1000000007;
const int INF = INT_MAX;

void solve();
template<class T> void read(T &x) { cin >> x; };
template<class T> void read(vector<T> &v, int n) { FOR (i, 0, n - 1) cin >> v[i]; };
template<class T> void read(vector<T> &v, int f, int t) { FOR (i, f, t) cin >> v[i]; };
template<class T> void read(T v[], int n) { FOR(i, 0, n - 1) cin >> v[i]; }; 
template<class H, class... T> void read(H &v, T&... args) { read(v); read(args...); };

int plus_mod(unsigned int a, unsigned int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int minus_mod(unsigned int a, unsigned int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
int mul_mod(unsigned int a, unsigned int b) { return ((a % MOD) * 1LL * (b % MOD)) % MOD; }
int lcm(unsigned int a, unsigned int b) { return a * 1LL * b / __gcd(a, b); }
int gcd(unsigned int a, unsigned int b) { return __gcd(a, b); }

//---------------------------------------------------------------//
//                                                               //
// FB: https://facebook.com/tgbaodeeptry                         //
//                                                               //
// From Viet Nam with Love :D                                    //
//                                                               //  
//---------------------------------------------------------------//

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

const int M = 2000000;

vector<bool> primes(M + 1, true);

void gen() {
    int m = sqrt(M);
    primes[0] = primes[1] = false;
    for (int i = 4; i <= M; i += 2) 
        primes[i] = false;

    for (int i = 3; i <= m; i += 2)
        if (primes[i])
            for (int j = i*i; j <= M; j += i)
                primes[j] = false;
}

void solve() {
    int n, k, c1, c2;
    read(n, k);

    int m = n / 2;

    if (!m && k) {
        cout << -1 << endl;
        return;
    }

    k -= m;

    if (k < 0) 
        cout << -1;
    else {
        c1 = 0;
        c2 = 0;

        if (k) {
            k++;

            c1 = k;
            c2 = 2*k;

            cout << c1 << " " << c2 << " ";

            m--;
        }
        gen();

        m *= 2;
        m += n % 2;
        
        for (int i = 1; i <= M && m; i += 2) {
            if (primes[i] && i != c1 && i != c2) {
                cout << i << " ";
                m--;
            }
        }
    }
}
