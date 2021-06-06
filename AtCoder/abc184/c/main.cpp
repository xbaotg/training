#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

int solve() {
    // a + b = c + d -> second diagonal
    // a - b = c - d -> primary diagonal
    // 
    // we can reach to (r2, c2) in three moves
   
    int r1, c1, r2, c2;

    cin >> r1 >> c1 >> r2 >> c2;

    int r = r1 - r2;
    int c = c1 - c2;

    if (r == 0 && c == 0) {
        return 0;
    }

    if (r == -c || r == c || abs(r) + abs(c) <= 3) {
        return 1;
    }

    // 2 moves => A + B, A + C, B + C, C + C
    //
    // call point (x, y) with x = r2 same with point 2
    //
    // abs(c2 - y) <= 3 
    //
    // a + b = c + d => d = a + b - r2 = r1 + c1 - r2 =>> abs(c2 - (r1 + c1 - r2)) = abs(-c - r)
    // a - b = c - d => d = c - a + b = r2 - r1 + c1 =>> abs(c2 - (r2 - r1 + c1)) = abs(r - c)
    //

    if ((r1 + r2 + c1 + c2) % 2 == 0 || (abs(r) + abs(c) <= 6) || abs(r + c) <= 3 || abs(r - c) <= 3) {
        return 2;
    }

    return 3;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

//    cin >> tests;
//    while (tests--) {
//        solve();
//    }

    cout << solve();
}
