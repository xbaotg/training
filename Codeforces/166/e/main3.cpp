#include <bits/stdc++.h>
using namespace std;

#define fort(i, a, b) for (int i = a; i < b; i++)
#define ford(i, a, b) for (int i = a; i > b; i--)

using ll = long long;
using vvi = vector<vector<int>>;

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

int m = int(1e9) + 7;

vvi multiply_matrix(vvi a, vvi b) {
    if (a.size() == 0)
        return b;

    vvi ans (a.size(), vector<int> (b[0].size(), 0));

    fort (i, 0, (int) a.size()) {
        fort (j, 0, (int) b[0].size()) {
            fort (k, 0, (int) b.size()) {
                ans[i][j] = (ans[i][j] % m + (((ll) (a[i][k] % m)) * (b[k][j] % m) % m) % m) % m;
            }
        }
    }

    return ans;
}

vvi pow_matrix(vvi a, int m) {
    vvi ans = {};
    vvi x = a;

    while (m) {
        if (m & 1) {
            ans = multiply_matrix(ans, x);
        }

        x = multiply_matrix(x, x);
        m >>= 1;
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;

    vvi temp = {{0, 3}, {1, 2}};
    vvi base = {{0}, {1}};

    vvi ans = multiply_matrix(pow_matrix(temp, n - 1), base);

    cout << ans[0][0] << endl;
}
