//-----------------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define deb(x) cout<<"LINE("<<__LINE__<<"): "<<(#x)<<" = "<<(x)<<endl; 
#else
#define deb(...)
#endif

const double pi = acos(-1.0);

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

    //int t; cin >> t; while(t--) solve();
    solve();
}


void solve() {
    ifstream inf("inp", ios::in);

    int n, k;
    inf >> n >> k;

    int s[n][n];
    int a[n];

    memset(s, 0, sizeof s);

    for (int i = 0; i < n; i++) {
        int c = 0, j = 0;

        for (; j < k; j++) {
            inf >> a[j];
            c += a[j];
        }

        s[i][j-1] = c;
        for (; j < n; j++) {
            inf >> a[j];

            c += a[j] - a[j-k];
            s[i][j] = c;
        }
    }

    int r = 0;

    for (int i = k - 1; i < n; i++) {
        int c = 0, j = 0;
        for (; j < k; j++) {
            c += s[j][i];
        }
        
        r = max(r, c);

        for (; j < n; j++) {
            c += s[j][i] - s[j - k][i];
            r = max(r, c);
        }
    }

    cout << r;
}
