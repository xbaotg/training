#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

void solve() {
    int l;
    cin >> l;

    int cl = l - 1;
    long long r = 1;
    int c = 2;

    for (int i = cl - 10; i <= cl; i++) {
        r *= i;
        while (r % c == 0 && c <= 11) {
            r /= c;
            c ++;
        }
    }
    
    cout << r;
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
