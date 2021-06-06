#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

void solve() {
    int h, w, x = 0;
    int s = 0;
    int m = INT_MAX;

    cin >> h >> w;

    REP(i, 0, h) {
        REP(j, 0, w) {
            cin >> x;

            s += x;
            m = min(m, x);
        }
    }

    cout << s - h*w*m;
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
