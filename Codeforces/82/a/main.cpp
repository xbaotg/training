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

    string names[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

    int i = 1;
    int j;

    while (n > 0) {
        for (j = 0; j < 5; j++) {
            n -= i;
            if (n <= 0) break;
        }
        
        i *= 2;
    }

    cout << names[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    solve();
}
