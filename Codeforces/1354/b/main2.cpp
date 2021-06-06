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

    vector<pii> locs;

    for (auto ch : s) {
        if (locs.empty() || locs.back().first != ch) {
            locs.emplace_back(ch, 1);
        } else
            locs.back().second++;
    }

    int n = (int) locs.size();
    int res = int(1e9);

    fort (i, 1, n - 1) {
        if (locs[i-1].first != locs[i+1].first) {
            res = min(res, locs[i].second + 2);
        }
    }

    cout << (res != int(1e9) ? res : 0) << endl;
}
