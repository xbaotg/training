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
    int a, b, k, x;
    cin >> a >> b >> k;

    int cb[a+1], cg[b+1];
    memset(cb, 0, sizeof cb);
    memset(cg, 0, sizeof cg);

    FOR (i, 0, k) {
        cin >> x;
        cb[x]++;
    }
    FOR (i, 0, k) {
        cin >> x;
        cg[x]++;
    }

    int64 m = (int64) k*(k-1)/2;
    int64 c = 0;

    FOR (i, 1, a + 1) {
        c += (int64) cb[i] * (cb[i] - 1) / 2;
    }

    FOR (i, 1, b + 1)
        c += (int64) cg[i] * (cg[i] - 1) / 2;

    cout << m - c << endl;
}
