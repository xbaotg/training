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
    string s; cin >> s;
    int n = s.length();
    int m, l, r;
    cin >> m;

    vi c(n+1);

    c[0] = 0;
    c[1] = 0;
    fort(i, 1, n - 1) {
        if (s[i] == s[i-1])
            c[i+1] = c[i] + 1;
        else
            c[i+1] = c[i];
    }

    while (m--) {
        cin >> l >> r;
        cout << c[r] - c[l] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    solve();
}
