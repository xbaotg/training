//-----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define deb(x) cout<<"LINE("<<__LINE__<<"): "<<(#x)<<" = "<<(x)<<endl; 
#else
#define deb(...)
#endif

const double pi = acos(-1.0);

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
// Main code below
//-----------------------------------------------------------------------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}


void solve() {
    int n, m, k, x;
    cin >> n >> m;

    int a[n];
    int c[n];
    int ck[m];
    int *d[m];

    memset(a, 0, sizeof a);
    memset(c, 0, sizeof c);

    FOR(i, 0, m) {
        cin >> k;
        d[i] = new int[k];
        ck[i] = k;

        FOR(j, 0, k) {
            cin >> x;
            d[i][j] = x;
            a[x - 1]++;
        }
    }

    int ma = m / 2;
    int ch[m];

    FOR(i, 0, m) {
        int diff = 0;
        int cs = 0;
        int r = -1;
        FOR(j, 0, ck[i]) {
            x = d[i][j] - 1;
            if (a[x] - c[x] > diff && c[x] < ma) {
                r = j;
                diff = a[x] - a[x];
                cs = 1;
            } else {
                cs++;
            }
        }
        if (r == -1) {
            cout << "NO\n";
            return;
        } else {
            if (cs == ck[i]) {
                diff = m;
                FOR(j, 0, ck[i]) {
                    x = d[i][j] - 1;
                    if (c[x] < diff) {
                        diff = c[x];
                        r = j;
                    }
                }
            }

            c[d[i][r] - 1]++;
            ch[i] = d[i][r];
        }
    }

    cout << "YES\n";
    for (auto v : ch) cout << v << " ";
    cout << "\n";
}
