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

    // example
    // if n is even: a + f = b + e = b + c (sequence a b c d e f) => 3 sticks = n / 2
    // if n is odd: a + d = b + c = e (sequence a b c d e) => 3 sticks = ceil(n / 2)
    
    printf("%.f\n", ceil(1.0 * n / 2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
