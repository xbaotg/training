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
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    if (k == 0) {
        printf("YES\n");
        return;
    }

    int c = 0;

    fort (i, 0, n / 2 + (n % 2) - 1) {
        if (s[i] == s[n - i - 1]) {
            c++;
        } else {
            if (c >= k) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
            return;
        }
    }

    // aa 

    if (n % 2 == 0 && k == n / 2) {
        printf("NO\n");
        return;
    } 

    printf("YES\n");
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
