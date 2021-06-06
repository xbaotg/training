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
    int n, m, x, y;
    char c;
    cin >> n >> m >> x >> y; 
    bool a[n][m];

    FOR (i, 0, n) {
        FOR (j, 0, m) {
            cin >> c;
            a[i][j] = c != '*';
        }
    }

    int c1 = 0, c2 = 0;
    FOR (i, 0, n) {
        int j = 0;
        while (j < m - 1) {
            if (a[i][j] && a[i][j+1])
                c2++, j++;
            else if (a[i][j])
                c1++;
            j++;
        }
        c1 += (j == m - 1 && a[i][j]);
    }

    if (y > 2*x) {
        cout << (c2*2 + c1)*x;
    } else {
        cout << c2*y + c1*x;
    }
    cout << endl;
}
