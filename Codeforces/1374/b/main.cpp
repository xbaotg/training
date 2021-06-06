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

    // 2 = 2
    // 6 = 2 . 3
    //
    // n = 2^m . 3^n . 5^o . 7^p ...
    // n * 2 => n = 2^(m + 1) . 3^n ....
    // n / 6 => n = 2^(m - 1) . 3^(n - 1) ....
    //
    // if n contains power numbers that are not 2, 3 => no have any
    // else
    // if m <= n => ways = (n - m) + n = 2n - m;
    // if m > n => no ways

    int c2 = 0, c3 = 0;

    fort(i, 2, 3) {
        while (n % i == 0) {
            if (i == 2) c2++;
            if (i == 3) c3++; 
            n /= i;
        }
    }

    if (c2 > c3 || n != 1) cout << -1 << endl; else cout << 2*c3 - c2 << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
