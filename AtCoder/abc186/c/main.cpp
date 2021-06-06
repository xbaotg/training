#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

bool c7(int x) {
    int t = x;
    while (t) {
        if (t % 10 == 7) return true;
        t /= 10;
    }

    t = x;
    while (t) {
        if (t % 8 == 7) return true;
        t /= 8;
    }

    return false;
}

void solve() {
    int n;
    cin >> n;

    int res = 0;

    FOR(i, 1, n) {
        res += !c7(i);
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
