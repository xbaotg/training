#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

void solve() {
    int n, res = 0;

    cin >> n;

    vector<int> a(n);

    REP(i, 0, n) cin >> a[i];

    REP(i, 0, n) {
        int m = 100000;
        REP(j, i, n) {
            m = min(m, a[j]);
            res = max(res, (j - i + 1) * m);
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
