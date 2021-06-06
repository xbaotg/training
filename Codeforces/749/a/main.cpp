#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    int res = n / 2;
    int rem = n - res*2;

    if (rem == 0) {
        cout << res << endl;
        REP(i, 0, res) cout << 2 << " ";
        return;
    } else {
        while (!isPrime(rem)) {
            res --;
            rem += 2;
        }

        res++;

        cout << res << endl;
        REP(i, 0, res - 1) cout << 2 << " ";
        cout << rem;
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
