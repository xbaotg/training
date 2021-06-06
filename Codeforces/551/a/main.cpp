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

    int a[n];
    for (auto &v : a)
        cin >> v;

    int b[n];
    copy(a, a + n, b);
    sort(b, b + n, greater<int>());

    int c[2001];
    memset(c, 0, sizeof c);

    FOR(i, 0, n)
        if (c[b[i]] == 0) 
            c[b[i]] = i + 1;

    for (auto v : a)
        cout << c[v] << " ";
}
