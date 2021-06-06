#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

void solve() {
    int n;
    cin >> n;

    int m = pow(2, n);
    vector<int> a(m);

    REP(i, 0, m) cin >> a[i];

    vector<int> b(a);

    while (m > 2) {
        m /= 2;

        REP(i, 0, m) {
            if (a[i] < a[i + 1]) a.erase(a.begin() + i); else a.erase(a.begin() + i + 1);
        }
    }

    m = pow(2, n);
    int v = *min_element(a.begin(), a.end());

    REP(i, 0, m) {
        if (v == b[i]) {
            cout << i + 1; return;
        }
    }
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
