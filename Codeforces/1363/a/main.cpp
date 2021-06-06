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
    int n, x, v;
    cin >> n >> x;

    // sum odd
    //    count odds is odd

    int co = 0, ce = 0;
    
    while (n--) {
        cin >> v;
        co += (v & 1) == 1;
        ce += (v & 1) == 0;
    }

    int rem = max(1, x - ce);

    if (rem % 2 == 0 && rem < x) {
        rem ++;
    }

    if (co >= rem && (rem & 1) == 1) 
        printf("Yes\n");
    else
        printf("No\n");
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
