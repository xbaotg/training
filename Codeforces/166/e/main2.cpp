#include <bits/stdc++.h>
using namespace std;

#define fort(i, a, b) for (int i = a; i < b; i++)
#define ford(i, a, b) for (int i = a; i > b; i--)

typedef long long ll;

void solve();

//---------------------------------------------------------------//
//                                                               //
// FB: https://facebook.com/tgbaodeeptry                         //
//                                                               //
// From Viet Nam with Love :D                                    //
//                                                               //  
//---------------------------------------------------------------//

int main() {
    #ifdef _CRUN 
        //freopen("input", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t; 
    while (t--)
        solve();
}

ll dp[2][10000001];
int m = int(1e9) + 7;

//int ways(int s, int n) {
    //if (n == 0)
        //return s == 1;

    //if (dp[s][n] != -1)
        //return dp[s][n];

    //if (s) 
        //return dp[1][n] = ( 3 * ways(0, n-1) % m ) % m;
    //else
        //return dp[0][n] = ( ( 2 * ways(0, n-1) % m ) % m + ways(1, n-1) % m ) % m;
//}

void solve() {
    // ways(source, count)
    // 
    // if (ways(D, n)) = ways(A, n-1) + ways(B, n-1) + ways(C, n-1) = 3ways(lower vertex, n-1);
    // if ways(lower vertex, n) = 2*ways((B, C), n-1) + ways(D, n-1)
    
    // base:
    // - ways(D, 1) = 1
    // - ways(lwoer vertex, 1) = 0

    //cout << ways(1, 3) << endl;
    int n;
    cin >> n;

    dp[0][1] = 1; dp[1][1] = 0;
    fort (i, 2, n + 1) {
        dp[1][i] = (3*(dp[0][i-1] % m)) % m;
        dp[0][i] = (2*(dp[0][i-1] % m)%m + dp[1][i-1] % m) % m;
    }

    cout << dp[1][n] << endl;
}
