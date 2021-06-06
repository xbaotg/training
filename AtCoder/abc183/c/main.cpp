#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

int n, k;
int res = 0;

void dfs(int c, int s, int tt, vector<vector<int>> t, vector<bool> &v) {
    v[s] = true;

    REP(i, 0, n) {
        if (v[i]) continue;

        if (c + 1 == n) {
            int v = tt + t[i][0] + t[s][i];

            if (v == k) {
                res ++;
            }
        } else {
            dfs(c + 1, i, tt + t[s][i], t, v);
        }
    }

    v[s] = false;
}

void solve() {
    cin >> n >> k;

    vector<vector<int>> t(n, vector<int>(n));
    vector<bool> v(n, false);

    REP(i, 0, n) REP(j, 0, n) cin >> t[i][j];

    dfs(1, 0, 0, t, v);

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

//    cin >> tests;
//    while (tests--) {
//        solve();
//    }

    solve();
}
