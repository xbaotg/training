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
        freopen("input", "r", stdin);
    #endif

    int t = 1;
    //cin >> t; 
    while (t--)
        solve();
}

void solve() {
    int n, x;
    cin >> n;
    map<int, int> base = {
        {4, 0},
        {8, 1},
        {15, 2},
        {16, 3},
        {23, 4},
        {42, 5}
    };
    map<int, vi> c;
    fort (i, 0, 6) c[i] = vi();

    fort (i, 0, n) {
        cin >> x;
        c[base[x]].emplace_back(i);
    }

    if (min({c[0].size(), c[1].size(), c[2].size(), c[3].size(), c[4].size(), c[5].size()}) == 0) {
        cout << n << endl;
        return;
    }

    int ans = 0;
    int l[6] = {0, 0, 0, 0, 0, 0};

    fort (k, 0, (int) c[0].size()) {
        fort (i, 1, 6) {
            if (l[i] == (int) c[i].size()) {
                cout << n - ans;
                return;
            }
            while (c[i][l[i]] < c[i-1][l[i-1]]) {
                l[i]++;
                if (l[i] == (int) c[i].size()) {
                    cout << n - ans;
                    return;
                }
            }
        }
        fort (i, 0, 6) l[i]++;
        ans += 6;
    }

    // 0: 0 2
    // 1: 1 5
    // 2: 3 7
    // 3: 4 8
    // 4: 6 10
    // 5: 9 11

    cout << n - ans;
}
