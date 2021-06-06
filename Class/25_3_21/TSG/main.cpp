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
    ifstream cin("TGS.INP", ios::in);

    int n, x;
    cin >> n;

    int dp[101][101];
    for (auto &v : dp[0]) v = 0;

    cin >> dp[0][0]; 

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> x;

            if (j == 0) 
                dp[i][j] = dp[i-1][j] * x;
            else if (j == i)
                dp[i][j] = dp[i-1][j-1] * x;
            else
                dp[i][j] = max(dp[i-1][j-1] * x, dp[i-1][j] * x);
       }
    }

    cout << *max_element(dp[n-1], dp[n-1] + n);
}
