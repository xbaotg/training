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
    cout << fixed << setprecision(12);

    string a, b;
    cin >> a >> b;

    int da = 0, db = 0;
    int cnt = 0;

    for (auto c : a)
        da += (c == '+') ? 1 : -1;
    for (auto c : b)
        db += (c == '+') ? 1 : (c == '?') ? 0 : -1, cnt += c == '?';

    int d = db - da;

    if (!cnt) {
        if (da == db)
            cout << 1.0f;
        else
            cout << 0.0f;
        return;
    }

    if ((d + cnt) & 1) 
        cout << 0.0f;
    else {
        int ca = (d + cnt) >> 1;
        
        int p = 1;
        FOR (i, 1, cnt + 1)
            p *= i;

        FOR (i, 1, cnt - ca + 1)
            p /= i;

        FOR (i, 1, ca + 1)
            p /= i;

        int m = 1 << cnt;

        cout << 1.0 * p / m;
    }
}
