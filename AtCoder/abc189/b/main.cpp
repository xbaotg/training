#include <bits/stdc++.h>
#include <math.h>
#include <pthread.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

void solve() {
    int n, i = 0, v, p, x;
    cin >> n >> x;

    x *= 100;

    while (n-- && x >= 0 && ++i) {
        cin >> v >> p;
        x -= v * p;
    } 

    if (x >= 0) {
        cout << -1;
    } else {
        cout << i;
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
