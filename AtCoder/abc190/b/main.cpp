#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

void solve() {
    int n, s, d;
    cin >> n >> s >> d;

    REP(i, 0, n) {
        int x, y;
        cin >> x >> y;

        if (x < s && y > d) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";

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
