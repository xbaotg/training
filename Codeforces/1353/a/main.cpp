#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

void solve() {
    int n, m;
    cin >> n >> m;

    // 0 a 0 b 0 c
    // 2a + 2b + 2c
    //
    // a + a + b + c + d
    //
    if (n == 1) {
        cout << 0;
    } else if (n == 2) {
        cout << m;
    } else {
        cout << 2*m;
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
