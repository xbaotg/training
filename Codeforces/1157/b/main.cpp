#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fort(i, a, b) for (int i = a; i < b; i++)
#define ford(i, a, b) for (int i = a; i > b; i--)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

const int MOD = 1000000007;
const int INF = INT_MAX;

void solve();

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
    int n;
    string s;
    int f[10];

    cin >> n >> s;
    fort (i, 1, 10) 
        cin >> f[i];

    bool w = false;
    int idx = -1;
    int end = -1;

    fort (i, 0, n) {
        int n = s[i] - '0';
        
        if (f[n] > n) {
            if (!w) {
                w = true;
                idx = i;
            }
        } else if (f[n] < n) {
            if (w) {
                end = i;
                w = false;
                break;
            }
        }
    }

    if (idx == -1) {
        cout << s;
        return;
    }

    if (w) 
        end = n;

    fort (i, 0, idx) 
        cout << s[i];

    fort (i, idx, end) 
        cout << f[s[i] - '0'];

    fort (i, end, n) 
        cout << s[i];
}
