#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

void solve() {
    int n, res = 0;
    cin >> n;
    vector<int> x(n), y(n);

    REP(i, 0, n) cin >> x[i] >> y[i];

    REP(i, 0, n - 1) {
        REP(j, i + 1, n) {
            if (abs(1.0 * (y[j] - y[i]) / (x[j] - x[i])) <= 1) {
                res ++;
            }
        }
    }

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
