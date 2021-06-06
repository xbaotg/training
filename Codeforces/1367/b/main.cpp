#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = a; x <= b; x++)
#define FOD(x, a, b) for (int x = a; x >= b; x--)
#define REP(x, a, b) for (int x = a; x < b; x++)
#define RED(x, a, b) for (int x = a; x > b; x--)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (auto &v : a) cin >> v;

    int ce = 0, co = 0;

    REP(i, 0, n) {
        if ((i & 1) != (a[i] & 1)) {
            if ((i & 1) == 0) ce++; else co++;
        } 
    }

    if (ce != co) {
        cout << -1 << endl;
        return;
    }

    cout << ((ce + co) >> 1) << endl; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
