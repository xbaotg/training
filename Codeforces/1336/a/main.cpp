#include <bits/stdc++.h>
using namespace std;

#define fast_io        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define For(i, a, b)   for (int i = int(a); i <= int(b); i++)
#define Fod(i, a, b)   for (int i = int(a); i >= int(b); i--)
#define sz(x)          ((int) x.size())
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
template<class T> void read(vector<T> &v, int n) { For (i, 0, n - 1) cin >> v[i]; };
template<class T> void read(vector<T> &v, int f, int t) { For (i, f, t) cin >> v[i]; };
template<class T> void read(T v[], int n) { For(i, 0, n - 1) cin >> v[i]; }; 
template<class H, class... T> void read(H &v, T&... args) { read(v); read(args...); };

int add_mod(unsigned int a, unsigned int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int sub_mod(unsigned int a, unsigned int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
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

vector<vector<int>> adj;
vector<int> ans;
int n, k;
bool vs[100000];

void dfs(int id, int l) {
    vs[id] = true;

    // leaf
    if (adj[id].size() == 1) {
        ans.ep(l);
        return;
    }

    for (auto nxt : adj[id]) {
        if (vs[nxt]) 
            continue;

        dfs(nxt, l + 1);
    }
}

void solve() {
    read(n, k);
    memset(vs, false, sizeof vs);

    adj.assign(n, vector<int> ());
    For (i, 0, n - 2) {
        int x, y;
        read(x, y);

        --x, --y;
        adj[x].ep(y);
        adj[y].ep(x);
    }

    dfs(0, 0);
    sort(ans.begin(), ans.end(), greater<int>());

    if (n == 8)
        for (auto v : ans) 
            cout << v << " ";   
    int cnt = accumulate(ans.begin(), ans.begin() + min(k, (int) ans.size()), 0);

    k = k - ans.size();

    //if (k > 0) {
        //cnt -= k;
    //}

    cout << cnt;
}
