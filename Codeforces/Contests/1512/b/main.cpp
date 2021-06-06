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
    int n;
    cin >> n;
    int x1 = -1, x2, y1 = -1, y2;

    string s[n];
    FOR (i, 0, n) {
        cin >> s[i];

        FOR (j, 0, n) {
            if (s[i][j] == '*') {
                if (x1 == -1) {
                    x1 = i;
                    y1 = j;
                } else {
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }

    if (x1 == x2) {
        if (x1 > 0) {
            s[x1-1][y1] = '*';
            s[x2-1][y2] = '*';
        } else {
            s[x1+1][y1] = '*';
            s[x2+1][y2] = '*';
        }
    } else if (y1 == y2) {
        if (y1 > 0) {
            s[x1][y1-1] = '*';
            s[x2][y2-1] = '*';
        } else {
            s[x1][y1+1] = '*';
            s[x2][y2+1] = '*';
        }
    } else {
        if (x1 > x2) {
            s[x2][y1] = '*';
            s[x1][y2] = '*';
        } else {
            s[x2][y1] = '*';
            s[x1][y2] = '*';
        }
    }

    FOR (i, 0, n)
        cout << s[i] << endl;
}
