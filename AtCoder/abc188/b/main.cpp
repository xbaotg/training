#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    REP(i, 0, n) {
        cin >> a[i];
    }
    REP(i, 0, n) {
        cin >> b[i];
    }

    int r = 0;

    REP(i, 0, n) {
        r += a[i] * b[i];
    }

    if (r == 0) cout << "Yes"; else cout << "No";
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
