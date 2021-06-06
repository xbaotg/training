#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (auto &v : a) cin >> v;
    cin >> m;
    vector<int> b(m);
    for (auto &v : b) cin >> v;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int res = 0;

    for (auto &v : a) {
        REP(i, 0, m) {
            if (abs(v - b[i]) <= 1) {
                b[i] = 1000;
                res ++;
                break;
            }
        }
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
