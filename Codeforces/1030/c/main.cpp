#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fort(i, a, b) for (int i = int(a); i < int(b); i++)
#define ford(i, a, b) for (int i = int(a); i > int(b); i--)
#define SZ(x) ((int) x.size())
#define ALL(x) (x).begin(), (x).end()
#define F first
#define S second

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

const int MOD = 1000000007;
const int INF = INT_MAX;

void solve();
template<class T> void read(T &x) { cin >> x; };
template<class T> void read(vector<T> &v, int n) { fort (i, 0, n) cin >> v[i]; };
template<class T> void read(vector<T> &v, int f, int t) { fort (i, f, t + 1) cin >> v[i]; };

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

void solve() {
    int n; read(n);
    string s; read(s);

    s.erase(remove_if(s.begin(), s.end(), [](char c) { return c == '0'; }), s.end());
    n = s.length();

    if (n == 0) {
        cout << "YES";
        return;
    }

    int t = 0;
    fort (i, 0, n - 1) {
        t += s[i] - '0';

        int j = i + 1;
        int w = 0;

        while (j < n) {
            w += s[j] - '0';
            if (w == t) {
                if (j == n - 1) {
                    cout << "YES";
                    return;
                }

                w = 0;
            }
            j++;
        }
    }

    cout << "NO";
}
