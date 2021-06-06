#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    double x = 1.0 * abs(c - a) * b / (b + d);

    if (c < a) {
        printf("%.10f", a - x);
    } else {
        printf("%.10f", a + x);
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
