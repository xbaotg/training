#include <bits/stdc++.h>
using namespace std;

#define fort(x, a, b) for (int x = a; x <= b; x++)
#define ford(x, a, b) for (int x = a; x >= b; x--)
#define printv(v, sep) if (v.size() - 2 >= 1) fort(i, 0, v.size() - 2) cout << v[i] << sep; cout << v[v.size() - 1];

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>

void solve() {
    int n;
    cin >> n;

    int res = 0, v, cu = 0;
    unordered_map<int, int> c;

    fort (i, 0, n - 1) {
        cin >> v;

        if (c.find(v) == c.end()) {
            cu++;
            c[v] = 1;
        } else {
            c[v]++;
        }
    }

    for (auto p : c) {
        res = max({res, min(cu - 1, p.second), min(cu, p.second - 1)});
    }

    printf("%d\n", res);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
