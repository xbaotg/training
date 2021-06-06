#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fort(i, a, b) for (int i = a; i < b; i++)
#define ford(i, a, b) for (int i = int(a) - 1; i >= b; i--)

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
    cin >> t; 
    while (t--)
        solve();
}

void solve() {
    string s;
    cin >> s;

    unordered_map<char, int> m;
    m['L'] = m['R'] = m['U'] = m['D'] = 0;

    for (auto c : s) m[c]++;

    if (min(m['L'], m['R']) == 0) {
        if (m['D'] >= 1 && m['U'] >= 1) {
            cout << 2 << endl << "UD" << endl;
            return;
        }
        cout << 0 << endl << endl;
        return;
    }

    if (min(m['D'], m['U']) == 0) {
        if (m['L'] >= 1 && m['R'] >= 1) {
            cout << 2 << endl << "LR" << endl;
            return;
        }
        cout << 0 << endl << endl;
        return;
    }

    int cX = min(m['L'], m['R']);
    int cY = min(m['D'], m['U']);
    int ans = 2*cX + 2*cY;

    cout << ans << endl;
    fort (i, 0, cX) cout << 'R';
    fort (i, 0, cY) cout << 'D';
    fort (i, 0, cX) cout << 'L';
    fort (i, 0, cY) cout << 'U';
    cout << endl;
}
