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
    //cin >> t;

    while (t--) 
        solve();
}

void solve() {
    int n;
    cin >> n;

    int cp = 0, c0 = 0, cn = 0;
    int x;

    FOR (i, 0, n) {
        cin >> x;
        cp += x > 0;
        c0 += x == 0;
        cn += x < 0;
    }

    int l = n / 2 + n % 2;

    if (cp >= l) 
        cout << 1;
    else if (cn >= l) 
        cout << -1;
    else 
        cout << 0;
}
