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
    int n, v;
    cin >> n;

    vi a;
    a.push_back(0);
    int l = 1;

    fort(i, 0, n-1) {
        cin >> v;
        fort(j, 1, v) {
            a.push_back(i+1);
        }
        l = v + 1;
    }

    cin >> n;
    while (n--) {
        cin >> v;
        cout << a[v] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    solve();
}
