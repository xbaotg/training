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

int n, m;
bool cat[100001] = {false}, vs[100001] = {false};
bool can[100001] = {false};
list<int>* adj;

void dfs(int node, int c) {
    vs[node] = true;

    if (adj[node].size() == 1 && vs[adj[node].back()]) {
        can[node] = true;
        return;
    }

    for (auto v : adj[node]) {
        if (!vs[v]) {
            if (cat[v]) {
                if (c + 1 > m) {
                    vs[v] = true;
                    continue;
                }

                dfs(v, c + 1);
            } else
                dfs(v, 0);
        }
    }
}


void solve() {
    read(n, m);

    FOR (i, 1, n)
        read(cat[i]);

    adj = new list<int>[n+1];
    FOR (i, 1, n - 1) {
        int x, y;
        read(x, y);

        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    dfs(1, cat[1]);

    int ans = 0;
    for (auto &v : can)
        ans += v;

    cout << ans << endl;
}
