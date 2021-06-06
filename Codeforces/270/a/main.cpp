#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define fort(x, a, b) for (int x = a; x <= b; x++)
#define ford(x, a, b) for (int x = a; x >= b; x--)
#define printv(v, sep) if (v.size() - 2 >= 1) fort(i, 0, v.size() - 2) cout << v[i] << sep; cout << v[v.size() - 1];

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>

void solve() {
    int a;
    cin >> a;

    if (360 % (180 - a) == 0) {
        int n = 360 / (180 - a);

        if (n >= 3) cout << "YES"; else cout << "NO";
    } else {
        cout << "NO";
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
