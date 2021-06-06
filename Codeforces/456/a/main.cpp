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

    pair<int, int> a[n];

    for (auto &p : a) {
        cin >> p.first >> p.second;
    }

    sort(a, a + n);

    fort(i, 0, n - 2) {
        if (a[i].second > a[i+1].second) {
            printf("Happy Alex");
            return;
        }
    }

    printf("Poor Alex");
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    solve();
}
