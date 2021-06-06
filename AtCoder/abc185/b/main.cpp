#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

void solve() {
    int n, m, t, s, e = 0;

    cin >> n >> m >> t;

    int p = n;

    REP(i, 0, m) {
        cin >> s;
        p = max(p - s + e, 0);

        if (p == 0) {
            cout << "No"; return;
        }

        cin >> e;
        p = min(p + e - s, n);
    }

    p = max(p - t + e, 0); 
    if (p == 0) {
        cout << "No"; return;
    }
    
    cout << "Yes";
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
