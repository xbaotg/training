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
    ll n, k;
    cin >> n >> k;

    // sum of 2 odd numbers -> even number
    // sum of 4 odd numbers -> even number
    if ((k & 1) == (n & 1)) {
        // first caculate sum from 1,3...,x (x is kth-number)
        // 1 + 3 + 5 + ... = k^2
        ll s = k * k;

        if (s <= n)
            printf("YES\n");
        else 
            printf("NO\n");

    } else {
        printf("NO\n");
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
