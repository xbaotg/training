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
        freopen("input", "r", stdin);
    #endif

    int t = 1;
    //cin >> t; 
    while (t--)
        solve();
}

bool block[200001];
vi need;
vvi edges;

bool check(int v) {
    block[v] = true;

    int s = edges[v][0], e = edges[v][1], l = v;
    vi t;

    while (s != e) {
        if (edges[s].size() == 2 && !block[s]) {
            block[s] = true;
            fort (i, 0, 2) {
                if (edges[s][i] != l) {
                    l = s;
                    s = edges[s][i];
                    break;
                }
            }
        } else 
            break;
    }

    if (s == e && !block[e]) {
        block[s] = true;
        return true;
    } 

    return false;
}

void solve() {
    int n, m, x, y;
    cin >> n >> m;

    memset(block, false, sizeof block);
    edges.assign(n + 1, vector<int>());

    fort (i, 0, m) {
        cin >> x >> y;
    
        if (!block[x]) {
            edges[x].emplace_back(y);
            if (edges[x].size() > 2) 
                block[x] = true;
        }

        if (!block[y]) {
            edges[y].emplace_back(x);
            if (edges[y].size() > 2) 
                block[y] = true;
        }
    }

    int ans = 0;
    vi to_check;

    fort (i, 1, n + 1) {
        if (block[i])
            continue;

        if (edges[i].size() == 2) {
            if (check(i)) {
                ++ans;
            }
        }
    }

    cout << ans;
}
