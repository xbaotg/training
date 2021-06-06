#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

#ifdef LOCAL
    #define deb(x) cout<<"LINE("<<__LINE__<<"): "<<(#x)<<" = "<<(x)<<endl; 
#else
    #define deb(...)
#endif

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FOD(i, a, b) for (int i = a; i > b; i--)

#define push_back pb
#define mod 1000000007

typedef long int32;
typedef unsigned long uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve();

//-----------------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while (t--) 
        solve();
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;

    int ca[a], cb[b];
    memset(ca, 0, sizeof ca);
    memset(cb, 0, sizeof cb);

    vpii edges (k);

    for (auto &p : edges)
        cin >> p.first;
    for (auto &p : edges)
        cin >> p.second;
    for (auto &p : edges) {
        p.first--;
        p.second--;
        ca[p.first]++;
        cb[p.second]++;
    }

    int64 ans = 0;

    for (auto p : edges) {
        ans += (int64) k - ca[p.first] - cb[p.second] + 1;
    }

    cout << ans / 2 << endl;
}
