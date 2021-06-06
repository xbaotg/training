#include <bits/stdc++.h>
#include <cmath>
#include <unordered_set>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

void solve() {
    int n;
    cin >> n;

    vector<string> s(n);
    unordered_set<string> a;

    for (string& x : s) {
        cin >> x;
        a.emplace(x);
    }

    REP(i, 0, n) {
        if (a.count("!" + s[i])) {
            cout << s[i];
            return;
        }
    }

    cout << "satisfiable";
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
