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
    cin >> t; 
    while (t--)
        solve();
}

void solve() {
    int a, b;
    cin >> a >> b;

    string s;
    cin >> s;

    int n = s.length();
    vector<pii> loc;

    fort (i, 0, n) {
        if (s[i] == '1') {
            if (!loc.empty() && loc.back().second + 1 == i) {
                loc.back().second++;
            } else {
                loc.emplace_back(i, i);
            }
        }
    }

    int i = 1, m = loc.size(), c = a, ans = 0;

    if (m == 0) {
        cout << 0 << endl;
        return;
    }

    while (i < m) {
        if (a < (loc[i].first - loc[i-1].second - 1)*b) {
            ans += c;
            c = a;
        } else {
            c += (loc[i].first - loc[i-1].second - 1)*b;
        }

        i++;
    }

    ans += c;
    cout << ans << endl;
}
